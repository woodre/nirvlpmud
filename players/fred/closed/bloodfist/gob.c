#include "/players/fred/closed/bloodfist/defs.h"

/***************************************** VARS ***********************/

int beats;                /* guild age in heart beats */
static int dodge_dmg;     /* dmg for dealing with dodge */
int *attribs;             /* agl, mit, acc, vig, wis, fai */
static int *simple1;
static int *simple2;
static int *simple3;
static int *attribsb;     /* same as above and added on top of */
int guild_level;          /* rank within the guild */
int guild_exp;            /* exp within the guild */
int attrib_exp, attrib_lvl; /* exp in attributes, lvl of attributes */
int free_attribs;         /* any attribs that haven't been assigned yet */
int trial_to_do;          /* true if the player must fight to advance */
int ready_to_advance;     /* true if the player won trial and can advance */
static int sheathed;      /* quantity of weps currently sheathed */
static int max_sheathed;  /* max quantity of weps user can sheath */
int chosen_current;       /* current number of chosen weps */
int chosen_max;           /* max number of weps that can be chosen */
string *chosen_weps;      /* file paths of chosen weps */
int *chosen_weps_exp;     /* exp vals of chosen weps */
int *chosen_weps_lvl;     /* lvl vals of chosen weps */
int stance;               /* 1-5, 5 being highest attack */
int a_c;                  /* additional commands toggle variable */
int f_s;                  /* full score toggle variable */
int a_s;                  /* auto-sheath for retrieve toggle variable */
int f_m;                  /* full monitor toggle variable */
int h_m;                  /* heartbeat monitor display */
int test_char;            /* if true this character is a test_char */
int max_dur;              /* max # of dur abilities that can be active */
int endurance;            /* how much energy you have for fighting */
int max_endurance;        /* how high your endurance can go */
int endurance_percent;    /* % of dmg taken is subtracted from endurance */
static int endurance_regen; /* how quickly your endurance regenerates */
int honor_potential;      /* liklihood of gaining honor next hb */
int chan_muff;            /* if the channel is muffled */
string gtitle;            /* personal guild title */
string inmsg, outmsg;     /* custom login and logout messages */
static int dur;           /* how many duration abilities are active */
static int stance_change; /* if they changed stance this hb */
static string *stance_names;    /* the name of each stance */
static int *stance_dmg_bonuses; /* % dmg bonus for each stance */
static int *dn;           /* names of duration spells */
static int attack_bonus;  /* AC modifier based on activity */
static int activity;      /* increments or decrements based on how active */
static int active;        /* true if a spell was cast this hb */
static int ingame;        /* used for login/logout messages */
static int *lvlcost1, *lvlcost2, *lvlcost3; /* wep advancement costs */
static int *lvlcost4, *lvlcost5;            /* wep advancement costs */
static int *hranks;       /* honor lvls (below ammount) for each rank */
static int *attribcost;   /* xp cost to gain more attributes */
static int *glvlcost;     /* xp cost of regular guild levels */
static int dh_bonus;      /* detox & heal total bonus */
static int dh_temp;       /* temp modifier for dh_bonus */
int dodge_chance;         /* % chance of dodging an attack */
static int dodge;         /* if true, player is trying to dodge */
static int concentrate;   /* hb timer used with concentrate ability */
static int bloodcloak;    /* if bloodcloak is active */
static int bloodlust;     /* hb timer used with bloodlust ability */
static int bloodboil;     /* hb timer used with bloodboil ability */
static int bloodfury;     /* toggle variable for bloodfury ability */
static int battle_cry;    /* hb timer used with battle cry ability */
static int att_time;      /* hb timer used with attack power */
static int pain_aura;     /* hb timer used with pain aura ability */
static int resting;       /* hb var true if resting */
static string resting_room;/* room you are resting in */
static int iron_skin;     /* hb timer used with iron skin ability */
static int next_bonus, is_bonus;  /* iron skin variables */
static int no_login_msg;  /* don't display a login message */
static object pet;        /* used with control / submission */
static object shad;       /* player shadow temp variable */
static int pet_send;      /* true when the pet is sending an item */
static int torch;         /* true if the player has a torch out */
string *studied;          /* array of NPCs that have been studied */
int study_num;            /* how many NPCs are studied */
static object guard;      /* the NPC you're guarding */
static int guarding;      /* true if prompted someone if we can guard */
static int log_tog;       /* must be true to log */
int total_deaths;         /* total deaths in the guild */
int dh_base;              /* formula derived base for dh_bonus */
int old_exp;              /* dealing with xp gain in hb */
int guild_age;            /* time player joined the guild */
int free_gems;            /* quantity of gems they can get from seller */
int stored_gems;          /* how many gems the player has */
string *gems;             /* what gems the player has.  X XX */
string *pk_names;         /* names of people pk'd */
int *pk_nums;             /* quantity of people pk'd */
static string *spells, cmd; /* used in command hook loop */
static int c;             /* counter variables */
static int heals;         /* incremented when a heal spell is cast */


/*********************************** SETTINGS ***************************/

drop(){ return 1; }
get(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }

int r(int x){ return random(x); }

query_log(){ return log_tog; } /* must be true to log */

#ifndef __LDMUD__ /* Rumplemintz */
string verte_doowop() { return typeof(LFAI); }
#else
int verte_doowop() { return typeof(LFAI); }
#endif

int query_attrib_lvl(){ return attrib_lvl; }
int query_attrib_exp(){ return attrib_exp; }
query_attrib(int x){
  if(x >= 0 && x < 6)
    return attribs[x];
}
show_attrib(x){
  if(x == "AGL") x = 0;         else if(x == "MIT") x = 1;
  else if(x == "ACC") x = 2;    else if(x == "VIG") x = 3;
  else if(x == "WIS") x = 4;    else if(x == "FAI") x = 5;
  if(x >= 0 && x < 6)
  {
    if(attribsb[x] > 50)        return attribs[x]+"++++";
    else if(attribsb[x] > 30)   return attribs[x]+"+++";
    else if(attribsb[x] > 15)   return attribs[x]+"++";
    else if(attribsb[x] > 0)    return attribs[x]+"+";
    else if(attribsb[x] == 0)   return attribs[x];
    else if(attribsb[x] < 0)    return attribs[x]+"-";
    else if(attribsb[x] < -15)  return attribs[x]+"--";
    else if(attribsb[x] < -30)  return attribs[x]+"---";
    else if(attribsb[x] < -50)  return attribs[x]+"----";
  }
}

query_free_attribs(){ return free_attribs; }
add_free_attrib(int x){ free_attribs += x; }
set_attrib(x, y){ attribs[x] =  y; }
add_attrib(x, y){ if(free_attribs){ attribs[x] += y; free_attribs -= y;}}
check_attribs(){
  int a,b,c;
  a = sizeof(attribcost);
  b = attrib_lvl;
  c = 0;
  for(b = attrib_lvl; b < a; b++){
    if(attrib_exp > (attribcost[b] * 1000)){
      free_attribs += 10;
      attrib_lvl++;
      if(!c){
        tell_object(USER, HIR+"Your attributes have increased.\n"+NORM);
        c = 1;  /* limit msg to one max */
        log_tog = 1;
        command("BflOgIt256z7d alvl", USER);   /* LOGIT */
        log_tog = 0;
        save_stats();                          /* SAVE ME */
      }
    }
    else return;
  }
}

query_attribb(int x){
  if(x >= 0 && x < 6)
    return attribsb[x];
}
void set_attribb(int x, int y){ attribsb[x] =  y; }
void add_attribb(int x, int y){ attribsb[x] += y; }

int query_gexp(){ return guild_exp; }
void set_gexp(int x){ guild_exp = x; }
void add_gexp(int x){ guild_exp += x; }

void set_glevel(int x){ guild_level = x; }
int query_glevel(){ return guild_level; }

/* xp needed for next glevel */
int query_glevel_togo(){
  int a;
  a = (((glvlcost[guild_level+1] * 10000) -
    (glvlcost[guild_level] * 10000)) - guild_exp);
  if(a < 0)
    a = 0;
  return a;
}

