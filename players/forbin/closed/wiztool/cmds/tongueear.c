inherit "players/forbin/closed/wiztool/emote";

void reset(status arg) {
  if(arg) return;
  ::reset();
  load_targeted_msgs(({
    "You lean close, then stick your tongue in #T#'s ear.\n",
    "#N# leans close to #T#, and then sticks #P# tongue in #TP# ear.\n",
    "#N# leans close to you, and then sticks #P# tongue in your ear.\n" }));
  load_untargeted_msgs(({
    "You try to stick your tongue in your own ear.\n",
    "#N# tries to stick #P# tongue in #P# own ear.\n" }));
}