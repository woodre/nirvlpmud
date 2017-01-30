#include "std.h"

object schar;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!schar || !living(schar)) {
  object scalpel;
    schar = clone_object("obj/monster");
    call_other(schar, "set_name", "shady character");
    call_other(schar, "set_alias", "man");
    call_other(schar, "set_level", 12);
    call_other(schar, "set_wc", 16);
    call_other(schar, "set_aggressive", 1);
    call_other(schar, "set_hp", 500);
    call_other(schar, "set_ac", 11);
    call_other(schar, "set_al", -300);
    call_other(schar, "set_short", "A shady looking character");
    call_other(schar, "set_long",
      "A shady looking character, lurking in the shadows.  He looks\n" +
      "poised to attack and a glint of metal can be seen in his hand.\n");
    move_object(schar, this_object());
    scalpel = clone_object("obj/weapon");
    call_other(scalpel, "set_name", "scalpel");
    call_other(scalpel, "set_short", "A scalpel");
    call_other(scalpel, "set_long",
      "A surgical, steel scalpel, excessively sharp and very dangerous.\n");
    call_other(scalpel, "set_class", 16);
    call_other(scalpel, "set_value", 650);
    call_other(scalpel, "set_weight", 1);
    transfer(scalpel, schar);
    call_other(scalpel, "set_type", "weapon");
    call_other(schar, "init_command", "wield scalpel");
  }
}
 
TWO_EXIT("players/aislinn/2archery", "south",
         "players/aislinn/change_area", "west",
	 "Changing Area - Men",
   "This is the second of the changing buildings, for the men.  There is\n" +
   "an attendant here, as at the women's changing building, wearing the\n" +
   "club colors.  The sounds coming from inside the building are abit\n" +
   "louder than those coming from the womens, apparently the boys are \n" +
   "having some pre-swimming fun.....\n" +
    "    \n", 1)
