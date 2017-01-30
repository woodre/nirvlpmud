/* 
* CyberNinja Guild Object, by Dune and Snow
* Some pieces of code modified from Dragnar/Balowski
   */


/**** INCLUDES AND DEFINES ******************************/
#include "DEFS.h"
#include DEFS_HLEVELS
#include DEFS_GLEVELS
#include DEFS_OFFICES

#define STATIC_P1 LIB_ADVCMDS+"p1.c"
#define STATIC_P2 LIB_ADVCMDS+"p2.c"
#define STATIC_P3 LIB_ADVCMDS+"p3.c"
#define STATIC_STRIKE LIB_GENCMDS+"strike.c"
#define DISALLOW ({"mi","missile","fireball","fi","shock","sh",\
      "so","sonic","invisible","wear"})
#define M_CMDS "/open/mokri/cybers/cmds/"
/********************************************************/



/**** VARIABLES *****************************************/
static mapping genCmds, advCmds, admCmds, tools, emotes, nocmds;
static status muffle,
bion_on, blad_on, rejuv_on, regen_on, equil_on,
convert_on, light_on, armor_on, tough_on, charge_on;
static int spellscast, mode_delay, use_delay;
static string use_name;

string stone, art, weapon, weapon_name, sphere, brand, wepsync, 
prevstrike, counselor, flux_type;

int beats, kills, color, flux_charges, weplink, mech, 
guild_lev, guild_exp, bal, artlevel, honor, nohonor, attack_mode, 
basexp, shadows_modifier;
int device_channel;

object target;

status suspend, flux_hb, auto_att, auto_def, 
auto_on, auto_reg, auto_rej, auto_blad, auto_bion, auto_targ, 
auto_dgst, corpse, electricflux, magneticflux, heatflux, flash, emt,
armor, bionics, blades, eyes, activate_droid, legs, convert, digest,
trans, poisona, poisonh, mechmon, blood, inertia, nanoblood;
status in_shadows, adjust, broken_eyes, broken_corpse, broken_flux, 
broken_emt,broken_bionics, broken_blades, broken_convert, broken_armor,
is_wizard;
/********************************************************/



/**** DESCRIPTIVE FUNCTIONS *****************************/
status id(string str)
{ 
   string move_silent;
  if(str=="GI") return 1;
   if (this_player() && this_player()->query_level() > 20)
      {
      return str == "implants" || str == GUILD_ID || str==AFFILIATE;
   }
   
   return str == GUILD_ID || 
   str == AFFILIATE     || 
   str == "implants"    ||
   str == "no_spell"    ||
   str == "generic_wc_bonus"    ||
   str == "notarmor"    ||
   (environment()->query_invis() ? (str == "silent_move_object") : (str == GUILD_ID)) ||
   (str == "dark_sight_object" && eyes) ||
   str == "GI";
}


string short() { return (BOLD+YELLOW+FUNKYNAME+OFF+" Implants"); }


void long()
{
   tell_object(ETO, 
      "Cybernetic implants emmerge from your flesh.  Cables and tubes stick\n"+
      "out from plugs in your arms and neck.  Carbon fibers form a destinque \n"+ 
      "patterns visible through your skin.  Green liquids seem to pump though\n"+
      "your veins and you can feel the soft hum of electronics throughout your\n"+
      "body.  Tiny lights flash in response to your movements.\n"+
      "To recieve information type '"+BOLD+YELLOW+"cyber"+OFF+"'.\n");
}


status get()  { return 1; }


status drop()
{
   if (environment() && environment()->is_player())
      {
      if ((int)environment()->query_exp() < basexp)
         {
         basexp = (int)environment()->query_exp();
       }
   }
   return 1;
}


string extra_look()
{
   string stuff;
   string name;
   name  = capitalize((string)ETO->query_name());
   stuff = name+" has Cybernetic Implants.";
   if(stone) stuff += "\n"+name+" has eyes of "+stone+".";
   else      stuff += "\n"+name+" has eyes of "+NOSTONE+".";
   if ( blades || bionics )
      stuff += "\n"+name+" has muscle enhancements.";
   if ( electricflux || magneticflux || heatflux )
      stuff += "\n"+name+" has "+BOLD+"FluX"+OFF+" jacks.";
   if (weplink > 0) 
      stuff += "\n"+name+" has a smartweapon link.";
   if (poisona || poisonh)
      stuff += "\n"+name+"'s arms are plated with poison dart cannons";
   return stuff;
}
/********************************************************/



