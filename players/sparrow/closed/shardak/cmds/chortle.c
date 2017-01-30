inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
        "You grin as Shardak chortles at #T#'s pitiful soul.\n",
        "#N# grins as Shardak chortles at #T#'s pitiful soul.\n",
        "#N# grins as Shardak chortles at your pitiful soul.\n",}));
    load_untargeted_msgs(({
        "Your chortle echoes the power of Shardak.\n",
        "#N# chortles with echoes of Shardak's power.\n"}));
}

