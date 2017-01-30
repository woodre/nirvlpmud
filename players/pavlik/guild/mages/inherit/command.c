#include "/players/pavlik/guild/mages/defs.h"

string verb;			/* command */
string name;			/* spell name */
string color_name;		/* colorized spell name */
int level;			/* spell level */
int rank;			/* spell rank (for commands */
string school;			/* school of magic */
int sp_cost;			/* spell point cost */
string cost_string;		/* displayable spell cost */
int delay;			/* casting delay */
string type;			/* spell type */
string component_id;		/* spell component id */
string component_string;	/* displayable spell component */
int combat_spell;		/* flag for combat checks */
string descrip;			/* spell description */

void set_verb(string str){ verb = str; }
string query_verb(){ return verb; }

void set_name(string str){ name = str; }
string query_name(){ return name; }

void set_color_name(string str){ color_name = str; }
string query_color_name(){ return color_name; }

void set_level(int i){ level = i; }
int query_level(){ return level; }

void set_rank(int i){ rank = i; }
int query_rank(){ return rank; }

void set_school(string str){ school = str; }
string query_school(){ return school; }

void set_sp_cost(int i){ sp_cost = i; }
int query_sp_cost(){ return sp_cost; }

void set_cost_string(string str){ cost_string = str; }
string query_cost_string(){ return cost_string; }

void set_delay(int i){ delay = i; }
int query_delay(){ return delay; }

void set_type(string str){ type = str; }
string query_type(){ return type; }

void set_component_id(string str){ component_id = str; }
string query_component_id(){ return component_id; }

void set_component_string(string str) { component_string = str; }
string query_component_string(){ return component_string; }

void set_combat_spell(int i){ combat_spell = i; }
int query_combat_spell(){ return combat_spell; }

void set_descrip(string str){ descrip = str; }
string query_descrip(){ return descrip; }


/*
 * Check Various Legalities of Spell Casting
 */
check_sp()
{
  if(tp->query_ghost())
  {
        write("You cannot cast spells while your dead!\n");
        return 0;
  }

  if(tp->query_sp() < MIN_SP)
  {
	write("You are too weak to cast this spell.\n");
        return 0;
  }

  if(present("mageobj", tp)->query_casting())
  {
	write("You are already casting a spell.\n");
        return 0;
  }

  /* OK */
  return 1;
}

is_gc() {
  return this_player()->query_guild_rank() >= 71;
}
