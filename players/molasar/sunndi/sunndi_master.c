
/*
 * Sunndi Master Control Object
 *
 */

#include "/players/molasar/sunndi/include/log.h"

#define DATADIR "players/molasar/sunndi/data/"
#define DATAFILE "sunndi"
#define LOGFILE "sunndi_master.log"

#define DEFAULT_PLAYER_ALIGNMENT 10

int alignment;
int debug;

void log_data(string logfile, string message);
int set_alignment(int align);
void add_alignment(int align);
int query_alignment();
int save_me();
int query_player_alignment(string who);
void add_player_alignment(string who, int align);
void set_player_alignment(string who, int align);
int query_debug();
void toggle_debug();

static mapping player_alignment;
mixed saved_player_alignment;

void reset(int arg) {
   if (arg)
     return;

   player_alignment = ([]);
   if (!restore_object(DATADIR + DATAFILE)) {
      log_data(LOGFILE, "Unable to restore data from " + DATADIR + DATAFILE);
   } else {
      player_alignment = reconstruct_mapping(saved_player_alignment);
      log_data(LOGFILE, "Data restored from " + DATADIR + DATAFILE + ".o");
   }

}

int set_alignment(int align) {
   alignment = align;

   log_data(LOGFILE, "Alignment set to " + align);
   save_me();
   return 1;
}

void add_alignment(int align) {
   alignment += align;
   save_me();
}

int query_alignment() {
   return alignment;
}

int save_me() {
   saved_player_alignment = deconstruct_mapping(player_alignment);
   save_object(DATADIR + DATAFILE);
   return 1;
}

int query_player_alignment(string who) {
   string name;

   /* who = lower_case(who); */
   if (!who || !sscanf(who, "%s", name))
     return 0;

   if (!member(player_alignment, name)) {
      player_alignment[name] = DEFAULT_PLAYER_ALIGNMENT;
      save_me(); 
   }

   return player_alignment[name];

}

void add_player_alignment(string who, int align) {
   string name;

   log_data(LOGFILE, "add_player_alignment() name: " + who + " alignment: " + align);

   if (!who || !sscanf(who, "%s", name))
     return;

   name = lower_case(name);
   log_data(LOGFILE, "add_player_alignment() name: " + name + " alignment: " + align);

   if (!member(player_alignment, name)) 
      player_alignment[name] = DEFAULT_PLAYER_ALIGNMENT + align;
   else 
      player_alignment[name] += align;

   save_me();

}

void set_player_alignment(string who, int align) {
   string name;

   log_data(LOGFILE, "set_player_alignment() name: " + who + " alignment: " + align);

   if (!who || !sscanf(who, "%s", name))
     return;

   name = lower_case(name);
   log_data(LOGFILE, "set_player_alignment() name: " + name + " alignment: " + align);

   player_alignment[name] = align;

   save_me();

}

int query_debug() {
   return debug;
}

void toggle_debug() {
   debug = !debug;
   save_me();
}

