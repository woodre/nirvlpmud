inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     "You question #T#'s courage and fortitude.\n",
      "#N# questions #T#'s courage and fortitude.\n",
      "#N# questions your courage and fortitude.\n" }));
    load_untargeted_msgs(({
      "You call the people in the room pansies.\n",
      "#N# drops #P# drawers and calls everyone a pansy.\n", }));
}