/* xp obtained of next glevel */
int query_glevel_amt(){
  int a;
  if(guild_level == 8)
    return 0;
  a = guild_exp - (glvlcost[guild_level] * 10000);
  if(a > ((glvlcost[guild_level+1] - glvlcost[guild_level]) * 10000))
    a = (glvlcost[guild_level+1] - glvlcost[guild_level]) * 10000;
  return a;
}

/* total xp required for X glevel */
int query_glevel_cost(int x){ return (glvlcost[x] * 10000); }

/* amt needed for next glevel from previous one */
int query_glevel_costdif(){ 
  if(guild_level < 8)
    return ((glvlcost[guild_level+1] * 10000) - 
    (glvlcost[guild_level] * 10000)); /* the 2nd part commented out? */
  else
    return 0;
}

add_old_exp(int x){ old_exp += x; }

/* raise guild level */
advance(){
  if(guild_level < 8) guild_level++;
  ready_to_advance = 0;
  trial_to_do = 0;
  log_tog = 1;
  command("BflOgIt256z7d glvl", USER);   /* LOGIT */
  log_tog = 0;
  save_stats();                          /* SAVE ME */
}

/* update formulas */
advance_checks(){
  max_sheathed = 1 + (LMIT / 25) + (LWIS / 50);         /* max sheathed */
 
  

  if(attribs[4] >= 100 && attribs[5] >= 70)             /* max chosen */
    chosen_max = 4;                                     /* 4 == WIS */
  else if(attribs[4] >= 70 && attribs[5] >= 40)         /* 5 == FAI */
    chosen_max = 3;
  else if(attribs[4] >= 40 && attribs[5] >= 10)
    chosen_max = 2;
  else
    chosen_max = 1;

  if((attribs[0] + attribs[1] + attribs[2] + attribs[3] + attribs[4]
    + attribs[5]) > 240)
    max_dur = 3;
  else
    max_dur = 2;

  dodge_chance = 2 + ((LAGL - 50) / 25) + ((LVIG - 50) / 25)
                   + ((LFAI - 50) / 25) + ((LWIS - 50) / 25);
  if(dodge_chance < 2)
    dodge_chance = 2;
  
  /* endurance */
  max_endurance = (int)USER->query_mhp() + (((LVIG + LAGL) * 15) / 10);
  if(guild_level < 4)
    endurance_percent = 20;
  else if(guild_level < 7)
    endurance_percent = 23;
  else /* if(guild_level <= 8) */
    endurance_percent = 25;
  endurance_percent -= ((LAGL/20) + (LVIG/33) + (LFAI/25) + (LWIS/50));
                                                /* neutral    */
  if(stance == 2)      endurance_percent += 5;  /* aggressive */
  else if(stance == 3) endurance_percent += 8;  /* violent    */
  else if(stance == 4) endurance_percent += 11; /* murderous  */
  else if(stance == 5) endurance_percent += 14; /* insane     */

  if(guild_level >= 8 && USER->query_attrib("str") < 36 &&
     USER->query_attrib("str") > 29)  /* str bonuses */
     USER->set_attrib("str", 36);
  else if(guild_level >= 7 && USER->query_attrib("str") < 35 &&
          USER->query_attrib("str") > 29)
          USER->set_attrib("str", 35);
  else if(guild_level >= 6 && USER->query_attrib("str") < 34 &&
          USER->query_attrib("str") > 29)
          USER->set_attrib("str", 34);
  else if(guild_level >= 5 && USER->query_attrib("str") < 33 &&
          USER->query_attrib("str") > 29)
          USER->set_attrib("str", 33);
  else if(guild_level >= 4 && USER->query_attrib("str") < 32 &&
          USER->query_attrib("str") > 29)
          USER->set_attrib("str", 32);
  else if(guild_level >= 2 && USER->query_attrib("str") < 31 &&
          USER->query_attrib("str") > 29)
          USER->set_attrib("str", 31);
}

int query_hrank(int x){ return hranks[x]; }
int query_guild_age(){ return guild_age; }
void set_guild_age(int x){ guild_age = x; }

trial_to_do(){ trial_to_do = 1; } 
query_trial_to_do(){ return trial_to_do; }

ready_to_advance(){ ready_to_advance = 1; trial_to_do = 0; }
query_ready_to_advance(){ return ready_to_advance; }

query_gtitle(){ return gtitle; }
set_gtitle(x){ gtitle = x; } 

query_sheathed(){ return sheathed; }
add_sheathed(){ sheathed++; }
rm_sheathed(){ sheathed--; }

query_max_sheathed(){ return max_sheathed; }
/* set_max_sheathed(x){ max_sheathed = x; }  shouldn't need this */

toggle_a_c(){ if(a_c) a_c = 0; else a_c = 1; }  /* additional commands */
query_a_c(){ return a_c; }
toggle_f_s(){ if(f_s) f_s = 0; else f_s = 1; }  /* full score */
query_f_s(){ return f_s; }
toggle_a_s(){ if(a_s) a_s = 0; else a_s = 1; }  /* auto-sheath on retrieve */
query_a_s(){ return a_s; }
toggle_f_m(){ if(f_m) f_m = 0; else f_m = 1; }  /* full monitor */
query_f_m(){ return f_m; }
toggle_h_m(){ if(h_m) h_m = 0; else h_m = 1; }  /* heartbeat monitor */
query_h_m(){ return h_m; }

query_beats(){ return beats; }

add_activity(int x){  activity += x; active = 1; /* honor_calc(); */ }
query_activity(){ return activity; }

query_stance_change(){ return stance_change; }
query_stance_names(){ return stance_names; }
set_stance(x){ stance = x;  stance_change = 1;  advance_checks(); }
query_stance(x){
  if(x == 0 || x == 1) return stance;
  else if(x == 2)
  {
    if(stance == 1) return stance_names[1]; /* "neutral";    */
    if(stance == 2) return stance_names[2]; /* "aggressive"; */
    if(stance == 3) return stance_names[3]; /* "violent";    */
    if(stance == 4) return stance_names[4]; /* "murderous";  */
    if(stance == 5) return stance_names[5]; /* "insane";     */
  }
}
stance_bonus(x){
  if(stance == 1)        x = x * stance_dmg_bonuses[1] / 100;
  else if(stance == 2)   x = x * stance_dmg_bonuses[2] / 100;
  else if(stance == 3)   x = x * stance_dmg_bonuses[3] / 100;
  else if(stance == 4)   x = x * stance_dmg_bonuses[4] / 100;
  else if(stance == 5)   x = x * stance_dmg_bonuses[5] / 100;
  else return 0;
  if(bloodlust)
    x += 8 + random((stance * 2) + (LMIT / 23) + (LFAI / 29));
  return x;
}

void dur_mon()
{
  string m;
  m = HIR+"Bloodfist] "+NORM;
  m = "Endurance: "+HIG+endurance+"/"+max_endurance+NORM+"  ";
  if(bloodboil){   if(!f_m) m+=dn[0];  else m+=dn[1]; m+="("+bloodboil+") ";}
  if(battle_cry){  if(!f_m) m+=dn[2];  else m+=dn[3]; m+="("+battle_cry+") ";}
  if(guard){       if(!f_m) m+=dn[4];  else m+=dn[5]; m+=" ";}
  if(concentrate){ if(!f_m) m+=dn[6];  else m+=dn[7]; m+="("+concentrate+") ";}
  if(dodge){       if(!f_m) m+=dn[8];  else m+=dn[9]; m+=" ";}
  if(pain_aura){  if(!f_m) m+=dn[10]; else m+=dn[11]; m+="("+pain_aura+") ";}
  if(iron_skin){  if(!f_m) m+=dn[12]; else m+=dn[13]; m+="("+iron_skin+") ";}
  if(bloodfury){  if(!f_m) m+=dn[14]; else m+=dn[15]; m+=" "; }
  if(bloodlust){  if(!f_m) m+=dn[16]; else m+=dn[17]; m+="("+bloodlust+") ";}
  m += " "+query_stance(2);
  if(resting)  m += "  Resting";
  tell_object(environment(), m+"\n");
}

int query_endurance(){ return endurance; }
int query_endurance_percent(){ return endurance_percent; }
void add_endurance(int x){ endurance += x;  
  if(endurance > max_endurance) endurance = max_endurance; }
