/* *************************************************************************
 * /players/earwax/closed/shardak/include/ghall.c
 *
 * Shardak Guildhall Inheritable
 *
 * Earwax 7/23/03
 *
 * *************************************************************************
 * 
 * This inheritable is for the Shardak Guildhall.  The hall will have a
 * few features that make it worth doing an inheritable for.  
 * Features already in noted with a '*' whereas ones to do are with '-'
 *
 * * Item Descriptions
 * - Room Spam for Intruders when not in combat
 * - Additional room spam for non-pk invaders
 * * Short shows to nonshards under level 21 as 'Grotto' everywhere
 * * Exits only show for Shards
 * - May add 1hp damage per hb or two for invaders
 * * PK area
 * * Non-teleport/non-follow (except for one room)
 *
 * *************************************************************************
 *
 * Syntax
 *
 * void on_create() {
 *   add_exit("direction","destinationfile")
 *   add_exit("direction","functiontocall");
 *   add_item("itemname","description");
 *   add_item("itemname","functiontocall");
 *   set_short("shortforshardstosee");
 *   set_long("longdesc of room");
 *   set_long("functiontocall");
 * }
 *
 * *************************************************************************
 *
 * Notes:
 *
 * Don't use 'init()' or 'reset()' or 'short()' or 'long()' with this
 * inheritable.  Instead, use on_create() for 'reset(0)' (when room is
 * created) and on_reset() when the room is reset.
 * All these will automatically detect if the arguement is a function or
 * not, if it's a function they'll call it, otherwise they will just show
 * what's there.  That's not exactly necessary (to detect if it's a function
 * or not), but it's probably better to check with this lib.
 *
 * - add 'glance' support later on
 *
 * *************************************************************************
*/

#include "ansi.h"

#define MASK RED+"The Grotto"+NORM

inherit "/room/room.c";

/* Global Variables */
mapping Exits,            /* Doing this in a mapping just to be different */
        Items;            /* Items to look at and their descriptions      */
string  Short,            /* Correct short description of the room        */
        Long;             /* Long description of the room                 */

/* *************************************************************************
 * Just setting these up for use, meant to be overidden
*/

void on_create(); void on_create() { return; }
void on_reset(); void on_reset() { return; }
void on_init(); void on_init() { return; }

/* *************************************************************************
 * reset()
 * 
 * Just set things up, the rooms will use 'on_create()' and 'on_reset()'
 * instead of reset()
*/

void
reset(status arg)
{

  if (arg) 
  {
    ::reset(arg);
    on_reset();
    return;
  }

  Exits = ([ ]);
  Items = ([ ]);
  ::reset(arg);
  set_light(1);
  on_create();    
  on_reset();
}

/* *************************************************************************
 * query_shardak_realm()
 *
 * This function is just for me.  It's just something I want in here, for
 * some things I may do later on with Shardak and some other things.
 * Not sure I'll even use it, but who cares :)
*/

string
query_realm()
{
  return "Shardak Guildhall";
}

/* *************************************************************************
 * add_exit()
 *
 * add an exit to the room, call this from on_create()
 *
 * syntax: add_exit("direction","destination");
 * syntax: add_exit("direction","functionname");
*/

void
add_exit(string dir, string dest)
{

  Exits[dir] = dest;

}

/* *************************************************************************
 * do_exit()
 * 
 * Move the player to the destination room.
 * Check for function first, if not a funciton, move them to the room.
*/

status
do_exit()
{
  
  string dir;

  dir = query_verb();

  if (function_exists(Exits[dir],this_object()))
  {
    call_other(this_object(),Exits[dir]);
    return 1;
  }

  this_player()->move_player(dir+"#"+Exits[dir]);
  return 1;
}

/* *************************************************************************
 * add_desc()
 *
 * Add an item description to the room.
 *
 * syntax: add_item("item","itemdescription");
 * syntax: add_item("item","functionname");
*/

void
add_desc(string item, string desc)
{
  Items[item] = desc;
}

/* ************************************************************************
 * add_item()
 *
 * Add an item description to the room.
*/

void add_item(string arg, string desc) {

  Items[arg] = desc;
}

/* *************************************************************************
 * show_desc()
 *
 * Show the description of an item.
 * Check for a function existing first, if not, show the description.
*/

status
show_desc(string what)
{

  if (function_exists(Items[what],this_object()))
  {
    call_other(this_object(),Items[what]);
    return 1;
  }

  write(Items[what]);
  return 1;
}

