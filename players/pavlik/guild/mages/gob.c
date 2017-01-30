inherit "players/pavlik/guild/mages/inherit/calculate_exp";
inherit "players/pavlik/guild/mages/inherit/transfer_exp"; /* mizan */
inherit "players/pavlik/guild/mages/inherit/health_monitor";
inherit "players/pavlik/guild/mages/inherit/string";
#include "defs.h"
#include "include/string.h"

static int casting;
static int hb_count;
static int cmd_count;
static int autosave;
static int dragon_hps;
static string is_loaded;
static mapping guild_var;
static mapping guild_bonus;
static mapping next_casting;
static mapping spell_objects;
static mapping spell_count;

int intelligence;		/* guild attribute */
int wisdom;			/* guild attribute */
int will_power;			/* guild attribute */
int power;			/* guild attribute */
int conjuration;		/* guild statistic */
int enchantment;		/* guild statistic */
int evocation;			/* guild statistic */
int illusion;			/* guild statistic */
int necromancy;			/* guild statistic */
int weapons;			/* guild statistic */
int monitor;			/* guild monitor */

string *spells;			/* stored array of known spells (NEW) */
int training_sessions;		/* chances to raise stats */
int new_spell_chances;		/* chances to learn new spells */
string dragon_stats;		/* guild pet stats */
string dragon_descrip;		/* guild pet description */
static object dragon;		/* active guild pet object */
string login_cmds;		/* commands executed at login */
string logout_cmds;		/* commands executed at logout */
string login_msg;		/* custom login message */
string logout_msg;		/* custom logout message */
string sponsor;			/* guild sponsorship info */
string staff_spells;		/* being phased out... */
int muffled;			/* guild channel muffles */
int my_exp;			/* track our earned experience (non-guild) */
int divd;			/* how much earned exp goes to the guild */
int donation;			/* guild donations */
int balance;			/* guild donations */
int spell_dtype;                /* prestige players can set dtypes */

reset(arg)
{
  if(arg) return;
  casting = 0;
  divd = 50;
  my_exp = 0;
  donation = 0;
  balance = 0;
  dragon_stats = "dragon#1#1#1#1#1";
  dragon_descrip = "the#none";
  staff_spells = "0#0#0#0#0#0";
  sponsor = "0#0+";
  login_cmds = 0;
  logout_cmds = 0;
  hb_count = 0;
  cmd_count = 0;
  monitor = 1;
  autosave = 0;
  spells = ({});
  guild_var = ([]);
  guild_bonus = ([]);
  spell_objects = ([]);
  spell_count = ([]);
  set_heart_beat(1);
}

/* object version */
query_gob_version(){ return GOB_VERSION; }

mage_autosave()
{
  if(en->query_level() < WIZLEVEL)
	call_other(en, "set_al_title", rancol2("MAGE"));
  if(GOB_FILENAME->query_gob_version() > GOB_VERSION)
	tell_object(en, HIC+"* Updated Mage Soul available, type 'renew'\n"+NORM);
  if(spells && sizeof(spells))
	save_object(SAVE_DIR+en->query_real_name());
  return 1;
}

save_data(name)
{
  save_object(SAVE_DIR+name);
}

load_data(name)
{
  restore_object(SAVE_DIR+name);
  is_loaded = name;
}

/* spells */
query_spell(string name)	{ return (member_array(name, spells) == -1 ? 0 : 1); }
query_spells()			{ return spells; }
learn_spell(string name)	{ add_spell(name); }
add_spell(string name)		{ if(member_array(name, spells) == -1) spells += ({ name }); }
clear_all_spells()		{ spells = ({}); }

/* ability to learn new skills */
add_new_spell_chances(i)	{ new_spell_chances += i; }
query_new_spell_chances()	{ return new_spell_chances; }
add_training_sessions(i)	{ training_sessions += i; }
query_training_sessions()	{ return training_sessions; }

/* stats for the dragon (guild pet) */
set_dragon_stats(str)		{ dragon_stats = str; }
query_dragon_stats()		{ return dragon_stats; }
set_dragon_descrip(str)		{ dragon_descrip = str; }
query_dragon_descrip()		{ return dragon_descrip; }
set_dragon(obj)			{ dragon = obj; }
query_dragon()			{ return dragon; }

/* guild health monitor */
set_monitor(i)			{ monitor = i; }
query_monitor()			{ return monitor; }

