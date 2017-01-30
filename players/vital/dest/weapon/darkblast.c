/******************************************************************************
 *  
 *  File:           darkblast.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 5/7/01.
 *  
 *  Notes:			
 *  
 *  Change History: 5/30/01-added feedback on special,corrected color,touched up
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "obj/weapon.c";
int lightlevel;

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("blaster");
  set_alias("dark blaster");
  set_short(BOLD+BLK+"Dark "+NORM+"Blaster");
  set_long(
"This is a large Caleb version 3 Absorption Blaster. It has been banned \n\
in most systems and has a potential for abuse in the wrong hands.\n"
  );
  set_type("gun");
  set_class(16);
  set_weight(7);
  set_value(random(1000)+800);
  set_hit_func(this_object());
  message_hit=({
    "blasted"," with anti-matter",   
    "flooded"," with light absorbing anti-photons"+BLK, /*designed to bleed, but ansi monitor will quickly check it in battle*/
    "bathed","'s body with radiation",
    "shot"," painfully in the middle",
    "hit"," solidly",
    "winged","",
    "missed"," with a wild shot into the cosmos",
  });

}

weapon_hit(object attacker) {
    string name;
    name = C(attacker->query_name());
    if(random(100) < 13) {
        write("You "+BOLD+BLK+"blast "+NORM+name+".\n");
        say(TPN+BOLD+BLK+" blasts "+NORM+name+".\n");
        return 2;
    }
    if(random(100) > 90) dark_blast(attacker);
    return 0;
}

dark_blast(object attacker) {
    int x, y, z;
    x = -random(3);
    y = query_light();
    SET_LIGHT(x-y);
    lightlevel = x;
    write("The "+BOLD+BLK+"Dark "+NORM+"Blaster chases away the light.\n");
    say("The "+BOLD+BLK+"Dark "+NORM+"Blaster chases away the light.\n");
    call_out("light_reset",12);
    attacker->heal_self((1+random(100))/20);
    return;
}

query_light() { return lightlevel; }

light_reset() {
    int x;
    if(lightlevel < 1) {
        x = 0;
        SET_LIGHT(x-lightlevel);
        lightlevel = x;
        write("The light seeps back into the room.\n");
        say("The light seeps back into the room.\n");
    }
    return;
}
