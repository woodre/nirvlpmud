/*
 *     rainbow.c              
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

     set_name("rainbow dash");
     set_alt_name("rainbow");
     set_short("Rainbow Dash");
     set_alias("dash");
     set_race("pony");
     set_long("\
Rainbow Dash is a beautiful blue pony with a long \n\
swaying rainbow tail.  On her hip she has a picture \n\
of a rainbow that has clouds at each end.\n");
     set_gender("female");
     set_level(9);
     set_ac(7 + random(3));
     set_wc(13 + random(3));
     set_hp(135 + random(50));
     set_al(320);
   }
}