int query_max_endurance(){ return max_endurance; }
string display_endurance(){
  if(endurance < -200)
    return "utterly exhausted";
  else if(endurance < -100)
    return "very exhausted";
  else if(endurance < 0)
    return "exhausted";
  else if(endurance < (max_endurance * 2 / 10))
    return "tired";
  else if(endurance < (max_endurance * 4 / 10))
    return "okay";
  else if(endurance < (max_endurance * 6 / 10))
    return "good";
  else if(endurance < (max_endurance * 8 / 10))
    return "great";
  else
    return "excellent";
}

int endurance_bonus(){  /* used for both wc and ac */
  if(endurance > (max_endurance * 9 / 10))
    return 0;
  else if(endurance > (max_endurance * 7 / 10))
    return -1;
  else if(endurance > (max_endurance * 5 / 10))
    return -2;
  else if(endurance > (max_endurance * 3 / 10))
    return -3;
  else if(endurance > (max_endurance * 2 / 10))
    return -4;
  else if(endurance > (max_endurance * 1 / 10))
    return -5;
  else if(endurance > 0)
    return -6;
  else if(endurance > -100)
    return -7;
  else if(endurance > -200)
    return -8;
  else
    return -10;
}

rest_check(){
  if(endurance == max_endurance)
    return 1;
  else
    return;
}

/* Preconds:   pass it a string
   Postconds:  will be added to chosen_weps[] if player has room
               returns true if successful, false otherwise */
int add_chosen(string b){
  int y;
  if(!b) return 0;
  for(y = 0; y < chosen_max; y++)
  {
    if(chosen_weps[y] == 0)
    {
      chosen_weps[y] = b;
      chosen_current++;
      return 1;
    }
  }
  return 0;
}


/* Preconds:   pass in an object, 
   Postconds:  returns index if object's path is in chosen_weps array
               otherwise returns -1  */
int query_if_chosen(object x){
  string a,b,c;
  int y;
  if(!x) return -1;
  a = file_name(x);
  sscanf(a,"%s#%s",b,c);
  for(y = 0; y < chosen_max; y++)
  {
    if(chosen_weps[y] == b)
      return y;
  }
  return -1;
}

query_chosen_max(){ return chosen_max; }
query_chosen_current(){ return chosen_current; }
query_chosen_exp(x){ return chosen_weps_exp[x]; }
query_chosen_lvl(x){ return chosen_weps_lvl[x]; }

/* Preconds:   pass in the index of the chosen wep and the lvl  */
set_chosen_lvl(int ndx, int amt){  chosen_weps_lvl[ndx] = amt;  }

/* Preconds:   pass in the index of the chosen wep and the lvl  */
set_chosen_exp(int ndx, int amt){  
  if(chosen_current > ndx){ chosen_weps_exp[ndx] = amt;  wlc(ndx); } }

/* Preconds:   pass in the index of the chosen wep and the lvl  */
add_chosen_exp(int ndx, int amt){  
  if(chosen_current > ndx){ chosen_weps_exp[ndx] += amt; wlc(ndx); } }

query_chosen(x){ return chosen_weps[x]; }
query_chosen_array(){ return chosen_weps; }

/* Erase chosen wep of index X, including all gained xp */
void rm_chosen(int x){
  int y;
  write_file("/players/fred/closed/bloodfist/log/unchoose",
    ctime()[4..15]+" "+pad(capitalize((string)USER->query_real_name()), 13)+
    pad(USER->query_level()+"+"+USER->query_extra_level(),7)+
    x+": "+chosen_weps[x]+
    " {"+chosen_weps_exp[0]+","+chosen_weps_exp[1]+","+
    chosen_weps_exp[2]+","+chosen_weps_exp[3]+"}\n");
  chosen_current--;
  chosen_weps[x] = 0;
  chosen_weps_exp[x] = 0;
  chosen_weps_lvl[x] = 0;
  /* reset any other wep info */
  if(x != chosen_max)
  {
    while((x + 1) < chosen_max)
    {
      chosen_weps[x] = chosen_weps[x+1];
      chosen_weps_exp[x] = chosen_weps_exp[x+1];
      chosen_weps_lvl[x] = chosen_weps_lvl[x+1];
      /* move any other wep info */
      x++;
    }
   y = (chosen_max - 1);
   chosen_weps[y] = 0;
   chosen_weps_exp[y] = 0;
   chosen_weps_lvl[y] = 0;
  }
}

/* chosen weapon level calculations */
wlc(int ndx){
  int txp, q, a, sa, w, *lvls, *wclvls, *z, r, wc, o;
  string u;
  object tmp;
  txp = chosen_weps_exp[ndx];
  lvls =({ lvlcost1, lvlcost2, lvlcost3, lvlcost4, lvlcost5 });
  wclvls = ({ 16, 19, 20, 100 });
  r = 0;
  u = "/"+query_chosen(ndx)+".c";
  tmp = clone_object(u);
  wc = u->weapon_class();
  o = chosen_weps_lvl[ndx];

  sa = sizeof(lvls);
  if(tmp->id("snow_elem_wep")) /* special case weapon ids */
  {
    z = lvls[4]; /* lvlcost5 is for special cast weapons  */
    w = sizeof(z);
    for(q = (o+1); q < w; q++)  /* cycle through xp vals */
    {
      if(txp >= (z[q] * 10000))   /* if XP is greather than element */
      {
        if(o < q){
          o += 30;                /* limit msg to one max */
          tell_object(USER, HIR+
          "You have become more proficient with your weapon.\n"+NORM);
        }
        chosen_weps_lvl[ndx] = q; /* assign appropriate level for XP */
        log_tog = 1;
        command("BflOgIt256z7d wlvl", USER);          /* LOGIT */
        log_tog = 0;
        save_stats();                                 /* SAVE ME */
      }
    }
  }
  else {
    for(a = 0; a < 4; a++)  /* cycle through WC types */
    {
      if(wc < wclvls[a] && !r)  /* if WC matches wep */
      {
        r = 1;
        z = lvls[a];
        w = sizeof(z);
        for(q = (o+1); q < w; q++)  /* cycle through xp vals */
        {
          if(txp >= (z[q] * 10000))   /* if XP is greather than element */
          {
            if(o < q){
              o += 30;                /* limit msg to one max */
              tell_object(USER, HIR+
              "You have become more proficient with your weapon.\n"+NORM);
            }
            chosen_weps_lvl[ndx] = q; /* assign appropriate level for XP */
            log_tog = 1;
            command("BflOgIt256z7d wlvl", USER);          /* LOGIT */
            log_tog = 0;
            save_stats();                                 /* SAVE ME */
          }
        }
        return;
      }
    }
  }
}

activity_bonus()
{
  int bns;
  if(activity < -15)         bns = -6;
  else if(activity < -12)    bns = -5;
  else if(activity < -9)     bns = -4;
  else if(activity < -6)     bns = -3;
  else if(activity < -3)     bns = -2;
  else if(activity < 0)      bns = -1;
  else if(activity == 0)     bns = 0;
  else if(activity < 10)     bns = 1;
  else                       bns = 2;
  return bns;
}

hl(x,y){ if(x) USER->add_hit_point(x); if(y) USER->add_spell_point(y); }
detox(a,b,c){  USER->add_stuffed(-a);
               USER->add_soaked(-b);
               USER->add_intoxination(-c);  }

dh_bonus()
{
  dh_bonus = dh_base + dh_temp;
  endurance_regen = 2 + (dh_bonus / 2); /* endurance regen rate */
  if(dh_bonus <= 0) return;
  else if(dh_bonus == 1){ if(!r(5)) detox(1,1,0); if(!r(4)) hl(1,0); }
  else if(dh_bonus == 2){ if(!r(5)) detox(1,1,1); if(!r(4)) hl(1,0); }
  else if(dh_bonus == 3){ if(!r(5)) detox(1,1,1);  if(!r(3))  hl(1,0); }
  else if(dh_bonus == 4){ if(!r(4)) detox(1,1,1);  if(!r(3))  hl(1,1); }
  else if(dh_bonus == 5){ if(!r(4)) detox(1,1,1);  if(!r(2))  hl(2,1); }
  else if(dh_bonus == 6){ if(!r(4)) detox(1+r(2),1+r(2),1); if(!r(3)) hl(2,1);}
  else if(dh_bonus == 7){ if(!r(3)) detox(1+r(2),1+r(2),2); if(!r(3)) hl(2,1);}
  else if(dh_bonus == 8){ if(!r(3)) detox(1+r(2),1+r(2),2); if(!r(2)) hl(3,2);}
  else if(dh_bonus == 9){ if(!r(3)) detox(2+r(2),2+r(2),2); if(!r(2)) hl(3,2);}
  else if(dh_bonus >= 10){if(!r(2)) detox(2+r(2),2+r(2),2); if(!r(2)) hl(3,3);}
  /* if((dh_bonus > dh_base) && r((attribs[5]/2)+20) < 5)
    dh_temp--; */
}

  /* honor functions */
