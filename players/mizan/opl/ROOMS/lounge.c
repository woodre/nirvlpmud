inherit "/room/room.c";
#include "/obj/ansi.h"

object poker, board;

void reset(int arg)
{
    if (arg) return;
    set_light(1);

    short_desc = "The Beatdown Lounge";
    long_desc =
        "    " + HIB + ">>>" + NORM + " " + HIY +
        "The Beatdown Lounge"+
        NORM + " " + HIB + "<<<" + NORM + "\n" +

        "    This is a spacious lounge filled with soft beanbag sofas and a totally\n" +
        "  over-the-top level of decor. Pictures and paintings of the OverPowerLord\n" +
        "  hang in almost every spot where there was once a bare patch of wall, and\n" +
        "  it really looks like a who's who of Nirvana is posing there with each\n" +
        "  and every shot there with him. You notice almost immediately a shimmering\n"+
        "  blue light towards the east with an imposing neon sign hanging over it\n"+
        "  saying 'WIZARDS ONLY PLEASE'. The next thing you see of course are the\n"+
        "  vast amounts of food and drink setup in the catering tables spread\n"+
        "  out before you. Okay, so this 'OverPowerLord' guy might be a bit tacky\n"+
        "  but he really knows how to welcome his guests to a good time.\n" +
        "\n" +
        "  The bar is to the north, through the arches of a stuffed white elephant.\n" +
        "  To the south is an observation deck, and to the west is the main plaza.\n";

    items = ( {

        "floor",
        "The floor appears to be made of some fairly high quality granite tile.",

        "table",
        "There is a vast amount of food here. It seems that you can't actually eat\n"+
        "any of it... but you notice that just by being in this room in front of\n"+
        "the food something is happening to your body... yes... you are HEALING.\n",

        "pictures",
        "It's really crazy... where to begin? There's a picture of OverPowerLord\n"+
        "clinking champagne glasses with Boltar... There's another one where he\n"+
        "has Mizan in a headlock... There's another where he's managed to pin\n"+
        "Pain on his shoulders and is giving a thumbs-up to the camera.\n"+
        "\n"+
        "Another picture shows an adolescent Overpowerlord but his massively powerful\n"+
        "physique is already developing well. He is crouched down next to a tiny,\n"+
        "2-foot tall creature labelled the 'Mr. Pocket Hercules of the Universe'.\n"+
        "Overpowerlord is clutching an autograph book and is beaming with pride.\n"+
        "For some reason this photo really tugs at your emotional heart strings...\n"+
        "This little man is obviously a childhood idol of OverPowerLord.\n"+
        "The tiny little guy he is standing next to looks somewhat familiar...\n"+
        "\n"+
        "Overall, it's really a bedazzling array of pictures- quite surreal\n"+
        "and entertaining to look at.",

        "paintings",
        "A beautifully rendered painting in the style of the Golden Age of Dutch\n"+
        "Masters depicts OverPowerLord surrounded by what is literally hundreds\n"+
        "of cats. Everything feline from ligers down to the tiniest of tabby\n"+
        "kittens is seen here. The one thing you notice right away is that they\n"+
        "all seem to be rescue animals. Their names are visible on a placard\n"+
        "next to the painting itself. The language however is not completely\n"+
        "readable. Other paintings feature OverPowerLord posing with a who's-who\n"+
        "gallery of Nirvana players and wizards of present and past. After a\n"+
        "moment you realize that these must have been people who have contributed\n"+
        "money or volunteered their time to save orphaned animals.\n",

        /*
            "food",
            "There is a lot of stuff to eat here. 'help yourself' to the goodies!\n"
        */

    });

    dest_dir =
    ( {
        "/players/mizan/opl/ROOMS/bar.c","north",
        "/players/mizan/opl/ROOMS/entrance.c", "west",
        "/players/mizan/opl/ROOMS/observation.c", "south",
    });

    if (!poker)
    {
        poker = clone_object("/players/mizan/opl/environs/poker_machine.c");
        move_object(poker, this_object());
    }

    if (!board)
    {
        board = clone_object("/players/mizan/opl/environs/bullboard.c");
        move_object(board, this_object());
    }

    remove_call_out("heal_everyone");
    call_out("heal_everyone", 5);

    set_no_clean(1);
}

init()
{
    ::init();
    add_action("on_east","east");
}

on_east() 
{
    if (this_player()->query_level() < 30) 
    {
        write("A strong magic force stops you.\n");
        say(this_player()->query_name() +
            " tries to go through the field, but fails.\n");
        return 1;
    }

    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "east#players/mizan/opl/ROOMS/control");
    return 1;
}

heal_everyone()
{
    object ob, oc;
    int hp, mhp;

    ob = first_inventory(this_object());

    while(ob)
    {
        oc = next_inventory(ob);

        if(living(ob) && ob->is_player())
        {
            hp = ob->query_hp();
            mhp = ob->query_mhp();

            if(hp < (mhp - 10)) ob->heal_self(10);
        }

        ob = oc;
    }

    remove_call_out("heal_everyone");
    call_out("heal_everyone", 5);
}

