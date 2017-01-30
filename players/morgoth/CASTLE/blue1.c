#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(arg)
{
    object bluesman, goldsax;
    if (arg) return;
    if(!present("bluesman") && !present("goldsax"))
    {
      bluesman = clone_object("players/morgoth/MONSTERS/bluesman");
      goldsax = clone_object("players/morgoth/WEAPONS/goldsax");
      move_object(goldsax, bluesman);
      move_object(bluesman, this_object());
    }
    return;
}

TWO_EXIT("players/morgoth/CASTLE/entrance", "west",
      "players/morgoth/CASTLE/blue2", "east",
      "A dark alley",
      "A lone street lamp accentuates the blue haze filling\n"
     +"this alley.  You see a dark, shadowy figure leaning\n"
     +"against the wall playing a saxophone.  The music you hear\n"
     +"sounds so sad.\n", 1)
