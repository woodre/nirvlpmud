#include <security.h>


int cmd_exiv(string str)
{
 object ob;
 if(str) return 0;

 if((int)this_player()->query_level() < ITEM_OVER)
  return 0;

 if(ob = environment(environment(this_player())))
 {
  move_object(this_player(), ob);
  this_player()->look();
 }

 else
 {
  write("\
This cmd may only be used when you are in the inventory\n\
of something that has an environment.\n");
 }

 return 1;
}

