#include "/players/jareel/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("potion");
  add_alias("elixir");
  set_short(NORM+"Elixir of "+HIR+"Health "+NORM+"["+YEL+"HIGH TOX"+NORM+"]"+NORM);
  set_long("A potion filled with a swirling red liquid.\n"+
           "You may drink from the bottle. Elixir of'\n"+
           "Health is scribed on the side of the bottle.\n");
  set_type("potion");
  set_type_single("elixir of health");
  set_msg("You drink from the Elixir.\n"+
          "Health returns to your body.\n");
  set_msg2(" looks healthier\n");
  add_cmd("drink");
set_msg_postcharges(NORM+RED+" ]"+NORM);
set_msg_precharges(RED+"[ "+CYN);
  set_heal(100,0);
  set_charges(10);
  set_soak(10);
  set_stuff(10);
  set_value(400);
}