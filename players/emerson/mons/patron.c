
inherit"obj/monster";
reset(arg) {
object gold;
gold = clone_object("obj/money");
gold -> set_money((850));
move_object(gold,this_object());
::reset(arg);
if(arg) return;
set_name("customer");
set_alias("patron");
set_short("A Pizza Hut Patron");
set_long(
"This is a Pizza Hut patron, he looks like\n"
+ "he's really hungry. He is patiently waiting for a table.\n");
set_level(14);
set_wc(18);
set_ac(11);
set_hp(200);
set_al(500);
set_race("human");
  }
