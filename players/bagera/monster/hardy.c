inherit "obj/monster.c";
reset(arg) {
  ::reset(arg);
  if(!arg) {
object gold;
gold=clone_object("obj/money");
gold->set_money(500+random(450));
move_object(gold, this_object());
 set_name("hardy");
 set_alias("elephant");
 set_alias("colonel");
 set_short("Colonel Hardy");
set_long("You see a large elephant walking back and forth inspecting\n"+
         "his troops.\n");

  set_level(17);
 set_ac(14);
 set_wc(24);
 set_hp(425);
 set_chat_chance(35);
load_chat("Colonel Hardy shouts: Hup 2, 3, 4! Keep it up 2, 3, 4!\n");
set_a_chat_chance(50);
load_a_chat("Colonel Hardy yells: Attack!!!");
 }
}