/* *************************************************************************
 * do_look()
 *
 * Override for look command.  Check the arg, see if it's in item descs,
 * if so, show it, if not, parse for 'at' and check arg.
 * If not, return 0, if so, show call show_desc()
*/

status
do_look(string arg)
{

  int light;

  light = set_light(0);

  if (!light)
  {
    write("It's too dark.\n");
    return 1;
  }

  if (!arg)
  {
    long();
    return 1;
  }

  if (member(Items,arg))
    return show_desc(arg);

  if (sscanf(arg,"at %s", arg) == 1)
    if (member(Items,arg))
      return show_desc(arg);

  return 0;
}

/* *************************************************************************
 * set_short()
 *
 * Set the correct short description for the room.
*/

void
set_short(string arg)
{

  Short = RED + arg + NORM;

}

/* *************************************************************************
 * short()
 *
 * This one is slightly more complex.
 * If it's a shard, show correct short.
 * Check for light level, if it's 1 or more, show false description.
 * If it's < 1, and they aren't present, show 'dark room' if it's < 1, and
 * they are present, check for nightvision object, if they have it, then
 * show false short, otherwise show 'dark room'
*/

string
short()
{

  int light;   /* light level                                      */
  object p;    /* flag for if player is present in the room or not */
  object ob;   /* error check, short() bugs when no this_player()  */

  if (!(ob = this_player()))
    return RED+"The Grotto"+NORM;
  
  light = set_light(0);
  p = present(ob,this_object());

  /* Room is lit, so show one of the shorts */
  if (light)
  {  
    if (present("shardak_mark",ob))
      return Short;
    else
      return MASK;
  }

  /* They aren't present, no need to check for nightvision */
  if (!p)
    return "Dark Room";

  /* They have a nightvision object */
  if (present("nightvision_object",ob))
  {
    if (present("shardak_mark",ob))
      return Short;
    else
      return MASK;
  }

  /* Should be someone present without a nightvision object at this point */
  return "Dark Room";
}

/* *************************************************************************
 * set_long()
 *
 * Set the long description for the room.
 *
 * Syntax
 * set_long("long description goes here");
 * set_long("functiontocall");
*/

void
set_long(string desc)
{
  Long = HIK + desc + NORM;
}

/* *************************************************************************
 * long_exits()
 *
 * This function takes the exits shown in Exits() and automatically puts
 * them into a line of info called by long()
 *
*/

string
long_exits()
{

  string temp;
  string *all;
  int i, siz;

  siz = sizeof(all = m_indices(Exits));
  
  temp = RED + "	Exits: ";

  if (!siz)
    return temp + "None.\n" + NORM;

  all[0] = capitalize(all[0]);
  for (i = 0; i < siz; i++) 
  {
    if (siz > 0 && (i + 1 < siz))
      temp += all[i] + ", ";
    else
      temp += all[i];
  }

  temp += ".\n" + NORM;
  return temp;
}

/* *************************************************************************
 * long()
 *
 * Long description to the room.  Checks for function first, if there's
 * one, it uses it, then adds exits in for shards.
 * Otherwise, it just shows the long description, checks if the player is
 * a Shard, and displays exits if they are one.
 *
*/

void
long()
{

  if ((int) this_player()->query_brief() != 2)
    write(short() + "\n");

  if (function_exists(Long,this_object()))
    call_other(this_object(),Long);
  else
    write(Long);

  if (present("shardak_mark",this_player()))
    write(long_exits());
}

/* *************************************************************************
 * invader_spam()
 *
 * This is the invader spam.  Every 1-10 seconds they will get a random 
 * message while still in the room.
 * Just to be a bastard :)
*/

/* lookup call_out to see if i need to pass the object or not, I need to
   make sure they are still in the guild hall.  also, do the check here
   to see if they are not pk....if they aren't, torture them with more :)
void
invader_spam(object ob)
{


  switch(random(15)) 
  {
    case 0  : bleh bleh bleh
    case 1  : bleh bleh bleh
  }
  
}
*/

/* *************************************************************************
 * init()
 *
 * The init function, in the rooms themselves, use 'on_init()' instead.
 * This function does the add_action() for all the exits as well as an
 * override on 'look'
*/

void
init()
{

  int i, siz;
  string *temp;

  add_action("do_look","look");

  siz = sizeof(temp = m_indices(Exits));

  for (i = 0; i < siz; i++)
    add_action("do_exit",temp[i]);

  /* add in the call_outs for room spam here */
  /* I have to look this up further, to see where to remove the call_out()
  if (!present("shardak_mark",this_player()))
    call_out("invader_spam", random(10));
  */ 
  on_init();
}
