inherit "obj/monster.c";
reset(arg) {
  ::reset(arg);
  if(!arg) {
     object gold;
gold=clone_object("obj/money");
gold->set_money(300+random(100));
move_object(gold, this_object());
 set_name("ramos");
 set_alias("wolf");
 set_short("Ramos, leader of the council");
  set_long("A large grey wolf. He stands tall as he heads the council of wolves.\n");
  set_level(10);
 set_ac(8);
 set_wc(14);
 set_hp(150);
 set_al(300);
 set_chat_chance(15);
  load_chat("Ramos says: We have to send Mowgli back to the man-village.\n");
set_a_chat_chance(50);
load_a_chat("Ramos curls his lips back and snarls at you!\n");
load_a_chat("Ramos leaps for your throat, snapping ferociously.\n");
 }
}
