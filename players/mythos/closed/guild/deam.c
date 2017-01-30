#include "/players/mythos/closed/guild/def.h"

query_auto_load() {
    return "/players/mythos/closed/guild/hunger.c:"; }
    
id(str) {return str == fear; }

drop() {return 1;}
get() {return 0;}

init() {
  tp->set_guild_exp(69);
  if(epl > 4) { add_action("dmissle","missile",2);}
  if(epl > 9) { add_action("dshock","shock",2);}
  if(epl > 14) { add_action("dfireball","fireball",2);}
  if(epx > 4) { add_action("dsonic","sonic",2); }
  
  if(ep->query_npc() !=1) {
    write("Darkness envelopes you...\n<type dhelp for help>\n");} 
  add_action("dhelp","dhelp");  
  call_out("hb",9);
}

dhelp() {
  write("\nA Dark Aura surrounds you.  The day no longer is your\n"+
        "home.  It is night that rules you, that gives you the\n"+
        "sustenance needed for you to live.  Light hurts you and\n");
  write("you hunger for something...  something that screams of \n"+
        "pain and death.....\n<type dmon for a monitor>\n");
return 1;}

hb() {
call_out("hb",5);
return 1;}
