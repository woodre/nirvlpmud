#include "../define.h"
inherit WEAPON;
reset(arg) {
   if(arg) return;
   ::reset();
   set_name("tooth");
   set_alias("gator tooth");
   set_short("A large gator tooth");
   set_long( "\
A sharpened, deadly looking gator's tooth that you could 'barter'\n\
with a merchant if you find the correct one.  Its sharp edge makes\n\
it a formidable weapon as well.  You can 'string' it upon a gator\n\
tooth necklace, if one is available to you.\n");
   set_class(16);
   set_type("knife");
   set_weight(1);
   set_value(4000+random(2000));
}

status
id(string str)
{
    if(::id(str)) return 1;
    if(str == "large gator tooth") return 1;
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
      write("You string the adult gator tooth upon your necklace.\n");
      say((string)this_player()->query_name() + " strings an adult gator tooth upon " + possessive(this_player()) + " necklace.\n");
      this_player()->add_weight(-1);
      x->add_tooth(2);
      destruct(this_object());
      return 1;
    }
}
