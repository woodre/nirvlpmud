inherit "/players/vertebraker/closed/shardak/std/emote";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs( ({
        "You subtly incline your head toward #T#.\n",
        "#N# subtly inclines #P# head toward #T#.\n",
        "#N# subtly inclines #P# head toward you.\n"}) );
    load_untargeted_msgs( ({
        "You subtly incline your head with a nod.\n",
        "#N# subtly inclines #P# head with a nod.\n"}) );
}

