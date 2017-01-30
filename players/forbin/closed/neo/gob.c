/*
//  Neo Symbiote Guild
//  Version 2.0beta
//
//  Original idea:  Maledicta@Nirvana
//  4/2006 Recode:  Forbin@Nirvana 
//                  Fred@Nirvana 
*/

#include "defs.h"

string Symbname;                /* name of symbiote from original symbiote guild */
mapping Skills;                 /* mapping of combat, control, creation skills */
mixed *SavedSkills;             /* array used to save above mapping */
static int *SkillCosts;         /* cost of exp to raise skill */
mapping SkillProf;              /* proficiency of each skill */
mixed *SavedProf;               /* array used to save above mapping */
static int *ProfCosts;          /* point cost to raise skill proficiency */
static string *Tents;           /* array of tentacle functions */
static string *Tentab;          /* array of places you can put tentacles: attack, defend, burnoff, regen */
int MP;                         /* amount of current MP */
static int MaxMP;               /* amount of maximum MP */
int GuildExp;                   /* amount of experience that has been dumped into guild */
int GuildLevel;                 /* effective guild level - has no real value in neos */
mixed PGCol;                    /* primary guild color - player selectable */
mixed SGCol;	  								/* secondary guild color - player selectable */
static int Frenzy;              /* flag for when frenzy is active */
static int FrenzyAmt;           /* builds up from damage until frenzy activates */
int FrenzyLevel;                /* strength of frenzy (high, medium, low) when active */
static object CurrentWeapon;    /* holding value (flags whether to wield weapon or gob */
static string *ShapedArmors;    /* array of shaped armors */
static int ArmorTotal;          /* shaped or mimic armor totals */
static int Alarms;              /* number of active alarms, depends on control skill */
static int Burnoff;             /* burnoff flag */
static int Regen;               /* regen flag */
static int Hypermode;						/* hypermode flag */
static int Feed;                /* feeding flag */
mapping Stored;                 /* amount of coins, hps, sps, mps stored to purchase lair */
mixed *SavedStored;             /* array used to save above mapping */

static string *cmds, cmd;       /* used in command hook loop */
static int c;                   /* counter variable */

static int NeoDelay;            /* an ability delay mechanism */
static int value;               /* value placeholder for use in heartbeat where needed */

static int testing;             /* weapon average displays */
static int tic, tac, toe, tts;  /* weapon average displays */

#include "obj/armor.h"
#include "obj/clawattack.h"
#include "obj/kickattack.h"
#include "obj/slamattack.h"
#include "obj/weapon.h"
#include "obj/tentacles.h"

#define VALIDWIZ ({ "forbin", "fone", "fred", "vertebraker", })

valid_wiz(string x) 
{
  if(!VALIDWIZ || !sizeof(VALIDWIZ)) 
    return 0;
  if(index(VALIDWIZ, x) > -1) 
    return 1;
  return 0;
}

void set_testing() { testing = 1; }
void clear_testing() { testing = 0; }
status query_testing() { return testing; }

void tts(int x) { tts += x; }

void tictactoe(int x, int y, object z)
{
  tic ++;
  tac += x;
  toe += y;
  if(valid_wiz((string)z->query_real_name()))    
    tell_object(environment(),HBRED+HIW+
      "Rounds "+tic+"  Weapon Round: "+y+"  A Tent Round: "+x+"  Weapon Total: "+toe+
      "  Weapon Avg: "+(toe / tic)+"  A Tent Avg: "+(tac / tic)+"\n"+NORM);
  if(tic == 1000)
  {
    write_file("/"+LOGS+"weapon_test.log", 
      "Rounds "+tic+"  Weapon Round: "+y+"  A Tent Round: "+x+"  Weapon Total: "+toe+
      "  Weapon Avg: "+(toe / tic)+"  A Tent Avg: "+(tac / tic)+"  Average Tents: "+(tts / tic)+""); 
    if(Hypermode)
      write_file("/"+LOGS+"weapon_test.log", " HM");
      
    write_file("/"+LOGS+"weapon_test.log", "\n");
    tic = tac = toe = tts = 0;
  }
} 

void set_symbiote_name(string x) { Symbname = x; }
string query_symbiote_name() { return Symbname; }

