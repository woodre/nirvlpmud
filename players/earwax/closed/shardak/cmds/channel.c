#include "/players/vertebraker/ansi.h"

#include "../macros.h"


#define PATH "/players/earwax/closed/shardak/obj/channeling.c"
#define RANK 8
#define MANA 150

status
main(string arg)
{
    object a, e, z, ob;

    if(arg)
      return 0;

    needmana(MANA);
    needrank(RANK);
    
    if(present("dRkChnL", (e = environment(a = this_player()))))
    {
      write("\
The channeling of dark energy has already begun in this\n\
location.\n");
       return 1;
     }

    if(e->query_no_fight())
    {
      write("This room is protected by some means.\n");
      return 1;
    }
    write("You lower your head and intone the spell of " + 
      BOLD + BLK + "DarK ChanneLinG" + NORM + ".\n");

    say((string)a->query_name() + " \
bows " + possessive(a) + " head reverently, dark eyes ablaze.\n");
    say((string)a->query_name() + " whispers a few words...\n");

    if(!(ob = present("shardak_obsidian", this_player())))
    {
      write("You don't have the Obsidian stone.\n");
      return 1;
    }
    destruct(ob);
    write("You crush the Obsidian Stone in your fist.\n");
    tell_room(e, BOLD + BLK + "\
<< " + NORM + "UnHoly Blackness" + BOLD + BLK + "\
 >>" + NORM + " descends.\n");

    a->add_spell_point(-MANA);

    z = clone_object(PATH);
    move_object(z, e);
    z->load_target(a);
    
    return 1;
}
