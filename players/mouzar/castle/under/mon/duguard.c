inherit"obj/monster";
reset(arg) {
object armor;
object weapon;
object treasure;
::reset(arg);
if(arg) return;
set_chat_chance(40);
set_a_chat_chance(50);
load_chat("Duergar Warrior says:  Watch out for the Drow.  They are all around us!\n");
load_chat("Duergar Warrior says:  What is you business here!\n");
load_chat("Duergar Warrior says:  ugters asdeer doske asdke!\n");
load_a_chat("Duergar Warrior shouts:  siafei asidlek oijjji!\n");
load_a_chat("Duergar Warrior shouts:  qeiruc csdij nmhoo?\n");
set_name("guard");
set_alias("duergar");
set_alt_name("warrior");
set_short("Duergar Warrior");
set_long(
"These little bearded guys look like dwarves but they are not.  They are\n"
+ "the evil cousins of the dwarves.  These guys are just as good in battle\n"
+ "as their good cousins the dwarves.  Their armor isn't in the best of shape\n"
+ "and their weapons look like it's seen better days.\n");
set_level(13);
set_al(-400);
set_race("dwarf");
set_hp(225);
set_wc(17);
set_ac(10);
set_aggressive(1);
armor = clone_object("/players/mouzar/castle/under/obj/duscale");
move_object(armor,this_object());
weapon = clone_object("/players/mouzar/castle/under/obj/dusword");
move_object(weapon,this_object());
treasure = clone_object("/players/mouzar/castle/under/obj/orcear");
move_object(treasure,this_object());
}
