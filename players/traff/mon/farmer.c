inherit "obj/monster";

reset(arg)
{
  object coins,weapon;
  ::reset(arg);
  if(arg) return;
set_name("farmer");
set_race("human");
set_alias("zeke");
set_short("Zeke, the Farmer");
set_long(
"Zeke is a sturdy looking farm hand.  In better times he managed\n"+
"to stay steadily employed.  With so many farms closing due to\n"+
"high taxes, he has been spending a lot of time here at the tavern.\n"+
"Zeke sometimes has a mean streak after drinking.\n");
set_level(10);
set_hp(150);
set_al(-250);
set_wc(13+random(3));
set_ac(7+random(3));
  set_chat_chance(15);
  set_a_chat_chance(25);
load_chat("Zeke winks at Jill.\n");
load_chat("Zeke looks at you and grins, for no apparent reason.\n");
load_chat("Zeke says: Those crazy rebels are trying to get supplies from the local farms.\n");
load_chat("Zeke sneezes.  AAHCOOOOO!  He wipes his nose on his sleeve.\n");
load_a_chat("Zeke charges you wildly!\n");
load_a_chat("Zeke chuckles: I'll hang you up and dress you like a side of beef.\n");
load_a_chat("Zeke says: JILL!  Draw me another beer, I'll need it when I'm done here!\n");
load_a_chat("Zeke ducks behind a table.\n");
  coins=clone_object("obj/money");
  coins->set_money(random(100)+400);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/weps/hayhook.c");
  move_object(weapon,this_object());
  init_command("wield hayhook");
}
