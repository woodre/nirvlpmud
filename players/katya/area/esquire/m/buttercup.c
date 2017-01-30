/*
 *     buttercup.c              
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
    gold->set_money(random(151) + 875);
    move_object(gold,this_object());

     set_name("princess buttercup");
     set_alt_name("princess");
     set_short("Princess Buttercup");
     set_alias("buttercup");
     set_race("human");
     set_long("\
Princess Buttercup stands about five feet seven.  She\n\
has bright blue eyes and long golden hair that flows down\n\
her back.  She is wearing a long white silk dress that is\n\
tied with a ribbon under her bosom.\n"); 
     set_gender("female");
     set_level(16);
     set_ac(12 + random(3));
     set_wc(20 + random(3));
     set_hp(225 + random(50));
     set_al(800);
   }
}
