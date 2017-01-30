#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

inherit "/players/guilds/Rangers/CommandCenter/Enhancement.c";

static int Pulse;
static int count;

status
id(string str) { return str == "ion pulse cannon"; }

void
RestoreEnhancement()
{
  mixed *data;
  data = (mixed) Base->QData(Name);
  if(data)
  {
    Online = data[0];
    Pulse = data[1];
    if(sizeof(data) >= 3) Power = data[2];
  }
  if(Online)
  {
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
      write(Name+" is already Online.\n");
      return 1;
    }
    write(Name+" is Online.\n");
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
    move_object(this_object(),(Base));
    SOnline(0);
  }
  else if(sscanf(str,"power %d",Pulse) == 1)
  {
    if(Pulse < 0) Pulse = 0;
    if(Pulse > 100) Pulse = 100;
    write(Name+" is set to "+Pulse+"% power.\n");
  }
  else if(sscanf(str,"transfer %d",temp) == 1)
  {
    if(Base->QPower("base") >= temp)
    {
      if(Power + temp > 10000)
      {
        write("That amount would overload the "+Name+"\n");
        return 1;
      }
      write("Allocating "+temp+" Power for use on "+Name+"\n");
      APower(temp);
      Base->APower(-temp);
    }
    else
    {
      write("There is not that much power in the base to allocate.\n");
      return 1;
    }
  }
  else if(str == "help")
  {
    write("Configuration options for "+Name+"\n");
    write(
"syntax is 'configure <option>'\n\n\
online - Turn the Ion Pulse Cannon on.\n\
offline - Turn the Ion Pulse Cannon off.\n\
power <amt> - set the cannon power as a %.\n\
              The higher the power, the more damage the cannon does,\n\
              but the more power it uses, and the longer it takes to shoot\n\
transfer <amt> - move Power from the Power Pool into the Pulse Cannon.\n");
    return 1;
  }
  else
  {
    write("That is not a configuration option for "+Name+"\n");
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
  write(Name+"\n\n");
  write(Online ? BOLD+GREEN+"Online"+OFF : BOLD+RED+"Offline"+OFF);
  write("\n");
  if(Online && Pulse)
  {
    write("Power: [");
    i = Pulse/5;
    if(i <= 5) write(RED);
    else
    if(i >= 15) write(GREEN);
    else 
      write(YELLOW);
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
    write(OFF+"] "+Pulse+"%\n");
  }
  return 1;
}

int
pulse()
{
  object atkr;
  int X;
  if(!Online) return 0;
  if(!count)
  {
    tell_room(environment(this_object()),
      "Zordon says, \"The Ion Pulse Cannon begins to charge.\"\n");
    count++;
    return 0;
  }
  if(count == (Pulse/4))
  {
    if(Power < Pulse) return 0;
    say(BLUE + "              ***\n            *******\n\
***********\n            *******\n              ***\n" + OFF);
    count = 0;
    APower(-Pulse);
    return Pulse;
  }
  else
  {
    count ++;
    return 0;
  }
}
