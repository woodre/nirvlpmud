#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

int type;

reset(arg) 
{
  ::reset(arg);
  if (arg) return;
  if(!random(8)) ogirl();
  else if(!random(8)) oboy();
  else if(!random(8)) boy();
  else if(!random(8)) girl();
  else if(!random(8)) yboy();
  else if(!random(8)) lboy();
  else if(!random(8)) lgirl();
  else ygirl();

}

ogirl()
{
  set_name("girl");
  set_short("An older girl");
  set_alias("kid");
  set_long("A older girl with short dark hair wears a red\n"+
	   "blouse, jeans, and glasses.  She is holding a\n"+
	   "a pen and a book with a yellow cover.\n");
  set_race("human");
  set_gender("female");
  set_level(8);
  set_ac(7);
  set_wc(12);
  set_hp(120);
  set_al(0);
  add_money(300+random(50));
}

boy()
{
  set_name("boy");
  set_short("A boy");
  set_alias("kid");
  set_long("A young boy with scruffy hair wears a bright green\n"+
	   "sweatshirt and khaki cut off pants.  His sandals\n"+
	   "barely stay on his feet.  He kicks at the air once\n"+
	   "in a while and twirls a pencil.\n");
  set_race("human");
  set_gender("male");
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(0);
  add_money(225+random(25));
}

girl()
{
  type = 1;
  set_name("girl");
  set_short("A girl");
  set_alias("kid");
  set_long("A tall young girl with very long braids stares dreamily\n"+
	   "off into space.  Her shapeless brown dress with a white\n"+
	   "collar hangs off of her as if it once belonged to someone\n"+
	   "else.  She clutches some papers tightly.\n");
  set_race("human");
  set_gender("female");
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(0);
  add_money(225+random(25));
}

oboy()
{
  set_name("boy");
  set_short("A older boy");
  set_alias("kid");
  set_long("A strong older boy with very short hair looks slightly\n"+
	   "out of place with all of the smaller children.  He stares\n"+
	   "intently at the words in a book.  His white t-shirt and\n"+
	   "blue jeans fit very tightly.\n");
  set_race("human");
  set_gender("male");
  set_level(8);
  set_ac(7);
  set_wc(12);
  set_hp(120);
  set_al(0);
  add_money(300+random(50));
}

ygirl()
{
  set_name("girl");
  set_short("A young girl");
  set_alias("kid");
  set_long("Swathed in yellow, a young girl props her head\n"+
	   "on her elbows and stares at the blackboard.  Her\n"+
	   "hair flies out in all directions, as if she might\n"+
	   "have been in an electric storm.\n");
  set_race("human");
  set_gender("female");
  set_level(4);
  set_ac(4);
  set_wc(8);
  set_hp(60);
  set_al(0);
  add_money(100+random(50));
}

yboy()
{
  set_name("boy");
  set_short("A young boy");
  set_alias("kid");
  set_long("A young boy wearing cut off jeans and a light blue\n"+
	   "t-shirt with a picture of a truck on it squirms in\n"+
	   "his chair.  He taps a pencil on his desk and looks\n"+
	   "as if he would rather be anywhere else.\n");
  set_chat_chance (5);
  load_chat("t.tap ... t.tap ... t.tap ... t.tap ...\n");  
  set_race("human");
  set_gender("male");
  set_level(4);
  set_ac(4);
  set_wc(8);
  set_hp(60);
  set_al(0);
  add_money(100+random(50));
}

lgirl()
{
  set_name("girl");
  set_short("A little girl");
  set_alias("kid");
  set_long("A little girl wearing pink shorts and a matching\n"+
	   "pink shirt with a yellow butterfly on it scratches\n"+
	   "at a large piece of paper with crayons, each with\n"+
	   "one flat side.  She is drawing a house.\n");
  set_chat_chance (5);
  load_chat("A girl squeals: Gimme that back!\n");
  set_race("human");
  set_gender("female");
  set_level(3);
  set_ac(4);
  set_wc(7);
  set_hp(45);
  set_al(0);
  add_money(100+random(20));
}

lboy()
{
  set_name("boy");
  set_short("A little boy");
  set_alias("kid");
  set_long("A little boy wears jeans with ragged holes where the\n"+
	   "knees once were and a multi-colored striped shirt.\n"+
	   "His pockets bulge with unknown treasures.  He is\n"+
	   "licking paste from his fingers.\n");
  set_chat_chance (5);
  load_chat("Shoes rhythmically scuff the floor ... worsh ... worsh ...\n");
  set_race("human");
  set_gender("male");
  set_level(3);
  set_ac(4);
  set_wc(7);
  set_hp(45);
  set_al(0);
  add_money(100+random(20));
}

