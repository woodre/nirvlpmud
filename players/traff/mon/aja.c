inherit "obj/monster";

reset(arg)
{
  object coins,weapon;
  ::reset(arg);
  if(arg) return;
set_name("aja");
set_race("dog");
set_alias("dog");
set_short("Aja, Traff's Cocker Spaniel");
set_long("A beautiful, golden Cocker Spaniel.\n");
set_level(10);
set_level(10);
set_hp(9999);
set_al(250);
set_wc(14);
set_ac(5);
  set_chat_chance(2);
load_chat("Aja rolls over on her back and goes to sleep.\n");
load_chat("Aja jumps up on her favorite chair and watches you.\n");
  coins=clone_object("obj/money");
  coins->set_money(random(101)+100);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/weps/teeth.c");
  move_object(weapon,this_object());
  init_command("wield teeth");
  call_out("random_move",50);
}
status random_move() {
  int n;
  n = random(2);
switch(n) {
  case 0 : command("north"); break;
  case 1 : command("south"); break;
}
  call_out("random_move",50);
  return 1;
}
