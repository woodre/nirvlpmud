/*
*  andy.c
*  Katya@Nirvana
*  Copyright (c) 2004 Katya
*  All Rights Reserved.
*/


#include <ansi.h>

#define SMACK    (20 + random(25))

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;
    gold = clone_object("obj/money");
    gold->set_money(random(4980) + 350);
    move_object(gold,this_object());

     set_name("Andy");
     set_alt_name("andy");
     set_short("Andy Carmichael");
     set_alias("andy carmichael");
     set_alias("carmichael");
     set_race("human");
     set_long("\
Andy is a young woman around 16 years of age.  She has long\n\
red wavey hair that reaches the mid of her back.  She seems\n\
to have a crush on Brand!\n");
     set_gender("female");
     set_level(20);
     set_ac(17 + random(3));
     set_wc(30 + random(3));
     set_hp(500 + random(50));
     set_al(400);
     set_aggressive(0);
   }
}

smack()
{
   object attacker_ob;
   string attacker_name;

   attacker_ob = this_object()->query_attack();
   if(!attacker_ob) return;

   attacker_name = attacker_ob->query_name();
   if(attacker_ob && present(attacker_ob)) 
 {  
      
      tell_room(environment(), "Andy smacks "+attacker_name+" across the face!\n", ({
  attacker_ob }));

      tell_object(attacker_ob, "Andy smacks you across the face!\n");
     attacker_ob->hit_player(SMACK);  
   }
}

heart_beat()
{
   int i;

   ::heart_beat();
   
   if(attacker_ob)
   {
      i = random(20);
      switch(i)
      {
         
         case 0..4:
            smack();
         break;
         
         case 5..9: 
            return 0;
         break;
         
         case 10..14: 
            smack();
         break;
         
         case 15..19: 
            return 0;
         break;
      }
   }
}
