#include <ansi.h>
#include "RangerDefs.h"
#include "/obj/user/dt_stamp.h"

string messages, new_hd, new_body;
int num_messages;
object who;
int *ranger_time;
string *ranger_inactive;
string *ranger_purged;
string *ranger_types;
string *ranger_names;
string *ranger_colors;
string *ranger_animals;
string *ranger_dinos;
string *ranger_weapons;
string *ranger_levels;
string *ranger_numbers;
string *colors;
string *animals;
string *dinos;
string *weapons;
string *numbers;
int member_number;

mapping ranger;

void headers();
status remove_ranger_purged(string str);
status add_ranger_purged(string str);
status update_ranger_roster();
status join_power_rangers();
status save_globe();
status Dino1();
status Weapon1();


status
id(string str) { return str=="globe" || str=="ViewingGlobe"; }

void
reset(status arg)
{
  if (arg) return;
  ranger = ([]);
  restore_object(SAVEDIR + "Globe");
}

string
short()
{
  return "The Viewing Globe";
}

status
long()
{
  write("To see a list of guild members type 'Rangers'.\n");
  if( (string) this_player()->query_guild_name() == GUILDNAME 
  || (string)this_player()->query_real_name() == "fred")
  {
    write(format("\
  There are currently " + member_number + " Power Rangers. The maximum \
number of guild members allowed is "+MAXGUILD+". To leave the guild type \
\'leave_rangers\', but I hope you won't. You can set up new notes with the \
command \'note headline\'. Read a note with \'read num\'.\n"));
    if(num_messages == 0)
    {
      write("It is empty.\n");
      return 1;
    }
    write("The bulletine board contains " + num_messages);
    if (num_messages == 1) write(" note:\n\n");
    else
      write(" notes:\n\n");
    say(call_other(this_player(), "query_name") +
      " studies the Viewing Globe.\n");
    headers();
    return 1;
  }
  write(format("Welcome to the Power Ranger Command Center. If you wish to \
become a Power Ranger just type 'info' for information. There are currently " +
member_number + " Power Rangers. The maximum number of guild members allowed \
is " + MAXGUILD + ". If you wish to join the guild type 'join'.\nNote: Type \
\'restore\' to regain your lost guild object. Have a nice day.\n"));
  return 1;
}

void
init()
{
  int glevel;
  int gexp;
  add_action("ranger_info","info");
  add_action("test","Rangers");
  add_action("join_honorary","join_honorary");
  add_action("restore_object","restore");
  if( (string) this_player()->query_guild_name() == GUILDNAME
  || (string) this_player()->query_real_name() == "fred")
  {
    if(member_array( capitalize( (string) this_player()->query_real_name()),
      ranger_purged) != -1)
    {
      destruct(present("RangerCommunicator",this_player()));
      write("You have not played in over 45 days and have been removed \
from the Rangers.\n");
      glevel = (int) this_player()->query_guild_rank();
      gexp = (int) this_player()->query_guild_exp();
      this_player()->add_guild_exp(-gexp);
      this_player()->add_exp(gexp);
      this_player()->set_guild_name("none");
      this_player()->add_guild_rank(-glevel);
      this_player()->set_guild_file(0);
      this_player()->set_home("/room/church");
      rm(RANGERDIR+this_player()->query_real_name()+".o");
      remove_ranger_purged(capitalize(
        (string) this_player()->query_real_name()));
      return;
    }
    add_action("leave_power_rangers","leave_rangers");
    add_action("new"); add_verb("note");
    add_action("read"); add_verb("read");
     /*
    add_action("remove"); add_verb("remove");
    */
    add_action("Animal1"); add_verb("Animal");
    add_action("Weapon1"); add_verb("Weapon");
    if(this_player()->query_level() < 20 &&
      (string) this_player()->query_guild_name() == GUILDNAME)
    {
      update_ranger_roster();
    }
  }
  if( ( (string) this_player()->query_real_name() == "beck") ||
    ( (string) this_player()->query_real_name() == "illarion") ||
    ( (string) this_player()->query_real_name() == "vital") ||
    ( (string) this_player()->query_real_name() == "angel") ||
    ( (string) this_player()->query_real_name() == "fred") )
  {
    add_action("remove"); add_verb("remove");
    add_action("test","TEST");
    add_action("set_time","STIME");
    add_action("add_time","ATIME");
    add_action("remove_time","RTIME");
    add_action("set_ranger_purged","SPURGED");
    add_action("add_ranger_purged","APURGED");
    add_action("remove_ranger_purged","RPURGED");
    add_action("set_ranger_inactive","SINACTIVE");
    add_action("add_ranger_inactive","AINACTIVE");
    add_action("remove_ranger_inactive","RINACTIVE");
    add_action("see_time","TIME");
    add_action("see_inactive","INACTIVE");
    add_action("see_purged","PURGED");
    add_action("remove_from_roster","REMOVE");
    add_action("set_ranger_type","SRANGERTYPE");
    add_action("add_ranger_type","ARANGERTYPE");
    add_action("set_number","SNUMBER");
    add_action("set_mn","SMEMBERNUM");
    add_action("update_ranger_roster","UPDATE");
    add_action("add_color","ADDCOLOR");
    add_action("add_animal","ADDANIMAL");
    add_action("add_weapon","ADDWEAPON");
    add_action("remove_color","REMCOLOR");
    add_action("remove_animal","REMANIMAL");
    add_action("remove_weapon","REMWEAPON");
    add_action("remove_dino","RDINO");
    add_action("add_dino","ADINO");
    add_action("see_color","COLOR");
    add_action("see_animal","ANIMAL");
    add_action("see_dino","DINO");
    add_action("see_weapon","WEAPON");
    add_action("add_mn","AMEMBERNUM");
    add_action("add_ranger_number","ARANNUMBER");
    add_action("set_ranger_number","SRANNUMBER");
    add_action("see_number","NUMBER");
    add_action("add_number","ANUMBER");
    add_action("remove_number","RNUMBER");
  }
  if(present("ranger_communicator",this_player()))
  {
    join_power_rangers();
  }
}


