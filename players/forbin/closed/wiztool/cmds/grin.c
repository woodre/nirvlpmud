inherit "players/forbin/closed/wiztool/emote";

void reset(status arg) {
  if(arg) return;
  ::reset();
  load_targeted_msgs(({
    "You grin at #T# with a dark glimmer in your eyes.\n",
    "#N# grins at #T# with a dark glimmer in #P# eyes.\n",
    "#N# grins at you with a dark glimmer in #P# eyes.\n" }));
  load_untargeted_msgs(({
    "You grin with a dark glimmer in your eyes.\n",
    "#N# grins with a dark glimmer in #P# eyes.\n" }));
}