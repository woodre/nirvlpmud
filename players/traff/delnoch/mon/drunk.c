inherit "obj/monster";

reset(arg)
{
  object coins;
  ::reset(arg);
  if(arg) return;
set_name("drunk");
set_race("human");
set_alias("man");
set_short("Drunk");
set_long("A burly fellow, who is really, REALLY, drunk!\n");
set_level(5);
set_hp(120);
set_al(-100);
set_wc(6);
set_ac(3);
if(random(10)==0) {set_aggressive(1);}
set_whimpy(1);
  set_chat_chance(20);
  set_a_chat_chance(25);
load_chat("Drunk mutters: I wasn't always like this you know.\n");
load_chat("Drunk mumbles: It's Casca and his taxes that drove me to drink.\n");
load_chat("The drunk starts to stand, then slumps back in his seat.\n");
load_chat("The drunk snores loudly!\nZZZZZZZZZZZ!\n");
load_chat("Drunk whimpers: Casca's minions are following me.  I tell you\n"+
"I have seen them!\n");
load_a_chat("Drunk roars: Go ahead and kill me!  I'll be better off dead!\n");
load_a_chat("Drunk rages: You took my farm and my wife!  I'm going to kill you now!\n");
  coins=clone_object("obj/money");
  coins->set_money(random(26)+125);
  move_object(coins,this_object());
}
