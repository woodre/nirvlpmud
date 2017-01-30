inherit "players/forbin/closed/wiztool/emote";

void reset(status arg) {
  if(arg) return;
  ::reset();
  load_targeted_msgs(({
    "You nod at #T#.\n",
    "#N# nods at #T#.\n",
    "#N# nods at you.\n" }));
  load_untargeted_msgs(({
    "You nod.\n",
    "#N# nods.\n" }));
}