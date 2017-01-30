/* templar.c
   Original code from Bern's Clerics
   Modified by Boltar, Jaraxle, and others
   This version by illarion
*/

/* saved variables */

int sword,kinfe,club,axe,bow,polearm,horse;
int KPTS;


/* Elite Knights */
status elite;
int award1,award2,award3,award4;

/* non-saved variables */
static int horsed;
static int worn;
static int local_weight;
static string short_desc;

object sheathed_weapon;

#include "def.h"

void guild_save() {
  string name;
  if(!ETO) return;
  if(!(name=RNAME(ETO))) return;
  save_object(MEMBER_DIR+name);
  tell_object(ETO,"Templar Lore saved.\n");
}

void guild_restore() {
  string name;
  name=RNAME(TP);
  if(name) restore_object(MEMBER_DIR+name);
}

void reset(status arg) {
  if(!arg || root() || !TP) return;
  guild_restore();
} 

init() {
  string *cmds;
  int s;
  if(TP && LEV(TP) < 21) {
    add_action("no_spell", "missile", 2);
    add_action("no_spell","fireball", 2);
    add_action("no_spell","shock", 2);
    add_action("no_spell","sonic", 2);
    add_action("no_spell","pose"); 
  }
  cmds=master("get_cmds");
  s=sizeof(cmds);
  while(s--)
    add_action("templar_cmd",cmds[s]);
}

templar_cmd(str) {
  return master("templar_cmd",query_verb(),str,TO,ETO); 
}

no_spell(str) {
  write("You know nothing of that magic.");
  return 1;
}


get() { return 1; }

drop() { return 1; }

id(str) {
  return (elite && (str=="EliteTemplar" || str=="cape"))
      || str=="GI" || str=="ND" || str=="sheath"
      || str=="cross" || str=="templar cross" || str=="KnightTemplar"
      || str=="KnightInvite" || str=="kill_check_object";
}

varargs master(a,b,c,d,e,f,g,h) {
  return call_other(MASTER_DAEM,a,b,c,d,e,f,g,h);
}

short() {
  if(!short_desc)
    short_desc=(string)master("generate_short",TO);
  return short_desc;
}

long(str) {
  master("show_long",TO,str);
}

set_worn(x) { worn=x; short_desc=0;}
query_worn() { return worn; }

/* KPTS (honor) */
add_kpts(i) {
  KPTS+=i;
  if(KPTS > 100) KPTS=100;
  else if(KPTS < 0) KPTS=0;
  guild_save();
}
remove_kpts(i) {
  add_kpts(-i);
}
query_kpts() {
  return KPTS;
}

/* Code for Elite Guard */

set_elite(x) { elite=x; short_desc=0; guild_save();}
query_elite() { return elite; }

add_award(num,amt) {
  switch(num) {
    case 1: return award1+=amt;
    case 2: return award2+=amt;
    case 3: return award3+=amt;
    case 4: return award4+=amt;
  }
  if(num > 0 && num < 5 && amt > 0)
    guild_save();
  return -1;
}
query_award(num) {
  return add_award(num,0);
}
query_awards() {
  return award1+award2+award3+award4;
}

/* Temporary Weapon Storage (sheath) */

set_sheathed(object wep) {
  sheathed_weapon=wep;
}
query_sheathed() {
  return sheathed_weapon;
}
set_weight(x) {
  local_weight=x;
}
query_weight() {
  return local_weight;
}

/* Generic Backwards compatibility functions */
save_ob() {
  guild_save();
}