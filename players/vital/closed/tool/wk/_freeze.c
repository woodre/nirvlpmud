#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

object blob;

main(str)
{
  if(!str)
  {
    notify_fail("Freeze who?\n");
    return 0;
  }
  blob = present(str,environment(this_player()));
  tell_room(environment(this_player()),BOLD+BLK+this_player()->query_name()+" points at "+CAP(str)+".\n"+NORM);
  tell_object(blob,"You suddenly lose the ability to move.\n");
  MO(CO("/players/vertebraker/obj/petrify"),blob);
  call_out("call",3);
  return 1;
}

call()
{
  x+= 1;
  if(blob && environment(blob))
  {
    if(x == 1)
    {
      tell_room(environment(blob),BOLD+BLK+blob->query_name()+"'s legs turn to stone!\n"+NORM);
      present("petrify_obj",blob)->set_petrify(1);
      call_out("call",3);
      return 1;
    }
    if(x == 2)
    {
      tell_room(environment(blob),BOLD+BLK+blob->query_name()+"'s torso turns into a hard chunk of rock!\n"+NORM);
      present("petrify_obj",blob)->set_petrify(2);
      call_out("call",3);
      return 1;
    }
    if(x == 3)
    {
      tell_room(environment(blob),BOLD+BLK+blob->query_name()+" turns ENTIRELY to STONE!\n"+NORM);
      present("petrify_obj",blob)->set_petrify(3);
      x = 0;
      return 1;
    }
  }
  return 1;
}

get_help()
{
  string help;
  help = "Freeze a player";
  return help;
}
