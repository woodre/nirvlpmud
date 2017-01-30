/* MONSTER:  Xetra Hunter
   LEVEL:    24
   DESCRIPT: Hunters go deep into the unknown paths, searching for enemies
             to kill.  They use cunning and stealth to quickly kill any they
             encounter.  A hunter's job is to kill, but not at the cost of
             their own life.

   SPELLS:   Two spells both 30% change of 50 hit_player
   SPECIAL:  Dodge, healing, assassinate, stealth, block, hunt

   Dodge:    Dodge is a percent chance that this creature will completley 
             ignore damage from the object it is fighting.
   Heal:     Use a treasure crystal to heal damage.
   Assassin: The assassinate skill attacks everything in the room that is 
             attacking it, then it checks the hit points of its targets.
             If health is low enough, hunter attacks it until it dies.
   Stealth:  Stealth is more style than power.  It shows no short to low Int.  
   Block:    This creature has a chance to stop its attacker from leaving the
             room, based on the player's attributes.
   Hunt:     This creature has a chance to hunt down its attacker by following
             in the direction the player ran.
*/

#pragma strict_types
#include "/players/llew/closed/ansi.h"
#include "/players/llew/Bcrystal/factions.h"

#define DODGE_CHANCE 35
#define ASSASSINATE_LEVEL 50

inherit "obj/monster";

/* This tracks a special attack the hunter can perform. */               
int assassinate;
int countdown;

/* Variables for following a player. */
string follow_dir;

/* Declarations */
int dodge();
int prevent();
void follow_player();
void assassination();


void reset(int arg)
{
   ::reset(arg);
   if(arg) return;

   assassinate = 0;
   follow_dir = 0;
   countdown = 1;

   set_name(RED + "Nuidcali Xetra" + NORM);
   set_alt_name("nuidcali");
   set_alias("hunter");
   set_short(RED + "Nuidcali Xetra" + NORM);
   set_race("xetra");
   set_long("   This dark red-skinned creature is humanoid with two long arms and\n" +
            "two lithe legs.  It is of light build and looks extremely deadly.\n" +
            "Its eyes are full of cunning and death.  The fingers on its hands end\n" +
            "in extremely sharp claws.\n");
   set_whimpy();
   set_level(24);
   set_hp(850 + random(100));
   set_wc(45 + random(5));
   set_armor_params("physical",20 + random(3),0,"dodge");
   set_armor_params("magical",0,0,"dodge");
   set_chance(30);
   set_spell_mess1(query_name() + BOLD + " blurs in motions as it performs " +
                   GRY + "Eviscerate" + NORM + BOLD + "!" + NORM);
   set_spell_mess2(query_name() + BOLD + " blurs in motions as it performs " +
                   GRY + "Eviscerate" + NORM + BOLD + "!" + NORM);
   set_spell_dam(50);
   set_message_hit(({"mutilated"," to a pulpy red mass","slashed"," spraying the room with blood",
                     "thrashed"," with sharp claws","sliced"," cleanly","cut","",
                     "grazed","","scratched"," a glancing blow"}));
   set_chat_chance(3);
   set_a_chat_chance(0);
   load_chat(query_name() + " hunts for prey.\n");
   load_chat(query_name() + " hides in shadow.\n");
   load_chat(query_name() + " sniffs the air.\n");
   set_dead_ob(this_object());
   set_heal(5, 5);

   /* See heartbeat below for reason for bonus, an extra spell attack. */
   set_wc_bonus(query_wc_bonus() + (spell_chance * spell_dam_mon / 200));
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
      if (FACTION->query_faction(this_player()->query_real_name()) > HIGH_AGGRO)
      {
         /* Check stealth and attack. */
         if (this_player()->query_attrib("ste") < random(100) + 1)
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
      else
      {
         /* Even if they get by, we might want to chase them down. */
         if (this_player()->query_attrib("ste") < 50 && !follow_dir) /* Make sure we're not hunting another. */
         {
            follow_dir = query_verb();
            call_out("follow_player", 2);
         }               
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
   if (attacker_ob && present(attacker_ob, environment(this_object())) &&
      spell_chance > random(100)) 
   {
           say(query_name() + BOLD + " drills its claws forward to " + GRY + "Enervate" + NORM + "!\n");
      attacker_ob->hit_player(random(spell_dam_mon), spell_type);
   }

   /* Call the normal heartbeat. */
   ::heart_beat();

   /* Perform an assassination. */
   if (assassinate)
   {
      if (countdown == 0)
         assassination();
      else
      {
         countdown--;
         say (query_name() + BOLD + "'s claws glow with immense " + HIR + "POWER" + NORM + BOLD + "!\n" + NORM);
      }
   }


   /* Use a crystal for various purposes. */
   if (present("BC_money_crystal"))
   {
      if (attacker_ob)
      {
         if (!random(12) && !assassinate)
         {
            object mc;
            mc = present("BC_money_crystal");
            assassinate = ((int)mc->query_value()  * 3) / 500;
            destruct(mc);
            say (HIC + "Crystal Energy" + NORM + " is released by " + query_name() + ".\n");
            say (query_name() + BOLD + "'s claws glow with incredible " + RED + "power" + NORM + BOLD + "!\n" + NORM);
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


/* Assassination */
void assassination()
{
   object *targets, *targets2;
   object *room_inv;
   int i, target;

   room_inv = all_inventory(environment());
   targets = ({});
   targets2 = ({});

   /* Make a list of enemies in the room. */
   for (i = 0; i < sizeof(room_inv); i++)
   {
      if (((object)room_inv[i]->query_attack() == this_object() && room_inv[i] != this_object())
         || room_inv[i] == attacker_ob)
         targets += ({ room_inv[i] });
   }


   if (sizeof(targets))
   {
      /* Make an attack list. */
      while (assassinate > 0)
      {
         targets2 += ({ targets[random(sizeof(targets))] });
         assassinate--;
      }

      say (query_name() + BOLD + " devastates its enemies with " + GRY + "Whirldwind Stike" + NORM + BOLD + "!!!\n");
      say (HIR + "|---------------------------------------------------------------------|\n" + NORM);

      /* Attack stuff. */
      for (i = 0; i < sizeof(targets2); i++)
      {
         if (targets2[i] && !targets2[i]->query_ghost())
         {
            already_fight = 0;
            attack_object(targets2[i]);
         }
      }
      say (HIR + "|---------------------------------------------------------------------|\n" + NORM);
   }

   /* Check our targets for assassination. */
   for (i = 0; i < sizeof(targets2); i++)
   {
      if (targets2[i] && targets2[i]->query_hp() < ASSASSINATE_LEVEL)
      {
         int j;
         object corpse;

         /* Let's kill it. */
         say (query_name() + " charges forward to perform " + GRY + "Hunter Strike" + NORM + BOLD + "!!!\n\n" + NORM);
         for (j = 0;j < 10; j++)
         {
            already_fight = 0;
            attack_object(targets2[i]);
         }
         /* Probably dead by now */
         if (corpse = present("corpse", environment()))
         {
            say ("\n" + query_name() + BOLD + " completely ravages the corpse of " + NORM + capitalize((string)corpse->query_name()) + "!\n\n");
            destruct(corpse);
         }
      }
   }
   countdown = 1;
}