#include <security.h>

int cmd_climbin(string str)
{
 object ob;

 if((int)this_player()->query_level() < ITEM_OVER)
  return 0;

 if(!str)
 {
  write("Usage: 'climbin <object>'\n");
  return 1;
 }
 if(!(ob = present(str, environment(this_player()))))
 {
  write("You don't see "+str+" here.\n");
  return 1;
 }

 move_object(this_player(), ob);
 this_player()->look();
 return 1;
}
