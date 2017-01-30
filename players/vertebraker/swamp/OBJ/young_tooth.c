#include "../define.h"
inherit WEAPON;
reset(arg) {
   if(arg) return;
   set_name("tooth");
   set_alias("gator tooth");
   set_short("A small gator tooth");
   set_long( "\
A sharpened, deadly looking gator's tooth that you could sell\n\
to a merchant if you find the correct one.  Its sharp edge makes\n\
it a formidable weapon as well.  You can 'string' it upon a gator\n\
tooth necklace if you have one.\n");
   set_class(13);
   set_type("knife");
   set_weight(1);
   set_value(900+random(100));
}

status
id(string str)
{
    if(::id(str)) return 1;
    if(str == "small gator tooth") return 1;
}

void
init()
{
    ::init();
    add_action("cmd_string", "string");
}

status
cmd_string(string str)
{
    object x;
    if(!str) return 0;

    if(id(str))
    {
      if(!(x = present("gator tooth necklace", this_player())))
      {
        notify_fail("You don't have a necklace to string the tooth upon.\n");
        return 0;
      }
      if(creator(x) != "vertebraker")
      {
        notify_fail("That just won't work.\n");
        return 0;
      }
      write("You string the young gator tooth upon your necklace.\n");
      say((string)this_player()->query_name() + " strings an young gator tooth upon " + possessive(this_player()) + " necklace.\n");
      this_player()->add_weight(-1);
      x->add_tooth(1);
      destruct(this_object());
      return 1;
    }
}
