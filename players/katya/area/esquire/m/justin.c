/*
*  justin.c
*  Katya@Nirvana
*  Copyright (c) 2004 Katya
*  All Rights Reserved.
*/

#include <ansi.h>
#define SLAM    (80 + random(45))
#define PUNCH   (75 + random(30))


inherit "/obj/monster";

reset(arg) 
{
   ::reset(arg);
   if (!arg) 
      {
      object gold;
      gold = clone_object("obj/money");
      gold->set_money(random(1601) + 7000);
      move_object(gold,this_object());
      
      set_name("Justin");
      set_alt_name("justin");
      set_alias("clerk");
      set_short("Justin");
      set_race("human");
      set_long("Justin stands 5 feet 10 inches tall. He has short brown hair and a\n\
medium build. He is currently employed at the Esquire as a clerk\n\
at the concession stand. Don't under estimate his looks, he is quite\n\
strong for being an employee at an old theatre.\n");
      set_gender("male");
      set_level(23);
      set_ac(21 + random(5));
      set_wc(40 + random(6));
      set_hp(800 + random(150));
      set_al(0);
      set_aggressive(0);
      set_wc_bonus(15);
      set_ac_bonus(6);
      
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
      
      tell_room(environment(), "Justin swings his arm back and sucker punches "+attacker_name+" in the chin.\n", ({
  attacker_ob }));
      tell_object(attacker_ob, "Justin swings his arm back and sucker punches you.\n");
     attacker_ob->hit_player(PUNCH);  
   }
}

slam()
{
   object attacker_ob;
   string attacker_name;


   attacker_ob = this_object()->query_attack();
   /* no object, no service */
   if(!attacker_ob) return;
   
   attacker_name = attacker_ob->query_name();
   if(attacker_ob && present(attacker_ob)) 
   { 
      tell_room(environment(), "Justin grabs the back of "+attacker_name+" hair and slams "+attacker_ob->query_possessive()+" face into the counter!\n", ({ attacker_ob }));
      tell_object(attacker_ob, "Justin grabs the back of your hair and slams your face into the counter!\n");

     attacker_ob->hit_player(SLAM);
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
            slam();
         break;
         
         case 10..14: 
            return 0;
         break;
         
         case 15..19: 
            slam();
         break;
      }
   }
}
