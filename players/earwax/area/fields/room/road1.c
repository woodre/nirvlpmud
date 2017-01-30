#include "../defs.h"

inherit ROOM;

int
go_south(string arg)
{
  object ob;
  string t;

  write("You enter the clearing to the south and a sense of tranquility washes over you.\n");
  say((string)this_player()->query_name()+" leaves south.\n", this_player());
  move_object(this_player(), RPATH+"sanctuary");
  write((string)environment(this_player())->short()+".\n");
  ob = first_inventory(environment(this_player()));

  while(ob)
  {
    if (this_player() != ob)
      if ((t = (string)ob->short()))
        write(t+".\n");

      ob = next_inventory(ob);
  }

  return 1;
}

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("A "+HIK+"Dirt"+NORM+NORM+HIG+" Road");
  set_long("A dirt road starts here and continues to the north.  To the south, where the road ends, a grass clearing begins, and there are fields to either side of you.  Off in the distance to the north is a castle.");
  add_exit("south", RPATH+"sanctuary");
  add_exit("north", RPATH+"road2");
  add_exit("east", RPATH+"fields1");
  add_exit("west", RPATH+"fields6");
  add_desc("road", "Where it ends grass begins.  The rest of it goes off to the north somewhere.");
  add_desc("castle", "It looks like a castle, but it's hard to make out many details at this distance.");
  add_desc("clearing", "There is a grass-covered clearing south of here.");
  add_desc("fields", "There are grassy fields to the east and west.");
  add_desc("grass", "It begins where the road ends.");
  if (!present("corporal", this_object()) && random(100) < CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());
}
