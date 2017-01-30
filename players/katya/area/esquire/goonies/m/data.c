/*
*  data.c
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
    gold->set_money(random(3500) + 300);
    move_object(gold,this_object());

     set_name("Data");
     set_alt_name("data");
     set_short("Ricky 'Data' Wang");
     set_alias("ricky wang");
     set_alias("ricky");
     set_alias("rick");
     set_alias("wang");
     set_race("human");
     set_long("\
Data is a little inventor like his father.  He is about eleven\n\
years of age.  His inventions rarely work but they are quite\n\
humorous.  Data is a member of the neighborhood club\n\
'The Goonies'.\n");
     set_gender("male");
     set_level(18);
     set_ac(15 + random(4));
     set_wc(26 + random(4));
     set_hp(400 + random(55));
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
      
      tell_room(environment(), "Data's pinchers of pals bites "+attacker_name+"!\n", ({
  attacker_ob }));

      tell_object(attacker_ob, "Data's pinchers of pals bites you!\n");
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
