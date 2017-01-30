/*
*  chunk.c
*  Katya@Nirvana
*  Copyright (c) 2004 Katya
*  All Rights Reserved.
*/


#include <ansi.h>

#define BITE    (15 + random(15))

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;
    gold = clone_object("obj/money");
    gold->set_money(random(4000) + 300);
    move_object(gold,this_object());

     set_name("Chunk");
     set_alt_name("chunk");
     set_short("Lawrence 'Chunk' Cohen");
     set_alias("lawrence");
     set_race("human");
     set_long("\
Chunk is a child who is around thirteen yrs of age.  He has\n\
short dirty blonde hair and is a little chunk, which is how\n\
he gets his nickname from his friends.  Chunk is a member\n\
of their neighborhood club, 'The Goonies'.\n");
     set_gender("male");
     set_level(19);
     set_ac(16 + random(4));
     set_wc(28 + random(4));
     set_hp(450 + random(55));
     set_al(400);
     set_aggressive(0);
   }
}

bite()
{
   object attacker_ob;
   string attacker_name;

   attacker_ob = this_object()->query_attack();
   if(!attacker_ob) return;

   attacker_name = attacker_ob->query_name();
   if(attacker_ob && present(attacker_ob)) 
 {  
      
      tell_room(environment(), "Chunk bites "+attacker_name+" ear!\n", ({
  attacker_ob }));

      tell_object(attacker_ob, "Chunk bites your ear!\n");
     attacker_ob->hit_player(BITE); 
   }
}

heart_beat()
{
   int i;

   ::heart_beat();
   
   if(attacker_ob)
   {
      i = random(10);
      switch(i)
      {
         
         case 0..5:
            bite();
         break;
         
         case 6..9: 
            return 0;
         break;
         
      }
   }
}
