/* MONSTER:  Chaoti Explorer
   LEVEL:    22
   DESCRIPT: 

   SPELLS:   Two spells both 25% chance of 35 hit_player magic damage
   SPECIAL:  phase, shield, healing

   Phase:    Phase is a percent chance that this creature will completley 
             ignore damage from the object it is fighting.
   Heal:     Use a treasure crystal to heal damage.
   Shield:   Use a treasure crystal to create a damage shield.
*/

#pragma strict_types
#include "/players/llew/closed/ansi.h"
#include "/players/llew/Bcrystal/factions.h"

#define PHASE_CHANCE 25

inherit "obj/monster";

/* Is this creature currently hasted, and for how long. */
int shield;

/* special attacks variables */
int special_attack_chance;
int special_attack_damage;

/* Declarations */
int phase_shield();

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;

   shield = 0;

   set_name(GRN + "V'restiliar Chaoti" + NORM);
   set_alt_name("v'restiliar");
   set_alias("explorer");
   set_short(GRN + "V'restiliar Chaoti" + NORM);
   set_race("chaoti");
   set_long("   The chaoti is a slender green tinged being.  Its face is triangular with\n" +
            "penetrating rainbow flecked eyes.  Its thin arms move in a graceful dance.\n" +
            "It looks quick and agile.\n");
   set_whimpy();
   set_level(22);
   set_hp(650 + random(100));
   set_wc(34 + random(5));
   set_armor_params("physical",20 + random(3),0,"phase_shield");
   set_armor_params("magical",0,0,"phase_shield");
   special_attack_chance = 25;
   special_attack_damage = 35;
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
   load_chat(query_name() + " studies the crystal.\n");
   load_chat(query_name() + " mutters to itself in a strange language.\n");
   load_chat(query_name() + " makes a small mark on a wall a finger.\n");
   load_a_chat("");

   set_dead_ob(this_object());
   set_heal(5, 5);

   /* See heartbeat below for reason for bonus, an extra spell attack. */
   set_wc_bonus(query_wc_bonus() + (2 * (special_attack_chance * special_attack_damage / 200)));
   /* Slight addition to ac due to dodging attacks. */
   set_ac_bonus(query_ac_bonus() + 2);

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

void init()
{
   ::init();

   if (this_player() && this_player()->is_player())
   {
      if (FACTION->query_faction(this_player()->query_real_name()) < -MED_AGGRO)
      {
         /* Check stealth and run. */
         if (this_player()->query_attrib("ste") < random(50))
         {
            say(query_name() + " sees " + this_player()->query_name() + " and flees!\n");
            run_away();
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
         say (query_name() + BOLD + " chants " + HIG + "Abrogation" + NORM + "!\n");
         say (HIC + "      *" + NORM + CYN + "=" + GRN + "---" + CYN + "=" + GRY + "<" + 
              NORM + "{ " + BOLD + "(" + HIG + "+ " + NORM + attacker_ob->query_name() + 
              HIG + " +" + NORM + BOLD + ")" + NORM + " }" + GRY + ">" + NORM + CYN + "=" +
              GRN + "---" + CYN + "=" + HIC + "*\n" + NORM);
         attacker_ob->hit_player(random(special_attack_damage), spell_type);
      }
      if (special_attack_chance > random(100))
      {
         say (query_name() + BOLD + " chants " + HIG + "Negation" + NORM + "!\n");
         say (HIC + "      *" + NORM + CYN + "=" + GRN + "---" + CYN + "=" + GRY + "<" + 
              NORM + "{ " + BOLD + "(" + HIC + "* " + NORM + attacker_ob->query_name() + 
              HIC + " *" + NORM + BOLD + ")" + NORM + " }" + GRY + ">" + NORM + CYN + "=" +
              GRN + "---" + CYN + "=" + HIC + "*\n" + NORM);
         attacker_ob->hit_player(random(special_attack_damage), spell_type);
      }
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
   /* Will phase away from impending attacks. */
   if (attacker_ob && this_player() && attacker_ob == this_player() && PHASE_CHANCE > random(100))
   {
      if (attacker_ob->query_attrib("int") < random(50) + 1)
      {
         say(query_name() + BOLD + " chants " + HIG + "Phase" + NORM + BOLD + 
             ", blinking away from an attack!\n" + NORM);
         return 10000;
      }
      say(query_name() + " attempts to phase and fails!\n");
   }

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
