/*
*  mama.c
*  Katya@Nirvana
*  Copyright (c) 2004 Katya
*  All Rights Reserved.
*/


#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;
    gold = clone_object("obj/money");
    gold->set_money(random(1500) + 500);
    move_object(gold,this_object());

     set_name("Mama");
     set_alt_name("mama");
     set_short("Mama Fratelli");
     set_alias("fratelli");
     set_alias("mama fratelli");
     set_race("human");
     set_long("\
Mama Fratelli is almost, but not quite, five feet tall.  She has\n\
shoulder length brown hair and a bad attitude.  Mama is a very\n\
evil woman, trying to chase down the 'Goonies' to snatch their\n\
rich stuff.\n");
     set_gender("female");
     set_level(16);
     set_ac(13 + random(3));
     set_wc(22 + random(3));
     set_hp(300 + random(50));
     set_al(-400);
     set_aggressive(1);
   }
}