int
test()
{
  string *files;
  string rname, rtype, rbelt, rcolor, rtime;
  int s, r, p;
  write(colour_pad(" ",30));
  write("POWER RANGERS\n");
  write(colour_pad("Name",12));
  write(colour_pad("Type",13));
  write(colour_pad("Belt",10));
  write(colour_pad("Color",14));
  write(colour_pad("Last In",12));
  write(colour_pad("Leadership",12));
  write("\n\n");
  files = get_dir(RANGERDIR + "*.save");
  for(s = 0; s < sizeof(files); s++)
  {
    for(r = 1; r < 7; r++)    /* this is convoluted */
    {
      switch(r)
      {
        case 1: p = 12; break;
        case 2: p = 13; break;
        case 3: p = 10; break;
        case 4: p = 14; break;
        case 5: p = 12; break;
        case 6: p = 12; break;
        default: p = 12;
      }
      write(
        colour_pad(
        implode(
        explode(
        read_file(RANGERDIR + files[s], r),
        "\n"),
        ""),
        p));
    }
    write("\n");
  }
  return 1;
}

status
get() { return 0; }

int
query_weight() { return 0; }

int
query_value() { return 5000; }

status
ranger_info(string str)
{
  "/players/guilds/Rangers/Commands/Ranger.c"->ranger_help(str);
  write("TYPE 'info <subject>' (instead of 'ranger <subject>')!!!!\n");
  return 1;
}

void
headers()
{
  string hd, body, rest;
  int i, tmp;

  i = 1;
  rest = messages;
  while(rest != 0 && rest != "")
  {
    tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
    if (tmp != 2 && tmp != 3)
    {
      write("Corrupt.\n");
      return;
    }
    write(i + ":\t" + hd + "\n");
    i += 1;
  }
}

status
new(string hd)
{
  if (!hd)
    return 0;
  if (who && environment(who) == environment(this_object()))
  {
    write(call_other(who, "query_name") + " is busy writing.\n");
    return 1;
  }
  if (num_messages == 50)
  {
    write("You have to remove an old message first.\n");
    return 1;
  }
  if (strlen(hd) > 50)
  {
    write("Too long header to fit the paper.\n");
    return 1;
  }
  new_hd = hd;
  input_to("get_body");
  write("Give message, and terminate with '**'.\n");
  write("]");
  new_body = "";
  return 1;
}

