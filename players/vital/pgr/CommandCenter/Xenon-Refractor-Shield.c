#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

inherit "/players/guilds/Rangers/CommandCenter/Enhancement.c";

static int Pulse;
static int count;

status
id(string str)
{
  return str == "xenon refractor shield";
}

status
QPulse() { return Pulse; }

void
RestoreEnhancement()
{
  mixed *data;
  data = (array) Base->QData(Name);
  if(data)
  {
    Online = data[0];
    Pulse = data[1];
    Power = data[2];
  }
  if(Online)
  {
    Base->RegisterArmor(this_object(),({"physical",0,0,"pulse"}));
    move_object(this_object(),(Base));
  }
}

status
Configure(string str)
{
  int temp;
  if(str == "online")
  {
    if(Online)
    {
      tell_object(this_player(),
        "Zordon tells you: \"" + Name + " is already Online.\n");
      return 1;
    }
    write(Name+" is Online.\n");
    Base->RegisterArmor(this_object(),({"physical",0,0,"pulse"}));
    move_object(this_object(),(Base));
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
    Base->RemoveArmor(this_object());
    move_object(this_object(),(Base));
    SOnline(0);
  }
  else if(sscanf(str,"power %d",Pulse) == 1)
  {
    if(Pulse < 0) Pulse = 0;
    if(Pulse > 100) Pulse = 100;
    tell_object(this_player(),
      "Zordon tells you: \"" + Name + " is set to " + Pulse + "% power.\n");
  }
  else if(sscanf(str,"transfer %d",temp) == 1)
  {
    if(Base->QPower("base") >= temp)
    {
      if(Power + temp > 10000)
      {
        tell_object(this_player(),
          "Zordon tells you: \"That amount would overload the "+Name+".\"\n");
        return 1;
      }
      tell_object(this_player(),
        "Zordon tells you: \"Allocating " + temp + " Power for use on " +
        Name + ".\"\n");
      APower(temp);
      Base->APower(-temp);
    }
    else
    {
      tell_object(this_player(),
        "Zordon tells you: \"There is not that much Power in the base to \
allocate.\n");
      return 1;
    }
  }
  else if(str == "help")
  {
    write("Configuration options for "+Name+"\n");
    write("syntax is 'configure <option>'\n\n\
online - Turn the Xenon Refractor Shield on.\n\
offline - Turn the Xenon Refractor Shield off.\n\
power <amt> - set the shield power as a %.\n\
              The higher the power, the more damage the shield takes,\n\
              but the more power it uses.\n\
transfer <amt> - move Power from the Power Pool into the Shield.\n");
    return 1;
  }
  else
  {
    tell_object(this_player(),
      "Zordon tells you: \"That is not a configuration option for " + Name + 
      "\n");
    return 1;
  }
  Base->AData(Name, ({Online,Pulse,Power}));
  return 1;
}

status
Monitor()
{
  int i;
  int j;
  write(Name + "\n\n");
  write(Online ? BOLD + GREEN + "Online" + OFF : BOLD + RED + "Offline" + OFF);
  write("\n");
  if(Online && Pulse)
  {
    write("Power: [");
    i = Pulse/5;
    if(i <= 5) write(RED);
    else if(i >= 15) write(GREEN);
    else write(YELLOW);
    j = 20 - i;
    while(i)
    {
      write("|");
      i--;
    }
    while(j)
    {
      write(" ");
      j--;
    }
    write(OFF + "] " + Pulse + "%\n");
  }   
  return 1;
}

int
pulse()
{
  int X;
  if(!Online) return 0;
  if(Pulse <= 0)
  {
    Pulse = 0;
    return 0;
  }
  if(Power < 10*Pulse)
  {
    Pulse = Power/10;
    write("The shield begins to weaken.\n");
    Base->AData(Name, ({Online,Pulse,Power}));
  }
  if(!Pulse)
  {
    write("The shield has shut down.\n");
  }
  X = Pulse*100;
  APower(-Pulse);
  return X;
}
