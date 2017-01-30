#include <ansi.h>

/* Global Variables */
object Here;

void reset(status arg)
{
  object here;

  Here = environment();
  if (!arg) call_out("end_cloud", 10, Here);
}

void init()
{
  if ((int)this_player()->query_level() > 19)
  {
    write("Players are in a 10 second xverb() stun here.\n");
    return;
  }

#ifndef __LDMUD__
  add_action("block"); add_xverb("");
#else
  add_action("block", "", 3);
#endif
}

status block(string arg)
{
  write("The inky substance surrounding you is clouding your mind!\n");
  return 1;
}

void end_cloud(object here)
{
  object ob;

  ob = environment(this_object());
  if (!ob) return;
  tell_room(ob, BOLD+"The inky substance surrounding you dissipates.\n"+NORM);
  destruct(this_object());
}
