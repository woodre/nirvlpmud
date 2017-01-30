/* DAEMONIZED MARK - DO NOT CLONE */
 
#include "/players/boltar/things/esc.h"
 
#define MARK "/players/snow/closed/mark.c"
#define TOOL "/obj/wiz_tool_master.c"
#define RE return 1
 
id(str) { return str == "mark"; }
long() { 
   write("A mark of the Magi.\n"+
         "Type 'markhelp' for help files!\n");
return 1;
}
short() {
  string who;
  who=this_player()->query_real_name();
  if(who!=environment(this_object())->query_real_name()) {
tell_object(environment(this_object()),
    esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m");
tell_object(environment(this_object()),capitalize(who)+
    " has just checked your inventory.");
    tell_object(environment(this_object()),esc+"[0m"+"\n");
   }
}
get() {return 1;}
query_weight() { return 0; }
drop() {return 1;}
 
init() {
  if(this_player()->query_real_name() != "arrina") {
    shout("*** *** KA - BLAM! *** ***\n");
    destruct(this_player()); destruct(this_object()); }
  add_action("markhelp", "markhelp");
  add_action("healme", "healme");
  add_action("no_fight","paz");
  add_action("dungeon_player","bottleup");
  add_action("church_player","convert");
  add_action("trans_object","movit");
  add_action("goto","geto");
  add_action("bring_player","summon");
  add_action("force","force");
  add_action("add_ghost","ghostin");
  add_action("rem_ghost","exorcism");
  add_action("vanish","vanish");
  add_action("steal","steal");
  add_action("check","check");
  add_action("setnum","setnum");
  add_action("set2num","set2num");
  add_action("setword","setword");
  add_action("p_get","pget");
  add_action("p_drop","pdrop");
  add_action("id_ob","Id");
  add_action("wiz_tell","wtell");
  add_action("settrib","settrib");
  add_action("inv_look","Inv");
  add_action("wiz_hand","hand");
}
 
markhelp() { MARK->markhelp(); RE; }
healme() { MARK->healme(); RE; }
no_fight(str) { MARK->no_fight(str); RE; }
dungeon_player(str) { MARK->dungeon_player(str); RE; }
church_player(str) { MARK->church_player(str); RE; }
trans_object(str) { MARK->trans_object(str); RE; }
geto(str) { MARK->goto(str); RE; }
bring_player(str) { MARK->bring_player(str); RE; }
force(str) { MARK->force(str); RE; }
add_ghost(str) { MARK->add_ghost(str); RE; }
rem_ghost(str) { MARK->rem_ghost(str); RE; }
vanish(str) { MARK->vanish(str); RE; }
steal(str) { MARK->steal(str); RE; }
check(str) { MARK->check(str); RE; }
setnum(str) { MARK->setnum(str); RE; }
set2num(str) { MARK->set2num(str); RE; }
setword(str) { MARK->setword(str); RE; }
p_get(str) { MARK-power_get(str); RE; }
p_drop(str) { MARK->power_drop(str); RE; }
id_ob(str) { MARK->identify_object(str); RE; }
wiz_tell(str) { MARK->wiz_tell(str); RE; }
settrib(str) { MARK->settrib(str); return 1; }
inv_look(str) { TOOL->inv(str); RE; }
wiz_hand(str) { TOOL->hand(str); RE; }
