#include "../macros.h"
#include "../ansi.h"
status
main(string arg)
{
    if(this_player()->query_level() < 15) return 0;
    if(arg)
    {
      write("You can only cast Shardak Invisibility on yourself.\n");
      return 1;
    }

    needmana(50);
    write("You cast " + BOLD + "Shardak Invisibility" + NORM
         +" upon yourself.\n");
    say((string)this_player()->query_name() + " speaks a few ancient \
words and disappears from sight.\n");
    this_player()->set_invs_sp();
    this_player()->add_spell_point(-50);
    return 1;
}
