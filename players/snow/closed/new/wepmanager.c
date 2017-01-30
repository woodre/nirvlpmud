/* Guild Weapon Manager */


/**** FILE SETUP, VARIABLES *********************************/ 
#include "/players/dune/closed/guild/DEFS.h"
inherit "/players/dune/closed/guild/snow/weapons/weapon";

#define NI    RED+"*~*"+OFF
#define MAX_ODAM 40

status less_spam;

int baseChance, aura_low, aura_dmg, multi_attack_low, 
    multi_attack_high, multi_attack_dmg, 
    min_attack_low, min_attack_high, min_attack_dmg, 
    med_attack_low, med_attack_high, med_attack_dmg, 
    max_attack_low, max_attack_high, max_attack_dmg, 
    min_bonus_low, min_bonus_high, max_bonus_low, damage;
string min_attack_type, med_attack_type, max_attack_type, meatn, 
       max_bonus_private, max_bonus_public, min_bonus_private,
       min_bonus_public, multi_hit_private, multi_hit_public,
       min_attack_private, min_attack_public, med_attack_private,
       med_attack_public, max_attack_private, max_attack_public,
       extra_min1_private, extra_min1_public, 
       extra_med1_private, extra_med1_public, 
       extra_med2_private, extra_med2_public, 
       extra_med3_private, extra_med3_public, 
       extra_med4_private, extra_med4_public;
/************************************************************/



/**** SET AND ACCESS FUNCTIONS ******************************/
void set_spam(status x)     { less_spam  = x;   }
status query_spam()         { return less_spam; }
void set_base_chance(int x) { baseChance = x;   }

void set_aura_attack(int low, int dmg) {
  aura_low = low;
  aura_dmg = dmg;
}

void set_multi_attack(int low, int high) {
  multi_attack_low  = low;
  multi_attack_high = high;
}

void set_min_bonus(int low, int high) { 
  min_bonus_low = low; 
  min_bonus_high = high;
}

void set_max_bonus(int low) { max_bonus_low = low; }

void set_min_attack(int low, int high, string type, int dmg) {
  min_attack_type = type;
  min_attack_low  = low;
  min_attack_high = high;
  min_attack_dmg  = dmg;
}

void set_med_attack(int low, int high, string type, int dmg) {
  med_attack_type = type;
  med_attack_low  = low;
  med_attack_high = high;
  med_attack_dmg  = dmg;
}

void set_max_attack(int low, int high, string type, int dmg) {
  max_attack_type = type;
  max_attack_low  = low;
  max_attack_high = high;
  max_attack_dmg  = dmg;
}

void set_msg(string type, string msg) {
  switch(type) {
  case "max_bonus_private":   max_bonus_private  = msg; break;
  case "max_bonus_public":    max_bonus_public   = msg; break;
  case "min_bonus_private":   min_bonus_private  = msg; break;
  case "min_bonus_public":    min_bonus_public   = msg; break;
  case "multi_hit_private":   multi_hit_private  = msg; break;
  case "multi_hit_public":    multi_hit_public   = msg; break;
  case "min_attack_private":  min_attack_private = msg; break;
  case "min_attack_public":   min_attack_public  = msg; break;
  case "med_attack_private":  med_attack_private = msg; break;
  case "med_attack_public":   med_attack_public  = msg; break;
  case "max_attack_private":  max_attack_private = msg; break;
  case "max_attack_public":   max_attack_public  = msg; break;
  case "extra_min1_private":  extra_min1_private = msg; break;
  case "extra_min1_public":   extra_min1_public  = msg; break;
  case "extra_med1_private":  extra_med1_private = msg; break;
  case "extra_med1_public":   extra_med1_public  = msg; break;
  case "extra_med2_private":  extra_med2_private = msg; break;
  case "extra_med2_public":   extra_med2_public  = msg; break;
  case "extra_med3_private":  extra_med3_private = msg; break;
  case "extra_med3_public":   extra_med3_public  = msg; break;
  case "extra_med4_private":  extra_med4_private = msg; break;
  case "extra_med4_public":   extra_med4_public  = msg; break;
  }
}
/************************************************************/



