
#include "security.h"
#define ALIGN_EXP_DIVISOR               1800
#define WA_FACTOR           3
#define EXP_DIVISOR                     190
#define INTERVAL_BETWEEN_HEALING        9
#define WEAPON_CLASS_OF_HANDS           (3)
#define ARMOUR_CLASS_OF_BARE            0
#define KILL_NEUTRAL_ALIGNMENT          10
#define ADJ_ALIGNMENT(al)               ((-al - KILL_NEUTRAL_ALIGNMENT)/4)
#define MAX_LIST                        20
#define NAME_OF_GHOST                   "some mist"

/*
 * Include this file in objects that "lives".
 * The following variables are defined here:
 *
 */

int time_to_heal;       /* Count down variable. */
int hcnum;
int crime; /* have we been bad.  players */
static int crimetime;
int money;              /* Amount of money on player. */
int luck,lucky;
string name;            /* Name of object. */
static int already_fight;
     /* see if more than one attack per hb, method like that made by shadowhawk.*/
static int asf,vsf,rsf;
static int dieing; /* are we in the death sequence? */
static int runc; /* count how many times we try to run. after 3 goto random */
string gender;
string msgin, msgout;   /* Messages when entering or leaving a room. */
int is_npc, brief;      /* Flags. */
int level;              /* Level of monster. */
int armor_class;        /* What armor class of monster. */
int hit_point;          /* Number of hit points of monster. */
int max_hp;
int experience;         /* Experience points of monster. */
string mmsgout;         /* Message when leaving magically. */
string mmsgin;          /* Message when arriving magically. */
object attacker_ob;     /* Name of player attacking us. */
object h_check; /* for multiple hit_player calls in one round. */
object alt_attacker_ob; /* Name of other player also attacking us. */
int weapon_class;       /* How good weapon. Used to calculate damage. */
object name_of_weapon;  /* To see if we are wielding a weapon. */
object head_armor;      /* What armor we have. */
int ghost;              /* Used for monsters that can leave a ghost. */
int dead;
string whimpy_dir;
int local_weight;       /* weight of items */
object hunted, hunter;  /* used in the hunt mode */
int hunting_time;       /* How long we will stay in hunting mode. */
string cap_name;        /* Capital version of "name". */
int spell_points;       /* Current spell points. Same max as max_hp. */
int max_spell; /* for arrrib -Bp */
string spell_name;
int spell_cost, spell_dam;
int age;                /* Number of heart beats of this character. */
int is_invis;           /* True when player is invisible */
int frog;               /* If the player is a frog */
int whimpy;             /* Automatically run when low on HP */
static int no_exp_value;      /*flag for test monsters not to give exp.*/
string auto_load;       /* Special automatically loaded objects. */
string current_room;    /* Name of current room. */
static object mounted; /*what we may be riding, horse, etc */
static string omsgin, omsgout; /* used for mounted */
static string *armors;
static object *weapons;

/*
 * All characters have an aligment, depending on how good or chaotic
 * they are.
 * This value is updated when killing other players.
 */
int alignment;

/*
 * The following routines are defined for usage:
 * hit_player           Called when fighting.
 * transfer_all_to:     Transfer all objects to dest.
 * move_player:         Called by the object that moves the monster.
 * query_name:          Gives the name to external objects.
 * query_real_name:     Give the uncapitalized name, even if invisible.
 * attacked_by          Tells us who are attacking us.
 * show_stats           Dump local status.
 * stop_wielding        Called when we drop a weapon.
 * stop_wearing         Called when we drop an armor.
 * query_hp             Query the number of hit points we have
 * query_level          Give our level to external objects.
 * query_value          Always return 0. Can't sell this object.
 * query_npc            Return 1 if npc otherwise 0.
 * get                  Always return 0. Can't take this object.
 * attack               Should be called from heart_beat. Will maintain attack.
 * query_attack
 * drop_all_money       Used when the object dies.
 * wield                Called by weapons.
 * wear                 Called by armor.
 * add_weight           Used when picking up things.
 * heal_self            Enable wizards to heal this object.
 * can_put_and_get      Can look at inventory, but not take things from it.
 * attack_object        Called when starting to attack an object.
 * test_if_any_here     For monsters. Call this one if you suspect no enemy
 *                      is here any more. This will be checked, and the
 *                      heart beat turned off in that case.
 *                      Return 1 if anyone there, 0 if none.
 * force_us             Force us to do a command.
 */


/* 
 * Additions for Paladins
 * A couple off functions for handling offwielded weapons
 */

static object second_weapon;
static second_wc;
static object paladin_shield; 

stop_offwielding() {
   if(!second_weapon) {
     log_file("offwield_bug", "Weapon not offwielded!\n");
     write("Bug! The weapon was marked as offwielded! (fixed)\n");
     return;
   }
   call_other(second_weapon, "un_wield", dead);
   second_weapon = 0;
   second_wc = 0;
}

offwield(w) {
   if(second_weapon)
     stop_offwielding();
   second_weapon = w;
   second_wc = call_other(w, "weapon_class", 0);
   say(cap_name+" offwields "+call_other(w,"query_name",0)+".\n");
   write("Ok.\n");
}

/* END PALADIN ADDITIONS */


/*
 * This routine is called from objects that moves the player.
 * Special: direction "X" means teleport.
 */
move_player(dir_dest)
{
  string dir, dest;
  object ob;
  int is_light;
  
  if(!dir_dest)
    return 0;

  if (sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
    tell_object(this_object(), "Move to bad dir/dest\n");
    return;
  }
  current_room = dest;
  hunting_time -= 1;
  if (hunting_time == 0) {
    if (hunter)
      call_other(hunter, "stop_hunter");
    hunter = 0;
    hunted = 0;
  }
  if (attacker_ob && present(attacker_ob)) {
    hunting_time = 10;
    tell_object(this_object(), "You are now hunted by " +
		call_other(attacker_ob, "query_name", 0) + ".\n");
    hunter = attacker_ob;
  }
  if (!msgout)
    msgout = "leaves";
  is_light = set_light(0);
  if (is_light < 0)
    is_light = 0;
  if (ghost)
    say(NAME_OF_GHOST + " " + msgout + " " + dir + ".\n");
  else if (dir == "X" && query_invis() < INVIS_TELEPORT)
    say(cap_name + " " + mmsgout + ".\n");
  else if (query_invis() < NO_MOVE && is_light && !present("silent_move_object"))
    say(cap_name + " " + msgout + " " + dir + ".\n");
  move_object(this_object(), dest);
  is_light = set_light(0);
  if (is_light < 0)
    is_light = 0;
  if (level >= 20)
    tell_object(this_object(), dest + "\n");
  if (!msgin)
    msgin = "arrives";
  if(ghost && is_light)
    say(NAME_OF_GHOST + " " + msgin + ".\n");
  else if (query_invis() < INVIS_TELEPORT && dir == "X")
    say(cap_name + " " + mmsgin + ".\n");

  else if (query_invis() < NO_MOVE && is_light && !present("silent_move_object"))
    say(cap_name + " " + msgin + ".\n");
  if (hunted && present(hunted))
    attack_object(hunted);
  if (hunter && present(hunter))
    call_other(hunter, "attack_object", this_object());
  if (is_npc)
    return;
  if (!is_light && !present("dark_sight_object", this_object())) {
    write("A dark room.\n");
    return;
  }
  ob = environment(this_object());
  if (brief) {
    write(call_other(ob, "short", 0)); 
    write(".\n"); /* killed '+' --Wulkwa */
  } else
    call_other(ob, "long", 0);
  ob = first_inventory(ob);
  while(ob) {
    if (ob != this_object()) {
      string short_str;
      short_str = call_other(ob, "short");
      if (short_str)
	write(short_str + ".\n");
    }
    ob = next_inventory(ob);
  }
}


/* 2/2/2000
 * This function is now used as a conversion for existing format into
 * the new format.  New files can still make direct calls to hit_player()
 * but it is more limited in its usage.  
 */

hit_player(dam1, type1, dam2, type2){
   return do_damage(({dam1,dam2}),({type1,type2}));
}


mapping Armors;

RegisterArmor(object gear, mixed *params){
   if(Armors == 0){ Armors = ([ ]); }
   Armors[gear] = params;
}

RemoveArmor(object gear){
   if(Armors == 0){ Armors = ([ ]); }
   if(!Armors[gear]) return 0;
   Armors[gear] = 0;
   return 1;
}

mapping Weapons;

RegisterWeapon(object gear, mixed *params){
   if(Weapons == 0){ Weapons = ([ ]); }
   Weapons[gear] = params;
}

RemoveWeapon(object gear){
   if(Weapons == 0){ Weapons = ([ ]); }
   Weapons[gear] = 0;
}

/* 2/2/2000
 * This function is called from another living object to give this 
 * object some damage.  This function will return how much damage
 * was received.  
 * This function has been modified to support multiple damage types
 * and resistances to damage.  There are 3 basic types supported.
 * "physical", "magical", and "other".  Other is not really a damage
 * type, but rather a main category that MUST be accomonied by a 
 * sub category.  For example fire damage would be written as
 * "other|fire", with the "|" separator MUST be inserted.
 */

