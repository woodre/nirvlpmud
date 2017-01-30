/* ====================================================================
 * Earwax's Room Inheritable
 *
 * This is so Earwax can make his rooms easier.
 * ====================================================================
*/

#include "defs.h"

inherit "room/room.c"; /* I'll yank this eventually.           */
inherit WAXFUNS;       /* Misc pseudo-lib functions            */ 
/*
inherit DOOR;          /* Door code                            */


/* Globals */

string  *Full_dirs,    /* Full Direction names                 */
        *Small_dirs;   /* Direction Aliases                    */

string  *Dirs,         /* The exit directions                  */
        *Dests;        /* Destination rooms or functions       */
mapping Args;          /* Exit arguments                       */

mapping Descs;         /* Things players can look at           */

string  *mon_files;    /* File names of monsters in add_clone()*/
object  *mon_objects;  /* Monster objects for add_clone()      */

string  short_desc,    /* Short desc of room                   */
        long_desc,     /* Long desc of room                    */
        door_desc;     /* Door descriptions                    */
string color;          /* Color short desc/exits show in       */
string area;           /* Defines areas, not much use really   */


/* Prototypes */

void on_create();      /* Required in all rooms for creation   */
void on_reset();       /* add_clone(), add_door() go here      */
void on_init();        /* add_action() goes here               */
void load_mobs(status arg);

/* ********************************************************************
 * RESET
 *
 * The reset() function
 *
*/

void reset(status arg) {

  if (arg) {
    on_reset();
    load_mobs(arg);
    return;
  }

  /* Initialize Variables */
  Dirs = ({ });         Dests = ({ });    Args = ([ ]);
  Descs = ([ ]);
  door_desc = "";
  mon_objects = ({ });  mon_files = ({ });
  color = NORM;
  area = "default";


  Full_dirs = ({ "southeast", "southwest", "northwest", "northeast", 
                 "north", "south", "east", "west", "up", "down" });
  Small_dirs = ({ "se", "sw", "nw", "ne", "n", "s", "e", "w", "u", "d" });

  set_light(1); /* lit rooms are the default */

  /* Need a default description rather than '0' I think */
  long_desc = "This is an undefined room, talk to a wizard.";
  short_desc = "UNDEFINED ROOM";

  on_create();    /* Call the creation function in the room itself */
  on_reset();     /* call the reset function in room itself        */
  load_mobs(0);   /* Load mobs, items, if necessary                */
}

/* ====================================================================
 * QUERY_FUNCTION
 *
 * Return null if it's not a function, return the function if one is
 * shown.  Parses for '&' in front of the string.
 * (Add a check for function_exists() later on for further safety?)
 *
*/

string query_function(string arg) {

  if (sscanf(arg,"\&%s",arg) == 1)
    return arg;
  return "";
}

/* ********************************************************************
 * GET_SMALL, GET_FULL
 *
 * These return the abbreviated form, or full form, respectively, of
 * directions, if applicable.
 *
*/

string get_small(string dir) {
  int index;

  index = member_array(dir,Full_dirs) ;

  if (index < 0)
    return dir;

  return Small_dirs[index];
}

string get_full(string dir) {
  int index;

  index = member_array(dir,Small_dirs);

  if (index < 0)
    return dir;

  return Full_dirs[index];
}

/* ********************************************************************
 * Various query/set functions
 *
 * The little quick ones, here just to have them consolidated
 *
*/

void set_long(string arg) { long_desc = arg; }
void set_short(string arg) { short_desc = arg; }

void set_color(string arg) { color = arg; }
string query_color() { return color; }

void add_desc(string what, string desc) { Descs[what] = desc; }


string query_area() { return area; }
void set_area(string arg) {
  area = arg;
  if (area == "area")
    color = HIW;
  else
    color = NORM;
}

/* ********************************************************************
 * QUERY_DESC, SHOW_DESC 
 *
 * Show special descriptions
*/

string query_desc(string what) {
  if (Descs[what])
    return Descs[what];
  else
    return "";
}

int show_desc(string what) {
  string desc, func;

  desc = query_desc(what);
  func = query_function(desc);

  if (!strlen(func))
    write(line_wrap(desc)+"\n");
  else
    call_other(this_object(),func);

  return 1;
}

/* ********************************************************************
 * DO_LOOK
 *
 * Override look command, to see specially set descriptions
 *
*/

int do_look(string arg) {
  string target;
  int index;

  if (!arg)
    return 0;
  if (sscanf(arg, "at %s", target) != 1)
    target = arg;
  if (Descs[target])  {
    say(this_player()->query_name()+" looks at "+target+"\n",this_player());
    return show_desc(target);
  }

  index = member_array(target,Dirs);
  
  if (index < 0)
    index = member_array(get_full(target),Dirs);

  if (index < 0)
    return 0;

  say(this_player()->query_name()+" looks " + target + "\n", this_player());
  Dests[index]->long();


  return 1;
}

