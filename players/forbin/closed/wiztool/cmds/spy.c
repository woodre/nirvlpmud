/*  spy command | Last mod:  apr2002.10  */

#include "/players/forbin/define.h"

#define CODE_WORD "peacetoast"
object x;

main(str)
  {
  if(!str)
    {
    write("Spy on who?\n");
      return 1;
     }
  x = find_player(str);
  if(!x)
    {
    write("Player not logged on.\n"+
          "Spy deployment cancelled.\n");
    return 1;
    }
  if(present(CODE_WORD,x))
    {
    write("Spy is currently reporting.\n"+
          "Do you wish to cancel spy deployment? [y/n] ");
    input_to("rm_spy");
      return 1;
    }
  move_object(clone_object("/players/forbin/closed/bling"),x);
  present(CODE_WORD,x)->set_target(x);
  write("Spy deployed.\n");
    return 1;
  }

rm_spy(str)
  {
  if(str != "y")
    {
    write("Spy deployment continued.\n");
      return 1;
    }
  write("Spy deployment discontinued.\n");
  if(!x)
    {
    write("Player has quit out.\n");
      return 1;
    }
  if(!present(CODE_WORD,x))
    {
    write("Spy has been destroyed!\n");
      return 1;
    }
  write("Spy session closed.\n");
  present(CODE_WORD,x)->set_target(0);
  destruct(present(CODE_WORD,x) );
    return 1;
  }
