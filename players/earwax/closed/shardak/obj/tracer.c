#define TRACER_DAEMON "/players/earwax/closed/shardak/obj/tracer_daemon"
#include "../include/ansi.h"

int beats, flag;
object ob, hunter;

status
id(string str)
{
    return (str == "54a2dakt2ac32");
}

void
reset(status arg)
{
    if(arg) return;

    call_out("fake_beat", 2);
}

/*
 * This spell's effect lasts for 60 seconds, but it only does damage
 * once per monster, regardless of how many times it is cast,
 * and it only damages them the first time they flee from combat.
 */

void
fake_beat()
{
    object att, e, ee;

    while(remove_call_out("fake_beat") != -1);
    if(!(e = environment())) return destruct(this_object());

    if(beats++ >= 30)  /* 60 second delay */
    {
      if(environment(e))
      {
        tell_room(environment(e), (string)e->query_name() + " exhales.\n", ({ e }));
        tell_object(e, "Your dark fears vanish.\n");
      }
      destruct(this_object());
      return;
    }

    /*
     * Ok, let's check if someone has recently ran us.
     * And that better not be ourselves.
     */
    if((hunter = (object)e->query_hunter()) && (hunter != e))
    {
      tell_object(e, "\tYour " + BOLD + BLK + 
       "dark fears" + NORM + " lash out at you!\n");
      /*
       * Now let's check the daemon's mapping to make
       * sure this spell has not been cast on us before.
       */
      if(!TRACER_DAEMON->query_creat(e))
      {
        /* Now do the damage, one-time mind you. */
        e->hit_player(30 + random(30), "other|dark");
        /* And add our unique object to the daemon's mapping */
        TRACER_DAEMON->add_creat(e);
      }
      /* and poof! gone */
      return destruct(this_object());
    }

    call_out("fake_beat", 2);
}

status
drop()
{
    return 1;
}

void
extra_look()
{
    object a, b;

    if((a = this_player()) && (b = environment()))
    {
      if(a == b)
        write(BOLD + BLK + "You are dominated by your fears.\n" + NORM);
      else
        write(BOLD + BLK + (string)b->query_name() + " is dominated by " + 
                possessive(b) + " fears.\n" + NORM);
    }
}
