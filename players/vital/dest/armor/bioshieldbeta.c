/******************************************************************************
 *  
 *  File:           bioshieldbeta.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2002 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 9/14/02.
 *  
 *  Notes:			Added include/dest.h
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
   set_long("This is a better bio shield that can also be readily ob-\ntained with little or no liscense. It offers some level of protection at a relatively inexpensive price.\n");
   set_ac(1);
   set_info("On a small patch of the shield\'s scar tissue, you read, \n\t\"Krondak Bio Protectant Division: Beta-1.4.3.\"\n");
   set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(700);
}

do_special(owner) {
    int foo, fish, fart;
    foo = owner->query_attrib("str");
    fish = random(foo)+1;
    fart = foo / fish;
    if(fart > 7) return 1;
    if(fart < 5) return fart;
    else return -2;
}