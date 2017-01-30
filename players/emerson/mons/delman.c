
inherit"obj/monster";
reset(arg) {
object armour;
::reset(arg);
if(arg) return;
set_name("man");
set_alias("man");
set_short("A Pizza Hut Delivery man");
set_long(
"This is a Pizza Hut delivery man, he looks like\n"
+ "he's in a real hurry. You can smell the fresh pizza\n"
+ "in his pouch, it looks like the only way to get it is too kill him!\n");
set_level(14);
set_wc(20);
set_ac(10);
set_hp(200);
set_al(500);
set_race("human");
armour = clone_object("/players/emerson/armor/jacket.c");
if(armour) {
move_object(armour,this_object());
  }
}
