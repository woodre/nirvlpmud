/* MONSTER:  Xetra Berserker
   LEVEL:    25
   DESCRIPT: Berserkers are the elite shock troops of the xetra.  They are
             feared by all, included most xetra.  They always fight alone,
             seeking a fight to challenge their skill.  The goal of a xetra
             berserker is to become the Fury.

   SPELLS:   Two in Berserk mode.  30% chance of 50 hit_player 
   SPECIAL:  heal, might, berserk, fury, block, hunt, peace resistance

   Heal:     Use a treasure crystal to heal damage.  Low chance. 
   Might:    Use a treasure crystal to increase weapon class.  Low chance.
   Berserk:  This creature will not fight until it becomes berserk.  It will
             take damage until it drops below 600 health.  Then it will 
             immediately gain max health to 1200 and heal to full, increase
             its weapon class, and do additional attacks.
   Fury:     After berserk increases enough, creature will become Fury,
             increasing the chance of miltiple attacks, and having a chance
             to do fury special.  Special attacks all enemies in the room up
             to 15 attacks, divided randomly.
   Block:    This creature has a chance to stop its attacker from leaving the
             room, based on the player's attributes.
   Hunt:     This creature has a chance to hunt down its attacker by following
             in the direction the player ran.
   Peace:    This creature has a rating of how berserk it has become.  Any
             peace spell cast will lower this amount some, as opposed to 
             just stopping the fight.  It will never drop a Fury to berserk. 
*/

#pragma strict_types
#include "/players/llew/closed/ansi.h"
#include "/players/llew/Bcrystal/factions.h"

#define FURY_LEVEL 6
#define MAX_BERSERK 15

inherit "obj/monster";

/* Have we used a crystal to increase wc? */
int mighty;

/* Are we ready to kick ass? */
int berserk;

/* String to hold our old name during fury. */
string old_name;

/* Have we been "peaced" this round. */
int peacecast;

/* special attacks variables */
int special_attack_chance;
int special_attack_damage;

/* Variables for following a player. */
string follow_dir;

/* Declarations */
void berserker();
void go_berserk();
int prevent();
void follow_player();


