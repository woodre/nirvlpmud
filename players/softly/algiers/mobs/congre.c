#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

int type;

reset(arg) 
{
  ::reset(arg);
  if (arg) return;
  if(!random(7)) man1();
  else if(!random(7)) man2();
  else if(!random(7)) woman1();
  else if(!random(7)) woman2();
  else if(!random(7)) kid1();
  else if(!random(7)) kid2();
  else if(!random(7)) deacon();
  else usher();
}

man1()
{
  type = 0;
  set_name("man");
  set_short("A heavy man");
  set_alias("heavy");
  set_long("The heavy man has the sleeves of his pale blue\n"+
	   "shirt pushed up.  A damp handkerchief peeks out\n"+
	   "from the pocket of his dark trousers.  He wears\n"+
	   "a broad smile.\n");
  set_race("human");
  set_gender("male");
  set_level(11);
  set_ac(9);
  set_wc(15);
  set_hp(165);
  set_al(0);
  add_money(450+random(50));
}

man2()
{
  type = 1;
  set_name("man");
  set_short("A tall man");
  set_alias("tall");
  set_long("A tall man with short wavy hair and very small\n"+
	   "ears wears a dark pin striped suit, a gleaming\n"+
	   "white shirt, red silk tie, and polished black and\n"+
	   "white spectators.\n");
  set_race("human");
  set_gender("male");
  set_level(12);
  set_ac(9);
  set_wc(16);
  set_hp(180);
  set_al(0);
  add_money(500+random(50));
}

woman1()
{
  type = 2;
  set_name("woman");
  set_short("A buxom woman");
  set_alias("buxom");
  set_long("Dressed in a wrapped lilac dress with a bright\n"+
	   "pin holding it closed at the neck, the buxom\n"+
	   "woman is overcome with a look of reverence.\n"+
           "The tall yellow feather on her head bobs in time\n"+
	   "to the music.\n");
  set_race("human");
  set_gender("female");
  set_level(9);
  set_ac(7);
  set_wc(13);
  set_hp(135);
  set_al(0);
  add_money(200+random(100));
  set_dead_ob(this_object());
}

woman2()
{
  type = 3;
  set_name("woman");
  set_short("A tiny woman");
  set_alias("tiny");
  set_long("Small but muscular, this woman wears a bright\n"+
	   "green suit over yellow blouse and a yellow hat.\n"+
	   "Her hands tightly grip her black pocketbook.\n");
  set_race("human");
  set_gender("female");
  set_level(10);
  set_ac(8);
  set_wc(14);
  set_hp(150);
  set_al(0);
  add_money(425+random(25));
}

kid1()
{
  type = 4;
  set_name("boy");
  set_short("A boy");
  set_alias("boy");
  set_long("A boy, perhaps 10 years old, appears uncomfortable\n"+
	   "in his starched white shirt, black pants, and stiff\n"+
	   "belt.  His hard leather shoes look barely worn.\n");
  set_race("human");
  set_gender("male");
  set_level(7);
  set_ac(6);
  set_wc(11);
  set_hp(105);
  set_al(0);
  add_money(225+random(25));
}

kid2()
{
  type = 5;
  set_name("girl");
  set_short("A girl");
  set_alias("girl");
  set_long("The braids in the young girl's hair are anchored\n"+
	   "with pink barrettes that match her ruffled dress.\n"+
	   "A light weight pink sweater swings from her shoulders.\n");
  set_race("human");
  set_gender("female");
  set_level(6);
  set_ac(5);
  set_wc(10);
  set_hp(90);
  set_al(35);
  set_dead_ob(this_object());
  add_money(200+random(25));
}

deacon()
{
  type = 6;
  set_name("deacon");
  set_short("An elderly gentleman");
  set_alias("gentleman");
  set_long("A large elderly gentleman stands tall in his light\n"+
	   "grey suit.  A matching grey tie is draped down the\n"+
	   "front of his white shirt.  He seems to be a deacon.\n");
  set_race("human");
  set_gender("male");
  set_level(12);
  set_ac(9);
  set_wc(15);
  set_hp(180);
  set_al(0);
  add_money(300+random(250));
}

usher()
{
  type = 7;
  set_name("usher");
  set_short("A church usher");
  set_alias("man");
  set_long("An energetic man wearing a black suit, white\n"+
	   "shirt, and black tie wanders about the back of\n"+
	   "the sanctuary carrying a collection plate and a\n"+
	   "small stack of programs.\n");
  set_race("human");
  set_gender("male");
  set_level(13);
  set_ac(10);
  set_wc(17);
  set_hp(195);
  set_al(0);
  add_money(500+random(60));
  set_dead_ob(this_object());
}


monster_died() 
{
  object left;
  left = clone_object("/obj/treasure");

  if(type == 2)
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

  else if(type == 4)
    {
      left->set_id("yoyo");
      left->set_short("A red yoyo");
      left->set_long("A worn red yoyo with a twisted string.\n");
      left->set_weight(1);
      left->set_value(25);
      tell_room(environment(),"\
The boy dies and a red yoyo falls from his pocket.\n");
      move_object(left,environment());
    }

  else if(type == 7)
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

attacked_by(ob) 
{ 
  if(!environment()->query_snaked()) environment()->make_snakes(); 
  ::attacked_by(ob); 
}


