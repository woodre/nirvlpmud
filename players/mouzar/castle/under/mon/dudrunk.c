inherit"obj/monster";
reset(arg) {
object armor;
object weapon;
::reset(arg);
if(arg) return;
set_chat_chance(25);
load_chat("The drunk guard pukes on your shoes!\n");
set_name("guard");
set_alias("duergar");
set_short("Drunk guard");
set_long(
"This guard is drunk off of his ass.  He is hanging on the wall for support.\n"
+ "He seems to be untouched by the battle that went on to the north of the\n"
+ "community.  He has been partying hard.  \n");
set_level(15);
set_al(-300);
set_race("dwarf");
set_hp(255);
set_wc(20);
set_ac(6);
armor = clone_object("/players/mouzar/castle/under/obj/duscale");
  move_object(armor,this_object());
weapon = clone_object("/players/mouzar/castle/under/obj/dusword");
  move_object(weapon,this_object());
move_object(clone_object("/players/mouzar/castle/under/obj/ale"),this_object());
}
