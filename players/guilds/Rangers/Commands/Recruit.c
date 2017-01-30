#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

string *Banished;

status
RangerPower(string str, string align)
{

  string person;
  string type;
  object recruit;
  object comm, prev_obj;

  prev_obj = previous_object();

  restore_object(RANGERDIR[1..strlen(RANGERDIR)-1]+"BANISHED");

  if(!Banished)
  {
    Banished = ({}
    );
  }

  if(!str)
  {
    tell_object(this_player(),
      "Zordon tells you: \"Syntax is 'recruit <person> <type>'.\"\n");
    return 1;
  }
  if(sscanf(str, "%s %s", person, type) != 2)
  {
    tell_object(this_player(),
      "Zordon tells you: \"Syntax is 'recruit <person> <type>'.\"\n");
    return 1;
  }
  if(type == "ranger")
  {
    if(prev_obj->QuerySkillLevel("leadership") < 15)
      return 0;

    if("/players/guilds/Rangers/ViewingGlobe.c"->query_mn() >= MAXGUILD)
    {
      tell_object(this_player(),
        "Zordon tells you: \"The guild is full.\"\n");
      return 1;
    }
    if(!present(person, environment(this_player())))
    {
      tell_object(this_player(),
        "Zordon tells you: \"That person is not present.\"\n");
      return 1;
    }
    recruit = present(person, environment(this_player()));

    if(!recruit->is_player())
    {
      tell_object(this_player(),
        "Zordon tells you: \"You can only recruit players to become \
rangers.\"\n");
      return 1;
    }

    if(member_array(recruit->query_real_name(), Banished) != -1)
    {
      tell_object(this_player(),
        "Zordon tells you: \"That person has been Banished, and may not become \
a Power Ranger.\"\n");
      return 1;
    }

    if(recruit->query_guild_name() != 0)
    {
      tell_object(this_player(),
        "Zordon tells you: \"That person is not allowed to become a Ranger \
at this time.\"\n");
      tell_object(this_player(),
        "Zordon tells you: \"They are a member of " +
        recruit->query_guild_name() + ".\"\n");
      return 1;
    }

    if(recruit->query_level() > 10)
    {
      tell_object(this_player(),
        "Zordon tells you: \"Players must be level 10 or less to join the \
Power Rangers.\"\n");
      return 1;
    }
    tell_object(recruit, "Zordon tells you: \"" + this_player()->query_name() +
      " has invited you to become a Power Ranger.\n" +
      "If you wish to accept this invitation type 'its_morphin_time'.\"\n");
    comm = clone_object("/players/guilds/Rangers/RecruitObject.c");
    comm->set_recruit(recruit);
    comm->set_sponsor(this_player()->query_name());
    move_object(comm, recruit);
    tell_object(this_player(),
      "Zordon tells you: \"You have given " + recruit->query_name() +
      " an invitation to join the Power Rangers.\"\n");
    return 1;

  }

  else if(type == "ally")
  {
    if(!present(person, environment(this_player())))
    {
      tell_object(this_player(),
        "Zordon tells you: \"That person is not present.\"\n");
      return 1;
    }
    recruit = present(person, environment(this_player()));
    if(!recruit->is_player())
    {
      tell_object(this_player(),
        "Zordon tells you: \"You can only recruit players as an ally.\"\n");
      return 1;
    }
    if(member_array(recruit->query_real_name(), Banished) != -1)
    {
      tell_object(this_player(),
        "Zordon tells you: \"That person has been Banished, and may not \
become an Ally.\"\n");
      return 1;
    }
    if( (string) recruit->query_guild_name() != "bard" &&
        (string) recruit->query_guild_name() != "healer" &&
        (string) recruit->query_guild_name() != "samurai" &&
        (string) recruit->query_guild_name() != "warrior" &&
        (string) recruit->query_guild_name() != "Knights Templar")
    {
      tell_object(this_player(),
        "Zordon tells you: \"That person is not allowed to become an Ally \
at this time.\"\n");
      return 1;
    }
    move_object(
      clone_object("/players/guilds/Rangers/HonorRangerCommunicator.c"), 
      recruit);
    CHANNEL->channel_message("Power Ranger", BLUE + "[" + OFF + RED + 
      "ALLY" + OFF + BLUE + "] " + OFF + recruit->query_name() +
      " has become a Ranger Ally, sponsored by " + 
      this_player()->query_name() + ".\n");
    return 1;
  }
  else if(type == "banish")
  {
    Banished += ({ person }
    );
    save_object("players/guilds/Rangers/Save/BANISHED");
    if(find_living(person))
    {
      recruit = find_living(person);
      if(recruit->is_player())
      {
        if(present("honor_ranger_communicator", recruit))
        {
          comm = present("honor_ranger_communicator", recruit);
          destruct(comm);
          tell_object(recruit, "Zordon tells you: \"You are no longer a Power \
Ranger Ally.\n");
        }
      }
    }
    tell_object(this_player(),
      "Zordon tells you: \"" + person +
      " has been added to the Banished list.\n");
    return 1;
  }
  else
  {
    tell_object(this_player(),
      "Zordon tells you: \"" + type + " is not a valid command.\n");
  }
  return 1;
}

status
QRangerInfo(){ return 1; }

status
RangerInfo()
{
  write("\
  Recruit allows you to bring new members and allies into the \n\
Power Ranger guild. It also allows you to banish such people \n\
from the guild. This task requires responsibility, and should \n\
not be taken lightly. Give serious thought, and consult other \n\
Rangers before recruiting or banishing anyone.\n\n\
Commands:\n\n\
recruit <person> ranger  - Recruit a person to be a Power Ranger\n\
recruit <person> ally    - recruit a person to be an ally\n\
                           must be a bard, healer, or knight templar\n\
recruit <person> banish  - Banished a person from being an Ally.\n\
                           You may banish a person even if they are\n\
                           not currently an Ally.\n\
                           This will prevent future joining.\n");
  return 1;
}