/* flags for various guild spells and functions */
set_divd(str){ divd = str; }		/* guild experience division */
query_divd(){ return divd; }		/* guild experience division */
set_muffled(str){ muffled = str; }	/* guild channel muffles */
query_muffled(){ return muffled; }	/* guild channel muffles */
set_my_exp(str){ my_exp = str; }	/* track experience */
query_my_exp(){ return my_exp; }	/* track experience */
set_casting(str){ casting = str; }	/* flag for spell casting */
query_casting(){ return casting; }	/* flag for spell casting */
set_sponsor(str){ sponsor = str; }	/* guild sponsorship */
query_sponsor(){ return sponsor; }	/* guild sponsorship */
add_sponsor(str){ sponsor += str; }	/* guild sponsorship */
query_donation(){ return donation; }	/* guild donations */
query_balance(){ return balance; }		/* balance */
add_balance(bal){ balance = balance + bal; }	/* balance */
add_donation(num)
{
  donation = donation + num; if(donation >= 48000+random(3000)) DAEMON->max_donation();
}

set_login_cmds(str){ login_cmds = str; }	/* login commands */
query_login_cmds(){ return login_cmds; }	/* login commands */
set_logout_cmds(str){ logout_cmds = str; }	/* logout commands */
query_logout_cmds(){ return logout_cmds; }	/* logout commands */
set_login_msg(str){ login_msg = str; }		/* custom login message */
query_login_msg(){ return login_msg; }
set_logout_msg(str){ logout_msg = str; }	/* custom logout message */
query_logout_msg(){ return logout_msg; }

set_staff_spells(str) { staff_spells = str; }	/* mage staff */
query_staff_spells()  { return staff_spells; }	/* mage staff */


/*
 * Query Spell Rank - used to determine players guild rank for spell casting
 */
query_spell_rank() {
	return (tp->query_guild_rank() > MAXGUILDRANK ? MAXGUILDRANK : tp->query_guild_rank());
}

/*
 * Raise Guild Stat
 */
raise_guild_stat(string name, int amt)
{
  switch(name)
  {
	case "conjuration"  : conjuration += amt; if(conjuration > 100) conjuration = 100;	break;
	case "enchantment"  : enchantment += amt; if(enchantment > 100) enchantment = 100;	break;
	case "evocation"    : evocation += amt;   if(evocation > 100) evocation = 100;		break;
	case "illusion"     : illusion += amt;    if(illusion > 100) illusion = 100;		break;
	case "necromancy"   : necromancy += amt;  if(necromancy > 100) necromancy = 100;	break;
	case "weapons"      : weapons += amt;     if(weapons > 100) weapons = 100;		break;
	case "intelligence" : intelligence += amt; if(intelligence > 100) intelligence = 100;	break;
	case "wisdom"       : wisdom += amt;      if(wisdom > 100) wisdom = 100;		break;
	case "will power"   : will_power += amt;  if(will_power > 100) will_power = 100;	break;
	case "power"        : power += amt;       if(power > 100) power = 100;			break;
  }
}

/*
 * Query "raw" Guild Stat
 */
query_guild_stat(string name)
{
  switch(name)
  {
	case "conjuration"  : return conjuration;	break;
	case "enchantment"  : return enchantment;	break;
	case "evocation"    : return evocation;		break;
	case "illusion"     : return illusion;		break;
	case "necromancy"   : return necromancy;	break;
	case "weapons"      : return weapons;		break;
	case "intelligence" : return intelligence;	break;
	case "wisdom"       : return wisdom;		break;
	case "will power"   : return will_power;	break;
	case "power"        : return power;		break;
  }
}

/*
 * Query Guild Stat + Bonuses
 */
query_total_guild_stat(string name)
{
  int i;
  switch(name)
  {
	case "conjuration"  : i = conjuration + query_guild_bonus("conjuration"); break;
	case "enchantment"  : i = enchantment + query_guild_bonus("enchantment"); break;
	case "evocation"    : i = evocation + query_guild_bonus("evocation"); break;
	case "illusion"     : i = illusion + query_guild_bonus("illusion"); break;
	case "necromancy"   : i = necromancy + query_guild_bonus("necromancy"); break;
	case "weapons"      : i = weapons + query_guild_bonus("weapons"); break;
	case "intelligence" : i = intelligence + query_guild_bonus("intelligence"); break;
	case "wisdom"       : i = wisdom + query_guild_bonus("wisdom"); break;
	case "will power"   : i = will_power + query_guild_bonus("will_power"); break;
	case "power"        : i = power + query_guild_bonus("power"); break;
  }
  if(i > STAT_MAX) i = STAT_MAX;
  return i;
}

