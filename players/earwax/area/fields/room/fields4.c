#include "../defs.h"

inherit LAND;
inherit ROOM;

status
do_play(string arg)
{

  if (member_array(arg, ({ "in the moat", "moat", "river", "in river", "in the river", "in moat", "in water" })) > -1)
    notify_fail(line_wrap("You suddenly, for no reason, decide not to go near the moat.  Actually, there's a very good reason: it's filled with pirahnas, sharks, leeches, jellyfish, and other assorted nasty things.  Earwax is obviously a very powerful wizard to have all those salt-water animals thriving in a freshwater environment!  Not only that, but although the moat is filled primarily with predators, they aren't attacking each other.  You think it might be best to stay on Earwax's good side.\n"));
  else
    notify_fail(capitalize(query_verb()) + " where?\n");
  return 0;
}

int
do_search(string arg) 
{
  if (arg == "vegetation" || arg == "dense vegetation")
  {
    write("You think you might be able to go "+HIW+"east"+NORM+NORM+" through the vegetation.\n");
    return 1;
  }

  return on_search(arg);
}

void
beast_desc()
{
  write(line_wrap("There are lots of nasty things in the moat.  Leave it at that.  Trust me.\n"));
}

int
go_east(string arg)
{
  write("You push into the vegetation, and come out in a large cave.\n");
  say((string)this_player()->query_name()+" disappears into the vegetation to the east.\n", this_player());
  move_object(this_player(), RPATH+"cave");
  this_player()->look(0);
  return 1;
}

void
on_init()
{
  add_action("do_play", "swim");
  add_action("do_play", "play");
  add_action("go_east", "east");
  add_action("go_east", "e");
}

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("Before a Moat");
  set_long("Grass ends where a moat to the north begins.  East a sheer cliff lies beyond some dense vegetation, and south and west lie grassy fields.");
  add_exit("south", RPATH+"fields3");
  add_exit("west", RPATH+"fields5");
  add_desc("castle", "There's a castle beyond the moat, but there is no way to get to it from here.");
  add_desc("moat", "It's practically a river.  A very muddy, foul-smelling river, with lots of nasty beasties in it.");
  add_desc("beasties", "&beast_desc");
  add_desc("moat-monsters", "You don't see any, but that doesn't mean they aren't in there...or does it?");
  add_desc("fields", "You might be getting sick of wide, open fields by now, but it doesn't change anything; they're still there.");
  add_desc("pirahnas", "&beast_desc");
  add_desc("sharks", "&beast_desc");
  add_desc("leeches", "&beast_desc");
  add_desc("jellyfish", "&beast_desc");
  add_desc("nasty things", "&beast_desc");
  add_desc("assorted nasty things", "&beast_desc");
  add_desc("things", "&beast_desc");
  add_desc("cliff-face", "It's obviously unclimbable.  It's as sheer as glass.");
  add_desc("cliff", "It's obviously unclimbable.");
  add_desc("vegetation", "At first glance, it seems impenetrable, but perhaps not...");
  add_desc("grass", "It's thick.");
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("corporal", this_object()) && random(100) < CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());

  set_lot_size(2);
  set_cost(100000);
  set_realm_name("Fields");
  setup_land();
}



