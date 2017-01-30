#include "../ansi.h"
#include "../def.h"

#include <security.h>

#define e (BOLD + BLK + "Evil" + NORM)

string pick_msg(int Evil, string x)
{
      string msg;

      switch(Evil)
      {
        case -300000000..-4800:
          msg = "The ultimate " + e + " has infested " + x + ".\n";
          break;
        case -4799..-3600:
          msg = "You feel the " + e + " crackle around " + x + ".\n";
          break;
        case -3599..-3000:
          msg = "The " + e + " swirls around " + x + ".\n";
          break;
        case -2999..-2000:
          msg = "You can greatly sense the presence of the dark gods.\n";
          break;
        case -1999..-1000:
          msg = e + " is at work around " + x + ".\n";
          break;
        case -999..-666:
          msg = "You feel that " + e + " has penetrated " + x + ".\n";
          break;
        case -665..-333:
          msg = "You feel a touch of " + e + " around " + x + ".\n";
          break;
        case -332..-1:
          msg = "You barely sense " + e + " around " + x + ".\n";
          break;
        default:
          msg = "You don't sense any " + e + " around " + x + ".\n";
          break;
      }

      return msg;
}


status
main(string arg)
{
    object ob;
    if(!arg)
    {
      int       Evil;
      string    msg;

      ob = first_inventory(environment(this_player()));
      while(ob)
      {
        object oc;
        oc = next_inventory(ob);
        if(!ob->is_player() || ((int)ob->query_level() < APPRENTICE))
          Evil += (int)ob->query_alignment();
        ob = oc;
      }

      msg = pick_msg(Evil, "this place");

      if(present("holy_blast", environment(this_player())))
        msg = "You sense " + HIW + "holy energy" + NORM + " at work...\n";

      write(msg);
      say((string)this_player()->query_name() + " lifts " +
        possessive(this_player()) + " head up briefly.\n");
      return 1;
    }
    
    else
    {
      if(!(ob = present(arg, environment(this_player()))) ||
         !ob->short())
        return (notify_fail("You don't see " + capitalize(arg) + " around you.\n"), 0);
      write(pick_msg((int)ob->query_alignment(), ((ob == this_player()) ?
         "you" : ((string)ob->query_gender_string() == "male" ? "him" : "her"))) + "\n");
      return 1;
    }
}
