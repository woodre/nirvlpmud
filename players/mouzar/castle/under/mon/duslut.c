inherit"obj/monster";
object gold;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("slut");
set_alias("duergar");
set_short("Duergar Slut");
set_long(
"This is one UGLY female.  She has whiskers!!!!!  How can these Duergar\n"
+ "Make love to something like this.  Just looking at her makes your feel\n"
+ "funny.  Now if you are a dwarf things are a little differnt.  This\n"
+ "female is a cross between the dudes from ZZTop and Sean Yseult.\n");
set_level(10);
set_al(-300);
set_race("dwarf");
set_hp(300);
set_wc(13);
set_ac(8);
gold = clone_object("obj/money");
  gold->set_money(random(450));
  move_object(gold,this_object());
}