void
get_body(string str)
{
  if (str == "**")
  {
    if((string) this_player()->query_real_name() == "fred")
    {
      new_hd = new_hd + "(" + capitalize( (string) call_other(this_player(),
      "query_real_name")) + " the Rubik's Cube TempRanger" + "\)";
    }
    else
    {
    new_hd = new_hd + "(" + capitalize( (string) call_other(this_player(),
      "query_real_name")) + " the " + COMM->COLOR + " Ranger" + "\)";
    }
    new_body = new_body + "\n"+"[" + DT + "]\n";
    messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
    num_messages += 1;
    new_body = 0;
    new_hd = 0;
    save_globe();
    write("Ok.\n");
    who = 0;
    return;
  }
  new_body = new_body + str + "\n";
  write("]");
  input_to("get_body");
}

status
read(string str)
{
  string hd, body, rest;
  int i, tmp;

  if (str == 0 || (sscanf(str, "%d", i) != 1 &&
    sscanf(str, "note %d", i) != 1))
    return 0;
  if (i > num_messages)
  {
    write("Not that number of messages.\n");
    return 1;
  }
  rest = messages;
  while(rest != 0 && rest != "")
  {
    i -= 1;
    tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
    if (tmp != 2 && tmp != 3)
    {
      write("Corrupt message.\n");
      return 0;
    }
    if (i == 0)
    {
      say(call_other(this_player(), "query_name") +
        " reads a note titled '" + hd + "'.\n");
      write("The note is titled '" + hd + "':\n\n");
      write(body);
      return 1;
    }
  }
  write("Hm. This should not happen.\n");
}

status
remove(string str)
{
  string hd, body, rest;
  string jun2,jun;
  int i, tmp;

  if (str == 0 || (sscanf(str, "%d", i) != 1 &&
    sscanf(str, "note %d", i) != 1))
    return 0;
  if (i > num_messages)
  {
    write("Not that number of messages.\n");
    return 1;
  }
  rest = messages;
  jun2 = messages;
  messages = "";
  while(rest != 0 && rest != "")
  {
    i -= 1;
    tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
    if (tmp != 2 && tmp != 3)
    {
      write("Corrupt message.\n");
      return 0;
    }
    if (i == 0)
    {
      if(sscanf(hd, "%sboltar", jun) == 1 &&
        (string) this_player()->query_real_name() != "boltar")
      {
        write("You cannot remove this message.\n");
        messages=jun2;
        return 1;
      }
      say(call_other(this_player(), "query_name") +
        " removed a note titled '" + hd + "'.\n");
      write("Ok.\n");
      messages = messages + rest;
      num_messages -= 1;
      save_globe();
      return 1;
    }
    messages = messages + hd + ":\n**\n" + body + "\n**\n";
  }
  write("Hm. This should not happen.\n");
}

status
set_number(string str)
{
  numbers = ({ str });
  save_globe();
  return 1;
}

status
add_number(string str)
{
  numbers += ({ str });
  save_globe();
  return 1;
}

status
remove_number(string str)
{
  numbers -= ({ str });
  save_globe();
  return 1;
}

status
set_time(string str)
{
  ranger_time = ({ str });
  save_globe();
  return 1;
}

status
add_time(string str)
{
  ranger_time += ({ str });
  save_globe();
  return 1;
}

status
remove_time(string str)
{
  ranger_time -= ({ str });
  save_globe();
  return 1;
}

status
set_ranger_number(string str)
{
  ranger_numbers = ({ str });
  save_globe();
  return 1;
}

status
add_ranger_number(string str)
{
  ranger_numbers += ({ str });
  save_globe();
  return 1;
}

status
set_ranger_purged(string str)
{
  ranger_purged = ({ str });
  save_globe();
  return 1;
}

status
add_ranger_purged(string str)
{
  ranger_purged += ({ str });
  save_globe();
  return 1;
}

status
remove_ranger_purged(string str)
{
  ranger_purged -= ({ str });
  save_globe();
  return 1;
}

status
set_ranger_inactive(string str)
{
  ranger_inactive = ({ str });
  save_globe();
  return 1;
}

status
add_ranger_inactive(string str)
{
  ranger_inactive += ({ str });
  save_globe();
  return 1;
}

status
remove_ranger_inactive(string str)
{
  ranger_inactive -= ({ str });
  save_globe();
  return 1;
}

