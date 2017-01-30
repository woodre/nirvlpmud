inherit "/players/vertebraker/closed/shardak/std/emote";
#include "../include/ansi.h"

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
      "You grin "+HIK+"darkly"+NORM+" at #T#.\n",
      "#N# grins "+HIK+"darkly"+NORM+"at #T#.\n",
      "#N# grins "+HIK+"darkly"+NORM+" at you.\n" }));
    load_untargeted_msgs(({
      "You grin "+HIK+"darkly"+NORM+".\n",
      "#N# grins "+HIK+"darkly"+NORM+".\n", }));
}
