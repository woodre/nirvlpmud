/* MONSTER:  Chaoti Assassin
   LEVEL:    24
   DESCRIPT: 

   SPELLS:   Two spells both 30% chance of 45 hit_player magic damage
   SPECIAL:  phase, healing, stealth, stasis, strip, assassinate, hunt

   Phase:    Phase is a percent chance that this creature will completley 
             ignore damage from the object it is fighting.
   Heal:     Use a treasure crystal to heal damage.
   Stealth:  Stealth is more style than power.  It shows no short to low Int.  
   Stasis:   Blocks all the exits in a room for a time.
   Strip:    Removes all armor from target and won't allow them to replace it
             for 7-12 seconds.
   Assassin: The assassinate skill checks the hit points of its targets.
             If health is low enough, hunter attacks it until it dies.
   Hunt:     This creature has a chance to hunt down its attacker by following
             in the direction the player ran.
*/

#pragma strict_types
#include "/players/llew/closed/ansi.h"
#include "/players/llew/Bcrystal/factions.h"

#define PHASE_CHANCE 30
#define STASIS_TIME  20
#define ASSASSINATE_LEVEL 60


inherit "obj/monster";

/* special attacks variables */
int special_attack_chance;
int special_attack_damage;

/* Variables for following a player. */
string follow_dir;

/* This tracks a special attack the assassin can perform. */
int assassinate;
int countdown;


/* Declarations */
int phase_shield();
int prevent();
void follow_player();
void assassination();

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;

   countdown = 1;

   set_name(GRN + "Kga'as'tah Chaoti" + NORM);
   set_alt_name("kga'as'tah");
   set_alias("assassin");
   set_short(GRN + "Kga'as'tah Chaoti" + NORM);
   set_race("chaoti");
   set_long("   The chaoti is a slender green tinged being.  Its face is triangular with\n" +
            "penetrating rainbow flecked eyes.  Its form seems to be hard to keep track of.\n" +
            "It shimmers and fades in the light of the crystal.  It looks alert and deadly.\n");
   set_whimpy();
   set_level(24);
   set_hp(850 + random(100));
   set_wc(31 + random(5));
   set_wc_bonus(7);
   set_armor_params("physical",22 + random(3),0,"phase_shield");
   set_armor_params("magical",0,0,"phase_shield");
   special_attack_chance = 30;
   special_attack_damage = 45;
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
   load_chat(query_name() + " searches the area.\n");
   load_chat(query_name() + " mutters to itself in a strange language.\n");
   load_chat(query_name() + " looks for tracks.\n");
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

