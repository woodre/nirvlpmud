
#include "security.h"
#define ALIGN_EXP_DIVISOR               1800
#define WA_FACTOR           4
#define EXP_DIVISOR                     170
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
int crime; /* have we been bad.  players */
int money;              /* Amount of money on player. */
int luck,lucky;
string name;            /* Name of object. */
static int already_fight;
     /* see if more than one attack per hb, method like that made by shadowhawk.*/
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
object alt_attacker_ob; /* Name of other player also attacking us. */
int weapon_class;       /* How good weapon. Used to calculate damage. */
object name_of_weapon;  /* To see if we are wielding a weapon. */
object head_armor;      /* What armor we have. */
int ghost;              /* Used for monsters that can leave a ghost. */
int dead;
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
string auto_load;       /* Special automatically loaded objects. */
string current_room;    /* Name of current room. */

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
  move_object(this_object(), dest);
  is_light = set_light(0);
  if (is_light < 0)
    is_light = 0;
  if (level >= 20)
    tell_object(this_object(), 
    environment(this_object())->short() + "\n");
  if (!msgin)
    msgin = "arrives";
  if (ghost && is_light)
    say(NAME_OF_GHOST + " " + msgin + ".\n");
  if (hunted && present(hunted))
    attack_object(hunted);
  if (hunter && present(hunter))
    call_other(hunter, "attack_object", this_object());
  if (is_npc)
    return;
  if (!is_light) {
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

/*
 * This function is called from other players when they want to make
 * damage to us. We return how much damage we received, which will
 * change the attackers score. This routine is probably called from
 * heart_beat() from another player.
 */
hit_player(dam,zap) {
    int dam2,ac_tmp;
    object pro_object;   /* paladin weapon pro & combat method object */

  if (this_player() && this_player() != this_object() && this_player()->query_level() < EXPLORE) {
    /* -= Protection =- */  
    if ( this_player()->is_player() &&
         this_player()->query_attack() != this_object() &&
         !this_player()->valid_attack( this_object()))
    { /* bad attack, could be logged */
      write( "Your attack fails.\n");
      return 0;
    }
    if ( attacker_ob == alt_attacker_ob || !alt_attacker_ob)
      attacked_by( this_player());
    /* -= Crime =- */
    if ( this_player()->query_level() < EXPLORE &&
         (!is_npc || this_object()->crime_to_attack()))
     if(!this_object()->query_crime() && !this_player()->query_crime())
      this_player()->set_crime();
  }
  if (level >= 20 && !is_npc)   /* You can't hit a wizard ! */
    return 0;
  if (!is_npc && armor_class > 9) {
    ac_tmp = 9;
   } else {
   ac_tmp = armor_class;
   }
 dam2 = dam;
/************************************/
/*    BEGIN PALADIN ADDITIONS       */
/************************************/
   pro_object = present("pro_object", this_object());
   if(pro_object && paladin_shield && pro_object->query_combat_method() == 2) {
     ac_tmp += call_other(paladin_shield, "shield_bonus", pro_object);
   }
/************************************/
/*     END PALADIN ADDITIONS        */
/************************************/
  dam -= random(ac_tmp + 1);
  lucky = random(500);
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
      tell_object(this_object(), attacker_ob->query_name() + " hits you with a crushing blow.\n");
      }
  if (dam <= 0)
    return 0;
  if (dam > hit_point+1)
    dam = hit_point+1;
/* PUT a cap on damage a player can do in one hit. */
    if(!zap) zap = attacker_ob;
   if(attacker_ob && zap && zap->query_level() < EXPLORE)
   {
   if (is_npc && dam > 50 && attacker_ob->query_level() < EXPLORE)
    {
    if(dam < 56) dam=50;
    if(dam > 55) dam=random(30);
   }
    }
  hit_point = hit_point - dam;
  if (hit_point<0) {
    object corpse;
    /* We died ! */
    if (hunter)
      call_other(hunter, "stop_hunter");
    hunter = 0;
    hunted = 0;
    say(cap_name + " died.\n");
    /* If this is a player, log the death for future reference */
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
    experience = (experience * 3) / 4;  /* Take away 1/4 of exp. */
   call_other(this_object(), "clear_crime");
     lower_attrib();
     call_other(this_object(),"rm_pk",0);
     }
    if (max_hp)
      hit_point = max_hp/3;
    else
      hit_point = 10;
    corpse = clone_object("obj/corpse");
    call_other(corpse, "set_name", name);
    call_other(corpse, "set_corpse_level", level);
    transfer_all_to(corpse);
    if (!attacker_ob)
      attacker_ob = alt_attacker_ob;
    if (!is_npc) {
    see_if_other(3); /* prevent cheating */
      save_object("players/" + name);
      attacker_ob = 0;
      alt_attacker_ob = 0;
/* zero out attackers, hopefully will cure death bug.*/
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
      /* Don't let the alignment bonus exceed 1/2 the base bonus */
      if (exp_bonus > base_bonus/2)
	exp_bonus = base_bonus/2;
      exp_bonus += base_bonus;
      wa_bonus = weapon_class * armor_class * WA_FACTOR;
      if (wa_bonus > base_bonus/3)
	   wa_bonus = base_bonus/3;
       exp_bonus += wa_bonus;
       party=present("party object", attacker_ob);
       if(party) exp_bonus = 24*exp_bonus/30;
       if (party) party->share_exp(exp_bonus);
       if(!party)
      call_other(attacker_ob, "add_exp", exp_bonus);
    }
    move_object(corpse, environment(this_object()));
    if (!call_other(this_object(), "second_life", 0))
      destruct(this_object());
  }
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
  return alignment;
}

