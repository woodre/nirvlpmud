/*
  alarm_bat.h
*/

#include "/players/eurale/defs.h"
#include "defs.h"

/* -------- Alarm bat ---------- */
message_bat(str) {
object bat_obj;
string str2;

if(!str) {
  write("You must include a message for the bat.\n"+
        "Use: mbat <msg>\n");
  return 1; }

if(TPL < 12 || TP->query_guild_exp() < 670) {
  write("You can't use that abilitiy yet.\n");
  return 1; }

if(FANGS->query_alarm_bat_obj()) {
  write("You already have an active bat.\n");
  write("Use: 'dismiss bat' to get rid of it.\n");
  return 1; }

if(TP->query_spell_point() < 30) {
  write("You don't have enough spell points.\n");
  return 1; }

TP->add_spell_point(- 30);
bat_obj = clone_object("/players/eurale/Vamp/NPC/bat_message.c");
FANGS->set_alarm_bat_obj(bat_obj);
bat_obj->set_message(str);
bat_obj->set_bat_owner(TPRN);
tell_room(environment(TP),
  "A large "+BOLD+"fruit bat"+NORM+" flies in and lands.\n\n");
move_object(bat_obj,environment(TP));
write_file("/players/nooneelse/black/lib/BAT_MESSAGES",
  capitalize(TPRN)+" wrote: "+str+".\n");
return 1;
}
