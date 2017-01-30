/* Removed all paladin guild stuff - Rumplemintz
   3/31/2015
 */

#include <security.h>
#include <ansi.h>

/* From /obj/lib/living/settings.h - Rumplemintz */
#define WA_FACTOR                 3
#define EXP_DIVISOR               190
#define INTERVAL_BETWEEN_HEALING  10
#define WEAPON_CLASS_OF_HANDS     3
#define ARMOUR_CLASS_OF_BARE      0
#define MAX_LIST                  20
#define NAME_OF_GHOST             "some mist"
#define MAXLEVEL_LOSS             2
#define MAXEXP_LOSS               3000000
#define MAXCOINS                  80000

/* Alignment Definitions */
#define ALIGN_EXP_DIVISOR         1800
#define KILL_NEUTRAL_ALIGNMENT    10
#define CAP_GOOD_ALIGN            1800
#define CAP_EVIL_ALIGN           -1800
#define ADJ_ALIGNMENT(al)         ((-al - KILL_NEUTRAL_ALIGNMENT)/4)

/* These are just used for alignment titles */
#define ALIGN_WHITE_LORD          640
#define ALIGN_PALADIN             320
#define ALIGN_CRUSADER            160
#define ALIGN_GOOD                80
#define ALIGN_HONORABLE           40
#define ALIGN_NEUTRAL            -40
#define ALIGN_MALICIOUS          -80
#define ALIGN_EVIL               -160
#define ALIGN_INFAMOUS           -320
#define ALIGN_BLACK_KNIGHT       -640

/* Hacked by Verte 12-13-06 */
#define MAX_SOAK                  (level * 8 + ex_lv * 2)
#define MAX_STUFF                 (level * 8 + ex_lv * 2)
#define MAX_INTOX                 ((level + 3) + (ex_lv / 5 + 1))
#define INFUSE_LIMIT              (((9 * level) + (9 * ex_lv / 4)) / 2)
#define SAVE_INTERVAL             400
#define IDLELIMIT                 1800
#define NUMOBS_STOR               25

#define EMOTE_OB "/obj/user/parse_emote"

/* 06/02/06 Earwax:  #define DOUBLEXPDAY 1    or TRIPLEXPDAY 1 to
 * turn on double xp, remove them when it's no longer bonus xp.
 */
#if 0
#define DOUBLEXPDAY 1
#endif
#if 0
#define TRIPLEXPDAY 1
#endif

/*
 * Include this file in objects that "lives".
 * The following variables are defined here:
 *
 */

int time_to_heal;          /* Count down variable. */
int hcnum;
int crime;                 /* have we been bad.  players */
static int crimetime;
int money;                 /* Amount of money on player. */
int luck2,lucky;
string name;               /* Name of object. */
static int already_fight;
                           /* see if more than one attack per hb
                              method like that made by shadowhawk.*/
static int asf,vsf,rsf;
static int dieing;         /* are we in the death sequence? */
static int runc;           /* count how many times we try to run
                              after 3 goto random */
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
object h_check;         /* for multiple hit_player calls in one round. */
object alt_attacker_ob; /* Name of other player also attacking us. */
int weapon_class;       /* How good weapon. Used to calculate damage. */
object name_of_weapon;  /* To see if we are wielding a weapon. */
object shield_ob;       /* for query_shield code */
object head_armor;      /* What armor we have. */
status ghost;           /* Used for monsters that can leave a ghost. */
status dead;
string whimpy_dir;
int local_weight;       /* weight of items */
object hunted, hunter;  /* used in the hunt mode */
int hunting_time;       /* How long we will stay in hunting mode. */
string cap_name;        /* Capital version of "name". */
string vis_name;        /* Capital version of "real_name" - Rumplemintz */
int spell_points;       /* Current spell points. Same max as max_hp. */
int max_spell;          /* for arrrib -Bp */
string spell_name;
status disallow_give;
int spell_cost, spell_dam;
string spell_dtype;     /* Allows damage type for spells <illarion> */
int age;                /* Number of heart beats of this character. */
int is_invis;           /* True when player is invisible */
int frog;               /* If the player is a frog */
int whimpy;             /* Automatically run when low on HP */
static int no_exp_value;/*flag for test monsters not to give exp.*/
string auto_load;       /* Special automatically loaded objects. */
string current_room;    /* Name of current room. */
static object mounted;  /*what we may be riding, horse, etc */
static string omsgin, omsgout; /* used for mounted */
static string *armors;
static int dam_taken_this_round;
static int old_dam_hp;
static lostexperience;
static object dc_stop_c;  /* dc cheating stoppage */
static status feedback_off;

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
 * query_vis_name:      Give the capitalized version of above. - Rumplemintz
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
 * set_spell_dtype      Set the damage type for a spell_object <illarion>
 */


#if 0 /* Rumplemintz */
/* 
 * Additions for Paladins
 * A couple off functions for handling offwielded weapons
 */

static object second_weapon;
static second_wc;
static object paladin_shield; 

string custom_room_death_mess;
string custom_attacker_death_mess;

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
#endif

/*
 * This routine is called from objects that moves the player.
 * Special: direction "X" means teleport.
 */
