inherit "/room/room.c";
#include "/obj/ansi.h"

object door1, door2;
object machine;

void reset(int arg)
{
    if (arg) return;
    set_light(1);

    short_desc = HIY + "The OverPowerLord's Landing to the Proving Grounds" + NORM;
    long_desc =
        "    " + HIB + ">>>" + NORM + " " + HIY +
        "[L A N D I N G   T O   T H E   P R O V I N G   G R O U N D S]" +
        NORM + " " + HIB + "<<<" + NORM + "\n" +
        "    This is one level above the legendary Proving Grounds of the OverPowerLord.\n"+
        "  A clearly printed sign indicates by proceeding downwards, you are entering\n"+
        "  the hazards of the proving grounds- which include combat, foul language,\n"+
        "  disorientation, aggressive roaming monsters, and of course the massive, \n"+
        "  sprawling complex of the maze itself. Are you brave enough to enter?\n"+
        "  If so, man up and proceed downwards to a realm of violence, rewards, and\n"+
        "  all sorts of interesting, vulgar, yet highly rewarding possibilities...\n\n"+
        "  " + HIY + "GO DOWN TO ENTER THE PROVING GROUNDS\n" +
        "  " + HIY + "GO UP FOR THE ENTRANCE PLAZA\n" + NORM;

    items = ( {

        "sign",
        "New Players: This area is really not for you.",

    });

    dest_dir =
    ( {
        "/players/mizan/opl/ROOMS/entrance.c", "up",
        "/players/mizan/opl/CELLS/C118.c", "down",
    });

    set_no_clean(1);

    if (!machine)
    {
        machine = clone_object("/players/mizan/opl/beasties/gatekeeper.c");
        move_object(machine, this_object());
    }

    if (!door1)
    {
        door1 = clone_object("obj/door");
        door1->set_dir("inside");
        door1->set_door_room("/players/mizan/opl/ROOMS/club");
        door1->set_type("high-security");
        door1->set_code("clubdoor");
        door1->set_door_long("This is a heavy steel door, several inches thick. There is a peephole in it,\n"+
                             "but from your vantage point you can't see anything. This door appears to go\n"+
                             "to some sort of maintenance area within the proving grounds... or does it?\n");
        door1->set_locked(1);
        door1->set_closed(1);
        door1->set_can_lock(0);

        door2 = clone_object("obj/door");
        door2->set_dir("south");
        door2->set_door_room("/players/mizan/opl/ROOMS/landing");
        door2->set_type("high-security");
        door2->set_code("clubdoor");
        door2->set_door_long("This is a heavy steel door, several inches thick.\n");

        door1->set_door(door2);
        door2->set_door(door1);
        move_object(door1, this_object());
        move_object(door2, "/players/mizan/opl/ROOMS/club");
        door1->set_both_status();
    }
}



