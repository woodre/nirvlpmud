/*
*  mikey.c
*  Katya@Nirvana
*  Copyright (c) 2004 Katya
*  All Rights Reserved.
*/


#include <ansi.h>

#define JAB    (10 + random(15))

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;
    gold = clone_object("obj/money");
    gold->set_money(random(3500) + 400);
    move_object(gold,this_object());

     set_name("Mikey");
     set_alt_name("mikey");
     set_short("Mikey Walsh");
     set_alias("mikey walsh");
     set_alias("mike");
     set_alias("walsh");
     set_race("human");
     set_long("\
Mikey is a young man around forteen years of age.  He is about \n\
five feet six inches tall.  He has short brown hair and braces on\n\
his teeth.  Mikey is basically the leader of the 'Goonies' club.\n\
He has lead them on this current adventure they are on searching\n\
for One-Eyed Willie's treasure.\n");
     set_gender("male");
     set_level(18);
     set_ac(15 + random(3));
     set_wc(26 + random(3));
     set_hp(400 + random(50));
     set_al(400);
     set_aggressive(0);
   }
}

jab()
{
   object attacker_ob;
   string attacker_name;

   attacker_ob = this_object()->query_attack();
   if(!attacker_ob) return;

   attacker_name = attacker_ob->query_name();
   if(attacker_ob && present(attacker_ob)) 
 {  
      
      tell_room(environment(), "Mikey jabs "+attacker_name+" in the eye!\n", ({
  attacker_ob }));

      tell_object(attacker_ob, "Mikey jabs you in the eye!\n");
     attacker_ob->hit_player(JAB); 
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
            jab();
         break;
         
         case 6..9: 
            return 0;
         break;
         
      }
   }
}
