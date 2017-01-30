inherit "obj/monster";

reset(arg)
{
  object coins,food;
  ::reset(arg);
  if(arg) return;
set_name("cook");
set_race("human");
set_alias("gertrude");
set_short("Gertrude, the cook");
set_long(
"From the looks of her, Gertrude must be a good cook.  An enormous,\n"+
"middle aged woman, she looks quite at home here.  She is very\n"+
"busy cooking and supervising the helpers.  She peeks in the\n"+
"oven and then checks a pan on the stove.\n");
set_level(16);
set_hp(350+random(75));
set_al(650);
set_wc(21+random(3));
set_ac(12+random(3));
  set_chat_chance(15);
  set_a_chat_chance(25);
load_chat("A boy sneaks in and swipes a roll, then heads back to the scullery.\n");
load_chat("Gertrude says: No matter who rules here, they all rely on ol' Gert for hot meals.\n");
load_chat("Gertrude says: Welcome friend.\n");
load_chat("Gertrude asks: Any word from the mountains?\n");
load_chat("Gertrude wipes a spill from the counter top.\n");
load_a_chat("Gertrude says: I've dealt with worse than the likes of you!\n");
load_a_chat("Gertrude roars: Get out!  Get out of my kitchen!\n");
  coins=clone_object("obj/money");
  coins->set_money(random(175)+750);
  move_object(coins,this_object());
  food = clone_object("/players/traff/misc/roll.c");
  move_object(food,this_object());
}
