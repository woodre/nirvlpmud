#include <security.h>

int cmd_climbout()
{
 object ob;

 if((int)this_player()->query_level() < ITEM_OVER)
  return 0;

 if(!(ob = environment(environment(this_player()))))
 {
  write("This isn't going to work.\n");
  return 1;
 }

 move_object(this_player(), ob);
 this_player()->look();
 return 1;
}
