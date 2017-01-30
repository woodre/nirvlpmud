/* 1800 gold */
#include <ansi.h>

inherit "/obj/generic_heal.c";
object gob;
int a;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("delaa plant");
  set_short(GRN+"A delaa plant"+NORM);
  add_alias("delaa");
  add_alias("plant");
  set_long(
"This small green plant grows exclusively in the Fallen Lands, and\n"+
"is considered a weed by the Gurthers.  Fortunately, the plant has\n"+
"wonderful healing properties for humans.  The cute green leaves\n"+
"jut out from the main stem, which is about an inch around and filled\n"+
"with a tasty white liquid.  ");
  set_type("bites");
  set_msg(
    GRN+"You take a bite of the delaa plant."+NORM+
    "  The thick "+HIW+"white liquid"+NORM+" within\n"+
    "the plant tastes sweet as it goes down your throat.\n");
  set_msg2(" takes a bite of a delaa plant and drinks the white liquid.\n");
  add_cmd("eat");
  set_heal(50,50);
  set_charges(3);
  set_soak(7);
  set_stuff(7);
  set_value(600);
}

query_save_flag(){  return 1;  }

int cmd_imbibe(string str)
{
  a = ::cmd_imbibe(str);
  if(a && (gob = present("circle_object", this_player())))
    gob->add_endurance(1);
  return a;
}