/**** INIT AND RESET ************************************/

/*
query_auto_load() { return "/players/dune/closed/guild/implants.c:"; }
*/

reset(arg)
{
   set_heart_beat(1);
   if (!arg)
      {
      muffle=0; digest=0; bion_on=0; blad_on=0; light_on=0; armor_on=0; 
      convert_on=0; equil_on=0; regen_on=0; rejuv_on=0; charge_on=0;
      if(honor > HONOR_LEVEL_MAX) honor = HONOR_LEVEL_MAX;
      /* ld don't like this on castle preloading... -Bp
      call_out("d_check", 10);  check for other "implants" - mythos <7-301998> */
      d_check();
   }
   return 1;
}


d_check()
{
   /* destructs extra copies of implants */
   object moo, moo2;
   int no;
   if (!environment(this_object())) return 1;
   moo = all_inventory(environment(this_object()));
   for (no = 0; no < sizeof(moo); no++)
   {
      if (moo[no]->id("implants") && moo[no] != this_object()) destruct(moo[no]);
   }
   return 1;
}


void news_check(object ob)
{
   command("news",  ob);
   command("cvotes", ob);
}


init()
{
   string *ks; int i;
   object shadow;
   
   if (!environment()) return;
   
  environment()->set_guild_file(basename(this_object()));
   if (environment() == this_player())
      {
      restore_me();
      
      /* Added to allow separating wizzes from players in .o files */
      is_wizard = ( (int)this_player()->query_level() > 19 ? 1 : 0 );
      
      call_other(CHANNELD, "resetchannel");
      if (call_other(CHANNELD, "newLogin", (string)TP->query_real_name()))
         {
         call_out("news_check", 1, TP);
       }
      
      /* Temporary resetting of wepsync, because wepsync no longer is used */
      wepsync = 0;
      
      TP->set_guild_name(GUILDNAME);
      
      if ((!stone || stone == NOSTONE) && (TRN == OWNER1 || TRN == OWNER2))
         {
         stone = "adamantium";
       }
      if (!stone) stone = NOSTONE;
      
      if (!brand) brand = BRAND0;
      
      if (attack_mode == 2) attack_mode = 0;
      
      if (mech) mech = 0;
      
      if (suspend)
         {
         write(BLINK+BOLD+"You remain suspended from the guild."+OFF+OFF+"\n");
         return;
       }
      
      if (nohonor && TP->query_level() < 20)
         {
         stone = NOSTONE;
         TP->set_home("/room/church.c");
       }
      
      if (nohonor ||
            (!nohonor && honor >= HONOR_LEVEL_MD1) || 
         TRN == OWNER1 || 
         TRN == OWNER2)
      {
         /* SHADOW */
         if(!this_player()->query_defense())
            {
            shadow = clone_object("/players/dune/closed/guild/objects/shadow.c");
            shadow->start_defense(this_player());
          }
         /* normal guild commands */
         if (genCmds = (mapping)call_other(ACTIOND, "query_genCmds"))
            {
            i = sizeof(ks = keys(genCmds));
            while (i--) add_action("genCmds_hook", ks[i]);
          }
         /* advanced guild commands */
         if (advCmds = (mapping)call_other(ACTIOND, "query_advCmds"))
            {
            i = sizeof(ks = keys(advCmds));
            while (i--) add_action("advCmds_hook", ks[i]);
          }
         /* administrative commands */
         if (admCmds = (mapping)call_other(ACTIOND, "query_admCmds"))
            {
            i = sizeof(ks = keys(admCmds));
            while (i--) add_action("admCmds_hook", ks[i]);
          }
         /* Static commands: these are all the guild spells that replace
         the game spells. They are static in order to prevent them
         from being included in speedsters. */
         add_action("p1_static", "p1");
         add_action("p2_static", "p2"); 
         add_action("p3_static", "p3");
         add_action("strike_static", "strike");
         add_action("strike_static", "st");
       }
      
      /* enhancement commands */
      if (tools = (mapping)call_other(ACTIOND, "query_tools"))
         {
         i = sizeof(ks = keys(tools));
         while (i--) add_action("tools_hook", ks[i]);
       }
      
      /* emotes */
      if (emotes = (mapping)call_other(ACTIOND, "query_emotes"))
         {
         i = sizeof(ks = keys(emotes));
         while (i--) add_action("emotes_hook", ks[i]);
       }
      
      /* disallowed cmds here */
      i = sizeof(ks = DISALLOW);
      nocmds = allocate_mapping(i);
      while (i--) add_action("not_allowed", ks[i]);
   }
   
   /* mokri command directory */
   ks = get_dir(M_CMDS);
   for(i = 0; i < sizeof(ks); i++)
   {
      if(extract(ks[i],0,0) == "_")
         add_action("m_cmds",extract(ks[i],1,strlen(ks[i]) - 3));
   }
}


