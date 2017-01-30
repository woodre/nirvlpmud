inherit "players/forbin/closed/wiztool/emote";

void reset(status arg) {
  if(arg) return;
  ::reset();
  load_targeted_msgs(({
    "You fucking nog at #T#.\n",
    "#N# fucking nogs at #T#.\n",
    "#N# fucking nogs at you.\n" }));
  load_untargeted_msgs(({
    "You fucking nog.\n",
    "#N# fucking nogs.\n" }));
}