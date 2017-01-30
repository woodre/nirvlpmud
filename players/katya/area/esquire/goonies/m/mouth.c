/*
*  mouth.c
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

     set_name("Mouth");
     set_alt_name("mouth");
     set_short("Clarke 'Mouth' Devereux");
     set_alias("clarke");
     set_race("human");
     set_long("\
Mouth is about twelve years of age.  He is about five feet four\n\
inches.  He is a member of the neighborhood club of the 'Goonies'. \n\
He got his nickname 'Mouth' due to the fact of he is unable to keep\n\
his mouth shut for any reason.\n");
     set_gender("male");
     set_level(17);
     set_ac(14 + random(4));
     set_wc(24 + random(4));
     set_hp(350 + random(55));
     set_al(400);
     set_aggressive(0);
   }
}
