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
  return ( arg == "seal" || arg == "consistory seal"
    || arg == MGOB_ID
    || arg == "base_obj" || arg == "mini-guild_object" );
}

string query_mini() { return "mini-guild_object"; }

string short() { return "A Consistory Seal (worn)"; }
void long() {
  write("\
The seal itself is circular in shape.  Engraved in the seal\n\
is a picture of a double-headed eagle grasping a sword\n\
in its talons.  Balanced on the heads of the eagle is\n\
a pyramid with the number 20 inscribed in it, which\n\
signifies the highest level obtainable by a mortal mason.\n");
}

status get() { return 1; }
status drop() { return 1; }

void load_info() { restore_object(DATAPATH+Name); }
void save_info() { save_object(DATAPATH+Name); }

void init_arg(status x) { cat(NEWS); load_info(); }

void init() {
  int i;
  string *t;

  if(environment() && present("allymark", environment())) {
   tell_object(environment(),
  "\n\tMasonry has no place for an Ally of Shardak.\n\n");
  destruct(this_object());
  return;
  }
  if (!environment() || environment(this_object()) != this_player())
    return;

  Name = (string)this_player()->query_real_name();
  load_info();
  i = sizeof(t = get_dir(BIN+"*.c"));

  while(i--) 
#ifndef __LDMUD__
    add_action("command_hook", t[i][0..-3]);
#else
    add_action("command_hook", t[i][0..<3]);
#endif

  CHANNELD->remove_channel(CHAN, this_player());
  if (!Muffle) {
    CHANNELD->add_channel(CHAN, this_player());
    command("mtalk ON_OFF_SILENT", this_player());
  }
/*I added next 2 lines to reset players glevel back to 20 if over 20. Angel*/
  if(present(MGOB_ID, this_player())->query_glevel() >20)
    present(MGOB_ID, this_player())->set_glevel(20);
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
void ghetto_channel_fix() {
  CHANNELD->remove_channel(CHAN, this_player());
  CHANNELD->add_channel(CHAN, this_player());
}
void set_muffle(status arg)
{
  if (arg == Muffle) return;

  write("Masons channel is now "+(arg ? "off" : "on")+"\n");
  Muffle = arg;
  if (arg) CHANNELD->remove_channel(CHAN, this_player());
  else CHANNELD->add_channel(CHAN, this_player());
}

void un_muffle() { Muffle = 0; }
status query_muffle() { return Muffle; }

void set_loan(int amount) { Loan = amount; }
int query_loan() { return Loan; }