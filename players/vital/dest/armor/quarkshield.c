/******************************************************************************
 *  
 *  File:           quarkshield.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2002 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 8/28/02.
 *  
 *  Notes:			
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("quark");
   set_alias("quark shield");
   set_short("A quark shield");
   set_long("This is high density, low stability, prototype MQS. It can shield the wearer from damage in combat [sort of].\n");
   set_ac(1);
   set_info("MQS: Magnum Quark Shield. Just like quarks, it may or may not be there when you are.\n");
   set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(20000);
}

do_special(owner) {
    int foo, fish, fart;
    foo = random(100) + 1;
    fish = random(5)+1;
    fart = foo / fish;
    if(foo > 50) return 0;
    if(foo < 20) return fart;
    if(fart > fish) {
        owner->hit_player(15,"other|radiation");
        say("The MQS burns on your arm!\n");
        write("The MQS on "+owner->query_name()+"\'s arm flashes and "+owner->query_objective()+" yelps.\n");
        return -5;
    }
    return 0;
}