/* static commands that had explicit add_actions above */
static p1_static(string str)
{
   call_other(STATIC_P1, "static_main", str);
   return 1;
}
static p2_static(string str){
   call_other(STATIC_P2, "static_main", str);
   return 1;
}
static p3_static(string str)
{ 
   call_other(STATIC_P3, "static_main", str);
   return 1;
}
static strike_static(string str)
{
   call_other(STATIC_STRIKE, "static_main", str);
   return 1;
}


genCmds_hook(string str)
{
   string cmd;
   if (cmd = genCmds[query_verb()]) return (status) cmd->main(str);
}
advCmds_hook(string str)
{
   string cmd;
   if (cmd = advCmds[query_verb()]) return (status) cmd->main(str);
}
admCmds_hook(string str)
{
   string cmd;
   if (cmd = admCmds[query_verb()]) return (status) cmd->main(str);
}
emotes_hook(string str)
{
   string cmd;
   if (cmd = emotes[query_verb()]) return (status) cmd->main(str);
}
tools_hook(string str)
{
   string cmd;
   /* if(str) problems reported, commented out */
      if (cmd = tools[query_verb()]) return (status) cmd->main(str);
}
/********************************************************/



/**** SAVE AND RESTORE **********************************/
status save_me()
{
   string file;
   int success;
   success = 1;
   file = SAVEDIR +"/"+ ETO->query_real_name();
   if (!save_object(file)) success = 0;
   return success;
}

status restore_me()
{
   string file;
   int success;
   success = 1;
   file = SAVEDIR +"/"+ ETO->query_real_name();
   if (!restore_object(file)) success = 0;
   reset();
   return success;
}

/* Overwrites the specified ninja's stats with this object's stats.
   This is used internally by guild commands. */
status external_save_me(string extName)
{
   string file;
   status success;
   success = 1;
   file = SAVEDIR +"/"+ extName;
   if (!save_object(file)) success = 0;
   return success;
}

/* Loads this object with the specified ninja's stats.
   This is used internally by guild commands. */
status external_restore_me(string extName)
{
   string file;
   status success;
   success = 1;
   file = SAVEDIR +"/"+ extName;
   if (!restore_object(file)) success = 0;
   reset();
   return success;
}
/********************************************************/



/**** MISC FUNCTIONS ************************************/
status not_allowed(string str)
{
   tell_object(TP, "This action is forbidden.\n");
   return 1;
}


/* Simulated Heartbeat */
void heart_beat()
{
   if(!environment()) return;
   if(!ETO) return;
   if(environment()->query_attack() && 
         environment()->query_invis() &&
      environment()->query_attack()->is_player() &&
      environment()->query_level() < 20)
   {
      environment()->visible();
   }
   if(environment()->query_invis() &&
         !environment()->query_pl_k() &&
      environment()->query_level() < 20)
   {
      tell_object(environment(), "Your shadows runs out, since you are not pk.\n");
      environment()->visible();
   }
   if(environment()->query_invis() &&
         environment()->query_level() < 20)
   {
      environment()->set_invs_sp();
   }
   spellscast = 0;
   call_other(BEATD,"fake_beat",environment());
}


