/*
 * Standard Load/Update cmd by V [7.8.01]
 * Also catches a load error and shows the log
 */

#include "/players/vertebraker/closed/std/load_object.h"
#include "/players/vertebraker/closed/std/resolve_path.h"
#include "/players/vertebraker/ansi.h"

status
main(string arg)
{
    if(!arg)
    {
      write("Mk what?\n");
      return 1;
    }

    else
    {
      object ob;

      if(!(arg = resolve_path(arg, ".c")))
      {
        write(HIR + "Bad path error.\n" + NORM);
        return 1;
      }

      write("Making " + HIW + arg + NORM + "...\n");
      if(ob = find_object(arg))
      {
        write("Object found.\n");
        write("Updating old copy... ");
        destruct(ob);
        write(HIG + "Ok\n" + NORM);
      }

      else
        write("No object found.\n");

      write("Loading new copy... ");

      if(!(ob = loadObject(arg)))
      {
        string me;

        write(HIR + "Load aborted.\n" + NORM);

        if(file_size("/log/" + 
           (me = (string)this_player()->query_real_name())) > 0)
        {
          write(BOLD + "Error found.\n" + NORM);
          command("log " + me, this_player());
          command("rlog " + me, this_player());
        }

        else
          write(BOLD + "File does not exist!\n" + NORM);
        return 1;
      }

      else
        write(HIG + "Success!\n" + NORM);

      return 1;
    }
}
