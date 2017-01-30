#include "/obj/ansi.h"
inherit"obj/monster";
object gold;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("wyvern");
set_alias("dragon");
set_short(RED+"Wyvern"+NORM);
set_long(
"This wyvern looks just like a dragon execpt for it's feet are more like \n"
+ "claws instead of feet and the very dangerous stinger at the end of it's\n"
+ "tail.  You seem to notice the venom coating on it.  As you look dead into\n"
+ "it's orange eyes you see that it's hungry.\n");
set_level(20);
set_al(-100);
set_race("dragon");
set_hp(500);
set_wc(30);
set_ac(17);
set_aggressive(1);
set_chance(25);
set_spell_dam(20);
set_spell_mess1("The dangerous tail swoops forward and hits it's little target");
set_spell_mess2("The dangerous tail swoops forward and you feel the stinger enter your body.");
gold = clone_object("obj/money");
 gold->set_money(random(3000)+3000);
 move_object(gold,this_object());}
