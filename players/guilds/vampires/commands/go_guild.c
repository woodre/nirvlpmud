/*
  go_guild.h
*/

#include "/players/eurale/defs.h"

/* -------- gohome (teleport to the vampire guild hall) ---------- */
go_guild(str) {
  int success_percent;
  string wheree;

if(TPL < 7 || TPGEXP < 667 || TP->query_attrib("str") < 18) {
  write("You lack the necessary skills to perform that ability.\n");
  return 1; }

if(ROOM->realm() == "NT") {
  tell_object(TP, "You can't do that in this area.\n");
  return 1; }

if(TPBPTS < 2) {
  write("You lack the blood energy to return to the haunt.\n");
  return 1; }

success_percent = TPL * 2 + 70;

  /* now do it */
if(TPSP < 80){
  write("You don't have enough spell points.\n");
  return 1; }

TP->add_spell_point(-80);
PFANGS->add_BLOODPTS(-4);
if(success_percent >= random(100)) {
  FANGS->tell_my_room(
    "A mist envelops "+capitalize(TPRN)+
    ".  When it clears, you see a small\n"+
    "bat flying away.");
  write("You fly to the vampire guild hall.\n\n");
  TP->move_player("flying#players/eurale/VAMPIRES/RMS/vguild_hall.c");
    return 1;
  } else if(wheree = call_other("obj/base_tele","teleport")) {
      TP->move_player("with an astonished look#"+wheree); }
  write("Ok.\n");
  return 1;
}
