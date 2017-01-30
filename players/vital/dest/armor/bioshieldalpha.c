/******************************************************************************
 *  
 *  File:           bioshieldalpha.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2002 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 9/14/02.
 *  
 *  Notes:          Added include/dest.h
 *  
 *  Change History: 11/15/02,
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
   set_long("This is a generic bio shield that can be readily obtained \nwith little or no liscense. It offers a minimum acceptable level of \nprotection at a relatively inexpensive price.\n");
   set_ac(1);
   set_info("On a small patch of the shield\'s scar tissue, you read, \n\t\"Krondak Bio Protectant Division: Alpha-0.9.6.\"\n");
   set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(20000);
}

do_special(owner) {
    int foo, fish, fart;
    foo = owner->query_attrib("sta");
    fish = random(foo)+1;
    fart = foo / fish;
    if(fart > 7) return 0;
    if(fart < 5) return fart;
    else return -1;
}
