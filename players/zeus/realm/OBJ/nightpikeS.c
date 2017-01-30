/*  Weight 4,  wc 20,  non-storable, 1:20 special of 6 damage  
Super NightPike:  -1 weight, wears slower.
                   2nd smaller special, 10% of return 3, 
*/
/*  Made storable by Forbin after checking with Zeus */

inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"
#define TQN  +target->QN+

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("nightpike");
  set_alias("pike");
  set_type("spear");
  set_short(BOLD+"NightPike"+NORM);
  set_long(
"This is the legendary "+BOLD+"NightPike"+NORM+".  The pike itself is four feet\n"+
"long, with a long and narrow metal head.  The pike is made of a wood that\n"+
"is as black as night, and has tiny white spots all across it.  A dark energy\n"+
"resides within the magical wood of the "+BOLD+"NightPike"+NORM+".\n");
  set_value(1800);
  set_weight(3);
  set_class(20);
  set_read(0);
  /* changed to darkness damage by Fred   
  set_hit_func(TO);
  */
  set_params("other|dark",0,"dark_hit");
  message_hit=({
    HIR+"impaled"+NORM," with a deadly attack",
    BOLD+"pierced"+NORM," with incredible force",
    BOLD+"stabbed"+NORM," with a strong blow",
    BOLD+"wounded"+NORM," with a hard thrust",
    "grazed","",
    "grazed","",
    "grazed","",
  });
}

/*
query_save_flag(){    return 1; }

query_dest_flag() { return 1; }
2005.02.19 Forbin */

int dark_hit(object target){
	if(random(100) < 5)
	{
write("\nYou impale the "+BOLD+"NightPike"+NORM+" deep into "TQN"...\n"+
"A funnel of darkness pours from the "+BOLD+"NightPike"+NORM+" into "TQN"...\n");
write("\n\t\t"TQN" screams in terror!\n\n");
say(
"\n"+ENV->QN+" impales the "+BOLD+"NightPike"+NORM+" deep into "TQN"...\n"+
"A funnel of darkness pours from the "+BOLD+"NightPike"+NORM+" into "TQN"...\n");
say("\n\t\t"TQN" screams in terror!\n\n");
	return 6;
	}
    else if(!random(10))
    {
      tell_object(environment(),
        "Your "+BOLD+"NightPike"+NORM+" radiates darkness!\n");
      tell_room(environment(),
        environment()->QN+"'s "+BOLD+"NightPike"+NORM+" radiates darkness!\n", 
        ({ environment() }));
      return 3;
    }
}

query_wear(){
  int wear;
  wear = 3*misses/5 + 2*hits/11;
  return wear;
}
