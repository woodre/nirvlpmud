inherit "obj/monster";

reset(arg)
{
object coins,doodad;
  ::reset(arg);
  if(arg) return;
    set_name("girl");
    set_race("human");
    set_alias("woman");
    set_short("Serving Girl");
    set_long(
"One of the many serving girls employed by the Keep.  She serves\n"+
"food during the meals and helps clean up between meals.  She looks\n"+
"rather ordinary, but you suspect there is more to her than you see\n"+
"at first glance.\n");
    set_level(16);
    set_hp(300+random(125));
    set_al(550);
    set_wc(22);
    set_ac(13);
  set_chat_chance(10);
  set_a_chat_chance(15);
load_chat("The girl listens intently.\n");
load_chat("The girl scrubs the tables and appears bored.\n");
load_chat("The girl brings a pot of tea.\n");
load_chat("Girl whispers to you: Beware.  Casca's minions are everywhere.\n");
load_a_chat("Tenaka will feed your innards to the buzzards!\n");
load_a_chat("Girl says: When you fight with me you fight with the Dragon!\n");
  coins=clone_object("obj/money");
  coins->set_money(random(250)+650);
  move_object(coins,this_object());
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
