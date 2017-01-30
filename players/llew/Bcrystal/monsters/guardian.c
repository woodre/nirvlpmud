/* MONSTER:  Xetra Guardian
   LEVEL:    24
   DESCRIPT: Guardians are what they seem.  They help protect other xetra and
             stop people from entering the city of the xetra.  They work best
             in teams.

   SPELLS:   25% chance of 50 hit_player
   SPECIAL:  heal, defend, call to arms, disarm, block, watch

   Heal:     Use a treasure crystal to heal damage.
   Defend:   Use a treasure crystal to increase weapon class.
   Call:     Will tell other xetra in the room to help it fight its target.
   Disarm:   Forces a player to unwield a weapon.
   Block:    This creature has a chance to stop its attacker from leaving the
             room, based on the player's attributes.
   Watch:    Guardians will watch the room they are in to protect other xetra.
             They will try to draw the attention of the enemy to themselves.
*/

#pragma strict_types
#include "/players/llew/closed/ansi.h"
#include "/players/llew/Bcrystal/factions.h"

inherit "obj/monster";

/* Have we used a crystal to increase ac? */
int defend;

/* Declarations */
int prevent();
void call_to_arms();
void watch();


void reset(int arg)
{
   ::reset(arg);
   if(arg) return;

   defend = 0;

   set_name(RED + "Yl'kata Xetra" + NORM);
   set_alt_name("yl'kata");
   set_alias("guardian");
   set_short(RED + "Yl'kata Xetra" + NORM);
   set_race("xetra");
   set_long("   This dark red-skinned creature is humanoid with two huge arms and\n" +
            "two strong legs.  Its bulky massive frame heaves whenever it moves.\n" +
            "Its eyes are wary and onimous.  The fingers on its hands end in\n" +
            "extremely sharp claws.\n");
   set_level(24);
   set_hp(850 + random(100));
   set_wc(40 + random(5));
   set_ac(22 + random(3));
   set_chance(25);
   set_spell_mess1(query_name() + BOLD + " weaves it claws in a deadly " +
                   GRY + "Claw Barrier" + NORM + BOLD + "!" + NORM);
   set_spell_mess2(query_name() + BOLD + " weaves it claws in a deadly " +
                   GRY + "Claw Barrier" + NORM + BOLD + "!" + NORM);
   set_spell_dam(50);
   set_message_hit(({"mutilated"," to a pulpy red mass","slashed"," spraying the room with blood",
                     "thrashed"," with sharp claws","sliced"," cleanly","cut","",
                     "grazed","","scratched"," a glancing blow"}));
   set_chat_chance(3);
   set_a_chat_chance(0);
   load_chat(query_name() + " flexes powerful muscles.\n");
   load_chat(query_name() + " watches the tunnels.\n");
   load_chat(query_name() + " speaks in a strange language.\n");
   load_chat(query_name() + " hefts its strong body.\n");
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
      if (FACTION->query_faction(this_player()->query_real_name()) > HIGH_AGGRO)
      {
         /* Check stealth and attack. */
         if (this_player()->query_attrib("ste") < random(60) + 1)
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

   /* Call */
   if (attacker_ob && !random(8))
      call_to_arms();

   /* Watch */
   if (!attacker_ob && !random(6))
      watch();

   /* Disarm */
   if (attacker_ob && !random(15) && attacker_ob->is_player() && attacker_ob->query_weapon())
   {
      if (attacker_ob->query_attrib("str") < random(weapon_class) + 10)
      {
         say(query_name() + BOLD + " smacks the weapon from " + attacker_ob->query_name() +
             "'s hand!\n" + NORM, attacker_ob);
         tell_object(attacker_ob, query_name() + BOLD + " smacks the weapon from your hand!\n" + NORM);
         attacker_ob->stop_wielding();
      }
      else
         say(query_name() + " attempts to disarm and fails!\n");
   }
   
   /* Use a crystal for various purposes. */
   if (present("BC_money_crystal"))
   {
      if (attacker_ob)
      {
         /* Should we use a crystal for defend? */
         if (!random(10) && !defend)
         {
            object mc1;
            mc1 = present("BC_money_crystal");
            defend = (int)mc1->query_value() / 100;
            armor_class  = pac = query_ac() + defend;
            set_ac(pac);
            destruct(mc1);
            say (HIC + "Crystal Energy" + NORM + " is released by " + query_name() + ".\n");
            say (query_name() + BOLD + " skin hardens with power!\n" + NORM);

            /* Find a armor class bonus based on how long this creature has to live. */
            /* Because ac was increased, this bonus will be negative in a range from */
            /* -defend to 0   In effect, this LOWERS the exp gained.  This must be   */
            /* done to compensate for not having the higher ac for the whole fight.  */
            set_ac_bonus(query_ac_bonus() + (-defend + (defend * hit_point / max_hp)));
         }
      }

      if (((!attacker_ob && !random(10)) || !random(25)) && hit_point != max_hp)
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


/* Call to Arms */                                                  
/* If there is another xetra in the room, get him to attack the same target. */
void call_to_arms()
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

/* Watch */
/* Check the room to see if another xetra is fighting something and help. */
void watch()
{
   object *room_inv;
   int i;

   room_inv = all_inventory(environment());

   for (i = 0; i < sizeof(room_inv); i++)
   {
      if ((string)room_inv[i]->query_race() == "xetra" && room_inv[i] != this_object())
      {
         if ((object)room_inv[i]->query_attack() && !attacker_ob)
         {
            object target;
            target = (object)room_inv[i]->query_attack();
            attack_object(target);
            say (query_name() + " turns to fight " + target->query_name() + "!\n");

            /* Check to see if we can get its attention. */
            if (target->query_attrib("wil") < random(50) + 1)
            {
               say (query_name() + " forces itself in front of " + target->query_name() + "!\n");
               target->stop_fight(); 
               target->stop_fight(); 
               target->attack_object(this_object());
            }

            /* We found someone to fight, so stop looking. */
            return;
         }
      }
   } 
}