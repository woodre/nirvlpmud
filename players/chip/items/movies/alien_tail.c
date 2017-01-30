inherit "/obj/treasure.c";
#include <ansi.h>
#define COST 10000

reset (arg)
{
  set_id("tail");
  set_short("An "+MAG+"A"+HIK+"lien"+NORM+"'s tail");
  set_long("This is the tail of the alien drone you recently killed.\n"+
		   "It can be transformed into a dangerous weapon if taken to\n"+
		   "the right person.\n");
}

init()
{
  ::init();
  add_action("transform","transform");
}


transform(arg)
{
  if(!arg)
  {
    write("Transform what?\n");
    return 1;
  }
  if(arg != "tail")
  {
    write("You can't transform that!\n");
    return 1;
  }
  if(!present("darkbeard", environment(environment(this_object()))))
  {
    write("Darkbeard is not here.\n");
    return 1;
  }
  if(this_player()->query_money() < COST)
  {
    write("Darkbeard tells you, \"Come back when you got 10,000.\"\n");
    return 1;
  }
  write("Darkbeard transforms the tail into a deadly whip, for a fee.\n");
  this_player()->add_money(-COST);
  move_object(clone_object("/players/chip/weps/movies/alien_tail_spike.c"), this_player());
  destruct(this_object());
  return 1;
}
