int do_ht(string str)
{
  if(!str)
  {
    return command("hwho", TP);
  }

  if(MYOB->query_muffle())
  {
    write("You cannot speak while muffled.\n");
    return 1;
  }

  if(TP->query_invis() >= 29 && TP->query_guild_rank() < 11)
  {
    write("You may not speak invisibly on this channel.\n");
    return 1;
  }

  if(str[0]==':')
    CHANNEL->broadcast(GUILD_STRING, TPN+" "+str[1..strlen(str)]);
  else
    CHANNEL->broadcast(GUILD_STRING, TPN+" says: "+str);
  return 1;
}