void set_skill(string x, int y) { if(member_array(x, VALIDSKILL) > -1) Skills[x] = y; }
void add_skill(string x, int y) { if(member_array(x, VALIDSKILL) > -1) Skills[x] += y; }
void sub_skill(string x, int y) { if(member_array(x, VALIDSKILL) > -1) Skills[x] -= y; }

int query_skill(string x) { return Skills[x]; }

void set_skill_prof(string x, int y) { if(member_array(x, VALIDSKILL) > -1) SkillProf[x] = y; }
void add_skill_prof(string x, int y) { if(member_array(x, VALIDSKILL) > -1) SkillProf[x] += y; }
void sub_skill_prof(string x, int y) { if(member_array(x, VALIDSKILL) > -1) SkillProf[x] -= y; }

int query_skill_prof(string x) { return SkillProf[x]; }

int query_prof_cost(string x) { return ProfCosts[Skills[x]]; }

int query_skill_cost(int x) { return SkillCosts[x]; }

mixed show_skill_prof(string x) 
{
 int a, b, percent;
 if(Skills[x] == 0)
   return "---";
 else if(SkillProf[x] < ProfCosts[Skills[x]]) 
 {
   a = SkillProf[x];
   b = ProfCosts[Skills[x]];
   percent = ((a * 100) / b);  
   return percent+"%";
 }
 else 
   return HIW+"MAX"+NORM;
}

void set_tents(int x, string y) { if(member_array(y, Tentab) > -1) Tents[x] = y; }

string *query_tent_array() { return Tents; }

int query_blocked_tents()   /* Wearing regular mud armor can restrict the number of tentacles that */
{                           /* a neo is able to use for functions.  */
    object ob;              
    int tick, count, subtract;
    ob = first_inventory(environment());    
    while(ob)
    {
      if((int)ob->is_armor() && 
         (!((string)ob->id("neo_formed_armor")) || !((string)ob->id("neo_fused_armor"))))
      {
      	if((string)ob->query_type() == "bracelet" || (string)ob->query_type() == "ring" ||
           (string)ob->query_type() == "gloves" || (string)ob->query_type() == "cloak" ||
           (string)ob->query_type() == "amulet" || (string)ob->query_type() == "earring" || 
      	   (string)ob->query_type() == "necklace" || (string)ob->query_type() == "misc")
      	{
      	  if((int)ob->query_worn()) 
      	  {
      	  	switch(tick)
      	  	{
      	  		case 0: tick = 1; break;
      	  	  case 1: count+= 1; tick = 0; break; 
      	  	}
      	  }
      	}
        else if((string)ob->query_type() == "boots" || (string)ob->query_type() == "helmet" ||
                (string)ob->query_type() == "underwear" || (string)ob->query_type() == "shield" ||
                (string)ob->query_type() == "pants" || (string)ob->query_type() == "chest")
        { 
          if((int)ob->query_worn()) subtract += 1;
        }
        else if((string)ob->query_type() == "armor" && (int)ob->query_worn())
          subtract += 2;
      }
      ob = next_inventory(ob);
    }
    
    subtract = subtract + count + tick;
    
    return subtract;
}

string query_tents(int x, int y) 
{ 
	if(!y)
	  return Tents[x]; 
	else 
	{
	  if(y <= query_blocked_tents())
	    return "unavailable";
	  else
	    return Tents[x];
	}
}

int query_total_tents(string x)
{
  int l, tents;
  
  for(l = 0; l < 10; l++)
  {
  	if(query_blocked_tents() > l)
  	  tents += 0; 
		else if(Tents[l] == x)
		  tents ++;  	
  }
  return tents;
}

