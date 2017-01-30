inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     "You grin darkly at #T#.\n",
      "#N# grins darkly at #T#.\n",
      "#N# grins darkly at you.\n" }));
    load_untargeted_msgs(({
      "You grin darkly.\n",
      "#N# grins darkly.\n", }));
}
