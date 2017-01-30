#include "/players/guilds/bards/def.h"

status main() {
  if (present("sphere_bard", TP)) {
    write("You have already shaped a globe of chromatic spheres.\n");
    return 1;
  }
  if (spell(-164, 5, 100) == -1)
    return 0;
  write("You play a psalm upon your " + INST + ".\n" +
    "The music slowly shapes the forces of primal chaos into a globe.\n"
    +"When the psalm ends, the sphere gently floats into your hand.\n");
  say(tp + " plays a psalm upon " + POSS(TP) + " " + INST + ".\n" +
    "The music slowly shapes the forces of primal chaos into a globe.\n"
     + "When the psalm ends, the globe lands in " +
  tp + "'s hand.\n");
  move_object(clone_object(OBJ+"sphere"), TP);
  call_other(TP, "add_spell_point", -100);
  return 1;
}
