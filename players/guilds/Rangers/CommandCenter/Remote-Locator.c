#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

inherit "/players/guilds/Rangers/CommandCenter/Enhancement.c";

static object Target;
static int Autolook;
static object CommTower;
static status LiveUpdate;
static int Transmission;

status lookout();

status
id(string str)
{
  return str == "remote locator" || str == "ranger_locator" || str == Name;
}

string
short()
{
  if(this_player())
  {
    if( (string) this_player()->query_guild_name() == GUILDNAME)
    {
      return Name;
    }
    return 0;
  }
}

void
RestoreEnhancement()
{
  mixed *data;
  data = (mixed) Base->QData(Name);
  if(data)
  {
    Online = data[0];
  }
  if(Online)
  {
    enable_commands();
    CHANNEL->add_channel("Power Ranger",this_object());
  }
}

status
Configure(string str)
{
  string target;
  if(COMM)
  {
    if(COMM->QuerySkillLevel("communication") < 13)
    {
      write("You do not have the skill to configure the Remote Locator.\n");
      return 1;
    }
  }
  if(str == "online")
  {
    if(Online)
    {
      write(Name+" is already Online.\n");
      return 1;
    }
    write(Name+" is Online.\n");
    CHANNEL->add_channel("Power Ranger",this_object());
    enable_commands();
    SOnline(1);
  }
  else if(str == "offline")
  {
    if(!Online)
    {
      write(Name+" is already Offline.\n");
      return 1;
    }
    write(Name+" is Offline.\n");
    CHANNEL->remove_channel("Power Ranger",this_object());
    Autolook = 0;
    Target = 0;
    SOnline(0);
  }
  else if(str == "help")
  {
    write("Configuration options for "+Name+"\n");
    write("syntax is 'configure <option>'\n\n\
online - Turn the Remote Locator on.\n\
offline - Turn the Remote Locator off.\n");
    return 1;
  }
  else
  {
    write(capitalize(str)+" is not a configuration option for "+Name+"\n");
    return 1;
  }
  Base->AData(Name, ({Online}));
  return 1;
}

status
Monitor()
{
  write(Name+"\n\n");
  write(Online ? BOLD+GREEN+"Online"+OFF : BOLD+RED+"Offline"+OFF);
  write("\n");
  if(Online && Autolook) write("Transmitting data every " + Autolook +
    " seconds.\n");
  if(Online && Target) write("Tracking is ON.  Target: " +
    Target->query_name() + "\n");
  return 1;
}

status
Autolook()
{
  object ob;
  if(!Autolook) return 0;
  if(!Online) return 0;
  lookout();
  call_out("Autolook",Autolook);
  return 1;
}

status
Track()
{
  if(!Online) return 0;
  if(!Target)
  {
    Target = 0;
    return 0;
  }
  if(Target->query_invis())
  {
    Target = 0;
    return 0;
  }
  if(!present(Target, environment(this_object()))) move_object(this_object(),environment(Target));
  call_out("Track",20);
  return 1;
}

/*
* This routine is called from objects that moves the player.
* Special: direction "X" means teleport.
*/
void
move_player(string dir_dest)
{
  string msgout, msgin;
  string dir, dest;
  object ob;
  int is_light;
  if(!dir_dest) return;
  if (sscanf(dir_dest, "%s#%s", dir, dest) != 2)
  {
    tell_object(this_object(), "Move to bad dir/dest\n");
    return;
  }
  if (!msgout) msgout = "leaves";
  is_light = set_light(0);
  if (is_light < 0) is_light = 0;
  move_object(this_object(), dest);
  is_light = set_light(0);
  if (is_light < 0) is_light = 0;
  if (!msgin) msgin = "arrives";
  lookout();
}

status
lookout()
{
  object ob;
  Transmission = 1;
  write("");
  Transmission = 2;
  environment(this_object())->long();
  for(ob = first_inventory(environment(this_object()));
    ob; ob = next_inventory(ob))
  {
    if(ob != this_object())
    {
      if(ob->short()) write(ob->short()+"\n");
    }
  }
  Transmission = 3;
  write("");
  Transmission = 0;
  return 1;
}

status
get()
{ 
  if( (string) this_player()->query_guild_name() == "rangers")
    if(COMM->QuerySkillLevel("communication") >= 13)
      return 1;
    else
      return 0;
  else
    return 0;
}

status
drop() { return 0; }

string
query_name() { return Name; }

string
QRangerAnsi() { return ""; }

string
QRangerColor() { return ""; }

string
QRangerType() { return "<<>>"; }

status
query_invis()
{
  if(this_player())
    if(COMM)
      if(COMM->QuerySkillLevel("communication") >= 13)
         return 0;
  return 1;
}

status
valid_teleport()
{
  if(this_player())
    if(COMM)
      if(COMM->QuerySkillLevel("communication") >= 13 &&
        COMM->QuerySkillLevel("teleport") >= 10)
        return 1;
  return 0;
} 

int
query_weight() { return 3; }   

status
QMuffles() { return 1; }
