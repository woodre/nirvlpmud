#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

inherit "/players/guilds/Rangers/CommandCenter/Regenerate.c";
inherit "/obj/monster.c";

int Power;
mixed *Enhancements;
mixed *Data;
static object *CurrEnhancements;
static object Config;
mapping DataHolder;
int titanium, steel, concrete;
static object cc_attack;

void RestoreBase();
void AEnhancement(string name, string path);
void ACurrEnhancement(object ob);
int QPower(status arg);

status
id(string str)
{
  return str == "command center" || str == "center";
}

status
query_npc() { return 1; }

status
query_invis() { return 1;}

void
reset(status arg)
{
  if(!present("globe", this_object()))
    move_object(GLOBE, this_object());
  if(!present("alpha", this_object()))
    move_object("/players/guilds/Rangers/Npc/Alpha.c", this_object());
  if(!present("zordon", this_object()))
    move_object("/players/guilds/Rangers/Npc/Zordon.c", this_object());
  ::reset(arg);
  if (arg) return;
  if(!environment(this_object())) move_object(this_object(),
    "/players/beck/room/mountain2.c");
  RestoreBase();
  Align = "Power Ranger";
  is_npc = 1;
  cap_name = "Command Center";
  set_light(1);
  weapon_class = 0;
  set_wc(500);
  set_ac(100000);
  set_armor_special("Defense");
}

string
short()
{
  return RED+"Power Ranger"+OFF+BLUE+" Command Center"+OFF;
}

status
long()
{
  if(dead)
  {
    write("A pile of rubble.\n");
    return 1;
  }
  if(!present(this_player(),this_object()))
  {
    write("This is a huge building made of steel and concrete.\n\
The walls seem impenetrable to outsiders, and there are\n\
several towers and devices that appear to be formidable weaponry.\n");
  }
  else
  {
    write(
"  This is the main control center of the power rangers.\n\
All around you are computer consoles and strange inventions.\n\
It almost seems as if one could control the entire world from here.\n\
There are so many switches and buttons it almost boggles your mind.\n\
Glancing around you notice one button that looks to be important.\n\
Upon closer inspection you notice it is on the transporter control panel.\n\
You can also 'monitor' the activities of the base, and 'configure' them.\n\
'help' is also available.\n");
  }
  return 1;
}

void
init()
{
  ::init();
  
  if(present(this_player(), this_object()))
  {
    add_action("push","push");
    add_action("Monitor","monitor");
    add_action("Configure","configure");
    add_action("Build","build");
    add_action("Help","help");
    add_action("Vault","vault");
  }
  else
  {
    add_action("Enter","enter");
  }
}

void
attacked_by(object ob)
{
  ::attacked_by(ob);
  if(!( this_object()->query_attack()) ||
      ( (object) this_object()->query_attack() != cc_attack))
  {
    CHANNEL->channel_message(Align, WHITE + "[" + RED + "Command Center" + OFF +
             WHITE + "]" + OFF +
             " Zordon says: The Command Center is under attack from " +
             ob->query_name() + ".\n");
    cc_attack = ob; 
  }
}

void
save_center()
{
  save_object(SAVEDIR+"CommandCenter");
}

void
death()
{
  if (hunter) call_other(hunter, "stop_hunter");
   hunter = 0;
  hunted = 0;
  stop_fight();
  if(this_player()) this_player()->stop_fight();
  tell_room(environment(this_object()), "The Command Center has been destroyed.\n");
  tell_room((this_object()), "The Command Center has been destroyed.\n");
  CHANNEL->channel_message(Align, WHITE + "[" + RED + "Command Center" + OFF +
           WHITE + "]" + OFF + " Zordon says: " + BOLD + RED +
           "The Command Center has been destroyed." + OFF + "\n");
  dieing = 1;
  dead = 1;
  set_heart_beat(0);
  MASTER->ResetPowerPoints(Align);
  Power = 0;
  save_center();
}

status
query_ghost()
{ 
  if(dead) write("Command Center is already destroyed.\n");
  return dead; 
}

string
query_name()
{
  if(dieing)
  {
     dieing = 0;
     return "some mist";
  }
  else
     return "Command Center";
}

status
Enter()
{
  if( (string) this_player()->query_guild_name() != GUILDNAME)
  {
    notify_fail("You can't enter the command center.\n");
    return 0;
  }
  this_player()->move_player("X#" + file_name(this_object()));
  return 1;
}

status
push()
{
  this_player()->move_player("teleport#" + file_name(environment(this_object())));
  return 1;
}