status
add_dino(string str)
{
  dinos += ({ str });
  save_globe();
  return 1;
}

status
remove_dino(string str)
{
  dinos -= ({ str });
  save_globe();
  return 1;
}

int
query_mn(){ return member_number; }

status
set_mn(string num)
{
  int i;
  if(sscanf(num, "%d", i) !=1)
  {
    return 1;
  }
  member_number = i;
  save_globe();
  return 1;
}

status
add_mn(mixed num)
{
  int i;
  if(!previous_object()->is_player() && intp(num) )
  {
    member_number += num;
    save_globe();
    return 1;
  }
  if(sscanf(num, "%d", i) !=1)
  {
    return 1;
  }
  member_number += i;
  save_globe();
  return 1;
}

status
add_color(string str)
{
  colors += ({ str });
  save_globe();
  return 1;
}

status
set_ranger_type(string str)
{
  ranger_types = ({ str });
  return 1;
}

status
add_ranger_type(string str)
{
  ranger_types += ({ str });
  save_globe();
  return 1;
}

status
add_animal(string str)
{
  animals += ({ str });
  save_globe();
  return 1;
}

status
add_dinos(string str)
{
  dinos += ({ str });
  save_globe();
  return 1;
}

status
remove_dinos(string str)
{
  dinos -= ({ str });
  save_globe();
  return 1;
}

status
add_weapon(string str)
{
  weapons += ({ str });
  save_globe();
  return 1;
}

status
remove_color(string str)
{
  colors -= ({ str });
  save_globe();
  return 1;
}

status
remove_animal(string str)
{
  animals -= ({ str });
  save_globe();
  return 1;
}

status
remove_weapon(string str)
{
  weapons -= ({ str });
  save_globe();
  return 1;
}

status
see_number()
{
  int i;
  for(i=0; i<sizeof(numbers); i++)
  {
    write(numbers[i]);
    write(", ");
  }
  write("\n");
  return 1;
}

status
see_color()
{
  int i;
  for(i=0; i<sizeof(colors); i++)
  {
    write(colors[i]);
    write(", ");
  }
  write("\n");
  return 1;
}

status
see_dino()
{
  int i;
  for(i=0; i<sizeof(dinos); i++)
  {
    write(dinos[i]);
    write(", ");
  }
  write("\n");
  return 1;
}

status
see_animal()
{
  int i;
  for(i=0; i<sizeof(animals); i++)
  {
    write(animals[i]);
    write(", ");
  }
  write("\n");
  return 1;
}

status
see_weapon()
{
  int i;
  for(i=0; i<sizeof(weapons); i++)
  {
    write(weapons[i]);
    write(", ");
  }
  write("\n");
  return 1;
}

status
see_purged()
{
  int i;
  for(i=0;i<sizeof(ranger_purged);i++)
  {
    write(ranger_purged[i]);
    write(", ");
  }
  write("\n");
  return 1;
}

status
see_inactive()
{
  int i;
  for(i=0;i<sizeof(ranger_inactive);i++)
  {
    write(ranger_inactive[i]);
    write(", ");
  }
  write("\n");
  return 1;
}

status
see_time()
{
  int i;
  for(i=0; i<sizeof(ranger_time); i++)
  {
    write(ranger_time[i]);
    write(", ");
  }
  write("\n");
  return 1;
}

status
join_honorary()
{
  if(COMM)
  {
    write("You are a Power Ranger!");
    return 0;
  }
  if( (string) this_player()->query_guild_name() == "dark rangers")
  {
    write("Your guild will never be an Ally of the Power Rangers!\n");
    return 1;
  }
  if( (string) this_player()->query_guild_name() == "shardak" ||
    (string) this_player()->query_guild_name() == "cyberninja")
  {
    write("Your guild will never be an Ally of the Rangers!\n");
    return 0;
  }
  if(!present("honor_ranger_communicator"), this_player())
  {
    move_object( 
      clone_object("/players/guilds/Rangers/HonorRangerCommunicator.c"),
      this_player());
    return 1;
  }
  return 0;
}

