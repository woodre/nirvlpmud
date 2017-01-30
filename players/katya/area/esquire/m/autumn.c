/*
 *     autumn.c              
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
    gold->set_money(random(151) + 350);
    move_object(gold,this_object());

     set_name("autumn skye");
     set_alt_name("autumn");
     set_short("Autumn Skye");
     set_alias("skye");
     set_race("pony");
     set_long("\
Autumn Skye is a blue pony with a long flowing yellow\n\
and white mane.  She has a picture of three leaves with\n\
yellow, orange and red colors in it.\n");
     set_gender("female");
     set_level(8);
     set_ac(10 + random(3));
     set_wc(12 + random(3));
     set_hp(120 + random(50));
     set_al(400);
   }
}
