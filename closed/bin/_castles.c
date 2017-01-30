/*
 * this command refreshes the list of documented
 * castles in /open/info
 */
#include <ansi.h>

string *shorts;
string *envs;
string *wiznames;

int cmd_castles(string arg)
{
  if(arg) return 0;

  else
  {
    int s;
    if(!wiznames)
    {
      string *df;
      object cast, env;
      wiznames = shorts = envs = ({ });
      df = get_dir("/players/");
      s = sizeof(df);
      write("s: "+s+"\n");
      while(s --)
      {
        if(file_size("/players/"+df[s]) < 0 &&
           (cast = find_object("/players/"+df[s]+"/castle.c")) &&
           (env = environment(cast)))
        {
          wiznames += ({ df[s] });
          envs     += ({ (string)env->short() });
          shorts   += ({ (string)cast->short() });
        }
      }
    }
    s = sizeof(wiznames);
    while (s --)
    {
      string f;
      f = "/open/info/"+wiznames[s]+".nfo";
      if(file_size(f) <= 0)
      {
        write_file(f,
          GRN + capitalize(wiznames[s]) + "'s Castle\n"+NORM);
        write_file(f, "\n");
        write_file(f, shorts[s]+".\n");
        write_file(f, "\n");
        write_file(f, GRN+"Location:"+NORM+" "+envs[s]+".\n");
      }
    }
  }
  return 1;
}
