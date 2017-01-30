#include "std.h"

object archer;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!archer || !living(archer)) {
  object qstaff, arrow;
    archer = clone_object("obj/monster");
    call_other(archer, "set_name", "archer");
    call_other(archer, "set_alias", "robin");
    call_other(archer, "set_level", 18);
    call_other(archer, "set_hp", 900);
    call_other(archer, "set_wc", 36);
    call_other(archer, "set_ac", 16);
    call_other(archer, "set_al", 800);
    call_other(archer, "set_short", "Robin Hood the Archer");
    call_other(archer, "set_long",
      "The legendary Robin Hood stands before you, dressed in forest green\n" +
      "and tan, an unstrung bow over his shoulder, quarrel at his hip\n" +
      "and wielding the same quarterstaff he used to defeat Friar Tuck.\n");
    call_other(archer, "set_chance", 20);
    call_other(archer, "set_spell_mess1",
      "There is a ping and a groan....\n");
    call_other(archer, "set_spell_mess2", 
      "You are struck by an invisible arrow and feeling much weaker.\n");
    call_other(archer, "set_spell_dam", 55);
    move_object(archer, this_object());
    qstaff = clone_object("obj/weapon");
    call_other(qstaff, "set_name", "quarterstaff");
    call_other(qstaff, "set_alias", "staff");
    call_other(qstaff, "set_long", 
      "The famous quarterstaff of Robin Hood.\n");
    call_other(qstaff, "set_class", 18);
/*     call_other(qstaff, "set_value", 10000);*/
    call_other(qstaff, "set_value", 2400);
    call_other(qstaff, "set_weight", 2);
    transfer(qstaff, archer);
    arrow = clone_object("obj/treasure");
    call_other(arrow, "set_id", "arrow");
    call_other(arrow, "set_short", "The Avalon Emerald Arrow");
    call_other(arrow, "set_long",
      "The famous Avalon Emerald Arrow, carved from one perfect emerald.\n" +
      "Considered by most to be a myth, this arrow is virtually priceless.\n");
/*     call_other(arrow, "set_value", 100000); */
    call_other(arrow, "set_value", 3200);
    call_other(arrow, "set_weight", 2);
    transfer(arrow, archer);
  }
}
 
ONE_EXIT("players/aislinn/2archery", "north",
	 "Avalon Archery Range",
   "This is a large, open field.  There are three archery targets set\n" +
   "up at the far south end.  A covered viewing stand is midway along\n" +
   "the east side of the field, waiting for spectators to fill the\n" +
   "seats.  A banner in the club colors hangs above the stand, and\n" +
   "reads:\n" +
   "        Welcome to the 11th Annual Avalon Archery Contest\n" +
   "                Special Contestant -- Robin Hood\n" +
    "    \n", 1)