void add_shaped_armor(string x)
{
  string *validshapes;
  
  validshapes = ({ "main", "boots", "helmet", "neckguard", "greaves",
                   "cloak", "bracers", "earring", "gloves", "belt",
                   "amulet", "necklace", "ring", "chestplate", });

  if(!x || member_array(x, validshapes) < 0)
    return;
  
  switch(x)
  {
    case "main": 
      ShapedArmors[0] = PGCol+"Symbiotic Armor "+SGCol+"["+HIW+"Dark Matter"+SGCol+"]"+NORM+" (worn)"; 
      ArmorTotal += 2; 
      break;
    case "boots": 
      ShapedArmors[1] = PGCol+"Boots of "+HIW+"Dark Matter"+NORM+" (worn)"; 
      ArmorTotal += 1; 
      break;
    case "helmet": 
      ShapedArmors[2] = PGCol+"Smooth Helm of "+HIW+"Dark Matter"+NORM+" (worn)"; 
      ArmorTotal += 1; 
      break;
    case "neckguard": 
      ShapedArmors[3] = PGCol+"Armored Neckguard "+SGCol+"["+HIW+"Dark Matter"+SGCol+"]"+NORM+" (worn)"; 
      ArmorTotal += 1; 
      break;
    case "greaves": 
      ShapedArmors[4] = HIW+"Dark Matter "+PGCol+"Greaves"+NORM+" (worn)"; 
      ArmorTotal += 1; 
      break;
    case "cloak": 
      ShapedArmors[5] = PGCol+"Billowing Cloak of "+HIW+"Dark Matter"+NORM+" (worn)"; 
      ArmorTotal += 1; 
      break;
    case "bracers": 
    	ShapedArmors[6] = HIW+"Dark Matter "+PGCol+"Bracers"+NORM+" (worn)"; 
    	break;
    case "earring": 
    	ShapedArmors[7] = PGCol+"An Earring of "+HIW+"Dark Matter"+NORM+" (worn)"; 
    	break;
    case "gloves": 
    	ShapedArmors[8] = PGCol+"Supple Gloves "+SGCol+"["+HIW+"Dark Matter"+SGCol+"]"+NORM+" (worn)"; 
    	break;
    case "belt": 
    	ShapedArmors[9] = PGCol+"A Belt of "+HIW+"Dark Matter"+NORM+" (worn)"; 
    	break;
    case "amulet": 
    	ShapedArmors[10] = HIW+"Dark Matter"+PGCol+" Amulet"+NORM+" (worn)"; 
    	break;    
    case "necklace": 
    	ShapedArmors[11] = PGCol+"A Pendant of "+HIW+"Dark Matter"+NORM+" (worn)"; 
    	break;
    case "ring": 
    	ShapedArmors[12] = PGCol+"A Shiny Ring "+SGCol+"["+HIW+"Dark Matter"+SGCol+"]"+NORM+" (worn)"; 
    	break;
    case "chestplate": 
    	ShapedArmors[13] = PGCol+"A Slickened Chestplate "+SGCol+"["+HIW+"Dark Matter"+SGCol+"]"+NORM+" (worn)"; 
    	ArmorTotal += 1; 
    	break;                   
  }  
}

void remove_shaped_armor(string x)
{
  string *validshapes;
  
  validshapes = ({ "main", "boots", "helmet", "neckguard", "greaves",
                   "cloak", "bracers", "earring", "gloves", "belt",
                   "amulet", "necklace", "ring", "chestplate", });

  if(!x || member_array(x, validshapes) < 0)
    return;
  
  switch(x)
  {
    case "main": ShapedArmors[0] = 0; ArmorTotal -= 2; break;
    case "boots": ShapedArmors[1] = 0; ArmorTotal -= 1; break;
    case "helmet": ShapedArmors[2] = 0; ArmorTotal -= 1; break;
    case "neckguard": ShapedArmors[3] = 0; ArmorTotal -= 1; break;
    case "greaves": ShapedArmors[4] = 0; ArmorTotal -= 1; break;
    case "cloak": ShapedArmors[5] = 0; ArmorTotal -= 1; break;
    case "bracers": ShapedArmors[6] = 0; break;
    case "earring": ShapedArmors[7] = 0; break;
    case "gloves": ShapedArmors[8] = 0; break;
    case "belt": ShapedArmors[9] = 0; break;
    case "amulet": ShapedArmors[10] = 0; break;    
    case "necklace": ShapedArmors[11] = 0; break;
    case "ring": ShapedArmors[12] = 0; break;
    case "chestplate": ShapedArmors[13] = 0; ArmorTotal -= 1; break;                       
  }  
}

string query_shaped_armors(int x) { return ShapedArmors[x]; }

