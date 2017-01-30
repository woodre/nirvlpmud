#include "defs.h"

/* Global Variables */
static string Name;
int GExp;
status Muffle;
int GLevel;    /* Guild Level */
int Loan;


string query_auto_load() { return AUTOLOAD; }

void reset(status arg) {
  if (arg) return;

  Loan = GLevel = GExp = 0; Name = ""; Muffle = 0;
}

status id(string arg) {
  return ( arg == "seal" || arg == "masonic seal"
    || arg == MGOB_ID
    || arg == "base_obj" || arg == "mini-guild_object" );
}

string query_mini() { return "mini-guild_object"; }

string short() { return "Masonic Seal"; }
void long() { write("This give all the mason mini-guild commands.\n"); }
status get() { return 1; }
status drop() { return 1; }

void load_info() { restore_object(DATAPATH+Name); }
void save_info() { save_object(DATAPATH+Name); }

void init_arg(status x) { cat(NEWS); load_info(); }

void init() {
  int i;
  string *t;

  if (!environment() || environment(this_object()) != this_player())
    return;

  Name = (string)this_player()->query_real_name();
  load_info();
  i = sizeof(t = get_dir(BIN+"*.c"));

  while(i--)
#ifndef __LDMUD__ /* Rumplemintz */ 
    add_action("command_hook", t[i][0..-3]);
#else
    add_action("command_hook", t[i][0..<3]);
#endif
}

status command_hook(string arg) {
  return (int)call_other(BIN+query_verb(), "main", arg, GLevel);
}

/* Parameters: query/set funs */
void add_glevel(int i) { GLevel += i; }
void set_glevel(int i) { GLevel = i; }

void add_gexp(int i) { GExp += i; }
void set_gexp(int i) { GExp = i; }

int query_glevel() { return GLevel; }
int query_gexp() { return GExp; }

status toggle_muffle() { Muffle = (Muffle ? 0 : 1); return Muffle; }
void set_muffle() { Muffle = 1; }
void un_muffle() { Muffle = 0; }
status query_muffle() { return Muffle; }

void set_loan(int amount) { Loan = amount; }
int query_loan() { return Loan; }
