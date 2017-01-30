/*
  go_guild.h
*/

#include "/players/eurale/defs.h"

/* -------- gohome (teleport to the vampire guild hall) ---------- */
go_guild(str) {
  int success_percent;
  string wheree;

if(TPL < 7 || TPGEXP < 667 || TP->query_attrib("mag") < 15) {
  write("You lack the necessary skills to perform that ability.\n");
  return 1; }

if(ROOM->realm() == "NT") {
  tell_object(TP, "You can't do that in this area.\n");
  return 1; }

success_percent = TPL * 2 + 70;

  /* now do it */
if(TPSP < 40) {
  write("You don't have enough spell points.\n");
  return 1; }

TP->add_spell_point(-40);
if(success_percent >= random(100)) {
  EFANGS->tell_my_room(
    "A mist envelops "+capitalize(TPRN)+
    ".  When it clears, you see a small\n"+
    "bat flying away.");
  write("You fly to the vampire guild hall.\n\n");
  TP->move_player("flying#players/eurale/Vamp/RMS/vguild_hall.c");
    return 1;
  } else if(wheree = call_other("obj/base_tele","teleport")) {
      TP->move_player("with an astonished look#"+wheree); }
  write("Ok.\n");
  return 1;
}
