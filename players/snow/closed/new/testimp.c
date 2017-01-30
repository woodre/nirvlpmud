/* 
 * Guild Object, by Dune and Snow
 * Some pieces of code modified from Dragnar/Balowski
 */


/**** INCLUDES AND DEFINES ******************************/
#include "/players/dune/closed/guild/DEFS.h"
#include DEFS_HLEVELS
#include DEFS_GLEVELS
#include DEFS_OFFICES

#define STATIC_P1 LIB_ADVCMDS+"p1.c"
#define STATIC_P2 LIB_ADVCMDS+"p2.c"
#define STATIC_P3 LIB_ADVCMDS+"p3.c"
#define DISALLOW ({"mi","missile","fireball","fi","shock","sh",\
                   "so","sonic"})
/********************************************************/



/**** VARIABLES *****************************************/
static mapping genCmds, advCmds, admCmds, tools, emotes, nocmds;

static status muffle,
              bion_on, blad_on, rejuv_on, regen_on, equil_on,
              convert_on, light_on, armor_on, tough_on, charge_on;

string stone, art, weapon, sphere, brand, wepsync;

int beats, kills, color, flux_charges, weplink, 
    guild_lev, guild_exp, bal, artlevel, honor, nohonor, attack_mode; 

object target;

status suspend, 
    auto_att, auto_def, auto_on, auto_reg, auto_rej, auto_blad, auto_bion, 
    corpse, electricflux, magneticflux, heatflux, flash, emt, armor, 
    bionics, blades, eyes, activate_droid, legs, convert, digest;
/********************************************************/



/**** DESCRIPTIVE FUNCTIONS *****************************/
status id(string str) { 
  return str == GUILD_ID || 
  str == AFFILIATE       || 
  str == "implants"      ||
  str == "notarmor"; }

string short() { return (FUNKYNAME+" Implants"); }

void long() {
  tell_object(ETO, 
  "This is the "+FUNKYNAME+" guild object.\n"+
  "To recieve information just type 'cyber'.\n"); }

status get()  { return 1; }
status drop() { return 1; }

string extra_look() {
  string stuff;
  string name;
  name  = capitalize((string)ETO->query_name());
  stuff = name+" has Cybernetic Implants";
  if(stone) stuff += "\n"+name+" has eyes of "+stone;
  else      stuff += "\n"+name+" has eyes of "+NOSTONE;
  if( blades || bionics )
            stuff += "\n"+name+" has muscle enhancements";
  if( electricflux || magneticflux || heatflux )
            stuff += "\n"+name+" has "+BOLD+"FluX"+OFF+" jacks";
  if(weplink > 0) 
            stuff += "\n"+name+" has a smartweapon link";
  return stuff; }
/********************************************************/



/**** INIT AND RESET ************************************/
reset(arg) {
  if(!arg) {
    muffle=0; digest=0; bion_on=0; blad_on=0; light_on=0; armor_on=0; 
    convert_on=0; equil_on=0; regen_on=0; rejuv_on=0; charge_on=0;
    remove_call_out("fake_beat");
    call_out("fake_beat",5); 
  } 
  return 1; }

init() {
  string *ks; int i;
  object shadow;
  if (!environment()) return;
  if (environment() == this_player()) {
    restore_me();
    call_other(CHANNELD,"resetchannel");
    /* Temporary resetting of wepsync, because wepsync no longer is used */
    wepsync = 0;
    TP->set_guild_name(GUILDNAME);
    if((!stone || stone == NOSTONE) && 
      (TRN == OWNER1 || TRN == OWNER2)) 
      stone = "adamantium";
    if(!stone) stone = NOSTONE;
    if(!brand) brand = BRAND0;
    if(suspend) {
      write("You remain suspended from the guild.\n");
      return;
    }

    if((honor >= HONOR_LEVEL_MD1) || TRN == OWNER1 || TRN == OWNER2) {
/* SHADOW */
shadow = clone_object("/players/dune/closed/guild/objects/shadow.c");
shadow->start_defense(this_player());
      /* normal guild commands */
      if (genCmds = (mapping)call_other(ACTIOND, "query_genCmds")) {
        i = sizeof(ks = keys(genCmds));
        while (i--) add_action("genCmds_hook", ks[i]); }
      /* advanced guild commands */
      if (advCmds = (mapping)call_other(ACTIOND, "query_advCmds")) {
        i = sizeof(ks = keys(advCmds));
        while (i--) add_action("advCmds_hook", ks[i]); }

      /* administrative commands */
      if (admCmds = (mapping)call_other(ACTIOND, "query_admCmds")) {
        i = sizeof(ks = keys(admCmds));
        while (i--) add_action("admCmds_hook", ks[i]); }

      /* Static commands: these are all the guild spells that replace
         the game spells. They are static in order to prevent them
         from being included in speedsters. */
      add_action("p1_static", "p1");
      add_action("p2_static", "p2"); 
      add_action("p3_static", "p3");
    }

    /* enhancement commands */
    if (tools = (mapping)call_other(ACTIOND, "query_tools")) {
      i = sizeof(ks = keys(tools));
      while (i--) add_action("tools_hook", ks[i]); }

    /* emotes */
    if (emotes = (mapping)call_other(ACTIOND, "query_emotes")) {
      i = sizeof(ks = keys(emotes));
      while (i--) add_action("emotes_hook", ks[i]); }

    /* disallowed cmds here */
    i = sizeof(ks = DISALLOW);
    nocmds = allocate_mapping(i);
    while (i--) add_action("not_allowed", ks[i]);
  }
}

