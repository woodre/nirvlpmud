
inherit"obj/monster";
reset(arg) {
object treasure;
object gold;
string chat_str;
::reset(arg);
if(arg) return;
set_chat_chance(20);
load_chat("Wife crys!!\n");
set_name("wife");
set_alias("duergar");
set_short("Crying Wife");
set_long(
"This Duergar is crying over her dying husband.  Her beard is braided up\n"
+ "into a bun like design.  Her eyes are red from crying.  Her hands are\n"
+ "soaked with her husbands blood as she holds his dying body in her hands.\n");
set_level(15);
set_al(-200);
set_race("dwarf");
set_hp(225);
set_wc(15);
set_ac(10);
gold = clone_object("obj/money");
  gold->set_money(900+random(100));
  move_object(gold,this_object());
treasure = clone_object("/players/mouzar/castle/under/obj/duhkc");
  move_object(treasure,this_object());
}
