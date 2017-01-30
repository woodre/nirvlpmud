inherit "/players/vertebraker/closed/shardak/std/emote";
#include "/players/pestilence/ansi.h"

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     ""+HIG+"You"+NORM+" tell #T# 'OMG'!\n",
      "#N# tells #T# 'OMG'!\n",
      "#N# tells you 'OMG'!\n" }));
    load_untargeted_msgs(({
      "You go 'OMG'!\n",
      "#N# goes 'OMG'!\n", }));
}
