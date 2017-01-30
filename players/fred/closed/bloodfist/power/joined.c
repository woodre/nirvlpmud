#include "/players/fred/closed/bloodfist/defs.h"

int guild_age(int guild_age)
{
  int i, x;
  string temp;
  object PO;
  /*
  if(!guild_age)
    return "an unknown amount of time";    
  */
  PO = present("bloodfist_gob", this_player());
  i = (int)PO->query_beats();

  if(i > 43200)
  {
    write("You joined Bloodfist ");
    if(i/43200 < 2)
    {
      write(i/43200 + " day ");
    }
    else
    {
      write(i/43200 + " days ");
    } 
    x = (i/43200);
    x = (x * 43200);
    i = i - x;
  }
  if(i > 1800)
  {
    write(i/1800 + " hours ");
    x = (i/1800);
    x = (x * 1800);  
    i = i  - x;
  }
  if(i > 30)
  {
    write(i/30 + " minutes ");
    x = (i/30);
    x = (x * 30);    
    i = i - x;
  }
  write(i*2 + " seconds ago.\n");
  return 1;
}

status main(string str, object PO, object User)
{
  guild_age((int)PO->query_guild_age());
  return 1;
}