void reset(int arg)
{
   ::reset(arg);
   if(arg) return;

   mighty = 0;
   berserk = 0;
   peacecast = 0;
   follow_dir = 0;

   set_name(RED + "Ragrissk Xetra" + NORM);
   set_alt_name("ragrissk");
   set_alias("berserker");
   set_short(RED + "Ragrissk Xetra" + NORM);
   set_race("xetra");
   set_long("   This dark red-skinned creature is humanoid with two immense arms and\n" +
            "two strong legs.  Thick skin over bulging muscles is laced with many scars.\n" +
            "Its eyes are wild and filled with anger.  The fingers on its hands end in\n" +
            "extremely sharp claws.\n");
   set_level(25);
   set_hp(650);
   set_wc(35);    
   /* Bonus because of extra attacks in berserk and fury.   */
   /* This should technically be MUCH higher, but it pushes */
   /* the experience up too high for my tastes.             */
   set_wc_bonus(6);
   set_ac(24);
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
   set_heal(8, 4);
   special_attack_chance = 30;
   special_attack_damage = 50;

   /* See heartbeat below for reason for bonus, two extra spell attack. */
   set_wc_bonus(query_wc_bonus() + (2 * (special_attack_chance * special_attack_damage / 200)));

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
         /* Check stealth and attack. Berserkers are not so bright. */
         if (this_player()->query_attrib("ste") < random(40) + 1)
         {

            say(query_name() + " notices " + this_player()->query_name() + " and attacks!\n");

            go_berserk();
            kill_ob = this_player();
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

void monster_died()
{
   /* Adjust the faction of the person I was trying to kill. */
   if (attacker_ob && attacker_ob->is_player())
      "/players/llew/Bcrystal/faction_tracker"->add_faction(attacker_ob->query_real_name(), 1);
}

/* Block most peace spells.  If they disconnect, too bad.  They were warned upon entering area. */
void stop_fight()
{
   if ((this_player() && this_player()->query_level() < 20 && !peacecast) || !berserk)
   {
      if (berserk == 0 || berserk == 1)
      {
         ::stop_fight();
         ::stop_fight();
         return;
      }

      if (berserk < FURY_LEVEL || berserk > FURY_LEVEL)
      {
         say (query_name() + " calms slightly.\n");
         berserk--;  
      }
      else if (berserk == FURY_LEVEL)
         say (query_name() + " will not calm down!\n");

      peacecast = 1;
      return;
   }

   ::stop_fight();
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
   /* Reset peace flag. */
   peacecast = 0;

   /* Extra special "spell" attacks. */
   if (berserk)
   {
      if (attacker_ob && present(attacker_ob, environment(this_object())))
      {
         /* Spell attack #1 */
         if (special_attack_chance > random(100)) 
         {
            say(query_name() + BOLD + " dances death with " + GRY + "Claw Storm" + NORM + "!\n");
            attacker_ob->hit_player(random(special_attack_damage), spell_type);
         }
         /* Spell attack #2 */
         if (special_attack_chance > random(100)) 
         {
            say(query_name() + BOLD + " loses control in a " + GRY + "Blood Maelstrom" + NORM + "!\n");
            attacker_ob->hit_player(random(special_attack_damage), spell_type);
         }
      }
   }



   /* Use a crystal for various purposes. */
   if (present("BC_money_crystal") && !berserk)
   {
      if (attacker_ob)
      {
         /* Should we use a crystal for might? */
         if (!random(15) && !mighty)
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
/*            set_wc_bonus(query_wc_bonus() + (-mighty + (mighty * hit_point / max_hp)));
 *
 *  Taken out because this only happens before berserk,
 *  therefore, we'll soon be at full health again.
 */

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


   /* Process Berserk stuff. */
   berserker();

   /* If we're not berserk, we don't want to fight anyone. */
   if (!berserk && attacker_ob)
      return;

   /* Call the normal heartbeat. */
   ::heart_beat();
}

void berserker()
{ 
   /* If we are FURY, then maybe perform the fury attack. */
   if (berserk >= FURY_LEVEL && !random(15) && attacker_ob)
   {
      object *targets, *targets2;
      object *room_inv;
      int i, target_count;

      room_inv = all_inventory(environment());
      targets = ({});
      targets2 = ({});
      target_count = berserk;

      /* Make a list of enemies in the room. */
      for (i = 0; i < sizeof(room_inv); i++)
      {
         if ((object)room_inv[i]->query_attack() == this_object() && room_inv[i] != this_object())
            targets += ({ room_inv[i] });
      }


      if (sizeof(targets))
      {
         /* Make an attack list. */
         while (target_count > 0)
         {
            targets2 += ({ targets[random(sizeof(targets))] });
            target_count--;
         }

         say (query_name() + BOLD + " unleashes all its " + RED + "RAGE " + NORM + BOLD + " with " + GRY + "Death Frenzy" + NORM + BOLD + "!!!\n" + HIR);
         say(GRY+".."+NORM+"**"+NORM+BOLD+"/ "+NORM+RED+"-"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"- -- "+BOLD+"-"+NORM+RED);
         say(" -- -"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- "+NORM+BOLD+"\\"+NORM+"**"+GRY+"..\n\n"+NORM);

         /* Attack stuff. */
         for (i = 0; i < sizeof(targets2); i++)
         {
            if (targets2[i] && !targets2[i]->query_ghost())
            {
               already_fight = 0;
               attack_object(targets2[i]);
            }
         }
         say(GRY+".."+NORM+"**"+NORM+BOLD+"/ "+NORM+RED+"-"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"- -- "+BOLD+"-"+NORM+RED);
         say(" -- -"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- "+NORM+BOLD+"\\"+NORM+"**"+GRY+"..\n\n"+NORM);
      }

      /* Reset berserk to min. */
      berserk = 1; 
      set_name(old_name);
      set_short(old_name);
      
      /* Don't do anymore berserky stuff this round.  We're spent. */
      return;   
   }

   /* Test for going into berserk. */
   if (!berserk && attacker_ob)
   {
      if (hit_point < 600)
      {
         go_berserk();
         say(query_name() + BOLD + " charges into combat!\n" + NORM);
      }
      else
      {
         if (!random(4))
         {
            string *rand_say;
            rand_say = ({ query_name() + " grins grotesquely at " + attacker_ob->query_name() + ".\n",
                          "Blood drips from the new wounds on " + query_name() + ".\n",
                          query_name() + " laughs.\n",
                          query_name() + " feeds on the aggression.\n",
                          query_name() + "'s breathing increases rapidly.\n",
                       });
            say (rand_say[random(sizeof(rand_say))]);
         }
      }   
   }

   /* Increase berserk status*/
   if (berserk && random(10) < 3 && attacker_ob)
   {
      string *berserk_say;
      berserk_say = ({ HIR + "*" + NORM + RED + "=" + GRY + "- " + NORM + query_name() + BOLD +
                          " roars in anger! " + GRY + "-" + NORM + RED + "=" + BOLD + "*\n" + NORM,
                       HIR + "*" + NORM + RED + "=" + GRY + "- " + NORM + query_name() + BOLD +
                          " froths and fumes!" + GRY + "-" + NORM + RED + "=" + BOLD + "*\n" + NORM,
                       HIR + "*" + NORM + RED + "=" + GRY + "- " + NORM + query_name() + BOLD +
                          " rampages maniacally!" + GRY + "-" + NORM + RED + "=" + BOLD + "*\n" + NORM,
                       HIR + "*" + NORM + RED + "=" + GRY + "- " + NORM + query_name() + BOLD +
                          " is enranged beyond reckoning!" + GRY + "-" + NORM + RED + "=" + BOLD + "*\n" + NORM,
                     });

      
      if (berserk < MAX_BERSERK)
      {
         berserk++;
         if (berserk > FURY_LEVEL)
            say (query_name() + BOLD + " grows from the power of " + GRY + "Devastation" + NORM + BOLD + "!\n" + NORM);
         else if (berserk == FURY_LEVEL)
         {
            say(GRY+".."+NORM+"**"+NORM+BOLD+"/ "+NORM+RED+"-"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"- -- "+BOLD+"-"+NORM+RED);
            say(" -- -"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- "+NORM+BOLD+"\\"+NORM+"**"+GRY+"..\n\n"+NORM);
            say("              " + query_name() + " is suffused in "+HIR+"red"+NORM+" light.\n");
            say("           " + query_name() + " is "+BOLD+"F U R Y"+NORM+" Incarnate!\n\n");
            say(GRY+".."+NORM+"**"+NORM+BOLD+"\\ "+NORM+RED+"-"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"- -- "+BOLD+"-"+NORM+RED);
            say(" -- -"+BOLD+"-"+NORM+RED+"- -"+BOLD+"--"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"-"+BOLD+"-"+NORM+RED+"- -"+BOLD+"-"+NORM+RED+"--"+BOLD+"-"+NORM+RED+"- "+NORM+BOLD+"/"+NORM+"**"+GRY+"..\n"+NORM);

            old_name = (string)query_name();
            set_name(BOLD+"F U R Y"+NORM+ RED + " Incarnate" + NORM);
            set_short(query_name());
         }
         else if (berserk < FURY_LEVEL)
            say (berserk_say[berserk - 2]);
      }
   }

   /* Do extra hits based on berserk status */
   if (berserk && attacker_ob)
   {
      int x, maxhits;
      maxhits = ((berserk > FURY_LEVEL) ? FURY_LEVEL : berserk);
      
      for (x = 0; x < maxhits; x++)
      {
         if (!random(6) || (berserk >= FURY_LEVEL && !random(4)))
         {
            already_fight = 0;
            attack();
         }
         already_fight = 0;
      }
   }
}

void go_berserk()
{
   if (berserk) return;

   /* Going Berserk */
   set_hp(1200);
   set_wc(query_wc() + 12 + random(5));
   berserk = 1;
}


