#include "/players/softly/closed/ansi.h"
inherit "/obj/treasure";

#define LUCKY "/players/softly/algiers/obj/luck"

reset(arg)
{
  if(arg) return;

  set_id("lucky root");
  set_short("Lucky Hand Root");
  set_alias("root");
  set_long("\A very small piece of pungent root.  The flesh\n\
is moist pale yellowish white covered with flakes\n\
of grey-brown bark.  The bark is peeling off.  For\n\
luck 'chew' the root.\n");
  set_weight(1);
  set_value(1500);

}

init() 
{ 
  ::init(); 
    add_action("cmd_eat", "eat");
    add_action("cmd_eat", "chew");
    add_action("cmd_eat", "bite");
    add_action("cmd_eat", "nibble");
}

status
cmd_eat(string str)
{
    int luck;
    object ob;

    if(!str) return 0;

    if(id(str))
    {
      write("You nibble the entire root.\n\
You feel a clutch in your throat.\n");
      say((string)this_player()->query_name() + " \eats a piece of an ugly root.\n");

        /* if an object is not already there ... */
      if(!present("50ft_root", this_player()))
      {
        write("A flash of bright green suddenly appears before\n\
your eyes.  As it disappears, you feel luckier.\n");
        /* get the current luck value */
        luck = (int)this_player()->query_attrib("luc");
        /* set luck + 3 */
        this_player()->set_attrib("luc", (luck + 3));
        /* clone the path LUCKY */
        ob = clone_object(LUCKY);
        /* set the variable old_luck in ob to old_luck */
        ob->set_old_luck(luck);
        /* move it to the player */
        move_object(ob, this_player());
      }
      
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
    return 0;
}

query_save_flag() 
{ 
  return 1; 
}

get() { return 1; }