void
RestoreBase()
{
  int i;
  int j;
  int k;
  object ob;
  restore_object(SAVEDIR + "CommandCenter");
  is_npc = 1;
  DataHolder = ([]);
  for(i=0; i<sizeof(Data); i++)
  {
    DataHolder[Data[i]] = ({});
    j = Data[i+1];
    k = 0;
    while(k < j)
    {
      DataHolder[Data[i]] += ({ Data[i+2+k] });
      k++;
    }
    i = i+j+1;
  }
  if( (int) MASTER->QPowerPoints(Align) != Power)
    MASTER->APowerPoints(Power - ((int) MASTER->QPowerPoints(Align)), Align);
  set_living_name("command center");
  for( i=0; i<sizeof(Enhancements); i++)
  {
    j = Enhancements[i+1];
    while(j)
    {
      ob = clone_object(Enhancements[i+2]);
      ob->SBase(this_object());
      ob->SName(Enhancements[i]+" "+j);
      move_object(ob, this_object());
      ob->RestoreEnhancement();
      ACurrEnhancement(ob);
      j--;
    }
    i = i+2;
  }
  if(environment(this_object())) environment(this_object())->set_no_clean(1);
}

void
AEnhancement(string name, string path)
{
  int temp;
  if(!Enhancements) Enhancements = ({});
  temp = member_array(name, Enhancements);
  if(temp != -1) Enhancements[temp+1] += 1;
  else
     Enhancements += ({ name, 1, path });
  save_object(SAVEDIR+"CommandCenter");
}

status
QEnhancementNum(string name)
{
  int temp;
  if(!Enhancements) Enhancements = ({});
  temp = member_array(name, Enhancements);
  if(temp != -1) return Enhancements[temp+1];
  else 
     return 0;
}

void
ACurrEnhancement(object ob)
{
  int temp;
  if(!CurrEnhancements) CurrEnhancements = ({});
  temp = member_array(ob, CurrEnhancements);
  if(temp != -1) return;
  else
     CurrEnhancements += ({ ob });
}

object
QCurrEnhancement(string name)
{
  int i;
  for(i=0;i<sizeof(CurrEnhancements); i++)
  {
    if(CurrEnhancements[i])
      if( (string) CurrEnhancements[i]->QName() == name)
        return CurrEnhancements[i];
  }
  return 0;
} 

void
AData(string name, mixed *data)
{
  int i;
  string *temp;
  int size;
  if(!Data) Data = ({});
  if(!DataHolder) DataHolder = ([]);
  DataHolder[name] = data;
  temp = keys(DataHolder);
  Data = ({});
  for(i=0;i<sizeof(temp);i++)
  {
    Data+= ({ temp[i] });
    size = sizeof(DataHolder[temp[i]]);
    Data += ({ size });
    Data += DataHolder[temp[i]];
  }
  save_object(SAVEDIR+"CommandCenter");
}

mixed
QData(string name)
{
  if(!DataHolder) return 0;
  return DataHolder[name];
}

status
Monitor(string str)
{
  int i;
  int num;
  if(!str)
  {
    num = (int) this_object()->QPower(1);
    write("Pool\tPower: " + num + "\n");
    for (i=0; i<sizeof(CurrEnhancements); i++)
    {
      write((i+1)+"\t");
      write(pad( (string) CurrEnhancements[i]->QName(),27));
      write(CurrEnhancements[i]->QOnline() ? BOLD+GREEN + "Online" + OFF :
            BOLD + RED + "Offline" + OFF);
      write("\tPower: " + CurrEnhancements[i]->QPower(0) + "");
      write("\n");
    }
    write("Total Power: " + QPower(0) + "\n");
    
    return 1;
  }
  if(str == "command center")
  {
    write("Command Center\n");
    write("\nVault: " + money + "\n\n");
    write("Titanium: " + titanium + "\n");
    write("Steel:    " + steel + "\n");
    write("Concrete: " + concrete + "\n");
    write("\nTotal:    " + (titanium + steel + concrete) + "\n");
    return 1;
  }
  i = sizeof(CurrEnhancements);
  if(sscanf(str, "%d", num) !=1)
  {
    tell_object(this_player(),
        "Zordon tells you: \"Pick a number of an object to configure.\"\n");
    return 1;
  }
  if(num <= i)
  {
    CurrEnhancements[num-1]->Monitor();
    return 1;
  }
  else
  {
    tell_object(this_player(),
      "Zordon tells you: \"That is not a valid choice.\"\n");
    return 1;
  }
}

