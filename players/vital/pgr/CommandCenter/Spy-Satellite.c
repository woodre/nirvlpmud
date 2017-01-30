#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

inherit "/players/guilds/Rangers/CommandCenter/Enhancement.c";

static object Target;
static int Autolook;
static object CommTower;
static status LiveUpdate;

static int Transmission;

status move_player(string dir_dest);
status lookout();

status
id(string str)
{
  return str == "spy satellite";
}

void
RestoreEnhancement()
{
  mixed *data;
  data = (array) Base->QData(Name);
  if(data)
  {
    Online = data[0];
  }
  if(Online)
  {
    enable_commands();
    move_object(this_object(),environment(Base));
  }
}

status
Configure(string str)
{
  string target;
  if(COMM)
  {
    if(COMM->QuerySkillLevel("communication") < 15)
    {
      tell_object(this_player(),
        "Zordon tells you: \"You do not have the skill to configure the \
Spy Satellite.\"\n");
      return 1;
    }
  }
  if(str == "online")
  {
    if(Online)
    {
      tell_object(this_player(),
        "Zordon tells you: \"" + Name + " is already Online.\"\n");
      return 1;
    }
    tell_object(this_player(),
        "Zordon tells you: \"" + Name + " is Online.\"\n");
    enable_commands();
    move_object(this_object(),environment(Base));
    SOnline(1);
  }
  else if(str == "offline")
  {
    if(!Online)
    {
      tell_object(this_player(),
        "Zordon tells you: \"" + Name + " is already Offline.\"\n");
       return 1;
    }
    tell_object(this_player(),
        "Zordon tells you: \"" + Name + " is Offline.\"\n");
    move_object(this_object(),environment(Base));
    Autolook = 0;
    Target = 0;
    SOnline(0);
  }
  else if(str == "help")
  {
    write("Configuration options for "+Name+"\n");
    write("syntax is 'configure <option>'\n\n\
online - Turn the Spy Satellite on.\n\
offline - Turn the Spy Satellite off.\n\
transmit <amt> - The time period between broadcasts.  Longer time \n\
                 saves power.\n\
track <person> - Allows the satellite to automatically track a person.\n\
return - Returns the satellite to the Command Center (outside)\n\
<direction> - moves the satellite in the given direction\n");
    return 1;
  }
  else if(sscanf(str,"transmit %d",Autolook) == 1)
  {
    tell_object(this_player(),
        "Zordon tells you: \"" + Name + " is configured to transmit every " + 
        Autolook + " seconds.\"\n");
    call_out("Autolook",Autolook);
  }
  else if(sscanf(str,"track %s",target) == 1)
  {
    if(present(target, environment(this_object())))
    {
      Target = present(target, environment(this_object()));
      if(Target->query_invis())
      {
        tell_object(this_player(),
          "Zordon tells you: \"" + capitalize(str) +
          " is not present to track.\n");
        return 1;
      }
      if(!(living(Target)))
      {
        tell_object(this_player(),
          "Zordon tells you: \"You don't need to track a non-living \
object.\"\n");
        return 1;
      }
      tell_object(this_player(),
        "Zordon tells you: \"" + Name + " is configured to track " + 
        capitalize(target) + ".\n");
      call_out("Track",20);
    }
    else
    {
      tell_object(this_player(),
        "Zordon tells you: \"" + capitalize(str) + " is not present to \
track.\"\n");
      return 1;
    }
  }
  else if(command(str, this_object()))
  {
    tell_object(this_player(),
        "Zordon tells you: \"" + Name + " is doing " + str + ".\"\n");
    return 1;
  }
  else
  {
    tell_object(this_player(),
      "Zordon tells you: \"" + capitalize(str) +
      " is not a configuration option for " + Name + ".\"\n");
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
    Target->query_name()+"\n");
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
  if(!present(Target, environment(this_object())))
    move_object(this_object(),environment(Target));
  call_out("Track",20);
  return 1;
}

status
catch_tell(string str)
{
  if(this_player() != this_object() && !LiveUpdate) return 0;
  if(!CommTower)
    CommTower = (object) Base->QCurrEnhancement("Communications Tower 1");
  if(!Online) return 0;
  if(!CommTower)
    return 0;
  if(Transmission == 1)
  {
    tell_object(CommTower, BLUE + "---------------------------" + OFF + RED +
      "Satellite Trasmission" + OFF + BLUE +
      "-------------------------" + OFF + "\n\n");
  }
  else if(Transmission == 2)
  {
    tell_object(CommTower, str);
  }
  else if(Transmission == 3)
  {
    tell_object(CommTower, "\n\n" + BLUE + "------------------------------" +
      OFF + RED + "End Trasmission" + OFF + BLUE +
      "----------------------------" + OFF + "\n");
  }
  else
  {
    tell_object(CommTower, BLUE + "---------------------------" + OFF + RED +
      "Satellite Trasmission" + OFF + BLUE +
      "-------------------------" + OFF + "\n\n");
    tell_object(CommTower,str);
    tell_object(CommTower, "\n\n" + BLUE + "------------------------------" +
      OFF + RED + "End Trasmission" + OFF + BLUE +
      "----------------------------" + OFF + "\n");
  }
}


/*
* This routine is called from objects that moves the player.
* Special: direction "X" means teleport.
*/
status
move_player(string dir_dest)
{
  string msgout, msgin;
  string dir, dest;
  object ob;
  int is_light;
  if(!dir_dest) return 0;
  if(sscanf(dir_dest, "%s#%s", dir, dest) != 2)
  {
    tell_object(this_object(), "Move to bad dir/dest\n");
    return 1;
  }
  if(!msgout) msgout = "leaves";
  is_light = set_light(0);
  if(is_light < 0) is_light = 0;
  move_object(this_object(), dest);
  is_light = set_light(0);
  if(is_light < 0) is_light = 0;
  if(!msgin) msgin = "arrives";
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
      if(ob->short())
        write(ob->short()+"\n");
    }
  }
  Transmission = 3;
  write("");
  Transmission = 0;
  return 1;
}
