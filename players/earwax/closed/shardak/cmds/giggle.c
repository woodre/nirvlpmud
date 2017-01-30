inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
        "You giggle at #T# with a sound like dry bones rattling.\n",
        "#N# giggles at #T# with a sound like dry bones rattling.\n",
        "#N# giggles at you with a sound like dry bones rattling.\n",}));
    load_untargeted_msgs(({
        "Your giggle sounds like dry bones rattling.\n",
        "#N# giggles with a sound reminicent of dry bones rattling.\n"}));
}

