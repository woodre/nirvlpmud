#include "std.h"
#define ELFGUARD 1

int count, i;

#if ELFGUARD
object elfguard, armor, bow, arrow, arrow1, arrow2, arrow3, arrow4, arrow5;
#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!find_living("elfguard"))\
        starta_elfguard();
#endif

TWO_EXIT("players/molasar/FOREST/forest1","north",
         "players/molasar/FOREST/forest3","east",
         "A path to the castle",
 "A path that leads to the entrance of the inner castle.  The exit of\n"+
 "the castle's compound lies to the east.\n",1)

#if ELFGUARD
starta_elfguard() {
    i = 0;
    if(!elfguard || !living(elfguard)) {
      while(i<3) {
      i += 1;
        elfguard = clone_object("players/molasar/MONSTERS/elf_scout");
        armor = clone_object("players/molasar/ARMOR/leather_armor");
        bow = clone_object("players/molasar/WEAPONS/bow");
        arrow = clone_object("players/molasar/WEAPONS/arrow");
        arrow1 = clone_object("players/molasar/WEAPONS/arrow");
        arrow2 = clone_object("players/molasar/WEAPONS/arrow");
        arrow3 = clone_object("players/molasar/WEAPONS/arrow");
        arrow4 = clone_object("players/molasar/WEAPONS/arrow");
        arrow5 = clone_object("players/molasar/WEAPONS/arrow");
        transfer(armor, elfguard);
        transfer(bow, elfguard);
        transfer(arrow, elfguard);
        transfer(arrow1, elfguard);
        transfer(arrow2, elfguard);
        transfer(arrow3, elfguard);
        transfer(arrow4, elfguard);
        transfer(arrow5, elfguard);
        call_other(elfguard, "init_command", "wear leather armor");
        move_object(elfguard, "players/molasar/FOREST/forest2");
      }
    }
}
#endif

