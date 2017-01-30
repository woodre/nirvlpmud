#include "/players/guilds/Rangers/RangerDefs.h"

string playername;
string pathname;
string guildname;

void
set_up()
{
  if(this_player()->is_player())
  {
    call_out("find_monster",1);
    playername = (string) this_player()->query_name();
/* Changed file_name() to object_name - Rumplemintz */
    pathname = object_name();
    guildname = (string) this_player()->query_guild_name();
  }
}

status
find_monster()
{
  if(guildname == "rangers" || guildname == "dark rangers")
  {
    if(random(100) < 20)
    {
      if(!find_living("RangerMonster"))
      {
        MASTER->CreateMonster(playername, this_object()->short(), pathname);
        return 0;
      }   
    }
  }     
  if(random(100) < 5)
  {
    if(!find_living("RangerMonster"))
    {
      MASTER->CreateMonster(playername, this_object()->short(), pathname);
    }   
  }
  return 1;
}   
