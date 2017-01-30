inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     "You pull out a Colt .45 and splatter #T#'s mind on the wall.\n",
      "#N# pulls out a Colt .45 and splatters #T#'s mind on the wall.\n",
      "#N# pulls out a Colt .45 and splatters your mind on the wall behind you.\n" }));
    load_untargeted_msgs(({
      "You pull out a Colt .45 and put your mind on the wall behind you.\n",
      "#N# pulls out a Colt .45 and put #P# mind on the wall behind #O#.\n", }));
}
