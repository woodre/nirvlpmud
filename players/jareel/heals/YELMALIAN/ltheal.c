#include "/players/jareel/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("potion");
  add_alias("elixir");
  set_short(NORM+"Elixir of "+HIR+"Vi"+HIB+"ta"+HIR+"li"+HIB+"ty"+NORM+"["+HIY+"LOW TOX"+NORM+"]");
  set_long("A potion filled with a swirling red and blue\n"+
           "liquid.  You may drink from the bottle. Elixir of'\n"+
           "Vitality is scribed on the side of the bottle.\n");
  set_type("potion");
  set_type_single("elixir of vitality");
  set_msg("You drink from the Elixir.\n"+
          "Health returns to your body.\n");
  set_msg2(" looks healthier\n");
  add_cmd("drink");
set_msg_postcharges(NORM+RED+" ]"+NORM);
set_msg_precharges(RED+"[ "+CYN);
  set_heal(50,50);
  set_charges(10);
  set_soak(3);
  set_stuff(3);
  set_value(400);
}

/* added by mizan because this shit is BOGUS. Credits goto many others
 * who found this though. */

init()
{
	add_action("on_drink","drink");
}

on_drink(arg)
{
	if(!arg) return 0;
	if((arg == "potion" || arg == "elixir") && 1 == random(7) )
	{
		write("The power of the force stops you.\nThe potion explodes violently for no good reason!\n");
		write("Well... perhaps because the original creator Jareel made a highly illegal\n"+
		"and toxic product so this sort of risk is inherent in the system it seems...\n");
		say(this_player()->query_name() + "'s potion EXPLODES and disappears...\n");
		this_player()->add_weight(this_object()->query_weight());
		destruct(this_object());
		return 1;
	}
	if(arg == "potion" || arg == "elixir") return ::cmd_imbibe(arg);
	else return 0;
}
