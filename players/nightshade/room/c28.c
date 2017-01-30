/* inherit "players/nightshade/new_room"; */
inherit "/room/room";
#include <ansi.h>

/******************************************************************************
 * Program: c28.c
 * Path: /players/nightshade/room
 * Type: Room
 * Updated: October 2014 by Karash
 *
 * Purpose: A room object used for dragon treasure room. (No Teleport)
 *
 * History:
 *          
 ******************************************************************************/


object ob, gold;

reset(arg){

if(!present("coins"))
{
gold=clone_object("obj/money");
gold->set_money(12000+random(5000));
move_object(gold, this_object());
}

/* PATHS UPDATED */
if(!present("frenzy wand"))
{
ob=clone_object("players/nightshade/misc/frenzy_wand_new");
move_object(ob, this_object());
}

if(!present("black_opal"))
{
ob=clone_object("players/nightshade/misc/black_opal");
move_object(ob, this_object());
}

if(!present("moonstone"))
{
ob=clone_object("players/nightshade/misc/moonstone");
move_object(ob, this_object());
}

if(!present("topaz"))
{
ob=clone_object("players/nightshade/misc/topaz");
move_object(ob, this_object());
}

if(!present("onyx"))
{
ob=clone_object("players/nightshade/misc/onyx");
move_object(ob, this_object());
}


if(arg) return;
set_light(1);
short_desc = " Dark Cave";
long_desc =
"Hephaestus keeps his bountiful treasure in this large room. As\n"+
"you look around you see vast chunks of rock that has been melted\n"+
"by the reds incredible breath. If you are here you must be very\n"+
"lucky or very brave.\n";

dest_dir = 
({
"players/nightshade/room/c27", "south",
      });

add_property("no_teleport");
	  
}

