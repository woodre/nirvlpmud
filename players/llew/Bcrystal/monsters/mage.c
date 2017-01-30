/* MONSTER:  Chaoti Mage
   LEVEL:    23
   DESCRIPT: 

   SPELLS:   Two spells both 25% chance of 35 hit_player magic damage
   SPECIAL:  phase, shield, healing, stasis, powerboost, hunt

   Phase:    Phase is a percent chance that this creature will completley 
             ignore damage from the object it is fighting.
   Heal:     Use a treasure crystal to heal damage.
   Shield:   Use a treasure crystal to create a damage shield.
   Stasis:   Blocks all the exits in a room for a time.
   Power:    Use a crystal to increase spell damage.
   Hunt:     This creature has a chance to hunt down its attacker by following
             in the direction the player ran.
*/

#pragma strict_types
#include "/players/llew/closed/ansi.h"
#include "/players/llew/Bcrystal/factions.h"

#define PHASE_CHANCE 25
#define STASIS_TIME  20

inherit "obj/monster";

/* Is this creature currently hasted, and for how long. */
int shield;

/* This power boost is a bonus to magical damage. */
int powerboost;

/* Variables for following a player. */
string follow_dir;


/* special attacks variables */
int special_attack_chance;
int special_attack_damage;

/* Declarations */
int phase_shield();
int prevent();
void follow_player();


void reset(int arg)
{
   ::reset(arg);
   if(arg) return;

   shield = 0;
   powerboost = 0;

   set_name(GRN + "Taashadpi Chaoti" + NORM);
   set_alt_name("taashadpi");
   set_alias("mage");
   set_short(GRN + "Taashadpi Chaoti" + NORM);
   set_race("chaoti");
   set_long("   The chaoti is a slender green tinged being.  Its face is triangular with\n" +
            "penetrating rainbow flecked eyes.  Its thin arms are covered with symbols of\n" +
            "power.  It looks ready for a fight.\n");
   set_level(23);
   set_hp(750 + random(100));
   set_wc(30 + random(5));
   set_wc_bonus(5);  /* Because of magical attacks below. */
   set_armor_params("physical",20 + random(3),0,"phase_shield");
   set_armor_params("magical",0,0,"phase_shield");
   special_attack_chance = 30;
   special_attack_damage = 40;
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
   load_chat(query_name() + " produces an arcane symbol.\n");
   load_chat(query_name() + " mutters to itself in a strange language.\n");
   load_chat(query_name() + " chants softly.\n");
   load_a_chat("");

   set_dead_ob(this_object());
   set_heal(5, 5);

   /* See heartbeat below for reason for bonus, an extra spell attack. */
   set_wc_bonus(query_wc_bonus() + (2 * (special_attack_chance * special_attack_damage / 200)));
   /* Slight addition to ac due to dodging attacks. */
   set_ac_bonus(query_ac_bonus() + 3);

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
      if (FACTION->query_faction(this_player()->query_real_name()) < -MED_AGGRO)
      {
         /* Check stealth and attack. */
         if (this_player()->query_attrib("ste") < random(50) + 1)
         {
            say(query_name() + " notices " + this_player()->query_name() + " and attacks!\n");
            attack_object(this_player());
         }
      }
   }

   /* Hunt players if they leave the room. */
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

      /* Even if they get by, we might want to chase them down. */
      if (this_player()->query_attrib("ste") < 50 && !follow_dir) /* Make sure we're not hunting another. */
      {
         follow_dir = query_verb();
         call_out("follow_player", 2);
      }
   }
}

void follow_player()
{
   command(follow_dir);
   follow_dir = 0;
}
       
void heart_beat()
{
   /* Extra special "spell" attack. */
   if (attacker_ob && present(attacker_ob, environment())) 
   {
      if (special_attack_chance > random(100))
      {
         say (query_name() + BOLD + " chants " + HIG + 
         (powerboost ? "Powered Extirpation" : "Extirpation") + NORM + "!\n");

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
      if (special_attack_chance > random(100))
      {
         say (query_name() + BOLD + " chants " + HIG + 
         (powerboost ? "Powered Dissolution" : "Dissolution") + NORM + "!\n");

         say (HIC + "         *" + NORM + CYN + "=" + GRN + "-" + GRY + "<" + HIC + "*" + GRY + 
              ">"+ NORM + GRN + "-" + CYN + "=" + GRY + "<" + NORM + "{" + BOLD + " (" + NORM + 
              YEL + "~ " + NORM + attacker_ob->query_name() );
         say (YEL + " ~" + NORM + BOLD + ") " + NORM + "}" + GRY + ">" + NORM + CYN + "=" + GRN +
              "-" + GRY + "<" + HIC + "*" + GRY + ">" + NORM + GRN + "-" + CYN + "=" + BOLD + 
              "*\n" + NORM);

         attacker_ob->hit_player(random(special_attack_damage), spell_type);
      }
   }

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
         
         if (!random(15) && !powerboost)
         {
            int old_bonus, new_bonus;
            object mc3;
            mc3 = present("BC_money_crystal");
            powerboost = (int)mc3->query_value() / 80;
            destruct(mc3);
            say (HIC + "Crystal Energy" + NORM + " is released by " + query_name() + ".\n");
            say (query_name() + BOLD + " is surrounded by a shining " + HIG + "Aura of Power" + NORM + "!\n");
            

            /* Find a weapon class bonus based on how long this creature has to live. */
            /* Because damage was increased, this bonus will only add experience for  */
            /* the percentage of the creatures remaining life                         */
            old_bonus = (2 * (special_attack_chance * special_attack_damage / 200));
            special_attack_chance += powerboost * 2 / 3;
            special_attack_damage += powerboost;
            new_bonus = (2 * (special_attack_chance * special_attack_damage / 200));
            set_wc_bonus(query_wc_bonus() + ((new_bonus - old_bonus) * hit_point / max_hp) + 2);

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
