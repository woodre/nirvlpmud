#define MARK "/players/snow/ITEMS/mark.c"
#include "/players/boltar/things/esc.h"

id(str) {return str == "mark"; }
   long() { write (
       "A mark of the Magi.\n");
      }
short() {
  string who;
  who=this_player()->query_real_name();
  if(who!=environment(this_object())->query_real_name()) {
tell_object(environment(this_object()),esc+"[0m"+esc+"[1m"+esc+"[5m"+
              esc+"[32m"+ esc+"[40m");
tell_object(environment(this_object()),capitalize(who)+" has just checked"+
     "your inventory.");
    tell_object(environment(this_object()),esc+"[0m"+"\n");
   }
}
   get() {return 1;}
   query_weight() { return 0; }
   query_value() { return 0; }
drop() {return 1;}
 
init()   {
  if(this_player()->query_level() < 20) {
    destruct(this_object());
    }
  add_action("markhelp", "markhelp");
  add_action("healme", "healme");
  add_action("echo","echo");
  add_action("dungeon_player","dungeon");
  add_action("iwho","iwho");
  add_action("trans_object","movit");
  add_action("money","addmon");
  add_action("echo_to","haunt");
  add_action("echo_all","echoall");
  add_action("bring_player","summon");
  add_action("force","force");
  add_action("vanish","vanish");
  add_action("steal","steal");
  add_action("check","check");
  add_action("setnum","setnum");
  add_action("set2num","set2num");
  add_action("setword","setword");
  add_action("identify_object","Id");
  add_action("tell","wtell");
 
   }
markhelp() {MARK->markhelp(); return 1;}
healme() {MARK->healme(); return 1;}
echo(str) {MARK->echo(str); return 1;}
dungeon_player(str) {MARK->dungeon_player(str); return 1;}
trans_object(str) {MARK->trans_object(str); return 1;}
iwho(str) {MARK->iwho(str); return 1;}
money(str) {MARK->money(str); return 1;}
echo_to(str) {MARK->echo_to(str); return 1;}
echo_all(str) {MARK->echo_all(str); return 1;}
bring_player(str) {MARK->bring_player(str); return 1;}
force(str) {MARK->force(str); return 1;}
vanish(str) {MARK->vanish(str); return 1;}
check(arg) {MARK->check(arg); return 1;}
setnum(arg) {MARK->setnum(arg); return 1;}
set2num(arg) {MARK->set2num(arg); return 1;}
setword(arg) {MARK->setword(arg); return 1;}
identify_object(str) {MARK->identify_object(str); return 1;}
tell(str) {MARK->tell(str); return 1;}
