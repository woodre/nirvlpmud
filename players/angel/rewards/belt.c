/*                                                                    *
 *    File:             /players/angel/tools/belt.c                   *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007                            *
 *                              All Rights Reserved.                  *
 *    Source:           07/25/07                                      *
 *    Notes:                                                          *
 *                     With Earwax's guidance                         *
 *                                                                    *
 *    Change History:                                                 *
 */
#if 0 /* Rumplemintz */
#include "/sys/lib.h"
#endif

#include <ansi.h>

inherit "obj/treasure.c";

int coins_held;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("belt");
  set_alias("bag");
  set_long(
  " This is a Money belt pack to store extra money so it doesn't\n"+
  "get lost.  This is a small fabric pouch secured with a zipper\n"+
  "and worn at the waist by a strap around the hips.  Belt packs\n"+
  "are used by travelers to secure their money.\n");
  set_weight(0);
  set_value(0);
  set_no_clean(0);
}

short()
{
  if (this_player() != environment(this_object())
  && (int)this_player()->query_level() < 21) 
    return "";
  return HIB+"Money Belt "+NORM+"("+YEL+coins_held+NORM+" coins stashed) (worn)";
}

drop() { return 1; }

string query_auto_load()
{
  return "/players/angel/rewards/belt.c:"+coins_held;
}

void init_arg(mixed x)
{
  int i;
  if (!x) return;
  sscanf(x+"", "%d%s", i, x);
  coins_held = i;
}

init()
  {
  ::init();
  add_action("stash","stash");
  add_action("unstash","unstash");
}

/*  I added   this_player()->add_money(-(stash)); for coins to come out of players INV and finished the unstash */
/*  Took a while to get the operators correct.  The thought process help ALOT */
/*  WOOOP!!!!! FINALLY GOT IT WORKING!!!  TESTED AND WORKS GREAT */
/*  It is ready for APPROVAL!!!!!! */
stash(string arg)
{
  int current, stash;

  if (!arg || !sscanf(arg, "%d", stash))
  {
    notify_fail("You currently have "+coins_held+" coins stashed in your moneybelt.\n");
    return 0;
  }
  if (coins_held == 20000) 
  {
    notify_fail("You cannot stash any more coins in your moneybelt.\n");
    return 0;
  }
  if ((int)this_player()->query_money() < stash)
  {
    notify_fail("You don't have enough coins for that.\n");
    return 0;
  }
  if (stash < 0)
  {
    notify_fail("Nice try fruitcake.  Positive integers only.\n");
    return 0;
  }
  if ((stash + coins_held) > 20000)
  {
    stash = 20000 - coins_held;
    write("You can only stash up to 20,000 coins in the belt.\n");
  }

  this_player()->add_money(-(stash));
  coins_held += stash;
  write("You stash "+stash+" coins in your moneybelt.\n");
  write("Your moneybelt now holds "+coins_held+" coins in it.\n");
  return 1;
}

unstash(string arg)
{
  int current, unstash;

  if (!arg || !sscanf(arg, "%d", unstash))
  {
    notify_fail("You currently have "+coins_held+" coins stashed in your moneybelt.\n");
    return 0;
  }
  if (coins_held == 0) 
  {
    notify_fail("You have no more coins in your moneybelt.\n");
    return 0;
  }
  if (unstash < 0)
  {
    notify_fail("Nice try fruitcake.\n");
    return 0;
  }
  if ((unstash > coins_held))
  {
    notify_fail("You can only unstash the "+coins_held+" coins that are in the belt.\n");
    return 0;
  }
  
  this_player()->add_money(unstash);
  coins_held -= unstash;
  write("You unstash "+unstash+" coins from your moneybelt.\n");
  write("Your moneybelt now holds "+coins_held+" coins in it.\n");
  return 1;
}
