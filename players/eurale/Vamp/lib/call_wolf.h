/*
  call_wolf.h
*/

#include "/players/eurale/defs.h"

/* -------- Call a wolf to help fight ---------- */
call_wolf(str) {
  string wolf_name, str1, str2;
  object wolf_obj;

if(!str) return 0;
wolf_name = 0;
sscanf(str, "wolf %s", wolf_name);

if(!wolf_name) {
  write("You must supply the wolf's name.  (call wolf <name>)\n");
  return 1; }

if(TPL < 17 || TPGEXP < 669 || TP->query_attrib("pie") < 18) {
  write("You don't have the skills for that ability yet.\n");
  return 1; }

if(TPSP < 50) {
  write("You don't have enough magic to do that.\n");
  return 1; }

if(EFANGS->query_wolf_obj()) {
  write("You already command a wolf.\n");
  return 1; }

str1 = file_name(ROOM);
sscanf(str1, "%s.c", str2);
if(!str2) str2 = str1;

if(str2 != "players/eurale/Vamp/RMS/wolf_summon") {
  write("A wolf may only be summoned from the wolf rock.\n");
  return 1; }

TP->add_spell_point(-50);
wolf_obj = clone_object(VAMP_WOLF);
wolf_obj->set_master(TPRN);
wolf_obj->set_name(wolf_name);
move_object(wolf_obj,str1);
EFANGS->set_wolf_obj(wolf_obj);
EFANGS->tell_my_room(
  "A "+BOLD+"large black wolf"+NORM+" pads into the room and stands at "+
               capitalize(TPRN)+"'s left side.");
  write("A "+BOLD+"large black wolf"+NORM+" pads into the room and "+
        "stands at your left side.\n");
  return 1;
}