status
Configure(string str)
{
  int i;
  int num;
  if(!str)
  {
    write("Exiting Configuration Mode.\n");
    Config = 0;
    return 1;
  }
  if(!Config)
  {
    i = sizeof(CurrEnhancements);
    if(sscanf(str, "%df", num) !=1)
    {
      write("Pick a number of an object to configure.\n");
      return 1;
    }
    if(num <= i)
    {
      Config = CurrEnhancements[num-1];
      write("Entering Configuration Mode for " +
            CurrEnhancements[num-1]->QName() + ".\n");
       return 1;
    }
    else
    {
      write("That is not a valid choice.\n");
      return 1;
    }
  }
  else
  {
    return (int) Config->Configure(str);
  }
}

status
PowerCheck(string channel)
{
  if(channel == Align)
  {
    if(dead)
    {
      write("The Command Center has been destroyed.\nNo Power may be added.\n");
      return 0;
    }
    return 1;
  }
  return 1;
}

void
APower(int amt, string channel)
{
  if(channel == Align)
  {
    Power = (int) MASTER->QPowerPoints(Align);
    save_object(SAVEDIR+"CommandCenter");
  }
  else if(!channel)
  {
    MASTER->APowerPoints(amt, Align);
  }
}

int
QPower(status arg)
{
  int i;
  int energon;
  if(arg) return (int) MASTER->QPowerPoints(Align);
  energon = (int) MASTER->QPowerPoints(Align);
  for(i=0;i<sizeof(CurrEnhancements);i++)
  {
    energon += (int) CurrEnhancements[i]->QPower(0);
  }
  return energon;
}

string
realm()
{
  if(this_player())
    if( (string) this_player()->query_guild_name() != GUILDNAME)
    {
      return "NT";
    }
    else
    return 0;
}

status
query_NM()
{
  if(this_player())
    if( (string) this_player()->query_guild_name() != GUILDNAME)
    {
      return 1;
    }
  else
    return 0;
}

status
Vault(string str)
{
  int num;
  if(!str)
  {
     write("Vault amount: " + money + "\n");
     return 1;
  }
  if(sscanf(str, "%df", num) !=1)
  {
    tell_object(this_player(),
      "Zordon tells you: \"Pick an amount of money to store in the vault.\"\n");
    return 1;
  }
  if(num > this_player()->query_money())
  {
    tell_object(this_player(),
      "Zordon tells you: \"You don't have that much money.\"\n");
    return 1;
  }
  money += num;
  this_player()->add_money(-num);
  tell_object(this_player(),
    "Zordon tells you: \"" + num + " has been stored in the vault.\"\n");
  save_center();
  return 1;
}

