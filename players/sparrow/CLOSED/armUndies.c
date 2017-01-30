/*****************************************************************************
 *      File:                   undies.c
 *      Function:               BWO unidentified boots
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow All Rights Reserved.
 *      Source:                 03/25/2006
 *      Notes:                  
 *      Change History:         
 ****************************************************************************/
#include <ansi.h>
#include "/players/sparrow/areas/bwo/include/defs.h"
inherit "/players/sparrow/areas/bwo/include/gear_funcs.c";
inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_name("undies");
   set_short(HIK+"Undies of Armor Making"+NORM);
   set_alias("underwear");
   set_long("armor <type> to create armor\n");
   set_type("underwear");
   set_ac(0);
   set_weight(2);
   set_value(100);
}

init() {
  add_action("make_armor", "armor"); 
}

/* 
 * Function name: make_armor()
 * Description:   This function checks for shaade, if shaade is present,
 *                it allows the player to have the masking spells removed
 *                from the boots. Basically it clones new boots and dests
 *                these
 * Arguments:     string str
 * Returns:       int
 */

make_armor(str) 
{
  object playerob, roomob, newboots;
  string *allow;
  allow = ({"armor","shield","helmet","boots","amulet","chest","necklace",
  "cloak","bracelet","pants","belt","gloves","earring","ring","misc"});
  if(!str)
  {
    tell_object(environment(this_object()),
    "[ERROR!] You must also enter the type of armor you wish to create!\n");
    return 1;
  }
  if(member(allow, str) == -1) 
  {
     tell_object(environment(this_object()),
      "[ERROR!] Invalid armor configuration!\n");
      return 1;
  } 
  playerob = environment(this_object());
  roomob = environment(playerob);
  tell_room(roomob, "The undies glow with a sick light.\nA new piece of"+
  "armor is now in the room.\n");
  newboots = generate_accessory(str,(random(3)+1));
  move_object(newboots, playerob);
  /* destroy(this_object); */
  return 1;
}