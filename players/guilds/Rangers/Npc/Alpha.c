/******************************************************************************
 *  File:           Alpha.c
 *  Author(s):      Beck@Nirvana modified by Vital@Nirvana
 *  Copyright:      Copyright (c) 2002 
 *  Source:         10/13/05
 *  Change History: 2005.10.13, 2005.10.28 [added coin deposit/retrieve]
 *****************************************************************************/
#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

inherit "obj/monster";

int coins;

status
RangerNPC() { return 1; }

string
QRangerAnsi() { return ""; }

string
query_guild_name(){ return "rangers"; }

void set_coins(int x) { coins = x; }
int  query_coins() { return coins; }
void add_coins(int x) { coins += x; }

void
reset(status arg)
{
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_race("robot");
  set_name("alpha");
  set_alias("alpha");
  set_short("Alpha");
  set_long(format("This is Alpha 5, the power rangers tiny robot friend. He \
can control the command center all by himself."));
  set_al(500);
  set_level(6);
  set_hp(100);
  set_wc(11);
  set_ac(5);
  set_chat_chance(2);
  load_chat("Alpha cries: Aye, Aye, Aye!\n");
  add_money(250);
  set_dead_ob(this_object());
  set_coins(0);
}

void
long()
{
  ::long();
  write(format("Alpha currently has " + coins + (coins == 1? " coin" : " coins")
    + " in reserve. you may either \'deposit\' or \'retrieve\' <amount>."));
}

void
init()
{
  ::init();
  if (this_player() &&
     (string) this_player()->query_guild_name() == GUILDNAME)
  {
    add_action("coin_exchange","deposit");
    add_action("coin_exchange","retrieve");
  }
}

status
coin_exchange(string str)
{
  string doing, junk;
  int moolah, exchange;
  if (!str)
  {
    notify_fail("Alpha says: Aye, Aye, Aye! What did you want to do?\n\
Alpha says: You may \'deposit\' or \'retrieve\' <amount> with/from me.\n");
    return 0;
  }
  doing = query_verb();
  moolah = (int) this_player()->query_money();
  if ( str == "all")
  {
    if (doing == "deposit")
      str = "" + (string) this_player()->query_money();
  }
  if ( sscanf(str, "%d", exchange) == 1 )
  {
    if (doing && doing == "deposit")
    {
      if (exchange <= moolah)
      {
        this_player()->add_money(-exchange);
        add_coins(exchange); 
        CHANNEL->channel_message("Power Ranger", RED + "[" + GRN +
          "Power Ranger" + OFF + RED + "]" + OFF + " Alpha says: " +
          this_player()->query_name() + " has deposited " + exchange +
          " coins with me.\n");
        CHANNEL->channel_message("Power Ranger", RED + "[" + GRN +
          "Power Ranger" + OFF + RED + "]" + OFF +
          " Alpha says: If you need some assistance, you can retrieve them \
from me.\n");
        tell_object(this_player(), "Zordon tells you: \"Thank you for leaving "+
          exchange + " coins for other Power Rangers.\"\n");
        return 1;
      }
      else
      {
        write("Alpha says: Aye, Aye, Aye! You don't have that many coins.\n");
        return 1;
      }
    }
    if (doing && doing == "retrieve")
    {
      if (exchange > coins)
      {
        write("Alpha says: Aye, Aye, Aye! There are only " + coins +
          " coins.\n");
        return 1;
      }
      if (moolah < 80000 && ((moolah + exchange) <= 80000))
      {
        this_player()->add_money(exchange);
        add_coins(-exchange);
        CHANNEL->channel_message("Power Ranger", RED + "[" + GRN +
          "Power Ranger" + OFF + RED + "]" + OFF + " Alpha says: " +
          this_player()->query_name() + " has retrieved " + exchange +
          " coins from me.\n");
        tell_object(this_player(), "Zordon tells you: \"You have retrieved " +
          exchange + " coins from Alpha.\"\n");
        return 1;
      }
      else
      {
        write("Alpha says: Aye, Aye, Aye! Don't be greedy, you don't need " +
          exchange + " coins.\n");
        return 1;
      }
    }
  }
  else
  {
    notify_fail("Alpha says: Aye, Aye, Aye! What did you want to do?\n\
Alpha says: \"" + str + "\" is not an amount.\n");
    return 0;
  }
}

status
custom_clean()
{
  CHANNEL->remove_channel("Power Ranger", this_object());
  return 0;
}

status
monster_died()
{
  object corpse;
  CHANNEL->remove_channel("Power Ranger", this_object());
  set_coins(0);
  return 0;
}

#ifndef __LDMUD__
status
#else
void
#endif
remove_object(object ob)
{
  set_coins(0);
  CHANNEL->remove_channel("Power Ranger", this_object());
#ifndef __LDMUD__
  return 1;
#endif
}
