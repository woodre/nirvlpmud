inherit "players/forbin/closed/wiztool/emote";

void reset(status arg) {
  if(arg) return;
  ::reset();
  load_targeted_msgs(({
    "You reach over and bonk #T# on the head with your fist.\n",
    "#N# reaches over and bonks #T# on #TP# head with #P# fist.\n",
    "#N# reaches over and bonks you on your head with #P# fist.\n" }));
  load_untargeted_msgs(({
    "You bonk yourself on the head.\n",
    "#N# bonks #O#self on #P# head.\n" }));
}