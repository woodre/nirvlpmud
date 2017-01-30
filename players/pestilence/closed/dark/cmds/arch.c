inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     "You arch your eyebrow inquisitively at #T#.\n",
    "#N# arches their eyebrow inquisitively at #T#.\n",
     "#N# arches their eyebrow inquisitively at you.\n" }));
    load_untargeted_msgs(({
      "You arch your eyebrow inquisitively.\n",
      "#N# arches their eyebrow inquisitively.\n", }));
}
