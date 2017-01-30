#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int a, b, c, sa;
  string *all,g,f;
  if(!str)
    cat(DIR+"help/root");
  else if(str == "all" || str == "list")
  {
    all = get_dir(DIR+"help/");
    sa = sizeof(all);
    b = 0;
    TOU "Bloodfist Help Files:\n");
    for(a = 0; a < sa; a++)
    {
      if(b == 4){ b = 0; TOU"\n"); }
      TOU pad(all[a], 18));
      b++;
    }
    TOU"\n");
    return 1;
  }
  else if(sscanf(str, "glevel %d", c) || sscanf(str, "glvl %d", c))
  {
    if(c > 8)
      return (notify_fail("There are not that many guild levels.\n"), 0);
    if(PO->query_glevel() < c)
      return (notify_fail("You can not read that help file yet.\n"), 0);
    all = explode(read_file(DIR+"help/glevels"), "\n");
    sa = sizeof(all);
    for(a = 0, b = 0; a < sa; a++)
    {
      if(a < 4 && c != 0)
        TOU all[a]+"\n");
      if(all[a] == "**")
        b++;
      if(b == c && all[a] != "**")
        TOU all[a]+"\n");
    }
    return 1;
  }
  else if(str == "abilities" || str == "glevels" || str == "glvls")
  {
    all = explode(read_file(DIR+"help/glevels"), "\n");
    sa = sizeof(all);
    for(a = 0, b = 0; a < sa; a++)
    {
      if(all[a] == "**")
      {
        TOU "\n");
        b++;
      }
      else
        TOU all[a]+"\n");
      if(b > PO->query_glevel())
        return 1;
    }
    return 1;
  }
  else if(str == "bf" || str == "channel")
    cat(DIR+"help/bf");
  else if(str == "emergency" || str == "~")
    cat(DIR+"help/emergency");
  else if(str == "allies")
    cat(DIR+"help/loyalty");
  else if(str == "iron skin")
    cat(DIR+"help/iron_skin");
  else if(str == "absorb corpse")
    cat(DIR+"help/absorb_corpse");
  else if(str == "battle cry")
    cat(DIR+"help/battle_cry");
  else if(str == "pain aura")
    cat(DIR+"help/pain_aura");
  else if(str == "sacrifice corpse" || str == "sacrifice")
    cat(DIR+"help/sacrifice_corpse");
  else if(str == "preserve corpse" || str == "preserve")
    cat(DIR+"help/preserve_corpse");
  else if(str == "construct bloodward" || str == "construct")
    cat(DIR+"help/bloodward");
  else if(str == "light torch" || str == "extinguish torch")
    cat(DIR+"help/torch");
  else if(str == "trick" || str == "tricks" || str == "weapon tricks")
    cat(DIR+"help/weapon_tricks");    
  else if(sscanf(str, "%s %s",g,f))
    TOU "No help is available for that topic.\n");
  else if(file_size(DIR+"help/"+str) > 0)
    cat(DIR+"help/"+str);
  else 
    TOU "No help is available for that topic.\n");
  return 1;
}

