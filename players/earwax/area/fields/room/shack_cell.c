#include "../defs.h"

inherit ROOM;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("A Holding Cell");
  set_long("This is a a holding cell.  It's where the "+ENG+" keeps their detainees.  Well, it would be the place they'd keep their detainees if they ever had any, but all their enemies either end up dead (not very likely) or laughing at them (much more likely).  Anyway, there's a small cot in the corner, a stainless steel toilet in the corner, and a whole lot of nothing else in here.");
  add_exit("south", RPATH+"shack_entrance");
  add_desc("cot", "It's not really a cot, it's a concrete ledge.");
  add_desc("concrete ledge", "It doesn't look very comfortable.");
  add_desc("ledge", "It doesn't look very comfortable.");
  add_desc("toilet", "It's functional yet ... functional.");
  add_desc("nothing", "There's a whole lot of it.");
  add_desc("detainees", "Please reread the description to this room.  There are no detainees, nor are there likely to be any.");
}