query_npc() {
  return is_npc;
}

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
    write("armor class: " + armor_class);
    if (head_armor)
	write("\narmor: " + call_other(head_armor, "rec_short", 0));
    write("\nweapon class: \t"); write(weapon_class);
    if (name_of_weapon)
	write("\nweapon: " + call_other(name_of_weapon, "query_name", 0));
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
    write("room: " + file_name(environment(this_object())) + "\n");
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
    if (!name_of_weapon) {
	/* This should not happen ! */
/*
	log_file("wield_bug", "Weapon not wielded !\n");
*/
	write("Bug ! The weapon was marked as wielded ! (fixed)\n");
	return;
    }
    call_other(name_of_weapon, "un_wield", dead);
    name_of_weapon = 0;
    weapon_class = WEAPON_CLASS_OF_HANDS;
}


stop_wearing(name) {
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
	if(!dead)
	    say(cap_name + " removes " + name + ".\n");
    write("Ok.\n");
}

query_level() {
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
  int tmp;
  string mfight,thingone,thingtwo;
  int tmpk,pal_tmp,whit,weap_tmp;
  int intox_no;
  string name_alt_at;
  string name_of_attacker;
  object pro_object;     /* paladin object */
  pal_tmp = 0;
  if (!is_npc)
   intox_no = call_other(this_object(), "query_intoxination", 0)/5;
 else
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
 /* Stop fighting if one party is disconnected */
  /* Stop player disconnected player from fighting */
 if (!is_npc && !call_other(this_object(), "query_interactive",0))
{
    alt_attacker_ob=0;
    attacker_ob =0;
  return 0;
}
  /* stop monster from fighting disconnected player */
 if (is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
   stop_fight();
  /* stop player from fighting disconnected player */
if(!is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
  stop_fight();
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
    tell_object(attacker_ob, "You are hit by a " + spell_name + ".\n");
    write("You cast a " + spell_name + ".\n");
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
   if(this_object()->is_kid() && weap_tmp > 17) weap_tmp = 17;
   }
   pal_tmp=weap_tmp;
/******************************/
/*  BEGIN PALADIN ADDITIONS   */
/******************************/
   pro_object = present("pro_object", this_player());
   if(name_of_weapon && pro_object && name_of_weapon->query_pro_weapon()) {
     weap_tmp += call_other(name_of_weapon, "proficiency_hit", pro_object);
   }
   if(second_weapon && pro_object && pro_object->query_combat_method() == 3) {
     weap_tmp += call_other(second_weapon, "dual_hit", pro_object);
   }
/******************************/
/*   END PALADIN ADDITIONS    */
/******************************/
   if(alt_attacker_ob)
  if(!alt_attacker_ob->query_name()) alt_attacker_ob = attacker_ob;
  if(alt_attacker_ob && alt_attacker_ob != attacker_ob){
     if(present(alt_attacker_ob))
   hit_pet(weap_tmp,spell_dam);
   }
  if(whit != "miss")
    tmp = call_other(attacker_ob, "hit_player", 
		     random(weap_tmp - intox_no) + spell_dam);
  else
    tmp = 0;
  if (tmp == 0) {
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
     if(!is_npc && random(4000000/name_of_weapon->query_wear()) < 10)
	name_of_weapon->weapon_breaks();
     }
    }
    return 1;
  }
  experience += tmp;
  tmp -= spell_dam;
  spell_cost = 0;
  spell_dam = 0;
  /* Does the enemy still live ? */
  if (attacker_ob &&
      call_other(attacker_ob, "query_name", 0) != NAME_OF_GHOST) {
    string how, what;
    how = " to small fragments";
    what = "massacre";
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
   already_fight = 1;
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

wield(w) {
    if (name_of_weapon)
	stop_wielding();
    name_of_weapon = w;
    weapon_class = call_other(w, "weapon_class", 0);
    say(cap_name + " wields " + call_other(w, "query_name", 0) + ".\n");
    write("Ok.\n");
}

/* Wear some armor. */

wear(a) {
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
  if (!h)
    return;
  hit_point += h;
  if (hit_point > max_hp)
    hit_point = max_hp;
  spell_points += h;
  if (spell_points > max_spell)
    spell_points = max_spell;
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
  call_other(ob, "attacked_by", this_object());
  checked_say(cap_name + " summons a flash from the sky.\n");
  write("You summon a flash from the sky.\n");
  if (!call_other(ob, "query_npc", 0))
    shout("There is a big clap of thunder.\n\n");
  ob->hit_player(100000,this_object());
}

missile_object(ob)
{
  /* If this is a player, make sure they are entitled to attack this person */
  if (!valid_attack(ob)) {
    write("You can't attack " + call_other(ob, "query_name", 0) + "!\n");
    return 0;
  }
  if (spell_points < 10) {
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
  if (spell_points < 15) {
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
  if (spell_points < 20) {
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
  if(this_object()->query_hbflag()=="hbstayon") return 1;
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
  if (level <= 19)
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
  int i, j;
  
  here = environment();
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
query_wc() {return weapon_class;}
query_ac() {return armor_class;}
query_sp() {return spell_points;}
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
     if (spell_points < cost) {
       write("Too low on power.\n");
       return;
     }
    if(at_msg) tell_object(this_object(), at_msg);
    if(vi_msg) tell_object(ob,vi_msg);
    if(rm_msg) say(rm_msg);
     spell_name = name;
    spell_dam = dam;
     spell_cost = cost;
     attacker_ob =ob;
}
query_weapon() {return name_of_weapon;}
query_hunted() {return hunted;}
hit_pet(k1,k2){
int tmpk;
string name_alt_at;
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
