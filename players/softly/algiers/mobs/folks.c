#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

int type;

reset(arg) 
{
  ::reset(arg);
  if (arg) return;
  if(!random(11)) man();
  else if(!random(11)) hen();
  else if(!random(11)) woman();
  else if(!random(11)) chicken();
  else if(!random(11)) boy();
  else if(!random(11)) girl();
  else if(!random(11)) maiden();
  else if(!random(11)) dog();
  else if(!random(11)) tot();
  else if(!random(11)) pig();
  else call_out("snake", 0);
}

man()
{
  set_name("man");
  set_short("A working man");
  set_alias("stfolk");
  set_long("A strong man in his early 20s looks as if he is\n"+
	   "in a hurry to get somewhere.  He wears worn dark\n"+
	   "trousers, a clean white t-shirt, and black loafers\n"+
	   "with no socks.  He is muscular and cheerful.\n");
  set_race("human");
  set_gender("male");
  set_level(11);
  set_ac(9);
  set_wc(15);
  set_hp(165);
  set_al(400);
  set_chat_chance (5);
  load_chat("A man whistles a little tune as he walks along ...\n");
  set_wander(20, 0, ({"northeast"}));
  add_money(450+random(50));
}

hen()
{
  type = 0;
  set_name("hen");
  set_short("A hen");
  set_alias("stfolk");
  set_long("A small hen sporting shiny red, green, and brown\n"+
	   "feathers struts across the dusty road, occasionally\n"+
	   "pecking at a seed or a piece of gravel.  It is in\n"+
	   "no hurry to get anywhere.\n");
  set_race("creature");
  set_level(2);
  set_ac(3);
  set_wc(6);
  set_hp(30);
  set_al(0);
  set_chat_chance (5);
  load_chat("kpeck ..     kpeck ..     kpeck ..\n");
  set_wander(10, 0, ({"northeast","enter"}));
  set_dead_ob(this_object());
}

woman()
{
  type = 2;
  set_name("woman");
  set_short("A woman in a thin dress");
  set_alias("stfolk");
  set_long("Long hair streaming behind her, a young woman\n"+
	   "wearing a thin pink dress draped closely over\n"+
	   "her body meanders across the road.  Her bare\n"+
	   "arms hand loosely at her sides and her bare feet\n"+
	   "occasionally kick at the dust.\n");
  set_race("human");
  set_gender("female");
  set_level(9);
  set_ac(7);
  set_wc(13);
  set_hp(135);
  set_al(200);
  set_chat_chance (5);
  load_chat("A woman says: Good day.  How are you?\n");
  set_wander(40, 0, ({"northeast","enter"}));
  add_money(350+random(50));
}

chicken()
{
  type = 0;
  set_name("chicken");
  set_short(YEL+"A brown chicken"+NORM);
  set_alias("stfolk");
  set_long("A brown chicken wearing a bright red comb and\n"+
	   "wattle jerkily walks in the middle of the road.\n"+
	   "He seems to be looking for something.\n");
  set_race("creature");
  set_level(2);
  set_ac(3);
  set_wc(6);
  set_hp(30);
  set_al(0);
  set_wander(15, 0, ({"northeast","enter"}));
  set_dead_ob(this_object());
}

boy()
{
  set_name("boy");
  set_short("A boy");
  set_alias("stfolk");
  set_long("A young boy with scruffy hair wears a bright red\n"+
	   "t-shirt and raggedy cut off jeans.  He kicks at\n"+
	   "stones with his bare feet and occasionally tosses\n"+
	   "a paper airplane into the sky.\n");
  set_race("human");
  set_gender("male");
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(0);
  set_wander(30, 0, ({"northeast","enter"}));
  add_money(225+random(25));
}

girl()
{
  type = 1;
  set_name("girl");
  set_short("A girl");
  set_alias("stfolk");
  set_long("A pretty little girl has stringy hair and a dirty face.\n"+
	   "She wears bright pink shorts and a white t-shirt with\n"+
	   "a picture of a kitten on it.  A broken doll is cradled\n"+
	   "lovingly in her arms.\n");
  set_race("human");
  set_gender("female");
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(0);
  set_chat_chance (5);
  load_chat("A little girl whispers: It's ok dolly.  We'll make you well.\n");
  load_chat("A little girl tugs at your sleeve.  'Where's the doll doctor?'\n");
  set_wander(30, 0, ({"northeast","enter"}));
  add_money(225+random(25));
}

