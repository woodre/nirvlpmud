/*
 * This is a creature which I put in the entrance of the realm.
 *
 */
inherit "/players/mizan/opl/core/monster.c";

reset(arg)
{
    object gold, what;
    ::reset(arg);
    if (arg) return;
    set_name("Wilbur the Greeter");
    set_race("human");
    set_alias("wilbur");
    set_short("Wilbur the Greeter");
    set_long("    Wilbur is a large, heavyset man with a vacant look on his face as\n"+
             "  he greets the guests to the Proving Grounds of the OverPowerLord.\n"+
             "  Wilbur is dressed in a large apron, in the front of which i adorned the\n"+
             "  gleaming, beaming face of the OverPowerLord himself. He bids you WELCOME!\n");
    set_level(25);
    set_hp(5400);
    set_al(0);
    set_wc(6);
    set_ac(300);
    set_chat_chance(20);
    load_chat("Wilbur the Greeter says: Welcome to the Proving Grounds. I love you.\n");

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 0;
}

init()
{
    object guest;
    object room;
    object card;

    guest = this_player();
    if (guest)
    {
        room = environment(guest);
        if (room &&
                environment(this_object()) &&
                room == environment(this_object()) &&
                guest->is_player() &&
                !guest->query_invis())
        {
            /* this person is in the same room as us. We check to see that they have a tripod card. */
            if (!present("tripod_card", guest))
            {
                say(this_object()->query_name() + " hands " + guest->query_name() + " a tripod card.\n");
                card = clone_object("/players/mizan/opl/items/tripod_card.c");
                move_object(card, guest);

            }

        }
    }
    ::init();
}