status
join_power_rangers()
{
  int k,jjj,hhh;
  object communicator;
  if(present("ranger_communicator", this_player()))
  {
    write("Converting to new power ranger...");
    jjj = 0 - (int) this_player()->query_guild_exp();
    call_other(this_player(),"add_guild_exp",jjj);
    hhh = 0 - (int) this_player()->query_guild_rank();
    this_player()->add_guild_rank(hhh);
    this_player()->set_guild_name(0);
    this_player()->set_guild_file(GUILDOBJ);
    rm(RANGERDIR+this_player()->query_real_name()+".o");
    this_player()->add_exp(-jjj);
    destruct(present("ranger_communicator",this_player()));
    write("Conversion Complete.\n");
  }
  if(this_player()->query_npc() || this_player()->is_kid())
  {
    return 0;
  }
  if(this_player()->query_level() > 19)
  {
    write("Wizards are not allowed to join, because of errors that will\n\
occur due to their level.\n");
    write("Please do not clone a guild object.  \nClone \ HonorRangerCommunicator.c instead.\n");
    return 1;
  }
  if(member_number == 50)
  {
    write("The Guild has already reached its maximum number of members.\n\
You will have to try to join some other time.\n");
    return 1;
  }

  if(this_player()->query_guild_exp() > 0)
  {
    write("You are already in a guild.  \n\
If this is not correct mail Beck.\n");
    return 1;
  }
  if(this_player()->query_level() < 5)
  {
    write("You need to be at least level 5 to join.\n");
    return 1;
  }
  if(this_player()->query_level() > 10)
  {
    write("You can't be above level 10 to initially join.  If you are \
willing to\ndrop to level 10 mail Beck.\n");
    return 1;
  }
  this_player()->set_guild_name(GUILDNAME);
  this_player()->set_guild_file(GUILDOBJ);
  communicator = clone_object(GUILDOBJ);
  move_object(communicator, this_player());
  communicator->SRangerColor("Initiate");
  communicator->SRangerNumber("0");
  communicator->SRangerDino("None");
  communicator->SRangerAnimal("None");
  communicator->SRangerWeapon("None");
  communicator->SKarateLevel(0);
  communicator->SOldTitle(this_player()->query_title());
  communicator->SOldPretitle(this_player()->query_pretitle());
  communicator->SRangerTypes("initiate");
  communicator->SSkills("power");
  communicator->ASkills("skills");
  communicator->ASkills("ranger");
  communicator->ASkills("time");
  communicator->ASkills("rsc");
  communicator->SDefense("block");
  communicator->SOffense("chop");
  communicator->SUnlearnedSkills("rwho");
  communicator->AUnlearnedSkills("practice");
  communicator->AUnlearnedSkills("generate");
  communicator->AUnlearnedSkills("study");
  communicator->AUnlearnedSkills("white");
  communicator->AUnlearnedSkills("dino");
  communicator->AUnlearnedSkills("shiho-nage");
  communicator->AUnlearnedSkills("irimi-nage");
  write("Zordon tells you: Welcome to the Power Rangers!\n"+
    "I am pleased you have decided to become part of our orginization.\n"+
    "For a period of time you will be an initiate\n"+
    "This will be a chance for you to prove that you are worthy\n"+
    "of the ideals that the Power Rangers hold.\n"+
    "The Power Rangers are given their abilities in order to protect good\n"+
    "and destroy evil.  In time you learn many skills that will help\n"+
    "you to use the power you are given to the fullest.\n"+
    "\n"+"Zordon hands you a Communicator.\n"+
    "Zordon tells you:  This is the device that the Rangers use to\n"+
    "communicator with others.  You must learn how to use\n"+
    "it well, for it has many beneficial functions.\n"+
    "Go now and meet the other Power Rangers, learn about your communicator,\n"+
    "and begin your martial arts training.  You must do all this as\n"+
    "well as begin to start fighting the forces of evil in order\n"+
    "to become a true Power Ranger.\n"+
    "Good Luck, and may the Power protect you!\n\n");
  write("Please log out of Nirvana and back in again for changes to take \
effect.\n\n");
  communicator->SaveRanger();
  communicator->guild_login();
  communicator->init();
  this_player()->add_guild_exp(100);
  member_number += 1;
  save_globe();
  init();
  if(present("honor_ranger_communicator",this_player()))
  {
    destruct(present("honor_ranger_communicator",this_player()));
  }
  return 1;
}

