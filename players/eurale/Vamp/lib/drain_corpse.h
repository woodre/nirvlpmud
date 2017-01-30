/*
  drain_corpse.h
*/

#include "/players/eurale/defs.h"

/* -------- Drain corpse ---------- */
drain_corpse(str) {
  object target_obj;

if(TPL < 7 || TPGEXP < 667) {
  write("You can't use that abilitiy yet.\n");
  return 1; }

if(!str || str != "corpse") return 0;

target_obj = present("corpse", ROOM);
if(!target_obj) target_obj = present("corpse", TP);

if(!target_obj) {
  write("A corpse must be present to do that.\n");
  return 1; }

TP->heal_self(target_obj->heal_value());
TP->add_alignment(-35);
destruct(target_obj);
write("You pierce the corpse's neck and "+HIR+"SUCK the LIFEBLOOD"+
    NORM+" from its lifeless body.\n\n");
EFANGS->tell_my_room(
           capitalize(TPRN)+" sinks "+TP->query_possessive()+
            " fangs into the corpse and "+HIR+"SUCKS the lifeblood "+
            NORM+"from it.\n");
command("mon",TP);
return 1;
}
