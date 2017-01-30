#include "../defs.h"

inherit "/obj/weapon.c";

/* Globals */
string Name; /* Who it belongs to. */


void
reset(status arg)
{
  if (arg)
    return;

  if (this_player())
    Name = capitalize((string)this_player()->query_real_name());

  set_name(HIR+"I-Vibe Rabbit"+NORM+NORM);
  set_short(HIR+ (Name ? Name+"'s" : "An") + " I-Vibe Rabbit"+NORM+NORM);
  set_long("\
This is a small, clublike object, strawberry-colored, made from \n\
some type of soft textured plastic.  It's about a foot in length, \n\
and has a studded band around it in roughly the center, and a \n\
small prong jutting out near the base.  There is a small tag \n\
hanging from the base.  You may 'read ivibe' to find out what it \n\
says.\n");
  set_type("club");
  set_class(3);
}

string short() { return HIR+(Name ? Name+"'s" : "An") + " I-Vibe Rabbit"+NORM+NORM; }
string set_owner(string arg) {
  if (!arg) return "Not Set";
  Name = capitalize(arg);
  return short();
}

string query_my_name() { return "ivibe"; }
string query_cost() { return "1000"; }
string query_desc() { return "The I-Vibe Rabbit"; }

status id(string arg) { return ( ::id(arg) ? 1 : (arg == "club" || arg == "ivibe" || arg == "vibrator" || arg == "sex toy" || arg == "ivibe rabbit" || arg == "i-vibe rabbit" || arg == "rabbit" || arg == "i-vibe" || arg == "club") );
}

void init() {
  if (!Name) Name = capitalize((string)this_player()->query_real_name());

  ::init();
  add_action("read","read");
}

status read(string arg) {

  if (arg == "tag" || arg == "base" || id(arg))
  {
    write("The Ivibe Rabbit vibrator has a clitoral stimulator that gently\n");
    write("vibrates while the head rotates and pleasure pearls swirl. The head \n");
    write("on the Ivibe Rabbit vibrator pivots right to left and front to back. \n");
    write("The IVibe Rabbit Vibrator has three different pleasure modes and \n");
    write("sensitive independent controls of the shaft movement and the \n");
    write("vibrations. The IVibe Rabbit Vibrator is 10 inches in total length\n"); 
    write("with 5.5 insertable inches. 3 inch clit stimulator. The shaft of the \n");
    write("IVibe Rabbit Vibrator is 1.25 inches wide and 4.5 inches in \n");
    write("circumference. Requires 4 AA Batteries (included).\n");
    write("The I-Vibe Rabbit is manufactured by Doc Johnson.\n");
    return 1;
  }

  return 0;
}