move_player(dir_dest)
{
  string dir, dest;
  object ob;
  int sm;
  int is_light;
  
  sm = present("silent_move_object") ? 1 : 0;
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
  if(environment() && !environment()->silent_leave(dir)) {
  if (ghost)
    say(NAME_OF_GHOST + " " + msgout + " " + dir + ".\n");
  else if (dir == "X" && query_invis() < INVIS_TELEPORT)
    say((string)this_object()->query_name() + " " + mmsgout + ".\n");
  else if(query_invis() < NO_MOVE && is_light && !sm)
    tell_room(environment(), (string)this_object()->query_name() + " " + msgout + " " + dir + ".\n", ({ this_object() }));
  }
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
    say((string)this_object()->query_name() + " " + mmsgin + ".\n");

  else if(query_invis() < NO_MOVE && is_light && !sm)
    tell_room(environment(), (string)this_object()->query_name() + " " + msgin + ".\n", ({ this_object() }));
  if (hunted && present(hunted))
    attack_object(hunted);
  if (hunter && present(hunter))
    call_other(hunter, "attack_object", this_object());
  if (is_npc)
    return;
  if (is_light > 0 && present("black_willow_object", this_object())) {
    write("A bright room.\n");
    return;
  }
  if (!is_light && !present("dark_sight_object", this_object())) {
    write("A dark room.\n");
    return;
  }
  if(present("blindness_object", this_object())) {
    write("You can't see!\n");
    return;
  }
  ob = environment(this_object());
  if (brief == 1) {
    write(call_other(ob, "short", 0)); 
    write(".\n"); /* killed '+' --Wulkwa */
  } else {
          if(brief == 2) {
           string sdec;
           int sdecl,lkcol;
            sdec=call_other(environment(), "short");
            sdecl=strlen(sdec);
            sdecl=40-(sdecl/2);
            if(lkcol=get_ansi_pref("roomtitle"))
              write(pad(" ",sdecl-1)+lkcol+sdec+NORM+"\n");
            else
            write(pad(" ",sdecl-1)+sdec+"\n");
          }
    call_other(ob, "long", 0);
  }
  ob = first_inventory(ob);
  while(ob) {
    if (ob != this_object()) {
      string short_str;
      short_str = call_other(ob, "short");
      if (short_str)
	write(short_str + ".\n");
    }
   if(ob) ob = next_inventory(ob);
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
   if(gear && gear->query_type()=="shield") {
     shield_ob=gear;
   }
   Armors[gear] = params;
}

RemoveArmor(object gear){
   if(Armors == 0){ Armors = ([ ]); }
   if(!Armors[gear]) return 0;
   Armors[gear] = 0;
   if(gear && gear->query_type()=="shield") {
     shield_ob=0;
   }
   Armors=m_delete(Armors,gear);
   return 1;
}

mapping Weapons;

RegisterWeapon(object gear, mixed *params){
   if(Weapons == 0){ Weapons = ([ ]); }
   Weapons[gear] = params;
}

RemoveWeapon(object gear){
   if(Weapons == 0){ Weapons = ([ ]); }
   if(!Weapons[gear]) return 0; /* dtype addition <illarion> */
   Weapons[gear] = 0;
   Weapons=m_delete(Weapons,gear);      /* dtype addition <illarion> */
   return 1;                    /* dtype addition <illarion> */
}

QueryWeapon(object gear) {
  if(!Weapons) Weapons = ([ ]);
  return Weapons[gear];
}

QueryArmor(object gear) {
  if(!Armors) Armors = ([ ]);
  return Armors[gear];
}

query_shield() {
  return shield_ob;
}

/* dtype addition <illarion> */
mapping WeaponBonuses;

RegisterWeaponBonus(object gear, mixed *params) {
  if(WeaponBonuses==0) WeaponBonuses = ([]);
  WeaponBonuses[gear]=params;
}

RemoveWeaponBonus(object gear) {
  if(WeaponBonuses==0) WeaponBonuses = ([]);
  if(!WeaponBonuses[gear]) return 0;
  WeaponBonuses[gear]=0;
  WeaponBonuses=m_delete(WeaponBonuses,gear);
  return 1;
}

QueryWeaponBonus(object gear) {
  if(WeaponBonuses==0) WeaponBonuses = ([]);
  return WeaponBonuses[gear];
}

QueryWeaponBonuses() {
  return WeaponBonuses;
}
object pob_dd;
query_pob_dd() { return pob_dd; }
/* end dtype addition */



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
  int i, j, k, y;
  string type;
  int ac_tmp, dam, total, class, res, temp, itemp, pres_ac;
  string cat,subcat;
  mixed *armors2;
  object *armors;
  status testerme,testerthem;

  if (this_player()) {
    pob_dd = this_player();
  } else {
    pob_dd = 0;
  }
  if(dieing) {
    if (dieing < 8)
      return 0;
    dieing += 1;
  }
  /* if we are in the death sequence do not allow access to hit_player() */
  if (!is_npc)
    if (!this_object()->query_interactive()) {
      say(cap_name + " is disconnected.\n");
      stop_fight(); 
      if (this_player()) 
        this_player()->stop_fight();
        return 0;
    }
  if (this_player() &&
      this_player() != this_object() &&
      this_player()->query_level() < EXPLORE) {
   /* -= Protection =- */  
    if (this_player()->is_player() &&
        this_player()->query_attack() != this_object() &&
        !this_player()->valid_attack(this_object())) {
    /* bad attack, could be logged */
      write( "Your attack fails.\n");
      return 0;
    }
    if(this_object()->is_player() &&
       !is_npc &&
       !this_object()->query_interactive())
      return 0;
    if (attacker_ob == alt_attacker_ob || !alt_attacker_ob)
      attacked_by(this_player());
    }
    if (level >= EXPLORE && !is_npc)   /* You can't hit a wizard ! */
      return 0;
    if (ghost == 1) return 0;      /* You cannot hit the dead! */

  /***********************************/
  /*  BEGIN ADDITIONS FOR MULTIPLE   */
  /*  TYPES OF DEFENSE               */
  /*  Coded by Beck                  */
  /***********************************/
    if(!damage) return 0;
    /* testchar feedback setup */
   
    if (this_object()->query_level() > 20)
      testerme = 1;
    else if(this_object()->is_testchar() && feedback_off==0)
      testerme=1;
    if(this_player() && this_player()->toggle_feedback(1)==0 && 
       (this_player()->is_testchar() || this_player()->query_level() > 20))
      testerthem=1;
    for(i=0; i<sizeof(damage); i++){
      if(damage[i]){
        dam = damage[i];
/*
         dam = guild_power_reduction(dam);
*/
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
                temp=0;
                if(objectp(armors[k])) {
                  if(armors2[itemp+3])
                    if(armors[k])
                      temp += (int) call_other(armors[k],armors2[itemp+3], this_object(), dam);
                  if(armors[k])
                    temp+= (int) call_other(armors[k], "get_enchantment_defense", this_object(), type);
                }
                if(temp) {
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
        if(testerme)
          tell_object(this_object(),"Testchar feedback[defense]: type:"+type+" raw dam:"+dam+"\n");
        if(testerthem && this_player())
          tell_object(this_player(),"Testchar feedback[offense]: type:"+type+" raw dam:"+dam+"\n");
         
         /* Calculate new damage */
        res = 100 - res;
        dam = res * dam;
         /* integer math adjustment */
        if(dam % 100 > 50)
          dam = 1+dam/100;
        else
          dam = dam/100;
         
        ac_tmp = 0;
        /* Pregnancy has it's drawbacks */
        if(!is_npc && this_object()->query_pregnancy()){
          y = age - this_object()->query_pregnancy();
          y = y/5000;
          ac_tmp = ac_tmp - y;
        }
        class += ac_tmp;
        /* replaced with testchar feedback - Ill
         if(this_player()){
            if(this_player()->query_level() > 19){
               write("Class: "+class+" Res: "+(100-res)+"\n");
            }
         }
         */
/* this hack, likely mine, doesn't seem right -Bp
phase in a fix */
        if(attacker_ob){
          if (attacker_ob->is_player() &&
              attacker_ob->query_level() < EXPLORE &&
              attacker_ob != this_object()){
            if(class > 14) class = 14 + random(random(class-10));
          }
        }
/*Replace with:*/
        if(!is_npc && level < 21) {
          ac_tmp=10+this_object()->query_total_level()/20;
          if(class>ac_tmp)
            class=ac_tmp+random(1+class-ac_tmp);
        }
        dam -= random(class + 1);
        /*****************************************************************
         * BEGIN PRESTIGE AC ADDITION 
         ****************************************************************/
         pres_ac = this_object()->query_prestige_skill( "AC" );
        if( pres_ac > random( pres_ac + 2 ) ) {
          if( pres_ac > 9 ) pres_ac = 9 + ( pres_ac - 9 )/3;
          dam -= random( pres_ac );
          if(testerme)
            tell_object(this_object(), "Testchar feedback[defense]: prestige ac:"+pres_ac+"\n");
          tell_object(this_object(), "Your prestige aura "+HIB+"glows"+NORM+" and "+CYN+"p u l s a t e s"+NORM+" as it "+HIBLK+"absorbs"+NORM+" energy.\n" );
          tell_room(environment(), (string)this_object()->query_name()+"'s "+HIB+"aura of prestige"+NORM+CYN+" p u l s a t e s"+NORM+" as it "+HIBLK+"absorbs"+NORM+" energy.\n", ({ this_object() }));
        }
        /*****************************************************************
         * BEGIN PRESTIGE AC ADDITION 
         ****************************************************************/
         
        if(testerme)
          tell_object(this_object(),"Testchar feedback[defense]: ac:"+class+" res:"+(100-res)+" reduced dam:"+dam+"\n");
        if(testerthem)
        {
          if(this_player())
            tell_object(this_player(),"Testchar feedback[offense]: ac:"+class+" res:"+(100-res)+" reduced dam:"+dam+"\n");
        }
        total += dam;  
      }
    }
   
    /***********************************/
    /*  END OF ADDITIONS FOR MULTIPLE  */
    /*  TYPES OF DEFENSE               */
    /*  Coded by Beck                  */
    /***********************************/

    lucky = random(500);
    luck2 = (is_npc ? 0 : this_object()->query_stat("luck"));
    if (lucky < luck2) {
      tell_object(this_object(), "Your luck comes through for you.\n");
      if (luck2 < 12)
        total = total/2;
      if (luck2 > 11 && luck2 <16)
        total = total/3;
      if (luck2 > 15)
        total = total/5;
    }
    /* Old crushing blow calculation.  Updated by Fred on 12.31.13 */
    /* Updated so Luck stat was involved and Dmg wasn't quite as   */
    /* extreme with some large mobs.  Code per Dragnar.  Go Gnar!  */   
    /*  
    if (lucky > 494){
      total = total*5/3;
    if(attacker_ob)
      tell_object(this_object(), attacker_ob->query_name() + " hits you with a crushing blow.\n");
    }
    */

    /* New Code for crushing blow */
    if (lucky > 494){
      switch( luck2 ) {
        case 0..9:
          /* 167% damage */
          total = total*5/3;
          break;
        case 10..15:
          /* 150% damage */
          total = total*6/4;
          break;
        case 16..20:
          /* 140% damage */
          total = total*7/5;
          break;
        case 21..26:
          /* 130% damage */
          total = total*13/10;
          break;
        default:
          /* 125% damage */
          total = total*5/4;
          break;
      }
      if(attacker_ob)
        tell_object(this_object(), attacker_ob->query_name() + " hits you with a crushing blow.\n");
    }

   /* fixed damage cap */
    if(attacker_ob){
      if (attacker_ob->is_player() && attacker_ob->query_level() < 21 && attacker_ob != this_object()){
        if(total > 49) {
          if(total < 50) total = total - random(1);
          if(total < 53 && total > 49) total = total - random(5);
          if(total < 55 && total > 52) total = total - random(8);
          if(total > 54 && total < 60) total = 55 - random(8);
          if(total > 59 && total < 70) total = 55 - random(15);
          if(total > 69) total = 55 - random(19);
        }
      }
    }
    /* alternate damage cap based on level */
    /* cap is 32 at level 1, and goes up 1 pt per normal level and 1/4 pt per extra level
    if(this_player()) {
      object att_ob;
      int cap;
      att_ob=this_player();
      if(att_ob!=this_object() && att_ob->is_player() && att_ob->query_level() < 21) {
        cap=31+att_ob->query_level()+att_ob->query_extra_level()/4;
        if(total>cap)
          total=cap;
       }
     }
    */
    if(hit_point < 0 && total <= 0) total = 1;
    if(hit_point < 0) hit_point = 0;
    if (total <= 0) return 0;
    if (total > hit_point + 1) total = hit_point + 1;
    /* 07/13/07 Earwax: a little experiment */
    COMBATD->do_damage((this_player() ? this_player() : 0), this_object(), total);
    hit_point = hit_point - total;
    if (hit_point < 0) {
      death();
    }
    if(this_player()){
      if(testerthem) {
        tell_object(this_player(),"Testchar feedback[offense]: total damage:"+total+"\n");
        /* wizards are considered testers already
        if(this_player()->query_level() > 19){
          write("Damage: "+total+"\n");
         */
      }
    }
    if(this_object()) {
      if(testerme)
        tell_object(this_object(),"Testchar feedback[defense]: total damage:"+total+"\n");
      if(present("damage_report_object", this_object()))
         present("damage_report_object", this_object())->report_damage(total, previous_object());
    }
    dam_taken_this_round += total;
    return total;
}
 

/* 2/2/2000
 * Death Function.  Separated for clarity.  Identical to old death sequence.
 * Spar/PK stuff fixed/added by Vertebraker [7.10.01]
 * New PK Code in testing [3.13.02]
 * PK test ended, nov-2002, restored risk/reward -Bp
 * added death(str) syntax
 */
death(str)
{
    status s_flag, PKFlag;
    object corpse, e;
    int lostexp;

    /* We died ! */

    dieing = 1;
    /* use this in case death squence errors. -Bp */
    call_out("clear_dieing",45);

    if (hunter)
       hunter->stop_hunter();

    hunter = 0;
    hunted = 0;

#if 0 /* Rumplemintz */
    if(!custom_room_death_mess)
      say((string)this_object()->query_name() + " died.\n");
    else if(stringp(custom_room_death_mess))
      say(custom_room_death_mess);
#else
  say((string)this_object()->query_name() + " died.\n");
#endif

  if(environment() && !is_npc) {
    object tombstone;
    tombstone=clone_object("/obj/user/tomb/tombstone");
    move_object(tombstone, environment());
    tombstone->setPlayerName(capitalize(name));
  }
    if((e = environment()) && e->query_spar_area() && !is_npc) s_flag = 1;
    if(s_flag && (int)environment()->player_spar_only()) {
      if(!test_if_any_monsters_attacking()) s_flag = 1;
      else s_flag = 0;
    }

   if(attacker_ob)
     if(environment()) /* this better happen ! */
     {
       int s;
       object *inv, *ob_inv, kc,obe;
       obe = first_inventory(this_object());
       while(obe) {
         if ((status)obe->id("death_check_object"))
            obe->death_check(this_object());
         obe = next_inventory(obe);
       }

       if(!alt_attacker_ob)
       {
         s = sizeof(inv = all_inventory(attacker_ob));
         while(s --)
           if((kc = inv[s]) && (kc->id("kill_check_object")))
             kc->kill_check(this_object());
       }
       else
       {
         object a;
        
         s = sizeof(inv = all_inventory(environment()));
         while(s --)
         {
           if((a = inv[s]) && ((object)a->query_attack() == this_object()) &&
             (kc = present("kill_check_object", a)))
            while(kc)
           {
             if((status)kc->id("kill_check_object"))
                kc->kill_check(this_object());
             if(kc)
               kc = next_inventory(kc);
           }

         }
         }
     }

   if(str) log_file("DEATHS", ctime()+" "+name+" "+experience+" exp "+money+" gold killed by "+str+".\n");
   /* If this is a player, log the death for future reference */
    else if(!is_npc && s_flag)
      log_file("DEATHS","Spar-> ");

    if(!is_npc)
    {
      if(!str && attacker_ob)
      {
        log_file("DEATHS", ctime() + " " + name + " " + experience +
          " exp " + money + " gold killed by " +
          attacker_ob->query_real_name() + ".\n");

        if(attacker_ob->is_player())
           log_file((s_flag ? "SPAR" : "PK"), 
             ctime() + " " + name + " " + experience +
             " exp " + money + " gold killed by " +
             attacker_ob->query_real_name() + ".\n");
      } 

      else if(!str)
      {
        log_file("DEATHS", 
          ctime() + " " + name + " " + experience + " exp " +
          money + " gold - killer unknown.\n");
        if(this_player())
        {
          log_file("DEATHS","this_player is " + 
            this_player()->query_real_name() + 
            "   " + this_player()->query_name() + "\n");
        } else if(previous_object()) {
          log_file("DEATHS","previous object is "+object_name(previous_object())+"\n");
        }

      }
        
      tell_object(this_object(), "\n\n\
You feel very weak as your badly damaged body falls \
to the ground to die.\n");

        if(((int)this_object()->query_pl_k() == 1) &&
         ((attacker_ob) || (alt_attacker_ob)) &&
         !test_if_any_monsters_attacking())
        {
          PKFlag = 1;
        }
        if((int)this_object()->query_pl_k() == 1 &&
          previous_object() && (previous_object()->pk_spell()))
          {
            PKFlag = 1;
          }

      if(!s_flag)
      {
        int newexp, new2exp, oldexp;
        oldexp = experience;
        newexp = call_other("room/adv_guild", "check_exp",experience,-MAXLEVEL_LOSS);

        if(this_object()->query_extra_level() > 2)
          newexp=call_other("room/exlv_guild","check_exp",experience,-MAXLEVEL_LOSS);
        new2exp = (experience - MAXEXP_LOSS);
        if(new2exp > newexp) newexp = new2exp;

        if(level > 7)
        experience = (experience * 3) / 4;  /* Take away 1/4 of exp. */
        else
        experience = (experience * 5) / 6;  /* Take away 1/6 of exp. */

        if(newexp > experience)
          experience = newexp;
  
        this_object()->eat_food(-(this_object()->query_stuffed()));
        this_object()->drink_soft(-(this_object()->query_soaked()));
        this_object()->add_intoxination(-(this_object()->query_intoxination()));
        if(PKFlag) {
          if(experience < (oldexp*5)/6)
            experience = (oldexp*5/6);
          lostexp=oldexp - experience;
        }
                    
        lostexperience = oldexp - experience;
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
    if(!s_flag) {
      corpse->set_level(level);
      corpse->set_mhp(max_hp);
      corpse->set_ac(armor_class);
      corpse->set_wc(weapon_class);
      corpse->set_exp_worth( calculate_worth() );
    }
    else corpse->set_level(1);
    
    if(!is_npc)
    { 
      set_ghost(1);
      move_object(corpse, e); 
      set_ghost(0);
    } else {
      string tmp;
      if((tmp=this_object()->query_corpse_name()))
        corpse->add_id(tmp);
      if((tmp=this_object()->query_corpse_short()))
        corpse->set_short(tmp);
      if((tmp=this_object()->query_corpse_long()))
        corpse->set_long(tmp);
      this_object()->perform_death_emote();
    }
   
    if(!attacker_ob)
      attacker_ob = alt_attacker_ob;
    if(!this_object()->is_kid() && !this_object()->is_pet())
      if(attacker_ob && !environment(this_object())->pk_tourney()) 
        corpse->set_killer(attacker_ob->query_real_name());
      else
      {
        corpse->set_killer("pK Tourney");
        corpse->add_decay(50000);
      }   
    if(!is_npc)
    {
      see_if_other(3); /* prevent cheating */
      this_object()->save_me();
     /* Added this to clear crime if it exists - Rumplemintz */
      if(this_object()->query_crime()) this_object()->clear_crime();
     /* Remove the following two lines to get rid of pk exp value */
      if(attacker_ob && attacker_ob->is_player())
        attacker_ob->add_exp(lostexp/10); 
      /* Transfer lost exp/10 to pk victor! */
    }

    /* that last line was not true before.. it is now. */

    else if(attacker_ob && is_npc)
    {
      int exp_worth, pres_exp;  
      object party, pres_attacker;

      exp_worth = (int)this_object()->calculate_evaluated_worth(attacker_ob);

      if(present("double_xp_object", attacker_ob) || attacker_ob->query_is_bday() )
        exp_worth *= 2;

      /*****************************************************************
       * BEGIN PRESTIGE EXP ADDITION 
       ****************************************************************/
      if( attacker_ob->is_mirror() && attacker_ob->query_owner() )
        pres_attacker = attacker_ob->query_owner();
      else
        pres_attacker = attacker_ob;
        
      pres_exp = pres_attacker->query_prestige_skill( "EXP" );  
      if( exp_worth > 0 && pres_exp > random( pres_exp + 4 ) ) {
        exp_worth += exp_worth * ( pres_exp * 110 ) / ( 10 + pres_exp ) / 100;
        tell_object(pres_attacker, HIBLK+"Your prestige honor blesses your victory and increases your experience.\n"+NORM);
        tell_room(environment(), HIBLK+(string)pres_attacker->query_name() + " is is surrounded by a glow of prestige honor.\n"+NORM, ({ pres_attacker }));
      }
      /*****************************************************************
       * END PRESTIGE EXP ADDITION 
       ****************************************************************/
      party = present("party object", attacker_ob);
      if(!no_exp_value)
      {
        if(party) 
          party->share_exp(exp_worth);
        else {
          tell_object(attacker_ob,"Experience Gain: "+exp_worth+"\n");
          
          attacker_ob->add_exp(exp_worth);

          if(attacker_ob->query_level() < 20 && attacker_ob->query_extra_level() < 100)
         {
           int xpn;
           xpn = (int)call_other("/bin/play/_xpnext", "query_next_xp", 0, attacker_ob);
           if(xpn <= 0) write("You are ready to advance to your Next Level.\n");
           else write("Experience needed for your Next Level: "+xpn+".\n");
        }
          /*
          attacker_ob->add_exp(exp_worth);
          */
        }
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
#if 0 /* Fix for Shard LD issues --Gnar */
    dieing = 0;
#else
    call_out("clear_dieing", 0);
#endif

    if(!this_object()->second_life())
      if(this_object())
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
 /* Crime - Added back in by Rumplemintz */
    if (this_player()->query_level() < EXPLORE)
    { /* Don't log or set for Wizards */
      if ( (!is_npc || this_object()->crime_to_attack()) ||
           (!is_npc && this_player()->query_pl_k() == 1))
      { /* It's a player and not a spar, or it's a crime to attack it */
        if (!this_player()->query_crime() && !this_player()->is_npc())
        { /* If the crime flag isn't set and it's not an aggressive mob */
          this_player()->set_crime();
          log_file("crime", "----------------------------------------\n" +
                   this_player()->query_real_name() + "\n" +
                   "set_crime called by " +
                   (this_object()->is_npc() ? object_name(this_object())
                                            : this_object()->query_real_name()
                   ) + " " + ctime()[4..strlen(ctime())] + "\n");
        }
      }
    }
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

#if 0 /* Rumplemintz */
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
#endif


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
  luck2 = (is_npc ? 0 : this_object()->query_stat("luck"));
  if (lucky < luck2) {
    tell_object(this_object(), "Your luck comes through for you.\n");
    if (luck2 < 12)
       dam = dam/2;
    if (luck2 > 11 && luck2 <16)
       dam = dam/3;
    if (luck2 > 15)
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
    say((string)this_object()->query_name() + " died.\n");
    /* If this is a player, log the death for future reference */
    if(!is_npc && environment(this_object())->query_spar_area())
      log_file("DEATHS","Spar-> ");
    if (!is_npc) 
      if (attacker_ob)
    log_file("DEATHS", ctime() + " " + name + " " + experience + " exp " + money + " gold killed by " +
		 call_other(attacker_ob, "query_real_name", 0) + ".\n");
       else
           {
        log_file("DEATHS", ctime() +" "+ name +" "+ experience +" exp "+ money +" gold - killer unknown.\n");
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
 if(query_ip_number(this_object()))
 {
  object grr;
  grr=clone_object("/obj/user/keep_dfix");
  move_object(grr, this_object());
  grr->do_it();
 }
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

/* Changed from below - Rumplemintz */
varargs string query_name(status real) {
  return (real)
       ? lower_case(name)
       : is_invis > SOMEONE 
       ? "Someone"
       : (this_object()->query_ghost())
       ? NAME_OF_GHOST
       : (name)
       ? capitalize(name)
       : "";
}

string query_real_name() { return ((name) ? lower_case(name) :0); }
string query_cap_name() { return capitalize(query_name()); }

/*
query_name() {
  if (ghost)
    return NAME_OF_GHOST;
  return cap_name;
}


query_real_name() {
  return name;
}

*/

query_vis_name() { /* Rumplemintz */
  return vis_name;
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
    if (this_object()->is_player()) { 
      write("extra_level: "+this_object()->query_extra_level()+ "\n");
      write("prestige_level: "+this_object()->query_prestige_level()+ "\n");
      write("score: "+this_object()->query_prestige_score()+ "\n");
    }
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
    /*
    if(this_object()->is_npc()){
      */
       if(Armors){
          write("Armor:\n");
          armors = keys(Armors);
          for(i=0;i<sizeof(armors);i++){
             if(Armors[armors[i]] != 0){
                write("   " + object_name(armors[i]) + "\n");
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
                write("   " + object_name(weapons[i]) + "\n");
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
      /*
    }
    */
    write("armor class: " + this_object()->query_ac());
    if (head_armor)
	write("\narmor: " + call_other(head_armor, "rec_short", 0));
    write("\nweapon class: "+this_object()->query_wc());
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
  write("room: " + object_name(yjy) + "\n");
  if (yjyj) write("Room's room: " + object_name(yjyj) + "\n");
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


stop_wielding() {
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
    RemoveWeapon(name_of_weapon);
    name_of_weapon = 0;
/* disabled for dtypes <illarion>
    weapon_class = WEAPON_CLASS_OF_HANDS;
    end of disabled */
}

stop_wearing(object name, string type, silent) {

#if 0 /* Rumplemintz */
  /* For paladins.  Removes paladin_shield */
   if(name->query_paladin_shield())
      paladin_shield = 0;
#endif

   if(RemoveArmor(name))
      armors -= ({ type });
   if(!silent)
     {
      say(cap_name + " removes "+ call_other(name, "query_name", 0) +".\n");
   write("Ok.\n");
    }
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

#if 0  /* Rumplemintz */
/* For paladins.  Removes paladin_shield */
   if(present(name, this_object())->query_paladin_shield())
     paladin_shield = 0;
#endif

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
  sscanf (object_name(this_object()), "%s#%s", ab, bc);
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

/* Added for dtypes   <illarion>
 * Argument: string
 * Returns : string
 * Checks to make sure a string is a valid damage type */
check_type(style) {
  string cat,subcat;
  if(style) {
    if(sscanf(style,"%s|%s",cat,subcat)!=2) {
      if(style!="magical") style="physical";
    } else if(cat!="other") style="physical";
  } else style="physical";
  return style;
}

/* Added for dtypes.  <illarion>
 * Argument: mixed (should be an int or an array of ({int,dtype string})
 * Returns:  array of ({int,dtype string})
 * Allows weapon_hit and other bonuses to have dtypes or to just 
 * return an int like they do now */
mixed *get_dam_and_type(mixed arg) {
  if(intp(arg))
    return ({arg,"physical"});
  else if(pointerp(arg) && sizeof(arg)>1)
    return ({arg[0], check_type(arg[1])});
  else /* hopelessly fubarred at this point */
    return ({0,"physical"});
}
/* Added for dtypes <illarion>
 * Arguments: array of ints, array of dtype strings
 * Returns ({array of ints, array of dtype strings})
 * combines damages for the same dtypes together */
merge_dtypes(damarr,typearr) {
  int i,n,s;
  int *fdam;
  string *ftype;
  fdam=({});
  ftype=({});
  s=sizeof(damarr);
  for(i=0;i<s;i++) {
    n=member_array(typearr[i],ftype);
    if(n!=-1)
      fdam[n]+=damarr[i];
    else {
      if(damarr[i]!=0) {
        fdam+=({damarr[i]});
        ftype+=({typearr[i]});
      }
    }
  }
  return ({fdam,ftype}); 
}

/* Create damage modifiers array from WeaponBonuses 
   these bonuses/penalties are applied to all registered
   weapons
*/

create_bonus_arrays() {
  object *weps;
  int s,s2,i;
  mixed *dtmp;
  int *moddamarr;
  string *modtypearr;
  moddamarr=({});
  modtypearr=({});
  if(WeaponBonuses) {
    weps=m_indices(WeaponBonuses);
    s=sizeof(weps);
    while(s--) {
      if(weps[s] && WeaponBonuses[weps[s]]) {
        dtmp=WeaponBonuses[weps[s]];
        s2=sizeof(dtmp);
        for(i=0;i<s2;i+=3) {
          modtypearr+=({check_type(dtmp[i])});
          moddamarr+=({dtmp[i+1]+(dtmp[i+2]?call_other(weps[s],dtmp[i+2],attacker_ob):0)});
        }
      }
    }
  }
  return ({moddamarr,modtypearr});
}

/* End of damage modifer creation */

resolve_emote(str,ob1,ob2)
{
  return call_other(EMOTE_OB, "parse_emote",str,ob1,ob2);
}


/*
 * Return true if there still is a fight.
 */
attack()
{
  int tmp, tmpk;
  int whit,weap_tmp;
#if 0 /* Rumplemintz */
  int pal_tmp;
#endif
  int knt_tmp,knt_tmp2;
  int intox_no;
  int pres_wc;
  string name_alt_at;
  string name_of_attacker;

#if 1 /* Rumplemintz - rangers use this also */
  object pro_object;     /* paladin object */
#endif
  object templar_ob;     /* templar object */
  object gen_ob;         /* generic object */

/* Extra Vars for dtypes <illarion>*/
  int *damarr,moddamarr;
  string *typearr,modtypearr;
  mixed *dtmp;
  int s,s2;
  object *weps;
  int i;
  int wep_tot;
  int tmp2;
/* End of extra vars     <illarion>*/
    
#if 0 /* Rumplemintz */
  pal_tmp = 0;
#endif
  knt_tmp = 0;
  knt_tmp2 = 0;
  if(this_object()->query_block_attack()){return;}
  if(present("block_attack_object")) return;
  if(is_npc) h_check = 0;
  hcnum = 1;
  if(!is_npc) {
    if(level < EXPLORE && this_object()->query_invis()) {
        if(random(100) < 20) invs_counter();
    }
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
  if(already_fight) 
    return 0;
  if(!attacker_ob) {
    spell_cost = 0;
    spell_dtype= 0;
    return 0;
  }
/* fight_area pk check */
  if(!is_npc && attacker_ob->is_player())
    if(!this_object()->query_pl_k() || !attacker_ob->query_pl_k())
      if(!this_object()->check_fight_area()){
        if(!attacker_ob->check_fight_area()) 
          attacker_ob->clear_fight_area();
        attacker_ob =0;
        alt_attacker_ob=0;
        return 0;
      }
 /* Stop disconnected player from fighting */
  if(!is_npc && !call_other(this_object(), "query_interactive",0)) {
    attacker_ob =0;
    return 0;
  }
  /* stop monster from fighting disconnected player */
if(is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0)) {
  if(dc_stop_c != attacker_ob) {
    dc_stop_c = attacker_ob;
    remove_call_out("clear_dc_stop");
    call_out("clear_dc_stop", 900);
    stop_fight();
  }
}
  /* stop player from fighting disconnected player */
  if(!is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
    stop_fight();
  /* stop player from fighting a likely dc'd player */
/*
  if(attacker_ob->is_player())
    if(!is_npc && query_idle(attacker_ob) > 600 )
      stop_fight();
*/
  /* stop monster from attacking likely dc'd player */
/*
  if(attacker_ob->is_player())
    if (is_npc && query_idle(attacker_ob) > 600)
      stop_fight();
*/
  if(attacker_ob)
    name_of_attacker = call_other(attacker_ob, "query_name", 0);
  if((!name_of_attacker)
     || (name_of_attacker == NAME_OF_GHOST)
     || (environment(attacker_ob) != environment(this_object()))) {
    if(!hunter && name_of_attacker && attacker_ob &&
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
    if(attack() && attacker_ob) {
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
  
  damarr=({});
  typearr=({});

#if 0 /* Rumplemintz */
/******************************/
/*  BEGIN PALADIN ADDITIONS   */
/******************************/
#else /* Ranger guild uses this part .... */
  if(this_player())
    pro_object = present("pro_object", this_player());
  if(pro_object && name_of_weapon && name_of_weapon->query_pro_weapon()) {
    /* disabled as a possible cause of lag
    dtmp=get_dam_and_type(name_of_weapon->proficiency_hit(pro_object));
      if(dtmp[0]) {
        damarr+=({dtmp[0]});
        typearr+=({dtmp[1]});
      }
      */
    if((dtmp=name_of_weapon->proficiency_hit(pro_object))) {
      damarr+=({dtmp});
      typearr+=({"physical"});
    }
  }
#endif

#if 0
  if(second_weapon && pro_object && pro_object->query_combat_method() == 3) {
    /* disabled as possible cause of lag
    dtmp=get_dam_and_type(call_other(second_weapon, "dual_hit", pro_object));
    if(dtmp[0]) {
      damarr+=({dtmp[0]});
      typearr+=({dtmp[1]});
     }
     */
    if((dtmp=second_weapon->dual_hit(pro_object))) {
      damarr+=({dtmp});
      typearr+=({"physical"});
    }
   }
/******************************/
/*   END PALADIN ADDITIONS    */
/******************************/
#endif

/******************************/
/* BEGIN GENERIC WC ADDITION  */
/******************************/
  if((gen_ob = this_player()) && (gen_ob = present("generic_wc_bonus", gen_ob)))
    while(gen_ob) {
      object ob;
      ob = next_inventory(gen_ob);
      /* disabled as a possible cause of lag
      dtmp=get_dam_and_type(gen_ob->gen_wc_bonus(attacker_ob));
      if(dtmp[0]) {
        damarr+=({dtmp[0]});
        typearr+=({dtmp[1]});
      }
      */
      if((dtmp=gen_ob->gen_wc_bonus(attacker_ob))) {
        damarr+=({dtmp});
        typearr+=({"physical"});
      }
      gen_ob = ob;
    }
/******************************/
/*   END GENERIC WC ADDITION  */
/******************************/

/*****************************************************************
 * BEGIN PRESTIGE WC ADDITION 
 ****************************************************************/
  pres_wc = this_object()->query_prestige_skill( "WC" );
  if( pres_wc > random( pres_wc + 2 ) ) {
    pres_wc = 3 + pres_wc/5;
    damarr+=({ pres_wc });
    typearr+=({"other|prestige"});
    tell_object(this_object(), "Your prestige aura "+HIY+"glows"+NORM+" and "+CYN+"pulsates"+NORM+" as it "+HIBLK+"explodes"+NORM+" from your body\n\
and flows into your "+ (name_of_weapon ? name_of_weapon->query_name() : "attack" )+" as you lash out with "+HIR+"Ungodly Rage"+NORM+".\n" );
    tell_room(environment(), (string)this_player()->query_name()+"'s "+ (name_of_weapon ? name_of_weapon->query_name() : "attack" )+CYN+" pulsates"+NORM+" as "+this_player()->query_pronoun()+" attacks with "+HIR+"Ungodly Rage"+NORM+".\n", ({ this_object() }));
  }
/******************************/
/*  END PRESTIGE WC ADDITION  */
/******************************/

/******************************/
/*   TEMPLAR ADDITIONS        */
/******************************/
  if(this_player() && !is_npc && this_player()->query_guild_name()=="Knights Templar" &&
     (templar_ob=present("KnightTemplar", this_player()))) {
    if(name_of_weapon && templar_ob) {
       knt_tmp = templar_ob->skill_check(name_of_weapon);
       knt_tmp2 = 2*knt_tmp/3;
       knt_tmp = random(knt_tmp - knt_tmp2);
       if(knt_tmp2) {
         damarr+=({knt_tmp2});
         typearr+=({"physical"});
       }
     }
     if(mounted) {
       int mnt,mnt2;
       mnt = templar_ob->query_skill("horse");
       mnt2=random(mnt/2);
       if(mnt2) {
         damarr+=({mnt2});
         typearr+=({"physical"});
       }
       if(name=="numberthree") write("mounted bonus ="+mnt2+">>>"+mnt+"\n");
     }
   }
/******************************/
/*   END TEMPLAR SECTION      */
/******************************/

/* Black Circle bonus */
  if(this_player() && !is_npc && this_player()->query_guild_name()=="black circle") {
    if(name == "verte") write("BCM BONUS\n");
    templar_ob = present("dark_circle", this_player());
    if(name_of_weapon && templar_ob && (mounted) && (mounted->is_drakyr())) {
      if(name == "verte") write("IS DRAKYR BONUS\n");
        dtmp=random(((int)this_player()->query_attrib("dex")/5)+((int)this_player()->query_attrib("str")/5));
        if(dtmp) {
          damarr+=({dtmp});
          typearr+=({"physical"});  
        }
    }
  }
/* End Black Circle Bonus */

  dtmp=create_bonus_arrays();
  moddamarr=dtmp[0];
  modtypearr=dtmp[1];

/* Damage for primary weapon, either wielded or NPCs <illarion> */
  if(this_object())

/* Templar */
  if( (templar_ob = present("no_weapon_attack",this_object()))) {
    dtmp = templar_ob->do_no_attack_message(attacker_ob);
    if(!dtmp) {
      tell_object(this_object(),"You are too busy to attack.\n");
    }
  } /* End Templar */
  else if(Weapons && sizeof(Weapons)) {
    weps=m_indices(Weapons);
    if(name_of_weapon && member_array(name_of_weapon,weps)!=-1) {
      weps-=({name_of_weapon});
      dtmp=Weapons[name_of_weapon];
      s2=sizeof(dtmp);
      knt_tmp=0;
      knt_tmp2=0;
      for(i=0;i<s2;i+=3) {
        typearr+=({dtmp[i]});
        if(is_npc && !this_object()->is_kid() && dtmp[i]=="physical") {
          if(attacker_ob)
          damarr+=({(dtmp[i+2]?call_other(name_of_weapon,dtmp[i+2],attacker_ob):0)});
          knt_tmp+=dtmp[i+1];
        } else {
          if(attacker_ob)
            if(name_of_weapon)
              wep_tot=dtmp[i+1]+(dtmp[i+2]?call_other(name_of_weapon,dtmp[i+2],attacker_ob):0);
          if((!is_npc && level < 20) || this_object()->is_kid()) {
            if(wep_tot>25) {
              if(wep_tot>30)
                wep_tot=20+random(5);
              else
                wep_tot=25;
              if(this_object()->is_testchar())
                write("Testchar Info: Damage lowered to "+wep_tot+"\n");
            }
          }
#if 0 /* Rumplemintz */
          pal_tmp+=wep_tot; /* This is passed to the weapon for use in eff_wc */
#endif
          damarr+=({wep_tot});
        }
      }
      /* weapon_enchantment additions */
  if(name_of_weapon)
      dtmp=name_of_weapon->get_enchantment_damage(attacker_ob);
      if(sizeof(dtmp)==2) {
        damarr+=dtmp[0];
        typearr+=dtmp[1];
      }
    } /* NPCs other than kids will usually use themselves as their weapon */
    if(is_npc && !this_object()->is_kid() && member_array(this_object(),weps)!=-1) {
      weps-=({this_object()});
      dtmp=Weapons[this_object()];
      s2=sizeof(dtmp);
      for(i=0;i<s2;i+=3) {
        typearr+=({dtmp[i]});
        if(dtmp[i]=="physical") {
          damarr+({ (dtmp[i+2]?call_other(this_object(),dtmp[i+2],attacker_ob):0) });
          knt_tmp2+=dtmp[i+1];
        } else {
          damarr+=({dtmp[i+1]+(dtmp[i+2]?call_other(this_object(),dtmp[i+2],attacker_ob):0)});
        }
      }
    }
    /* Backwards compatibility: for monsters with weapons wielded and a natural wc, only
       the higher physical damage is used.  However, any specicial function for the wep
       or the monster itself is always called and any return used.
     */
    if(is_npc && (knt_tmp || knt_tmp2)) {
      typearr+=({"physical"});
      damarr+=({knt_tmp>knt_tmp2?knt_tmp:knt_tmp2});
      knt_tmp=0;
      knt_tmp2=0;
    }
  } else if(is_npc) {
    damarr+=({weapon_class});
    typearr+=({"physical"});
  } else {
    damarr+=({WEAPON_CLASS_OF_HANDS});
    typearr+=({"physical"});
  }
/* End of damage for Primary weapon/NPC "hands" weapon */

  if(alt_attacker_ob)
    if(!alt_attacker_ob->query_name()) 
      alt_attacker_ob = attacker_ob;
  if(alt_attacker_ob != attacker_ob)
    hit_pet_new(damarr,typearr);
  if(attacker_ob) {
    dtmp=merge_dtypes(damarr,typearr);  /* Combine like damage types */
    damarr=dtmp[0];
    typearr=dtmp[1];
    s=sizeof(damarr);
    while(s--) {   /* Randomize all this damage */
      if(typearr[s]=="physical")
        damarr[s]=random(damarr[s]-intox_no); /*drunk drawback*/
      else
        damarr[s]=random(damarr[s]);
    }
    if(knt_tmp) {
     damarr += ({knt_tmp});
     typearr += ({"physical"});
    }
    if(spell_dam) {
     damarr += ({spell_dam});
     typearr += ({check_type(spell_dtype)});
    }
    /* Add bonuses/penalties from WeaponBonuses, if any, and merge
      them again */
    dtmp=merge_dtypes(damarr+moddamarr,typearr+modtypearr);
    damarr=dtmp[0];
    typearr=dtmp[1];
    spell_dtype=0; /* reset this so a default spell_dtype isn't set */
    tmp = attacker_ob->do_damage(damarr,typearr);
   } else
    tmp = 0;
/* Hits and damage for other registered weapons */
  if(sizeof(weps)) {
    string *dmess;
    tmp2=0;
    s=sizeof(weps);
    while(s-- && attacker_ob &&
          call_other(attacker_ob, "query_name", 0) != NAME_OF_GHOST)
      if(weps[s] && Weapons[weps[s]]) {
        typearr=({});
        damarr=({});
        dtmp=Weapons[weps[s]];
        s2=sizeof(dtmp);
        wep_tot=0;
        for(i=0;i<s2;i+=3) {
          typearr+=({dtmp[i]});
          tmp2=dtmp[i+1]+(dtmp[i+2]?call_other(weps[s],dtmp[i+2],attacker_ob):0);
          wep_tot+=tmp2;
          damarr+=({tmp2});
        }
        /* weapon enchantment info */
        dtmp=weps[s]->get_enchantment_damage(attacker_ob);
        if(sizeof(dtmp)==2) {
          damarr+=dtmp[0];
          typearr+=dtmp[1];
        }
        /* merge and randomize damage */
        dtmp=merge_dtypes(damarr,typearr);
        damarr=dtmp[0];
        typearr=dtmp[1];
        s2=sizeof(damarr);
        while(s2--)
          damarr[s2]=random(damarr[s2]);
        /* add bonusus, which aren't auto-randomized */
        dtmp=merge_dtypes(damarr+moddamarr,typearr+modtypearr);
        /** Not sure why this is needed but it seems to be -- Gnar **/
        if( attacker_ob )
          tmp2=attacker_ob->do_damage(dtmp[0],dtmp[1]);
        if(attacker_ob && !weps[s]->query_silent_damage() && 
           !present("no_msg_hit", this_object())) {
          if(!tmp2) {
            if(!is_npc)
              weps[s]->count_misses();
            dmess=({"","missed"});
          } else {
            if(!is_npc)
              weps[s]->count_hit_made(wep_tot);
            dmess=weps[s]->query_message_hit(tmp2);
          }
          if(!is_npc && weps[s]->query_wear() > 120 && random(4450000/weps[s]->query_wear()) < 10)
            weps[s]->weapon_breaks();
          if(!dmess) 
            dmess=query_message_hit(tmp2);
          if(sizeof(dmess)==3) {
            tell_object(this_object(), resolve_emote(dmess[0], this_object(), attacker_ob));
            tell_object(attacker_ob,  resolve_emote(dmess[1], this_object(), attacker_ob));
            if(query_invis() < INVIS_ACTION)
              tell_room(environment(), resolve_emote(dmess[2], this_object(), attacker_ob), ({ this_object(), attacker_ob }));
          } else {
            tell_object(this_object(),"You "+dmess[1]+" "+name_of_attacker+dmess[0]+".\n");
            if(attacker_ob && query_invis() >= INVIS_ACTION) {
              tell_object(attacker_ob,cap_name+" "+dmess[1]+" you"+dmess[0]+".\n");
            } else if(environment())
              tell_room(environment(),
                cap_name+" "+dmess[1]+" "+name_of_attacker + dmess[0] + ".\n", ({this_object()}));
          }
        }
      }
  }
/* End of hits and damage for other registered weapons */
  spell_cost=0;
  already_fight=1;
  if(this_object() && tmp == 0) {
    if(!present("no_msg_hit", this_object())) {
      tell_object(this_object(), "You missed.\n");
      checked_say(cap_name + " missed " + name_of_attacker + ".\n");
    }
    if(!is_npc) {

#if 0 /* Rumplemintz */
      if(second_weapon && pro_object && pro_object->query_combat_method() == 3)
        second_weapon->count_misses();
#endif

      if(name_of_weapon) {
        name_of_weapon->count_misses();
        if(name_of_weapon->query_wear() > 120 
           && random(4450000/name_of_weapon->query_wear()) < 10)
          name_of_weapon->weapon_breaks();
      }
    }
    spell_dam=0;
    return 1;
  }
  if(!is_npc && attacker_ob && !attacker_ob->query_no_exp_value())
    this_object()->add_exp(tmp);
  tmp -= spell_dam;
  spell_dam=0;
  /* Does the enemy still live ? */
  if(attacker_ob && call_other(attacker_ob, "query_name", 0) != NAME_OF_GHOST) {
    string *mess;
    if(this_object() && !present("no_msg_hit", this_object())) {
      if(name_of_weapon) 
        mess = name_of_weapon->query_message_hit(tmp); 
      if(!mess)
        mess = query_message_hit(tmp);
      if(sizeof(mess)==3) {
        tell_object(this_object(), resolve_emote(mess[0], this_object(), attacker_ob));
        tell_object(attacker_ob,  resolve_emote(mess[1], this_object(), attacker_ob));
        if(query_invis() < INVIS_ACTION)
          tell_room(environment(), resolve_emote(mess[2], this_object(), attacker_ob), ({ this_object(), attacker_ob }));
      } else {
        tell_object(this_object(), "You " + mess[1] + " " + name_of_attacker +
                  mess[0] + ".\n");
        if(query_invis() >= INVIS_ACTION)
          tell_object(attacker_ob, cap_name + " " + mess[1] + " you" + mess[0] +
                    ".\n");
      checked_say(cap_name + " " + mess[1] + " " + name_of_attacker + mess[0] +
                  ".\n");
      }
      
    }
    if(!is_npc) {
#if 0 /* Rumplemintz */
      if(second_weapon && pro_object
         && pro_object->query_combat_method() == 3)
        second_weapon->count_hit_made(pal_tmp);
      if(name_of_weapon) {
        name_of_weapon->count_hit_made(pal_tmp);
        if(name_of_weapon->query_wear() > 120 
           && random(4500000/name_of_weapon->query_wear()) < 10)
          name_of_weapon->weapon_breaks();
#else
      if (name_of_weapon) {
        /* name_of_weapon->count_misses(); ill 2015.08.02 */
        name_of_weapon->count_hit_made(); 
        if (name_of_weapon->query_wear() > 120
            && random(4500000/name_of_weapon->query_wear()) < 10)
          name_of_weapon->weapon_breaks();
#endif
      }
    }
    return 1;
  }
  if(this_object())
    tell_object(this_object(), "You killed " + name_of_attacker + ".\n");
  attacker_ob = alt_attacker_ob;
  alt_attacker_ob = 0;
  if(attacker_ob)
    return 1;
  return 0;
}

attack_old()
{
  int tmp;
  string mfight,thingone,thingtwo;
#if 0 /* Rumplemintz */
  int pal_tmp;
#endif
  int tmpk,whit,weap_tmp;
  int knt_tmp,knt_tmp2;
  int intox_no;
  string name_alt_at;
  string name_of_attacker;
#if 0 /* Rumplemintz */
  object pro_object;     /* paladin object */
#endif
  object templar_ob;    /* templar object */
    object gen_ob;         /* generic object */
#if 0 /* Rumplemintz */
  pal_tmp = 0;
#endif
  knt_tmp = 0;
  knt_tmp2 = 0;
  if(is_npc) h_check = 0;
  hcnum = 1;
  if (!is_npc) {
    if(level < EXPLORE && this_object()->query_invis()) {
        if(random(100) < 20) invs_counter();
      }
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
   {
     if(dc_stop_c != attacker_ob) {
       dc_stop_c = attacker_ob;
       remove_call_out("clear_dc_stop");
       call_out("clear_dc_stop", 900);
       stop_fight();
     }
   }
  /* stop player from fighting disconnected player */
if(!is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
  stop_fight();
  /* stop player from fighting a likely dc'd player */
/*
if(attacker_ob->is_player())
  if(!is_npc && query_idle(attacker_ob) > 600 )
   stop_fight();
*/
  /* stop monster from attacking likely dc'd player */
/*
if(attacker_ob->is_player())
  if (is_npc && query_idle(attacker_ob) > 600)
   stop_fight();
*/
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
  if(!is_npc && (this_object()) && (this_object()->query_level() < 20) && (1*weap_tmp > 30))
   weap_tmp = 10 + random(12);
   if(!is_npc && this_object()->query_level() <20 && weap_tmp > 24){
	weap_tmp = 24;
     }
  if(this_object())
   if(this_object()->is_kid() && weap_tmp > 15) weap_tmp = 15;
   }
#if 0 /* Rumplemintz */
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
#endif

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

/* Verte Black Circle */
    if(this_player())
    if(!is_npc && this_player()->query_guild_name()=="black circle") {
       if(name == "verte") write("BCM BONUS\n");
      templar_ob = present("dark_circle", this_player());
   if(name_of_weapon && templar_ob && (mounted) && (mounted->is_drakyr())) {
      if(name == "verte") write("IS DRAKYR BONUS\n");
        weap_tmp += random(((int)this_player()->query_attrib("dex")/5)+((int)this_player()->query_attrib("str")/5));
   }
  }
/* End Black Circle */

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

#if 0 /* Rumplemintz */
   if(!is_npc && second_weapon && pro_object &&
                 pro_object->query_combat_method() == 3)
     second_weapon->count_misses();
#endif

   if(!is_npc && name_of_weapon) {
    name_of_weapon->count_misses();
   if(name_of_weapon->query_wear() > 120)
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
/* Took out the underline on the name_of_attacker -- Rumplemintz
 * Jan 7,2010 */
    tell_object(attacker_ob, cap_name+" "+mess[1]+" you"+mess[0]+".\n");
    checked_say(cap_name+" "+mess[1]+" "+name_of_attacker+mess[0]+".\n");
   already_fight = 1;
   }
#if 0 /* Rumplemintz */
   if(!is_npc && second_weapon && pro_object &&
                 pro_object->query_combat_method() == 3)
     second_weapon->count_hit_made(pal_tmp);
   if(name_of_weapon && !is_npc) {
   name_of_weapon->count_hit_made(pal_tmp);
   if(!is_npc && name_of_weapon->query_wear() > 120)
   {
  if(!is_npc && random(4500000/name_of_weapon->query_wear()) < 10)
  name_of_weapon->weapon_breaks();
   }
   }
#else
   if (name_of_weapon) {
        name_of_weapon->count_misses();
        if (name_of_weapon->query_wear() > 120
            && random(4500000/name_of_weapon->query_wear()) < 10)
          name_of_weapon->weapon_breaks();
   }
#endif
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
    log_file("ADD_MONEY",
             ctime() + " " + object_name(environment(this_object())) + " " +
             name + " dropped " + tmp + " coins\n");
  }
}

/* Wield a weapon. */
/* Modified for dtypes <illarion> */
wield(w,silently,params) {
    int x;
    if(!w) return;
    if (name_of_weapon)
	    stop_wielding();
    name_of_weapon = w;
    if(params) {
      RegisterWeapon(w,params);
    } else { /* If no params are passed, make some up */
      x = call_other(w, "weapon_class", 0);
      RegisterWeapon(w, ({"physical", x, "hit"}));
    }
    if(!silently) {
    say(cap_name + " wields " + call_other(w, "query_name", 0) + ".\n");
    write("Ok.\n");
    }
}
/* End of mod */

/* Wear some armor. */
wear(a, silently, type, mixed *params) {
   
   if(armors){
      if(member_array(type,armors) != -1) return 0;
   }
   
#if 0 /* Rumplemintz */   
   /* For use with paladins.  Sets paladin_shield if worn */
      if(a->query_paladin_shield())
      paladin_shield = a;
#endif

   head_armor = a;
   
   if(!armors) armors = ({ type });
   else armors += ({ type });
   RegisterArmor(a, params);
   
   
   /* Calculate new ac */
   
   if(!silently){    
      say(cap_name + " wears " + call_other(a, "query_name", 0) + ".\n");
   }
   write("Ok.\n");
   return this_object();
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

#if 0 /* Rumplemintz */
/* For use with paladins.  Sets paladin_shield if worn */
   if(a->query_paladin_shield())
     paladin_shield = a;
#endif

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
int old_hp, old_sp;
  if(dieing) return;
  if (!h)return;
  thypl = this_player();
  old_hp = hit_point;
  old_sp = spell_points;
  if(thypl)
   if(this_object()->query_interactive())
     if (level < EXPLORE && thypl->query_interactive() && thypl != this_object()) {
       if(thypl->query_level() > EXPLORE)
         log_file("POINTS", name +" heal_self "+ h +" by "+thypl->query_real_name() +" "+ ctime() +"\n");
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
        if(((LIV_INFUSE_LIMIT) < INF_MIN ||liv_infuse >INF_MAX) && h > 0) {
           int blah;
           blah = (LIV_INFUSE_LIMIT - liv_infuse)/3;
           tell_object(thypl,cap_name+" must wait before absorbing "+h+" healing.\n");
           if(liv_infuse < INF_MAX && blah > 0 && h > 0)
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
    if(h < 0)
    {
      object x;
      dam_taken_this_round += (-h);
      if(x=present("damage_report_object", this_object()))
        x->report_damage(-h, previous_object());
    }
    hit_point += h;
    if (hit_point > max_hp) hit_point = max_hp;
    spell_points += h;
    if (spell_points > max_spell) spell_points = max_spell;
   if(!attacker_ob && h < 0) hit_player(1);
   if(hit_point < 0) hit_point = 0;
   if( old_hp != hit_point || old_sp != spell_points )
     this_object()->set_auto_monitor();
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
void add_money(int m) {
    int diff,flag;
    if (this_player() && this_player() != this_object() &&
      query_ip_number(this_player()) && query_ip_number(this_object()) &&
      call_other(this_player(), "query_level",0) > 20 &&
      level < 20)
      {
        log_file("ADD_MONEY", object_name(environment(this_object())));

        log_file("ADD_MONEY", ctime() +" "+ name +"("+ level +
		") " + m + " money by " + this_player()->query_real_name() +
		"(" + this_player()->query_level() + ")\n");
	}
  if(m < 0 || money + m <= MAXCOINS) {
    money = money + m;
    flag = 1;
  }
  if(this_player() && this_player()!=this_object()) {
  if(money >= MAXCOINS && this_player() && m > 0 && !flag)
    if(this_player()->is_player()) {
       flag = 1;
       this_player()->add_money(m);
       tell_object(this_player(), cap_name+" is maxed. You keep your coins.\n");
    }
  if(money + m > MAXCOINS && this_player() && m > 0 && !flag)
    if(this_player()->is_player()) {
      diff=MAXCOINS - money;
      flag=1;
      money = money + diff;
      this_player()->add_money(m-diff);
      tell_object(this_player(), cap_name+" maxes out, and takes only "+
       diff+" coins, you keep the rest.\n");
    }
  }
  if(this_player() == this_object() && !flag) {
    money = money + m;
    if(money > MAXCOINS)
    {
      object geld;
      geld = clone_object("/obj/money");
      geld->set_money(money - MAXCOINS);
      move_object(geld, this_object());
      money = MAXCOINS;
    }
    flag = 1;
  }
  if(!flag) {
    money = money + m;
    if(money > MAXCOINS)
    {
      object gld;
      gld = clone_object("/obj/money");
      gld->set_money(money - MAXCOINS);
      move_object(gld, this_object());
      money = MAXCOINS;
    }
  }
  if (!query_npc() && level <= 19)
    add_worth(m);
}

int query_money() {
  return money;
}

int query_exp() {
  return experience;
}

int query_frog() {
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
  if(!this_object()) return;
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
set_current_room(arg) {
 current_room = arg;
}

checked_say(str) {
  if (query_invis() >= INVIS_ACTION) return;
  say(str);
}

query_invis(num,enum) {
  if(num && enum && num < EXPLORE) {
    if(this_object()->query_total_level() <= num+enum)
      return -is_invis;
    else return is_invis;
  }
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
clear_dc_stop() {
  dc_stop_c = 0;
  return 1;
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
/* Added the ! check - Rumplemintz */
    if (!gender || gender == "creature")
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
  if(Weapons) {
    int total_phys,size1,size2,x,wep_dam,nat_dam;
    object *weps;
    mixed *params;
    weps=keys(Weapons);
    size1=sizeof(weps);
    while(size1--)
      if(weps[size1] && (params=Weapons[weps[size1]])) {
        size2=sizeof(params);
        for(x=0;x<size2;x+=3)
          if(params[x]=="physical") {
            if(is_npc) {
              if(weps[size1]==name_of_weapon)
                wep_dam+=params[x+1];
              else if(weps[size1] == this_object())
                nat_dam+=params[x+1];
              else
                total_phys+=params[x+1];
            
            } else 
              total_phys+=params[x+1];
          }
      }
    return total_phys+(wep_dam>nat_dam?wep_dam:nat_dam);
  } else
    return weapon_class;
}
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
  la = random(10);
i=i+1;
  if(i>70) return 1;
  if (la == 10) return 1;
  if (la == 8) las = "charisma";
  if (la == 9) las = "dexerity";
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
    if(rm_msg) { rsf =1; say(rm_msg, ob); }
     spell_name = name;
    spell_dam = dam;
     spell_cost = cost;
     attacker_ob =ob;
}

/* Addition for dtypes <illarion> */
set_spell_dtype(style) {
  spell_dtype=check_type(style);
}
/* End Addition */

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
hit_pet_new(damarr,typearr) {
  int dam_done;
  int tar_name;
  int s;
  if(is_npc && alt_attacker_ob && alt_attacker_ob->is_pet() 
     && environment () && present(alt_attacker_ob,environment()) 
     && random(100) < 37) {
    tar_name=alt_attacker_ob->query_name();
    s=sizeof(damarr);
    while(s--)
      damarr[s]=random(damarr[s]);
    dam_done=alt_attacker_ob->do_damage(damarr,typearr);
    if(!present("no_msg_hit",this_object())) {
      string *mess;
      if(dam_done) {
        if(name_of_weapon) 
          mess=name_of_weapon->query_message_hit(dam_done);
        if(!mess)
          mess=query_message_hit(dam_done);
      } else {
        mess=({"","missed"});
      }
      if(environment())
        tell_room(environment(),
          cap_name+" "+mess[1]+" "+tar_name+mess[0]+" with a side attack.\n",
          alt_attacker_ob?({alt_attacker_ob,this_object()}):({this_object()}));
    }
  }
}
/* end of modified hit_pet <illarion> */

query_name_of_weapon() {return name_of_weapon;}
query_message_hit(int tmp) {
   string *mess;
  object bwo;
  if(bwo=present("black_willow_object", this_object()))
    return (string *)bwo->query_message_hit(tmp);

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
query_spell_dtype() { return spell_dtype; }
query_spell_name() { return spell_name; }
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
  int hp_diff,tmp_hp,x;

/* up to 2000 hp is weighted normally
   for each additional 1000hp 10 is added
   to the divisor (/60, /70, etc)
*/
   tmp_hp = max_hp + hp_bonus;
   x = 1;
   hp_factor = 0;
   while(tmp_hp>2000) {
     hp_diff = tmp_hp-2000;
     if(hp_diff > 1000)
       hp_diff = 1000;
     hp_factor += hp_diff / (50+10*x);
     x++;
     tmp_hp -= hp_diff;
   }
   hp_factor += tmp_hp/50;
    
/* This gets WAY too inflated for values > 1000
  hp_factor = (max_hp / 50) + 1;
  hp_factor += hp_bonus / 50;
  -- Gnar moved bonus to the calc above by adding to max_hp
*/

  wc_factor = this_object()->query_damage_potential();
  if(!wc_factor)
    wc_factor = this_object()->query_wc();
  wc_factor += this_object()->query_spell_chance() * this_object()->query_spell_dam()/ 200;
  wc_factor += this_object()->query_spell_exp();
  wc_factor += wc_bonus;

  ac_factor = this_object()->query_defense_potential();
  if(!ac_factor)
    ac_factor = this_object()->query_ac();
   if(this_object()->query_heal_rate() > 0 && this_object()->query_heal_intv() > 0)
      ac_factor += (this_object()->query_heal_rate() * 3) / this_object()->query_heal_intv();
  ac_factor += ac_bonus;

  exp_worth = 1;
  if(hp_factor) exp_worth*= hp_factor;
  if(wc_factor) exp_worth*= wc_factor;
  if(ac_factor) exp_worth*= ac_factor;
  if(exp_worth < 0) {
    log_file("NEG_EXP", ctime() + " " + object_name(this_object()) + "\n");
    exp_worth=0;
  }


/* 06/02/06 Earwax: put this to make doing double/triple xp days easy. */
#ifdef DOUBLEXPDAY
  exp_worth *= 2;
#else
#ifdef TRIPLEXPDAY
  exp_worth *= 3;
#endif
#endif

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
    int i,s;
    mixed *k;
    mapping n;

    if(!Weapons) Weapons = ([ ]);

    s = sizeof(k = keys(Weapons));
    n = ([ ]);

    /** Changing order returned - Gnar **/
    for( i=0; i < s; i++ ) {
      if(k[i] && objectp(k[i]))
        n[k[i]] = Weapons[k[i]];
    }
/*
    while(s --)
      if(k[s] && objectp(k[s]))
        n[k[s]] = Weapons[k[s]];
*/
    return n;
}

toggle_already_fight(x) { already_fight ^= 1; }

is_dieing() { return dieing; }

add_hp(x) { return this_object()->add_hit_point(x); }
/* 03/24/06 Earwax: added this so it works vs mobs as well */
add_hit_point(arg) {
  int old_hp;

  old_hp = hit_point;
  if(arg < 0)
  {
    object x;
    dam_taken_this_round += (-arg);
    if(x=present("damage_report_object", this_object()))
      x->report_damage(-arg, previous_object());
  }
  hit_point += arg;
  if (hit_point > max_hp) hit_point = max_hp;
  if (hit_point < 0) hit_point = 0;
  if( old_hp != hit_point )
    this_object()->set_auto_monitor();
}
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

query_dam_taken_this_round()
{
    return dam_taken_this_round;
}

int
calculate_evaluated_worth(object ob)
{
    int exp_worth, align_diff, exp_bonus;

    if(!ob) return 0;

    exp_worth = (int)this_object()->calculate_worth();
    ob->add_alignment(ADJ_ALIGNMENT(alignment));

    /* Give some more experience for staying in your alignment */
    align_diff = alignment - (int)ob->query_alignment();

    /* Never more than 20 percent */
    align_diff /= 200;
      
    /* Get absolute value */
    if (align_diff < 0) 
       align_diff = -align_diff; 
    exp_bonus = align_diff * exp_worth / 100;

    /* Never more than 1000 */
    if(exp_bonus > 1000) 
      exp_bonus = 1000;
      
/*
    if(ctime()[4..9] == "May 24") {
      write("Double Experience Day!\n");
      exp_worth *= 2;
    }
*/
    return (exp_worth + exp_bonus);
}

#if 0 /* Rumplemintz */
set_custom_attacker_death_mess(x)
{
    custom_attacker_death_mess = x;
}
set_custom_room_death_mess(x)
{
     custom_room_death_mess = x;
}
#endif

query_hurt() {
  if(hit_point < max_hp) return 1;
  return 0;
}
query_lostexperience() { return lostexperience; }

#if 0 /* Rumplemintz */
query_second_weapon()
{
 return second_weapon;
}
#endif

guild_power_reduction(arg) {
  int newdam;
  string junk;
  newdam = arg;
  if(!this_player()) return arg;
  if(this_player()->query_guild_name()=="cyberninja") {
    newdam = (arg * 8) / 10;
  }
  if(this_player()->query_guild_name()=="warrior") {
      newdam = (arg * 8) / 10;
  }
  if(sscanf(this_player()->query_guild_name(),"%symbiote",junk)) {
            newdam = (arg * 8) / 10;
  }
  return newdam;
}

stop_hunted() { hunted = 0; }
clear_dieing() { dieing = 0; }
toggle_feedback(arg) {  /* pass an argument to get the status but NOT toggle */
  if(arg) return feedback_off;
  return (feedback_off=!feedback_off);
}

#include "/obj/lib/living/alignment_tags.h"

query_light()
{
  return set_light(0);
}

query_save_flag() { return 1; }
query_maxcoins() { return MAXCOINS; }

void set_disallow_give(status x)
{
  disallow_give=x;
}

status query_disallow_give()
{
  return disallow_give;
}

/***************************************************************************/

string pad_str(string prefix, string str, int len) {
  int pad_len, i;
  string pad, tmp_str, new_str;

  pad_len = strlen(prefix);
  pad = "                                             " +
        "                                             ";
  pad = pad[0..pad_len-1];
  str = prefix + str + " ";    /* space flags end of string */
  new_str = "";
  if (len < 1 || len > 79) len = 75;         /* line length */
  while (str && strlen(str)) {
    if (new_str != "") str = "\n" + pad + str;
    tmp_str = str[0..len];                  /* get one line */
    for (i = strlen(tmp_str)-1; i >= pad_len && tmp_str[i] != ' '; i--);
    if (i <= pad_len) i = strlen(tmp_str)-2;  /* no spaces! */
    tmp_str = str[0..i];
#if 0
    str = str[i+1];
#else
    str = extract(str, i+1);
#endif
    new_str += tmp_str;
  }
  return new_str + "\n";
}

string filter_ansi(string str) {
  string rest, tmp;

  str = str + "";
  while (sscanf(str, "%s" + ESC + "%sm%s", str, tmp, rest) == 3) str += rest;
  return str;
}

