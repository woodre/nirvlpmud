/* *************************************************************************
 * /open/earwax/examples/guild/obj/gob.c
 *
 * Sample Guild Object
 *
 * - Earwax 12/26/03
 *
 * Keep this as small as possible.
 *
 * *************************************************************************
*/

#pragma weak_types

/* Global Variables */
static   object    Owner;        /* Who the gob belongs to                */
static   string    Name;         /* real_name of the owner                */
static   string   *Commands;     /* all commands they can use             */
         status    Muffled;      /* channel muffled or not                */

#include "../defs.h"

inherit WAXFUNS;

/* Prototypes */
status save_info();

/* ******
 * temporary debug
 *
*/
void tell_wax(string info) {
  object ob;

  if (ob = find_player("jareel")) tell_object(ob,info);
}


/* *************************************************************************
 * Query/set functions
 *
*/

void set_muffle(status flag)             { Muffled = flag;    }
void toggle_muffle()          { Muffled = ( Muffled ? 1 : 0); }
status query_muffle()         { return Muffled; }

/* *************************************************************************
 * Reset, load_info, save_info
 *
*/

void
reset(status arg)
{

  if (arg)
    return;

  return;
}

status
load_info()
{
  if (file_size(SAVEPATH+Name) < 0)
  {
    Muffled = 0;
    return 1;
  }

  restore_object("/"+SAVEPATH+Name);
  return 1;
}

status
save_info()
{
  string fname;
  fname = SAVEPATH+Name;
  save_object(fname);

  return 1;
}

/* *************************************************************************
 * Item setup functions
 *
*/

status get() { return 1; }
status drop() { return 1; }
int query_weight() { return 0; }
int query_value() { return 0; }

string query_auto_load() { return AUTOLOAD; }

status 
id(string arg)
{ 

  return ( 
    arg == GOB_ID ||
    arg == "guild_object_jareel"
  );
}

string 
extra_look()
{
  return NORM+"A member of the order of the "+RED+"Crimson Bat"+NORM+NORM;
}

long()
{
  write("This will need a help list of sorts.\n");
}

/* *************************************************************************
 * command_hook
 *
*/

int
command_hook(string arg)
{
  return (int)(BINDIR+query_verb())->main(arg);
}

/* *************************************************************************
 * init
 *
*/

void
init()
{
  int i;

  if (environment() != this_player())
    return;

  if (Owner)
    return;

  Owner = this_player();
  Name = (string) Owner->query_real_name();
  load_info();

  i = sizeof(Commands = (string *)COMMANDSD->get_commands());
  while (i--) add_action("command_hook",Commands[i]);
}