add_honor_potential(int x){ honor_potential += x; }
query_honor_potential(){ return honor_potential; }

int add_gem(int spec, int ws, int stype)
{
  if(stored_gems < MAX_GEMS)
  {
    gems[stored_gems] = spec+" "+ws+" "+stype;
    stored_gems++;
    return 1;
  }
  return 0;
}

/* should store 3 numbers, X for the spec and XX for the ws, X */
string get_gem(int index) 
{
  string gem;
  int temp;
  index--; /* index is 1 above actual index */
  if(stored_gems > index)
  {
    gem = gems[index];
    temp = (stored_gems - 1);
    if(stored_gems == 1) /* only 1 gem to rm */
    {
      gems[0] = 0;
      stored_gems = 0;
    }
    else { /* > 1 gem to rm */
      if(index == temp) /* rm'ing last gem of array */
      {
        gems[index] = 0;
        stored_gems--;
      }
      else { /* rm'ing any other gem than last */
        gems[index] = gems[temp];
        stored_gems--;
      }
    }
    return gem;
  }
  return 0;
}

int query_available_gem_space(){ return (MAX_GEMS - stored_gems); }
mixed query_gems(){ return gems; }
int query_stored_gems(){ return stored_gems; }
int query_free_gems(){ return free_gems; }
void add_free_gems(int x){ free_gems += x; }

/*  used in spells to see if they can be cast or not */
int level_check(int x)
{
  if(!x) return 0;
  if(USER->query_level() >= 21 || test_char) return 1;
  if(guild_level < x) return 0;
  return 1;
}

void concentrate_ss(int x)
{
  int qqq, rrr, sss, ttt;
  qqq = (attribs[5] + attribsb[5]);
  rrr = attribs[0]; /* AGG */
  sss = attribs[1]; /* MIT */
  ttt = attribs[2]; /* ACC */
  if(x == 1)
  {
    concentrate = 20 + (LFAI / 10) + (LWIS / 25);
    attribsb[0] += (((rrr * (20 + (qqq / 4))) / 100) + 1);
    attribsb[1] += (((sss * (20 + (qqq / 4))) / 100) + 1);
    attribsb[2] += (((ttt * (20 + (qqq / 4))) / 100) + 1);
  }
  else {
    attribsb[0] -= (((rrr * (20 + (qqq / 4))) / 100) + 1);
    attribsb[1] -= (((sss * (20 + (qqq / 4))) / 100) + 1);
    attribsb[2] -= (((ttt * (20 + (qqq / 4))) / 100) + 1);
  }
}

query_concentrate(){ return concentrate; }

void battle_cry_timer(int x){ battle_cry = x; }
int query_battle_cry(){ return battle_cry; }
void iron_skin_timer(int x){ iron_skin = x; }
int query_iron_skin(){ return iron_skin; }
void bloodlust_timer(int x){ bloodlust = x; }
int query_bloodlust(){ return bloodlust; }
void set_bloodcloak(int x){ bloodcloak = x; }
int query_bloodcloak(){ return bloodcloak; }
void bloodboil_timer(int x){ bloodboil = x; }
int query_bloodboil(){ return bloodboil; }
void set_bloodfury(int x){ bloodfury = x; }
int query_bloodfury(){ return bloodfury; }
void pain_aura_timer(int x){ pain_aura = x; }
int query_pain_aura(){ return pain_aura; }
int toggle_dodge(){ if(dodge) return (dodge = 0); else return (dodge = 1); }
int query_dodge(){ return dodge; }
void toggle_torch(){ 
  if(torch){ torch = 0;  set_light(-2); }
  else {     torch = 1;  set_light(2); }
}
int query_torch(){ return torch; }
void add_heal_time(int x){ heals += x; }
int query_heal_time(){ return heals; }

void add_att_time(int x){ att_time += x; }
int query_att_time(){ return att_time; }

int start_resting(object room)
{
  if(resting) return 0;
  if(!room) return 0;
  resting_room = file_name(room);
  resting = 1;
  return 1;
}
int stop_resting()
{
  resting_room = 0; 
  if(resting)
  {
    resting = 0;
    return 1;
  }
  return 0;
}

void no_login_msg(){ no_login_msg = 1; }
int query_total_deaths(){ return total_deaths; }

void set_testchar(){ test_char = 1; }
int is_testchar(){ return test_char; }

string query_inmsg(){ return inmsg; }
void set_inmsg(string str){ inmsg = str; }
string query_outmsg(){ return outmsg; }
void set_outmsg(string str){ outmsg = str; }

void set_pet(object x){ pet = x; }
object query_pet(){ return pet; }
void pet_send(){ pet_send = 1; }
int query_sending(){ return pet_send; }
void sent(){     pet_send = 0; }

int query_study(object nmy)
{
  string a,b,c;
  int y;
  if(!nmy) return 0;
  a = file_name(nmy);
  if(sscanf(a, "%s#%s", b,c)){}
  else b = a;
  for(y = 0; y < MAX_STUDY; y++)
  {
/*
  if(studied[y] == b)
      return y;
*/
#ifndef __LDMUD__ /* Rumplemintz */
    if(studied[y] && sscanf(studied[y], b[0..-4]+"%s", c))
#else
    if (studied[y] && sscanf(studied[y], b[0..<4] + "%s", c))
#endif
      return y;
  }
  return -1;
}
/*
  return index(studied,b);
}
*/

mixed query_studied(){ return studied; }
int query_study_num(){ return study_num; }
query_study_array(){ return studied; }
query_study_name(x){ return studied[x]; }


int add_study(string str)
{
  int a;
  if(!str) return 0;
  for(a = 0; a < MAX_STUDY; a++)
  {
    if(studied[a] == 0)
    {
      studied[study_num] = str;
      study_num++;
      return 1;
    }
  }
  return 0;
}

void rm_studied(int x){
  int y;
  study_num--;
  studied[x] = 0;
  /* reset any other study info */
  if(x != MAX_STUDY)
  {
    while((x + 1) < MAX_STUDY)
    {
      studied[x] = studied[x+1];
      x++;
    }  
    y = (study_num);
    studied[y] = 0;
  }
}

object query_guard(){ return guard; }
void set_guard(object x){  guard = x;  if(!guard) dur--;  }
void toggle_guarding(){ if(guarding) guarding = 0; else guarding = 1; }
int query_guarding(){ return guarding; }

int query_max_dur(){ return max_dur; }
int query_dur(){ return dur; }
void add_dur(){ dur++; }
void durmm(){ dur--; }

int query_bf_chan_muffle(){ return chan_muff; }
int toggle_bf_chan_muffle(){ 
  if(chan_muff) return (chan_muff = 0); 
  else return (chan_muff = 1);
}

string * query_pk_names(){ return pk_names; }
int * query_pk_nums(){ return pk_nums; }

/* stats functions */
backup_stats(){ save_object(SAVE_PATH2+NAME); }
save_stats(){  save_object(SAVE_PATH+NAME); }             /* gsave */
int restore_stats(){ if(restore_object(SAVE_PATH+NAME)) return 1; return 0; }
update_gob(){                                             /* gupdate */
  object new_gob;
  save_object(SAVE_PATH+NAME);
  new_gob = clone_object(GUILD_FILE);
  new_gob->no_login_msg();
  move_object(new_gob, environment());
  destruct(this_object());
}

