inherit "obj/monster.c";
reset(arg) {
  ::reset(arg);
  if(!arg) {
object gold;
 set_name("louie");
 set_alias("king");
set_short("King Louie, the king of the jungle");
set_long("King Louie is a large orangutan. His arms hang to the\n"+
          "ground and he is very hairy. He sits upon his throne and\n"+
          "pops in banana after banana into his mouth.\n");
  set_level(10);
 set_ac(8);
  set_wc(14);
 set_hp(150);
 set_al(100);
 set_chat_chance(10);
load_chat("Louie sings: I'm the king of the swingers, yeah! The jungle V.I.P!!\n");
set_a_chat_chance(50);
load_a_chat("Louie shoots a banana at you!\n");
gold=clone_object("obj/money");
gold->set_money(450);
move_object(gold, this_object());
 }
}
