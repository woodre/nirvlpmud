inherit "/obj/treasure.c";
#include <ansi.h>;
#define COST 10000

reset (arg)
{
  set_id("skull");
  set_short("An "+MAG+"A"+HIK+"lien"+NORM+"'s skull");
  set_long("This is the skull of the alien drone you recently killed.\n"+
		   "It can be transformed into a dangerous weapon if taken to\n"+
		   "the right person of skill.\n");
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
  if(arg != "skull")
  {
    write("You can't transform that!\n");
    return 1;
  }
  if(!present("smith_7845", environment(environment(this_object()))))
  {
    write("The Smith of Darkness is not here.\n");
    return 1;
  }
  if(this_player()->query_money() < COST)
  {
    write("The Dark Smithy tells you, \"Come back when you have 10,000.\"\n");
    return 1;
  }
  write("The Smith removes some of the gooey mess from the skull and hands you your new shield.\n");
  this_player()->add_money(-COST);
  move_object(clone_object("/players/chip/armor/movies/alien_skull_shield.c"), this_player());
  destruct(this_object());
  return 1;
}
