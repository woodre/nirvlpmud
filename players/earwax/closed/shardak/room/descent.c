/*
 * Shardak guild is (c) Dragnar/John + Balowski/Rasmus
 * Change log:
 * 950422 - created, 950508 - finished writing
 * 030715 - added color, exits readable by shardaks only, tweaked desc [linus]
 * 030719 - fixed long to allow set_items [linus]
 */

#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/people.h"
#include "../include/ansi.h"
#define VBOARD "/players/earwax/closed/misc/board2"

inherit ROOM;

void
create()
{
    ::create();
    set_short(RED+"Descent into grotto"+NORM);
    set_long(HIK+"\
The cold gallery leads down to the lower regions of the caves.\n\
This tunnel has been recently excavated; rubble and debris from the\n\
crudely cut tunnel walls cover the floor and make walking uneasy.\n\
The tunnel grows narrower and darker as it continues to descend in a\n\
northernly direction. A makeshift staircase leads up.\n"+NORM);
    set_items( ([
({ "rubble", "debris", }) : "\
A thick layer of chips of rock and boulders cover the floor, making\n\
the floor fairly even but less than immovable.\n",
({ "floor", "walls", }) : "\
The more you look, the more you are convinced that this tunnel was\n\
dug in haste to widen a big crack in the rock.\n",
({ "staircase", "stair", }) : "\
Built from odd pieces of wooden planks, it compensates for the initial\n\
three foot drop from the upper grotto and down into the tunnel.\n",
    ]) );
    set_exits(([
        "south":   (PATH + "plair"),
        "up" :   (PATH + "grotto"),
        "north": (PATH + "deepdown"),
        ]));
    set_light(1);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}

/* Room long description, shows exits only to Shards */

void
long(string arg) {
 if(!arg) {
  if((int)this_player()->query_brief() != 2) 
   write(RED+"Descent into grotto\n"+NORM);
    ::long(arg);
  if (present("shardak_mark",this_player())) 
   write("\t"+NORM+RED+"\The exits are: north, south, and up.\n"+NORM);
    return;
 }
 else ::long(arg);
}

status
allow_read(object who)
{
    if (who && (string) who->query_guild_name() == GUILDNAME) return 1;
}

void
reset(int arg)
{
    object          board;

    ::reset(arg);
    if (!present("bulletin board")) {
        board = clone_object(VBOARD);
        board->set_name("bs");
        board->set_size(50);
        board->set_short("A board with BS notes");
        board->set_readers(symbol_function("allow_read", this_object()));
        board->set_editors(LAW);
        move_object(board, this_object());
    }
}