status
restore_object()
{
  if(COMM)
  {
    write("You do not need to restore anything.\n");
    return 1;
  }
  if( (string) this_player()->query_guild_name() != GUILDNAME)
  {
    write("This is for Rangers guild members only.\n");
    return 1;
  }
  write("Restoring your guild object!!!\n");
  move_object(clone_object(GUILDOBJ), this_player());
  COMM->guild_login();
  COMM->init();
  return 1;
}


Color1()
{
  int k;
  write("It is time decide on your Ranger Color.\nYou may choose from \
the following list.\n\n");
  for(k=0; k<sizeof(colors); k++)
  {
    write(colors[k]);
    write(", ");
  }
  write("\n");
  write("To choose your color type ' <name of color from list>'.\nMake sure \
you capitalize the first letter of the color you choose.\n");
  input_to("color");
  return 1;
}

status
color(string str)
{
  int k;
  if( (string) COMM->QRangerColor() == "Initiate")
  {
    for(k=0; k<sizeof(colors); k++)
    {
      if(colors[k] == str)
      {
        COMM->SRangerColor(capitalize(str));
        write("Your new color is set.\n");
        colors -= ({ str });
        save_globe();
        Dino1();
        return 1;
      }
    }
    write("That is not a color you can choose.  Write Beck if you want it approved.\n");
    input_to("color");
    return 1;
  }
  write("Your color is already set.\n");
  return 1;
}

status
Animal1()
{
  int k;
  write("\nNow you are to choose an animal that best exemplifies your \
character.\nYou may choose from the list presented to you.\n\n");
  for(k=0; k<sizeof(animals); k++)
  {
    write(animals[k]);
    write(", ");
  }
  write("\nTo choose your animal name type ' <name of animal>'.\n");
  input_to("animal");
  return 1;
}

status
animal(string str)
{
  int k;
  if( (string) COMM->QRangerAnimal() == "None")
  {
    for(k=0; k<sizeof(animals); k++)
    {
      if(animals[k] == str)
      {
        COMM->SRangerAnimal(capitalize(str));
        write("Your new animal is set.\n");
        save_globe();
        Weapon1();
        return 1;
      }
    }
    write("That is not a animal you can choose.  Write Beck if you want it approved.\n");
    input_to("animal");
    return 1;
  }
  write("Your animal is already set.\n");
  return 1;
}

status
Dino1()
{
  int k;
  write("\nIt is now time to choose your personal Dinozord.\nChoose a Dinozord \
that best exemplifies yourself.\n\n");
  for(k=0; k<sizeof(dinos); k++)
  {
    write(dinos[k]);
    write(", ");
  }
  write("\nTo choose your dinozord name type '<name of thunderzord>'.\n");
  input_to("dino");
  return 1;
}

status
dino(string str)
{
  int k;
  if( (string) COMM->QRangerDino() == "None")
  {
    for(k=0; k<sizeof(dinos); k++)
    {
      if(dinos[k] == str)
      {
        COMM->SRangerDino(capitalize(str));
        write("Your new dinozord is set.\n");
        save_globe();
        COMM->SaveRanger();
        return 1;
      }
    }
    write("That is not a dinozord you can choose.  Write Beck if you want \
it approved.\n");
    input_to("dino");
    return 1;
  }
  write("Your dinozord is already set.\n");
  return 1;
}

status
Weapon1()
{
  int k;
  write("\nNow choose your weapon that you will bring into battle with you.\n");
  for(k=0; k<sizeof(weapons); k++)
  {
    write(weapons[k]);
    write(", ");
  }
  write("\nTo choose your weapon name type '<name of weapon>'.\n");
  input_to("weapon");
  return 1;
}

status
weapon(string str)
{
  int k;
  if( (string) COMM->QRangerWeapon() == "None")
  {
    for(k=0; k<sizeof(weapons); k++)
    {
      if(weapons[k] == str)
      {
        COMM->SRangerWeapon(capitalize(str));
        write("Your new weapon is set.\n");
        save_globe();
        COMM->SaveRanger();
        return 1;
      }
    }
    write("That is not a weapon you can choose.  Write Beck if you want it \
approved.\n");
    input_to("weapon");
    return 1;
  }
  write("Your weapon is already set.\n");
  return 1;
}

status
Number1()
{
  int k;
  write("\nNow choose your number.\n\n");
  for(k=0; k<sizeof(numbers); k++)
  {
    write(numbers[k]);
    write(", ");
  }
  write("\nTo choose your number type '<number>'.\n");
  input_to("number");
  return 1;
}

