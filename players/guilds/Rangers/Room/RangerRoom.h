string playername;
string pathname;
string guildname;

void
init()
{
  ::init();
  if(TP->is_player())
  {
    call_out("find_monster",1);
    playername = TPNAME;
    pathname = file_name();
    guildname = TP->query_guild_name();
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
        MASTER->CreateMonster(playername,short(),pathname);
        return 0;
      }   
    }
  }     
  if(random(100) < 5)
  {
    if(!find_living("RangerMonster"))
    {
      MASTER->CreateMonster(playername,short(),pathname);
    }   
  }
  return 1;
}   
