#include "/players/sado/guild/std.h"

inherit POTION;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_color("azure");
}

long()
{
  write("A thick azure liquid sloshes around inside the phial.\n");
  write("You remove the stopper from the phial and sniff the contents.\n");
  write("I think this potion may have gone rancid.  Been keeping it warm?\n");
}

drink()
{
  object haste;

  if(present("hastener", tp))
    {
      write("You are already sped up.  Drinking another speed potion would make\n");
      write("your heart explode, and we don't want that now, do we?\n");
      return 1;
    }

  ::drink();

  haste=co(HASTE);
  haste->set_hastee(tp);
  mo(haste,tp);
  haste->start_haste();
  destruct(this_object());
  return 1;
}
