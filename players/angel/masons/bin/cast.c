#include "defs.h"

status main(string str, int glevel) {
  object ob;
  object dest;

  if (!str) {
    notify_fail("Cast what?\n");
    return 0;
  }

  if (str != "light") {
    notify_fail("Masons can only cast 'light'.\n");
    return 0;
  }
   
  if((int)this_player()->query_spell_point() < CAST_COST) {
    write("You are too low on power.\n");
    return 1;
  }
  dest = environment(this_player());
  ob = clone_object(LIGHT_OBJ);
  move_object(ob, dest);
  this_player()->add_spell_point(-CAST_COST);
  say((string)this_player()->query_name()+" builds a magical fire.\n");
  write("You create a magical fire.\n");
  this_player()->look();
  return 1;
}
