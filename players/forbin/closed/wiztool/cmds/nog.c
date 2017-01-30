inherit "players/forbin/closed/wiztool/emote";

void reset(status arg) {
  if(arg) return;
  ::reset();
  load_targeted_msgs(({
    "You nog at #T#.\n",
    "#N# nogs at #T#.\n",
    "#N# nogs at you.\n" }));
  load_untargeted_msgs(({
    "You nog.\n",
    "#N# nogs.\n" }));
}