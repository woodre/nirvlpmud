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

void
beast_desc()
{
  write(line_wrap("There are lots of nasty things in the moat.  Leave it at that.  Trust me.\n"));
}

void
on_init()
{
  add_action("do_play", "swim");
  add_action("do_play", "play");
}

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("Before a Moat");
  set_long("Beyond a moat to the north lies a castle.  To the east and south are fields and to the west lies the end of a dirt road.");
  add_exit("south", RPATH+"fields2");
  add_exit("west", RPATH+"road3");
  add_exit("east", RPATH+"fields4");
  add_desc("castle", "You can see it from here, but it doesn't look like there's any way to get to it.  Even if you could swim across the moat, there's nothing but sheer wall on the other side, and the drawbridge is raised.");
  add_desc("drawbridge", "You can see clearly from here that it's raised.");
  add_desc("moat", "It's practically a river.  A very muddy, foul-smelling river with lots of nasty beasties in it.");
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
  if (!present("corporal", this_object()) && random(100) < CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());

  set_lot_size(3);
  set_cost(150000);
  set_realm_name("Fields");
  setup_land();
}



