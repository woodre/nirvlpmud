/* ******************************************************************************
 * Garter Object
 * 
 * - Earwax 12/09/03
 *
 * ******************************************************************************
*/

#include "../defs.h"

inherit WAXFUNS;

/* Global Variables */
string *Commands;
object Owner;
status Muffled;


status
do_it(string arg)
{
  return (status)(BIN_DIR+query_verb())->main(arg);
}

void
init()
{
  int i;

  if (!Owner)
  {
    if (environment(this_object()) != this_player())
      return;

    Owner = this_player();
  }

  if (Owner != this_player())
    return;

  i = sizeof(Commands = (string*)COMMANDSD->get_commands());

  while(i--)
    add_action("do_it", Commands[i]);
}

void
reset(status arg)
{
  Commands = ({ });
}

string
extra_look()
{
return (BOLD+BLU+Owner->query_name()+" has a "+RED+"Girls Gone Wild"+NORM+BOLD+BLU+" Tattoo on the small of "+Owner->query_possessive()+" back"+NORM+NORM);
}

void
long()
{
  write(extra_look()+".\n");
  write(line_wrap("This is a sexy tattoo showing that you belong to an illustrious group of women that shed their clothes in public for the benefit of a paid viewing audience.  They get butt-naked, dance on tables and generally display themselves in ways that their parents just simply wouldn't understand.  They do all that for glass beads.\n"));
}

status id(string arg) { return (arg == "tattoo" || arg == OBJECT_ID);}

status drop() { return 1; }
status get() { return 1; }
int query_value() { return 0; }
int query_weight() { return 0; }
string query_auto_load() { return LOADER; }

/* Muffled 0 == they can see the channel, 1 means they can't. */
status query_muffled() { return Muffled; }
status toggle_muffled() { Muffled = ( Muffled ? 0 : 1); return Muffled; }
status set_muffle() { Muffled = 1; }
status set_unmuffle() { Muffled = 0; }