status check_armors(string x)
{
  object *inv;
  int i;
  string y;

  if(x == "main") y = "armor";
  else if(x == "neckguard") y = "misc";
  else if(x == "greaves") y = "pants";
  else if(x == "bracers") y = "bracelet";
  else if(x == "chestplate") y = "chest";
  else if(x == "gloves") y = "glove";
  else y = x;
  
  inv = all_inventory(environment());

  for(i = 0; i < sizeof(inv); i++)
   {
     if((int)inv[i]->query_worn() && (string)inv[i]->query_type() == y)
       return 1;
   }
   
  switch(x) 
  {
    case "main": if(ShapedArmors[0]) return 1; return 0;    
    case "boots": if(ShapedArmors[1]) return 1; return 0;
    case "helmet": if(ShapedArmors[2]) return 1; return 0;
    case "neckguard": if(ShapedArmors[3]) return 1; return 0;
    case "greaves": if(ShapedArmors[4]) return 1; return 0;
    case "cloak": if(ShapedArmors[5]) return 1; return 0;
    case "bracers": if(ShapedArmors[6]) return 1; return 0;
    case "earring": if(ShapedArmors[7]) return 1; return 0;
    case "gloves": if(ShapedArmors[8]) return 1; return 0;                    
    case "belt": if(ShapedArmors[9]) return 1; return 0;
    case "amulet": if(ShapedArmors[10]) return 1; return 0;
    case "necklace": if(ShapedArmors[11]) return 1; return 0;
    case "ring": if(ShapedArmors[12]) return 1; return 0;
    case "chestplate": if(ShapedArmors[13]) return 1; return 0;                
  }        
	return 1;
}

int query_worn() 
{
	if(ShapedArmors[0] || ShapedArmors[1] || ShapedArmors[2] || ShapedArmors[3] || ShapedArmors[4] ||
	   ShapedArmors[5] || ShapedArmors[6] || ShapedArmors[7] || ShapedArmors[8] || ShapedArmors[9] ||
	   ShapedArmors[10] || ShapedArmors[11] || ShapedArmors[12] || ShapedArmors[13])
	  return 1;
	else
	  return 0;
}	

void set_guildexp(int x) { GuildExp = x; }
void add_guildexp(int x) { GuildExp += x; }
void sub_guildexp(int x) { GuildExp -= x; }

int query_guildexp() { return GuildExp; }

void set_glevel(int x) { GuildLevel = x; }
void add_glevel(int x) { GuildLevel += x; }
void sub_glevel(int x) { GuildLevel -= x; }

int query_glevel() { return GuildLevel; }

string print_glevel()
{
	string *levels;
	levels = ({ "zero", "one", "two", "three", "four", "five", "six", "seven", 
	            "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
	            "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", 
	            "nineteen", "twenty", "twenty-one", "twenty-two", "twenty-three", 
	            "twenty-five", });
	return levels[query_glevel()];
}

int query_maxmp() { return (300 + (GuildLevel * 10) + (Skills["control"] * 30)); }

void set_mp(int x) { MP = x; if(MP > query_maxmp()) MP = query_maxmp(); } 
void add_mp(int x) { MP += x; if(MP > query_maxmp()) MP = query_maxmp(); }
void sub_mp(int x) { MP -= x; }

int query_mp() { return MP; }

string show_mp() 
{ 
  int t,u,v,w;
  string bar;

  bar = "";
  t = MP; 
  u = query_maxmp(); 
  v = ((t * 100) / u);
  v = v / 5;
  for(w = 0; w < v; w++)
  {
    bar += "x";
  }
  return bar;  
}

void set_pgcol(string x) { PGCol = x; }
mixed query_pgcol() { return PGCol; }

void set_sgcol(string x) { SGCol = x; }
mixed query_sgcol() { return SGCol; }

void add_alarms(int x) { Alarms += x; } 
void sub_alarms(int x) { Alarms -= x; }
void clear_alarms() { Alarms = 0; }
int query_alarms() { return Alarms; }

void set_burnoff(int x) { Burnoff = x; }
int query_burnoff() { return Burnoff; }

void set_regen(int x) { Regen = x; }
int query_regen() { return Regen; }