do_damage(int *damage, string *method){
   
   int i, j, k;
   string type;
   int dam, total, class, res, temp, itemp;
   string cat,subcat;
   mixed *armors2;
   object *armors;


   if(dieing) {
      if(dieing < 8) return 0;
      dieing +=1;
   }

   /* if we are in the death sequence do not allow access to hit_player() */
   if(!is_npc)
      if(!this_object()->query_interactive()) {
         say(cap_name+" is disconnected.\n");
         stop_fight(); 
         if(this_player()) 
            this_player()->stop_fight();
         return 0;
      }

   if (this_player() && this_player() != this_object() && this_player()->query_level() < EXPLORE) {
      /* -= Protection =- */  
      if ( this_player()->is_player() &&
         this_player()->query_attack() != this_object() &&
         !this_player()->valid_attack( this_object())){
         /* bad attack, could be logged */
         write( "Your attack fails.\n");
         return 0;
      }
      if(this_object()->is_player() && !is_npc && !this_object()->query_interactive())
         return 0;
      if ( attacker_ob == alt_attacker_ob || !alt_attacker_ob)
         attacked_by( this_player());

      /* -= Crime =- */
      if ( this_player()->query_level() < EXPLORE &&
         (!is_npc || this_object()->crime_to_attack()))
        if(!this_object()->query_crime() && !this_player()->query_crime())
           this_player()->set_crime();
   }
   if (level >= 21 && !is_npc)   /* You can't hit a wizard ! */
      return 0;
   if(ghost == 1) return 0;      /* You cannot hit the dead! */


   /***********************************/
   /*  BEGIN ADDITIONS FOR MULTIPLE   */
   /*  TYPES OF DEFENSE               */
   /*  Coded by Beck                  */
   /***********************************/
   if(!damage) return 0;
   for(i=0; i<sizeof(damage); i++){
      if(damage[i]){
         dam = damage[i];
         class = 0;
         res = 0;
         if(method){
            if(method[i]){
               type = method[i];
               if(sscanf(type, "%s|%s",cat,subcat) !=2){
                  if(type != "physical" && type != "magical") type = "physical";
               }
               else if(cat != "other") type = "physical";
            }
            else type = "physical";
         }
         else type = "physical";
         /* Add in individual object modifications from mapping Objects */
         if(Armors){
            armors = keys(Armors);
            for(k=0; k<sizeof(armors); k++){
               if(Armors[armors[k]]){
                  armors2 = Armors[armors[k]];
                  itemp = member_array(type,armors2);
                  if(itemp != -1){
                     class += armors2[itemp+1];
                     res += armors2[itemp+2];
                     if(armors2[itemp+3]){
                        temp = (int) call_other(armors[k],armors2[itemp+3], this_object());
                        res += temp/100;
                        class += temp - ((temp/100)*100);  
                     }
                  }     
               }
            }
         }
         else if(armor_class && this_object()->is_npc())
            class = armor_class;


         if(res > 100) res = 100;

         /* Calculate new damage */
         res = 100 - res;
         dam = res*dam;
         dam = dam/100;
         if(this_player()){
            if(this_player()->query_level() > 19){
               write("Class: "+class+" Res: "+(100-res)+"\n");
            }
         }
         dam -= random(class + 1);
         total += dam;  
      }
   }
   
   /***********************************/
   /*  END OF ADDITIONS FOR MULTIPLE  */
   /*  TYPES OF DEFENSE               */
   /*  Coded by Beck                  */
   /***********************************/


   lucky = random(500);
   if(is_npc) luck = 0;
   if (lucky < luck) {
      tell_object(this_object(), "Your luck comes through for you.\n");
      if (luck < 12)
         total = total/2;
      if (luck > 11 && luck <16)
         total = total/3;
      if (luck > 15)
         total = total/5;
   }
   if (lucky > 494){
      total = total*5/3;
      if(attacker_ob)
         tell_object(this_object(), attacker_ob->query_name() + " hits you with a crushing blow.\n");
   }
   if(attacker_ob){
      if (attacker_ob->is_player() && attacker_ob->query_level() < 21 && attacker_ob != this_object()){
            if(total > 56) total = 56;
      }
   }

   if(this_object()->query_guild_name() == "Predator") /* high pain threshold [verte] */
   {
     int repulsed_damage;
     total -= (repulsed_damage=random((total * 50) / 1000));
     tell_object(this_object(), " <*> Predator living.c Defense Bonus: " + repulsed_damage + " <*>\n");
   }
   if(hit_point < 0 && total <= 0) total = 1;

   if(hit_point < 0) hit_point = 0;

   if (total <= 0)
      return 0;

   if (total > hit_point + 1)
      total = hit_point + 1;
   hit_point = hit_point - total;

   if (hit_point < 0) {
      death();
   }
   if(this_player()){
      if(this_player()->query_level() > 19){
         write("Damage: "+total+"\n");
      }
   }
    if(this_object())
   if(present("damage_report_object", this_object()))
     present("damage_report_object", this_object())->report_damage(total, previous_object());
   return total;
}
 

/* 2/2/2000
 * Death Function.  Separated for clarity.  Identical to old death sequence.
 * Spar/PK stuff fixed/added by Vertebraker [7.10.01]
 * New PK Code in testing [3.13.02]
 */
death()
{
    status s_flag, PKFlag;
    object corpse, e;

    /* We died ! */

    dieing = 1;

    if (hunter)
       hunter->stop_hunter();

    hunter = 0;
    hunted = 0;

    say(cap_name + " died.\n");

    if((e = environment()) && e->query_spar_area() && !is_npc) s_flag = 1;
    if(s_flag && (int)environment()->player_spar_only()) {
      if(!test_if_any_monsters_attacking()) s_flag = 1;
      else s_flag = 0;
    }

   if(attacker_ob)
     if(environment()) /* this better happen ! */
     {
       object kc, a;

       if(!alt_attacker_ob)
       {
         if(kc = present("kill_check_object", attacker_ob))
           kc->kill_check(this_object());
       }
       else
       {
        
         a = first_inventory(environment());
         while(a)
         {
           if((object)a->query_attack() == this_object() &&
             (kc = present("kill_check_object", a)) &&
             a != this_object())
           while(kc)
           {
             if((status)kc->id("kill_check_object"))
                kc->kill_check(this_object());
             if(kc)
               kc = next_inventory(kc);
           }

           if(a) a = next_inventory(a);
         }
       }
     }

   /* If this is a player, log the death for future reference */
    if(!is_npc && s_flag)
      log_file("DEATHS","Spar-> ");

    if(!is_npc)
    {
      if(attacker_ob)
      {
        log_file("DEATHS", ctime(time()) + " " + name + " " + experience +
          " exp " + money + " gold killed by " +
          attacker_ob->query_real_name() + ".\n");

        if(attacker_ob->is_player())
           log_file((s_flag ? "SPAR" : "PK"), 
             ctime(time()) + " " + name + " " + experience + 
             " exp " + money + " gold killed by " +
             attacker_ob->query_real_name() + ".\n");
      } 

      else
      {
        log_file("DEATHS", 
          ctime(time()) + "  " + name + " " + experience + " exp " + 
          money + " gold - killer unknown.\n");
        if(this_player())
        {
          log_file("DEATHS","this_player is " + 
            this_player()->query_real_name() + 
            "   " + this_player()->query_name() + "\n");
        }
      }
        
      tell_object(this_object(), "\n\n\
You feel very weak as your badly damaged body falls \
to the ground to die.\n");

        if((int)this_object()->query_pl_k() == 1)
        {
          status hmm;
          if(!test_if_any_monsters_attacking()) { s_flag = 1; PKFlag = 1; }
        }

      if(!s_flag)

      {
        int newexp;
        newexp = call_other("room/adv_guild", "check_exp", experience, -2);

        if(this_object()->query_extra_level() > 2)
         newexp = call_other("room/exlv_guild", "check_exp", experience,-3);

        experience = (experience * 3) / 4;  /* Take away 1/4 of exp. */

        if(newexp > experience)
          experience = newexp;
        
        this_object()->clear_crime();
        lower_attrib();

      }
      this_object()->rm_pk();
    }

    if(max_hp)
      hit_point = max_hp/3;
    else
     hit_point = 10;

    corpse = clone_object("obj/corpse");
    corpse->set_name(name);
    if(!s_flag) corpse->set_level(level);
    else corpse->set_level(1);

    if(!is_npc)
    { 
      set_ghost(1);
      move_object(corpse, e); 
      set_ghost(0);
    }
   
    if(!attacker_ob)
      attacker_ob = alt_attacker_ob;
    if(!is_npc)
    {
      see_if_other(3); /* prevent cheating */
      this_object()->save_me();
    }

    /* Note that you get no experience for killing other players! */
    /* that last line was not true before.. it is now. */

    else if(attacker_ob && is_npc)
    {
      int exp_worth, align_diff, exp_bonus;
      object party;

      exp_worth = this_object()->calculate_worth();
      call_other(attacker_ob, "add_alignment", ADJ_ALIGNMENT(alignment));

      /* Give some more experience for staying in your alignment */
      align_diff = alignment - attacker_ob->query_alignment();

      /* Never more than 20 percent */
      align_diff /= 200;
      
      /* Get absolute value */
      if (align_diff < 0) 
         align_diff = -align_diff; 
      exp_bonus = align_diff * exp_worth / 100;

      /* Never more than 1000 */
      if(exp_bonus > 1000) 
        exp_bonus = 1000;
      
      exp_worth += exp_bonus;

      party = present("party object", attacker_ob);
      if(!no_exp_value)
      {
        if(party) 
          party->share_exp(exp_worth);
        else 
          attacker_ob->add_exp(exp_worth);
      }
    }

    if(PKFlag)
    {
       object ab, bc, bx;
      bx=clone_object("/obj/pkbox");
      this_object()->set_pk_gh_cnt(180);
      bx->set_owner(name);
      move_object(bx, environment());
      ab = first_inventory(this_object());
      while(ab)
      {
        bc = next_inventory(ab);
        if((status)ab->query_worn() || (status)ab->query_wielded())
        {
          if(!ab->drop())
            move_object(ab, bx);
        }
        ab=bc;
      }
    }

    if(corpse)
      transfer_all_to(corpse);
 
    if(!is_npc)
    {
      see_if_other(3); /* prevent cheating */
      this_object()->save_me();
    }

    move_object(corpse, e);
    dieing = 0;

    if(!this_object()->second_life())
      if(this_object()->query_guild_name() != "shardak")
        destruct(this_object());
}




/*
 * This function is called from other players when they want to make
 * damage to us. We return how much damage we received, which will
 * change the attackers score. This routine is probably called from
 * heart_beat() from another player.
 */


