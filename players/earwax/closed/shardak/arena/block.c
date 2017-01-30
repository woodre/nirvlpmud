#include <security.h>

init()
{
   add_action("cmd_block"); add_xverb("");
}

cmd_block()
{
   if(this_player()->query_level() <= APPRENTICE) {
      return (write("You cannot do anything.\n"), 1);
   }
}

id(str) { return (str == "shardak_arena_block"); }
