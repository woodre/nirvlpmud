#pragma strict_types
#pragma save_types
#pragma combine_strings

#include <mudlib.h>
inherit BASE;

#include "/include/cfg/living.cfg"
#include "/include/fn_specs/living.spc"
#include "/include/fn/compare.h"
#include "/include/fn/tell.h"
#include "/include/fn/shout.h"
#include "/include/skills/skills.h"
#include <ansi.h>
#include "/include/cfg/spell.h"

/* 'rename' some base_obj stuff */

#define invis_name alt_name

#define POISON_OB present("Poison", this_object())
#define POISON (POISON_OB) ? (int)POISON_OB->query_poison_penalty() : 0

#define THIS_PLAYER_WIZ  ((this_player()->query_level() > 19) ? 1 : 0)
#define THIS_OBJECT_WIZ  ((this_object()->query_level() > 19) ? 1 : 0)
#define PRIMARY_DEX      (int)primary_attack->query_dexterity()
#define PRIMARY_DISGUISE (int)primary_attack->query_disguise()
#define THIS_PRIMARY_COM (int)this_player()->query_combat()

int level;                   /* Level of being */
int level_drained;           /* number of levels 'drained' */

string msgin;                /* Message for walking into a room */
string msgout;               /* Message for walking out of a room */
string mmsgin;               /* Message for magical entry to a room */
string mmsgout;              /* Message for magical exit from a room */

string race;                 /* race of this being */

string *languages_known;     /* list of languages known */
string *weapon_prof;         /* list of weapon proficiencies */
string *classes;             /* list of classes */

status ghost;                /* Is the being a ghost? */
status dead;                 /* Is the being dead? */
status no_wimpy;             /* Is the being restricted from wimpy? */
int whimpy;                  /* Number of hp being will run at */

int hp;                      /* Number of hit points of being */
int max_hp;                  /* Maximum number that hp may reach */

int experience;              /* Experience points earned by being */
int money;                   /* Amount of gold coins possessed by being */
int age;                     /* Number of heartbeats being has existed */
int alignment;               /* Numerical alignment of being */
int gender;                  /* Numerical gender of being... 0 = neuter
                                                             1 = male
                                                             2 = female */

static string custom;        /* Custom direction for wimpy exit */
static string *spell_immune; /* Spell types that being is immune to */
static mixed *loaded_spell;  /* Spell cast next heart beat */

static string speak_language; /* Language being spoken */
static int magic_resist;      /* Resistance to offensive spells */
static status is_npc;         /* Is the being not a player? */
int is_invis;                 /* Use invis_name, short() = 0 */
static status is_alias;       /* Use alias_name */
static status brief;          /* In brief mode */
static int spell_time;        /* spell casting counter */

static int armor_class;       /* Measure of protection */
static object *armor_worn;    /* List of armor being worn */
static int ac_bonus;
static int npc_ac;

static object *followers;     /* objects following me */

static int right_wc;          /* right weapon */
static object right_weapon;
static string right_weapon_type;
static int right_weapon_bonus;
static string *right_attack_msg;
static int npc_wc;

static int left_wc;           /* left weapon */
static object left_weapon;
static string left_weapon_type;
static int left_weapon_bonus;
static string *left_attack_msg;
static int npc_wc_l;

static object primary_attack;     /* main opponent */
static object *secondary_attacks; /* list of other opponents */

static string *sec_att_names;

/*** Primary skills ***/

int combat;              /* replaces dex, how well do you attack */
int dexterity;           /* how well you defend against attacks */
int intelligence;        /* do you perceive eg. thief's stealth */
int wisdom;              /* wisdom - resistance to some spells */
int charisma;            /* how good you are at shopping */
int constitution;        /* how many hit points */
int strength;            /* how much you can carry, also different to combat */

int max_combat;
int max_dexterity;
int max_intelligence;
int max_wisdom;
int max_charisma;
int max_strength;

status hp_displ;         /* display hp */


/*************************************************************************/
/* log */

void log(string file, mixed old, mixed new) {
  if (is_npc || !THIS_PLAYER_WIZ) return;
  write_file("/log/MAIN/" + file, "To: " + query_name(1) +
             ";By: " + (string)this_player()->query_name(1) +
             ((new) ? ";Old: " + old + ";New: " + new : ";" + old) +
             ";Time: " + ctime(time()) + ";\n");
}

