inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     "Your bloody hand reaches out to drip on #T#.\n",
      "#N#'s bloody hand reaches out to drip on #T#.\n",
      "#N#'s bloody hand drips on you.\n" }));
    load_untargeted_msgs(({
      "Your blood drips slowly from your body.\n",
      "#N# is dripping blood.\n", }));
}

status
main(string arg) {
    if(((int)this_player()->query_mhp() * 9 / 10) <= (int)this_player()->query_hp()) {

        notify_fail("You can't be bleeding, you are too healthy.\n");
        return 0;
    }
}