/**** ATTACK TYPES ******************************************/ 
void hit_location(string msg_private, 
string msg_public, int dmg) {
  int X, num;
  X = random(10);
  num = dmg + 1;
  if(X == 0) {
    if(!less_spam) write(msg_private+"head.\n");
    if(!less_spam) say  (msg_public+"head.\n");
    num = dmg + 4;
  }
  if(X == 1) {
    if(!less_spam) write(msg_private+"gut.\n");
    if(!less_spam) say  (msg_public+"gut.\n");
    num = dmg + 2;
  }
  if(X == 2) {
    if(!less_spam) write(msg_private+"chest.\n");
    if(!less_spam) say  (msg_public+"chest.\n");
  }
  if(X > 2 && X <5) {
    if(!less_spam) write(msg_private+"shoulders.\n");
    if(!less_spam) say  (msg_public+"shoulders.\n");
  }
  if(X > 4 && X < 7) {
    if(!less_spam) write(msg_private+"legs.\n");
    if(!less_spam) say  (msg_public+"legs.\n");
  }
  if(X > 6) {
    if(!less_spam) write(msg_private+"arms.\n");
    if(!less_spam) say  (msg_public+"arms.\n");
  }
  mod_damage(num);
}

void standard(string msg_private, 
string msg_public, int dmg) {
  if(!less_spam) write(msg_private);
  if(!less_spam) say  (msg_public);
  mod_damage(dmg);
}

void aura() {
  if(!less_spam) write(
NI+"A "+BOLD+BLINK+"VORTEX"+OFF+OFF+
" of death energy enshrouds you!\n"+
"You writh and scream in agony!\n");
  if(environment(TP)) {
    if(!less_spam) tell_room(environment(TP), 
NI+"A "+BOLD+BLINK+"VORTEX"+OFF+OFF+
" of death energy enshrouds "+TPN+"!\n"+
TPN+" writhes and screams in agony!\n"+
NI+"The room is drained of all light.\n"+
NI+"Rings of crackling "+BOLD+"lightning"+OFF+" surround "+
MEAN+"!\n");
   if(!less_spam) tell_room(environment(TP),
MEAN+" is lifted, screaming, from the ground!\n"+
NI+"The "+BOLD+"lightning"+OFF+
" releases all of its energy into "+MEAN+"!\n"+
MEAN+" groans pitifully and falls into a "+
"smoking heap on the floor.\n");
   if(!less_spam) tell_room(environment(TP),
NI+"Light returns to the room.\n"+
NI+"The "+BOLD+BLINK+"VORTEX"+OFF+OFF+" surrounding "+
TPN+" disappears.\n");
  }
  mod_damage(aura_dmg);
}
/************************************************************/



/**** ATTACK LEVELS *****************************************/
void min_attack() {
  int count;
  string msg_private, msg_public;
  msg_private = min_attack_private;
  msg_public  = min_attack_public;
  count = 1;
  if(extra_med1_private) count++;
  count = random(count);
  switch(count) {
    case 0: break;
    case 1: msg_private = extra_min1_private; 
            msg_public = extra_min1_public; 
            break;
  }
  switch(min_attack_type) {
    case "hit_location": 
      hit_location(min_attack_private, min_attack_public, 
                   min_attack_dmg); break;
    case "standard": 
      standard(min_attack_private, min_attack_public, 
      min_attack_dmg); break;
  }
}

void med_attack() {
  int count;
  string msg_private, msg_public;
  msg_private = med_attack_private;
  msg_public  = med_attack_public;
  count = 1;
  if(extra_med1_private) count++;
  if(extra_med2_private) count++;
  if(extra_med3_private) count++;
  if(extra_med4_private) count++;
  count = random(count);
  switch(count) {
    case 0: break;
    case 1: msg_private = extra_med1_private; 
            msg_public = extra_med1_public; 
            break;
    case 2: msg_private = extra_med2_private; 
            msg_public = extra_med2_public; 
            break;
    case 3: msg_private = extra_med3_private; 
            msg_public = extra_med3_public; 
            break;
    case 4: msg_private = extra_med4_private; 
            msg_public = extra_med4_public; 
            break;
  }
  switch(med_attack_type) {
    case "hit_location": 
      hit_location(msg_private, msg_public, 
                   med_attack_dmg); break;
    case "standard": 
      standard(msg_private, msg_public, 
               med_attack_dmg); break;
  }
}

void max_attack() {
  switch(max_attack_type) {
    case "hit_location": 
      hit_location(max_attack_private, max_attack_public, 
                   max_attack_dmg); break;
    case "standard": 
      standard(max_attack_private, max_attack_public, 
               max_attack_dmg); break;
  }
}
/************************************************************/