hit_player_old(dam,zap) {
 int i,dam2,ac_tmp;
 object pro_object;   /* paladin weapon pro & combat method object */
 object templar_ob; /*templar object*/
 if(dieing) {
   if(dieing < 8) return 0;
   dieing +=1;
 }
  /* if we are in the death sequence do not allow access to hit_player() */
 if(!is_npc)
   if(!this_object()->query_interactive()) {
     say(cap_name+" is disconnected.\n");
     stop_fight(); if(this_player()) this_player()->stop_fight();
     return 0;
   }
 if (this_player() && this_player() != this_object() && this_player()->query_level() < EXPLORE) {
    /* -= Protection =- */  
    if ( this_player()->is_player() &&
         this_player()->query_attack() != this_object() &&
         !this_player()->valid_attack( this_object()))
    { /* bad attack, could be logged */
      write( "Your attack fails.\n");
      return 0;
    }
    if(this_object()->is_player() &&
       !is_npc && !this_object()->query_interactive())
       return 0;
    if ( attacker_ob == alt_attacker_ob || !alt_attacker_ob)
      attacked_by( this_player());
    /* -= Crime =- */
    if ( this_player()->query_level() < EXPLORE &&
         (!is_npc || this_object()->crime_to_attack()))
     if(!this_object()->query_crime() && !this_player()->query_crime())
      this_player()->set_crime();
  }
  if (level >= 21 && !is_npc)   /* You can't hit a wizard ! */
    return 0;
  if(ghost == 1) return 0; /* You cannot hit the dead! */
/* Feldegast's armor_special 11/12/98 */
  ac_tmp=armor_class;

  if(head_armor)
    ac_tmp+=head_armor->call_armor_special(this_object());

  if (!is_npc && armor_class > 9) {
    int rz;
    ac_tmp = 9;
    rz = random(armor_class-9);
    ac_tmp += rz;
   }
/*
  if (!is_npc && armor_class > 9) {
    ac_tmp = 9;
   } else {
   ac_tmp = armor_class;
   }
*/
    if(!is_npc && this_object()->query_pregnancy()){
     i = age - this_object()->query_pregnancy();
     i = i/5000;
     ac_tmp = ac_tmp - i;
    }
 dam2 = dam;
/************************************/
/*    BEGIN PALADIN ADDITIONS       */
/************************************/
/*
     if(!is_npc && this_object()->query_guild_name()=="paladin") {
*/
   pro_object = present("pro_object", this_object());
   if(pro_object && paladin_shield && pro_object->query_combat_method() == 2) {
     ac_tmp += call_other(paladin_shield, "shield_bonus", pro_object);
   }
/************************************/
/*     END PALADIN ADDITIONS        */
/************************************/
/***********************************/
/* START TEMPLAR ADD              */
/**********************************/
  if(!is_npc && this_object()->query_guild_name()=="Knights Templar") {
    templar_ob = present("KnightTemplar", this_object());
    if(templar_ob)
      ac_tmp += templar_ob->skill_check_def();
     }
/***********************************/
/*  END TEMPLAR ADD                */
/***********************************/
  dam -= random(ac_tmp + 1);
  lucky = random(500);
  if(is_npc) luck = 0;
  if (lucky < luck) {
    tell_object(this_object(), "Your luck comes through for you.\n");
    if (luck < 12)
       dam = dam/2;
    if (luck > 11 && luck <16)
       dam = dam/3;
    if (luck > 15)
       dam = dam/5;
  }
   if (lucky > 494)
    {
	 dam = dam2*5/3;
      if(attacker_ob)
      tell_object(this_object(), attacker_ob->query_name() + " hits you with a crushing blow.\n");
      }
  if(hit_point<0 && dam <=0) dam = 1;
  if(hit_point<0) hit_point = 0;
  if (dam <= 0)
    return 0;
/* PUT a cap on damage a player can do in one hit. */
   if(!zap) zap = attacker_ob;
   if(attacker_ob && zap && zap->query_level() < EXPLORE){
      if (is_npc && dam > 50 && attacker_ob->query_level() < EXPLORE){
         if (attacker_ob->is_player()){
            if(dam > 56) dam=56;
   }}}
/* penalize multiple calls to hit_player() by the same player in one hb */
  if(this_player() && is_npc) { 
        if(this_player()->query_level() > 99) write("DAMAGE = "+dam+" \n");
     if(h_check==this_player()) { hcnum += 1; 
        if(hcnum > 2) dam = dam/(hcnum+2);
        if(this_player()->query_level() > 99) write("DAMAGE REDUCED to "+dam+" hcnum="+hcnum+"\n");
     }}
  if (dam > hit_point+1)
    dam = hit_point+1;
  hit_point = hit_point - dam;
/*
    if(name=="numberone") say("DAMAGE TO HITPLAYER DONE="+dam+"\n");
*/
  if (hit_point<0) {
    object corpse;
    /* We died ! */
    dieing = 1;
    if (hunter)
      call_other(hunter, "stop_hunter");
    hunter = 0;
    hunted = 0;
    say(cap_name + " died.\n");
    /* If this is a player, log the death for future reference */
    if(!is_npc && environment(this_object())->query_spar_area())
      log_file("DEATHS","Spar-> ");
    if (!is_npc) 
      if (attacker_ob)
    log_file("DEATHS", ctime(time()) + " " + name + " " + experience + " exp " + money + " gold killed by " +
		 call_other(attacker_ob, "query_real_name", 0) + ".\n");
       else
           {
	log_file("DEATHS", ctime(time()) + "  " + name + " " + experience + " exp "+money + " gold - killer unknown.\n");
        if(this_player()) log_file("DEATHS","this_player is "+this_player()->query_real_name() +"   "+this_player()->query_name()+"\n");
           }
   if (!is_npc)
   {
tell_object(this_object(), "\n\nYou feel very weak as your badly damaged body falls to the ground to die.\n");
    if(!environment(this_object())->query_spar_area()) {
      int newexp;
      newexp = call_other("room/adv_guild", "check_exp", experience,-2);
      if(this_object()->query_extra_level() > 2)
        newexp = call_other("room/exlv_guild", "check_exp", experience,-3);
      experience = (experience * 3) / 4;  /* Take away 1/4 of exp. */
      if(newexp > experience) experience = newexp;
     lower_attrib();
    }
   call_other(this_object(), "clear_crime");
     call_other(this_object(),"rm_pk",0);
     }
    if (max_hp)
      hit_point = max_hp/3;
    else
      hit_point = 10;
    corpse = clone_object("obj/corpse");
    call_other(corpse, "set_name", name);
    call_other(corpse, "set_corpse_level", level);
    if(!is_npc) { set_ghost(1);
    move_object(corpse, environment(this_object())); }
    transfer_all_to(corpse);
    if(!is_npc) set_ghost(0);
    if (!attacker_ob)
      attacker_ob = alt_attacker_ob;
    if (!is_npc) {
    see_if_other(3); /* prevent cheating */
      this_object()->save_me();
/*
      attacker_ob = 0;
      alt_attacker_ob = 0;
 zero out attackers, hopefully will cure death bug.*/
    }
    /* The player killing us will update his alignment */
    /* and experience if he exists. */
    /* Note that you get no experience for killing other players! */
    /* that last line was not true before.. it is now. */
    else if(attacker_ob && is_npc) {
      int wa_bonus, exp_diff, exp_bonus, base_bonus;
       object party;
      call_other(attacker_ob, "add_alignment", ADJ_ALIGNMENT(alignment));
      /* Give some more experience for staying in your alignment
       * All the following basically works out to
       * exp_bonus = abs(monster's align - player's align)/75000 * exp;
       * Of course we can't just say that because of underflow problems.
       */
      if (is_npc && experience > 1000000) {
/*
      log_file("EXTRA_EXP", name + " " + creator(this_object()) + call_other(attacker_ob, "query_name",0) + "\n");
*/
	 experience = 1000000;
	  }
      exp_diff = (alignment - call_other(attacker_ob,"query_alignment",0));
      if (exp_diff < 0)
	exp_diff = -exp_diff;   /* Get absolute value */
      exp_diff /= 10;   /* Scale this down so we don't overflow! */
      exp_bonus = experience / 100;
      exp_bonus *= exp_diff;
      exp_bonus /= ALIGN_EXP_DIVISOR;
      /* Base bonus regardless of alignment is experience/75 */
      base_bonus = experience/EXP_DIVISOR;
      if(level < 5) base_bonus = experience/(EXP_DIVISOR/3);
      /* Don't let the alignment bonus exceed 1/2 the base bonus */
      if (exp_bonus > base_bonus/2)
	exp_bonus = base_bonus/2;
      exp_bonus += base_bonus;
      wa_bonus = weapon_class * armor_class * WA_FACTOR;
      if (wa_bonus > base_bonus/3)
	   wa_bonus = base_bonus/3;
       exp_bonus += wa_bonus;
       party=present("party object", attacker_ob);
/* Old party adjustment, removed jun 99 -Bp
       if(party) exp_bonus = 24*exp_bonus/30;
*/
       if(!no_exp_value) {
       if (party) party->share_exp(exp_bonus);
       if(!party)
       call_other(attacker_ob, "add_exp", exp_bonus);
       }
    }
    move_object(corpse, environment(this_object()));
    dieing = 0;
    if (!call_other(this_object(), "second_life", 0))
      destruct(this_object());
  }
   if(this_player()&& is_npc)h_check=this_player();
  return dam;
}



transfer_all_to(dest)
{
  object ob;
  object next_ob;

  if(!dest) return 0;
  ob = first_inventory(this_object());
  while(ob) {
    next_ob = next_inventory(ob);
    if (!call_other(ob, "drop", 1))
     if(ob)
      move_object(ob, dest);
    ob = next_ob;
  }
  local_weight = 0;
  if (money == 0)
    return;
  ob = clone_object("obj/money");
  call_other(ob, "set_money", money);
  move_object(ob, dest);
  money = 0;
}

query_name() {
  if (ghost)
    return NAME_OF_GHOST;
  return cap_name;
}

query_real_name() {
  return name;
}

query_alignment() {
  if(!is_npc) this_object()->add_alignment(0);
  return alignment;
}

query_npc() {
  return is_npc;
}
is_npc() { return is_npc; }

/*
 * This routine is called when we are attacked by a player.
 */
attacked_by(ob) {
  if (!attacker_ob) {
    attacker_ob = ob;
    set_heart_beat(1);
    return;
  }
/*
  if (!alt_attacker_ob) {
*/
  if (!alt_attacker_ob || alt_attacker_ob == attacker_ob) {
    alt_attacker_ob = ob;
    return;
  }
}