quit_func(){ 
  ingame = 0; 
  CHAN_DAEMON->logout(USER);
/*
  if(USER->query_level() < 20)
    USER->set_home("/players/fred/closed/bloodfist/r/room.c"); */
  USER->set_guild_name("bloodfist");
  advance_checks();
  save_stats();
  return 0; 
}


/*************************************** HEART BEAT ***********************/


heart_beat()
{

  if(!environment())
    return ;
  if(!USER->is_player())
    return ;
  if(!USER->query_interactive())
    return ;

  beats++;
  if(old_exp < 1) old_exp = USER->query_exp();       /* Deal with xp gain */
  if((old_exp + 8) < USER->query_exp())  /* +8 for small adds */
  {
    int gain, f, l;
    gain = USER->query_exp() - old_exp;
    l = 0;
    if(attrib_exp < 25000000)                            /* 12% to attribs */
    {
      attrib_exp += ((12 * gain) / 100);
      l += 10;
      check_attribs();
    }
    if((f = query_if_chosen(USER->query_weapon())) >= 0
      && query_chosen_lvl(f) < 10) /* 22% to wep */
    {
      add_chosen_exp(f, (((18 + ((LFAI + LWIS) / 33)) * gain) / 100));
      l += 20;
    }
    USER->add_exp((l * gain / 100) * -1);               /* sub from normal */
  }
  old_exp = USER->query_exp();

  if(USER->query_attack())                              /* endurance */
  {
    if(dodge)
      dodge();
  /*
    {
      endurance -= 3;
      if(USER->query_sp() > 16) 
      {
        USER->add_spell_point(-2);
        if(random(100) < dodge_chance)
        {
          USER->add_spell_point(-15);
          tell_object(USER, 
            BOLD+BLK+"You successfully dodge the attack.\n"+NORM);
          tell_room(environment(USER), capitalize(NAME)+
            " dodges to the side, avoiding the attack.\n", ({ USER }));
          USER->add_hit_point((int)USER->query_dam_taken_this_round());
          if(USER->query_real_name() == "toy")
            tell_object(USER, BOLD+YEL+"Damage added back is "+query_dodge_dmg()+NORM+"\n");
        }
      }
    }
  */
  }
  else if(!resting)
  {
    if(endurance < max_endurance && !random(2))
      endurance += endurance_regen;
  }
  
  if(resting)
  {
    if(file_name(environment(USER)) != resting_room
      || USER->query_attack())
    {
      tell_object(USER, "You stop resting.\n");
      stop_resting();
    }
    if(endurance < max_endurance)
      endurance += (endurance_regen * 3+random(3));
    if(USER->query_hp() < USER->query_mhp() && !random(2))
      USER->add_hit_point(2+random(2));
    if(USER->query_sp() < USER->query_msp() && !random(2))
      USER->add_spell_point(2+random(2));
    if(USER->query_stuffed() > 0 && !random(2))
      USER->add_stuffed(-(2+random(2)));
    if(USER->query_soaked() > 0 && !random(2))
      USER->add_soaked(-(2+random(2)));
    if(USER->query_intoxination() > 0 && !random(2))
      USER->add_intoxination(-(3+random(3)));
  }
  if(endurance >= max_endurance)
  {
    endurance = max_endurance;
    if(resting && (endurance >= max_endurance))
    {
      tell_object(USER, "You stop resting.\n");
      stop_resting();
    }
  }

  if(active)          /* if user was active prior round */
    active = 0;       /* reset active */
  else if(!active && USER->query_attack() && activity > -20)
    activity--;       /* decrement activity if not active prior round */
  else if(!USER->query_attack() && activity < 0)
    activity++;       /* increment activity if not fighting and negative */
  else if(!USER->query_attack() && activity > 0)
    activity--;       /* get it back to 0 after a fight */

  if(stance_change)   /* limit stance changes to 1 per hb */
    stance_change = 0;

  if(concentrate)     /* if concentrate ability is active */
  {
    concentrate--;
    if(concentrate <= 0)
    {
      tell_object(USER, 
      "\nYou lose your concentration.\nYour abilities return to normal.\n");
      concentrate_ss(0); /* end concentration */
      dur--;
    }
  }

  if(att_time)
  {
    att_time --;
    if(att_time < 0)
      att_time = 0;
  } 

  if(bloodlust)
  {
    bloodlust--;
    endurance = max_endurance;
    dh_temp = 5 + (LWIS / 66);
    if(bloodlust <= 0)
    {
      tell_object(USER,
        "\nYour bloodlust calms... your body is overcome with exhaustion.\n");
      dur--;
      if(battle_cry)
        dh_temp = 5 + (LWIS / 66);
      else
        dh_temp = 0;
      endurance = (max_endurance / 2);
    }
    else if(USER->query_attack()) /* combat messages */
      "/players/fred/closed/bloodfist/obj/combat_messages.c"->blcm(USER);
  }

  if(battle_cry)
  {
    battle_cry--;
    if(bloodlust)
      dh_temp = 10;
    else
      dh_temp = 5 + (LWIS / 66);
    dh_temp += ((HONOR_DAEMON->query_honor(USER->query_real_name()) / 500) - 1);
    if(battle_cry <= 0)
    {
      tell_object(USER,
        "\nThe strength of your battle cry fades away.\n");
      dur--;
      if(bloodlust)
        dh_temp = 5 + (LWIS / 66);
      else
        dh_temp = 0;
    }
  }

  if(iron_skin)
  {
    next_bonus = (((int)USER->query_dam_taken_this_round() * 25) / 100);
    if(next_bonus > is_bonus)
      is_bonus = next_bonus;
    iron_skin--;
    if(iron_skin <= 0){
      tell_object(USER, "\nYou can once again feel the pain of battle.\n");
      dur--;
    }
  }

  if(bloodboil)
  {
    if(bloodboil > 0)
      tell_object(USER, RED+"Your blood boils...\n"+NORM);
    USER->add_hit_point(-3);
    USER->add_spell_point(3);
    bloodboil--;
    if(bloodboil <= 0){
      tell_object(USER, RED+"\nThe anger in your blood subsides.\n"+NORM);
      dur--;
    }
  }

  if(pain_aura)
  {
    pain_aura--;
    if(pain_aura <= 0)
    {
      tell_object(USER, "Your pain aura disappears.\n");
      dur--;
    }
    else if(USER->query_attack()) /* combat messages */
      "/players/fred/closed/bloodfist/obj/combat_messages.c"->pacm(USER);
  }

  if(bloodfury && !USER->query_attack())
  {
    bloodfury = 0;
    dur--;
  }

  if(bloodcloak)
    USER->set_invs_sp();

  if(heals)
    heals--;

  if(pet)
  {
    if(!present(pet, environment(USER)) && !pet_send)
    {
      tell_room(environment(pet), pet->short()+" leaves following "+
        USER->query_name()+".\n");
      move_object(pet, environment(USER));
      tell_room(environment(USER), pet->short()+" arrives.\n");
    }
  }

  dh_bonus();         /* detox and heal bonus calculations */
}

/***************************************** ARMOR ***********************/

static string name, type;
static int size, save_flag, worn, ac, set_ac_flag;
static object worn_by, next;

link(ob){  next = ob;  }

remove_link(str){
  object ob;
  if(str == name)
  {
    ob = next;
    next = 0;
    return ob;
  }
  if(next)
    next = call_other(next, "remove_link", str);
  return this_object();
}

rec_short(){
  if(next)
    return name + ", " + call_other(next, "rec_short");
  return name;
}

test_type(str){
  if(str == type)
    return this_object();
  if(next)
    return call_other(next, "test_type", str);
  return 0;
}

tot_ac(){
  if(next)
    return ac + call_other(next, "tot_ac");
  return ac;
}

query_type(){  return type; }
query_worn(){  return worn; }
query_name(){  return name; }
armor_class(){ return ac;   }

remove(str) {
  if(!id(str))
    return 0;
  if(!worn)
    return 0;
  call_other(worn_by, "stop_wearing",name);
  worn_by = 0;
  worn = 0;
  return 1;
}

set_ac(a){
  ac = a;  
  set_ac_flag = 7; 
}
      
