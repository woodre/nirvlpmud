#include "room.h"

object Rider;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
object money, weapon;
object Spear;
if (!Rider ||living(Rider)) {
  money = clone_object("obj/money");
Rider = clone_object("obj/monster");
call_other(Rider, "set_name", "rider");

call_other(Rider, "set_hp", 400);
call_other(money, "set_money", random (100));
call_other(Rider, "set_ac", 13);
/* Moved set_wc from here. -Snow 3/00 */

call_other(Rider, "set_al", 500);
call_other(Rider, "set_short", "A Rider of Rohan");
call_other(Rider, "set_long",
"This fair rider rides for the knights of Rohan.  He has fair blond hair\n" +

" and rides his steed well.  \n");
call_other(Rider, "set_level", 16);
move_object(Rider, this_object());
move_object(money, Rider);

weapon=clone_object("obj/weapon");
call_other(weapon, "set_name", "spear");
call_other(weapon, "set_long", "A huge spear from a rider of Rohan\n");
call_other(weapon, "set_class", 16);
call_other(weapon, "set_value", 2000);
call_other(weapon, "set_weight", 2);
move_object(weapon, Rider);
call_other(Rider, "init_command", "wield spear");
call_other(Rider, "set_wc", 20);
    }
}

TWO_EXIT("players/ultramagnus/moria", "east",
     "players/ultramagnus/gimili", "north",

"Riders",
"As you look around, you realize that you are surrounded by the \n" +
"riders of Rohan.  Their love for horses is surpassed only by \n" +
"their hate for orcs and evil.  This group rides to help save \n"+
"the fair city of Gondor from the attacking forces of Mordor.\n"+
"Will you thwart them, or aid them??  \n", 1)
