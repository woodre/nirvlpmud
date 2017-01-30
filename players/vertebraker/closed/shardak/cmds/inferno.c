#include "../tasks.h"
#include "../ansi.h"
#include "../def.h"
#include "../macros.h"

#define in RED + "Inferno" + NORM

status main(string arg)
{
    if(arg)
      return 0;

    else
    {
      int cost;
      object room, me, mark, flames, Ob;
      string meep;

      mark = previous_object();
      room = environment(me = this_player());

      needtask(FLAMES_TASK);
      needrank(6);
      cost = 100 + random(75);
      needmana(cost);

/* added by Beck 09/11/02 changed spell so only pk Shardaks can call the inferno...wouldn't have changed it if players didnt abuse it. */

if(!this_player()->query_pl_k() && !this_player()->query_fight_area())
{
notify_fail("You must have PK set or be in a PK area to use this spell\n");
return 0;
}
    if(!(flames = (object)mark->query_flames()) && !(flames = present("shardak_fire", environment(this_player()))))
      {
        notify_fail("\
You must have a demonic fire raging in order to call the\n\
power of the " + in + ".\n");
        return 0;
      }

      if((status)room->WaxedOn())
      {
        notify_fail("\
The room is already coated with a Demonic " + in + ".\n");
        return 0;
      }

      if((status)room->query_limited_shadow() ||
          file_name(room)[0..3] == "room"     ||
         (status)room->query_no_fight())
      {
        notify_fail("\
There is some sort of protection around this room.\n");
        return 0;
      }

      meep = (string)me->query_name();

      switch(random(3))
      {
        case 0:
          write("You summon the power of the " + in + ".\n");
          say(meep + " summons the power of the " + in + ".\n");
          break;
        case 1:
          write("You focus the swirling heat energies of the " + 
           in + ".\n");
          say(meep + " focuses the swirling heat energies of the " +
           in + ".\n");
          break;
        case 2:
          write("You speak the ancient incantation of the " + in + ".\n");
          say(meep + " speaks an ancient incantation.\n");
          break;
      }

      tell_room(room, RED + "\
Fire bursts around the area, constricting around you.\n" + NORM);

      Ob = clone_object(OBJDIR + "exShadow");
      Ob->wax_on_daniel_san(room);

      this_player()->add_spell_point(-cost);

      flames->add_strength(-(6 + random(6)));
      return 1;
    }
}