status test_dark() {
  if (set_light(0) > 0) return 0;
  write("It is dark.\n");
  return 1;
}


/*************************************************************************/
/* sets */

int set_level(int i) {
#ifdef LOG_SET_LEVEL
  log(LOG_SET_LEVEL, level, i);
#endif /* LOG_SET_LEVEL */
  return level = i;
}


string set_msgin(string s)   { return msgin   = (s) ? s : DEFAULT_MSGIN;   }
string set_msgout(string s)  { return msgout  = (s) ? s : DEFAULT_MSGOUT;  }
string set_mmsgin(string s)  { return mmsgin  = (s) ? s : DEFAULT_MMSGIN;  }
string set_mmsgout(string s) { return mmsgout = (s) ? s : DEFAULT_MMSGOUT; }

string set_race(string str) {
  string race_type;
  int i;
  int *stats, *max_stats;
  string *stat_name;

#ifdef LOG_SET_RACE
  log(LOG_SET_RACE, race, str);
#endif /* LOG_SET_RACE */
  if (!str) str = "human";
  str = lower_case(str);
  race = str;
  sscanf(str, "%s %s", race_type, str);
  if (str == "elf") {    
    stats     = ({  1,  2,  1,  1,  3,  1,  2  });   
    if (race_type == "half") 
      max_stats = ({  20, 25, 22, 23, 26, 25, 24  }); 
    else if (race_type == "gray")
      max_stats = ({  19, 27, 20, 21, 26, 22, 26  });
    else if (race_type == "wood" || race_type == "wild")
      max_stats = ({  20, 20, 26, 23, 26, 19, 26  });
    else
      max_stats = ({  20, 26, 20, 22, 26, 21, 26  });
  }
  else if (str == "dwarf") {  
    stats     = ({  3,  1,  2,  1,  1,  2,  1, });
    max_stats = ({ 27, 20, 26, 23, 23, 25, 19, }); 
  }
  else if (str == "minotaur") {
    stats     = ({  2,  1,  2,  2,  2,  1,  1, });
    max_stats = ({  27, 18, 30, 23, 20, 20, 18 }); 
  }
  else if (str == "orc") { 
    stats     = ({  2,  1,  2,  2,  2,  1,  1, });   
    max_stats = ({ 25, 18, 29, 24, 23, 25, 18, }); 
  }
  else if (str == "giant") {   
    stats     = ({  3,  1,  3,  1,  1,  1,  1, });
    max_stats = ({ 32, 15, 32, 23, 20, 20, 18, }); 
  }   
  else if (str == "halfling" || str == "kender") {
    stats     = ({  1,  2,  1,  1,  2,  2,  2, });   
    max_stats = ({ 18, 25, 20, 20, 26, 25, 22, }); 
  }
  else if (str == "gnome") {   
    stats     = ({  1,  3,  1,  1,  2,  2,  1, });   
    max_stats = ({ 20, 25, 20, 20, 26, 27, 23, }); 
  }
  else if (race == "pixie"  || race == "nixie" ||  race == "kobold" 
        || race == "goblin" || race == "sprite" ) {
    stats     = ({  1,  3,  1,  1,  2,  2,  1, });   
    max_stats = ({  20, 25, 20, 20, 26, 27, 23   }); 
  }
  else {
    stats     = ({  2,  2,  2,  2,  2,  2,  2, });   
    max_stats = ({ 25, 25, 25, 25, 25, 25, 25, }); 
  }
  stat_name = ({   
      "constitution", "intelligence", "strength",   
      "combat",  "dexterity",    "wisdom", "charisma"   
  });   

  if (str != "human") add_language(str);
  for (i = 0; i < sizeof(stat_name); i++) {
    if (level < 1) {     
      call_other(this_object(),"set_"+stat_name[i],stats[i]);
    }
    call_other(this_object(),"set_max_"+stat_name[i],max_stats[i]);
  }
  return race;
}


string *set_languages_known(string *arr) {
  return languages_known = (arr) ? arr : ({});
}


status change_language(string str) {
  if (str == "common" || query_language(str)) {
    write("You begin to speak in " + str + ".\n");
    speak_language = str;
    return 1;
  }
  write("You don't know the language " + str + ".\n");
  return 1;
}