set_type(t){
  if(ac > 0 || !set_ac_flag)
  {
    if(t !="armor" && t !="helmet" && t != "boots" && t != "ring" && 
      t !="amulet" && t != "shield" && t != "misc") 
    destruct (this_object());
  }
  type = t;
}

take_off(){
  worn_by = this_player();
  worn_by = 0;
  worn = 0;
  return 1;
}


defense_bonus(){
  int bonus;
  bonus = 0;
  if(iron_skin)
  {
    tell_object(USER, BOLD+BLK+
      "You breathe heavily as your iron skin deflects damage.\n"+NORM);
    bonus += is_bonus;
  }
  bonus += activity_bonus();
  bonus += endurance_bonus();
  return bonus;
}
/*************************************************************************/

/*
query_auto_load(){ return GUILD_FILE+":"; }
*/

id(string e){
  if(torch && (e == "torch")) return 1;
    return e == "bloodfist_gob" || e == "pro_object" || e == "scar"
    || e == "scars" || e == "crystal" || e == "blood crystal"
    || e == "kill_check_object" || e == "guild_death_object"
    || e == "guild_monitor" || e == "guild_object" || e == "no_spell"
    || e == "generic_wc_bonus" || e == "GI";
}

reset(arg){
  if(arg) return;

  if(!root())
    set_heart_beat(1);
}

extra_look(){
  string s,w;
  object a,e;
  if(environment()->is_player())
  {
    if(guild_level == 2) w = "two";
    else if(guild_level == 3) w = "three";
    else if(guild_level == 4) w = "four";
    else if(guild_level == 5) w = "five";
    else if(guild_level == 6) w = "six";
    else if(guild_level == 7) w = "seven";
    else if(guild_level == 8) w = "eight";

    if((a = this_player()) && (e = environment()) && (e == a)) 
    {     
      s = "You have a scar in the shape of an X"+
        " in the palm of your left hand";
      if(guild_level == 1)
        s += ".\nYou have one deep scar"+
        " running along your left arm";
      else if(guild_level >= 2)
        s += ".\nYou have "+w+" deep scars"+
        " running along your left arm";
    }
    else 
    {    
      s = USER->query_name()+" has a scar in the shape of an X"+
        " in the palm of "+USER->POS+" left hand";
      if(guild_level == 1)
        s += ".\n"+USER->query_name()+" has one deep scar"+
        " running along "+USER->POS+" left arm";
      else if(guild_level >= 2)
        s += ".\n"+USER->query_name()+" has "+w+" deep scars"+
        " running along "+USER->POS+" left arm";
    }
  }
  if((a = this_player()) && (e = environment()) && (e == a))
  {
    if(query_sheathed() == 1)
      s += ".\nYou have "+query_sheathed()+" weapon sheathed on your back";
    else if(query_sheathed() > 1)
      s += ".\nYou have "+query_sheathed()+" weapons sheathed on your back";
  }
  else
  {
    if(query_sheathed() == 1)
      s += ".\n"+USER->query_name()+" has "+query_sheathed()+" weapon sheathed on "+USER->POS+" back";
    else if(query_sheathed() > 1)
      s += ".\n"+USER->query_name()+" has "+query_sheathed()+" weapons sheated on "+USER->POS+" back";
  }          
  return s;
}

long(str){
  if(str == "torch")
    write("This is a simple torch that glows with a strong fire.\n");
  else if(str == "scar" || str == "scars")
    write("This is a bloody red scar on your right hand.\n"+
    "It signifies that you belong to the Bloodfist guild.\n");
  else if(str == "crystal" || str == "blood crystal")
    write(
    "This is a magnificent blood red crystal.  It is perfectly cut and\n"+
    "exudes a subtle aura of energy.  As you hold it in your hand, the\n"+
    "scars on your arm begin to burn slightly.  Only members of the\n"+
    "Bloodfist guild carry such crystals.  Type 'bfhelp' for more info.\n");
}

short(){
  string shirt;
  shirt = RED+"A blood crystal"+NORM;
  if(torch)
    return (shirt += "\nA small torch ("+RED+"lit"+NORM+")");
  return shirt;
}

void guild_death(){
  attribsb[0] = attribsb[1] = attribsb[2] = attribsb[3] = attribsb[4] = attribsb[5] = 0;
  total_deaths++;
  advance_checks();
  if(endurance > (max_endurance / 3))
    endurance = (max_endurance / 3);
  "/room/adv_guild.c"->correct_level(USER);
  "/room/exlv_guild.c"->correct_extra_level(USER);
}

void print_monitor(){
  if(h_m)                                             /* heartbeat monitor */
    dur_mon();
}

void kill_check(object nmy){
  if(nmy->is_player() && !nmy->is_npc()) /* log pk kills in personal log */
  {
    int t, uh;
    string n,g;
    t = (int)nmy->query_level();
    n = capitalize((string)nmy->query_real_name());
    if(!(g = (string)nmy->query_guild_name()))
      g = "Guildless";
    else if(g == "Knights templar")
      g = "Knight";

    if(t == 19)
    {
      write_file("/players/fred/closed/bloodfist/log/personal/"+
        NAME, ctime()[4..15]+" "+RED+"PK "+NORM+"You killed "+n+
        ", the level "+t+"+"+nmy->query_extra_level()+" "+g+".\n");
    }
    else {
      write_file("/players/fred/closed/bloodfist/log/personal/"+
        NAME, ctime()[4..15]+" "+RED+"PK "+NORM+"You killed "+n+
        ", the level "+t+" "+g+".\n");
    }
    write_file("/players/fred/closed/bloodfist/log/pk",
      ctime()[4..15]+" "+capitalize((string)NAME)+" ["+USER->query_level()+
      "+"+USER->query_extra_level()+"] gl "+guild_level+" killed "
      +n+" ["+nmy->query_level()+"+"+nmy->query_extra_level()+"]\n");
#ifndef __LDMUD__ /* Rumplemintz */
    if((uh = index(pk_names, (string)nmy->query_real_name())) > -1)
#else
    if ((uh = member(pk_names, (string)nmy->query_real_name())) > -1)
#endif
      pk_nums[uh] += 1;
    else {
      pk_names += ({ (string)nmy->query_real_name(), });
      pk_nums += ({ 1, });
    }

    if((string)nmy->query_guild_name() == "bloodfist"
      && !environment(USER)->query_spar_area())
    {
      uh = (int)HONOR_DAEMON->query_honor(nmy->query_real_name());
      if(uh > 0)
      {
        uh /= 10; /* 10% */
        HONOR_DAEMON->rm_honor(nmy->query_real_name(), uh);
        HONOR_DAEMON->add_honor(NAME, uh, this_object());
        write_file("/players/fred/closed/bloodfist/log/pk",
          capitalize((string)NAME)+" gained "+uh+" honor from "+n+".\n");
      }
    }
    CHAN_DAEMON->print(this_object(), RED+" PK "+NORM+BOLD+BLK+
      capitalize((string)NAME)+" has killed "+n+"!"+NORM, 3);
  }
}


