#include "/players/mythos/closed/ansi.h"
#define ep  environment(this_object())
int dmonitor;

query_auto_load() {
    return "/players/mythos/mmisc/mon.c:"; }
    
id(str) {return str == "monitor"; }
short() { return "A Monitor";}
long() { write("A Body Monitor.  To turn on or off\n"+
               "type <mon>.  To get rid of monitor\n"+
               "type <no_monitor>\n"+
               "                         - Mythos\n"); }
drop() {return 1;}
get() {return 0;}

init_arg() { dmonitor = 0;  return 1;}

init() {
  if(ep->query_guild_name() == "shardak") {
  ep->add_money(500);
  tell_object(ep,"I'm sorry but your guild is unable to use this.\n"+
                 "You have been compensated with 500 coins.\n");
  destruct(this_object());
  ep->save_me();
  return 1;}
  add_action("no_monitor","no_monitor");
  add_action("mon","mon"); 
  call_out("hb",9);
}

no_monitor() {
  destruct(this_object());
return 1;
}

hb() {
  if(dmonitor > 0) {
      darkmon();
    call_out("hb",3);
return 1;
}
call_out("hb",5);
return 1;}
      
mon() {
  if(dmonitor== 0) { dmonitor = 1; write("Monitor is on.\n"); return 1;}
  dmonitor = 0;  write("Monitor is off.\n");
  return 1;}
  
darkmon() {
  int msp, mhp, sp, hp;
  string mesg, level, intox;
  int stuff, soak;
  msp = ep->query_msp();
  mhp = ep->query_mhp();
  sp = ep->query_sp();
  stuff = ep->query_stuffed();
  soak = ep->query_soaked();
  hp = ep->query_hp();
  level = ep->query_level();
  intox = ep->query_intoxination();
  mesg = "<hp> ["+hp+"/"+mhp+"] ";
  mesg += "<sp> ["+sp+"/"+(msp)+"] ";
  if(intox > 0) mesg += "<intox> ["+intox+"/"+(level+3)+"] ";
  if(stuff > 0) mesg += "<stuff> ["+stuff+"/"+(level*8)+"] ";
  if(soak > 0) mesg += "<soak> ["+soak+"/"+(level*8)+"] ";
  mesg += "\n";
  tell_object(ep,mesg);
  return 1;
}
 