/* static commands that had explicit add_actions above */
static p1_static(string str) { 
  call_other(STATIC_P1, "static_main", str);
  return 1; }
static p2_static(string str) { 
  call_other(STATIC_P2, "static_main", str);
  return 1; }
static p3_static(string str) { 
  call_other(STATIC_P3, "static_main", str);
  return 1; }

genCmds_hook(string str) {
    string cmd;
    if (cmd = genCmds[query_verb()]) return (status) cmd->main(str); }

advCmds_hook(string str) {
    string cmd;
    if (cmd = advCmds[query_verb()]) return (status) cmd->main(str); }

admCmds_hook(string str) {
    string cmd;
    if (cmd = admCmds[query_verb()]) return (status) cmd->main(str); }

emotes_hook(string str) {
    string cmd;
    if (cmd = emotes[query_verb()]) return (status) cmd->main(str); }

tools_hook(string str) {
    string cmd;
    if (cmd = tools[query_verb()]) return (status) cmd->main(str); }
/********************************************************/



/**** SAVE AND RESTORE **********************************/
status save_me() {
  string file;
  int success;
  success = 1;
  file = SAVEDIR +"/"+ ETO->query_real_name();
  if(!save_object(file)) success = 0;
  return success; }
 
status restore_me() {
  string file;
  int success;
  success = 1;
  file = SAVEDIR +"/"+ ETO->query_real_name();
  if(!restore_object(file)) success = 0;
  reset();
  return success; }
/********************************************************/



/**** MISC FUNCTIONS ************************************/
status not_allowed(string str) {
    tell_object(TP, "This action is forbidden.\n");
    return 1; }


/* Simulated Heartbeat */
void fake_beat() {
  if(!environment()) return;
  if(!ETO) return;
  call_out("fake_beat", 5, ETO);
  call_other(BEATD, "fake_beat", ETO);
}


void log(string type, string action) {
  if( !(TP && TP->query_level() > 20) ) return;
  write_file(LOGDIR + "/" + type, TRN + "[" + 
    action + " " + type + "] to " + capitalize((string)
    ETO->query_real_name()) + ", " + ctime(time()) + "\n");
}
/********************************************************/



/**** ACCESSORS *****************************************/
/* Guild Level Accessors */
int guild_exp() { return guild_exp; }
int guild_lev() { return guild_lev; }
void set_rank(int x) { log("rank","set("+x+")"); guild_lev = x;  }
void set_xp(int x)   { log("xp",  "set("+x+")"); guild_exp = x;  }
void add_xp(int x)   { log("xp",  "add("+x+")"); guild_exp += x; }

/* Art Level Accessors */
int query_art_level() { return artlevel; }
string query_art()    { return "Ninjitsu"; return art; }
void set_art_level(int x) { log("artlevel","set("+x+")"); artlevel = x; }

/* Guild Wiz Accessors */
status guild_wiz() { 
  if( (capitalize((string)ETO->query_real_name())) == OWNER1 ||
      (capitalize((string)ETO->query_real_name())) == OWNER2 || 
      (stone == "adamantium") ) return 1; 
  return 0; }

/* Honor Accessors */
int query_honor() { return honor; }
void add_honor(int x)  { honor += x; log("honor","add("+x+")"); }
void set_honor(int x)  { honor  = x; log("honor","set("+x+")"); }

/* No Honor Accessors */
void set_nohonor() { nohonor = 1; }
void remove_nohonor() { nohonor = 0; }
int query_nohonor() { return nohonor; }

/* Guild Office Accessors */
string query_stone() { return stone; }
void set_stone(string x)  { log("stone", "set("+x+")"); stone = x; }
status guild_officer() {
  if( (capitalize((string)ETO->query_real_name())) == OWNER1 ||
      (capitalize((string)ETO->query_real_name())) == OWNER2 || 
      (stone && guild_lev >= (int)call_other(GLEVELD, "senior")) ) return 1;
  return 0; }
status guild_manager() { 
  if( (capitalize((string)ETO->query_real_name())) == OWNER1 ||
      (capitalize((string)ETO->query_real_name())) == OWNER2 || 
      (sphere == WIZ_TIER2_A) || 
      (sphere == WIZ_TIER2_B) ) return 1; 
  return 0; }

