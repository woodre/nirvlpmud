inherit "players/forbin/closed/wiztool/emote";

void reset(status arg) {
  if(arg) return;
  ::reset();
  load_targeted_msgs(({
    "You groan loudly and say, 'BLOODY HELL' to #T#.\n",
    "#N# groans loudly and says, 'BLOODY HELL' to #T#.\n",
    "#N# groans loudly and says, 'BLOODY HELL' to you.\n" }));
  load_untargeted_msgs(({
    "You groan loudly and say, 'BLOODY HELL!'\n"
    "#N# groans loudly and says, 'BLOODY HELL!'\n" }));
}