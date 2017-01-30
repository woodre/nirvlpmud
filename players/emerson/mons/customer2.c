
inherit"obj/monster";
reset(arg) {
object food, gold;
gold = clone_object("obj/money");
gold -> set_money((500));
move_object(gold,this_object());
::reset(arg);
if(arg) return;
set_name("customer");
set_alias("patron");
set_short("A Pizza Hut Customer");
set_long(
"This is a Pizza Hut patron, he looks like\n"
+ "he's really hungry. You can smell the fresh breadstick\n"
+ "on his plate, it looks like the only way to get it is too kill him!\n");
set_level(13);
set_wc(17);
set_ac(10);
set_hp(195);
set_al(-500);
set_race("human");
food = clone_object("/players/emerson/heal/breadstick.c");
if(food) {
move_object(food,this_object());
  }
}
