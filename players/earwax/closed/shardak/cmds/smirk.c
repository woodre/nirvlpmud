inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     "You smirk at #T# in utter contempt.\n",
      "#N# smirks with contempt at #T#.\n",
      "#N# smirks contemptuously at you.\n" }));
    load_untargeted_msgs(({
      "Your lips curl contemptuously.\n",
      "#N# smirks contemptuously.\n", }));
}