show_stats() {
   int i;
   int j;
   mixed *types;
   object *armors, *weapons;
   object yjy,yjyj;
    write(short() + "\nlevel: " + level + "\n");
    if (this_object()->is_player()) write("extra_level: "+this_object()->query_extra_level()+ "\n");
    if (call_other(this_object(), "is_player", 0) && call_other(this_object(), "query_level", 0) > 19) {
   write("earmuffs: ");
    if (call_other(this_object(), "query_muffled", 0))
       write("on");
    else
       write("off");
    write("\n");
    }
    if (query_invis())
	  write("invis: " + is_invis + "\n");
    write("coins: "+ money +
	  "\nmax: " + max_hp + "\n");
    if (call_other(this_player(), "query_level", 0) > STAT)
	  write("hp: " + hit_point + "\n");
    write("spell: " + spell_points + "\n");
    write("max spell: " + max_spell + "\n");
    write("experience: "+ experience + "\n");
/*    if(this_object()->is_npc()){ */
       if(Armors){
          write("Armor:\n");
          armors = keys(Armors);
          for(i=0;i<sizeof(armors);i++){
             if(Armors[armors[i]] != 0){
                write("   "+file_name(armors[i])+"\n");
                types = Armors[armors[i]];
                j = sizeof(types)/4;
                while(j){
                   write("      "+types[(4*j)-4]+" "+types[(4*j)-3]+" "+types[(4*j)-2]+" "+types[(4*j)-1]+"\n");
                   j -= 1;
                }
                write("\n");
            }
         }
      }
      if(Weapons){
         write("Weapons:\n");
          weapons = keys(Weapons);
          for(i=0;i<sizeof(weapons);i++){
             if(Weapons[weapons[i]] != 0){
                write("   "+file_name(weapons[i])+"\n");
                types = Weapons[weapons[i]];
                j = sizeof(types)/3;
                while(j){
                   write("      "+types[(3*j)-3]+" "+types[(3*j)-2]+" "+types[(3*j)-1]+"\n");
                   j -= 1;
                }
                write("\n");
            }
         }
      }
 /*   } */
    write("armor class: " + this_object()->query_ac());
    if (head_armor)
	write("\narmor: " + call_other(head_armor, "rec_short", 0));
    write("\nweapon class: \t"); write(weapon_class);
    if (name_of_weapon)
	write("\nweapon: " + call_other(name_of_weapon, "query_name", 0));
    write("\ncomposite: " + this_object()->query_composite()+"\n");

   if(this_object()->calculate_worth())
      write("Experience Value: "+this_object()->calculate_worth()+"\n");

   if (!is_npc) {
     write("\nintoxinated:  " + call_other(this_object(), "query_intoxination", 0));
    }
    write("\ncarry: \t" + local_weight);
    if (attacker_ob)
	write("\nattack:  " + call_other(attacker_ob, "query_name"));
    if (alt_attacker_ob)
	write("\nalt attack:  " + call_other(alt_attacker_ob, "query_name"));
    write("\nalign: \t" + alignment + "\n");
    write("gender: \t" + query_gender_string() + "\n");
    if(!is_npc && this_object()->query_pregnancy()){
     i = age - this_object()->query_pregnancy();
     write("pregnancy: "+i+" / 16200 \n");
    }
    if (i = call_other(this_object(), "query_quests", 0))
     {
	write("Quests: \t" + i + "\n");
     write("Quest Points: \t" + query_quest_point() +"\n");
    }
    show_age();
    yjy = environment(this_object());
    if(yjy)
    yjyj = environment(yjy);
    if(yjy)
    write("room: " + file_name(yjy) + "\n");
    if(yjyj) write("Room's room: "+file_name(yjyj) + "\n");
    if(!yjy)  write("room: No environment\n");
    write("this_object()=");
    write(this_object());
    write("\n");
    if(creator(this_object()))
  {
       write("Creator: ");
       write(capitalize(creator(this_object())));
	write ("\n");
    }
      if(call_other(this_object(), "is_player")) 
	write("crime: " + crime + "\n");
}

unwield(object w, int silently){
   int temp;
   temp = member_array(w, weapons);
   if(temp == -1)
      return 0;
   if(weapons[0] == weapons[1]){
      name_of_weapon = 0;
      weapons[0] = 0;
      weapons[1] = 0;
   }
   else {
      weapons[temp] = 0;
      if(temp == 0) name_of_weapon = 0;
      if(temp == 1) second_weapon = 0;
   }
   this_object()->RemoveWeapon(w);
   w->un_wield();
   if(!silently && this_player() == this_object()) 
      write("You unwield "+w->query_name()+"\n");
   return 1;
} 

stop_wielding_old() {
    if (!objectp(name_of_weapon)) {
        name_of_weapon = 0;
	/* This should not happen ! */
/*
	log_file("wield_bug", "Weapon not wielded !\n");
*/
/*     hmm..
	write("Bug ! The weapon was marked as wielded ! (fixed)\n");
*/
	return;
    }
    call_other(name_of_weapon, "un_wield", dead);
    name_of_weapon = 0;
    weapon_class = WEAPON_CLASS_OF_HANDS;
}

stop_wearing(object name, string type, silent) {
  /* For paladins.  Removes paladin_shield */
   if(name->query_paladin_shield())
      paladin_shield = 0;

   if(RemoveArmor(name))
      armors -= ({ type });
   if(!silent)
      say(cap_name + " removes "+ call_other(name, "query_name", 0) +".\n");
   write("Ok.\n");
}

query_armor(){  return armors; }
/*
stop_wearing(object name, string type, silent) {
   if(!head_armor) {
*/
      /* This should not happen ! */
/*
      write("This is a bug, no head_armor\n");
      return;
   }
*/
   /* For paladins.  Removes paladin_shield */
/*
   if(name->query_paladin_shield())
      paladin_shield = 0;
   
   if(RemoveArmor(name))
      armors -= ({ type });
   if(!silent)
      say(cap_name + " removes "+ call_other(name, "query_name", 0) +".\n");
   write("Ok.\n");
}
*/


stop_wearing_old(name,silent) {
    if(!head_armor) {
	/* This should not happen ! */
/*
	log_file("wearing_bug", "armor not worn!\n");
*/
	write("This is a bug, no head_armor\n");
	return;
    }
/* For paladins.  Removes paladin_shield */
   if(present(name, this_object())->query_paladin_shield())
     paladin_shield = 0;
    head_armor = call_other(head_armor, "remove_link", name);
    if(head_armor && objectp(head_armor))
	armor_class = call_other(head_armor, "tot_ac");
    else {
	armor_class = 0;
	head_armor = 0;
    }
    if (!is_npc)
        if(!dead && !silent)
	    say(cap_name + " removes " + name + ".\n");
    write("Ok.\n");
}

query_level() {
    string ab,bc;
     if(!is_npc){
    sscanf(file_name(this_object()), "%s#%s",ab,bc);
    if(ab!="obj/player")
     {
        illegal_patch("cloned player.c add_commands block");
	destruct(this_object());
	return;
    }
      }
  return level;
}

/* This object is not worth anything in the shop ! */
query_value() { return 0; }

/* It is never possible to pick up a player ! */
get() { return 0; }

/*
 * Return true if there still is a fight.
 */