status
Build(string str)
{
  object structure;
  object enhance;
  string enhancename;
  string *all;
  string temp;
  string one, two, three;
  int num, num2, num3, num4;
  int cost, limit;
  if(!str)
  {
    write("You must pick a structure to build.\n");
    write("\
Availible items to build:        Cost:\n\
Concrete                         3000 coins per unit\n\
Steel                            9000 coins per unit\n\
Titanium                        27000 coins per unit\n\
Communications-Tower           100000 coins\n\
Spy-Satellite                  100000 coins\n\
Remote-Locator                 100000 coins\n\
Remote-Camera                  100000 coins\n\
Fire-Suppression-System        100000 coins\n\
Lightning-Rod                  100000 coins\n\
Xenon-Refractor-Shield         800000 coins\n\
Ion-Pulse-Cannon               300000 coins per unit\n\
Solar-Collector                500000 coins per unit\n");
     return 1;
  }
  if(sscanf(str, "%s %df", temp, num) == 2)
  {
    num2 = titanium+steel+concrete;
    if(temp == "titanium")
    {
      if(money < num*27000)
      {
        write("Not enough money to build titanium.\n");
        return 1;
      }
      if(num+titanium > 250)
      {
        num = 250 - titanium;
        write("Amount of titanium being adjusted to "+num+"\n");
      }
      if(num+num2 > 250)
      {
        num3 = 250 - num2;
        titanium += num3;
        num -= num3;
        num2 = titanium+steel+concrete;
      }
      if(num2 == 250 && titanium < 250)
      {
        if(concrete > 0)
        {
          if(concrete > num)
          {
            concrete -= num;
            hit_point -= 2*num;
            titanium += num;
            num4 = num;
            write(num+" concrete was turned to titanium.\n");
            num = 0; 
          }
          else
          {
            num4 = concrete;
            num -= num4;
            hit_point -= 2*num4;
            titanium += num4;
            write(concrete+" concrete was turned to titanium.\n");
            concrete = 0;
          }
        }
        if(num > 0)
        {
          steel -= num;
          hit_point -= 5*num;
          write(num+" steel was turned to titanium.\n");
        }
      }
      else if(num2 == 250 && titanium == 250)
      {
        write("You cannot build any more protection.\n");
        return 1;
      }
      titanium += num;
      write("A total of "+(num3+num+num4)+" titanium was built.\n");
      hit_point += 10*(num+num+num4);
      money -= 27000*(num3+num+num4);
      save_center();
      return 1;
    }
    else
    {
      write("You must also specify an amount.\n");
    }
    if(temp == "steel")
    {
      if(money < num*9000)
      {
        write("Not enough money to build steel.\n");
        return 1;
      }
      if(num+steel+titanium > 250)
      {
        num = 250 - steel-titanium;
        write("Amount of steel being adjusted to "+num+"\n");
      }
      if(num+num2 > 250)
      {
        num3 = 250 - num2;
        steel += num3;
        num -= num3;
        num2 = titanium+steel+concrete;
      }
      if(num2 == 250 && steel+titanium < 250)
      {
        if(concrete > 0)
        {
          if(concrete > num)
          {
            concrete -= num;
            hit_point -= 2*num;
            steel += num;
            num4 = num;
            write(num+" concrete was turned to steel.\n");
            num = 0; 
          }
          else
          {
            num4 = concrete;
            num -= num4;
            hit_point -= 2*num4;
            steel += num4;
            write(concrete+" concrete was turned to steel.\n");
            concrete = 0;
          }
        }
      }
      else if(num2 == 250 && steel+titanium == 250)
      {
        write("You cannot build any more steel protection.\n");
        return 1;
      }
      steel += num;
      write("A total of "+(num3+num+num4)+" steel was built.\n");
      hit_point += 5*(num+num+num4);
      money -= 9000*(num3+num+num4);
      save_center();
      return 1;
    }
    else
    {
      write("You must also specify an amount.\n");
    }
  if(temp == "concrete")
  {
    if(money < num*3000)
    {
      write("Not enough money to build steel.\n");
      return 1;
    }
    if(num+num2 > 250)
    {
      num = 250 - num2;
      write("Amount of concrete being adjusted to "+num+"\n");
    }
    if(num2 == 250)
    {
      write("You cannot build any more concrete protection.\n");
      return 1;
    }
    concrete += num;
    write("A total of "+(num3+num+num4)+" concrete was built.\n");
    money -= 3000*(num3+num+num4);
    hit_point += 2*(num+num+num4);
    save_center();
    return 1;
    }
    else
    {
      write("You must also specify an amount.\n");
    }
  }
  all = files("/players/guilds/Rangers/CommandCenter/*.c");
  temp = str+".c";
  if(sscanf(str, "%s-%s-%s", one, two, three) != 3)
  {
    if(sscanf(str, "%s-%s", one, two) != 2)
    {
      write("Not a valid format.\n");
      return 1;
    }
  }
  if(member_array(temp, all) != -1)
  {
    if(three) enhancename = one+" "+two+" "+three;
     else
       enhancename = one+" "+two;
  }
  else
  {
    write("That is not a structure you can build.\n");
    return 1;
  }
  switch(enhancename)
  {
    case "Xenon Refractor Shield":  cost = 800000; limit = 1; break;
    case "Ion Pulse Cannon":        cost = 300000; limit = 2; break;
    case "Solar Collector":         cost = 500000; limit = 4; break;
    case "Spy Satellite":
    case "Communications Tower":
    case "Remote Locator": 
    case "Remote Camera":
    case "Fire Suppression System":
    case "Lightning Rod":           cost = 100000; limit = 1; break;
    default:                        cost = 10000000000; limit = 0;
  }
  if(this_object()->QEnhancementNum(enhancename) >= limit)
  {
    write("You have already built enough "+enhancename+"'s.\n");
    return 1;
  }
  if(money < cost)
  {
    write("There is not enough money in the vault to build that.\n");
    return 1;
  }
  this_object()->AEnhancement(enhancename, 
    "/players/guilds/Rangers/CommandCenter/" + temp);
  enhance = clone_object("/players/guilds/Rangers/CommandCenter/" + temp);
  money -= cost;
  enhance->SBase(this_object());
  enhance->SName(enhancename + " " +
    this_object()->QEnhancementNum(enhancename));
  enhance->RestoreEnhancement();
  this_object()->ACurrEnhancement(enhance);
  move_object(enhance,this_object());
  save_center();
  tell_object(this_player(),
    "Zordon tells you: \"You have built a new " + enhancename + ".\"\n");
  return 1;
}  