status set_speak_language(string str) {
  speak_language = (query_language(str)) ? speak_language : "common";
  return (str == speak_language) ? 1 : 0;
}

string *set_weapon_prof(string *arr) {
  return weapon_prof = (arr) ? arr : ({});
}

string *set_right_attack_msg(string *msg) {
  return right_attack_msg = (msg) ? msg : ({});
}

string *set_attack_msg(string *msg) {
  return set_right_attack_msg(msg);
}

string *set_left_attack_msg(string *msg) {
  return left_attack_msg = (msg) ? msg : ({});
}

status set_ghost(status i)    { return ghost    = (i) ? 1 : 0; }
status set_dead(status i)     { return dead     = (i) ? 1 : 0; }

status set_no_wimpy(status i) { return no_wimpy = (i) ? 1 : 0; }
int set_wimpy(int i)          { return whimpy   = i; }
string set_custom(string s)   { return custom   = s; }

int set_hp(int i) {
#ifdef LOG_SET_HP
  log(LOG_SET_HP, hp, i);
#endif /* LOG_SET_HP */
  return hp = i;
}

int set_max_hp(int i) {
#ifdef LOG_SET_MAX_HP
  log(LOG_SET_MAX_HP, max_hp, i);
#endif /* LOG_SET_MAX_HP */
  return max_hp = i;
}

int set_exp(int i) {
#ifdef LOG_SET_EXP
  log(LOG_SET_EXP, experience, i);
#endif /* LOG_SET_EXP */
  return experience = i;
}

int set_money(int i) {
#ifdef LOG_SET_MONEY
  log(LOG_SET_MONEY, money, i);
#endif /* LOG_SET_MONEY */
  return money = i;
}

int set_age(int i) { return age = i; }

int set_alignment(int i) {
#ifdef LOG_SET_ALIGN
  log(LOG_SET_ALIGN, alignment, i);
#endif /* LOG_SET_ALIGN */
  if (!intp(i)) return 0;
  return alignment = i;
}

int set_al(int i) {
#ifdef LOG_SET_ALIGN
  log(LOG_SET_ALIGN, alignment, i);
#endif /* LOG_SET_ALIGN */
  if (!intp(i)) return 0;
  return alignment = i;
}

int set_gender(int i) { return gender = ((i==2) ? 2 : ((i==1) ? 1 : 0)); }


string *set_spell_immune(string *arr) {
  return spell_immune = (arr) ? arr : ({});
}

mixed *set_loaded_spell(mixed *arr) {
  return loaded_spell = (arr) ? arr : ({});
}

int set_magic_resist(int i) {
  return magic_resist = ((i > 100) ? 100 : ((i < 0) ? 0 : i));
}

status set_npc(status i)          { return is_npc   = (i) ? 1 : 0; }
int set_invis(int i)              { return is_invis =  i;          }
status set_alias_status(status i) { return is_alias = (i) ? 1 : 0; }
status set_brief(int i)           { return brief    = (i) ? 1 : 0; }

int set_ac(int i)                 { npc_ac = i; return armor_class = i; }
int set_armor_class(int i)        { npc_ac = i; return armor_class = i; }

int set_ac_bonus(int i) {
#ifdef LOG_SET_AC_BONUS
  log(LOG_SET_AC_BONUS, ac_bonus, i);
#endif /* LOG_SET_AC_BONUS */
  return ac_bonus = i;
}

object *set_armor_worn(object *arr) {
  return armor_worn = (arr) ? arr : ({});
}

int set_wc(int i)                       { npc_wc = i; return right_wc = i;  }
int set_right_wc(int i)                 { npc_wc = i; return right_wc = i;  }
object set_right_weapon(object ob)      { return right_weapon = ob;         }
string set_right_weapon_type(string s)  { return right_weapon_types = s;    }

int set_left_wc(int i)                  { npc_wc_l = i; return left_wc = i; }
object set_left_weapon(object ob)       { return left_weapon = ob;          }
string set_left_weapon_type(string str) { return left_weapon_types = s;     }
int set_left_weapon_bonus(int i)        { return left_weapon_bonus = i;     }

object set_primary_attack(object ob)    { return primary_attack = ob;       }

object *set_secondary_attacks(object *arr) {
  return secondary_attacks = (arr) ? arr : ({});
}

string *set_classes(string *arr) { return classes = (arr) ? arr : ({}); }