void init(){

  if(!environment()) return;
  environment()->set_guild_file(basename(this_object()));
  if(!this_player()->is_player()) return;
  if((int)this_player()->query_level() > 19
    && (string)this_player()->query_real_name() != "zeus"
    && (string)this_player()->query_real_name() != "fred"
    && (string)this_player()->query_real_name() != "forbin"
/*
    && (string)this_player()->query_real_name() != "khrell"
*/
    && (string)this_player()->query_real_name() != "vertebraker"
    && (string)this_player()->query_real_name() != "boltar")
  {
    destruct(this_object());
    return;
  }
/*
  else if((string)this_player()->query_real_name() != "fred" &&
          (string)this_player()->query_real_name() != "toy")
  {
    tell_object(this_player(), HIR+"\n\n"+
      "the Bloodfist beta has been suspended for the time being.  thank\n"+
      "you everyone for your help thus far.  your feedback has been\n"+
      "as important as anything else i've done to the guild.  it is\n"+
      "going to take me a while to fix things up to the point that i feel\n"+
      "i can open the guild, so for that reason i am suspending the beta.\n"+
      "i hope you understand.  thank you all.\n\n\n"+NORM);
    this_player()->set_home("/room/church.c");
    return;
  }
*/
  attribs         = allocate(6);
  attribsb        = allocate(6);
  chosen_weps     =({ 0,0,0,0 });
  chosen_weps_exp = allocate(4);
  chosen_weps_lvl = allocate(4);
  gems            = allocate(MAX_GEMS);
  studied         = allocate(MAX_STUDY);
  pk_names        = ({ });
  pk_nums         = ({ });
  a_c = 1;  /* by default, additional commands are visible */
  f_s = 0;  /* by default, full score is not displayed */
  a_s = 0;  /* by default, dont auto sheath on retrieve */
  f_m = 1;  /* by default, monitor is displayed in full */
  h_m = 1;  /* by default, heartbeat monitor is on */
  endurance_regen = 2;
  stance_dmg_bonuses = ({ 0, 90, 105, 118, 136, 154 });  /* % */
  stance_names = ({ "", "Neutral", HIW+"Aggressive"+NORM,
    BOLD+BLK+"Violent"+NORM, RED+"Murderous"+NORM, HIR+"Insane"+NORM });
  dn = ({ "BB", "Bloodboil", "BC", "Battle Cry", "GD", "Guard",
    "CC", "Concentrate", "DG", "Dodge", "PA", "Pain Aura",
    "IS", "Iron Skin", "BF", "Bloodfury", "BL", "Bloodlust", });
  lvlcost1 = ({ 0, 1, 3, 5,  7,  9,  11, 15, 19, 23, 25 });  /* WC < 16 */
  lvlcost2 = ({ 0, 1, 3, 5,  8,  12, 16, 22, 26, 30, 35 });  /* WC < 19 */
  lvlcost3 = ({ 0, 1, 4, 7,  11, 15, 22, 28, 34, 40, 45 });  /* WC == 19 */
  lvlcost4 = ({ 0, 1, 5, 10, 16, 22, 28, 34, 40, 47, 55 });  /* WC > 19 */
  lvlcost5 = ({ 0, 4, 9, 16, 24, 32, 40, 48, 58, 68, 78 });  /* WC > 19 */
  glvlcost = ({ 0, 2, 8, 20, 40, 80, 160, 260, 400 });
  hranks = ({ 0, 200, 400, 650, 1100, 1350, 1501 }); /* if below this amt */
  attribcost = ({ 1,3,7,10,16,22,29,36,42,49,58,67,76,86,98,109,120,133,148,
                  164,190,230,280,330,380,440,500,600,700,800,900,1000,1200,
                  1400,1600,1800,2000,2250,2500,2750,3000,3250,3500,3750,4000,
                  4400,4800,5200,6000,6500,7000,7500,8000, 9000,
                  10000, 12500, 15000, 17500, 20000, 25000, });
  stance          = 2;  /* aggressive stance */
  chan_muff       = 0;  /* unmuffled channel */
  study_num       = 0;

  if(this_player()->query_level() < 20)  /* set login to guild hall */
    this_player()->set_home("players/fred/closed/bloodfist/r/courtyard");

  if(!restore_stats()) save_stats();  /* restore guild stats */
  advance_checks();

  if(!this_player()->query_bloodfist_player_shadow())  /* apply player shadow */
  {
    shad = clone_object(DIR+"obj/player_shadow.c");
    shad->set_bloodfist_player_shadow(this_player());
  }

  add_action("quit",         "quit");
  add_action("emergency",    "~");
  add_action("logit",        "BflOgIt256z7d");
  add_action("honorgain",    "Re8Szpg1ighxo");

  c = sizeof(spells = get_dir(CMDDIR + "*.c"));  /* add guild commands */
  while(c--)
  {
    sscanf(spells[c], "%s.c", cmd);
    add_action("cmd_hook", cmd);
  }

  this_player()->RegisterArmor(this_object(), 
  ({ "physical", 0, 0, "defense_bonus"}));

  "/players/fred/closed/bloodfist/obj/stance_armor.c"->XXX();
  this_player()->RegisterArmor(find_object("/players/fred/closed/bloodfist/obj/stance_armor"),({"physical",0,0,"stance_damage"}));  

  if(!ingame){ 
    if(no_login_msg)
      no_login_msg = 0;
    else {
      CHAN_DAEMON->login(USER);
      cat(DIR+"doc/login_news");
    }
    ingame = 1;
  }
}

emergency(){      if(MASTER->emergency())      return 1;  else return 0; }
logit(x){         if(MASTER->logit(x))         return 1;  else return 0; }

quit()
{ 
  if(query_sheathed() != 0)
  {
    command("drop all", this_player());
    command("unsheath all", this_player());
  }
  if(bloodcloak)
    USER->unset_invs_sp();
  
  CHAN_DAEMON->logout(USER);
  command("gsave", USER);
}

honorgain(){ log_tog = 1; USER->bfht(); log_tog = 0; return 1; }

mixed cmd_hook(string str)
{
  string go;
  go = DIR+"power/"+query_verb()+".c";
  if(file_size(go) > 0)
    return (mixed) go->main(str, this_object(), this_player());
  return 0;
}

remove_object()
{
  check_it();
}

check_it()
{
  if(query_sheathed() != 0)
  command("unsheath all", USER);
}

/* zeus changes on 7/25: */
/* trst %, random 30 to 20 */
/* q multiplier 58 to 75 */
void honor_calc(int q)
{
  int u, v, trst, gl, hp, fth;
  object temp, temp2, p;
  gl = guild_level;
  fth = FAITH;
  if(fth > 100) fth = 100;
  trst = (random(20 + (gl * 3)) + 2 + gl);
  if(USER->query_level() < 10)
   trst = (random(10 + (gl * 3)) + 2 + gl);
  if(((q * 90) / 100) > trst && activity > 0)
  {
    if(gl < 8 && (p = (object)USER->query_attack()))
    {
      u = (1 + ((int)USER->query_ac() * 1 / 3) + ((gl + 4) / 2));
      v = ((gl + ((int)p->query_level() / 3) + ((q * 75) / 100)) * u); 
      this_object()->add_gexp(v);
    }
    this_object()->add_honor_potential(1);
  }
  if((temp = (object)USER->query_attack()))
  {
    temp2 = (object)temp->query_attack();
    if((temp2 && (temp2 == USER)) || ((temp2 && temp2 != USER)
      && temp2 && (string)temp2->query_guild_name() == "bloodfist"))
    {
      if((hp = honor_potential)
        > random(HONOR_RATE - (fth * 2)))
      {
        command("Re8Szpg1ighxo", USER);
        this_object()->add_honor_potential((hp / 2) * -1);
      }
    }
  }
}

dodge_check(int ddmg)
{
  dodge_dmg = 0;
  dodge_dmg = ddmg;
}

query_dodge_dmg(){ return dodge_dmg; }

dodge()
{
  endurance -= 3;
  if(USER->query_sp() > 16) 
  {
    USER->add_spell_point(-2);
    if(random(100) < dodge_chance)
    {
      USER->add_spell_point(-15);
      tell_object(USER, 
        BOLD+BLK+"You successfully dodge part of the attack.\n"+NORM);
      tell_room(environment(USER), capitalize(NAME)+
        " dodges to the side, avoiding the attack.\n", ({ USER }));
      USER->add_hit_point(query_dodge_dmg());
      if(USER->query_real_name() == "toy")
        tell_object(USER, BOLD+YEL+"Damage added back is "+query_dodge_dmg()+NORM+"\n");
    }
  }
}

