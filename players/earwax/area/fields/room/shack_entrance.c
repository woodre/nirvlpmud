#include "../defs.h"

inherit ROOM;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("Inside a Guard Shack");
  set_long("A banner on one wall proclaims this to be the "+ENG+" Special Beano Control Detachment's command center.  This room serves as a reception area as well as an office, as evidenced by a desk covered in papers here.  A doorway to the north leads into a holding cell, another to the east is marked 'CO's Office,' and to the south is the guard berthing area.");
  add_exit("out", RPATH+"by_shack");
  add_exit("south", RPATH+"shack_equarters");
  add_exit("north", RPATH+"shack_cell");
  add_exit("east", RPATH+"shack_office");
  add_desc("lights", "They're blinking, turning on, turning off, and turning different colors.  Too bad you're not on mushrooms or acid, it could be enlightening.");
  add_desc("desk", "It's pretty well covered in papers and cleaning gear.");
  add_desc("cleaning gear", "Weapons cleaning gear.  CLP (cleaner/lubricant/protectant), brushes, patches, and cleaning-rods are what it consists of.");
  add_desc("papers", "It would be the epitome of rudeness to go through someone else's papers.  Besides, they look like military papers (and therefore very dull and written in nonsensical language), so you don't bother disturbing them.");
  add_desc("doorway", "Doorways - there are two.");
  add_desc("doorways", "Yup, it's a plural.  Go east or north to see what's through them.");
  add_desc("CLP", "It's the standard gun-oil.");
  add_desc("brushes", "Wire and nylon brushes designed for cleaning weapons with.");
  add_desc("patches", "You run them through the barrel of a weapon to get rid of carbon residue and excess lubricant.");
  add_desc("cleaning-rods", "You use these to pull patches through the barrel of a weapon.");
  add_desc("gear", "Try looking at 'cleaning gear' instead.");
  add_desc("cleaning-gear", "Somehow you think you should look at the 'cleaning gear' instead.");
}

void
on_reset()
{
  object ob;

  if (!present("sergeant", this_object()))
  {
    ob = (object)MOB_SETUP->make_sgt();
    move_object(ob, this_object());
    say((string)ob->query_name()+" arrives.\n");
  }
}
