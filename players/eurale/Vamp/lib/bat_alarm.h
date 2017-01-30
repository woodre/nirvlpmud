/*
  alarm_bat.h
*/

#include "/players/eurale/defs.h"

/* -------- Alarm bat ---------- */
alarm_bat(str) {
object bat_obj;
string bat_owner_name;

if(TPL < 12 || TPGEXP < 668) {
  write("You lack the skills necessary to use this ability.\n");
  return 1; }

if(EFANGS->query_alarm_bat_obj()) {
  write("You have an active bat, use 'dismiss bat' to get rid of it.\n");
  return 1; }

if(TP->query_spell_point() < 30) {
  write("You don't have enough spell points.\n");
  return 1; }

TP->add_spell_point(- 30);
bat_obj = clone_object("/players/eurale/Vamp/NPC/bat_alarm.c");
EFANGS->set_alarm_bat_obj(bat_obj);
bat_obj->set_bat_owner(TPRN);
tell_room(environment(TP),
  "A small, grey bat flies in and lands.\n\n");
move_object(bat_obj,environment(TP));
return 1;
}
