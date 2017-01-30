/**************************************************************************
 * The Dark Ranger Communicator                                           *
 * Created by Beck/Russ Warren for Nirvana.                               *
 *  Updated by vital/keith for the Rangers                                *
 *  Last changed 2005.10.13                                               *
 **************************************************************************/
#pragma strict_types

#include "../RangerDefs.h"
#include <ansi.h>

status
id(string str)
{
  return str == "communicator" || str == "DarkRangerCommunicator" ||
    str == "channel_object";
}

string
query_name() { return "Dark Ranger Communicator"; }

string
short()
{
  string msg;
  msg = "";
  msg = "A Dark Ranger Communicator";
  return msg;
}


void
long()
{
  write(
    "This communicator is made with a steel case,"+
    " and has a fine quartz crystal.\n"+
    "Looking closer you see little blinking lights\n"+
    "all over the communicator.\n"+
    "");
}

void
guild_login()
{
  CHANNEL->channel_message("Power Ranger", "[" + BOLD + RED + " ENEMY " + OFF +
    "] Zordon says: " + this_player()->query_name() + " has appeared\n");
}

void
init_arg() { guild_login(); }

void
init()
{
  int i;
  if(environment(this_object()))
  {
    if(environment(this_object())->is_player() && environment(this_object()) == this_player() && !this_player()->is_kid())
    {
    }
  }
  CHANNEL->add_channel("Dark  Ranger",this_object());
}


status
get(){ return 1;}

status
drop() { return 1; }

status
QMuffles(){ return 1; }

string
QRangerType()
{
  if(environment(this_object()))
  {
    if(environment(this_object())->is_player())
    {
      if(this_player())
        write(RED);
      return "Dark Ranger";
    }
    else
    {
      if(this_player())
        write(BOLD+RED);
      return "Enemy";
    }
  }
}

string
QRangerColor(){ return " "; }

string
QRangerAnsi(){ return ""; }
