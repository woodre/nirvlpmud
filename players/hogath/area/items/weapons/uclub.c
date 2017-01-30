/*
 *      File:                   uclub.c
 *      Function:               weapon
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 11/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
  
  set_name("Shillelagh");
  set_alt_name("shillelagh");
  set_alias("club");
  set_short(HIC+"Undine Shillelagh"+NORM);
  set_long("A stout wooden club.  This shillelagh was carved from a\n"+
           "single piece of iron wood.  It's three foot length has \n"+
           "been carved and sanded until it is a fashionalbe cudgle.\n"+
           "A single rune of water has been carved into it's grip.\n");
  set_class(19);
  set_value(10000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
  string msg,msg2;
  int W, i;
  W = random(3);
  i = random(100);
  switch(W){
    case 0 : msg = " calls upon"+HIC+" \n\tthe power of the undine as "+poss+" \n\t\tclub strikes"+NORM+" "+atn+".\n";
             msg2 = " call upon"+HIC+" \n\tthe power of the undine as your \n\t\tclub strikes"+NORM+" "+atn+".\n";break;
    case 1 : msg = " "+HIC+"lashes out at\n\t "+atn+" with \n\t\tspirits of the deep.\n"+NORM;
             msg2 = " "+HIC+"lash out at\n\t "+atn+" with \n\t\tspirits of the deep.\n"+NORM;break;
    case 2 : msg = " "+HIC+"calls down\n\t a storm as "+poss+" club \n\t\tconnects with "+atn+".\n"+NORM;
             msg2 = " "+HIC+"call down\n\t a storm as your club \n\t\tconnects with "+atn+".\n"+NORM;break;
    case 3 : msg = ""+HIC+"'s shillelagh glows with elemental might.\n"+NORM;
             msg2 = ""+HIC+"r shillelagh glows with elemental might\n\t\tas you pound "+atn+".\n"+NORM;break;
   }
  
    if (i > 75){
    say(tpn+""+msg);
    write("You"+msg2);
    attacker->hit_player((W+7),"other|water");}
    if ((this_player()->query_attribute("pie")+this_player()->query_attribute("wil") > random(100))){
      tell_object(environment(),
      "The healing power of the Undine flows through you.\n");
      this_player()->add_hit_point(random(3));
    }
  
  return;
}

   
