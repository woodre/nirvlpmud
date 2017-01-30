inherit "obj/monster";

reset(arg)
{
  object coins;
  ::reset(arg);
  if(arg) return;
set_name("minion");
set_race("human");
set_alias("evil");
set_short();
set_long(
"One of Casca's evil minions.  He is dressed in black and is an\n"+
"expert at skulking in the shadows, gathering information for\n"+
"his master.\n");
set_level(13);
set_hp(195);
set_al(-500);
set_wc(19);
set_ac(10);
if(random(100)==0) {set_aggressive(1);}
  set_chat_chance(1);
  set_a_chat_chance(10);
load_chat("You get the feeling that you are being watched.\n");
load_chat("You sense the presence of evil nearby.\n");
load_a_chat("Minion spits: Fool!  You don't stand a chance against us!\n");
load_a_chat("Minion whispers: I hope I'm there when they turn you into a halfling.\n");
  coins=clone_object("obj/money");
  coins->set_money(666);
  move_object(coins,this_object());
}
