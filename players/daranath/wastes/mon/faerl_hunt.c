#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2, ob3;
 ob = clone_object("obj/money");
  ob->set_money(random(50) + 25);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"obj/stud_leather.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/bl_sword.c");
  move_object(ob3, this_object());

set_name("Faerl Hunter");
set_alias("platmon");
set_alt_name("hunter");
set_race("faerl");
set_gender("male");

set_short(WHT+"Faerl"+WHT+" hunter"+NORM);
set_long("The Faerl hunter is wearing a suit of dark leather armor covered in wicked\n"+
         "silver studs. The armor is cut to accomodate the Faerl's wings, which\n"+
         "are currently wrapped about his body, giving him a demonic appearance.\n");

set_level(13);
set_ac(10);
set_wc(15 + random(4));
set_hp(160 + random(60));
set_al(-1000);
set_aggressive(0);

init_command("wield sword");
init_command("wear leather");

   }
}
