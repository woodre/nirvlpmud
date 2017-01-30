inherit "players/forbin/closed/wiztool/emote";

void reset(status arg) {
  if(arg) return;
  ::reset();
  load_targeted_msgs(({
    "You glance at #T# and say, \"Spot on!\"\n",
    "#N# glances at #T# and says, \"Spot on!\"\n",
    "#N# glances at you and says, \"Spot on!\"\n" }));
  load_untargeted_msgs(({
    "You say, \"Spot on!\"\n",
    "#N# says, \"Spot on!\"\n" }));
}