void log(string type, string action)
{
   string doer;
   if (!TP) doer = "AUTO";
   else     doer = TRN;
   if (!TP || !environment())
      {
      log_file("dune.auto", doer + "[" + 
         action + " " + type + "] to " + capitalize((string)
            ETO->query_real_name()) + ", " + ctime(time()) + "\n");
   }
   else
      {
      write_file(LOGDIR + "/" + type, doer + "[" + 
         action + " " + type + "] to " + capitalize((string)
            ETO->query_real_name()) + ", " + ctime(time()) + "\n");
   }
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
status guild_wiz()
{ 
   if( (capitalize((string)ETO->query_real_name())) == OWNER1 ||
         (capitalize((string)ETO->query_real_name())) == OWNER2 ||
      (stone == "adamantium") ) return 1; 
   return 0;
}


/* Honor Accessors */
int query_honor() { return honor; }
void add_honor(int x)  { honor += x; log("honor","add("+x+") {is now "+honor+"}"); }
void set_honor(int x)  { honor  = x; log("honor","set("+x+")"); }


/* Base Exp */
void set_basexp(int x) { basexp = x; }
int query_basexp() { return basexp; }


/* No Honor Accessors */
void set_nohonor() { nohonor = 1; }
void remove_nohonor() { nohonor = 0; }
int query_nohonor() { return nohonor; }


/* Guild Office Accessors */
string query_stone() { return stone; }
void set_stone(string x) { stone = x; }
status guild_officer()
{
   if( (capitalize((string)ETO->query_real_name())) == OWNER1 ||
         (capitalize((string)ETO->query_real_name())) == OWNER2 ||
      guild_wiz() == 1   || /* wocket add */
      stone == "diamond" || 
      stone == "emerald" ||
      stone == "onyx"    ||
      stone == "pearl"   ||
      stone == "sapphire")
   {
      return 1;
   }
   return 0;
}
status guild_manager()
{ 
   if( (capitalize((string)ETO->query_real_name())) == OWNER1 ||
         (capitalize((string)ETO->query_real_name())) == OWNER2 || 
      (sphere == WIZ_TIER2_A) || 
      (sphere == WIZ_TIER2_B) )
   {
      return 1;
   }
   return 0;
}


/* Guild Money Accessors */
int balance()            { return bal; }
void addToBalance(int x) { log("credits", "add("+x+")"); bal += x; }


/* Miscellaneous Accessors */
status muffled()                   { return muffle;       }
void set_muffle(status new_muffle) { muffle = new_muffle; }
string query_weapon()              { return weapon;       }
void set_weapon(string wep)        { weapon = wep;        }
string query_weapon_name()         { return weapon_name;  }
void set_weapon_name(string nam)   { weapon_name = nam;   }
status suspended()                 { return suspend;      }
void set_suspended(status new)     { suspend = new;       }
void add_beats()                   { beats ++;            }
int check_beats()                  { return beats;        }
int query_kills()                  { return kills;        }
void add_kills(int new)            { kills += new;        }
void set_kills(int new)            { kills = new;         }
void set_attack_mode(int num)      { attack_mode = num;   }
int query_attack_mode()            { return attack_mode;  }
void set_mode_delay(int num)       { mode_delay = num;    }
int query_mode_delay()             { return mode_delay;   }
void set_prevstrike(string str)    { prevstrike = str;    }
string query_prevstrike()          { return prevstrike;   }
int item_weplink()                 { return weplink;      }
void add_weplink(int num)          { weplink += num;      }
void set_weplink(int num)          { weplink = num;       }
void set_sphere(string new)        { sphere = new;        }
string query_sphere()              { return sphere;       }
void set_brand(string new)         { brand = new;         }
string query_brand()               { return brand;        }
void set_wepsync(string new)       { wepsync = new;       }
string query_wepsync()             { return wepsync;      }


/* Shadows Accessors */
void set_shadows(status num) { in_shadows = num; }
status query_shadows() { return in_shadows; }
void add_shadows_modifier(int num) { shadows_modifier += num; }
int shadows_modifier() { return shadows_modifier; }


/* Enhancement Accessors */
void set_armor(status new)     { armor = new;           }
int query_armor()              { return armor;          }
int query_mech()               { return mech;           }
void set_mech(int num)         { mech = num;            } 
void set_armor_on(status num)  { armor_on = num;        }
status query_armor_on()        { return armor_on;       }

void set_flux_charges(int num) { flux_charges = num;    }
void add_flux_charges(int num) { flux_charges = flux_charges + num; }
int query_flux_charges()       { return flux_charges;   }
void set_charge_on(status num) { charge_on = num;       }
status query_charge_on()       { return charge_on;      }

void set_light_on(int num)     { light_on = num;        }
int query_light_on()           { return light_on;       }
void do_light(int new)         { if(new > 4) new = 4;
   if(new < -2) new = -2;
   set_light(new);        }

object query_target()          { return target; }
void set_target(object ob)     { target = ob; }

string query_flux_type()       { return flux_type; }
void   set_flux_type(string x) { flux_type = x;    }
status query_flux_hb()         { return flux_hb;   }
void   set_flux_hb(status x)   { flux_hb = x;      }

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
status query_auto_dgst()  { return auto_dgst;  }
status query_auto_targ()  { return auto_targ;  }

status query_blad_on()    { return blad_on;    }
status query_bion_on()    { return bion_on;    }
status query_convert_on() { return convert_on; }
status query_tough()      { return tough_on;   }
status query_trans()      { return trans;      }

void set_auto(status num)      { auto_on = num;   }
void set_auto_att(status num)  { auto_att = num;  }
void set_auto_def(status num)  { auto_def = num;  }
void set_auto_reg(status num)  { auto_reg = num;  }
void set_auto_rej(status num)  { auto_rej = num;  }
void set_auto_blad(status num) { auto_blad = num; }
void set_auto_bion(status num) { auto_bion = num; }
void set_auto_dgst(status num) { auto_dgst = num; }
void set_auto_targ(status num) { auto_targ = num; }

void set_bion_on(status new)   { bion_on = new;   } 
void set_blad_on(status new)   { blad_on = new;   }
void set_tough(status num)     { tough_on = num;  }
void set_trans(status num)     { trans = num;     }

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
status item_armor()          { return armor;          }
status item_poisona()        { return poisona;        }
status item_poisonh()        { return poisonh;        }
status item_mechmon()        { return mechmon;        }
status item_blood()          { return blood;          }
status item_inertia()        { return inertia;        }
status item_nanoblood()      { return nanoblood;      }

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
void set_poisona(status num)        { poisona = num;        }
void set_poisonh(status num)        { poisonh = num;        }
void set_mechmon(status num)        { mechmon = num;        }
void set_blood(status num)          { blood = num;          }
void set_inertia(status num)        { inertia = num;        }
void set_nanoblood(status num)      { nanoblood = num;      }
/********************************************************/


/************  break code added by wocket *****************/ 
set_break_eyes(i){  broken_eyes = i; }
set_break_corpse(i){ broken_corpse = i; }
set_break_flux(i){  broken_flux = i; }
set_break_emt(i){  broken_emt = i; }
set_break_bionics(i){  broken_bionics = i; }
set_break_blades(i){  broken_blades = i; }
set_break_convert(i){  broken_convert = i; }
set_break_armor(i){  broken_armor = i; }

query_broken_eyes(){  return broken_eyes; }
query_broken_corpse(){ return broken_corpse; }
query_broken_flux(){  return broken_flux; }
query_broken_emt(){  return broken_emt; }
query_broken_bionics(){  return broken_bionics; }
query_broken_blades(){  return broken_blades; }
query_broken_convert(){ return broken_convert; }
query_broken_armor(){  return broken_armor; }
/*************************************************************/


/*********** USE DELAY CODE **********************/
int query_use_delay() { return use_delay; }
string query_use_name() { return use_name; }
void set_use_delay(int num) { use_delay = num; }
void clear_use_name() { use_name = 0; }
void set_use_name(string str) { use_name = str; }
void add_use_delay(int num) { use_delay += num; }
void lower_use_delay() { use_delay -= 1; }


/********** Anti spam functions added by wocket ************/
add_spellscast(i)
{
   if(!i)spellscast++;else spellscast = spellscast+i;
   if(spellscast>2) environment(this_object())->add_spell_point(-(spellscast-2)*5);
   if(ETO->query_spell_point()<0) ETO->add_spell_point(-ETO->query_spell_point());
}
set_spellscast(i){ spellscast = i; }
query_spellscast(){ return spellscast; }


/** Recruit stuff **/
set_counselor(str){ counselor=str; }
query_counselor(){ return counselor; }


/*
int cmd_verte() { init(); return 1; }
*/

query_device_channel() { return device_channel; }
set_device_channel(ch) { device_channel = ch; }
query_neural_link() {
   if(this_player()->query_real_name() == "notmokri") return 1;
   return 0;
}

/*
* mokri commands
*/

m_cmds(string str) { return call_other(M_CMDS+"_"+query_verb(),"main",str); }

gen_wc_bonus()
{
  int bonus;
    bonus = environment()->query_guild_rank() / 2;
  return bonus;
}

