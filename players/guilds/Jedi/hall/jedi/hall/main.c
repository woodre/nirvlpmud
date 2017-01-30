inherit "/players/vertebraker/closed/std/room.c";
#include "../../defs.h"
#include "../../room_funcs.h"

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Clan Hall");
   set_long("generic clan hall room.\ntype 'exit' to leave.\n");
   add_property("NT");
   restore_me();
   set_no_clean(1);
}

init()
{
   ::init();
   check_valid_entry();
   if(present(TP))
      add_action("exit_command","exit");
}

int exit_command()
{
   string my_path;
   if(!C_OBJ)
      {
      write("Error. No clan object.\n");
      return 1;
   }
   
   my_path = (string)C_OBJ->query_hall_path();
   if(!my_path)
      {
      write("Error. hall_path not set.\n");
      return 1;
   }
   
   move_object(this_player(),my_path);
   say(TP->query_name() + " exits the hall.\n");
   "/bin/play/_look"->cmd_look();
   return 1;
}

void set_long(string str) { long_desc = strip_prepending_spaces(str, 1) + "Type 'exit' to leave.\n"; }
