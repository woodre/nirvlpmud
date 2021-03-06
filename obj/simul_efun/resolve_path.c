/* Simul_efun: resolve_path()
 * string resolve_path(String arg)
 *
 * See /doc/efun/resolve_path
 *
 * - Earwax 5/20/04
 *
 * Added ~/ support, cleaned up code a wee bit.
 * also changed file_size() check to
 * .... file_size()
 * [verte] <5-20-04>
 */

string resolve_path(string arg)
{
  int i, siz;
  string junk, junk2, path, filename, *args;
  object y;

  if (!arg) return 0;
  if (arg == "/") return arg;

  y = this_player();

  if (arg == "~")
    return "/players/"+(string)y->query_real_name()+"/";

  if (text_contains(arg, "~"))
  {
    if (y && sscanf(arg, "~/%s",junk))
      arg = "/players/" +
       (string)y->query_real_name() + "/" + junk;
    else if (sscanf(arg, "~%s/%s", junk, junk2) == 2)
      arg = "/players/"+junk+"/"+junk2;
    else if (sscanf(arg, "~%s", junk) == 1)
    {
            junk2 = "/players/"+(string)y->query_real_name()+"/"+junk;
            arg = (file_size(junk2)) ? junk2 : "/players/"+junk;
    }
  }

  if (arg[0] != '/')
    arg = (y && (int)y->query_level() > 19) ?
           (string)y->query_pwd() + arg :
           "/" + arg;

  if (text_contains(arg, ".."))
  {
    string b, c, *t;
    int x;

    t = ({ });
    b = (arg[strlen(arg)-1]=='/') ? "/" : "";
    siz = sizeof(args = explode(arg, "/"));

    for (i = 0; i < siz; i++)
    {
            if (args[i] == ".")
              continue;
            else if (args[i] != "..")
              t += ({ args[i] });
            else
            {
                    x = sizeof(t) - 1;
        t = (x) ? t[0..x-1] : ({ });
            }
    }
    arg = "/"+implode(t, "/")+b;
  }
  i = strlen(arg)-1;
  if (arg[i] != '/' && file_size(arg+"/") == -2)
    arg += "/";

  while (text_contains(arg, "//"))
  {
          if (sscanf(arg, "//%s", arg) == 1)
            arg = "/"+arg;
          if (sscanf(arg, "%s//%s", arg, junk) == 2)
            arg = arg + "/" + junk;
          if (sscanf(arg, "%s//", arg) == 1)
            arg += "/";
  }

  return arg;
}

