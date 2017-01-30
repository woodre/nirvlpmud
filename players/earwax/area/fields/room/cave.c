#include "../defs.h"

inherit ROOM;

void
on_init()
{
  say((string)this_player()->query_name()+" parts the vegetation outside and enters the cave.\n", this_player());
}
void
on_create()
{
  set_color(HIK);
  set_no_clean(0);
  set_short("A Small Cave");
  set_long("This cave was carved out of the cliff face extending above the valley outside.  There are signs of habitation here, mainly in the form of a small campfire and a pallet in one corner of the cave.");
  add_exit("out", RPATH+"fields4");
  add_desc("campfire", "The campfire is starting to putter out.");
  add_desc("fire", "The campfire is starting to die out.");
  add_desc("pallet", "A small bed made from leaves and covered with a wool blanket comprise the pallet.  It doesn't look very comfortable, but it apparently serves its function.");
  add_desc("signs", "Signs in the figurative, not literal sense.  There is nothing to read here.");
  add_desc("corner", "In one corner of the cave lies a small pallet used as a bed.");
  add_desc("bed", "A make-shift pallet comprised of leaves and a wool blanket.");
  add_desc("leaves", "The leaves are green, indicating that they are probably changed very regularly.");
  add_desc("blanket", "It's a scratchy wool blanket.");
}
