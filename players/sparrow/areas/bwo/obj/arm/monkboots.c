/*****************************************************************************
 *      File:                   monkboots.c
 *      Function:               BWO unidentified boots
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow All Rights Reserved.
 *      Source:                 03/24/2006
 *      Notes:                  
 *      Change History:         
 ****************************************************************************/
#include <ansi.h>
#include "/players/sparrow/areas/bwo/include/defs.h"
inherit "/players/sparrow/areas/bwo/include/gear_funcs.c";
inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_name("monk boots");
   set_short(HIK+"Standard Issue Monk Boots"+NORM);
   set_alias("boots");
   set_long("These boots appear to be a pair of common black boots.\n"+
            "You notice something strange about them though, you just\n"+
            "can't put your finger on it.\n");
   set_type("boots");
   set_ac(0);
   set_weight(2);
   set_value(100);
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
      
    