#define IDS ({"mageobj","mageobj2","mageobj_NEW","no_spell","spellbook",\
              "guild_object","GI","generic_wc_bonus",\
              "generic_hp_bonus","generic_sp_bonus",\
})
              
id(str)
{
  if(member_array(str, IDS) > -1) return 1;
  else if(str=="notarmor")
  {
	object c;
	if((c=caller()) && c->is_armor())
	{
		string a;
		if((a=(string)c->query_type()) && (a=="helmet" || a=="shield") &&
		  (!c->id("wiz_hat") && !c->id("mage_belt")))
			return 1;
		else if((int)c->query_weight() > 1)
			return 1;
	}
  }
  else if(str == "no_weapon_attack" || str == "no_msg_hit")
  {
	if(query_casting()) return 1;
	else return 0;
  }
}

/* this is a guild object, treat accordingly! */
is_gob(){ return 1; }

/* use this to stop attack messages when casting */
do_no_attack_message(ob){ return 1; }

int gen_wc_bonus()
{
  int bonus;
  object wep;

  bonus -= (random(GENERAL_WEAPON_PENALTY));		/* general mage deduction */
  
  if(wep=(object)environment()->query_weapon())
  {
	int s, found;
	s = sizeof(MAGEWEPS);
	while(s-- && !found) 
		if(wep->id(MAGEWEPS[s]))
			found = 1;
	if(!found)
		bonus -= (random(NONMAGE_WEAPON_PENALTY));
  }
  return bonus;
}

int gen_hp_bonus()
{
  int bonus;
  bonus -= (int)environment()->query_level() * LEVEL_HP_PENALTY;
  bonus -= (int)environment()->query_extra_level() * EXTRALEVEL_HP_PENALTY;
  return bonus;
}

int gen_sp_bonus()
{
  int bonus;
  bonus += (int)environment()->query_level() * LEVEL_SP_BONUS;
  bonus += (int)environment()->query_extra_level() * EXTRALEVEL_SP_BONUS;
  return bonus;
}
        
int display_notarmor_msg()
{
  write(
    "As a mage, you may only wear light armors.\n" +
    "You are also denied the usage of shields and helmets.\n");
  return 1;
}

drop(){ return 1; }
get(){ return 1; }

short()
{
  if(tp == environment()) return rancol2("Your magic spellbook")+" "+HIB+"["+HIY+"*"+HIB+"]"+NORM;
  else return rancol2(Me+"'s magic spellbook")+" "+HIB+"["+HIY+"*"+HIB+"]"+NORM;
}

long()
{
  write(
    "The spellbook is the "+MAG+"heart and soul"+NORM+" of a Mage.\n" +
    "This tome presents limitless power and possibilities without boundry.\n" +
    "Your knowledge of the arcane is recorded within the books thick leather\n" +
    "covers which have been careful bound with sigils of privacy and protection.\n" +
    "Type "+CYN+"mhelp"+NORM+" to uncover the books secrets.\n");
  return;
}

/* -- INIT --*/
init()
{
  string *f;
  string c;
  int x;

  if(en && en->is_player())
  {
	if(!is_loaded || is_loaded != en->query_real_name())
	{
		load_data(en->query_real_name());
    CHAND->add_channel( CHAN_NAME, en );
		tell_object(en, "Mage Soul Initialized.\n");

		if(en->query_level() < WIZLEVEL)
		{
			en->set_guild_file(GOB_FILENAME);
			en->RegisterArmor(this_object(), ({"physical",0,ARMOR_PHYSICAL_PENALTY,0}));
			call_other(en, "set_al_title", rancol2("MAGE"));
			call_other(en, "set_home", GUILD_HOME);
		}
	}

	/*
	 * add_action for commands
	 */
	x = sizeof(f = get_dir(CMD_DIR + "*.c"));
	while(x--)
	{
		sscanf(f[x], "%s.c", c);
		/* NOTE: files that start with "__" are inactive or disabled */
		if(c[0..1] == "__")
			continue;

		/* note: files that start with "_" are for players only          */
		/*       this is to avoid conflict with customer wizard commands */
		if(c[0..0] == "_")
		{
			if(en->query_level() < WIZLEVEL)
				add_action("cmd_hook", c[1..(strlen(c)-1)]);
		}
		else
			add_action("cmd_hook", c);
	}

	/*
	 * add_action for spells
	 */
	x = sizeof(f = get_dir(SPELL_DIR + "*.c"));
	while(x--)
	{
		sscanf(f[x], "%s.c", c);
		/* note: files that start with "__" are inactive or disabled */
		if(c[0..1] == "__")
			continue;

		/* note: files that start with "_" are for players only          */
		/*       this is to avoid conflict with customer wizard commands */
		if(c[0..0] == "_")
		{
			if(en->query_level() < WIZLEVEL)
				add_action("spell_hook", c);
		}
		else
			add_action("spell_hook", c);
	}

  }

  /* -= MISC COMMANDS =- */
  add_action("renew",		"renew");
  add_action("mage_quit",	"quit");
  add_action("calculate_exp",	"calcxp");
  add_action("transfer_exp",   "xferxp"); /* mizan */

}

