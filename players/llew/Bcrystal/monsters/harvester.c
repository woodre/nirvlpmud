/* MONSTER:  Xetra Harvester
   LEVEL:    20
   DESCRIPT:

   SPELLS:   none
   SPECIAL:  Dodge, healing, Call to Arms, haste

   Heal:     Use a treasure crystal to heal damage.
   Call:     Will tell other xetra in the room to help it fight its target.
   Dodge:    Dodge is a percent chance that this creature will completley
             ignore damage from the object it is fighting.
   Haste:    Use a treasure crystal to increase attacks for awhile.
*/

#pragma strict_types
#include "/players/llew/closed/ansi.h"
#include "/players/llew/Bcrystal/factions.h"

#define DODGE_CHANCE 40

inherit "obj/monster";

/* Is this creature currently hasted, and for how long. */
int haste;

/* Declarations */
int dodge();

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;

   haste = 0;

   set_name(RED + "Triatsor Xetra" + NORM);
   set_alt_name("triatsor");
   set_alias("harvester");
   set_short(RED + "Triatsor Xetra" + NORM);
   set_race("xetra");
   set_long("   This dark red-skinned creature is humanoid with two long arms and\n" +
            "two slim legs.  It is of slight build and looks hardened from labor.\n" +
            "Its eyes study the crystal around it.  The fingers on its hands end\n" +
            "in extremely sharp claws.\n");
   set_whimpy();
   set_level(20);
   set_hp(700 + random(100));
   set_wc(28 + random(5));
   set_armor_params("physical",22 + random(3),0,"dodge");
   set_armor_params("magical",0,0,"dodge");
   set_message_hit(({"mutilated"," to a pulpy red mass","slashed"," spraying the room with blood",
                     "thrashed"," with sharp claws","sliced"," cleanly","cut","",
                     "grazed","","scratched"," a glancing blow"}));
   set_chat_chance(3);
   set_a_chat_chance(0);
   load_chat(query_name() + " cuts away the crystal walls.\n");
   load_chat(query_name() + " studies the crystal.\n");
   load_chat(query_name() + " mutters to itself in a strange language.\n");
   load_chat(query_name() + " grabs a bit of crystal.\n");
   set_dead_ob(this_object());
   set_heal(5, 5);

   /* Slight addition to ac due to dodging attacks. */
   set_ac_bonus(query_ac_bonus() + 3);

   /* TREASURE */
   {
      int crystals;
      crystals = random(4);  /* 0 to 3 crystals */
      while (crystals > 0)
      {
         move_object(clone_object("/players/llew/Bcrystal/treasure/money_crystal.c"), this_object());
         crystals--;
      }
   }
}

/* Aggression code based on faction standings. */
void init()
{
   ::init();
   if (this_player() && this_player()->is_player())
   {
      if (FACTION->query_faction(this_player()->query_real_name()) > HIGH_AGGRO)
      {
         /* Check stealth and attack. */
         if (this_player()->query_attrib("ste") < random(40) + 1)
         {
            say(query_name() + " notices " + this_player()->query_name() + " and attacks!\n");
            attack_object(this_player());
         }
      }
   }
}
       
void heart_beat()
{
   /* Call the normal heartbeat. */
   ::heart_beat();


   /* Call to Arms */                                                  
   /* If there is another xetra in the room, get him to attack the same target. */
   if (attacker_ob)
   {
      object *room_inv;
      int i,shouted;

      room_inv = all_inventory(environment());
      shouted = 0;

      for (i = 0; i < sizeof(room_inv); i++)
      {
         if ((string)room_inv[i]->query_race() == "xetra" && room_inv[i] != this_object())
         {
            if ((object)room_inv[i]->query_attack() != attacker_ob)
            {
               room_inv[i]->attack_object(attacker_ob);
               if (!shouted)
               {
                  say(query_name() + BOLD + " shouts in a strange language!\n" + NORM);
                  shouted = 1;
               }
                say(room_inv[i]->query_name() + " turns to fight " + attacker_ob->query_name() + "!\n");
            }
         }
      } 
   }


   /* If we are hasted, attack again, and decrement haste time. */
   if (haste)
   {
      already_fight = 0;
      attack();
      if (attacker_ob)
         haste--;
      if (haste == 0) 
         say(query_name() + " slows its attacks.\n");
   }

   /* Use a crystal for various purposes. */
   if (present("BC_money_crystal"))
   {
      if (attacker_ob)
      {
         if (!random(30) && !haste)
         {
            object mc;
            mc = present("BC_money_crystal");
            haste = (int)mc->query_value() / 100;
            destruct(mc);
            say (HIC + "Crystal Energy" + NORM + " is released by " + query_name() + ".\n");
            say (query_name() + BOLD + " begins to attack faster!\n" + NORM);
         }
      }
      if ((!attacker_ob && !random(10) && hit_point < max_hp) || (!random(20) && hit_point < max_hp && attacker_ob))
      {
         object mc2;
         int heal_amt;
         mc2 = present("BC_money_crystal");
         heal_amt = (int)mc2->query_value() / 10;

         if (heal_amt + hit_point > max_hp)
            heal_amt = max_hp - hit_point;

         heal_self(heal_amt);
         destruct(mc2);
         say (HIC + "Crystal Energy" + NORM + " is released by " + query_name() + ".\n");
         say (query_name() + "'s wounds close!\n");

         /* Add heal bonus by how much we healed. */
         set_hp_bonus(query_hp_bonus() + heal_amt);
      }
   }
}


int dodge()
{
   /* Xetra has a chance to completely dodge an attack. */
   if (attacker_ob && this_player() && attacker_ob == this_player() && DODGE_CHANCE > random(100))
   {
      if (attacker_ob->query_attrib("dex") < random(60) + 1)
      {
         say(query_name() + BOLD + " performs " + GRY + "Wind Claw" + NORM + BOLD + 
             ", completly avoiding an attack!\n" + NORM);
         return 10000;
      }
      say(query_name() + " attempts to dodge and fails!\n");
   }
   return 0;
}

void monster_died()
{
   /* Adjust the faction of the person I was trying to kill. */
   if (attacker_ob && attacker_ob->is_player())
      "/players/llew/Bcrystal/faction_tracker"->add_faction(attacker_ob->query_real_name(), 2);
}
