#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

int type;

reset(arg) 
{
  ::reset(arg);
  if (arg) return;
  if(!random(9)) man();
  else if(!random(9)) hen();
  else if(!random(9)) woman();
  else if(!random(9)) chicken();
  else if(!random(9)) boy();
  else if(!random(9)) girl();
  else if(!random(9)) maiden();
  else if(!random(9)) dog();
  else if(!random(9)) tot();

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
  set_level(11);
  set_ac(9);
  set_wc(15);
  set_hp(165);
  set_al(400);
  set_wander(20, 0);
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
  set_level(2);
  set_ac(3);
  set_wc(6);
  set_hp(30);
  set_al(0);
  set_wander(10, 0);
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
  set_level(9);
  set_ac(7);
  set_wc(13);
  set_hp(135);
  set_al(200);
  set_wander(40, 0);
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
  set_level(2);
  set_ac(3);
  set_wc(6);
  set_hp(30);
  set_al(0);
  set_wander(15, 0);
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
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(0);
  set_wander(30, 0);
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
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(0);
  set_wander(30, 0);
  add_money(225+random(25));
}

maiden()
{
  type = 6;
  set_name("maiden");
  set_short("A young maiden");
  set_alias("stfolks");
  set_long("A very pretty young woman smiles knowingly as she\n"+
	   "lightly wanders down the road.  Her long ightweight\n"+
	   "white dress is dusty at the hem.  In her right hand\n"+
	   "she carries a wilted rose.\n");
  set_level(8);
  set_ac(7);
  set_wc(12);
  set_hp(120);
  set_al(400);
  set_wander(60, 0);
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
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(-200);
  set_wander(45, 0);
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
  set_level(4);
  set_ac(4);
  set_wc(8);
  set_hp(60);
  set_al(-100);
  set_wander(60, 0);
  add_money(100+random(50));
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
      left->set_id("pin");
      left->set_short("Bright pin");
      left->set_long("A bright goldish pin with glass stones.\n");
      left->set_weight(1);
      left->set_value(100);
      tell_room(environment(),"\
As the woman dies, her pin falls noisily to the floor.\n");
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
      left->set_id("plate");
      left->set_short("Collection plate");
      left->set_long("A shiny flat plate made to hold church offerings.\n");
      left->set_weight(1);
      left->set_value(40);
      tell_room(environment(), "\nAs the usher expires, his collection plate flies\n"+
		"from his grasp, clattering loudly on the floor.\n");
      move_object(left,environment());  
    }
}