/* -- PART OF AUTOLOAD PROCESS -- */
guild_login() {
  if(tp->query_level() < WIZLEVEL)
  {
	write(HIC);
	cat("/players/pavlik/guild/mages/helps2/news");
	write(NORM);
	call_other(tp, "set_al_title", rancol2("MAGE"));
	call_other(tp, "set_home", GUILD_HOME);
  }
  if(divd < 5 && divd != 0) divd = 50;

  if(!tp->query_invis())
  {
	if(login_msg)
    CHAND->transmit_message( CHAN_NAME, CYN+"<{"+HIC+"mage"+NORM+CYN+"}> "+NORM+tokenize(login_msg)+NORM+"\n" );
	else
    CHAND->transmit_message( CHAN_NAME, CYN+"<{"+HIC+"mage"+NORM+CYN+"}> "+
		  ME+" has entered the realms.\n"+NORM);
  }
	
  do_cmds("login", login_cmds);
}

/* -- RENEW -- */
renew() {
  object obj;
  int estat;

  if(tp->query_level() < WIZLEVEL)
  {
	call_other(tp, "set_al_title", rancol2("MAGE"));
	call_other(tp, "set_home", GUILD_HOME);
  }
  if(is_loaded && is_loaded == tp->query_real_name())
  {
	write("Saving Mage Stats ...\n");
	save_object(SAVE_DIR + tp->query_real_name());
  }
  obj = clone_object(GOB_FILENAME);
  obj->load_data(tp->query_real_name());
  move_object(obj, tp);
  write("Mage Soul renewed.\n");
  obj->set_casting(casting);
  obj->set_dragon(dragon);
  obj->set_guild_vars(guild_var);
  obj->set_guild_bonuses(guild_bonus);
  obj->set_next_castings(next_casting);
  obj->set_spell_objects(spell_objects);
  obj->set_spell_count(spell_count);
  write_file("/players/pavlik/guild/mages/log/RENEW", tp->query_name()+" renewed their gob at: "+ctime()+"\n");
  destruct(this_object());
  return 1;
}

/* -- HEART BEAT -- */
heart_beat()
{
  string c;
  int x, y;

  if(!en || !living(en)) return;

  /*
   * clear the command counter
   */
  cmd_count = 0;

  if(en->query_attack() && query_monitor())
	health_monitor(en);

  if(autosave >= AUTOSAVE_INTERVAL)
  {
	mage_autosave();
	autosave = 0 ;
  }

  autosave += 1;

  /*
   * accelerated spell point recovery
   */
  hb_count--;

  if(hb_count <= 0)
  {
	en->add_spell_point(SP_REGEN_BONUS);
	hb_count = SP_REGEN_INTERVAL;
  }

  return;

}

/* MAGE QUIT */
mage_quit()
{
  if(casting)
  {
	write("\n"+SPELL_PROMPT+" You "+HIR+"cannot "+NORM+HIC+"quit"+NORM+" while you are "+HIM+"casting"+NORM+" a spell!\n\n");
	return 1;
  }
  if(!spells || spells == "NO")
  {
	write("Bug!  No stats are being saved.\n");
  }
  else
  {
	save_object(SAVE_DIR+tp->query_real_name());
	write("Saving Mage Stats ... ok.\n");
  }

  if(logout_cmds)
	do_cmds("logout", logout_cmds);

  if(!tp->query_invis())
  {
	if(logout_msg)
    CHAND->transmit_message( CHAN_NAME, CYN+"<{"+HIC+"mage"+NORM+CYN+"}> "+NORM+tokenize(logout_msg)+NORM+"\n" );
	else
    CHAND->transmit_message( CHAN_NAME, CYN+"<{"+HIC+"mage"+NORM+CYN+"}> "+
		  ME+" has left the realms.\n"+NORM);
  }
  
  CHAND->remove_channel( CHAN_NAME, tp );

  destruct(this_object());
}

