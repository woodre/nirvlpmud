inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
      "You smile darkly at #T#.\n",
      "#N# smiles darkly at #T#.\n",
      "#N# smiles darkly at you.\n" }));
    load_untargeted_msgs(({
      "You smile darkly.\n",
      "#N# smiles darkly.\n", }));
}
