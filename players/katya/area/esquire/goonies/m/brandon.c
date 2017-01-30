/*
*  brandon.c
*  Katya@Nirvana
*  Copyright (c) 2004 Katya
*  All Rights Reserved.
*/


#include <ansi.h>

#define PUNCH    (40 + random(25))
#define KICK    (30 + random(35))

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;
    gold = clone_object("obj/money");
    gold->set_money(random(5983) + 350);
    move_object(gold,this_object());

     set_name("Brandon");
     set_alt_name("brandon");
     set_short("Brandon Walsh");
     set_alias("brandon walsh");
     set_alias("brand");
     set_alias("walsh");
     set_race("human");
     set_long("\
Brand is a tall young man approx 18 years of age and around six\n\
feet tall.  He has short brown hair with greenish colored eyes.\n");
     set_gender("male");
     set_level(21);
     set_ac(19 + random(3));
     set_wc(34 + random(3));
     set_hp(600 + random(50));
     set_al(400);
     set_aggressive(0);
   }
}

punch()
{
   object attacker_ob;
   string attacker_name;

   attacker_ob = this_object()->query_attack();
   if(!attacker_ob) return;

   attacker_name = attacker_ob->query_name();
   if(attacker_ob && present(attacker_ob)) 
 {  
      
      tell_room(environment(), "Brandon punches "+attacker_name+" in the stomach!\n", ({
  attacker_ob }));

      tell_object(attacker_ob, "Brandon punches you in the stomach!\n");
     attacker_ob->hit_player(PUNCH);  
   }
}

kick()
{
   object attacker_ob;
   string attacker_name;

   attacker_ob = this_object()->query_attack();
   if(!attacker_ob) return;

   attacker_name = attacker_ob->query_name();
   if(attacker_ob && present(attacker_ob)) 
 {  
      
      tell_room(environment(), "Brandon kicks "+attacker_name+" in the crotch!\n", ({
  attacker_ob }));

      tell_object(attacker_ob, "Brandon kicks you in the crotch!\n");
     attacker_ob->hit_player(KICK);  
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
            punch();
         break;
         
         case 5..9: 
            return 0;
         break;
         
         case 10..14: 
            kick();
         break;
         
         case 15..19: 
            return 0;
         break;
      }
   }
}
