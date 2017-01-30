/******************************************************************************
 *  
 *  File:           bioshieldgamma.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2002 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 9/14/02.
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
   set_name("bio shield");
   set_alias("bioshield");
   set_short("A bio shield");
   set_long("This is a high-level bio shield that can only be obtained with \na special \"Protective Technologies\" liscense. It offers a fairly high level \nof protection.\n");
   set_ac(2);
   set_info("On a small patch of the shield\'s scar tissue, you read, \n\t\"Krondak Bio Protectant Division: Gamma-2.0.pr1.\"\n");
   set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(5700);
}

do_special(owner) {
    int foo, fish, fart;
    string oname;
    oname = owner->query_name();
    if((foo = owner->query_attrib("str")) > 20) foo = 20;
    if(foo < 16) foo = 16;
    fish = random(foo)+1;
    fart = 0;
    switch(fish) {
        case  1..15:
            return fart;
        case     16:
            write(BLU+"Ice"+NORM+" flows through your veins.\n");
            say(capitalize(oname)+" shivers slightly.\n");
            return fart+1;
        case     17:
            write("You feel your skin tighten with "+CYN+"cool"+NORM+" touch of the shield.\n");
            say(BLU+capitalize(oname)+NORM+" looks chilled.\n");
            return fart+2;
        case     18:
            write("You cannot believe how "+HIB+"cold"+NORM+" the room feels.\n");
            say("Cold air fills the room.\n");
            return fart+3;
        case     19:
            write(HIB+BLINK+"Ice "+HIR+"Fire"+NORM+" burns through your nerves.\n");
            say(capitalize(oname)+" stumbles.\n");
            return fart+4;
        case     20:
            write("Your body\'s metabolism slows and you turn to stone at the nano-\nsecondary moment of impact.\n");
            say(capitalize(oname)+"\'s body seems to almost stutter.\n");
            return fart+5;
        default:
            write("Mudmail Vital if you see this message.\n");
            return -200;
    }
}