status
number(string str)
{
  int k;
  if( (string) COMM->QRangerNumber() == "0")
  {
    for(k=0; k<sizeof(numbers); k++)
    {
      if(numbers[k] == str)
      {
        COMM->SRangerNumber(str);
        write("Your new number is set.\n");
        save_globe();
        COMM->SaveRanger();
        return 1;
      }
    }
    write("That is not a number you can choose.  Write Beck if you want it \
approved.\n");
    input_to("number");
    return 1;
  }
  write("Your number is already set.\n");
  return 1;
}

status
leave_power_rangers()
{
  if(!present("RangerCommunicator", this_player()))
  {
    write("You are not a Power Ranger\n");
    return 1;
  }
  write("Are you sure you want to leave the Power Rangers?  Yes/No: ");
  input_to("verify_leave_power_rangers");
  return 1;
}

status
verify_leave_power_rangers(string str)
{
  int i;
  int exp;
  if(!str || (str != "yes" && str != "no"))
  {
    write("You want to leave the Power Rangers?  Yes/No: ");
    input_to("verify_leave_power_rangers");
    return 1;
  }
  if(str == "yes")
  {
    string cl,wo,an,th;
    string nu;
    int hh,jj;
    write("Very well then.  We will miss you.\n");
    exp = (int) this_player()->query_exp();
    exp = exp/6;
    jj = 0 - (int) this_player()->query_guild_exp();
    call_other(this_player(),"add_guild_exp",jj);
    hh = 0 - (int) this_player()->query_guild_rank();
    this_player()->add_exp(-exp);
    this_player()->add_guild_rank(hh);
    this_player()->set_guild_name(0);
    this_player()->set_guild_file(0);
    this_player()->set_home("/room/church");
    cl = (string) COMM->COLOR;
    wo = (string) COMM->WEAPON;
    an = (string) COMM->ANIMAL;
    th = (string) COMM->DINO;
    nu = (string) COMM->NUMBER;
    member_number -= 1;
    if(cl != "Initiate")
    {
      colors += ({ cl });
    }

    ranger_names -= ({"Beck"});
    ranger_levels -= ({"Gold"});
    ranger_types -= ({"Supreme"});
    ranger_colors -= ({"Rainbow"});
    ranger_animals -= ({"Goldfinch"});
    ranger_dinos -= ({"Golden Eagle"});
    ranger_time -= ({2000});
    for(i=0; i < sizeof(ranger_names); i++)
    {
      if(ranger_names[i] == (string) this_player()->query_name())
      {
        ranger_names[i] = "Beck";
        ranger_types[i] = "Supreme";
        ranger_colors[i] = "Rainbow";
        ranger_levels[i] = "Gold";
        ranger_animals[i] = "Goldfinch";
        ranger_dinos[i] = "Golden Eagle";
        ranger_time[i] = 2000;
      }
    }
    destruct(present("RangerCommunicator",this_player()));
    rm(RANGERDIR + this_player()->query_real_name() + ".o");
    save_globe();
    return 1;
  }
  if(str == "no")
  {
    write("Good.  We would have missed you.\n");
    return 1;
  }
  return 1;
}

status
save_globe()
{
  save_object(SAVEDIR + "Globe");
  return 1;
}

status
remove_from_roster(string str)
{
  int i;
  ranger_names -= ({"Beck"});
  ranger_levels -= ({"Gold"});
  ranger_types -= ({"Supreme"});
  ranger_colors -= ({"Rainbow"});
  ranger_animals -= ({"Goldfinch"});
  ranger_dinos -= ({"Golden Eagle"});
  ranger_time -= ({2000});
  member_number -= 1;
  for(i=0; i<sizeof(ranger_names); i++)
  {
    if(ranger_names[i] == str)
    {
      ranger_names[i] = "Beck";
      ranger_types[i] = "Supreme";
      ranger_colors[i] = "Rainbow";
      ranger_levels[i] = "Gold";
      ranger_animals[i] = "Goldfinch";
      ranger_dinos[i] = "Golden Eagle";
      ranger_time[i] = 2000;
    }
  }
  add_ranger_purged(str);
  return 1;
}