status
Help(string arg)
{
  if(!arg)
  {
    write(
"Command Center functions:\n\n\
  monitor - view status of the base.\n\
  monitor <num> - view status of particular enhancement.\n\
  configure <num> - enter configuration mode for a particular enhancement.\n\
  configure - exit configuration mode.\n\
  vault <amt> - take your money and put it in the command center vault (one way transfer).\n\
  build <item> - add an item to the command center.\n\
  push - leave command center.\n\
  help <topic> - view help on additional topic.\n\n\
Additional topics availible:\n\
  monitor, configure, build\n");
    return 1;
  }
  else if (arg == "monitor")
  {
    write(
"The monitor command allows you to see the status of the whole base or with\n\
the optional <num> modifier, the status of a particular enhancement.\n\
Monitor allows you to see the power of the base (Power Pool) as well as the \n\
power within each enhancement.\n");
    return 1;
  }
  else if (arg == "configure")
  {
    write(
"The configure command allows you to enter a setup/command mode for each \n\
enhancement. You must specify which <num> to modify first.  The list can \n\
be obtained from the 'monitor' command. Once in configuration mode you can \n\
choose from a variety of options.\nYou can look at these options by choosing \
'configure help'.\nTo exit configuration mode just type 'configure'.\n");
     return 1;
  }
  else if (arg == "build")
  {
    write(
"The build command allows you to construct enhancments for the command center.\n\
The items are listed when you type 'build' with no qualifier.\n\
These items vary in functionality.  Some are protection, some are weapons, and some\n\
are other useful items.\n\
The cost is taken directly from the vault at construction time.\n\
Additional help is availible on each item listed by using 'help <item>'\n");
    return 1;
  }
  else if(arg == "concrete")
  {
    write(
"This is the basic building block for the command center defense.\n\
Concrete raises the command centers ability to take damage from enemy attacks.\n\
A total of 250 units of protection can be built.\n\
To see what units are built so far type 'monitor command center'\n");
    return 1;
  }
  else if(arg == "steel")
  {
    write("This has the same functionality as concrete, but offers twice the \
protection.\n");
    return 1;
  }
  else if(arg == "titanium")
  {
    write("Same function as concrete and steel.\n\
It is twice as strong as steel...4 times as strong as concrete.\n");
     return 1;
  }
  else if(arg == "xenon refractor shield")
  {
    write(
"This structure protects the base with a high energy shield.\n\
The more higher the power setting, the more damage it absorbs, and the more\n\
power it uses up.\n\
To build this type 'build Xenon-Refractor-Shield' (case sensitive).\n");
    return 1;
  }
  else if(arg == "ion pulse cannon")
  {
    write(
"This structure destroys the enemy with a high energy pulse.\n\
 The more higher the power setting, the more damage it can do, and the more\n\
 power it uses up.\n\
 To build this type 'build Ion-Pulse-Cannon' (case sensitive).\n");
    return 1;
  }
  else if(arg == "solar collector")
  {
    write(
"This structure harnesses the suns energy to create power.\n\
Over time it will accumulate power which can be transfered into the common pool.\n\
Its ability is affected by the Xenon Refractor Shield.  The higher the shield setting\n\
the less the power the collecter can get.\n\
To build this type 'build Solar-Collector' (case sensitive).\n");
    return 1;
  }
  else
  {
    tell_object(this_player(),
      "Zordon tells you: \"That is not a valid subject.\"\n");
    return 1;
  }
}

int
Defense()
{
  int i,j,k;
  int temp,temp1,temp2;
  int ac;
  ac = (10*titanium)+(5*steel)+(2*concrete);
  if(query_hp() < ac)
  {
    i = ac - (int) this_object()->query_hp();
    if(i/4 > 0) j = i/4;
      if(titanium >= j) titanium -= j;
    else
    {
      j -= titanium;
      titanium = 0;
    }
    i -= (j*4);
    if(i/2 > 0) j = i/2;
    if(steel >= j) steel -= j;
    else
    {
      j -= steel;
      steel = 0;
    }
    i -= (j*2);
    if(i > 0)
      if(concrete >= i) concrete -= i;
    else
    {
      i -= concrete;
      concrete = 0;
    }
    ac = (10*titanium)+(5*steel)+(2*concrete);
    save_center();
  }
  return ac/26;
}
     
/* This is used by the shop etc. */
status
add_money(int m)
{
  if(query_verb() != "vault" && query_verb() != "build")
    return 0;
  money = money + m;
}      