maiden()
{
  set_name("maiden");
  set_short("A young maiden");
  set_alias("stfolks");
  set_long("A very pretty young woman smiles knowingly as she\n"+
	   "lightly wanders down the road.  Her long ightweight\n"+
	   "white dress is dusty at the hem.  In her right hand\n"+
	   "she carries a wilted rose.\n");
  set_race("human");
  set_gender("female");
  set_level(8);
  set_ac(7);
  set_wc(12);
  set_hp(120);
  set_al(400);
  set_chat_chance (5);
  load_chat("A maiden sings softly: 'We're living in a powder keg\n"+
	    "and giving off sparks...'\n");
  load_chat("A maiden sings: 'I guess I'll go on home, it's late\n"+
	    "there'll be tomorrow night, but wait...'\n");
  set_wander(60, 0, ({"northeast","enter"}));
  add_money(300+random(50));
}

dog()
{
  type = 2;
  set_name("dog");
  set_short("A dog");
  set_alias("stfolks");
  set_long("A thin dog roams around in the road, looking\n"+
	   "for treats.  His scruffy black fur is punctuated\n"+
	   "by white patches around his ears and on his chest.\n"+
	   "He looks like he might follow you home.\n");
  set_race("creature");
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(-200);
  set_chat_chance (5);
  load_chat("sniff...       sniff, sniff...\n");
  set_wander(45, 0, ({"northeast","enter"}));
  set_dead_ob(this_object());
}

tot()
{
  set_name("tot");
  set_short("A tot");
  set_alias("stfolks");
  set_long("A young tot of indeterminate age and gender\n"+
	   "has medium length black hair.  The tot wears\n"+
	   "khaki shorts and a bright blue t-shirt and is\n"+
	   "crying while looking for someone.\n");
  set_race("human");
  set_level(4);
  set_ac(4);
  set_wc(8);
  set_hp(60);
  set_al(-100);
  set_wander(60, 0, ({"northeast","enter"}));
  add_money(100+random(50));
}

pig()
{
  type = 3;
  set_name("piglet");
  set_short("A piglet");
  set_alias("stfolks");
  set_long("A small pink piglet wanders about in the road\n"+
	   "searching for it's mother.  The tiny ears and\n"+
	   "high curled tail perk up whenever someone comes\n"+
	   "near.\n");
  set_race("creature");
  set_level(4);
  set_ac(4);
  set_wc(8);
  set_hp(60);
  set_al(-100);
  set_chat_chance(3);
  load_chat("oink....    squee squee....\n");
  set_wander(60, 0, ({"northeast","enter"}));
}


snake()
{
  move_object(clone_object("/players/softly/algiers/mobs/snakes"), this_object());
  destruct(this_object());
}

monster_died() 
{
  object left;
  left = clone_object("/obj/treasure");

  if(type == 0)
    {
      left->set_id("egg");
      left->set_short("White egg");
      left->set_long("This egg is ideal for decoration.  It might have some value.\n");
      left->set_weight(1);
      left->set_value(90);
      tell_room(environment(),"\
As the chicken dies, it leaves a beautiful egg behind.\n");
      move_object(left, environment());
    }

  else if(type == 1)
    {
      left->set_id("doll");
      left->set_short("A broken doll");
      left->set_long("A doll with blue eyes and an arm missing.\n"+
		     "looks like it has been well loved.\n");
      left->set_weight(1);
      left->set_value(0);
      tell_room(environment(),"\
The girl reluctantly releases her doll as she dies.\n");
      move_object(left,environment());
    }

  else if(type == 2)
    {
      left->set_id("collar");
      left->set_short("An ornate collar");
      left->set_long("A hand tooled dog collar with silver studs.\n");
      left->set_weight(1);
      left->set_value(250);
      tell_room(environment(), "\nThe dog dies, looking at you sadly.  His collar\n"+
		"a reminder of happier times, falls to the ground.\n");
      move_object(left,environment());  
    }
  else if(type == 3)
    {
      left->set_id("tail");
      left->set_short("A tiny pig tail");
      left->set_long("A small curly pink tail from a piglet.\n");
      left->set_weight(1);
      left->set_value(25);
      tell_room(environment(), "\nAs the piglet dies he looks longingly up at you.\n"+
		"Heartlessly, you quickly slice his tail from his body.\n");
      move_object(left,environment());  
    }
}



