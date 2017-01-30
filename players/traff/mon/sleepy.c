inherit "obj/monster";

reset(arg)
{
  object coins,weapon;
  ::reset(arg);
  if(arg) return;
    set_name("soldier");
    set_race("human");
    set_alias("sleepy");
    set_short("Sleepy soldier");
    set_long("A sleepy soldier standing duty on the wall.\n");
    set_level(10);
    set_hp(150);
    set_al(-250);
    set_wc(13+random(3));
    set_ac(7+random(3));
  set_chat_chance(15);
  set_a_chat_chance(25);
load_chat("Soldier mumbles: Got to stay awake or they'll make a halfling of me!\n");
load_chat("Soldier yawns, then blinks several times.\n");
load_chat("The soldier's chin drops to his chest for a moment.\n");
load_chat("Soldier says: With all the new taxes you would think I could get a raise!\n");
load_a_chat("Soldier says: I wasn't asleep this time, really I wasn't!\n");
load_a_chat("Soldier smiles: They should give me a nice reward for killing you!\n");
  coins=clone_object("obj/money");
  coins->set_money(random(101)+400);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/weps/sword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
}