query_spendable_exp()
{
  int base, spend;
  base = ADVANCE->rank_costs(tp->query_guild_rank());
  spend = tp->query_guild_exp() - base;
  return spend;
}


no_standard()
{ 
  string junka, junkb;
  if(sscanf(object_name(env), "%spavlik/guild/mages/room%s", junka, junkb) != 2)
  { 
	write("You cannot do this here.\n");
	write("You must be in the "+HIC+"Mages Tower"+NORM+" to do this.\n"); 
	return 1; 
  } 
}


do_cmds(what, cmds)
{
  string c1, c2;
  int cont;

  if(what == "login" && query_guild_var("login_cmds") > 0)
	return 1;

  /* set flag to indicate login cmds have been processed */
  if(what == "login")
	set_guild_var("login_cmds", 1);

  if(!cmds)
  {
	write(CYN+"No "+what+" commands to execute.\n"+NORM);
	return 1;
  }

  write(CYN+"Executing "+what+" commands ... \n"+NORM);

  c2 = cmds;
  for(cont=0; cont<5; cont++)
  {
	if(sscanf(c2, "%s,%s", c1, c2)==2)
	{
		write(CYN+"executing "+what+" command: "+c1+"\n"+NORM);
		command(c1, tp);
	}
	else
	{
		write(CYN+"executing "+what+" command: "+c2+"\n"+NORM);
		command(c2, tp);
		write(CYN+capitalize(what)+" commands complete.\n"+NORM);
		return 1;
	}
  }
  return 1;
}


/*
 * rather than keep huge lists of variables and set_ and query_ functions we will
 * use a mapping to keep track of a dynamic list of guild variables, bonuses, etc...
 */

/*
 * Casting Timers
 */
void set_next_casting(string name, int value)
{
  if(!next_casting || !sizeof(next_casting)) next_casting = ([]);
  next_casting[name] = value;
}

void unset_next_casting(string name)
{
  if(!name) return;
  if(!next_casting || !sizeof(next_casting)) return;
  next_casting = m_delete(next_casting, name);
}

void query_next_casting(string name)
{
  if(!next_casting || !sizeof(next_casting)) return 0;
  if(!next_casting[name]) return 0;
  return next_casting[name];
}

set_next_castings(var) { next_casting = var; }
query_next_castings() { return next_casting; }

set_spell_count(var){ spell_count = var; }
query_spell_count(){ return spell_count; }

/*
 * Spell Objects - used to keep track of spells in effect
 */
void add_spell_object(string name, mixed obj)
{
  if(!spell_objects || !sizeof(spell_objects)) spell_objects = ([]);
  spell_objects[name] = obj;
}

void remove_spell_object(string name)
{
  if(!name) return;
  if(!spell_objects || !sizeof(spell_objects)) return;
  spell_objects = m_delete(spell_objects, name);
}

query_spell_object(string name)
{
  if(!spell_objects || !sizeof(spell_objects)) return 0;
  if(!spell_objects[name]) return 0;
  return spell_objects[name];
}

set_spell_objects(var) { spell_objects = var; }
query_spell_objects() { return spell_objects; }

/*
 * Variables, Objects, etc
 */
void set_guild_var(string name, mixed value)
{
  if(!guild_var || !sizeof(guild_var)) guild_var = ([]);
  guild_var[name] = value;
}

void unset_guild_var(string name)
{
  if(!name) return;
  if(!guild_var || !sizeof(guild_var)) return;
  guild_var = m_delete(guild_var, name);
}

mixed query_guild_var(string name)
{
  if(!guild_var || !sizeof(guild_var)) return 0;
  if(!guild_var[name]) return 0;
  return guild_var[name];
}

set_guild_vars(var) { guild_var = var; }
query_guild_vars() { return guild_var; }

/*
 * Guild Stat Bonuses
 */
int query_guild_bonus(string name)
{
  if(!guild_bonus || !sizeof(guild_bonus)) return 0;
  if(!guild_bonus[name]) return 0;
  return guild_bonus[name];
}

