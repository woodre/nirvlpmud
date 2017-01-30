/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Prison currency
//  Create Date:  2005.06.03
//	 Thanks to Everyone who helped me, specifically Illarion
//	 Adapted from Pestilence's funny money, thanks Pesty
*/

#include "/players/tristian/lib/ClubFeddefine.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("cigarette");
  set_alias("cig");
  set_short(HIG+"A generic cigarette"+NORM);
  set_long(
    "A generic cigarette used for currency in every prison across\n"+
    "the land.  You can 'pay' off a 'con' to stop molesting you with\n"+
    "it, or you can 'trade' it for actual money on your release.\n");
  set_weight(1);
  set_value(10);
}

init() 
{
  AA("pay_off","pay");
  AA("cmd_barter","trade");
}

cmd_barter(str)
{
int value;

  if(id(str)) 
  {
    if(present("joey_the_snitch",environment(this_player()))) 
    {
    value = 500+random(501);
    write(
      "Joey the Snitch says, 'I can give you "+value+" coins to be used\n"+
      "in the real world.\n"+
      "Joey gives you "+value+" coins for your smoke.\n");
      this_player()->add_money(value);
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("You gotta go find Joey to trade that!\n");
}

pay_off(arg) 
{
  object peep;
  peep = present("con", environment(this_player()));
  if(!arg) 
  {
    notify_fail("Pay off who?\n");
    return 0;
  }
  if(arg == "con" || arg == "convict")
  {
   if(peep) 
    {
    write("\n\nThanks "+HIG+"SUCKER"+NORM+", I knew you were a sissy.\n");
    peep ->stop_fight();
    peep ->stop_fight();
    this_player()->stop_fight();
    this_player()->stop_fight();
    destruct(this_object());
    this_player()->recalc_carry();
    return 1;
    }
  }
  else
  {
    notify_fail("Pay off who?\n");
    return 0;
  }
}
