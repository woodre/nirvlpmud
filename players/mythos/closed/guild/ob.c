#include "/players/mythos/closed/guild/def.h"

int dmonitor,moo;
object mooer;

query_auto_load() {
    return "/players/mythos/closed/guild/obb.c:"; }

id(str) {return str == pact; }

short() { return "Shroud of Darkness"; }

reset(arg) {
  if(arg) return;
  moo = 0;
  call_out("checkers",5);
  call_out("real_mon",5);
   call_out("blah",10);
}

extra_look() {
  return ""+capitalize(epn)+" has a shroud of darkness surrounding "+ep->query_objective()+"";
  }

drop() {return 1;}
get() {return 0;}

set_mooer(ob) { mooer = ob; }
set_moo(n) { moo = n; }

init() {
if(ep)
if(ep->query_level() < 20 && ep->query_guild_name()) {
  destruct(this_object());
  return 1;}
  add_action("update","shroud_update");
  add_action("llok","l at");
  add_action("llok","look at");
  add_action("llok","la");
  add_action("llok","exa");
   add_action("llok","examine");
}

update() {
object con;
  con = clone_object("/players/mythos/closed/guild/ob.c");
  con->set_mooer(mooer);
  con->set_moo(moo);
  move_object(con,tp);
  destruct(this_object());
  write("Darkness enfolds you...\n");
return 1;}

dahelp() {
  tell_object(ep,"\nA Dark Aura surrounds you.  The day no longer is your\n"+
        "home.  It is night that rules you, that gives you the\n"+
        "sustenance needed for you to live.  Light hurts you and\n");
  tell_object(ep,"you hunger for something...  something that screams of \n"+
        "pain and death.....\n\nNote: Type <shroud_update> to update\n");
return 1;}

llok(str) {
if(!str) return 0;
  if(str == "shroud") {
  dahelp();
  return 1;}
}

checkers() {
object h;
int j;
   if(ep) {
  h = all_inventory(ep);
  for(j = 0; j<sizeof(h);j++) {
    if(h[j]->id(pact) && h[j] != this_object()) {
    destruct(this_object());
    }
    }
  }
return 1;}

real_mon() {
object mooed;
int checks;
  if(ep)
  if(ep->query_attack()) {
    mooed = ep->query_attack();
    if(mooer != mooed) { mooer = mooed; checks = 0; moo = mooed->query_hp();}
    checks = mooer->query_hp();
    if(checks > moo) moo = checks;
         if(moo == 0) moo = 1;
    tell_object(ep,BOLD+"ATTACK: "+HIR+checks*10/moo+"/10"+NORM+"\n");
  }
  else { mooed = 0; checks = 0; }
call_out("real_mon",5);
return 1; }

blah() {
  if(environment(this_object()))
     move_object(this_object(),environment(this_object()));
return 1; }
