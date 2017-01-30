/* MONSTER:  Xetra Warrior
   LEVEL:    23
   DESCRIPT: Warriors are the main fighting force of the xetra.  They will
             try to fight in groups with other warriors, though they may not
             care if another is being attacked.  

   SPELLS:   25% chance of 50 hit_player
   SPECIAL:  haste, healing, might, call to arms, block

   Haste:    Use a treasure crystal to increase attacks for awhile.
   Heal:     Use a treasure crystal to heal damage.
   Might:    Use a treasure crystal to increase weapon class.  Low chance.
   Call:     Will tell other xetra in the room to help it fight its target.
   Block:    This creature has a chance to stop its attacker from leaving the
             room, based on the player's attributes.
*/

#pragma strict_types
#include "/players/llew/closed/ansi.h"
#include "/players/llew/Bcrystal/factions.h"

inherit "obj/monster";

/* Is this creature currently hasted, and for how long. */
int haste;
/* Have we used a crystal to increase wc? */
int mighty;

/* Declarations */
int prevent();


void reset(int arg)
{
   ::reset(arg);
   if(arg) return;

   haste = 0;
   mighty = 0;

   set_name(RED + "Hroct Xetra" + NORM);
   set_alt_name("hroct");
   set_alias("warrior");
   set_short(RED + "Hroct Xetra" + NORM);
   set_race("xetra");
   set_long("   This dark red-skinned creature is humanoid with two long arms and\n" +
            "two strong legs.  It's heavy muscles bulge with every deadly movement.\n" +
            "Its eyes are keen and full of danger.  The fingers on its hands end in\n" +
            "extremely sharp claws.\n");
   set_level(23);
   set_hp(750 + random(100));
   set_wc(40 + random(5));
   set_ac(23 + random(3));
   set_chance(25);
   set_spell_mess1(query_name() + BOLD + " slashes forward with a mighty " +
                   GRY + "Great Claw" + NORM + BOLD + "!" + NORM);
   set_spell_mess2(query_name() + BOLD + " slashes forward with a mighty " +
                   GRY + "Great Claw" + NORM + BOLD + "!" + NORM);
   set_spell_dam(50);
   set_message_hit(({"mutilated"," to a pulpy red mass","slashed"," spraying the room with blood",
                     "thrashed"," with sharp claws","sliced"," cleanly","cut","",
                     "grazed","","scratched"," a glancing blow"}));
   set_chat_chance(3);
   set_a_chat_chance(0);
   load_chat(query_name() + " flexes powerful muscles.\n");
   load_chat(query_name() + " watches the tunnels.\n");
   load_chat(query_name() + " speaks in a strange language.\n");
   load_chat(query_name() + " sharpens its claws.\n");
   set_dead_ob(this_object());
   set_heal(5, 5);

   /* TREASURE */
   {
      int crystals;
      crystals = random(5) + 1;  /* 1 to 5 crystals */
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
      if (FACTION->query_faction(this_player()->query_real_name()) > MED_AGGRO)
      {
         /* Check stealth and attack. */
         if (this_player()->query_attrib("ste") < random(50) + 1)
         {
            say(query_name() + " notices " + this_player()->query_name() + " and attacks!\n");
            attack_object(this_player());
         }
      }
   }

   /* Prevent players from leaving the room. */
   add_action("prevent","north");
   add_action("prevent","south");
   add_action("prevent","east");
   add_action("prevent","west");
   add_action("prevent","northeast");
   add_action("prevent","northwest");
   add_action("prevent","southeast");
   add_action("prevent","southwest");
}

int prevent()
{
   if (this_player() && this_player()->query_level() < 20
       && member_array(query_verb(), (string *)environment()->query_dest_dir()) > -1)
   {
      int check;

      /* Let them go if I'm not mad. */
      if (this_player() != attacker_ob)
         return 0;

      /* They may be able to push past if they make a dex/str check. */
      check = (int)(this_player()->query_attrib("dex") + this_player()->query_attrib("str")) / 2;
      if (check < random(50) + 1)
      {  
         write (query_name() + BOLD + " stops you from leaving!\n" + NORM);
         return 1;
      }
   }
}

void monster_died()
{
   /* Adjust the faction of the person I was trying to kill. */
   if (attacker_ob && attacker_ob->is_player())
      "/players/llew/Bcrystal/faction_tracker"->add_faction(attacker_ob->query_real_name(), 1);
}

void heart_beat()
{
   /* Call the normal heartbeat. */
   ::heart_beat();

   /* Call to Arms */                                                  
   /* If there is another xetra in the room, get him to attack the same target. */
   if (attacker_ob && !random(8))
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
         /* Should we use a crystal for haste? */
         if (!random(12) && !haste)
         {
            object mc;
            mc = present("BC_money_crystal");
            haste = (int)mc->query_value() / 100;
            destruct(mc);
            say (HIC + "Crystal Energy" + NORM + " is released by " + query_name() + ".\n");
            say (query_name() + BOLD + " begins to attack faster!\n" + NORM);
         }
         /* Should we use a crystal for might? */
         else if (!random(10) && !mighty)
         {
            object mc1;
            mc1 = present("BC_money_crystal");
            mighty = (int)mc1->query_value() / 100;
            weapon_class += mighty;
            destruct(mc1);
            say (HIC + "Crystal Energy" + NORM + " is released by " + query_name() + ".\n");
            say (query_name() + BOLD + " muscles bulge with immense power!\n" + NORM);

            /* Find a weapon class bonus based on how long this creature has to live. */
            /* Because wc was increased, this bonus will be negative in a range from  */
            /* -mighty to 0   In effect, this LOWERS the exp gained.  This must be    */
            /* done to compensate for not having the high wc for the whole fight.     */
            set_wc_bonus(query_wc_bonus() + (-mighty + (mighty * hit_point / max_hp)));
         }
      }
      if ((!attacker_ob && !random(10) && hit_point != max_hp) || (attacker_ob && hit_point < max_hp && attacker_ob))
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
