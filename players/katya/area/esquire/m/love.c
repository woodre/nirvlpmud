/*
 *     love.c              
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
    gold->set_money(random(143) + 300);
    move_object(gold,this_object());
     set_name("love-a-lot");
     set_alt_name("love");
     set_short(HIR+"Love-A-Lot Bear"+NORM);
     set_race("bear");
     set_alias("bear"); 
     set_long("\
Love-A-Lot bear is a pink bear that stands shy of three feet\n\
tall. On her belly she has two overlapping hearts inside\n\
a white circle, one pink and one red. All she wants is to\n\
bring love into everyone's heart!\n");
     set_gender("female");
     set_level(9);
     set_ac(7 + random(3));
     set_wc(12 + random(3));
     set_hp(135 + random(25));
     set_al(500);
     set_chat_chance(10);
     load_chat(HIR+"Love-A-Lot"+NORM+" says:  Don't forget your hugs!!\n");
     load_chat(HIR+"Love-A-Lot"+NORM+" hums a loving tune.\n");
     load_chat(HIR+"Love-A-Lot"+NORM+" smiles happily!\n");
     load_chat(HIR+"Love-A-Lot"+NORM+" spreads around as much love as she can.\n");
   }
}
