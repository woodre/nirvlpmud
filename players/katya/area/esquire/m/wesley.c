/*
 *     wesley.c              
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
    gold->set_money(random(151) + 1000);
    move_object(gold,this_object());

     set_name("dreaded pirate roberts");
     set_alt_name("roberts");
     set_alias("pirate");
     set_short("Dreaded Pirate Roberts");
     set_race("human");
     set_long("\
Dreaded Pirate Roberts stands short of six feet tall.  His hair is \n\
light brown and quite short.  He is wearing a pirates outfit with\n\
a pair of black pants, a black shirt and a black mask that covers\n\
his eyes.  He also has a long sword that has been stragically\n\
placed on his belt.\n");
     set_gender("male");
     set_level(18);
     set_ac(15 + random(3));
     set_wc(26 + random(3));
     set_hp(450 + random(50));
     set_al(650);
   }
}
