/* 03/07/06 Copyright (c) Earwax/David Halek
 *
 * An injection specifically intended for CyberNinja use only.  This
 * is sort of a stop-gap measure to beef ninja offense somewhat so
 * they can contend with other guilds, until we nerf the attack()
 * code in the dominant weapons, as well as address overall game
 * balance and equipment.
 *
 * Formula:  chance of a 2nd attack() call in a given round is:
 * ste/3 + dex/3 + chip level + belt level + xlevel/10
 * with each having a max of 10, for a total chance of 50%.
 *
 * This will not recurse further, for a max of 2 attacks per round,
 * on average, 3 attacks per 2 rounds, for a +100 with max stats
 * and max guild.
 */

#include "../defs.h"

#define ADRENALINE "/players/earwax/obj/products/support/adrenaline.c"

inherit "/obj/treasure.c";

void reset(status arg) 
{

  if (arg)
    return;

  set_short("A syringe containing "+HIC+"Crystalized Adrenaline"+NORM);
  set_long("\
This is a hypodermic needle containing a measured dose of crystalized\n\
adrenaline - the ultimate in performance drugs.  Were someone with a\n\
polymer-based blood type to inject this, they would experience a rush\n\
and performance enhancement greater than anything they'd ever experienced.\n\
To use this, "+HIW+"administer adrenaline"+NORM+".\n\n\
NOTE: this would be a fatal poison to anyone else.\n");
  set_weight(1);
  set_value(30000);
}

status id(string arg)
{
  return arg == "syringe" || arg == "injection" || arg == "shot" || arg == "adrenaline" || arg == "crystalized adrenaline" || arg == "hypodermic";
}

status do_inject(string arg)
{
  object ob;

  /*
   * Basic checks
   */
  if (!arg || arg != "adrenaline") 
    {
    notify_fail("Proper use:  "+HIW+"administer adrenaline"+NORM+".\n");
    return 0;
  }

  if (environment(this_object()) != this_player())
  {
    notify_fail("You must have the syringe in your inventory to use it.\n");
    return 0;
  }

  if ((string)this_player()->query_guild_name() != "cyberninja")
  {
    notify_fail("This injection would be fatal to you.\n");
    return 0;
  }

  if (present("CRYSTALIZED_ADRENALINE_ID", this_player()))
  {
    notify_fail("Your heart couldn't handle more of this drug.\n");
    return 0;
  }

  /*
   * Do the injection
   */
  ob = clone_object(ADRENALINE);
  move_object(ob, this_player());

  if (!((status)ob->activate_adrenaline(this_player())))
  {
    write("Injection failed.\n");
    return 1;
  }

  tell_object(this_player(), "Your pulse races madly and your muscles twitch slightly as the adrenaline takes hold!\n");
  tell_room(environment(this_player()), (string)this_player()->query_name()+" pulls out a syringe and administers a shot to their chest.\n", ({ this_player() }));
  move_object(this_object(), "/room/void");
  destruct(this_object());
  return 1;
}

void init() {
  add_action("do_inject", "administer");
}

/*
 * Dispenser setup
 */
string query_cost() { return "30000"; }
string query_desc() { return "Performance enhancer (CyberNinja only)"; }
string query_my_name() { return "syringe"; }
