#include "../defs.h"

inherit ROOM;

void
on_create()
{

  set_color(HIG);
  set_no_clean(0);
  set_short("Berthing Area");
  set_long("This is the berthing area (living quarters for the civilians out there) for the "+ENG+" Special Beano Control Detachment.  There are a number of bunks here and not much else, other than a few signs posted on the walls.  It smells bad, too - like feet mixed with unwashed genitals and simmered over a slow chicken and donkey dung fire.  Actually, it smells like that, but worse.");
  add_exit("north", RPATH+"shack_entrance");
  add_desc("bunks", "They don't look very comfortable.");
  add_desc("signs", "There are a number of them: 'The only good beano is a dead beano,' 'Down with Mizan!,' 'Employees must wash hands after using the restroom.' and of course the infamous ENGSBCD slogan, 'Beanos wanted: Fried or Alive!'");
  add_desc("walls", "Well, the walls aren't very interesting, but the signs might be.");
}

void
on_reset()
{
  int i, count;
  object ob;

  count = 3;

  if (present("private", this_object())) count--;
  if (present("private 2", this_object())) count--;
  if (present("private 3", this_object())) count--;

  for (i = 0; i < count; i++)
  {
    ob = (object)MOB_SETUP->make_pvt();
    move_object(ob, this_object());
    say((string)ob->query_name()+" arrives.\n");
  }
}