/*** Primary skills ***/

int set_combat(int i)       { return combat       = i; }
int set_dexterity(int i)    { return dexterity    = i; }
int set_intelligence(int i) { return intelligence = i; }
int set_wisdom(int i)       { return wisdom       = i; }
int set_charisma(int i)     { return charisma     = i; }
int set_strength(int i)     { return strength     = i; }

int average_hp_multiplier() {
  int i, j, total;

  if ((i = sizeof(classess))) {
    for (total = 0; i--;) {
      if ((j = member(HP_PER_LEVEL, classes[i])) != -1) {
        total += HP_PER_LEVEL[j+1];
      }
      else {
        log_file("HP_PER_LEVEL",
                 "Class: " + classes[i] + " is not defined in skills.h\n");
      }
    }
    return total/sizeof(classes);
  }
  return 8;
}

int set_constitution(int i) {
  max_hp = 60 + i * average_hp_multiplier();
  max_hp -= POISON;
  return constitution = i;
}

int set_max_combat(int i)       { return max_combat       = i; }
int set_max_dexterity(int i)    { return max_dexterity    = i; }
int set_max_intelligence(int i) { return max_intelligence = i; }
int set_max_wisdom(int i)       { return max_wisdom       = i; }
int set_max_charisma(int i)     { return max_charisma     = i; }
int set_max_strength(int i)     { return max_strength     = i; }
int set_max_constitution(int i) { return max_constitution = i; }


/*************************************************************************/
/* query */

string query_current_room()     { return object_name(environment()); }

varargs string query_name(status real) {
  return (real)
       ? lower_case(name)
       : (ghost)
       ? DEFAULT_GHOST_NAME
       : (is_invis)
       ? invis_name
       : (is_alias || disguise_on)
       ? alias_name
       : (name)
       ? capitalize(name)
       : "";
}

string query_real_name()         { return ((name) ? lower_case(name) : 0); }
string query_cap_name()          { return capitalize(query_name()); }
string query_invis_name()        { return invis_name;        }
int query_level()                { return level;             }
int query_level_drained()        { return level_drained;     }
 
string query_msgin()             { return msgin;             }
string query_msgout()            { return msgout;            }
string query_mmsgin()            { return mmsgin;            }
string query_mmsgout()           { return mmsgout;           }

string query_race()              { return race;              }

string *query_languages_known()  { return languages_known;   }
string *query_weapon_prof()      { return weapon_prof;       }
string *query_classes()          { return classes;           }

status query_ghost()             { return ghost;             }
status query_dead()              { return dead;              }

status query_no_wimpy()          { return no_wimpy;          }
int query_wimpy()                { return whimpy;            }
string query_custom()            { return custom;            }
  
int query_hp()                   { return hp;                }
int query_max_hp()               { return max_hp;            }

int query_exp()                  { return experience;        }
int query_money()                { return money;             }
int query_age()                  { return age;               }
int query_alignment()            { return alignment;         }
int query_al()                   { return alignment;         }
  
string *query_all_spell_immune() { return spell_immune;      }
mixed *query_loaded_spell()      { return loaded_spell;      }
int query_magic_resist()         { return magic_resist;      }

string query_speak_language()    { 
  return (speak_language) ? speak_language : "common";
}

status query_npc()               { return is_npc;            }
int query_invis()                { return is_invis;          }
status query_alias_status()      { return is_alias;          }
status query_brief()             { return brief;             }

int query_ac()                   { return armor_class;       }
int query_armor_class()          { return armor_class;       }
object *query_all_followers()    { return followers;         }
object *query_armor_worn()       { return armor_worn;        }
int query_ac_bonus()             { return ac_bonus;          }

int query_wc()                   { return right_wc;          }
int query_right_wc()             { return right_wc;          }
object query_right_weapon()      { return right_weapon;      }
string query_right_weapon_type() { return right_weapon_type; }

int query_left_wc()              { return left_wc;           }
object query_left_weapon()       { return left_weapon;       }
string query_left_weapon_type()  { return left_weapon_type;  }
string query_attacker() {
  return (primary_attack) ? (string)primary_attack->query_name() : 0;
}

object query_attack()            { return primary_attack;    }  
object query_primary_attack()    { return primary_attack;    }

object *query_secondary_attacks(){ return secondary_attacks; }
object *query_alt_attackers()    { return secondary_attacks; }  

