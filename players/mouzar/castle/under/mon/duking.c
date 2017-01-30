inherit"obj/monster";
reset(arg) {
object gold;
object armor;
object treasure;
::reset(arg);
if(arg) return;
set_name("king");
set_alias("duergar");
set_short("Duergar King");
set_long(
"This is the proud ruler of the Duergar community.  He is well intoxicated\n"
+ "but he can surely pack a punch.  He wears his crown/helmet proudly cause\n"
+ "they have just pushed back the drow party that had envaded their \n"
+ "community.\n");
set_level(20);
set_al(-500);
set_race("dwarf");
set_hp(500);
set_wc(30);
set_ac(17);
set_aggressive(1);
gold = clone_object("obj/money");
  gold->set_money(random(300));
  move_object(gold,this_object());
armor = clone_object("/players/mouzar/castle/under/obj/duboots");
  move_object(armor,this_object());
treasure = clone_object("/players/mouzar/castle/under/obj/duhelmet");
  move_object(treasure,this_object());
}
