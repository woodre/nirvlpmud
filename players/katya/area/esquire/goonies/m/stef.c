/*
*  stef.c
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
    gold->set_money(random(2100) + 300);
    move_object(gold,this_object());

     set_name("Stef");
     set_alt_name("stef");
     set_short("Stefaine 'Stef' Steinbrenner");
     set_alias("stefaine");
     set_race("human");
     set_long("\
Stef is a young woman around the age of fifteen.  She\n\
has short blonde hair.  She wears glasses but they had\n\
been broken, when she dropped them and Mikey stepped\n\
on them.  Stef is about five feet seven inches tall.\n");
     set_gender("female");
     set_level(17);
     set_ac(14 + random(3));
     set_wc(24 + random(3));
     set_hp(350 + random(50));
     set_al(400);
     set_aggressive(0);
   }
}
