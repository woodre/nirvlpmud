#include "/obj/ansi.h"
inherit"obj/monster";
reset(arg) {
object gold;
object armor;
::reset(arg);
if(arg) return;
set_name("trainer");
set_alias("bobo");
set_short("Drow Trainer");
set_long(
"This drow is perfectly built.  His moves are perfect and his speed\n"
+ "with his weapons are just out standing.  No wonder this guy is a \n"
+ "trainer of the best fighters.\n");
set_level(20);
set_al(-400);
set_race("drow");
set_hp(800);
set_wc(40);
set_ac(17);
set_chance(50);
set_spell_dam(50);
set_spell_mess1(HIR+"The Drow Cuts several red lines across his attackers skin as he breaks through their defences"+NORM);
set_spell_mess2(HIR+"The Drow cuts several red lines accoss your skin as he breaks through your defenses"+NORM);
gold = clone_object("obj/money");
 gold->set_money(5000);
 move_object(gold,this_object());
armor = clone_object("/players/mouzar/castle/under/obj/dbracers");
 move_object(armor,this_object());
}