/* Stealth */
mixed short()
{
   if (this_player() && this_player()->query_level() > 20)
      return short_desc;
   if (this_player() && environment(this_player()) == environment())
   {
      if (this_player()->query_attrib("int") < random(50) + 1)
         return 0;
   }
   return short_desc;
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
         say (query_name() + BOLD + " chants " + HIG + "Abolition" + NORM + "!\n");

         say (HIC + "      *" + NORM + CYN + "=" + GRN + "--" + CYN + "=" + GRN + "-" + HIB + 
              "[" + HIC + "*" + HIB + "]" + NORM + GRN + "-" + CYN + "=" + GRY + "<" +
              NORM + "{ " + BOLD + "(" + HIB + "[" + NORM + HIG + "# " + NORM +
              attacker_ob->query_name() + HIG + " #" + HIB);
         say ("]" + NORM + BOLD + ")" + NORM + " }" + GRY + ">" + NORM + CYN + "=" + GRN +
              "-" + HIB + "[" + HIC + "*" + HIB + "]" + NORM + GRN + "-" + CYN + "=" + GRN +
              "--" + CYN + "=" + BOLD + "*\n" + NORM);

       attacker_ob->hit_player(random(special_attack_damage), spell_type);
      }
      if (special_attack_chance > random(100))
      {
         say (query_name() + BOLD + " chants " + HIG + "Obliteration" + NORM + "!\n");

         say (HIC + "      *" + NORM + CYN + "=" + GRN + "---" + CYN + "=" + GRY + "<" + 
              NORM + "{ " + BOLD + "(" + HIG + "+ " + NORM + attacker_ob->query_name() + 
              HIG + " +" + NORM + BOLD + ")" + NORM + " }" + GRY + ">" + NORM + CYN + "=" +
              GRN + "---" + CYN + "=" + HIC + "*\n" + NORM);

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

   /* Perform an assassination. */
   if (assassinate && attacker_ob)
   {
      if (countdown == 0)
         assassination();
      else
      {
         countdown--;
         say (query_name() + BOLD + "'s hands glow with immense " + HIG + "POWER" + NORM + BOLD + "!\n" + NORM);
         say (HIC + "Light" + NORM + BOLD + " shoots from " + query_name() + "'s hands at " + NORM +
              attacker_ob->query_name() + "!\n");
         say (attacker_ob->query_name() + BOLD + "'s armor falls away!\n\n" + NORM);

         /* Remove this persons armor. */
         {
            int x;
            mixed *k;
            object noarm;

            k = keys((mapping)attacker_ob->QueryArmors());

            for (x = 0; x < sizeof(k); x++)
            {
               attacker_ob->RemoveArmor(k[x]);
               k[x]->take_off();
            }

            noarm = clone_object("/players/llew/Bcrystal/monsters/armorblock");
            move_object(noarm, attacker_ob);
            noarm->set_time(assassinate);
         }
      }
   }

   /* Use a crystal for various purposes. */
   if (present("BC_money_crystal"))
   {
      if (attacker_ob)
      {
         /* Assassinate */
         if (!random(25) && !assassinate)
         {
            object mc;
            mc = present("BC_money_crystal");
            assassinate = (int)mc->query_value() / 100;
            destruct(mc);
            say (HIC + "Crystal Energy" + NORM + " is released by " + query_name() + ".\n");
            say (query_name() + BOLD + "'s hands glow with incredible " + GRN + "power" + NORM + BOLD + "!\n" + NORM);
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

   return 0;
}

void monster_died()
{
   /* Adjust the faction of the person I was trying to kill. */
   if (attacker_ob && attacker_ob->is_player())
      "/players/llew/Bcrystal/faction_tracker"->add_faction(attacker_ob->query_real_name(), -1);
}

void assassination()
{
   object *targets, *targets2;
   object *room_inv;
   int i, target;

   room_inv = all_inventory(environment());
   targets = ({});

   /* Make a list of enemies in the room. */
   for (i = 0; i < sizeof(room_inv); i++)
   {
      if (((object)room_inv[i]->query_attack() == this_object() && room_inv[i] != this_object())
         || room_inv[i] == attacker_ob)
         targets += ({ room_inv[i] });
   }


   /* Check our targets for assassination. */
   for (i = 0; i < sizeof(targets); i++)
   {
      /* Check attacker for level, everyone else for level * 2 */
      if (targets[i] && ((targets[i] == attacker_ob && targets[i]->query_hp() < ASSASSINATE_LEVEL)
         ||  (targets[i] != attacker_ob && targets[i]->query_hp() < ASSASSINATE_LEVEL * 2)))
      {
         int j;
         object corpse;

         /* Let's kill it. */
         say (query_name() + " releases the " + HIG + "POWER" + NORM + " of " + HIG + "Annihilation" + NORM + "!!!\n\n");

         say("                      " + GRY + pad("", strlen((string)targets[i]->query_name()), '_') + "\n" +
            HIC + "            *" + NORM + CYN + "=" + GRN + "-" + GRY + "<" + CYN + "*" + GRY + ">" +
            NORM + GRN + "-" + CYN + "=" + GRN + "-" + GRY + "/    \\" + NORM + GRN + "-" + CYN + "=" + 
            GRN + "-" + GRY + "<" + CYN + "*" + GRY + ">" + NORM + GRN + "-" + CYN + "=" + BOLD + "*\n");

         say("     *" + NORM + CYN + "=" + GRN + "--" + CYN + "=" + GRY + "<" + CYN + "*" + HIB + "]" + 
            NORM + CYN + "=" + GRN + "---" + CYN + "=" + GRY + "<" + NORM + "{" + BOLD + "( " + NORM + 
            targets[i]->query_name() + BOLD + " )" + NORM + "}" + GRY + ">" + NORM + CYN + "=" + GRN + "---" + 
            CYN + "=" + HIB + "[" + CYN + "*" + GRY + ">" + NORM + CYN + "=" + GRN + "--" + CYN + "=" + BOLD + "*\n");

         say(HIC + "            *" + NORM + CYN + "=" + GRN + "-" + GRY + "<" + CYN + "*" + GRY + ">" +
            NORM + GRN + "-" + CYN + "=" + GRN + "-" + GRY +"\\" + pad("", strlen((string)targets[i]->query_name()), '_') +
            GRY + "/" + NORM + GRN + "-" + CYN + "=" + GRN + "-" + GRY + "<" + CYN + "*" + GRY + ">" + 
            NORM + GRN + "-" + CYN + "=" + BOLD + "*\n\n" +NORM);

         for (j = 0;j < 10; j++)
         {
            if (targets[i])
               targets[i]->hit_player(1000, "magical");
         }
        
         /* Probably dead by now */
         if (corpse = present("corpse", environment()))
         {
            say (BOLD + "The corpse of " + NORM + capitalize((string)corpse->query_name()) + " is nothing but dust!\n\n");
            destruct(corpse);
         }
      }
   }
   assassinate = 0;
   countdown = 1;

}