status two_weapons_wielded() {
  if(right_weapon && left_weapon) return 1;
  else return 0;
}

/*** Primary skills ***/ 
 
int query_combat()       { return combat;       }
int query_dexterity()    { return dexterity;    }
int query_intelligence() { return intelligence; }
int query_wisdom()       { return wisdom;       }
int query_charisma()     { return charisma;     }
int query_constitution() { return constitution; }
int query_strength()     { return strength;     }

int query_max_combat()       { return max_combat;       }
int query_max_dexterity()    { return max_dexterity;    }
int query_max_intelligence() { return max_intelligence; }
int query_max_wisdom()       { return max_wisdom;       }
int query_max_charisma()     { return max_charisma;     }
int query_max_constitution() { return max_constitution; }
int query_max_strength()     { return max_strength;     }



/* gender stuff */

int query_gender()    { return gender;      }

status query_neuter() { return !gender;     }  
status query_male()   { return gender == 1; }  
status query_female() { return gender == 2; }  
  
string query_gender_string () {  
  return (gender == 2) ? "female" : (gender == 1) ? "male" : "neuter";
}  
    
string query_pronoun () {  
  return (gender == 2) ? "she" : (gender == 1) ? "he" : "it";
}  
  
string query_possessive () {  
  return (gender == 2) ? "her" : (gender == 1) ? "his" : "its";
}  
  
string query_objective () {  
  return (gender == 2) ? "her" : (gender == 1) ? "him" : "it";
}  

/* primary stats */

void query_primary_stats() {
  string str, stat_str, *stat_name;
  int i;

  stat_name = ({
      "combat", "dexterity", "intelligence", "wisdom",
      "charisma", "constitution", "strength",
  });

  for (i = 0, stat_str = ""; i < sizeof(stat_name); i++) {
    str = capitalize(stat_name[i]) + ":.................";
    str = str[0..15];
    str += query(stat_name[i]) + "/" + query("max_" + stat_name[i]);
    str += "                               ";
    str = str[0..30];
    if (i%2) str += "\n";
    stat_str += str;
  }
  if (i%2) stat_str += "\n";
  write(stat_str);
}


/*************************************************************************/
/* adjust */

int adj_level(int i) {
#ifdef LOG_SET_LEVEL
  log(LOG_SET_LEVEL, level, level + i);
#endif /* LOG_SET_LEVEL */
  if (i > 0) level_drained -= i;
  if (level_drained < 0) level_drained = 0;
  return level += i;
}

int adj_level_drained(int i) {
#ifdef LOG_SET_LEVEL_DRAINED
  log(LOG_SET_LEVEL_DRAINED, level_drained, level_drained + i);
#endif /* LOG_SET_LEVEL_DRAINED */
  return level_drained += i;
}

int adj_wimpy(int i)          { return whimpy += i; }

int adj_hp(int i) {
#ifdef LOG_SET_HP
  log(LOG_SET_HP, hp, hp + i);
#endif /* LOG_SET_HP */
  hp = (hp + i > max_hp) ? max_hp : hp + i;
  if (hp < 0) hp = 0;
  return hp;
}

int adj_max_hp(int i) {
#ifdef LOG_SET_MAX_HP
  log(LOG_SET_MAX_HP, max_hp, max_hp + i);
#endif /* LOG_SET_MAX_HP */
  return max_hp += i;
}

int adj_exp(int i) {
#ifdef LOG_SET_EXP
  log(LOG_SET_EXP, experience, experience + i);
#endif /* LOG_SET_EXP */
  return experience += i;
}

int adj_money(int i) {
#ifdef LOG_SET_MONEY
  log(LOG_SET_MONEY, money, money + i);
#endif /* LOG_SET_MONEY */
  return money += i;
}

int adj_age(int i)           { return age += i; }
int add_alignment(int i)     { return adj_alignment(i); }

int adj_alignment(int i) {
#ifdef LOG_SET_ALIGN
  log(LOG_SET_ALIGN, alignment, alignment + i);
#endif /* LOG_SET_ALIGN */
  return alignment += i;
}

int adj_magic_resist(int i) {
  return magic_resist += ((i > 100) ? 100 : ((i < 0) ? 0 : i));
}

