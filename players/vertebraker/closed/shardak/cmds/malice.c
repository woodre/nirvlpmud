inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
      "Your malice burns toward #T#.\n",
      "#N# showers #T# with evil malice.\n",
      "#N# showers you with malice.\n" }));
    load_untargeted_msgs(({
      "You shower the room with your malice.\n",
      "#N# spreads malice and hatred around the room.\n", }));
}