status
ranger_roster()
{
  int i;
  write(pad(" ",35));
  write("POWER RANGERS\n");
  write(pad("Name",12));
  write(pad("Type",9));
  write(pad("Color",10));
  write(pad("Belt",7));
  write(pad("Dino",18));
  write(pad("Animal",15));
  write("\n\n");
  for(i=0; i<sizeof(ranger_names); i++)
  {
    if(member_array(ranger_names[i],ranger_inactive) == -1)
    {
      write(pad(ranger_names[i],12));
      write(pad(ranger_types[i],9));
      if(i > sizeof(ranger_colors)) ranger_colors += ({ "*" });
      if(i > sizeof(ranger_levels)) ranger_levels += ({ "*" });
      if(i > sizeof(ranger_dinos)) ranger_dinos += ({ "*" });
      if(i > sizeof(ranger_animals)) ranger_animals += ({ "*" });
      write(pad(ranger_colors[i],10));
      write(pad(ranger_levels[i],7));
      write(pad(ranger_dinos[i],18));
      write(pad(ranger_animals[i],15));
      write("\n");
    }
  }
  return 1;
}

status
update_ranger_roster()
{
  int i;
  return 1;
  if(member_array(capitalize( (string) this_player()->query_real_name()),
    ranger_names) == -1)
  {
    if( (string) this_player()->query_name() == "some mist"){ return 0; }
    ranger_names += ({ capitalize( (string) this_player()->query_real_name()) });
    ranger_types += ({ "Initiate" });
    ranger_colors += ({ COMM->COLOR });
    ranger_levels += ({ "None" });
    ranger_animals += ({ COMM->ANIMAL });
    ranger_dinos += ({ COMM->DINO });
    ranger_time += ({ time() });
    save_globe();
    return 1;
  }
  for(i=0; i<sizeof(ranger_names); i++)
  {
    if(ranger_names[i] ==
      capitalize( (string)this_player()->query_real_name()))
    {
      if(COMM->QuerySkillLevel("morph") < 90) ranger_types[i] = "Galaxy";
      if(COMM->QuerySkillLevel("morph") < 80) ranger_types[i] = "Space";
      if(COMM->QuerySkillLevel("morph") < 70) ranger_types[i] = "Rescue";
      if(COMM->QuerySkillLevel("morph") < 60) ranger_types[i] = "Turbo";
      if(COMM->QuerySkillLevel("morph") < 50) ranger_types[i] = "Zeo";
      if(COMM->QuerySkillLevel("morph") < 40) ranger_types[i] = "Ninja";
      if(COMM->QuerySkillLevel("morph") < 30) ranger_types[i] = "Thunder";
      if(COMM->QuerySkillLevel("morph") < 20) ranger_types[i] = "Dino";
      if(COMM->QuerySkillLevel("morph") < 10) ranger_types[i] = "Initiate";
      ranger_colors[i] = (string) COMM->COLOR;

      if(COMM->QuerySkillLevel("combat") > 79){ ranger_levels[i] = "Black"; }
      else if(COMM->QuerySkillLevel("combat") > 69)
      {
        ranger_levels[i] = "Brown";
      }
      else if(COMM->QuerySkillLevel("combat") > 59)
      {
        ranger_levels[i] = "Purple";
      }
      else if(COMM->QuerySkillLevel("combat") > 49)
      {
        ranger_levels[i] = "Blue";
      }
      else if(COMM->QuerySkillLevel("combat") > 39)
      {
        ranger_levels[i] = "Green";
      }
      else if(COMM->QuerySkillLevel("combat") > 29)
      {
        ranger_levels[i] = "Red";
      }
      else if(COMM->QuerySkillLevel("combat") > 19)
      {
        ranger_levels[i] = "Orange";
      }
      else if(COMM->QuerySkillLevel("combat") > 9)
      {
        ranger_levels[i] = "Yellow";
      }
      else if(COMM->QuerySkillLevel("combat") > 0)
      {
        ranger_levels[i] = "White";
      }
      else
      {
        ranger_levels[i] = "None";
      }
      if( (string) this_player()->query_name() == "Beck")
        ranger_levels[i] = "Gold";
      ranger_animals[i] = (string) COMM->ANIMAL;
      ranger_dinos[i] = (string) COMM->DINO;
      ranger_time[i] = time();
      save_globe();
    }
  }
  return 1;
}