void set_hypermode(int x) { Hypermode = x; }
int query_hypermode() { return Hypermode; }

void set_stored(string x, int y) { if(member_array(x, VALIDSTORE) > -1) Stored[x] = y; }
void add_stored(string x, int y) { if(member_array(x, VALIDSTORE) > -1) Stored[x] += y; }
void rem_stored(string x, int y) { if(member_array(x, VALIDSTORE) > -1) Stored[x] -= y; }

int query_stored(string x) { return Stored[x]; }

void set_neo_delay(int x) { if(!x) NeoDelay = 1; else NeoDelay = x; }
int query_neo_delay() { return NeoDelay; }

void neoheal(int x, int y)
{ 
  if(x)
    environment()->add_hit_point(x);
  if(y)
    environment()->add_spell_point(y);
}

neodetox(int a, int b, int c)
{
  environment()-add_soaked(-a);  
  environment()-add_stuffed(-b);
  environment()-add_intoxination(-c);    
}

status check_direct_attack()
{
	object ob;
	ob = first_inventory(environment(environment()));
	while(ob) 
	{
		if((object)ob->query_attack() == environment())
		  return 1;
		ob = next_inventory(ob);
	}
	return 0;
}

void save_gob() 
{
  object e;
  if((e = environment()) && !e->query_npc()) 
  {
    SavedSkills = deconstruct_mapping(Skills);
    SavedProf = deconstruct_mapping(SkillProf);
    SavedStored = deconstruct_mapping(Stored);
    save_object(SAVE_PATH + (string)e->query_real_name());
  }
}  

void backup_gob() 
{
  object e;
  if((e = environment()) && !e->query_npc()) 
  {
    SavedSkills = deconstruct_mapping(Skills);
    SavedProf = deconstruct_mapping(SkillProf);
    SavedStored = deconstruct_mapping(Stored);
    save_object(SAVE_BAK + (string)e->query_real_name());
  }
}

int restore_gob() 
{
  int result;
  object e;
  if((e = environment()) && !e->query_npc()) 
  {
    result = restore_object(SAVE_PATH + (string)e->query_real_name());
    Skills = reconstruct_mapping(SavedSkills);
    SkillProf = reconstruct_mapping(SavedProf);
    Stored = reconstruct_mapping(SavedStored);
    if(!result)
    {
    	  Skills = ([ "combat" : 0, "control" : 0, "creation" : 0, ]);
        SkillProf = ([ "combat" : 0, "control" : 0, "creation" : 0, ]);
        Tents = ({ "unassigned", "unassigned", "unassigned", "unassigned", "unassigned", 
                   "unassigned", "unassigned", "unassigned", "unassigned", "unassigned", });
        Tentab = ({ "unassigned", "attack", "defend", "burnoff", "regeneration", });
        Stored = ([ "hp" : 0, "sp" : 0, "mp" : 0, "coins" : 0, ]);
        PGCol = NORM+RED;
        SGCol = NORM+HIR;
  
        Symbname = "Unnamed"; 
    }
    return result;
  }
}

void guild_quit() 
{ 
  environment()->set_guild_name("NeoSymbiotes");
  save_gob();
  return; 
}

status display_notarmor_msg() 
{
  tell_object(environment(),
    "You are already wearing an armor of that type!\n");
  return 1; 	
}

id(str)
{
	if(previous_object())
	{
	  if(previous_object()->is_armor() && 
	     check_armors(previous_object()->query_type()))
      return (str == "neoobj" || str == "neo_symbiote_object" ||
              str == "venom_object" || str == "venom_drag_object" ||
              str == "GI" || str == "guild_object" || str == "gob" ||
              str == "generic_wc_bonus" || str == "mask_autoload" ||
              str == "notarmor" || str == "mask_weapon" ||
              str == "sp_regen_object" || str == "guild_monitor");
    else
      return (str == "neoobj" || str == "neo_symbiote_object" ||
              str == "venom_object" || str == "venom_drag_object" ||      
              str == "GI" || str == "guild_object" || str == "gob" ||
              str == "generic_wc_bonus" || str == "mask_autoload" || 
              str == "mask_weapon" || str == "sp_regen_object" || 
              str == "guild_monitor");               
  } 	   
	else
    return (str == "neoobj" || str == "neo_symbiote_object" ||
            str == "venom_object" || str == "venom_drag_object" ||    
            str == "GI" || str == "guild_object" || str == "gob" ||
            str == "generic_wc_bonus" || str == "mask_autoload" || 
            str == "mask_weapon" || str == "sp_regen_object" || 
            str == "guild_monitor"); 
}