void add_guild_bonus(string name, int amt)
{
  if(!guild_bonus) guild_bonus = ([]);
  /** Ensure we don't call this when killing mobs with mage bonus gear **/
  if( previous_object() ) {
    if( environment( previous_object() ) )
      if( environment( previous_object() ) != en )
        return;
  }
  guild_bonus[name] += amt;
}

void remove_guild_bonus(string name, int amt)
{
  if(!guild_bonus) guild_bonus = ([]);
  /** Ensure we don't call this when killing mobs with mage bonus gear **/
  if( previous_object() ) {
    if( environment( previous_object() ) )
      if( environment( previous_object() ) != en )
        return;
  }
  guild_bonus[name] -= amt;
}

set_guild_bonuses(var) { guild_bonus = var; }
query_guild_bonuses() { return guild_bonus; }

set_dragon_hps(int x) { dragon_hps = x; }
int query_dragon_hps() { return dragon_hps; }


cmd_hook(string str)
{
  string c;
  c = CMD_DIR + query_verb() + ".c";
  if(file_size(c) <= 0)
	c = CMD_DIR + "_" + query_verb() + ".c";

  if(file_size(c) > 0)
	return (mixed) c->cmd(str);
  else
	return 0;
}

spell_hook(string str)
{
  string s;

  /* make sure we actually know this spell */
  if(!query_spell_learned(query_verb()))
	return 0;

  /* limit command stacking! */
  /* 08/08/07 Earwax: temporary til we fix the issues */
  /* 08/19/07 Fakir located the problem, and mizan fixed the code. Fakir's char tested and verified. */

  s = SPELL_DIR + query_verb() + ".c";
  if(file_size(s) <= 0)
	s = SPELL_DIR + "_" + query_verb() + ".c";

  if(file_size(s) > 0)
  {
    if( s->query_combat_spell() == 1 ) {
      if(cmd_count >= 3) {
	notify_fail("Command limit per round reached.\n");
	return 0;
      }
      cmd_count++;
    }
    spell_count[query_verb()]++;
    return (int)s->spell(str);
  }
  else
	return 0;
}

/*
 * Determine if we know a spell (for casting)
 */
query_spell_learned(string name)
{
  if(tp->query_level() > WIZLEVEL) return 1;		/* wiz */
  if(tp->query_guild_rank() > MAXGUILDRANK) return 1;	/* gc  */
  return query_spell(name);
}


int query_cmd_count_max() { return cmd_count >= 3; }
int query_cmd_count() { return cmd_count; }
/* query_cmd_count() added by mizan */

/* Used by /obj/monitor to call guild monitor */
mixed
query_guild_monitor() {
  return 0;
}

set_spell_dtype( int i ) { spell_dtype = i; }
int query_spell_dtype() { return spell_dtype; }

string query_spell_dtype_dam() {
  return (string) DTYPES[spell_dtype][0];
}

string query_spell_dtype_msg() { 
  string str;
  if( (string) DTYPES[spell_dtype][1] == "Magic" )
    str = (string) rancol2( DTYPES[spell_dtype][1]);
  else
    str = DTYPES[spell_dtype][2]+DTYPES[spell_dtype][1]+NORM;
  return str;
}

string
query_mon_spells() {
  int x;
  string msg, c;
  string *n;
  string *names;
  mapping spells;

  spells = (mapping) query_spell_objects();

  if(!spells || !sizeof(spells))
        msg = " ";
  else
  {
        n = ({});
        names = m_indices(spells);
        for(x=0; x<sizeof(names); x++)
        {
                if(!spells[names[x]]) continue;
                if(names[x] == "blind")       n += ({ "BL" });
                if(names[x] == "ffire")       n += ({ "FF" });
                if(names[x] == "eshield")     n += ({ "ES" });
                if(names[x] == "lifesteal")   n += ({ "LS" });
                if(names[x] == "stoneskin")   n += ({ "SS" });
                if(names[x] == "absorb")      n += ({ "AB" });
                if(names[x] == "augury")      n += ({ "AU" });
                if(names[x] == "gstr")        n += ({ "GS" });
                if(names[x] == "mimage")      n += ({ "MI" });
        }
        c = implode(n, "/");
        if(strlen(c) > 0)
                msg = strpad(c, " ", 15);
        else
                msg = " ";
  }
  return msg;
}

string
query_gmon1() {
  return query_mon_spells();
}

string
query_gmon2() {
  return ""+ query_dragon_hps();
}
