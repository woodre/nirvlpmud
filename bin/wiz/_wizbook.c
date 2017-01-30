#include <ansi.h>

int cmd_wizbook()
{
 if(present("eurale's funky wizbook", this_player()))
 {
  write("You already have the Wizard Handbook.\n");
  return 1;
 }

 write("You summon the legendary "+HIR+"Wizard's Handbook"+NORM+".\n"+
      "");
 move_object(clone_object("/obj/wizbook"), this_player());
 return 1;
}
