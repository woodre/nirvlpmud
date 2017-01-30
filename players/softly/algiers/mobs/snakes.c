#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

int type;

reset(arg) 
{
  ::reset(arg);
  if (arg) return;
  if(!random(6)) snake1();
  else if(!random(6)) snake2();
  else if(!random(6)) snake3();
  else if(!random(6)) snake4();
  else if(!random(6)) snake5();
  else if(!random(6)) snake6();
  else snake7();
}

snake1()
{
  type = 1;
  set_name("snake");
  set_short(YEL+"Yellow snake"+NORM);
  set_alias("yellow");
  set_long("The large yellow snake is nearly six feet long.\n"+
	   "Its black tongue darts out of the flat elongated head\n"+
	   "tasting your presence.  Powerful muscles move it along\n"+
	   "quickly.\n");
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(0);
  set_race("snake");
  set_dead_ob(this_object());
}

snake2()
{
  type = 1;
  set_name("snake");
  set_short(YEL+"R"+BLK+BOLD+"at"+NORM+YEL+"t"+BLK+BOLD+"le"+NORM+YEL+"s"+BLK+BOLD+"na"+NORM+YEL+"k"+BLK+BOLD+"e"+NORM);
  set_alias("rattlesnake");
  set_long("The rattler halts occasionally to taste the air and\n"+
	   "warn you away.  His multi-shaded brown scales are\n"+
	   "arranged in a characteristic diamond pattern.\n");
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(0);
  set_race("snake");
  set_dead_ob(this_object());
}

snake3()
{
  type = 0;
  set_name("snake");
  set_short(MAG+"Water snake"+NORM);
  set_alias("water");
  set_long("The 4 foot long dark snake has an orange belly.\n"+
	   "Large bright eyes in it's dark head glance about\n"+
	   "as he tries to make his escape.\n");
  set_level(5);
  set_ac(5);
  set_wc(9);
  set_hp(75);
  set_al(0);
  set_race("snake");
  set_dead_ob(this_object());
}

snake4()
{
  type = 0;
  set_name("snake");
  set_short(BLK+BOLD+"Pine snake"+NORM);
  set_alias("pine");
  set_long("A long, slim but muscular black snake glistens\n"+
	   "as it races to escape its long period of captivity.\n");
  set_level(5);
  set_ac(5);
  set_wc(9);
  set_hp(75);
  set_al(0);
  set_race("snake");
  set_dead_ob(this_object());
}

snake5()
{
  type = 0;
  set_name("snake");
  set_short(HIW+"Buttermilk racer"+NORM);
  set_alias("racer");
  set_long("Lightly speckled, the five foot long snake is agile\n"+
	   "as it slithers toward freedom.\n");
  set_level(5);
  set_ac(5);
  set_wc(9);
  set_hp(75);
  set_al(0);
  set_race("snake");
  set_dead_ob(this_object());
}

snake6()
{
  type = 1;
  set_name("snake");
  set_short(HIR+"St"+BLK+BOLD+"r"+HIW+"ip"+BLK+BOLD+"e"+HIR+"d S"+BLK+BOLD+"n"+HIW+"ak"+BLK+BOLD+"e"+NORM);
  set_alias("girl");
  set_long("The three foot striped snake has red, black and\n"+
	   "white bands.  Or are they red, white and black?\n"+
	   "It moves slowly, savoring freedom.\n");
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(0);
  set_race("snake");
  set_dead_ob(this_object());
}

snake7()
{
  type = 0;
  set_name("snake");
  set_short(HIG+"Green snake"+NORM);
  set_alias("green");
  set_long("Lightly speckled, the five foot long snake is agile\n"+
	   "as it slithers toward freedom.\n");
  set_level(5);
  set_ac(5);
  set_wc(9);
  set_hp(75);
  set_al(0);
  set_race("snake");
  set_dead_ob(this_object());
}

monster_died() 
{
  object left;

  if(type == 0)
    {
      left = clone_object("obj/money");
      left->set_money(160+random(40));
      move_object(left,environment(this_object()));
      tell_room(environment(),"\
The dying snake curls up and flops to the side revealing some coins.\n");
      move_object(left, environment());
    }

  else if(type == 1)
    {
      left = clone_object("obj/money");
      left->set_money(220+random(30));
      move_object(left,environment(this_object()));
      tell_room(environment(),"\
In death the snake jerks and rolls to the side, revealing some coins.\n");
      move_object(left,environment());
    }
}
