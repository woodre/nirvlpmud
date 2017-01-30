/*
  alarm_bat.h
*/

#include "/players/eurale/defs.h"

/* -------- Alarm bat ---------- */
message_bat(str) {
object bat_obj;
string str2;

if(EFANGS->query_alarm_bat_obj()) {
  write("You have an active bat, use 'dismiss bat' to get rid of it.\n");
  return 1; }

if(!str) {
  write("You must include a message.  Use: mbat <msg>\n");
  return 1; }

if(TPL < 12 || TPGEXP < 668) {
  write("You can't use that abilitiy yet.\n");
  return 1; }

if(TP->query_spell_point() < 30) {
  write("You don't have enough spell points.\n");
  return 1; }

TP->add_spell_point(- 30);
bat_obj = clone_object("/players/eurale/Vamp/NPC/bat_message.c");
EFANGS->set_alarm_bat_obj(bat_obj);
bat_obj->set_message(str);
bat_obj->set_bat_owner(TPRN);
tell_room(environment(TP),
  "A large "+BOLD+"fruit bat"+NORM+" flies in and lands.\n\n");
move_object(bat_obj,environment(TP));
write_file("/players/eurale/Vamp/lib/BAT_MESSAGES",
  capitalize(TPRN)+" wrote: "+str+".\n");
return 1;
}
