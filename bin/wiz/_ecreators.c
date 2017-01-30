#include <lib/usr/term_settings.h>
#include <lib/bin/paths.h>

#define BEGIN "\n"
#define END   "\n"
#define SEP   "==>"

mapping get_creators()
{
  string *gd, wn, tmp;
  mapping m;
  object  obj;
  int     x, y;
  
  gd = get_dir(BINSOUL+"_*.c");
  m = ([]);
  y = sizeof(gd);
  
  for(x = 0; x < y; x ++)
  {
    if(!(obj = find_object(tmp=BINSOUL+gd[x])))
    {
      if(!catch(call_other(tmp,"???")))
        obj = find_object(tmp);
      else
        continue;
    }
    if((string)obj->query_code_word() != "verbal_kint")
      continue;
    if(!(wn=(string)obj->query_creator()))
      wn = "vertebraker";
    wn = capitalize(wn);
    if(!m[wn])
      m[wn] = ({ });
    m[wn] += ({ gd[x] });
  }
  return m;
}

int cmd_ecreators(string nm)
{
  int     x;
  mapping m;
  string *ks, capName;
  m = get_creators();
  if(!nm)
  {
    x = sizeof(ks = keys(m));
    write(BEGIN);
    while(x--)
      write(pad("  "+ks[x],14)+SEP+" "+sizeof(m[ks[x]])+"\n");
    write(END);
  }
  else
  {
    int y;
    string lineDesc;
    if(member_array((capName=capitalize(nm)),keys(m)) == -1)
      return (notify_fail((!valid_wizard(nm)?
      capName+" isn't even a wizard.\n":
      capName+" hasn't created an emote yet.\n")), 0);
    write(BEGIN);
    lineDesc = "  ";
    write(pad("  "+capitalize(nm),14)+SEP+" "+
      (y=sizeof(ks=m[capName]))+"\n");
    for(x=0;x<y-1;x++)
    {
      sscanf(ks[x],"_%s.c",ks[x]);
      if(strlen(lineDesc) + strlen(ks[x]) >= SCREEN_WIDTH)
      {
        write(lineDesc + "\n");
        lineDesc = "  ";
      }
      lineDesc += ks[x]+", ";
    }
    sscanf(ks[y-1],"_%s.c",ks[y-1]);
    write(lineDesc+ks[y-1]+".\n");
    write(END);
  }
  return 1;
}
