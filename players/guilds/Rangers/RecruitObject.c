/**************************************************************************
 * The Power Ranger Communicator (Guild Object)                           *
 * Created by Beck/Russ Warren for Nirvana.                               *
 *  Updated by vital/keith for the Rangers                                *
 *  Last changed 3/20/2002                                                *
 **************************************************************************/
#pragma strict_types

#include <ansi.h>
#include "RangerDefs.h"

object recruit;
string sponsor;

status
id(string str) { return str == "recruit object"; }

string
short()
{
  string msg;
  msg = "";
  msg += "A Power Ranger Recruit Object (recruit object)";
  return msg;
}

void
long()
{
  write(format("This communicator is made with a steel case, and has a \
fine quartz crystal. Looking closer you see little blinking lights all \
over the communicator. Type \'its morphin time\' to join the Power \
Rangers.\n"));
}

void
set_sponsor(string arg){ sponsor = arg; }

void
set_recruit(object arg){ recruit = arg; }

status
recruit_ranger()
{
  object communicator;
  if(this_player()->query_guild_name() != 0)
  {
    write("You cannot join the Power Rangers.  You are already in a guild.\n");
    destruct(this_object());
    return 1;
  }

  this_player()->set_guild_name("rangers");
  communicator = clone_object("/players/guilds/Rangers/RangerCommunicator.c");
  move_object(communicator, this_player());
  communicator->SRangerColor("Initiate");
  communicator->SRangerNumber("0");
  communicator->SRangerDino("None");
  communicator->SRangerAnimal("None");
  communicator->SRangerWeapon("None");
  communicator->SOldTitle(this_player()->query_title());
  communicator->SOldPretitle(this_player()->query_pretitle());
  write(format("Zordon tells you: Welcome to the Power Rangers! I am pleased \
you have decided to become part of our orginization. For a period of time you \
will be an initiate This will be a chance for you to prove that you are \
worthy of the ideals that the Power Rangers hold. The Power Rangers are \
given their abilities in order to protect good and destroy evil.  In time \
you learn many skills that will help you to use the power you are given to \
the fullest. \n\nZordon hands you a Communicator. Zordon tells you:  This is \
the device that the Rangers use to communicator with others.  You must learn \
how to use it well, for it has many beneficial functions. Go now and meet the \
other Power Rangers, "+"learn about your communicator, and begin your martial \
arts training.  You must do all this as well as begin to start fighting the \
forces of evil in order to become a true Power Ranger. \n\nGood Luck, and may \
the Power protect you!\n"));
  communicator->SaveRanger();
  communicator->guild_login();
  communicator->init();
  GLOBE->add_mn(1);
  if(present("honor_ranger_communicator",this_player()))
  {
    destruct(present("honor_ranger_communicator",this_player()));
  }
  CHANNEL->channel_message("Power Ranger", BLUE+"["+OFF+RED+"Power Ranger"+OFF+BLUE+"] "+OFF+recruit->query_name()+" has become a Power Ranger, sponsored by "+sponsor+".\n");
  GLOBE->Color1();
  destruct(this_object());
  return 1;
}


void
init()
{

  add_action("recruit_ranger","its_morphin_time");
}

status
get(){ return 1;}

status
drop(){ return 1;}
