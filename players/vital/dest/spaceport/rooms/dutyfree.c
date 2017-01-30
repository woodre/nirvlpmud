/******************************************************************************
 *  File:           dutyfree.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         2000.12.18
 *  Notes:
 *  Change History: 2001.01.04 [added objects for sale]
                    2005.10.23 [strict_type'd]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h" /*area header */

inherit "room/room";

object item;
int value;

status checks_and_balances(string str);
status buy_me(string str);
status search_me(string str);
status read_sign(string str);

void
reset(status arg)
{
  ::reset(arg);
  if (arg) return;
  set_light(1);
  set_short("Duty Free Shop");
  set_long(format("  The Duty Free Shop\nWelcome to the Duty Free Shop. Here \
you can purchase items free of the taxes that plague the rest of Nirvana. \
The shop is brightly lit and full of fancy items that only the rich and \
influential can afford. The merchandise is varied and always rare here. In \
the future they will expand to include a mail order catalog that can be \
browsed while flying in a shuttle. There is a small sign on the wall behind \
the counter."));
  add_item("shop",
    "This is the best shop for expensive trinkets");
  add_item("trinkets",
    "The most expensive of items for sale here");
  add_item("here",
    "This is the best shop for expensive trinkets");
  add_item("items",
    "You can find a wide variety of unique, albeit expensive things here");
  add_item("taxes",
    "You are outraged at the rising inflation endemic in the world");
  add_item("plague",
    "An insidous, evil monster that sucks the life blood from the world");
  add_item("nirvana",
    "From a shuttle it is said you can see the whole mud");
  add_item("light",
    "You will go blind if you look at these " + BOLD + WHT +
    "bright" + NORM + YEL + " lights" + NORM);
  add_item("rich",
    "The fat cats have a lot of cash");
  add_item("influential",
    "These are the people you want to have on your side");
  add_item("merchandise",
    "Everything here is of the highest quality");
  add_item("future",
    "Everyone always wants to see what is in the future");
  add_item("catalog",
    "Coming Soon to a Duty Free Shop near you");
  add_item("shuttle",
    "The standard rho-field transportation vessel used at the N.U.T.S.\n\
  Their arrivals and departures are recorded on the display");
  add_item("sign",
    "If you \'read\' the sign, you might learn more");
  add_item("counter",
    "A wide, " + BOLD + RED + "oak" + NORM +
    " counter where the merchandise is purchased");
  add_exit(SPROOM + "seconcourse.c","out");
}

void
init()
{
  ::init();
  add_action("search_me","search");
  add_action("read_sign","read");
  add_action("buy_me","buy");
}

status
read_sign(string str)
{
  if(!str)
  {
    notify_fail("What are you trying to read?\n");
    return 0;
  }
  else if(str == "sign")
  {
    write("     Buy Now And Save ! ! !\n");
    write(read_file(SPSAVE + "dutyfreesign.txt"));
  }
  return 1;
}

status
search_me(string str)
{
  if(!str)
  {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else write("You search the " + str + " but find nothing.\n");
  return 1;
}

status
buy_me(string str)
{
  if(!str)
  {
    write(read_file(SPSAVE + "dutyfreesign.txt"));
    notify_fail("What is it that you are trying to buy?\n");
    return 0;
  }
  else switch(str)
  {
    case "ring":
    case "diamond ring":
      item = clone_object(SPARMOR + "dfring.c");
      value = 3000;
      break;
    case "chocolates":
      item = clone_object(SPOBJ + "dfchocolates.c");
      value = 800;
      break;
    case "pen":
    case "gold pen":
    case "gold plated pen":
      item = clone_object(SPOBJ + "dfpen.c");
      value = 5450;
      break;
    case "buttons":
    case "cashmere buttons":
      item = clone_object(SPARMOR + "dfbuttons.c");
      value = 10000;
      break;
    default :
      write("You cannot buy " + str + " here. Mail Vital if you think you need it.\n");
  }
  checks_and_balances(str);
  return 1;
}

status
checks_and_balances(string str)
{
  if(this_player()->query_money() < value)
  {
    write("You don't have enough money to buy the " + str + ".\n");
    return 1;
  }
  if(!this_player()->add_weight(item->query_weight()))
  {
    write("You are already carrying too much to carry the" + str + ".\n");
    return 1;
  }
  move_object(item, this_player());
  this_player()->add_money(-value);
  write("You purchase a " + str + ".\n");
  say(this_player()->query_name() + " purchases a " + str + " for " +
    value + "\n");
  return 1;
}
