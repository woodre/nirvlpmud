#include <security.h>

init()
{
#ifndef __LDMUD__
   add_action("cmd_block"); add_xverb("");
#else
   add_action("cmd_block", "", 3);
#endif
}

cmd_block()
{
   if(this_player()->query_level() <= APPRENTICE) {
      return (write("You cannot do anything.\n"), 1);
   }
}

id(str) { return (str == "shardak_arena_block"); }