/**** MULTIPLE HITS *****************************************/
void r_attack() {
  int Z;
  Z = random(12);
  if(Z >= 0 && Z < 2) max_attack(); /* 2 in 12 */
  if(Z >= 2 && Z < 6) med_attack(); /* 4 in 12 */
  if(Z >= 6)          min_attack(); /* 6 in 12 */
}

void multi_hit() {
  int rart, i;
  rart = random((int)IPTP->query_art_level() / 2) + 2;
  if(rart > 3) rart = 3; /* max of 3 multiple attacks */
  for(i=0; i < rart; i++) r_attack();
}
/************************************************************/



/**** CHECKING FUNCTIONS ************************************/
void check_extra() {
  status bi, bl;
  object meat;
  bi = (status)IPTP->query_bion_on();
  meat = (object)IPTP->query_target();
  if(bi && random(45) < (int)IPTP->guild_lev()) {
    write(REV_BLUE+"~##~  BIONICS  ~##~"+OFF+"\n");
    mod_prof(random((int)IPTP->guild_lev()));
  }
  if(IPTP->item_weplink()) mod_prof(IPTP->item_weplink());
  if(meat && meat == TP->query_attack()) mod_prof(4);
}

void restrain_damage(object ob) {
  int MAX, mhp, dmg, amode;
  amode = (int)IPTP->query_attack_mode();
  MAX = (int)IPTP->query_art_level() + 5;
  if(MAX > 17) MAX = 17;
  mhp = (int)ob->query_hp();
  dmg = (int)query_prof();
  if(amode == 1) { MAX += 5; dmg += 2; }
  if(amode == 2) { MAX -= 10; dmg -= 10; }
  if(dmg > MAX) dmg = MAX;
  if(TP->query_alignment() > 500) dmg = dmg - 2;
  if((string)IPTP->query_stone() == "diamond") dmg = dmg + 2;
  if(dmg < 0) dmg = 0;
  if(TRN == OWNER1 || TRN == OWNER2) 
    write(RED+"..WEAPON BONUS : "+dmg+OFF+"\n");
  set_prof(dmg);
}
/************************************************************/



/**** WEAPON HIT ********************************************/
int weapon_hit() {
  string sync;
  int returnValue;
  int chance;

  this_object()->ninjaWeapon();
  chance = baseChance;
  meatn = MEAN;
  set_prof(0);
  if(!chance) return 0; 
  
  /* This is where the weapon damage from emotes comes */
  call_out("do_damage", 1, MEAT);

  if((int)IPTP->query_attack_mode() == 1) chance  += 15;
  if((int)IPTP->query_attack_mode() == 2) chance  -= 40;
  if((string)IPTP->query_weapon() != name_of_weapon) chance  -= 40;

  if(chance > aura_low) 
    aura();
  if(chance > multi_attack_low   && chance < multi_attack_high) 
    multi_hit();
  if(chance > min_attack_low  && chance < min_attack_high) 
    min_attack();
  if(chance > med_attack_low  && chance < med_attack_high) 
    med_attack();
  if(chance > max_attack_low  && chance < max_attack_high) 
    max_attack();

  check_extra();
  restrain_damage((object)TP->query_attack());


  if(chance > min_bonus_low && chance  < min_bonus_high 
  && min_bonus_private) {
    if(!less_spam) say(min_bonus_public);
    if(!less_spam) write(min_bonus_private);
    returnValue = (int)IPTP->query_art_level() / 4;
  }

  if(chance > max_bonus_low 
  && max_bonus_private) {
    if(!less_spam) say(max_bonus_public);
    if(!less_spam) write(max_bonus_private);
    returnValue = (int)IPTP->query_art_level() / 3;
  }

  if((TP->query_attack()->query_hp()) < 
     ((int)IPTP->query_art_level())) {
    if(name_of_weapon == WEAPON_HANDS)
      if(!less_spam) write("You hunger for the kill!\n");
    else 
      if(!less_spam) write("Your "+name_of_weapon+
        " hungers for the kill!\n");
    returnValue = ((int)IPTP->query_art_level() / 3) + 1; 
  }

  return returnValue;
}
/************************************************************/


void do_damage(object meat) {
  object to_hit;
  to_hit = meat;
  if(!wielded_by) return;
  if((object)wielded_by->query_attack() != to_hit) return;
  if(to_hit->query_ghost()) return;
  if(damage > MAX_ODAM) damage = MAX_ODAM;
  if(((int)to_hit->query_hp() - 10) < damage)
    damage = (int)to_hit->query_hp() - 10;
  to_hit->hit_player(damage);
  damage = 0; }
