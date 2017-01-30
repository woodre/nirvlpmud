/**********************************************************/
/*  With this 'container' players can use my 3 pill heals from
/*  within it, without having to take them out.  Saves on carry,
/*  and makes the fact that they are 1 shot heals not matter.
/*  This object is not an actual container.
/**********************************************************/

inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
int max, pills, zp1, zp2, zp3;
reset(arg){

  max = 80;
  pills = 0;
  zp1 = 0;
  zp2 = 0;
  zp3 = 0;
  set_value(100);
  set_save_flag(1);
}
id(str){ return str == "bottle" || str == "zeus_pill_bottle"; }
query_weight(){ return 1+(pills/8); }

short()
{
  if(this_player() == environment())
    return "A white pill bottle ["+zp1+","+zp2+","+zp3+"]";
  else
    return "A white pill bottle";
}

long()
{
  write(
"This is a small white bottle for keeping pills in.  You can\n"+
"'fill' the 'bottle' up with pills from your inventory, and\n"+
"then 'pop' the pills from within the bottle.\n");
}

void init()
{
	::init();
  add_action("pop_cmd", "pop");
  add_action("fill_cmd", "fill");
}

fill_cmd()
{
  int x, didya;
  object room;
  didya = 0;
  if(!environment()) return;
  room = all_inventory(environment());
  if(str != "bottle") return 0;
  for(x = 0; x < sizeof(room); x++)
  {
	if(room[x]->query_info() == "zp1" ||
		room[x]->query_info() == "zp2" ||
		room[x]->query_info() == "zp3")
	{
	  if(pills < max)
	  {
	    move_object(room[x], this_object());
		if(room[x]->query_info() == "zp1")
			zp1++;
		else if(room[x]->query_info() == "zp2")
			zp2++;
		else if(room[x]->query_info() == "zp3")
			zp3++;
		pills++;
		didya = 1;
	  }
	}
  }
  if(didya)
  {
    write("You fill the bottle up with pills.\n");
    this_player()->recalc_carry();
  }
  return 1;
}

pop_cmd(str)
{
  object pill;
  if(str != "zp1" && str != "zp2" && str != "zp3") return 0;
  pill = present(str, this_object());
  if(!pill)
  {
	write(BOLD+"You are all out of those.\n"+NORM);
	return 1;
  }
  else
  {
	move_object(pill, this_player());
	pill->pop_cmd(str);
	this_player()->recalc_carry();
  }
  return 1;
}


