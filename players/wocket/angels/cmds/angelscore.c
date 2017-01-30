#include "/players/wocket/closed/ansi.h"
#define TP this_player()

angelscore(){
string arg;
write(CYN+"--------------------------------------------------------------\n");
    arg = HIC+"Name: "+NORM+TP->query_name();
    arg += "\t\t";
    arg += HIC+"Level: "+NORM+TP->query_level();
    arg += "\n";
    arg += HIC+"Hp: "+NORM+TP->query_hp();
    arg += "["+TP->query_maxhp()+"]";
write(HIC+"Hp: "+NORM+TP->query_hp()+"["+TP->query_max_hp()+"]\n");
    arg += HIC+"Sp: "+NORM+TP->query_spell_point();
    arg += "["+TP->query_max_spell()+"]\n";
write(arg);
return 1;
}
