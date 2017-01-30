/* MONSTER:  Xetra Scout
   LEVEL:    22
   DESCRIPT: Scouts explore the reaches of the crystal away from the xetra
             city.  They'll run from too much danger, but are a formidable
             opponent if forced to fight.

   SPELLS:   Two spells both 25% chance of 40 hit_player
   SPECIAL:  Dodge, haste, healing

   Dodge:    Dodge is a percent chance that this creature will completley 
             ignore damage from the object it is fighting.
   Heal:     Use a treasure crystal to heal damage.
   Haste:    Use a treasure crystal to increase attacks for awhile.
*/

#pragma strict_types
#include "/players/llew/closed/ansi.h"
#include "/players/llew/Bcrystal/factions.h"

#define DODGE_CHANCE 30

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

   set_name(RED + "Bsirri Xetra" + NORM);
   set_alt_name("bsirri");
   set_alias("scout");
   set_short(RED + "Bsirri Xetra" + NORM);
   set_race("xetra");
   set_long("   This dark red-skinned creature is humanoid with two long arms and\n" +
            "two strong legs.  It is of medium build and looks surprisingly agile.\n" +
            "Its eyes are alert to everything around.  The fingers on its hands end\n" +
            "in extremely sharp claws.\n");
   set_whimpy();
   set_level(22);
   set_hp(650 + random(100));
   set_wc(37 + random(5));
   set_armor_params("physical",20 + random(3),0,"dodge");
   set_armor_params("magical",0,0,"dodge");
   set_chance(25);
   set_spell_mess1(query_name() + BOLD + " leaps to the side for a quick " +
                   GRY + "Claw Stab" + NORM + BOLD + "!" + NORM);
   set_spell_mess2(query_name() + BOLD + " leaps to the side for a quick " +
                   GRY + "Claw Stab" + NORM + BOLD + "!" + NORM);
   set_spell_dam(40);
   set_message_hit(({"mutilated"," to a pulpy red mass","slashed"," spraying the room with blood",
                     "thrashed"," with sharp claws","sliced"," cleanly","cut","",
                     "grazed","","scratched"," a glancing blow"}));
   set_chat_chance(3);
   set_a_chat_chance(0);
   load_chat(query_name() + " scans the passages.\n");
   load_chat(query_name() + " studies the crystal.\n");
   load_chat(query_name() + " mutters to itself in a strange language.\n");
   load_chat(query_name() + " makes a small claw mark on a wall.\n");
   set_dead_ob(this_object());
   set_heal(5, 5);

   /* See heartbeat below for reason for bonus, an extra spell attack. */
   set_wc_bonus(query_wc_bonus() + (spell_chance * spell_dam_mon / 200));
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
      if (FACTION->query_faction(this_player()->query_real_name()) > MED_AGGRO)
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
   if (attacker_ob && present(attacker_ob, environment(this_object())) &&
      spell_chance > random(100)) 
   {
           say(query_name() + BOLD + " lunges both hands forward in a " + GRY + "Claw Impale" + NORM + "!\n");
      attacker_ob->hit_player(random(spell_dam_mon), spell_type);
   }

   /* Call the normal heartbeat. */
   ::heart_beat();

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
         if (!random(15) && !haste)
         {
            object mc;
            mc = present("BC_money_crystal");
            haste = (int)mc->query_value() / 100;
            destruct(mc);
            say (HIC + "Crystal Energy" + NORM + " is released by " + query_name() + ".\n");
            say (query_name() + BOLD + " begins to attack faster!\n" + NORM);
         }
      }
      if (!attacker_ob && !random(10) && hit_point != max_hp)
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
      if (attacker_ob->query_attrib("dex") < random(50) + 1)
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
      "/players/llew/Bcrystal/faction_tracker"->add_faction(attacker_ob->query_real_name(), 1);
}