/* ********************************************************************
 * QUERY_DEST
 * 
 * For a given direction, return the filename of the destination
 *
*/

string query_dest(string dir) {
  int i, siz;

  siz = sizeof(Dirs);
  if (!siz)
    return "Invalid Exit";

  for (i = 0; i < siz; i++) 
    if (Dirs[i] == dir)
      return Dests[i];

  return "Not a valid exit.";
}

/* ********************************************************************
 * DO_EXIT
 *
 * Figure out the direction, destination, and then move the player
 * there.  Add silent flag later on, and other goodies.
 *
*/

int do_exit(string arg) {
  string dir, dest;

  dir = query_verb();
  dest = query_dest(dir);
  this_player()->move_player(dir+"#"+dest);
  return 1;
}

/* ====================================================================
 * ADD_EXIT, REMOVE_EXIT
 *
 * Add or remove exits
*/

void add_exit(string dir, string dest) {
  Dirs += ({ dir });
  Dests += ({ dest });
}

void remove_exit(string dir) {
  string temp;

  temp = query_dest(dir);
  Dirs = s_delete(Dirs,dir);
  Dests = s_delete(Dests,temp);
}

/* ********************************************************************
 * INIT
 *
 * This calls the on_init(), and also adds the exits in, and the
 * capability to look at special descriptions
 *
*/
void init() {
  int i, siz;

  siz = sizeof(Dirs);

  for (i = 0; i < siz; i++) {
    add_action("do_exit",Dirs[i]);
  }

  add_action("do_look","look");
  add_action("do_look","l");
  add_action("do_search","search");
  on_init();
}

/* ********************************************************************
 * SHORT_EXITS
 *
 * Returns the short form of exit directions
 *
*/

string short_exits() {
  string temp;
  int i, siz;

  siz = sizeof(Dirs);

  if (!siz)
    return "[None]";

  
  temp = " [";

  for (i = 0; i < siz; i++) {
    if (i > 0)
      temp+=",";
    
    /* Get the abbreviation for the dir */
    temp += get_small(Dirs[i]);
  }

  temp += "]";
  return temp;
}

/* ********************************************************************
 * LONG_EXITS
 *
 * returns the long form of exit directions
 *
 * Exits: No obvious exits.      (if none)
 * Exits: north, south           (north and south exits)
 *
*/

string long_exits() {
  string temp;
  int i, siz;

  siz = sizeof(Dirs);

  if (!siz)
    return "Exits: No obvious exits.";

  temp = "Exits: ";

  for (i = 0; i < siz; i++)
    if (i + 1 == siz)
      temp += Dirs[i] + ".";
    else
      temp += Dirs[i] + ", ";

  return temp;
}

/* ********************************************************************
 * LONG
 *
 * Writes long desc (not returns it, like short())
 * Uses the following format:
 *
 * short() [short_exits]
 * long description + door short descriptions (if any)
 * valid exits (exits, and open door exits)
 *
*/

void long() {
  string func;
 
  if (long_desc) {
    write(short() + "\n");
    func = query_function(long_desc);

    if (strlen(func))
      call_other(this_object(), func);
    else
      write(line_wrap(long_desc + door_desc)+"\n");      
  }
  else
    write(short()+"\n");

  write(color + long_exits()+NORM+"\n");
}

/* ********************************************************************
 * SHORT
 *
 * Returns the room's short description
 * Uses the following format:
 * 
 * short description [s,n,enter]
 *
*/

string short() {
  string func;

  if (!strlen(short_desc))
    return "UNDEFINED ROOM";

  func = query_function(short_desc);

  if (strlen(func))
    return color + (string)call_other(this_object(),func) + NORM;

  return color + short_desc + short_exits() + NORM;
}

/* ********************************************************************
 * ADD_CLONE, LOAD_MOBS
 *
 * Add a monster to be cloned every reset (if not there already)
 * Load the monsters and move them to the room
 *
*/

void add_clone(string filename) { mon_files += ({ filename }); }

void load_mobs(status arg) {
  int i, siz;

  siz = sizeof(mon_files);

  if (!siz)
    return;

  if (!arg)
    mon_objects = allocate(siz);

  for (i = 0; i < siz; i++) {
    if (!mon_objects[i]) {
      mon_objects[i] = clone_object(mon_files[i]);
      move_object(mon_objects[i],this_object());
    }
  }
}

/* ********************************************************************
 * Functions to Override
 *
 * These are meant to be overridden. 
 * They are the functions to be used to create the individual rooms.
 *
*/

void on_create() { return; }
void on_reset() { return; }
void on_init() { return; }
