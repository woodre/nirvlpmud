#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

int type;

reset(arg) 
{
  ::reset(arg);
  if (arg) return;
  if(!random(8)) lr();
  else if(!random(8)) ct();
  else if(!random(8)) sg();
  else if(!random(8)) gh();
  else if(!random(8)) ha();
  else if(!random(8)) bl();
  else if(!random(8)) as();
  else gt();               
}

lr()
{
  set_name("cock");
  set_short(HIR+"La"+NORM+YEL+"cey"+BLU+" ro"+CYN+"und"+BLK+BOLD+"head"+NORM);
  set_alias("gamecock");
  set_long("A strong gamecock with a small red head, bronze,n"+
	   "blue, and black feathered body, golden neck, and\n"+
	   "huge dark green plume of a tail stands proudly.\n"+
	   "A gaff has been attached to his ???? te t-shirt, and black loafers\n"+
	   "with no socks.  He is muscular and cheerful.\n");
  set_level(6);

}

ct()
{
  set_name("cock");
  set_short(HIR+"Cr"+NORM+YEL+"ipp"+BOLD+BLK+"le tony round"+NORM+GRN+"head"+NORM);
  set_alias("gamecock");
  set_long("A small red headed gamecock with heavy bronze feathers\n"+
	   "on its neck, blue black body, and a dark green plumed\n"+
	   "tail feathers with a small patch of grey at the base.\n"+
	   "A gaff is attached to its strong pale yellow legs.\n");
  set_level(6);

}

sg()
{
  set_name("cock");
  set_short(BOLD+BLK+"Sla"+NORM+BOLD+"vin gr"+BOLD+BLK+"ey"+NORM);
  set_alias("gamecock");
  set_long("A solidly built yellow-white gamecock with a\n"+
	   "very dark grey head, neck and tail is champing\n"+
	   "at the bit for its match to begin.  His yellow\n"+
	   "legs and feet scratch at the earth.  A gaff is\n"+
	   "attached to his legs.\n");
  set_level(6);

}

gh()
{
  set_name("cock");
  set_short(YEL+"Grey roundhead"+NORM);
  set_alias("gamecock");
  set_long("The pale yellow body and neck feathers of the\n"+
	   "proud gamecock are very full.  Its leg and tail\n"+
	   "feathers are a glossy black.  He is in fighting\n"+
	   "trim, a gaff attached to his legs.\n");
  set_level(6);

}

ha()
{
  set_name("cock");
  set_short(HIR+"H"+BOLD+BLK+"atch"+NORM);
  set_alias("gamecock");
  set_long("A Strong gamecock covered with glossy black feathers\n"+
	   "punctuated with his red wattle and pale yellow legs\n"+
	   "claws at the earthen pit, ready to begin a fight with\n"+
	   "any other cock nearby.\n");
  set_level(6);

}

bl()
{
  set_name("cock");
  set_short(YEL+"Bl"+BLU+"ue hen"+NORM);
  set_alias("gamecock");
  set_long("A solid, strong gamecock covered with thick shiny blue\n"+
	   "grey feathers is ornamented with golden feather patches\n"+
	   "on its neck.  His strong pale grey legs have been fitted\n"+
	   "with a gaff and he stands anxious to fight.\n");
  set_level(6);

}
gt()
{
  set_name("cock");
  set_short(BOLD+BLK+"Grey toppie"+NORM);
  set_alias("gamecock");
  set_long("A solid, strong gamecock covered with thick shiny blue\n"+
	   "grey feathers with a string grey tail.  His strong pale\n"+
	   "yellow legs have been fitted with a gaff.  He claws at\n"+
	   "the earthen pit while waiting to fight.\n");
  set_level(6);

}

as()
{
  set_name("cock");
  set_short(YEL+"A"+CYN+"sil"+NORM);
  set_alias("gamecock");
  set_long("A strong gamecock with a small red head, bronze,n"+
	   "blue, and black feathered body, golden neck, and\n"+
	   "huge dark green plume of a tail stands proudly.\n"+
	   "A gaff has been attached to his ???? te t-shirt, and black loafers\n"+
	   "with no socks.  He is muscular and cheerful.\n");
  set_level(6);

}

wc()
{
  set_name("cock");
  set_short(BOLD+"White claret"+NORM);
  set_alias("gamecock");
  set_long("A pure white, short solid gamecock with a horizontal\n"+
	   "plume of tail feathers.\n");
  set_level(6);

}

