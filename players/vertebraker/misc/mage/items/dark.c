#include "../def.h"

#define DARK "/players/vertebraker/misc/mage/items/shadow"

inherit "/players/vertebraker/closed/std/treasure";

void
reset(int arg)
{
    if(arg) return;
    set_id("dusky flask");
    set_alias("flask");
    set_short("A " + BOLD + BLK + "dusky" + NORM + " flask");
    set_long("\
A charcoal-grey liquid rolls around inside of this glass\n\
bottle.  Holding the lid down is a small puffy cork.  You\n\
could throw the flask to release the contents within.\n");
    set_value(600);
    set_weight(1);
}

void
init()
{
    ::init();
    add_action("cmd_hurl", "hurl");
    add_action("cmd_hurl", "throw");
    add_action("cmd_hurl", "toss");
    add_action("cmd_hurl", "chuck");
}

status
cmd_hurl(string str)
{
    object z, e;

    if(id(str) && (z = this_player()) && (environment() == z))
    {
      write("\
You hurl the flask down upon the ground, shattering it\n\
into a thousand pieces.\n");
      say((string)z->query_name() + " \
hurls a flask down upon the ground, shattering it.\n");
      z->add_weight(-1);
      move_object(this_object(), "/room/void");
      if(!(e = environment(z)))
      {
        destruct(this_object());
        return 1;
      }
      call_out("darken", 2, e);
      return 1;
   }
   return 0;
}

void
darken(object ob)
{
    if(ob && creator(ob) && !present("verte_dark_thing", ob))
    {
      tell_room(ob, BOLD + BLK + "A black shadow" + NORM + " \
arises from the shattered remnants of the flask.\n");
      move_object(clone_object(DARK), ob);
    }
    destruct(this_object());
}
