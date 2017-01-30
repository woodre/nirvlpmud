#include "/players/sado/defines.h"
get() { return 1; }
id(str) { return str == "skullcap"; }
short() { return "A cast iron skullcap"; }
long() { write("More of a steel plate that covers the forehead really.\n"); }
butt(str)
{
   object t;
   t = present(str,env(tp));
   if(!t) return 0;
   if(!t->is_player()) return 0;
   write("You crack your head down across " + t->query_name() + "'s nose.\n");
write("It errupts in blood.  " + t->query_name() + " screams in pain!\n");
   say(tp->query_name()+" cracks their head down across the nose of " + t->query_name() + "\n",t);
   say("which errupts in blood.  " + t->query_name() + " squeals in pain!\n",t);
   tell_object(t,tp->query_name()+" cracks their head down across your nose, which bleeds all over your lips and chin.\n");
   tell_object(t,"You scream in agony and clutch your nose.\n");
   return 1;
}
init() { add_action("butt","butt"); }
