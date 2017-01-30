
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
  int tmp;
  string mfight,thingone,thingtwo;
  int tmpk,pal_tmp,whit,weap_tmp;
  int knt_tmp,knt_tmp2;
  int intox_no;
  string name_alt_at;
  string name_of_attacker;
  object pro_object;     /* paladin object */
  object templar_ob;    /* templar object */
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
  
    
   if(alt_attacker_ob)
      if(!alt_attacker_ob->query_name()) alt_attacker_ob = attacker_ob;
   if(alt_attacker_ob && alt_attacker_ob != attacker_ob){
      if(whit != "miss")
        if(present(alt_attacker_ob))
      hit_pet(weap_tmp,spell_dam);
   }

   DoHit(attacker_ob);
   if (!attacker_ob)
      attacker_ob = alt_attacker_ob;
      alt_attacker_ob = 0;
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
         say(cap_name+" is disconnected.\n");
         stop_fight(); this_player()->stop_fight();
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



test_if_any_here()
{
  object ob;
  if(!environment(this_object())) return 0;
  if(this_object()->query_hbflag()=="hbstayon") return 1;
  if(attacker_ob)
  if(attacker_ob->query_player_shell()) return 1;
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
    mess = ({" to small fragments","massacre"});
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
