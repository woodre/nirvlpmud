/* MONSTER:  Chaoti Defender
   LEVEL:    24
   DESCRIPT: 

   SPELLS:   Two spells both 25% chance of 35 hit_player magic damage
   SPECIAL:  shield, healing, stasis, watch, dazzle

   Heal:     Use a treasure crystal to heal damage.
   Shield:   Use a treasure crystal to create a damage shield.
   Stasis:   Blocks all the exits in a room for a time.
   Watch:    Defeners will watch the room they are in to protect other chaoti.
             They will try to draw the attention of the enemy to themselves.
   Dazzle:   This very powerful ability will place an object in the room which
             disallows ALL commands.
*/

#pragma strict_types
#include "/players/llew/closed/ansi.h"
#include "/players/llew/Bcrystal/factions.h"

#define STASIS_TIME  20
#define DAZZLE_TIME  8

inherit "obj/monster";

/* Is this creature currently shielded, and for how long. */
int shield;

/* special attacks variables */
int special_attack_chance;
int special_attack_damage;

/* Declarations */
int phase_shield();
void watch();
void dazzle();


void reset(int arg)
{
   ::reset(arg);
   if(arg) return;

   shield = 0;

   set_name(GRN + "Rinmlaqadan Chaoti" + NORM);
   set_alt_name("rinmlaqadan");
   set_alias("defender");
   set_short(GRN + "Rinmlaqadan Chaoti" + NORM);
   set_race("chaoti");
   set_long("   The chaoti is a slender green tinged being.  Its face is triangular with\n" +
            "penetrating rainbow flecked eyes.  A glowing aura surrounds the chaoti,\n" +
            "protecting it from danger.  It watches the area intently.\n");
   set_level(24);
   set_hp(850 + random(100));
   set_wc(33 + random(5));
   set_wc_bonus(5);  /* Because of magical attacks below. */
   set_armor_params("physical",24 + random(3),0,"phase_shield");
   set_armor_params("magical",10,0,"phase_shield");
   special_attack_chance = 30;
   special_attack_damage = 50;
   set_spell_type("magical");

   set_message_hit(({"annihilated", " with great magical force",
                     "destoyed", " with magical energy",
                     "devastated", " traumatically",
                     "blasts","",
                     "damages"," with a burst of energy",
                     "bruised"," with energy",
                     "glanced",""}));
   set_chat_chance(3);
   set_a_chat_chance(0);
   load_chat(query_name() + " scans the passages.\n");
   load_chat(query_name() + " chants and an aura appears.\n");
   load_chat(query_name() + " mutters to itself in a strange language.\n");
   load_chat(query_name() + " looks around.\n");
   load_a_chat("");

   set_dead_ob(this_object());
   set_heal(5, 5);

   /* See heartbeat below for reason for bonus, an extra spell attack. */
   set_wc_bonus(query_wc_bonus() + (special_attack_chance * special_attack_damage / 200));
 
   /* TREASURE */
   {
      int crystals;
      crystals = random(5) + 2; 
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
      if (FACTION->query_faction(this_player()->query_real_name()) < -HIGH_AGGRO)
      {
         /* Check stealth and attack. */
         if (this_player()->query_attrib("ste") < random(50) + 1)
         {
            say(query_name() + " notices " + this_player()->query_name() + " and attacks!\n");
            attack_object(this_player());
         }
      }
   }
}
 
       
void heart_beat()
{
   /* Extra special "spell" attack. */
   if (attacker_ob && present(attacker_ob, environment())) 
   {
      if (special_attack_chance > random(100))
      {
         say (query_name() + BOLD + " chants " + HIG + "Extirpation" + NORM + "!\n");

         say (HIC + "      *" + NORM + CYN + "=" + GRN + "--" + CYN + "=" + GRN + "-" + HIB + 
              "[" + HIC + "*" + HIB + "]" + NORM + GRN + "-" + CYN + "=" + GRY + "<" +
              NORM + "{ " + BOLD + "(" + HIB + "[" + NORM + HIG + "# " + NORM +
              attacker_ob->query_name() + HIG);
         say (" #" + HIB + "]" + NORM + BOLD + ")" +
              NORM + " }" + GRY + ">" + NORM + CYN + "=" + GRN + "-" + HIB + "[" + 
              HIC + "*" + HIB + "]" + NORM + GRN + "-" + CYN + "=" + GRN + "--" +
              CYN + "=" + BOLD + "*\n" + NORM);

       attacker_ob->hit_player(random(special_attack_damage), spell_type);
      }
   }

   /* Watch */
   if (!attacker_ob && !random(6))
      watch();

   if (attacker_ob && !random(16))
      dazzle();

   /* Chance to put up a statis field if one does not exist. */
   if (attacker_ob && !present("BC_stasisfield", environment()) && !random(10))
   {
      object field;
      field = clone_object("/players/llew/Bcrystal/monsters/stasisfield");
      move_object(field, environment());
      field->set_length(STASIS_TIME);

      say (query_name() + BOLD + " chants " + HIG + "Stasis" + NORM + "!\n");
      say ("A pulsating " + field->short() + " blocks all exit!\n");            
   }

   /* Call the normal heartbeat. */
   ::heart_beat();

   /* If we are shielded, decrease time and check for finish. */
   if (shield)
   {
      if (attacker_ob)
         shield--;
      if (shield == 0) 
         say(BOLD + " The glowing " + HIG + "Shield" + NORM + BOLD + " around " + query_name() + " fades.\n");
   }

   /* Use a crystal for various purposes. */
   if (present("BC_money_crystal"))
   {
      if (attacker_ob)
      {
         if (!random(15) && !shield)
         {
            object mc;
            mc = present("BC_money_crystal");
            shield = (int)mc->query_value() / 100;
            destruct(mc);
            say (HIC + "Crystal Energy" + NORM + " is released by " + query_name() + ".\n");
            say (query_name() + BOLD + " is surrounded by a glowing " + HIG + "Shield" + NORM + "!\n");
         }
         
      }
      if (((!attacker_ob && !random(10)) || !random(20)) && hit_point != max_hp)
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


int phase_shield()
{
   /* If we have damage shield on, do some damage to our attacker. */
   if (shield)
   {
      if (this_player())
      {
         write ("You are hit by the backlash of the " + HIG + "Shield" + NORM + "!\n");
         say (this_player()->query_name() + " is hit from the blacklash of the " + HIG + "Shield" + NORM + "!\n", this_player());
         this_player()->do_damage(shield + 5, "magical");
      }
   }

   return 0;
}

void monster_died()
{
   /* Adjust the faction of the person I was trying to kill. */
   if (attacker_ob && attacker_ob->is_player())
      "/players/llew/Bcrystal/faction_tracker"->add_faction(attacker_ob->query_real_name(), -1);
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
      if ((string)room_inv[i]->query_race() == "chaoti" && room_inv[i] != this_object())
      {
         if ((object)room_inv[i]->query_attack() && !attacker_ob)
         {
            object target;
            target = (object)room_inv[i]->query_attack();
            say (query_name() + " turns to fight " + target->query_name() + "!\n");

            /* Check to see if we can get its attention. */
            if (target->query_attrib("wil") < random(50) + 1)
            {
               say (query_name() + " forces itself in front of " + target->query_name() + "!\n");
               target->stop_fight(); 
               target->stop_fight(); 
               target->attack_object(this_object());
            }

            attack_object(target);
            /* We found someone to fight, so stop looking. */
            return;
         }
      }
   } 
}

void dazzle()
{
   if (!present("BC_dazzle", environment()))
   {
      object dazzle_object;
      
      string *spam;
      int spamsize;
      string *colors;

      int i,j;

      say (query_name() + BOLD + " chants " + HIG + "Fascination" + BOLD + "!!!\n" + NORM);
      say (BOLD + "The room is filled with dazzling lights!\n\n" + NORM);

      /* Put some random junk on the screen. */
      spam = ({ ".", "#", "*", "~", "%", ",", "`",
                "^", "o", "@", "*", "*", });
      spamsize = sizeof(spam);
      colors = ({ HIB, HIR, HIC, HIM, HIG, HIW, GRY, HIY });
      for (i = 0; i < 10; i++)
      {
         say("          ");
         for (j = 0; j < 60; j++)
         {
            if (!random(4))
               say (colors[random(8)] + spam[random(spamsize)]);
            else say (" ");
         }
         say ("\n");
      }
      
      dazzle_object = clone_object("/players/llew/Bcrystal/monsters/dazzle");
      move_object(dazzle_object, environment());
      dazzle_object->set_length(DAZZLE_TIME);         
   }
}
