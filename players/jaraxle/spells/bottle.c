#define SHIELD "/players/jaraxle/spells/shield"

#include "/players/vertebraker/ansi.h"

inherit "/obj/treasure";

void
reset(status arg)
{
    if(arg) return;

    set_id("bottle");
    set_short("A bottle");
    set_long("\
A bottle.  On the side you can read \"Defense\".\n\
You can drink it.\n");
}

void
init()
{
    ::init();
    add_action("cmd_drink", "drink");
}

status
cmd_drink(string arg)
{
    object x;
    string n;

    if(!arg)
    {
      notify_fail("Drink what?\n");
      return 0;
    }

    if(id(arg))
    {
      write("\
You drink from the bottle.\n");
      say((n = (string)(x = this_player())->query_name()) + " \
drinks from a bottle.\n");

      if(!present("magi@shield", x))
      {
        write(HIW + "\
\tA magic shield flashes into sight around you!\n" + NORM);
        say(HIW + "\
A magic shield flashes around " + n + ".\n" + NORM);
        move_object(clone_object(SHIELD), x);
      }

      else
        write("Nothing happens.\n");

      write("You shatter the bottle against the ground.\n");
      say(n + " shatters the bottle against the ground.\n");

      destruct(this_object());

      return 1;
    }

    notify_fail("You may 'drink bottle'.\n");
    return 0;
}
