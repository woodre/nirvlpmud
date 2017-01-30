
inherit"obj/monster";
reset(arg) {
object armour;
object weapon;
::reset(arg);
if(arg) return;
set_name("cook");
set_alias("assistant");
set_short("Assistant Cook");
set_long(
"This is the assistant cook,hmmm..... he's a\n"
+ "sweaty bastard ain't he, covered in sauce and dough\n"
+ "it is hard to determine whether he is the cook or the\n"
+ "pizza itself! I wouldn't bother him he looks pissed off!\n");
set_level(14);
set_wc(20);
set_ac(8);
set_hp(200);
set_al(-450);
set_race("human");
armour = clone_object("/players/emerson/weap/spatula.c");
if(armour) {
move_object(armour,this_object());
  }
weapon = clone_object("/players/emerson/heal/pizza.c");
if(weapon) {
move_object(weapon,this_object());
   }
}
