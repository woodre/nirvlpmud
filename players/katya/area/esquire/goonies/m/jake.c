/*
*  jake.c
*  Katya@Nirvana
*  Copyright (c) 2004 Katya
*  All Rights Reserved.
*/


#include <ansi.h>

#define CHOKE    (40 + random(45))
#define PUNCH   (35 + random(30))

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;
    gold = clone_object("obj/money");
    gold->set_money(random(9000) + 300);
    move_object(gold,this_object());

     set_name("Jake");
     set_alt_name("jake");
     set_short("Jake Fratelli");
     set_alias("fratelli");
     set_race("human");
     set_long("\
Jake Fratelli is an evil man, who recently escaped from jail.\n\
He has short brown hair and is about six feet tall.  Jake also\n\
enjoys singing opera and chasing down the 'Goonies' to get\n\
all of their treasure.\n");
     set_gender("male");
     set_level(24);
     set_ac(22 + random(3));
     set_wc(42 + random(3));
     set_hp(900 + random(50));
     set_al(-400);
     set_aggressive(1);
      set_wc_bonus(15);
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
      
      tell_room(environment(), "Jake sucker punches "+attacker_name+" square in the stomach.\n", ({
  attacker_ob }));

      tell_object(attacker_ob, "Jake sucker punches you square in the stomach.\n");
     attacker_ob->hit_player(PUNCH);  
   }
}

choke()
{
   object attacker_ob;
   string attacker_name;


   attacker_ob = this_object()->query_attack();
   if(!attacker_ob) return;
   
   attacker_name = attacker_ob->query_name();
   if(attacker_ob && present(attacker_ob)) 
   { 
      tell_room(environment(), "Jake reaches out and chokes "+attacker_name+" around "+attacker_ob->query_possessive()+" neck!\n", ({ attacker_ob
  }));
      tell_object(attacker_ob, "Jake reaches out and chokes you around your neck!\n");

     attacker_ob->hit_player(CHOKE);
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
            choke();
         break;
         
         case 10..14: 
            return 0;
         break;
         
         case 15..19: 
            punch();
         break;
      }
   }
}
