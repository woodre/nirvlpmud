/******************************************************************
 *  Honorary Ranger Communicator                                  *
 *  Made by Beck                                                  *
 *  Updated by vital/keith for the Rangers                        *
 *  Last changed 2005.10.13                                       *
 ******************************************************************/
#pragma strict_types

#include "RangerDefs.h"
#include <ansi.h>

static int muffles;
string *Banished;

status
id(string str)
{
  return str == "ranger_object" || str == "communicator" ||
    str == "honor_ranger_communicator" || str == "channel_object";
}

string
short(){ return "A Power Ranger Communicator"; }

status
long()
{
  write("This is a communications device for the Power Rangers.\n"+
    "It allows you to converse on the guild channel.\n"+
    "It also signifies your alliance with all Power Ranger guild members.\n"+
    "For a list of features, type 'ranger'.\n"+
    "");
  return 1;
}

void
init()
{
  if(!Banished)
    restore_object(SAVEDIR+"BANISHED");
  if(member_array(this_player()->query_real_name(), Banished) != -1)
  {
    write(CLR+OFF+"\n\n\n\n\n\n\n\n\n\n\n\n\n\t");
    write("You will no longer be associated with the Power Rangers.\n\n\n");
    write("\t\t\t"+BLINK+BOLD+RED+"B A N I S H E D"+OFF+"\n\n\n\n\n\n\n\n");
    destruct(this_object());
    return;
  }
  add_action("GeneratePower","generate");
  add_action("CheckPower","power");
  add_action("ranger_info","ranger");
  add_action("ranger_talk","rt");
  add_action("ranger_emote","rte");
  add_action("ranger_who","rwho");
  add_action("ranger_history","rth");
  add_action("dest_honor_ranger_communicator","rleave");
  add_action("muff_on","rtm");
  add_action("quit","quit");
  CHANNEL->add_channel("Power Ranger",this_object());
}

string
query_auto_load(){ return "/players/guilds/Rangers/HonorRangerCommunicator:"; }


string
query_ranger_type()
{
  string name;
  switch(environment(this_object())->query_guild_name())
  {
    case "warrior":
      name = "(Warrior)";
      break;
    case "bard":
      name = "(Bard)";
      break;
    case "Knights Templar":
      name = "(Knight)";
      break;
    case "vampire":
      name = "(Vampire)";
      break;
    case "healer":
      name = "(Healer)";
      break;
    case "polymorph":
      name = "(Poly)";
      break;
    case "decepticon":
      name = "(Decepticon)";
      break;
    case "dervish":
      name = "(Dervish)";
      break;
    default: name = "";
  }
  if(environment(this_object())->query_level() > 20) name = "(Coder)";
  if(this_player())
    write(BOLD+GREEN);
  return "Ally "+name;
}

status
CheckPower(){ MASTER->CheckPower("Power Ranger"); return 1;  }

status
GeneratePower(string str)
{
  return (int) "/players/guilds/Rangers/Commands/Generate.c"->RangerPower(str,
    "Power Ranger");
}

status
ranger_talk(string str)
{
  return (int) "/players/guilds/Rangers/Commands/Rt.c"->RangerPower(str,
    "Power Ranger");
}

status
ranger_emote(string str)
{
  return (int) "/players/guilds/Rangers/Commands/Rte.c"->RangerPower(str,
    "Power Ranger"); }

status
ranger_who(string str)
{
  return (int) "/players/guilds/Rangers/Commands/Rwho.c"->RangerPower(str,
    "Power Ranger");
}

status
ranger_history(string str)
{
  return (int) "/players/guilds/Rangers/Commands/Rth.c"->RangerPower(str,
    "Power Ranger");
}

status
dest_honor_ranger_communicator()
{
  write("I hope someday you'll be a member again.  Until then, Good Luck.\n");
  CHANNEL->remove_channel("Power Ranger",this_object());
  destruct(this_object());
  return 1;
}

status
ranger_info()
{
  write("Commands available with the Ranger Communicator.\n\n\n"+
"rt        Allows you to talk on the Power Ranger guild channel.\n"+
"rte       Allows you to emote on the Power Ranger guild channel.\n"+
"rtm       Turns your guild channel muffle on or off.\n"+
"rwho      A list of Power Rangers and Allies currently on Nirvana.\n"+
"rleave    Destruct your honorary communicator.\n"+
"ranger    This help screen.\n"+
"generate  Donate sps to the power pool.\n"+
"power     Check the Power Pool Levels.\n");
  return 1;
}

void
quit()
{
  CHANNEL->remove_channel("Power Ranger",this_object());
  return;
}

status
get(){ return 1;}

status
drop(){ return 1;}

status
muff_on()
{
  if(muffles)
  {
    muffles = 0;
    CHANNEL->add_channel("Power Ranger",this_object());
    write("Your guild channel muffle is OFF.\n");
    return 1;
  }
  muffles = 1;
  CHANNEL->remove_channel("Power Ranger",this_object());
  write("Your guild channel muffle is ON.\n");
  return 1;
}

status
QMuffles(){ return muffles; }

string
QRangerAnsi(){ return ""; }

string
QRangerColor(){ return ""; }
