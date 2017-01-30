inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     "You acknowledge #T# with a bow.\n",
      "#N# acknowledges #T# with a bow.\n",
      "#N# acknowledges you with a bow.\n" }));
    load_untargeted_msgs(({
      "You hail Shardak as lord.\n",
       "#N# hails Shardak as lord.\n", }));
}
