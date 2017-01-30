#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

inherit "/players/guilds/Rangers/CommandCenter/Enhancement.c";

object *targets;
string Align;
static int Pulse;

void Regenerate();

status
id(string str)
{
  return str == "regeneration chamber" || str == "chamber";
}

string
realm() { return "NT"; }

void
reset(status arg)
{
  if(arg) return;
  enable_commands();
  Align = "Power Ranger";
}

void
init()
{
  if(present(this_player(),this_object()))
  {
    add_action("ATarget","regen");
    add_action("RTarget","regen_stop");
    add_action("Exit","exit");
  }
  else
  {
    add_action("Enter","enter");
  }
}

void
heart_beat() { Regenerate(); }

string
short(){ return "Regeneration Chamber"; }

void
long()
{
  write("The Regeneration Chamber.\n\
You can regain your personal power here.\n");
  if(present(this_player(),this_object()))
  {
    write(Power+" Power is currently availible.\n");
    write("To regenerate personal power type 'regen'.\n\
To stop regenerating type 'regen_stop'.\n\
To return to the Command Center type 'exit'.\n");
  }
  else
  {
    write("To enter the chamber type 'enter'.\n");
  }
}

status
Enter()
{
  this_player()->move_player("regeneration chamber#"+file_name(this_object()));
  return 1;
}

status
Exit()
{
  this_player()->move_player("command center#" +
    file_name(environment(this_object())));
  return 1;
}

void
RestoreEnhancement()
{
  mixed *data;
  data = (mixed) Base->QData(Name);
  if(data)
  {
    Online = data[0];
    Pulse = data[1];
    Power = data[2];
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
    Pulse = 0;
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
      if(Power + temp > 3000)
      {
        write("That much power would overload the "+Name+"\n");
        return 1;
      }
      write("Allocating "+temp+" Power for use on "+Name+"\n");
      APower(temp);
      Base->APower(-temp);
    }
    else
    {
      write("There is not that much Power in the base to allocate.\n");
      return 1;
    }
  }
  else if(str == "help")
  {
    write("Configuration options for "+Name+"\n");
    write("syntax is 'configure <option>'\n\n\
transfer - move Power from the Power Pool into the Regen Chamber.\n");
    return 1;
  }
  else
  {
    write("That is not a configuration option for "+Name+"\n");
    return 1;
  }
  Base->AData(Name, ({Online,Pulse,Power}) );
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
    if(i <= 5)
      write(RED);
    else if(i >= 15)
      write(GREEN);
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

void
Regenerate()
{
  int i;
  object comm;
  if(!targets) return;
  for (i=0; i<sizeof(targets); i++)
  {
    if(targets[i])
    {
      if(present(targets[i], this_object()))
      {
        comm = present("RangerCommunicator",targets[i]);
        if( (string) comm->QRangerAlign() == Align)
        {
          if(targets[i]->query_hp() < targets[i]->query_mhp())
          {
            if(Power > 2)
            {
              APower(-2);
              tell_object(targets[i], "You feel a warm light surround your \
body as it heals.\n");
              targets[i]->add_hp(( (int) comm->QuerySkillLevel("machine")) / 4);
            }
            else
            {
              tell_object(targets[i],
                "Zordon tells you: \"There is not enough Power to \
regenerate.\"\n");
              targets -= ({ targets[i] }
              );
              i = i-1;
            }
          }
          else
          {
            tell_object(targets[i],
              "Zordon tells you: \"You stop regenerating your personal \
power.\"\n");
            targets -= ({targets[i]}
            );
            i = i-1;
          }
        }
        else
        {
          tell_object(targets[i],
            "Zordon tells you: \"You can't regenerate here!\"\n");
          targets -= ({targets[i]}
          );
          i = i-1;
        }
      }
      else
      {
        targets -= ({targets[i]}
        );
        i = i-1;
      }
    }
    else
    {
      targets -= ({ targets[i] }
      );
      i = i-1;
    }
  }
  if(sizeof(targets) == 0) set_heart_beat(0);
}

status
ATarget(object ob)
{
  if(!targets) targets = ({}
  );
  ob = this_player();
  if( (string) ob->query_guild_name() != GUILDNAME) return 0;
  if(member_array(ob, targets) != -1) return 0;
  else
  {
    targets += ({ ob }
    );
    write("You begin to regenerate your personal power.\n");
    set_heart_beat(1);
  }
  return 1;
}

status
RTarget(object ob)
{
  if(!targets) return 0;
  ob = this_player();
  if( (string) ob->query_guild_name() != GUILDNAME) return 0;
  if(member_array(ob, targets) != -1)
  {
    targets -= ({ ob }
    );
    write("You stop regenerating your personal power.\n");
    return 1;
  }
  else
    return 0;
}