int adj_ac(int i)            { return armor_class += i; }
int adj_armor_class(int i)   { return armor_class += i; }
int adj_ac_bonus(int i)      { return ac_bonus    += i; }

int adj_right_wc(int i)           { return right_wc += i;           }
int adj_right_weapon_bonus(int i) { return right_weapon_bonus += i; }

int adj_left_wc(int i)            { return left_wc += i;            }
int adj_left_weapon_bonus(int i)  { return left_weapon_bonus += i;  }

/*** Primary skills ***/

int adj_combat(int i)       { return combat       += i; }
int adj_dexterity(int i)    { return dexterity    += i; }
int adj_intelligence(int i) { return intelligence += i; }
int adj_wisdom(int i)       { return wisdom       += i; }
int adj_charisma(int i)     { return charisma     += i; }
int adj_strength(int i)     { return strength     += i; }

int adj_constitution(int i) {
  constitution += i;
  max_hp = 60 + constitution * average_hp_multiplier();
  max_hp -= POISON;
  return constitution;
}


/*************************************************************************/
/* adds */

status add_weight(int wt) {
/* causes too long evaluation errors on long lists
  recalc_carry();
*/
  if (wt + weight > strength + 10 + carry_bonus()) return 0;
  weight += wt;
  return 1;
}

int add_exp(int i) {
#ifdef LOG_SET_EXP
  log(LOG_SET_EXP, experience, experience + i);
#endif /* LOG_SET_EXP */
  experience += i;
  return i;
}

int add_money(int i) {
  money += i;
}

/*************************************************************************/
/* show age in clock time */

string show_age(status arg) {
  int i;
  string str;

  str = "Age: ";
  i = age;
  if (i/302400) {
    str += (i/302400) + " Weeks ";
    i = i - (i/302400)*302400;
  }
  if (i/43200) {
    str += (i/43200) + " Days ";
    i = i - (i/43200)*43200;
  }
  if (i/1800) {
    str += (i/1800) + " hours ";
    i = i - (i/1800)*1800;
  }
  if (i/30) {
    str += (i/30) + " minutes ";
    i = i - (i/30)*30;
  }
  str += (i*2) + " seconds.\n";
  if (!arg) write(str);
  return str;
}


/*************************************************************************/
/* level draining stuff */

void restore_level() {
  if (!level_drained) return;
  level_drained -= 1;
  set_exp(GET_NEXT_EXP(query_level()));
  set_level(query_level() + 1);
}

void drain_level() {
  if (level == 1) {
    death();
    return;
  }
  level_drained += 1;
  level -= 1;
  experience -= LOST_EXPERIENCE;
}


/*************************************************************************/
/* spell_immune array stuff */

status query_spell_immunity(string str) {
  if (!spell_immune) spell_immune = ({});
  return (member(spell_immune, str) == -1) ? 0 : 1;
}

status query_spell_immune(string str) {
  return query_spell_immunity(str);
}

void add_spell_immunity(string str) {
  if (!query_spell_immunity(str) && str) spell_immune += ({ str, });
}

void add_spell_immune(string str) {
  add_spell_immunity(str);
}

void remove_spell_immunity(string str) {
  int i;

  if ((i = member(spell_immune, str)) != -1) {
    spell_immune = spell_immune[0..i-1] +
                   spell_immune[i+1..sizeof(spell_immune) - 1];
  }
}

void remove_spell_immune(string str) {
  remove_spell_immunity(str);
}


/*************************************************************************/
/* languages_known array stuff */

status query_language(string str) {
  if (this_player() && this_object()->query_level() > 19) return 1;
  return (member(languages_known, str) == -1) ? 0 : 1;
}

status query_followers(object obj) {
  return (member(followers, obj) == -1) ? 0 : 1;
}

void add_language(string str) {
  if (!query_language(str) && str) languages_known += ({ str, });
}

void add_followers(object obj) {
  if (!query_followers(obj) && obj) followers += ({ obj, });
}

void remove_language(string str) {
  int i;

  if ((i = member(languages_known, str)) != -1 && str != "common") {
    languages_known = languages_known[0..i-1] +
                      languages_known[i + 1..sizeof(languages_known) -1 ];
  }
}


void remove_followers(object obj) {
  int i;

  if ((i = member(followers, obj)) != -1) {
    followers = followers[0..i-1] + followers[i+1..sizeof(followers) -1];
  }
}


/*************************************************************************/

