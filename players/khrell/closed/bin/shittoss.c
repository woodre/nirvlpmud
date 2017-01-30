#include "/obj/ansi.h"

status main(string str, object ob, object User) 
{
  object shit;
  int x,y;
  
  if(!str)
  { 
    write("Use -> shittoss <name>\n");
    return 1; 
  }
  
  shit = clone_object("/players/mizan/etheriel/items/shit100.c");
  move_object(shit, this_player());
  shit->set_size(101);
  command("fling "+str+"", this_player());  
  return 1; 
}
