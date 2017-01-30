inherit "/obj/generic_heal.c";
#include "/players/softly/misc/ansi.h"
void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("marshmallow");
  add_alias("marshmallow");
  add_alias("marshmallows");
  add_alias("marshm");
  set_short(HIW+"Marshmallows"+NORM);
  set_long("Large puffy white marshmallows for you to eat,\n");
  set_type("marshmallows");
  set_msg("You stuff a large puffy marshmallow into your mouth.\n");
  set_msg2(" eats a huge marshmallow.\n");
  add_cmd("eat");
  add_cmd("stuff");
  set_heal(0,40); 
  set_charges(3);
  set_stuff(12);
  set_value(208);
}
short(){ return HIW+"Marshmallows"+NORM+" ["+charges+"]"; }
