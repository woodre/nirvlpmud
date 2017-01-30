/*****************************************************************************
 *      File:                   itemgen.c
 *      Function:               Item Generator
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow 
 *                              All Rights Reserved.
 *      Source:                 03/25/2006
 *      Notes:                  
 *      Change History:         
 ****************************************************************************/
#include <ansi.h>
#include "/players/sparrow/areas/bwo/include/defs.h"
inherit "/players/sparrow/areas/bwo/include/gear_funcs.c";
inherit "obj/monster";

   set_name("generator");
   set_short(HIK+"Armor Generator"+NORM);
   set_alias("boots");
   set_long("Sparrow's Armor Generator.\n");
   set_type("armor generator");
}
init() {
  add_action("make_armor", "armor"); 
}

/* 
 * Function name: unbind_boots()
 * Description:   This function checks for shaade, if shaade is present,
 *                it allows the player to have the masking spells removed
 *                from the boots. Basically it clones new boots and dests
 *                these
 * Arguments:     none
 * Returns:       void
 */

make_armor(str) 
{
  object playerob, roomob, newboots;
  playerob = environment(this_object());
  roomob = environment(playerob);
    if(!str){
      tell_object(environment(this_object()), "Shaade turns to you and"+
      " speaks: 'Don't waste my time. Be more specific!'\n");
      return;
    }
    tell_room(roomob, "A piece of armor has been generated!\n");
    newboots = armor_generator(str,(random(2)+1),random(4));
    move_object(newboots, environment(playerob));
    /* destroy(this_object); */
    return;
}