attack()
{

  int i, j, temp, temp2, itemp;
   object *weapons; 
   mixed *weapons2;
   int *damage;
   string *type;

  int tmp;
  string mfight,thingone,thingtwo;
  int tmpk,pal_tmp,whit,weap_tmp;
  int knt_tmp,knt_tmp2;
  int intox_no;
  string name_alt_at;
  string name_of_attacker;
  object pro_object;     /* paladin object */
  object templar_ob;    /* templar object */
    object gen_ob;         /* generic object */
  pal_tmp = 0;
  knt_tmp = 0;
  knt_tmp2 = 0;
  if(is_npc) h_check = 0;
  hcnum = 1;
  if (!is_npc) {
     intox_no = call_other(this_object(), "query_intoxination", 0);
     if(intox_no > 0) {
        intox_no = 5 - ( (level + 4) / intox_no );
        if(intox_no < 0) intox_no = 0;
     }
  } 
  else
     intox_no = 0;
  
  if(alt_attacker_ob) {
     if(alt_attacker_ob->query_ghost())
     alt_attacker_ob = attacker_ob;
  }
  if (already_fight){
     return 0;
  }
  if (!attacker_ob) {
    spell_cost = 0;
    return 0;
  }

/* fight_are pk check */
   if(!is_npc && attacker_ob->is_player())
      if(!this_object()->query_pl_k() || !attacker_ob->query_pl_k())
         if(!this_object()->check_fight_area()){
            if(!attacker_ob->check_fight_area()) attacker_ob->clear_fight_area();
            attacker_ob =0;
            alt_attacker_ob=0;
            return 0;
         }
/* Stop fighting if one party is disconnected */
/* Stop player disconnected player from fighting */
   if (!is_npc && !call_other(this_object(), "query_interactive",0)){
      attacker_ob =0;
      return 0;
   }

/* stop monster from fighting disconnected player */
   if (is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
      stop_fight();

/* stop player from fighting disconnected player */
   if(!is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
      stop_fight();
   if (attacker_ob)
      name_of_attacker = call_other(attacker_ob, "query_name", 0);
   if ((!name_of_attacker) || 
      (name_of_attacker == NAME_OF_GHOST) ||
      (environment(attacker_ob) != environment(this_object()))) {
      if (!hunter && name_of_attacker &&
	 !call_other(attacker_ob, "query_ghost", 0)) {
	   tell_object(this_object(), "You are now hunting " +
	 call_other(attacker_ob, "query_name", 0) + ".\n");
	   hunted = attacker_ob;
	  hunting_time = 10;
      }
      attacker_ob = 0;
      if (!alt_attacker_ob)
         return 0;
      attacker_ob = alt_attacker_ob;
      alt_attacker_ob = 0;
      if (attack()) {
         tell_object(this_object(), "You turn to attack " +
		  call_other(attacker_ob, "query_name", 0) + ".\n");
         already_fight=1;
         return 1;
      }
      return 0;
   }
   call_other(attacker_ob, "attacked_by", this_object());





/*******************************
*
* NEW WEAPON CODE BY BECK
* FOR DAMAGE TYPES
*
*******************************/

   damage = ({});
   type = ({});

   if(Weapons){
      weapons = keys(Weapons);
      for(i=0; i<sizeof(Weapons); i++){
         if(Weapons[weapons[i]]){
            weapons2 = Weapons[weapons[i]];
            for(j=0; j<sizeof(weapons2); j++){
               temp = weapons2[j+1];
               if(weapons2[j+2]){
                  temp += call_other(weapons[i],weapons2[j+2], attacker_ob);
               }
               temp = random(temp);
               itemp = member_array(weapons2[j], type);
               if(itemp != -1){
                  damage[itemp] += temp;   
               }
               else {
                  type += ({ weapons2[j] });
                  damage += ({ temp });     
               }
               j = j + 2;
            }
         }
      }
   }

/*************************
* EXTRA PHYSICAL DAMAGE
*************************/

   itemp = member_array("physical", type);
   temp = 0;
   

/******************************/
/*  BEGIN PALADIN ADDITIONS   */
/******************************/
/*
     if(!is_npc && this_player()->query_guild_name()=="paladin") {
*/
   if(this_player())
      pro_object = present("pro_object", this_player());
   if(name_of_weapon) if(pro_object) if(name_of_weapon->query_pro_weapon()) {
     temp += call_other(name_of_weapon, "proficiency_hit", pro_object);
   }
   if(second_weapon && pro_object && pro_object->query_combat_method() == 3) {
     temp += call_other(second_weapon, "dual_hit", pro_object);
   }
/******************************/
/*   END PALADIN ADDITIONS    */
/******************************/
/******************************/
/*   TEMPLAR ADDITIONS        */
/******************************/
   if(this_player())
      if(!is_npc && this_player()->query_guild_name()=="Knights Templar") {
         templar_ob=present("KnightTemplar", this_player());
         if(name_of_weapon && templar_ob) {
            knt_tmp = templar_ob->skill_check(name_of_weapon);
            knt_tmp2 = 2*knt_tmp/3;
            knt_tmp = random(knt_tmp - knt_tmp2);
            temp += knt_tmp2;
         }
         if(mounted) {
            int mnt,mnt2;
            mnt = templar_ob->query_skill("horse");
            mnt2=random(mnt/2);

            temp += mnt2;
            if(name=="numberthree") write("mounted bonus ="+mnt2+">>>"+mnt+"\n");
         }
      }
/******************************/
/*   END TEMPLAR SECTION      */
/******************************/

/******************************/
/*   BEGIN GENERIC WC BONUS  ADDITIONS               */
/******************************/
  if((gen_ob = this_player()) && (gen_ob = present("generic_wc_bonus", gen_ob)))
    while(gen_ob)
    {
      object ob;
      ob = next_inventory(gen_ob);
      temp += (int)gen_ob->gen_wc_bonus();
      gen_ob = ob;
    }
/******************************/
/*   END GENERIC WC ADDITION  */
/******************************/


   temp -= intox_no;
   temp = random(temp);
   temp += knt_tmp;

   if(itemp != -1){
      damage[itemp] += temp;  
      weap_tmp = damage[itemp];   
   }
   else {
      type += ({ "physical" });
      damage += ({ temp });
      weap_tmp = temp;     
   }
   if(this_object()->is_kid() && weap_tmp > 15){
      itemp = member_array("physical", type);
      if(itemp != -1){
         damage[itemp] = 15;  
      }
   }


/********************************
*  END EXTRA PHYSICAL DAMAGE    *
********************************/

/********************************
* SPELLS
*
********************************/
   
   if (spell_cost) {
      if (level < 20) spell_points -= spell_cost;
      spell_cost = 0;
      if(!asf && !vsf && !rsf) {
         tell_object(attacker_ob, "You are hit by a " + spell_name + ".\n");
         write("You cast a " + spell_name + ".\n");
      }
      asf = 0; vsf = 0; rsf = 0;
      itemp = member_array("magical", type);
      if(itemp != -1){
         damage[itemp] += spell_dam;
      }
      else {
         type += ({ "magical" });
         damage += ({ spell_dam });     
      }
   }
/***************************
*         END SPELLS       *
****************************/

/***************************
*  EXTRA ATTACKS           *
***************************/

   if(alt_attacker_ob)
      if(!alt_attacker_ob->query_name()) alt_attacker_ob = attacker_ob;
      if(alt_attacker_ob && alt_attacker_ob != attacker_ob){
         if(present(alt_attacker_ob))
            hit_pet(weap_tmp,spell_dam);
      }

/***************************
*    END EXTRA ATTACK      *
***************************/

   if(attacker_ob){
      temp = (int)attacker_ob->do_damage( damage, type );
      tmp = temp;
   }


   else
      tmp = 0;
   if (this_object() && tmp == 0 && !present("no_msg_hit", this_object())) {
    tell_object(this_object(), "You missed.\n");
    checked_say(cap_name + " missed " + name_of_attacker + ".\n");
    spell_cost = 0;
    spell_dam = 0;
    already_fight = 1;
   if(!is_npc && second_weapon && pro_object &&
                 pro_object->query_combat_method() == 3)
     second_weapon->count_misses();
   if(!is_npc && name_of_weapon) {
    name_of_weapon->count_misses();
   if(name_of_weapon->query_wear() > 60)
  {
     if(!is_npc && random(4450000/name_of_weapon->query_wear()) < 10)
	name_of_weapon->weapon_breaks();
     }
    }
    return 1;
  }
  if(!is_npc && attacker_ob && !attacker_ob->query_no_exp_value())
  this_object()->add_exp(tmp);
  tmp -= spell_dam;
  spell_cost = 0;
  spell_dam = 0;


  /* Does the enemy still live ? */
  if (attacker_ob &&
      call_other(attacker_ob, "query_name", 0) != NAME_OF_GHOST) {

    string *mess;
    if(this_object())
    if(!present("no_msg_hit", this_object())) {
    if(name_of_weapon) mess = name_of_weapon->query_message_hit(tmp); 
    else mess = query_message_hit(tmp);
    if(!mess) mess = query_message_hit(tmp);
    if(this_object())
    tell_object(this_object(), "You " + mess[1] + " " + name_of_attacker +
                mess[0] + ".\n");
    if (query_invis() >= INVIS_ACTION)
    tell_object(attacker_ob, cap_name + " " + mess[1] + " you" + mess[0] +
          ".\n");
    checked_say(cap_name + " " + mess[1] + " " + name_of_attacker + mess[0] +
        ".\n");
   already_fight = 1;
   }
   if(!is_npc && second_weapon && pro_object &&
                 pro_object->query_combat_method() == 3)
     second_weapon->count_hit_made(pal_tmp);
   if(name_of_weapon && !is_npc) {
   name_of_weapon->count_hit_made(pal_tmp);
   if(!is_npc && name_of_weapon->query_wear() > 1)
   {
  if(!is_npc && random(4500000/name_of_weapon->query_wear()) < 10)
  name_of_weapon->weapon_breaks();
   }
   }
    return 1;
  }
  if(this_object())
  tell_object(this_object(), "You killed " + name_of_attacker + ".\n");
  attacker_ob = alt_attacker_ob;
  alt_attacker_ob = 0;
   already_fight = 1;
  if (attacker_ob)
    return 1;
}


attack_old()
{
  int tmp;
  string mfight,thingone,thingtwo;
  int tmpk,pal_tmp,whit,weap_tmp;
  int knt_tmp,knt_tmp2;
  int intox_no;
  string name_alt_at;
  string name_of_attacker;
  object pro_object;     /* paladin object */
  object templar_ob;    /* templar object */
    object gen_ob;         /* generic object */
  pal_tmp = 0;
  knt_tmp = 0;
  knt_tmp2 = 0;
  if(is_npc) h_check = 0;
  hcnum = 1;
  if (!is_npc) {
   intox_no = call_other(this_object(), "query_intoxination", 0);
   if(intox_no > 0) {
     intox_no = 5 - ( (level + 4) / intox_no );
     if(intox_no < 0) intox_no = 0;
   }
  } else
   intox_no = 0;
  
    if(alt_attacker_ob) {
    if(alt_attacker_ob->query_ghost())
     alt_attacker_ob = attacker_ob;
   }
    if (already_fight) 
{
       return 0;
 }
  if (!attacker_ob) {
    spell_cost = 0;
    return 0;
  }
/* fight_are pk check */
if(!is_npc && attacker_ob->is_player())
  if(!this_object()->query_pl_k() || !attacker_ob->query_pl_k())
  if(!this_object()->check_fight_area()){
  if(!attacker_ob->check_fight_area()) attacker_ob->clear_fight_area();
  attacker_ob =0;
  alt_attacker_ob=0;
  return 0;
}
 /* Stop fighting if one party is disconnected */
  /* Stop player disconnected player from fighting */
 if (!is_npc && !call_other(this_object(), "query_interactive",0))
{
    attacker_ob =0;
  return 0;
}
  /* stop monster from fighting disconnected player */
 if (is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
   stop_fight();
  /* stop player from fighting disconnected player */
if(!is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
  stop_fight();
  if (attacker_ob)
  name_of_attacker = call_other(attacker_ob, "query_name", 0);
  if ((!name_of_attacker) || 
      (name_of_attacker == NAME_OF_GHOST) ||
      (environment(attacker_ob) != environment(this_object()))) {
    if (!hunter && name_of_attacker &&
	!call_other(attacker_ob, "query_ghost", 0)) {
	  tell_object(this_object(), "You are now hunting " +
		      call_other(attacker_ob, "query_name", 0) + ".\n");
	  hunted = attacker_ob;
	  hunting_time = 10;
    }
    attacker_ob = 0;
    if (!alt_attacker_ob)
      return 0;
    attacker_ob = alt_attacker_ob;
    alt_attacker_ob = 0;
    if (attack()) {
      tell_object(this_object(), "You turn to attack " +
		  call_other(attacker_ob, "query_name", 0) + ".\n");
    already_fight=1;
      return 1;
    }
    return 0;
  }
  call_other(attacker_ob, "attacked_by", this_object());
  if (spell_cost) {
    if (level < 20) spell_points -= spell_cost;
    spell_cost = 0;
    if(!asf && !vsf && !rsf) {
    tell_object(attacker_ob, "You are hit by a " + spell_name + ".\n");
    write("You cast a " + spell_name + ".\n");
     }
    asf = 0; vsf = 0; rsf = 0;
  }
  if(name_of_weapon)
    whit = call_other(name_of_weapon,"hit",attacker_ob);
/* use weap_tmp as a weapon class limit as wizards dont listen.*/
    weap_tmp = weapon_class;
    if (!is_npc && this_object()->query_level() < 20 && weapon_class > 20) {
	  weap_tmp = 20;
     }
   if(whit) {
    weap_tmp = weap_tmp + whit;
  if(!is_npc && this_object()->query_level()<20 && 1*weap_tmp > 30)
   weap_tmp = 10 + random(12);
   if(!is_npc && this_object()->query_level() <20 && weap_tmp > 24){
	weap_tmp = 24;
     }
   if(this_object()->is_kid() && weap_tmp > 15) weap_tmp = 15;
   }
   pal_tmp=weap_tmp;
/******************************/
/*  BEGIN PALADIN ADDITIONS   */
/******************************/
/*
     if(!is_npc && this_player()->query_guild_name()=="paladin") {
*/
   if(this_player())
   pro_object = present("pro_object", this_player());
   if(name_of_weapon) if(pro_object) if(name_of_weapon->query_pro_weapon()) {
     weap_tmp += call_other(name_of_weapon, "proficiency_hit", pro_object);
   }
   if(second_weapon && pro_object && pro_object->query_combat_method() == 3) {
     weap_tmp += call_other(second_weapon, "dual_hit", pro_object);
   }
/******************************/
/*   END PALADIN ADDITIONS    */
/******************************/
/******************************/
/*   BEGIN GENERIC WC BONUS  ADDITIONS               */
/******************************/
  if((gen_ob = this_player()) && (gen_ob = present("generic_wc_bonus", gen_ob)))
    while(gen_ob)
    {
      object ob;
      ob = next_inventory(gen_ob);
      weap_tmp += (int)gen_ob->gen_wc_bonus();
      gen_ob = ob;
    }
/******************************/
/*   END GENERIC WC ADDITION  */
/******************************/
/******************************/
/*   TEMPLAR ADDITIONS        */
/******************************/
     if(this_player())
     if(!is_npc && this_player()->query_guild_name()=="Knights Templar") {
     templar_ob=present("KnightTemplar", this_player());
     if(name_of_weapon && templar_ob) {
       knt_tmp = templar_ob->skill_check(name_of_weapon);
       knt_tmp2 = 2*knt_tmp/3;
       knt_tmp = random(knt_tmp - knt_tmp2);
       weap_tmp += knt_tmp2;
     }
     if(mounted) {
       int mnt,mnt2;
       mnt = templar_ob->query_skill("horse");
       mnt2=random(mnt/2);
/*
       weap_tmp += random(mnt/2);
*/
       weap_tmp += mnt2;
       if(name=="numberthree") write("mounted bonus ="+mnt2+">>>"+mnt+"\n");
     }
     }
/******************************/
/*   END TEMPLAR SECTION      */
/******************************/
   if(alt_attacker_ob)
  if(!alt_attacker_ob->query_name()) alt_attacker_ob = attacker_ob;
  if(alt_attacker_ob && alt_attacker_ob != attacker_ob){
   if(whit != "miss")
     if(present(alt_attacker_ob))
   hit_pet(weap_tmp,spell_dam);
   }
  if(whit != "miss" && attacker_ob)
    tmp = call_other(attacker_ob, "hit_player", 
		     knt_tmp+random(weap_tmp - intox_no) + spell_dam);
  else
    tmp = 0;
  if (this_object() && tmp == 0 && !present("no_msg_hit", this_object())) {
    tell_object(this_object(), "You missed.\n");
    checked_say(cap_name + " missed " + name_of_attacker + ".\n");
    spell_cost = 0;
    spell_dam = 0;
    already_fight = 1;
   if(!is_npc && second_weapon && pro_object &&
                 pro_object->query_combat_method() == 3)
     second_weapon->count_misses();
   if(!is_npc && name_of_weapon) {
    name_of_weapon->count_misses();
   if(name_of_weapon->query_wear() > 60)
  {
     if(!is_npc && random(4450000/name_of_weapon->query_wear()) < 10)
	name_of_weapon->weapon_breaks();
     }
    }
    return 1;
  }
  if(!is_npc && attacker_ob && !attacker_ob->query_no_exp_value())
  this_object()->add_exp(tmp);
  tmp -= spell_dam;
  spell_cost = 0;
  spell_dam = 0;
  /* Does the enemy still live ? */
  if (attacker_ob &&
      call_other(attacker_ob, "query_name", 0) != NAME_OF_GHOST) {
/*
    string how, what;
    how = " to small fragments";
    what = "massacred";
    if (tmp < 30) {
      how = " with a bone crushing sound";
      what = "smashed";
    }
    if (tmp < 20) {
      how = " very hard";
      what = "hit";
    }
    if (tmp < 10) {
      how = " hard";
      what = "hit";
    }
    if (tmp < 5) {
      how = "";
      what = "hit";
    }
    if (tmp < 3) {
      how = "";
      what = "grazed";
    }
    if (tmp == 1) {
      how = " in the stomach";
      what = "tickled";
    }
    tell_object(this_object(), "You " + what + " " + name_of_attacker +
		how + ".\n");
    if (query_invis() >= INVIS_ACTION)
      tell_object(attacker_ob, cap_name + " " + what + " you" + how +
		  ".\n");
    checked_say(cap_name + " " + what + " " + name_of_attacker + how +
		".\n");
*/
    string *mess;
    if(this_object())
    if(!present("no_msg_hit", this_object())) {
    if(name_of_weapon) mess = name_of_weapon->query_message_hit(tmp); 
    else mess = query_message_hit(tmp);
    if(!mess) mess = query_message_hit(tmp);
    if(this_object())
    tell_object(this_object(), "You " + mess[1] + " " + name_of_attacker +
                mess[0] + ".\n");
    if (query_invis() >= INVIS_ACTION)
    tell_object(attacker_ob, cap_name + " " + mess[1] + " you" + mess[0] +
          ".\n");
    checked_say(cap_name + " " + mess[1] + " " + name_of_attacker + mess[0] +
        ".\n");
   already_fight = 1;
   }
   if(!is_npc && second_weapon && pro_object &&
                 pro_object->query_combat_method() == 3)
     second_weapon->count_hit_made(pal_tmp);
   if(name_of_weapon && !is_npc) {
   name_of_weapon->count_hit_made(pal_tmp);
   if(!is_npc && name_of_weapon->query_wear() > 1)
   {
  if(!is_npc && random(4500000/name_of_weapon->query_wear()) < 10)
  name_of_weapon->weapon_breaks();
   }
   }
    return 1;
  }
  if(this_object())
  tell_object(this_object(), "You killed " + name_of_attacker + ".\n");
  attacker_ob = alt_attacker_ob;
  alt_attacker_ob = 0;
   already_fight = 1;
  if (attacker_ob)
    return 1;
}
query_attack() {
  /* Changed by Herder */
  return attacker_ob;
  
  /* OLD
   * if (attacker_ob)
   * return 1;
   * return 0;
   */
}

drop_all_money(verbose) {
  object mon;
  int tmp;
  if (money == 0)
    return;
  mon = clone_object("obj/money");
  call_other(mon, "set_money", money);
   tmp = money;
  move_object(mon, environment());
  if (verbose) {
    checked_say(cap_name + " drops " + money + " gold coins.\n");
    tell_object(this_object(), "You drop " + money + " gold coins.\n");
  }
  money = 0;
   if(!is_npc)
  {
      save_me();
  log_file("ADD_MONEY", ctime(time()) + " " + file_name(environment(this_object())) + " " + name + " droped " + tmp + " coins\n");
  }
}


/* Wield a weapon. */
wield(w, silently, mixed *params, int hands) {
   int temp;
   if(!weapons) weapons = ({0,0});
   if(!armors) armors = ({});
   if(!hands) hands = 1; 
   temp = member_array(w, weapons);
   if(temp == -1){
      if(weapons[0]){
         if(weapons[1]){ 
            if(hands == 2 || weapons[0] == weapons[1]){
               unwield(weapons[0], 1);
               unwield(weapons[1], 1);
            }
            else
               unwield(weapons[1], 1);
         }
         else {
            if(member_array("shield",armors) != -1){
               if(hands == 2){
                  write("You can't wield a two-handed weapon while wearing a shield.\n");
                  return 0;
               }
               else
                  unwield(weapons[0], 1);
            }
            else {
               if(hands == 2)
                  unwield(weapons[0], 1);      
            }
         }
      }
      if(weapons[0]){
         if(this_object()->is_player()){
            if(this_object()->query_guild_name() == "dervish"){
               weapons[1] = w;
               second_weapon = w;
            }
            else {
               unwield(weapons[0], 1);
               weapons[0] = w;
               name_of_weapon = w;
            }
         }
         else {
            weapons[1] = w;
            second_weapon = w;
         }
      }
      else{
         weapons[0] = w;
         name_of_weapon = w;
         if(hands == 2)
            weapons[1] = w;
      }
      this_object()->RegisterWeapon(w,params);
      write("You wield "+w->query_name()+"\n");
      if(!silently)
         say(this_object()->query_name()+" wields "+w->query_name()+"\n");
      if(weapons[0] == w && weapons[1] == w)
         return 3;
      else if (weapons[1] == w)
         return 2;
      else
         return 1; 
   }
   else {
   write("You already are wielding that weapon.\n");
   return 0;
   }
}

qwielded(object ob){
   if(member_array(ob, weapons) != -1)
      return 1;
   else 
      return 0;
}



/* Wield a weapon. */

wield_old(w,silently) {
     if(!w) return;
    if (name_of_weapon)
	stop_wielding();
    name_of_weapon = w;
    weapon_class = call_other(w, "weapon_class", 0);
    if(!silently) {
    say(cap_name + " wields " + call_other(w, "query_name", 0) + ".\n");
    write("Ok.\n");
    }
}


/* Wear some armor. */
wear(a, silently, type, mixed *params) {
   
   if(armors){
      if(member_array(type,armors) != -1) return 0;
   }
   
   
   /* For use with paladins.  Sets paladin_shield if worn */
      if(a->query_paladin_shield())
      paladin_shield = a;
   head_armor = a;
   
   if(!armors) armors = ({ type });
   else armors += ({ type });
   RegisterArmor(a, params);
   
   
   /* Calculate new ac */
   
   if(!silently){    
      say(cap_name + " wears " + call_other(a, "query_name", 0) + ".\n");
      write("Ok.\n");
   }
   return 1;
}

wear_old(a,silent) {
    object old;

    if(head_armor) {
	old = call_other(head_armor, "test_type", call_other(a, "query_type"));
	if(old)
	    return old;
	old = head_armor;
	call_other(a, "link", old);
    }
/* For use with paladins.  Sets paladin_shield if worn */
   if(a->query_paladin_shield())
     paladin_shield = a;
    head_armor = a;
    /* Calculate new ac */
    armor_class = call_other(head_armor, "tot_ac");
    if(!silent)
    say(cap_name + " wears " + call_other(a, "query_name", 0) + ".\n");
    write("Ok.\n");
    return 0;
}

add_weight(w) {
  if (w + local_weight > level + 10 && level < 20)
    return 0;
  local_weight += w;
  return 1;
}

heal_self(h) {
object thypl;
int liv_infuse,LIV_INFUSE_LIMIT;
int TGR;
int INF_MIN, INF_MAX, INF_ADD;
  if(dieing) return;
  if (!h)return;
  thypl = this_player();
  if(thypl)
   if(this_object()->query_interactive())
     if (level < EXPLORE && thypl->query_interactive() && thypl != this_object()) {
       if(thypl->query_level() > EXPLORE)
         log_file("POINTS", name + " heal_self "+ h + call_other(thypl, "query_real_name", 0) + " " + ctime(time()) + "\n");
       else {
         if(environment(thypl) != environment(this_object())) {
           h = 0;
           tell_object(thypl,cap_name+" is not here.\n");
           /* tell_object(thypl,"Player to Player Healing transfers are not allowed.\n"); */
           tell_object(this_object(),"Attempted Healing transfer Aborted.\n");
         return 1; }
         liv_infuse = this_object()->query_infuse();
         LIV_INFUSE_LIMIT = this_object()->query_infuse_limit();
         if(thypl->query_guild_name() == "healer") { 
           TGR = thypl->query_guild_rank();   /* between 5 and 40 */ 
           INF_MIN = liv_infuse + (6 - TGR/7)*h/2; 
           INF_MAX = LIV_INFUSE_LIMIT/2 + TGR; 
           INF_ADD = (6 - TGR/7)*h/2; 
           if(INF_MIN < 0) INF_MIN = 0; 
           if(INF_MAX < 0) INF_MAX = 0;
           if(INF_ADD < 0) INF_ADD = 0;
        } else { INF_MIN = liv_infuse+6*h/2; INF_MAX = LIV_INFUSE_LIMIT/2; INF_ADD = 6*h/2; }
         if(LIV_INFUSE_LIMIT < INF_MIN || liv_infuse > INF_MAX) {
           int blah;
           blah = (LIV_INFUSE_LIMIT - liv_infuse)/3;
           tell_object(thypl,cap_name+" must wait before absorbing "+h+" healing.\n");
           if(liv_infuse < INF_MAX && blah > 0 )
             tell_object(thypl,cap_name+" may absorb up to "+blah+" healing.\n");
           tell_object(this_object(),"You must wait before absorbing more healing.\n");
           h = 0;
         return 1;}
         if(h > 0) this_object()->add_infuse(INF_ADD);
      }
    }
    if(!is_npc)
      if(!this_object()->query_interactive()) {
/*         say(cap_name+" is disconnected.\n"); */
         stop_fight(); 
         if(this_player()) this_player()->stop_fight();
      return 0;}
    hit_point += h;
    if (hit_point > max_hp) hit_point = max_hp;
    spell_points += h;
    if (spell_points > max_spell) spell_points = max_spell;
   if(!attacker_ob && h < 0) hit_player(1);
   if(hit_point < 0) hit_point = 0;
}

can_put_and_get(str)
{
  return str != 0;
}

attack_object(ob)
{
  if(!ob) {
    stop_hunter();
    return 0;
  }
  if (call_other(ob, "query_ghost", 0))
    return;
  set_heart_beat(1);    /* For monsters, start the heart beat */
  /* Zero these out just in case */
  spell_cost = 0;
  spell_dam = 0;
  if (attacker_ob == ob) {
    attack();
    return 1;
  }
  if (alt_attacker_ob == ob) {
    alt_attacker_ob = attacker_ob;
    attacker_ob = ob;
    attack();
    return 1;
  }
  if (!alt_attacker_ob)
    alt_attacker_ob = attacker_ob;
  /* If this is a player, make sure they are entitled to attack this person */
  if(call_other(this_object(), "is_player")) {
  if (!valid_attack(ob)) {
    return 0;
  }
  }
  attacker_ob = ob;
  attack();
  return 1;
}

query_ghost() { return ghost; }

zap_object(ob)
{
  if(query_level() < EXPLORE){
     write("You can't use this spell.\n");
     return 1;
  }
  call_other(ob, "attacked_by", this_object());
  checked_say(cap_name + " summons a flash from the sky.\n");
  write("You summon a flash from the sky.\n");
  if (!call_other(ob, "query_npc", 0))
    shout("There is a big clap of thunder.\n\n");
  ob->hit_player(100000);
  /*
  ob->hit_player(100000,this_object());
  */
}

missile_object(ob)
{
  /* If this is a player, make sure they are entitled to attack this person */
  if (!valid_attack(ob)) {
    write("You can't attack " + call_other(ob, "query_name", 0) + "!\n");
    return 0;
  }
  if (spell_points < 10 || checkNM()) {
    write("Too low on power.\n");
    return;
  }
  spell_name = "magic missile";
  spell_dam = random(20);
  spell_cost = 10;
  attacker_ob = ob;
}

shock_object(ob)
{
  /* If this is a player, make sure they are entitled to attack this person */
  if (!valid_attack(ob)) {
    write("You can't attack " + call_other(ob, "query_name", 0) + "!\n");
    return 0;
  }
  if (spell_points < 15 || checkNM()) {
    write("Too low on power.\n");
    return;
  }
  spell_name = "shock";
  spell_dam = random(30);
  spell_cost = 15;
  attacker_ob = ob;
}

fire_ball_object(ob)
{
  /* If this is a player, make sure they are entitled to attack this person */
  if (!valid_attack(ob)) {
    write("You can't attack " + call_other(ob, "query_name", 0) + "!\n");
    return 0;
  }
  if (spell_points < 20 || checkNM()) {
    write("Too low on power.\n");
    return;
  }
  spell_name = "fire ball";
  spell_dam = random(40);
  spell_cost = 20;
  attacker_ob = ob;
}

/*
 * If no one is here (except ourself), then turn off the heart beat.
 */

test_if_any_here()
{
  object ob;
  if(!environment(this_object())) return 0;
  if(this_object()->query_hbflag()=="hbstayon") return 1;
  if(attacker_ob)
  if(attacker_ob->query_player_shell()) return 1;
  if(!environment()) return 0;
  ob = first_inventory(environment());
  while(ob) {
    if (ob != this_object() && living(ob) && !call_other(ob, "query_npc"))
      return 1;
    ob = next_inventory(ob);
  }
  return 0;
}

show_age() {
  int i;
  
  write("age:\t");
  i = age;
  if (i/43200) {
    write(i/43200 + " days ");
    i = i - (i/43200)*43200;
  }
  if (i/1800) {
    write(i/1800 + " hours ");
    i = i  - (i/1800)*1800;
  }
  if (i/30) {
    write(i/30 + " minutes ");
    i = i - (i/30)*30;
  }
  write(i*2 + " seconds.\n");
}

stop_hunter()
{
  hunter = 0;
  tell_object(this_object(), "You are no longer hunted.\n");
}

force_us(cmd) {
   if(this_player() != this_object())
  if (level >= call_other(this_player(), "query_level")) {
    tell_object(this_object(), call_other(this_player(), "query_name") +
		" tried to force you to " + cmd + ".\n");
    return;
  }
  tell_object(this_object(), call_other(this_player(), "query_name") +
	      " forced you to '" + cmd + "'.\n");
  command(cmd);
}

/* This is used by the shop etc. */
add_money(m) {
    if (this_player() && this_player() != this_object() &&
      query_ip_number(this_player()) && query_ip_number(this_object()) &&
      call_other(this_player(), "query_level",0) > 20 &&
      level < 20)
      {
       log_file("ADD_MONEY", file_name(environment(this_object())));
	log_file("ADD_MONEY", ctime(time()) + " " +name + "(" + level + 
		") " + m + " money by " + this_player()->query_real_name() +
		"(" + this_player()->query_level() + ")\n");
	}
  money = money + m;
  if (money > 80000) 
     money = 80000;
  if (!query_npc() && level <= 19)
    add_worth(m);
}

query_money() {
  return money;
}

query_exp() {
  return experience;
}

query_frog() {
  return frog;
}

frog_curse(arg) {
  if (arg) {
    if (frog)
      return 1;
    tell_object(this_player(), "You turn into a frog !\n");
    frog = 1;
    return 1;
  }
  tell_object(this_object(), "You turn HUMAN again.\n");
  frog = 0;
  return 0;
}

run_away() {
  object here;
  int xplk;
  int i, j;
  
  object x, y;
   if(this_object()->is_player())
   if(((int)this_object()->query_pl_k() == 1) && attacker_ob)
   x=first_inventory(environment());
  while(x) {
    y=next_inventory(x);
    if(((int)x->query_pl_k() == 1) && ((object)x->query_attack() == this_object()))
      xplk=1;
    x=y;
    }
  if(xplk)
  {
     if((((int)this_object()->query_attrib("luc") * 20/30) + ((int)this_object()->query_attrib("ste") * 20 / 30) + ((int)this_object()->query_level() * 20   / 30) + ((int)this_object()->query_extra_level() / 10)) < random(100))
       return 1;


   }
  here = environment();
  if(whimpy_dir=="quit") whimpy_dir="random";
  if(!is_npc) clear_follow();
  if(runc > 1) {
    whimpy_dir = "random";
    write("Cannot run away, setting direction to random.\n");
    runc = 0;
  }
  if(!whimpy_dir || is_npc || whimpy_dir == "random") {
  i = 0;
  j = random(12);
    while(i<12 && here == environment()) {
      i += 1;
      j += 1;
      if (j > 12)
	j = 1;
      if (j == 1) command("east");
      if (j == 2) command("west");
      if (j == 3) command("north");
      if (j == 4) command("south");
      if (j == 5) command("up");
      if (j == 6) command("down");
      if (j == 7) command("in");
      if (j == 8) command("out");
      if (j == 9) command("northeast");
      if (j == 10) command("northwest");
      if (j == 11) command("southeast");
      if (j == 12) command("southwest");
    }
  if (here == environment()) {
    say(cap_name + " tried, but failed to run away.\n", this_object());
    tell_object(this_object(),
		"Your legs tried to run away, but failed.\n");
  } else {
    tell_object(this_object(), "Your legs run away with you!\n");
  }
  }
   if(whimpy_dir && whimpy_dir != "random") {
     int hp_tmp,sp_tmp,sp_new,hp_new,hp_chg,sp_chg;
     hp_tmp=hit_point;
     sp_tmp=spell_points;
   command(whimpy_dir);
     hp_new=hit_point;
     sp_new=spell_points;
     sp_chg=sp_new - sp_tmp;
     hp_chg=hp_new - hp_tmp;
     if(hp_chg > 10) { 
       hit_point = hit_point - hp_chg +5;
       if(sp_chg > 0)
       spell_points = spell_points - sp_chg;
       tell_object(this_object(), "You fumble your heal in your haste.\n");
       whimpy_dir="random";
       run_away();
     }
   tell_object(this_object(), "Your legs run away with you!\n");
   if (here == environment()) runc += 1;
   else runc = 0;
  }
}

query_hp() {
  return hit_point;
}

query_wimpy() {
  return whimpy;
}

query_current_room() {
  return current_room;
}

checked_say(str) {
  if (query_invis() >= INVIS_ACTION) return;
  say(str);
}

query_invis(num) {
  if (!num) {
    return is_invis;
  } else {
    if (level <= num || num >= ALL_POWER) {
      return -is_invis;
    } else { return is_invis;}
  }
}

stop_fight() {
  attacker_ob = alt_attacker_ob;
  alt_attacker_ob = 0;
}
query_gender_string() {
 return gender;
}

query_pronoun() {
    if (gender == "creature")
	return "it";
    else if (gender == "male")
	return "he";
    else
	return "she";
}

query_possessive() {
    if (gender == "creature")
	return "its";
    else if (gender == "male")
	return "his";
    else
	return "her";
}

query_objective() {
    if (gender == "creature")
	return "it";
    else if (gender == "male")
	return "him";
    else
	return "her";
}

query_age() {
      return age;
}

query_wc() {
   int temp, i, j;
   mixed *types;
   object *weapons2;
   if(Weapons){
      weapons2 = keys(Weapons);
      for(i=0;i<sizeof(weapons2);i++){
         if(Weapons[weapons2[i]] != 0){
            types = Weapons[weapons2[i]];
            j = sizeof(types)/3;
            while(j){
              if(types[(3*j)-3] == "physical")
                  temp += types[(3*j)-2];
              j -= 1;
            }
         }
      }
   }
   else if(weapon_class && this_object()->is_npc())
      temp = weapon_class;

   return temp;
}

query_wc_old() {return weapon_class;}

query_ac() {
   int temp, i, j;
   mixed *types;
   object *armors;
   if(Armors){
      armors = keys(Armors);
      for(i=0;i<sizeof(armors);i++){
         if(Armors[armors[i]] != 0){
            types = Armors[armors[i]];
            j = sizeof(types)/4;
            while(j){
              if(types[(4*j)-4] == "physical")
                  temp += types[(4*j)-3];
              j -= 1;
            }
         }
      }
   }
   else if(armor_class && this_object()->is_npc())
      temp = armor_class;

   return temp;
}

query_sp() {
 if(checkNM()) return -200;
 return spell_points;
}
query_msp() {return max_spell;}
query_mhp() {return max_hp;}
lower_attrib() {
  int la,ok,i;
  string las;
  ok = 0;
    i=0;
  while (ok < 1) {
  la = random(8);
i=i+1;
  if(i>70) return 1;
  if (la == 8) return 1;
  if (la == 7) las = "strength";
  if (la == 6) las = "will_power";
  if (la == 5) las = "magic_aptitude";
  if (la == 4) las = "piety";
  if (la == 3) las = "stamina";
  if (la == 2) las = "stealth";
  if (la == 1) las = "luck";
  if (la == 0) las = "intelligence";
if (call_other(this_object(), "query_attrib", extract(las,0,2)) > 1)
   ok = 1;
}
call_other(this_object(), "raise_" + las, -1);
return 1;
}
spell_object(ob,name,dam,cost,at_msg,vi_msg,rm_msg) {
    if(!valid_attack(ob)) {
       write("You can't attack " + call_other(ob,"query_name",0) + "!\n");
       return 0;
    }
     if (spell_points < cost || checkNM()) {
       write("Too low on power.\n");
       return;
     }
    if(at_msg) { asf = 1; tell_object(this_object(), at_msg); }
    if(vi_msg) { vsf = 1; tell_object(ob,vi_msg); }
    if(rm_msg) { rsf = 1; say(rm_msg); }
     spell_name = name;
    spell_dam = dam;
     spell_cost = cost;
     attacker_ob =ob;
}
set_spell_dam(dam) {
      spell_dam = dam;
 }
query_weapon() {return name_of_weapon;}
query_hunted() {return hunted;}
query_hunter() {return hunter;}
hit_pet(k1,k2){
int tmpk;
string name_alt_at;
      if(alt_attacker_ob)
      if(is_npc && alt_attacker_ob->is_pet() && random(100) < 37) {
           already_fight=0;
           name_alt_at=alt_attacker_ob->query_name();
           tmpk = alt_attacker_ob->hit_player(random(k1)+k2);
           if(tmpk == 0) say(cap_name +" missed "+name_alt_at+".\n");
           if(tmpk < 10) say(cap_name +" hits "+name_alt_at+" with a side attack.\n");
           if(tmpk > 10) say(cap_name +" hits "+name_alt_at+" hard with a side attack.\n");
           }
return 1;
}
query_name_of_weapon() {return name_of_weapon;}
query_message_hit(int tmp) {
   string *mess;
    mess = ({" to small fragments","massacred"});
  if (tmp < 30) {
    mess = ({" with a bone crushing sound","smashed"});
  }
  if (tmp < 20) {
    mess = ({" very hard","hit"});
  }
  if (tmp < 10) {
    mess = ({" hard","hit"});
  }
  if (tmp < 5) {
    mess = ({"","hit"});
  }
  if (tmp < 3) {
    mess = ({"","grazed"});
  }
  if (tmp == 1) {
    mess = ({" in the stomach","tickled"});
  }
  return mess;
}
set_no_exp_value() { no_exp_value = 1; }
query_no_exp_value() { return no_exp_value; }
set_mounted(arg) {
 string how;
 mounted = arg;
 how = mounted->on_what();
 omsgin = msgin;
 omsgout = msgout;
 msgin = msgin + " on "+how;
 msgout = msgout + " on "+how;
 }
clear_mounted() {
 mounted = 0;
 msgin = omsgin;
 msgout = omsgout;
}
query_mounted() { return mounted; }
checkNM() {
string rlm;
object envobj;
envobj=environment();
if(envobj) {
rlm = envobj->realm();
if(level < EXPLORE)
if(rlm=="NM" || envobj->query_NM()) {
if(this_player() == this_object())
write("Your powers fail here. Something seems to be sapping your power.\n");
return 1;
}
}
return 0;
}
query_alt_attack() { return alt_attacker_ob;}
query_local_weight() { return local_weight;}
query_spell_dam() { return spell_dam; }
query_head_armor(){ return head_armor; }
clear_name_of_weapon() { name_of_weapon = 0; }
query_composite() { 
  int composite;
  if(armor_class && weapon_class)
    composite = weapon_class * armor_class + max_hp + max_spell;
  else
    composite = weapon_class + armor_class + max_hp + max_spell;
  if(is_npc) {
   int sd1,sd2;
   sd1 = this_object()->query_spell_dam();
   sd2 = this_object()->query_spell_chance();
   composite += (sd1*sd2)/100;
 }
  return composite;
}


static int ac_bonus, hp_bonus, wc_bonus;

/* NEW SETTINGS and QUERIES */

set_hp_bonus(num) { hp_bonus = num; }
query_hp_bonus()  { return hp_bonus; }
set_wc_bonus(num) { wc_bonus = num; }
query_wc_bonus()  { return wc_bonus; }
set_ac_bonus(num) { ac_bonus = num; }
query_ac_bonus()  { return ac_bonus; }

/* NEW FUNCTION CALCULATING EXP WORTH */

calculate_worth() {
  int hp_factor, wc_factor, ac_factor, exp_worth;

  hp_factor = (max_hp / 50) + 1;
  hp_factor += hp_bonus / 50;

  wc_factor = weapon_class;
  wc_factor += this_object()->query_spell_chance() * this_object()->query_spell_dam()/ 200;
  wc_factor += wc_bonus;

  ac_factor = armor_class;
   if(this_object()->query_heal_rate() > 0 && this_object()->query_heal_intv() > 0)
      ac_factor += (this_object()->query_heal_rate() * 3) / this_object()->query_heal_intv();
  ac_factor += ac_bonus;

  exp_worth = hp_factor * wc_factor * ac_factor;
  return exp_worth;
}

/* cpl functions added by Verte [7.9.01] */


QueryArmors()
{
    int s;
    mixed *k;
    mapping n;

    if(!Armors) Armors = ([ ]);

    s = sizeof(k = keys(Armors));
    n = ([ ]);

    while(s --)
      if(k[s] && objectp(k[s]))
        n[k[s]] = Armors[k[s]];

    return n;
}

QueryWeapons()
{
    int s;
    mixed *k;
    mapping n;

    if(!Weapons) Weapons = ([ ]);

    s = sizeof(k = keys(Weapons));
    n = ([ ]);

    while(s --)
      if(k[s] && objectp(k[s]))
        n[k[s]] = Weapons[k[s]];

    return n;
}

toggle_already_fight(x) { already_fight ^= 1; }

is_dieing() { return dieing; }

add_hp(x) { return this_object()->add_hit_point(x); }
add_sp(x) { return this_object()->add_spell_point(x); }
query_hit_point() { return query_hp(); }

test_if_any_monsters_attacking()
{
    object ob, e;

    if(!(e = environment()))
      return 0;

    ob = first_inventory(e);

    while(ob)
    {
      object oc;
      oc = next_inventory(ob);
      if ((ob != this_object()) && living(ob) && (int)ob->query_npc() &&
          ((object)ob->query_attack() == this_object()))
        return 1;
      ob = oc;
    }
    return 0;
}
