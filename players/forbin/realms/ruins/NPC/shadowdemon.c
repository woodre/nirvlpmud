/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        The Ruins (/players/forbin/realms/ruins/)
//  Function:     NPC summoned by shadowangel.c
//  Create Date:  2004.07.12
//  Last Edit:    2004.07.22 -Forbin
//  Notes:        -this basically acts as a 2-6 round spell attack
//  Approval:     Fred 2004.07.24
//  Notable Changes:    
*/ 

#include "/players/forbin/realms/ruins/ruinsdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

#define SHADOWD HIW+"S"+NORM+WHT+"h"+HIW+"a"+NORM+WHT+"d"+HIW+"o"+NORM+WHT+"w "+NORM+WHT+"D"+HIW+"e"+NORM+WHT+"m"+HIW+"o"+NORM+WHT+"n"+NORM

object NoHit;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  NoHit = clone_object(OBJ+"no_msg_hit.c"); /* no_msg_hit insures that message_hit isn't */
  move_object(NoHit, this_object());        /* printed - it has no wc, but has a continuous */
  set_name("A "+SHADOWD);                   /* magic spell that mimics wc */
  set_alt_name("shadow demon");
  set_alias("demon");
  set_short("A "+SHADOWD);
  set_long(
    HIW+"  A swirling mass of shadow and darkness.\n"+NORM);
  set_level(20);
  set_hp(100000); /* not supposed to kill it */
  set_al(-500);
  set_wc(0);
  set_ac(0);
  set_dead_ob(this_object());  
  set_no_exp_value(); /* won't give any exp if you kill it */
/*
//  SPELL ATTACKS:
//  shadow_wc ::: 50% chance 15-35 magical damage to main attacker
//  shadow_wc2 :: 50% chance 15-35 magical damage to main attacker
*/  
  add_spell("shadow_wc", 
    "\n\The "+SHADOWD+" surrounds you with a cloud of $HK$darkness$N$.\n\n", 
    "\nThe "+SHADOWD+" surrounds #CTN# with a cloud of $HK$darkness$N$.\n\n", 
    50, "15-35", "magical");
  add_spell("shadow_wc2", 
    "\n\The "+SHADOWD+" lashes out at you with strands of $HK$darkness$N$.\n\n", 
    "\nThe "+SHADOWD+" lashes out at #CTN# with strands of $HK$darkness$N$.\n\n", 
    50, "15-35", "magical");
  call_out("destroy_self", 6 + random(7));
}

init(){
  ::init();
}

destroy_self() {
  if(environment()) {
    tell_room(environment(this_object()),
      "The demon of shadow vanishes as quickly as it formed...\n");
  }
  destruct(this_object());
  return 1;
}