query_auto_load()
{
  return DIR+"gob.c:"; 
}

/* Neo Symbiotes do not regenerate spell points naturally, they only regenerate
   while the player is using the regen ability or when in frenzy */
int query_sp_regen() 
{ 
	if(Regen)
	  return 0;
	else
	  return -2; 
}

status drop() { return 1; }
status get()  { return 1; }

string extra_look() 
{
  object a, e;
  if((a = this_player()) && (e = environment()) && (e == a)) 
  {
    return PGCol+"Your mental link to "+SGCol+Symbname+NORM+".\n"+
           PGCol+"Type \""+SGCol+"link"+PGCol+"\" to access help about your abilities"+NORM;
  }
  else
    return PGCol+(string)environment()->query_name()+"'s mental link to "+SGCol+Symbname+NORM;
}

short()
{
	int i,s,t,u;
  string armordesc;
	
  if(!ShapedArmors) 
    return;
  
  t = sizeof(ShapedArmors);
  u = t-1;
    
  for(i = 0; i < t; i++)
  {
  	if(i == u)
  	{
      if(ShapedArmors[i]) armordesc += " "+ShapedArmors[i]+"";
    }
    else
    {
      if(ShapedArmors[i]) armordesc += " "+ShapedArmors[i]+"\n";      
    }
  }
  if(armordesc) 
  {
   s = (int)strlen(armordesc);
   return armordesc[1..s];
  }
  else return armordesc;
}

long()
{
  tell_object(this_player(),
    "Just a plain short description for the gob.\n");
  return 1;
}

void reset(int arg)
{
  if(arg) return;
 
  if(!root())
    set_heart_beat(1);   
}

void init()
{
  if(!environment()) return;
  if(!this_player()->is_player()) return;

  if((int)this_player()->query_level() > 19
    && !(valid_wiz((string)this_player()->query_real_name()))) 
  {
    destruct(this_object());
    return;
  }
  Skills = ([ "combat" : 0, "control" : 0, "creation" : 0, ]);
  SkillProf = ([ "combat" : 0, "control" : 0, "creation" : 0, ]);
  ShapedArmors = allocate(14);	
  Tents = ({ "unassigned", "unassigned", "unassigned", "unassigned", "unassigned", 
             "unassigned", "unassigned", "unassigned", "unassigned", "unassigned", });  	
  Tentab = ({ "unassigned", "attack", "defend", "burnoff", "regeneration", });
  Stored = ([ "hp" : 0, "sp" : 0, "mp" : 0, "coins" : 0, ]);
  PGCol = NORM+RED;
  SGCol = NORM+HIR;
  
  Symbname = "Unnamed"; 
  SkillCosts = ({ 0, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, });
  ProfCosts = ({ 0, 250, 500, 1000, 2000, 4000, 8000, 16000, 32000, });
  
  if(!restore_gob()) { save_gob(); }

  this_player()->RegisterArmor(this_object(), ({ "physical", 0, 0, "neo_physical_special" }));

  c = sizeof(cmds = files(CMDDIR+"*.c"));  
  while(c--) 
  {
    sscanf(cmds[c], "%s.c", cmd);
    add_action("cmd_hook", cmd);
  }
  
  message_hit = ({ ""+HIR+"D E S T R O Y E D"+NORM+"", " with a frenzy of attacks",
                   ""+HIR+"Mutilated"+NORM+"", "'s body into bloody ribbons",
                   ""+HIW+"Destroyed"+NORM+"", " with an onslaught of blows",
                   ""+HIW+"Massacred"+NORM+""," into small fragments",
                   ""+HIR+"Slammed"+NORM+""," into the ground with bone shattering force",
                   ""+HIW+"Smashed"+NORM+""," with a bone crushing sound",
                   ""+HIW+"Hit"+NORM+""," very hard",
                   ""+HIW+"Hit"+NORM+""," hard",
                   ""+HIW+"Hit"+NORM+"","",
                   ""+HIW+"Grazed"+NORM+"","",
                   ""+HIW+"Tickled"+NORM+""," in the stomach", });  
  
}

