/*
 *     funshine.c              
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
    gold->set_money(random(151) + 300);
    move_object(gold,this_object());

     set_name("funshine bear");
     set_alt_name("funshine");
     set_short(BOLD+YEL+"Funshine Bear"+NORM);
     set_race("bear");
     set_alias("bear"); 
     set_long("\
Funshine Bear stands about three feet tall.  He is a bright\n\
yellow bear with a white circle on his belly.  In the middle\n\
of this white circle is a picture of a beautiful yellow sun.\n\
He tries to shine fun on everyone around him.\n");
     set_gender("male");
     set_level(10);
     set_ac(7 + random(3));
     set_wc(13 + random(3));
     set_hp(140 + random(50));
     set_al(450);
     set_chat_chance(10);
     load_chat(BOLD+YEL+"Funshine"+NORM+" says:  It's a wonderful day!  Let's go have some fun!!\n");
     load_chat(BOLD+YEL+"Funshine"+NORM+" hums with excitement!\n");
     load_chat(BOLD+YEL+"Funshine"+NORM+" smiles happily!\n");
     load_chat(BOLD+YEL+"Funshine"+NORM+" skips around with joy.\n");
   }
}
