/*                                                                    *
 *    File:             /players/angel/area/stargate/room/ar.c        *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";
/*
string what;

int cost;

object item, private;
*/
/* The NPC code had to be placed outside the reset inorder for\n\
 * the NPC's roam to kick in when loaded */
void reset(int arg){
  if(arg) return;
  if( !present("private", this_object()) )
    call_out("get_private", 1);
  if( !present("mp", this_object()) )
    call_out("get_mp", 1);
  ::reset(arg);
  set_light(1);
  short_desc = HIC+"ARMORY"+NORM;
  long_desc =
"    "+HIC+"~ ARMORY ~"+NORM+"\n\
"+CYN+"  This is the main armory at Stargate Command, several smaller arms\n\
lockers like this can be found throughout the base. This armory is\n\
equipped with bullet-proof gear, P-90's and other Earth equipment.\n\
The armory is stocked with alien weaponry, such as zatnikatels and\n\
staff weapons in the event an intruder cannot be disabled otherwise."+NORM+"\n";

  items =
  ({
    "armory",
    "military weapon storage",
    "arms",
    "weapons",
    "lockers",
    "metal spaces to hold personal affects",
    "base",
    "A large underground falicity that shelters military equipment and personnel",
    "gear",
    "It is locked up and not accessable",
    "P90",
    "A machine gun",
    "equipment",
    "It is locked up and not accessable",
    "weaponary",
    "It is locked up and not accessable",
    "zatnikatels",
    "A weapon formed in the shape of a coiled serpent",
    "staff",
    "A weapon of Goa'uld design",
    "weapons",
    "many types of hand guns",
    "intruder",
    "usually an enemy",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall5",  "east",
  });
}

void get_private(){
  move_object(clone_object("/players/angel/area/stargate/npc/private.c"), this_object());
  tell_room(this_object(), "A private arrives.\n");
}

void get_mp(){
  move_object(clone_object("/players/angel/area/stargate/npc/private_02.c"), this_object());
  tell_room(this_object(), "An MP arrives.\n");
}
/*
init()
  {
  ::init();
  add_action("buy_it","buy");
  add_action("list_it","list");
  }
list_it()
  {
  write(
      "00000000000000000000000000000000000000000\n\
       1."+HIY+" "+NORM+BOLD+"       1000"+NORM+"\n\
       2."+RED+" "+NORM+BOLD+"       1000"+NORM+"\n\
       3."+HIB+" "+NORM+BOLD+"       1000"+NORM+"\n\
       4."+MAG+" "+NORM+BOLD+"       1000"+NORM+"\n\
       5."+HIY+" "+NORM+BOLD+"       1000"+NORM+"\n\
       6."+HIG+" "+NORM+BOLD+"        500"+NORM+"\n\
       000000000000000000000000000000000000000000\n\
       Please '"+CYN+"buy #"+NORM+"'.\n\n");
  return 1;
  }
buy_it(string str)
  {
  int buy;
  buy = str;
  if(!present("private"))
  {
  write("I'm sorry you don't see the private here.\n");
  return 1;
  if(!buy){ write("Please use: buy 1-6.\n"); return 1; }
  }
  switch(buy)
  {
  case "1"  :
    cost = 1000;
    item = clone_object("/players/angel/area/stargate/ .c");
    what = " ";
    break;
  case "2"  :
    cost = 1000;
    item = clone_object("/players/angel/area/stargate/ .c");
    what = " ";
    break;
  case "3"  :
    cost = 1000;
    item = clone_object("/players/angel/area/stargate/ .c");
    what = " ";
    break;
  case "4"  :
    cost = 1000;
    item = clone_object("/players/angel/area/stargate/ .c");
    what = " ";
    break;
  case "5"  :
    cost = 1000;
    item = clone_object("/players/angel/area/stargate/ .c");
    what = " ";
    break;
  case "6"  :
    cost = 500;
    item = clone_object("/players/angel/area/stargate/  .c");
    what = " ";
    break;
  default:
    write("Sorry, We don't have that.\n");
    return 1;
  }
  if (call_other(this_player(), "query_money", 0) < cost) 
    {
    write("The Private tells you: You do not have enough money for that.\n");
    return 1;
    }          
    if(!this_player()->add_weight(item->query_weight())) 
    {
      write("The Private tells you: You can't carry that much.\n");
      destruct(item);
      return 1;
    }  
    write("You give the private "+cost+" coins and receive a "+what+".\n");                
    say(this_player()->query_name() + " buys a "+what+".\n");
    move_object(item,this_player());
    this_player()->add_money(-(cost));
    return 1;
}
*/ 
query_no_fight(){
  return 1;
}

realm(){ return "NT"; }