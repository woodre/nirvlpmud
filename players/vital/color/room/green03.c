/*************************************************************/
/*  File:           green03.c
/*  Function:       
/*  Author(s):      Vital@Nirvana
/*  Copyright:      Copyright (c) 2003 v-Dev Code Factory
/*                  All Rights Reserved.
/*  Source:         11/6/03
/*  Notes:          
/*  Change History: 
/*************************************************************/

#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>
#include "../color.h"

inherit "room/room";
inherit PROBABLE_EXITS;
int cut;

reset(arg)
{
    if(!arg)
    { 
        set_light(1);
        short_desc = GRN+"A Green Room"+NORM;
        long_desc =  BGRN+"\
  The verdant, "+HIG+"green"+NORM+BGRN+" grass stretches out here \
to the edges of the \nhorizons. There is a large tree planted here \
with a massive, round \ntrunk that is over seven meters in diameter. \
The branches extend \nupwards to the heavens and out to the rising \
and setting sun and \neveryday in between.  The branches cast dark \
shadows though the \nsource of the light is indiscernible.\n";
        items = ({
            "room",
            "This is the same room you just entered",
            "grass",
            "The grass is a beautiful, rich "+GRN+"green"+NORM+" in \
color. \nIt feels wonderful and soft to touch.",
            "edges",
            "The horizon is visible in the distance where the \ngrass \
meets the sky",
            "edge",
            "The horizon is visible in the distance where the \ngrass \
meets the sky",
            "horizon",
            "The horizon is visible in the distance where the \ngrass \
meets the sky",
            "horizons",
            "The horizon is visible in the distance where the \ngrass \
meets the sky",
            "tree",
            "This is one of the ancient Life Trees that was \nplanted \
by the Elders ages ago",
            "trunk",
            "The massive trunk of the tree is nearly 3 meters \nin \
diameter and would be very difficult to cut down",
            "branches",
            "The braches are massive and near the base they \nalmost \
complete obscure the sky",
            "branch",
            "The branch is very thick and provides a home for \nseveral \
species of birds",
            "heavens",
            "The sky is a light azure with thin, whispy clouds",
            "sun",
            "The sun is blocked out by the sky. In fact it is \nhard to \
tell if there is even a sun in the sky",
            "shadows",
            "The shadows are cool and not completely dark",
            "light",
            "There is an indistinct presence of light in this \nplace. \
It is hard to locate the source of the light",
            
        });
        dest_dir = ({
            "climb_placeholder",NORM+HIG+"climb"+NORM,
            "dig_placeholder",  NORM+HIG+"dig"+NORM,
        });
        cut = 0;
    }
}

init()
{
    ::init();
    add_action("search_me","search");
    add_action("random_exit","climb");
    add_action("random_exit","dig");
    add_action("cut_tree","cut");
    add_action("cut_tree","chop");
}

search_me(str)
{
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}

random_exit();

jump_exit()
{
    string name;
    name = this_player()->query_name();
    write(name + " jumps into the air and down the hole. With a \nflash " + name + " is gone and everything around you changes.\n");
    random_exit();
    return 1;
}

cut_tree(str)
{
    object ob1, ob2;
    ob1 = present("axe",this_player());
    ob2 = present("saw",this_player());
    if (!str)
    {
        notify_fail("What do you want to cut?\n");
        return 0;
    }
    if (!cut)
    {
        if (str == "tree" || str == "trunk")
        {
            if (!ob1)
            {
                if (!ob2)
                {
                    notify_fail("You need an axe or saw to cut down the tree!\n");
                    return 0;
                }
                notify_fail("You need an axe or saw to cut down the tree!\n");
                return 0;
            }
            if ((this_player()->query_attrib("str")) < 22)
            {
                notify_fail("You are not strong enough to cut down the tree!\n");
                return 0;
            }
            if ((this_player()->query_attrib("sta")) < 22)
            {
                notify_fail("You don't have enough stamina to cut down the tree!\n");
                return 0;
            }
            write("With mighty swings you quickly fell the living tree.\n");
            cut = 1;
            new_dirs();
            new_action();
            new_long();
            new_items();
            return 1;
        }
        notify_fail("The tree is only thing around you that you can cut down.\n");
        return 0;
    }
    notify_fail("The tree has already been cut down.\n");
    return 0;
}

exit()
{
    destruct(present("jumper",this_object()));
    reset();
    init();
}

new_dirs()
{
    dest_dir = ({
        "climb_placeholder",NORM+HIG+"climb"+NORM,
        "dig_placeholder",  NORM+HIG+"dig"+NORM,
        "jump_placeholder", NORM+HIG+"jump"+NORM,
    });
}

new_action()
{
    object jumper;
    jumper = clone_object("/players/vital/color/obj/jumper.c");
    move_object(jumper, this_object());
    return;
}    

new_long()
{
    long_desc = ("\
  The life and color are gone. The once verdant and green grass \n\
is now beginning to look pale and withered. There is a large stump \n\
nearby where a large tree once lived. At the center of the stump \n\
is a large hole. Already the trunk of the nearby fallen tree is \n\
starting to shrivel and dry up. The sky appears to have darkened \n\
and the air feels colder.\n");
}

new_items()
{
    items = ({
        "grass",
        "The grass is beginning to die all around you",
        "stump",
        "The stump is nearly three meters in diamter with a large \n\
hole in the center",
        "tree",
        "The once noble Life Tree now lays dead on the ground",
        "hole",
        "Though perilous, jumping in the hole might be a proper \n\
method of remorse for cutting down the tree",
        "center",
        "The center of the trunk is hollow with a hole that is \n\
big enough to jump down",
        "trunk",
        "The trunk is quickly shrivelling and dying",
        "sky",
        "The sky is starting to look threatening and the temperature\n\
has dropped indicating a storm is coming",
    });
}