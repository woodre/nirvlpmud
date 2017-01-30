/*
 *     bedtime.c              
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
    gold->set_money(random(155) + 300);
    move_object(gold,this_object());

     set_name("bedtime bear");
     set_alt_name("bedtime");
     set_short(HIB+"Bedtime Bear"+NORM);
     set_race("bear");
     set_alias("bear"); 
     set_long("\
Bedtime Bear is a blue bear that is about three feet tall.\n\
he has a picture of a yellow star dangling from a sleepy blue\n\
moon in a white circle on his belly.  All Bedtime Bear really\n\
wants is to grab a quick nap before bedtime.\n");
     set_gender("male");
     set_level(8);
     set_ac(7 + random(3));
     set_wc(12 + random(3));
     set_hp(120 + random(25));
     set_al(500);
     set_chat_chance(10);
     load_chat(HIB+"Bedtime"+NORM+" mumbles:  Is it bedtime yet!?\n");
     load_chat(HIB+"Bedtime"+NORM+" yawns biggly.\n");
     load_chat(HIB+"Bedtime"+NORM+" bats his sleepy eyes and says:  It's nap time!\n");
     load_chat(HIB+"Bedtime"+NORM+" whispers as he lays down:  All this work is making me sleepy!\n");
   }
}  
