/******************************************************************************
 *  
 *  File:           pain.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 4/19/01.
 *  
 *  Notes:			
 *  
 *  Change History: 8/22/01,
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

#undef  DAMAGE
#undef  DELAY
#undef  LONGEVITY
#define DAMAGE (15+random(10))
#define DELAY 5+random(20)
#define LONGEVITY 10+random(50)

int duration;

id(str) { 
    return str == "pain_object";
}

reset(arg) {
  if(!arg) {
    duration=LONGEVITY;
    call_out("pain_player",DELAY);
  }
}

/*
This object must be loaded from your castle.c in order for it
to autoload.  Notice the colon at the end of the autoload string
here.
*/

query_auto_load() { return "/players/vital/dest/acadie/obj/pain.c:"+duration; }

init_arg(str) {  sscanf(str,"%d",duration); }

pain_player() {
  if(!environment()) destruct(this_object());
  if(environment()) { 
    tell_object(environment(this_object()),
      "You feel the lingering effects of the doctor's exam.\n");
    if(environment()->is_player())
      call_other(environment(),"add_hit_point",-DAMAGE);
    else
      call_other(environment(),"heal_self",-DAMAGE);
    duration = duration - (duration/2);
    if(duration <= 6) {
      tell_object(environment(),"You begin to feel the pain subside.\n");
      destruct(this_object());
    }
    call_out("pain_player",DELAY);
  }
  return 1; 
}

drop()  { return 1; } /* Cannot drop */
get()   { return 0; } /* Cannot get */

extra_look() {
  if(this_player() == environment())
    write("You feel queasy after your recent encounter with the proctologist.\n");
  else write(environment()->query_name()+" looks queasy after visiting the proctologist.\n");
}
