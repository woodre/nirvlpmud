inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
        "You pin #T# up against the wall and....\n\tuse your imagination.\n",
        "#N# pins #T# up against the wall.\n",
        "#N# pins you up against the wall and does something perverse.\n",}));
    load_untargeted_msgs(({
        "You pin your hopes on a fading dream.\n",
        "#N# pins #P# hopes on a fading dream.\n"}));
}

