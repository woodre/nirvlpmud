/*
 *     surprise.c              
 *     Katya@Nirvana
 *     Copyright (c) 2004 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;
    gold = clone_object("obj/money");
    gold->set_money(random(151) + 150);
    move_object(gold,this_object());

     set_name("surprise");
     set_alt_name("pony");
     set_short("Surprise");
     set_race("pony");
     set_long("\
Surprise is a little pony who still has fuzzy yellow \n\
fur on her body.  Surprise has a short yellow tail \n\
and mane and has a yellow balloon on her hip.\n");
     set_gender("female");
     set_level(4);
     set_ac(4 + random(3));
     set_wc(8 + random(3));
     set_hp(60 + random(50));
     set_al(700);
   }
}
