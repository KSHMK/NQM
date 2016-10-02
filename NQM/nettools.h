#ifndef FINDAP_H
#define FINDAP_H

#include <map>
#include <string>
#include <thread>
#include <tins/tins.h>

using namespace std;
using namespace Tins;

class NetTools
{
private:
    typedef HWAddress<6> address_type;
    typedef map<string,address_type> AP_type;

    void FindAP(void);
    void FindVic(void);
    void KillVictim();
    bool changechannel(uint32_t channel);

    address_type victim,AP;
    uint32_t channel;
    bool flag;
    string iface;
    thread *th;

public:
    AP_type mapAP;
    map<address_type,uint32_t> mapVic;
    bool StartFindAP(string iface, uint32_t channel);
    void StopFindAP(void);
    bool StartFindVic(string AP, string iface, uint32_t channel);
    void StopFindVic(void);
    bool StartKill(string victim, string AP, string _iface, uint32_t channel);
    void StopKill(void);
};

#endif // FINDAP_H