/* Guild Money Accessors */
int balance()       { return bal; }
void addToBalance(int x) { log("credits", "add("+x+")"); bal += x; }


/* Miscellaneous Accessors */
status muffled()                   { return muffle;       }
void set_muffle(status new_muffle) { muffle = new_muffle; }
string query_weapon()              { return weapon;       }
void set_weapon(string wep)        { weapon = wep;        }
status suspended()                 { return suspend;      }
void set_suspended(status new)     { suspend = new;       }
void add_beats()                   { beats ++;            }
int check_beats()                  { return beats;        }
int query_kills()                  { return kills;        }
void add_kills(int new)            { kills += new;        }
void set_kills(int new)            { kills = new;         }
void set_attack_mode(int num)      { attack_mode = num;   }
int query_attack_mode()            { return attack_mode;  }
int item_weplink()                 { return weplink;      }
void add_weplink(int num)          { weplink += num;      }
void set_weplink(int num)          { weplink = num;       }
void set_sphere(string new)        { sphere = new;        }
string query_sphere()              { return sphere;       }
void set_brand(string new)         { brand = new;         }
string query_brand()               { return brand;        }
void set_wepsync(string new)       { wepsync = new;       }
string query_wepsync()             { return wepsync;      }

/* Enhancement Accessors */
void set_armor(status new)     { armor = new;           }
int query_armor()              { return armor;          }
void set_armor_on(status num)  { armor_on = num;        }
status query_armor_on()        { return armor_on;       }
void set_flux_charges(int num) { flux_charges = num;    }
void add_flux_charges(int num) { flux_charges = flux_charges + num; }
int query_flux_charges()       { return flux_charges;   }
void set_charge_on(status num) { charge_on = num;       }
status query_charge_on()       { return charge_on;      }
void set_light_on(int num)     { light_on = num;        }
int query_light_on()           { return light_on;       }
void do_light(int new)         { if(new > 2) new = 2; 
                                 if(new < -2) new = -2;
                                 set_light(new);        }
void set_target(object ob)     { target = ob; }
object query_target()          { return target; }

status query_rejuv()  { return rejuv_on; }
status query_regen()  { return regen_on; }
status query_equil()  { return equil_on; }
status query_digest() { return digest;   }

void set_digest(status num)     { digest = num;     }
void set_rejuv(status num)      { rejuv_on = num;   }
void set_regen(status num)      { regen_on = num;   }
void set_equil(status num)      { equil_on = num;   }
void set_convert_on(status num) { convert_on = num; }

status query_auto_on()    { return auto_on;    }
status query_auto_att()   { return auto_att;   }
status query_auto_def()   { return auto_def;   }
status query_auto_reg()   { return auto_reg;   }
status query_auto_rej()   { return auto_rej;   }
status query_auto_blad()  { return auto_blad;  }
status query_auto_bion()  { return auto_bion;  }
status query_blad_on()    { return blad_on;    }
status query_bion_on()    { return bion_on;    }
status query_convert_on() { return convert_on; }
status query_tough()      { return tough_on;   }

void set_auto(status num)      { auto_on = num;   }
void set_auto_att(status num)  { auto_att = num;  }
void set_auto_def(status num)  { auto_def = num;  }
void set_auto_reg(status num)  { auto_reg = num;  }
void set_auto_rej(status num)  { auto_rej = num;  }
void set_auto_blad(status num) { auto_blad = num; }
void set_auto_bion(status num) { auto_bion = num; }
void set_bion_on(status new)   { bion_on = new;   } 
void set_blad_on(status new)   { blad_on = new;   }
void set_tough(status num)     { tough_on = num;  }

status item_eyes()           { return eyes;           }
status item_corpse()         { return corpse;         }
status item_electricflux()   { return electricflux;   }
status item_magneticflux()   { return magneticflux;   }
status item_heatflux()       { return heatflux;       }
status item_flash()          { return flash;          }
status item_emt()            { return emt;            }
status item_bionics()        { return bionics;        }
status item_blades()         { return blades;         }
status item_activate_droid() { return activate_droid; }
status item_legs()           { return legs;           }
status item_convert()        { return convert;        }
status item_armor()        { return armor;        }

void set_eyes(status num)           { eyes = num;           }
void set_corpse(status num)         { corpse = num;         }
void set_electricflux(status num)   { electricflux = num;   }
void set_magneticflux(status num)   { magneticflux = num;   }
void set_heatflux(status num)       { heatflux = num;       }
void set_flash(status num)          { flash = num;          }
void set_emt(status num)            { emt = num;            }
void set_bionics(status num)        { bionics = num;        }
void set_blades(status num)         { blades = num;         }
void set_activate_droid(status num) { activate_droid = num; }
void set_legs(status num)           { legs = num;           }
void set_convert(status num)        { convert = num;        }
/********************************************************/
