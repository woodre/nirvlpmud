/*
*  sloth.c
*  Katya@Nirvana
*  Copyright (c) 2004 Katya
*  All Rights Reserved.
*/


#include <ansi.h>

#define CRUSH  (45 + random(45))
#define SHOVE  (30 + random(45))

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, gold;

  ob = clone_object("/players/katya/area/esquire/goonies/a/ssuit.c");
move_object(ob,this_object());

    gold = clone_object("obj/money");
    gold->set_money(random(8000) + 1000);
    move_object(gold,this_object());

     set_name("Sloth");
     set_alt_name("sloth");
     set_short("Sloth Fratelli");
     set_alias("fratelli");
     set_alias("sloth fratelli");
     set_race("human");
     set_long("\
Sloth is a large man.  No one really knows how old he is, most\n\
likely around thirty-five or so with a mind of a child.  When  \n\
he was younger his mother, Mama Fratelli, had dropped him on \n\
his head so many times it had destorted his facial structures. \n\
Sloth is against evil and wants only the best for Chunk and\n\
the other 'Goonies'!\n");
     set_gender("male");
     set_level(26);
     set_ac(24 + random(3));
     set_wc(46 + random(3));
     set_hp(1200 + random(150));
     set_al(400);
     set_aggressive(0);
     set_wc_bonus(15);
     set_ac_bonus(30);
     set_a_chat_chance(25);
     load_chat("Sloth yells: Hey you guys!\n");
   }
}

crush()
{
   object attacker_ob;
   string attacker_name;

   attacker_ob = this_object()->query_attack();
   if(!attacker_ob) return;

   attacker_name = attacker_ob->query_name();
   if(attacker_ob && present(attacker_ob)) 
 {  
   
      tell_room(environment(), "Sloth grabs "+attacker_name+" by the waist and crushes "+this_player()->query_objective()+".\n", ({
  attacker_ob }));

       tell_object(attacker_ob, "Sloth grabs you by the waist and crushes you.\n");
     attacker_ob->hit_player(CRUSH);  
   }
}

shove()
{
   object attacker_ob;
   string attacker_name;

   attacker_ob = this_object()->query_attack();
   if(!attacker_ob) return;
   
   attacker_name = attacker_ob->query_name();
   if(attacker_ob && present(attacker_ob)) 
   { 
      tell_room(environment(), "Sloth shoves "+attacker_name+" to the ground!\n", ({ attacker_ob
  }));
      tell_object(attacker_ob, "Sloth shoves you to the ground!\n");

     attacker_ob->hit_player(SHOVE);
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
            crush();
         break;
         
         case 5..9: 
            shove();
         break;
         
         case 10..14: 
            return 0;
         break;
         
         case 15..19: 
            crush();
         break;
      }
   }
}

