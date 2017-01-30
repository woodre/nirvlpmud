inherit "players/forbin/closed/wiztool/emote";

void reset(status arg) {
  if(arg) return;
  ::reset();
  load_targeted_msgs(({
    "You stick your tongue out at #T#.\n",
    "#N# sticks #P# tongue out at #T#.\n",
    "#N# sticks #P# tongue out at you.\n" }));
  load_untargeted_msgs(({
    "You stick your tongue out.\n",
    "#N# sticks #P# tongue out.\n" }));
}