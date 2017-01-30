/*
  Meditate Object.  Locks user from moving and certain channels/cmds.
*/
#include "/players/stark/defs.h"
#define GOB present("rakh_guild",ETO)
int life1_lvl;
int hpsdrain, spsdrain, tick, fpsadd;

id(string str) { return str == "meditate_lock"; }
drop() { return 1; }
get() { return 1; }

reset(arg){
call_out("setup",1);
    if(arg) return;
}
init(){
add_action("none_for_you","north");
add_action("none_for_you","west");
add_action("none_for_you","east");
add_action("none_for_you","south");
add_action("none_for_you","n");
add_action("none_for_you","w");
add_action("none_for_you","e");
add_action("none_for_you","s");
add_action("none_for_you","nw");
add_action("none_for_you","ne");
add_action("none_for_you","se");
add_action("none_for_you","sw");
add_action("none_for_you","northwest");
add_action("none_for_you","northeast");
add_action("none_for_you","southeast");
add_action("none_for_you","southwest");
add_action("none_for_you","enter");
add_action("none_for_you","exit");
add_action("none_for_you","leave");
add_action("none_for_you","get");
add_action("none_for_you","drop");
add_action("none_for_you","kill");
add_action("none_for_you","tell");
add_action("none_for_you","newbie");
add_action("none_for_you","gossip");
add_action("none_for_you","star");
add_action("none_for_you","junk");
add_action("none_for_you","babble");
add_action("none_for_you","shout");
add_action("none_for_you","equip");
add_action("none_for_you","risque");
}

none_for_you(){
write("You cannot do that while meditating.\n");
return 1;
}


setup(){
life1_lvl=GOB->query_life1_lvl();
hpsdrain=2;
spsdrain=2;
tick=4;
fpsadd=1;
if(life1_lvl>0){tick=3;}
if(life1_lvl>1){tick=2;}
if(life1_lvl>2){tick=1;}
if(life1_lvl>3){hpsdrain=1;}
if(life1_lvl>4){spsdrain=1; tick=2;}
if(life1_lvl>5){tick=1;}
if(life1_lvl>6){fpsadd=2; tick=2;}
if(life1_lvl>7){tick==1;}
if(life1_lvl>8){fpsadd=3; tick=2;}
if(life1_lvl=9){tick=1;}
call_out("shift",1);
}


shift(){
if(ETO->query_hp()<hpsdrain || ETO->query_spell_point()<spsdrain){
 tell_object(ENV(TO),"You have exhausted yourself\n");
 GOB->meditate();
return 1;
}
if(GOB->query_fps()>=GOB->query_fps_max()){
 tell_object(ENV(TO),"You wake from your meditation refreshed\n");
 GOB->meditate();
return 1;
}

ENV(TO)->add_hp(-hpsdrain);
ENV(TO)->add_sp(-spsdrain);
GOB->add_fps(fpsadd);
tell_object(ENV(TO),HIG+"~ ~ ~ You continue to meditate ~ ~ ~\n"+NORM);
call_out("shift",tick);
}
