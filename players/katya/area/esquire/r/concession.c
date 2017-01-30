/*
 *     concession.c              
 *     Katya@Nirvana
 *     Copyright (c) 2004 Katya
 *     All Rights Reserved.
 *    
 */

/* 
 *     Updated by Fred
 *     Price for some heals are quite off.
 *     See individual heals for more info.
 *
 */


#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
/*
#include "/players/vital/dest/include/dest.h"
*/

inherit "room/room";

object Heal;
int Cost;
string What;
     
reset(arg)
 {

   if(!present("trashcan"))
  {
    move_object(clone_object("/players/pathfinder/trashcan.c"),
      this_object());
  }

   if(!present("justin"))
  {
    move_object(clone_object("/players/katya/area/esquire/m/justin.c"),
      this_object());
  }

  if(!arg)
  { 

  set_light(1);
  
  short_desc = HIM+"Concession Stand"+NORM;

  long_desc=
"  Along the back wall of the entrance is a large counter encased in\n\
glass.  Many shelves with several sorts of packaged candy can be seen\n\
through the glass in the counter.  A large neon sign hangs on the wall\n\
behind the counter.  A large black trash can sits beside the counter.\n",  

  items=({
     "walls",
        "The walls seem to have large stains on them from being so old",
     "wall",
        "The walls seem to have large stains on them from being so old",
     "sign",
        "Maybe you should try and read it?",
     "trash can",
        "Large, black plastic trash can that you can throw your trash into",
     "can",
        "Large, black plastic trash can that you can throw your trash into",
     "counter",
       "A large counter made up of glass",
     "entrance",
       "The entrance is to the south",
     "glass",
       "The glass has a few finger smudges on it",
     "shelves",
       "The shelves in the case have candy scattered across them",
     "shelf",
       "The shelves in the case have candy scattered across them",
     "candy",
       "Many different types of candy, perhaps you want to buy some?",
     "packages",
       "Many different types of candy, perhaps you want to buy some?",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/entrance",  "south",
   });}
}
  init() {
     ::init();
  add_action("read_sign","read");
  add_action("cmd_buy","buy");
  add_action("cmd_buy",  "purchase");
  }

read_sign(str) {
  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  else if(str == "sign") {
  write("\
The sign reads:\n\n\
A list of items that one can "+HIM+"buy"+NORM+" here at the concession stand.\n\n\
         1.  Junior Mints  ..................  2135\n\
         2.  Reeses Pieces  .................   800\n\
         3.  Popcorn  .......................  2100\n\
         4.  Medium Soda  ...................  3000\n\
         5.  Nachos with Melted Cheese  .....  3000\n\
         6.  Spring Water  ..................  2135\n\n\
I apologize if you don't see anything that you like.  If you\n\
have any suggestions please feel free to mail Katya.\n\n");

   say(capitalize(this_player()->query_name())+" reads the sign.\n");

   return 1; }
}

cmd_buy(string str)
{
  if(!present("justin", this_object()))
  {
    write("Justin must be working in another part of the theater.\n");
      return 1;
  }

  if(!str){ write("Buy or purchase by number or item name.\n"); return 1; }
  if(str == "1" || str == "junior" || str == "mints" || str == "junior mints" || str == "mint")
  {
    Cost = 2135;
    Heal = CO("/players/katya/area/esquire/heals/mint.c");
    What = ""+YEL+"Junior Mints"+NORM+"";
  }

  else if(str == "2" || str == "reeses" || str == "pieces" || str == "reeses pieces")
  {
    Cost = 800;
    Heal = CO("/players/katya/area/esquire/heals/reeses.c");
    What = ""+YEL+"Reeses Pieces"+NORM+"";
  }

  else if(str == "3" || str == "popcorn")
  {
    Cost = 2100;
    Heal = CO("/players/katya/area/esquire/heals/popcorn.c");
    What = ""+HIW+"Popcorn"+NORM+"";
  }

  else if(str == "4" || str == "soda"  || str == "medium soda")
  {
    Cost = 3000;
    Heal = CO("/players/katya/area/esquire/heals/soda.c");
    What = ""+YEL+"Medium Soda"+NORM+"";
  }

  else if(str == "5" || str == "nachos"  || str == "nachos with melted cheese")
  {
    Cost = 3000;
    Heal = CO("/players/katya/area/esquire/heals/nacho.c");
    What = ""+YEL+"Nachos with Melted Cheese"+NORM+"";
  }

  else if(str == "6" || str == "water"  || str == "bottle"  || str == "spring"  ||  str == "spring water")
  {
    Cost = 2135;
    Heal = CO("/players/katya/area/esquire/heals/water.c");
    What = ""+HIW+"Spring Water"+NORM+"";
  }

  else
  {
    write("Justin says, \"I don't believe we have that item.\"\n");
      return 1;
  }	

  if (call_other(this_player(), "query_money", 0) < Cost) 
  {
    write("Justin says, \"You don't have enough money for that.\"\n");
      return 1;
  }	   	

  if(!this_player()->add_weight(Heal->query_weight())) 
  {
    write("Justin says, \"You can't carry anything else.\"\n");
    destruct(Heal);
      return 1; 
  }			
  write("Justin thanks you as you pay "+Cost+" coins for a "+What+".\n");
  say(this_player()->query_name() + " purchases a "+What+".\n");
  move_object(Heal,this_player());
  this_player()->add_money(-Cost);
    return 1;
}