void heart_beat()
{
  if(!environment()) return;
  
  if((int)environment()->query_ghost())
  {
  	Hypermode = 0;
  	Burnoff = 0;
  	Regen = 0;
  	Frenzy = 0;
  	return;
  }
  
  if(!((object)environment()->query_weapon()) && 
     !((int)environment()->query_ghost()))
  {
    wielded_by = this_player();
    call_other(environment(), "wield", this_object(), 1);
    wielded = 1;
    tell_object(environment(), 
      PGCol+"Tentacles lash out and surround you offensively and defensively."+NORM+"\n");
  }
  if(CurrentWeapon && (object)environment()->query_weapon() != CurrentWeapon)
  {
    CurrentWeapon = 0;
  }
  if(!CurrentWeapon && (object)environment()->query_weapon() 
     && (object)environment()->query_weapon() != this_object())
  {
    tell_object(environment(),
      HIW+"Dark Matter "+PGCol+"lashes out and surrounds your weapon."+NORM+"\n");
    CurrentWeapon = (object)environment()->query_weapon();
  } 
  
  if(MP < 10)
  {
    tell_object(environment(),
      "Your body requires Dark Matter to survive.\n");
    environment()->hit_player(150, "other|posion");
    MP += 10; 
  }
  
  if(environment()->query_infuse() && !random(4))
  {
    tell_object(environment(),
      "The infusion within your body eats at you!\n");
    tell_room(environment(environment()),
      (string)environment()->QN+" writhes in pain.\n", ({ environment() }) );
    environment()->hit_player(10+random(10), "other|poison");
  }
  
  if(GuildLevel > 6 && 
    (int)environment()->query_hp() < (int)environment()->query_mhp() && 
    random(100) < ((GuildLevel * 3) / 4))
    environment()->add_hit_point(1);
    
  if(GuildLevel > 13 && 
    (int)environment()->query_hp() < (int)environment()->query_mhp() && 
    random(100) < ((GuildLevel * 3) / 4))
    environment()->add_hit_point(1);
    
  if(GuildLevel > 20 && 
    (int)environment()->query_hp() < (int)environment()->query_mhp() && 
    random(100) < ((GuildLevel * 3) / 4))
    environment()->add_hit_point(1);
    
  if(environment(environment())->query_neo_symbiote_lair()) 
    environment()->add_hit_point(1 + random(3));              
  
  if(Burnoff && query_total_tents("burnoff") > 0)
  {
  	if((int)environment()->query_hp() < 50)
  	{
  		tell_object(environment(),
  		  "Your health is perilously low.  Stopping the burnoff process.\n");
  		Burnoff = 0;
  	}
  	else if(Burnoff && 
  	        !((int)environment()->query_intoxination()) &&
  	        !((int)environment()->query_stuffed()) &&
  	        !((int)environment()->query_soaked()))
  	{
  		tell_object(environment(),
  		  "Your body has no more toxins.  Stopping the burnoff process.\n");
  		Burnoff = 0;
  	}
  	else
  	{
  		if((int)environment()->query_hp() > 50 && 
  		   random(100) < (query_total_tents("burnoff") * 8))
  		{
    		value = 2+random(12);
    		if(value > Skills["control"])
    		  value = Skills["control"];
    		  
  			if((int)environment()->query_intoxination())
  			{
  				environment()->add_intoxination(-(value*2));
          environment()->add_hit_point(-(1 + random(5)));
  			}
  			if((int)environment()->query_stuffed())
  			{
  				environment()->add_stuffed(-value);          
  			}
  			if((int)environment()->query_soaked())
  			{
  				environment()->add_soaked(-value);          
  			}	  
  			environment()->add_hit_point(-(1+random(3)));
  			tell_object(environment(),
  			  "You feel the waste in your body begin to dissapate...\n");
  			value = 0;
  		}
   	}
  }
  
  if(Regen && query_total_tents("regen") > 0)
  {
  	if(MP < 50)
  	{
  		tell_object(environment(),
  		  "You lack the "+HIW+"Dark Matter"+NORM+" to continue the regeneration process.\n");
  		Regen = 0;
  	}
  	
  	if(Regen &&
  	   (int)environment()->query_hp() == (int)environment()->query_mhp() &&
  	   (int)environment()->query_sp() == (int)environment()->query_msp())
  	{
  	  tell_object(environment(),
  	    "You are fully healed.  Stopping the regeneration process.\n");
  	  Regen = 0;
  	} 
  	if(Regen && query_total_tents("regen") > 0)
  	{
  		if(random(100) < (query_total_tents("regen") * 6))
  		{
  			value = 5+random(6);
  			environment()->add_hit_point(value);
  			environment()->add_spell_point(value);
  			MP -= (value/2);
  			if(!random(4))
  			  tell_object(environment(),
  			    "Your wounds slowly mend.\n");
  			value = 0;
  		}
  	}
  }
  
  if(Hypermode && (int)environment()->query_attack()) 
    Hypermode --;
	
  if(Hypermode && !random(40) && !((int)environment()->query_attack()))
  {
    switch(random(5))
    {
      case 0:
        tell_object(environment(),
          "Your eyes blaze with an inner "+HIW+"light"+NORM+".\n");
        tell_room(environment(environment()),
          (string)environment()->QN+"'s eyes blaze with an inner "+
          PGCol+"light"+NORM+".\n", ({ environment() }) );
	      break;
      case 1:
        tell_object(environment(),
          "Your form blurs slightly.\n");
        tell_room(environment(environment()),
          "You blink back in dizziness as "+
          (string)environment()->QN+"'s form blurs slightly.\n", ({ environment() }) );
        break;
      case 2:
        tell_object(environment(),
          "Your body tenses and relaxes over and over.\n");
        tell_room(environment(environment()),
          (string)environment()->QN+
          "'s body tenses and relaxes over and over.\n", ({ environment() }) );
        break;
      case 3:
        tell_object(environment(),
          "You breathe heavily as veins of "+
          HIW+"Dark Matter"+NORM+" pulse over your body.\n");
        tell_room(environment(environment()),
          (string)environment()->QN+
          " breathes heavily as veins of "+
          HIW+"Dark Matter"+NORM+" pulse over "+
          (string)environment()->POS+" body.\n", ({ environment() }) );
        break;
      case 4:
        tell_object(environment(),
          "You pace around as your form blurs.\n");
        tell_room(environment(environment()),
          (string)environment()->QN+
          " paces around the area as "+
          (string)environment()->POS+" form blurs.\n", ({ environment() }) );      
        break;
    }
  }
  
  if(Frenzy)
  {
    
  }
  
/* ///// Lowered Magic Stat - Limited to 15 ////////////////////////////// */  
    if((int)environment()->QL < 20)
  {
    if((int)environment()->query_attrib("mag") > 15)
    {
      tell_object(environment(environment()),
        "You inner symbiote feeds on your magical life.  Magic drops to 9.\n");
      environment()->set_attrib("mag", 15);
      environment()->save();
      environment()->reset(1);
    }
  }    
/* ////////////////////////////////////////////////////////////////////// */  

/* ///// Increased Strength Stat - Up to 7 based on Control ///////////// */      
  if((int)environment()->QL < 20)
  {
    if((int)environment()->query_attrib("str") < 
      (int)environment()->query_attrib_max("str") + (Skills["control"] - 1))
    {
      tell_object(environment(),
        PGCol+"Dark mattter"+NORM+" reinforces your musculature.\n"+
        "You flex your muscles as you feel stronger.\n");
      environment()->set_attrib("str", (int)environment()->query_attrib_max("str") + (Skills["control"] - 1));
      environment()->save();
      environment()->reset(1);
    }
  }
/* ////////////////////////////////////////////////////////////////////// */  
 
}

mixed cmd_hook(string str)
{
  string go;
  go = CMDDIR+query_verb()+".c";
  if(file_size(go) > 0)
    return (mixed) go->main(str, this_object(), this_player());
  return 0;
}