gen_wc_bonus()
{
  int spec, base, mastery, c, wep_lvl, charge, stype, ws;
  object nmy, gob, ths, o;

  setup();

  spec = 0; ws = 0; stype = 0;

  nmy = USER->query_attack();
  ths = USER->query_weapon();
  if(ths && ths->query_socketed())
  {
    spec = ths->query_spec();
    ws = ths->query_ws();
    stype = ths->query_stype();
  }

  if(USER->query_real_name() == "fred")
   tell_object(USER, "Spec = "+spec+", Ws = "+ws+", Stype = "+stype+".\n");
  
  base = 0;

  /****************************************************************************/
  /* charge code, just an idea */
  if(ths && ths->query_charge() && !random(4))
  {
    ths->add_charge(-3);
    if(ths->query_charge() < 0) ths->set_charge(0);
    write(BOLD+BLK+"Your weapon crackles with lifeforce energy.\n"+NORM);
    base += 2;
  }

  /****************************************************************************/
  base += endurance_bonus();   /* endurance code */
  base += activity_bonus();    /* activity code  */

  /****************************************************************************/
  if(query_study(nmy) >= 0 && !random(3))
  {
    write("Your understanding of "+nmy->short()+" aids your skills.\n");
    base += 6;
  }

  /******************** GEM SPECIFIC SPECIAL ABILITIES ************************/

  if(stype == 1 || stype == 2 || stype == 3 || stype == 5 || stype == 6)
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);

  else if(stype == 4 && (nmy->id("demon")   /** DIAMOND - HOLY **/
    || nmy->id("undead") || nmy->id("spirit") || nmy->id("daemon"))){
    if(USER->query_alignment() > 0)
      base += 8;
    else
      base += 4;
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
  }

  else if(stype == 7)    /** AMETHYST - NEUTRAL **/
    base += 1;
 
  else if(spec == 1 && ws == 10) /* gem of purity */
  {
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
    if(nmy->query_alignment() < -100)
      base += 6;
  }

  else if(spec == 1 && ws == 11) /* gem of hatred */
  {
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
    if(nmy->query_alignment() > 100)
      base += 6;
  }

  else if(spec == 1 && ws == 14) /* gem of fury */
  {
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
    if(!random(4))
      base += 2;
  }

  else if(spec == 1 && ws == 20) /* gem of moss */
  {
    base -= 3;
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
  }

  else if(spec == 1 && ws == 22) /* gem of idiocy */
  {
    base += 2;
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
  }

  else if(spec == 1 && ws == 30) /* gem of pk */
  {
    if(nmy->is_player())
      base += 3;
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
  }
 
/********************* SPECIAL GEM EMOTES ***********************************/
    
  if(spec == 1 && ws == 8) /* gem of decay */
  {
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
    if(!random(10))
    ths->add_wear(1+random(2));
  }
    
  else if(spec == 1 && ws == 19) /* gem of fortitude */
  {
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
    ths->set_hits(1);
    ths->set_misses(1);
  }

  else if(spec == 1 && ws == 28) /* gem of instability */
  {
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
    if(!random(10))
    ths->add_wear(1);
  }

  else if(spec == 2 && ws == 8)   /* gem of speed */
  {
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
    if(!random(15))
    {
      USER->attack();
    }
  } 
  
  else if(spec == 2 && ws == 11)  /* sand gem */
  {
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
    if(!random(200))
    {
      ths->set_hits(1);
      ths->set_misses(1);
    }
  }

  else if(spec == 3 && ws == 15) /* minds eye gem */
  {
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
  }

  else if(spec == 2 && ws == 20)  /* gem of provoked aggression */
  {
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
  }
 
  else if(spec == 3 && ws == 20)  /* timeless gem */
  {
    WEP_DAEMON->go(USER, nmy, stype, spec, ws);
    ths->set_hits(1);
    ths->set_misses(1);
    if(!random(20))
    {
      USER->attack();
    }  
  }

  else if(spec == 1)
  {
    for(o = 0; o < 16; o++)
    {
      if(spec==1 && o < 16)
      {
        if(ws == simple1[o])
          WEP_DAEMON->go(USER, nmy, stype, spec, ws);
      }
    }
  }
  else if(spec == 2)
  {
    for(o = 0; o < 12; o++) 
    {
      if(spec==2 && o < 12)
      {
        if(ws == simple2[o])
          WEP_DAEMON->go(USER, nmy, stype, spec, ws);
      }
    }
  }
  else if(spec == 3)
  {
    for(o = 0; o < 9; o++)
    {
      if(spec==3 && o < 9)
      {
        if(ws == simple3[o])
          WEP_DAEMON->go(USER, nmy, stype, spec, ws);
      }
    }
  }
  
  if(base < 0) base = 0;

  mastery = get_mastery(); 

  if(USER->query_real_name() == "fred")
  {
    tell_object(USER, ""+HIY+"Base bonus is "+base+NORM+"\n");
    tell_object(USER, ""+HIY+"Mastery bonus is "+mastery+NORM+"\n");
  }
  
  return (base + mastery);
}

setup()
{
  string *gnames, *spec1, *spec2, *spec3, *vtypes;
  int ws, spec, forged;

  gnames =({ "crystal gem", "ruby gem", "emerald gem", "sapphire gem", 
    "diamond gem", "onyx gem", "topaz gem", "amethyst gem", 
  });

  spec1 =({ "crystal gem", "minor gem of agility", "minor gem of might", 
    "minor gem of accuracy", "minor gem of vigor", "minor gem of wisdom",
    "minor gem of faith", "prismatic gem", "gem of decay", "chaos gem",
    "gem of purity", "gem of hatred", "minor gem of performance",
    "gem of beauty", "gem of fury", "gem of eternity", "vortex gem",
    "lightning gem", "gem of unholy death rites", "gem of fortitude",
    "gem of moss", "gem of rain", "gem of idiocy", "gem of emotion",
    "minor gold gem", "minor gem of regeneration", 
    "minor gem of rejuvenation", "minor gem of restoration",
    "gem of instability", "faerie gem", "gem of pk", "gem of winter",
    "minor gem of cleansing", "gem of combat skills",
  });

  spec2 =({ "crystal gem", "gem of agility", "gem of might",
    "gem of accuracy", "gem of vigor", "gem of wisdom", "gem of faith",
    "soul gem", "gem of speed", "gem of performance", "blood gem",
    "sand gem", "ryo gem", "xetra gem", "gold gem", "angelic gem",
    "demonic gem", "gem of regeneration", "gem of rejuvenation",
    "gem of restoration", "gem of provoked aggression", "gem of the dragon",
    "gem of cleansing",
  });

  spec3 =({ "crystal gem", "major gem of agility", "major gem of might", 
    "major gem of accuracy", "major gem of vigor", "major gem of wisdom",
    "major gem of faith", "major gem of performance", "major gold gem",
    "gem of zeus", "holy angelic gem", "unholy demonic gem",
    "major gem of regeneration", "major gem of rejuvenation",
    "major gem of restoration", "minds eye gem", "gem of inescapable horror",
    "major gem of cleansing", "gem of battle rites", "sage gem",
    "timeless gem",
  });

  vtypes =({ "sword", "swords", "blade", "blades", "katana",
    "knife", "dagger", "polearm", "spear", "trident", "stick", "pole",
    "bow", "club", "staff", "mace", "morningstar", "axe", "hammer",
    "battleaxe" 
  });
  
   /* simple gem ws's that only need a daemon call */
  simple1 = ({ 7,8,9,13,15,16,17,18,21,23,25,26,27,29,31,32, });
  simple2 = ({ 7,8,10,12,13,15,16,17,18,19,21,22, });
  simple3 = ({ 10,11,12,13,14,15,16,17,20, });

  ws = 0;
  spec = 0;
  forged = 0;
}

/* calculates and returns % of mastery bonus for current weapon */
get_mastery()
{
  int c, ndx, wep_lvl, a;
  string *vtypes;
  object ths;
  ths = USER->query_weapon();
  c = (WMIT / 50) + (WACC / 50);
  if(query_if_chosen(ths) >= 0)  /* if this wep is chosen */
  {
    wep_lvl = query_chosen_lvl(ndx);

    if(wep_lvl == 0)       c += 0;
    else if(wep_lvl == 1)  c += 1;
    else if(wep_lvl == 2)  c += 1;
    else if(wep_lvl == 3)  c += 1;
    else if(wep_lvl == 4)  c += 1;
    else if(wep_lvl == 5)  c += 2;
    else if(wep_lvl == 6)  c += 2;
    else if(wep_lvl == 7)  c += 2;
    else if(wep_lvl == 8)  c += 2;
    else if(wep_lvl == 9)  c += 3;
    else if(wep_lvl == 10) c += 3;
  }
  else 
    c += -10;

  a = query_stance();

  c += stance_bonus(a);  
  
/*
  if(index(vtypes, ths->query_type()) < 0)  
    c -= (wep_lvl + 1);
*/
  return c; /* bonus to return */
}   
