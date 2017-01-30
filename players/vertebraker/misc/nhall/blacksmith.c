#define tp this_player()
#define tpn tp->query_name()

inherit "/players/vertebraker/closed/std/room";

void
reset(int arg)
{
    object s;

    if(arg) return;
    set_light(2);
    set_short("Hall of Apprentices [Smithy]");
    set_long("\
  A blazing fire roars up in the middle of a deep, dark pit\n\
here.  Glowing orange pieces of hot, freshly forged metal\n\
hang from a rear weapons rack.  A basin full of cool, fresh\n\
water bubbles in a wooden basin on the floor.  A heavy metal\n\
rack with slabs of unheated metal lie next to the basin, and\n\
a small wooden stool sits in the corner.\n");
    add_item(({ "fire", "forge" }), "\
The blazing red forge rises up from the depths of an earthen\n\
pit that extends many meters beneath your feet");
    add_item(({ "dark pit", "pit" }), "\
A shadowy dark, black pit that is momentarily lit with the flicker\n\
from the hot, roasting flames that dance from its depths");
    add_item(({ "pieces", "glowing metal", "metal" }), "\
Hot, orange, glowing metal rests on a rear weapons rack.  You\n\
recognize some of them as blades, axes, and polearms");
    add_item(({ "blades", "axes", "polearms", "weapons" }), "\
Many different kinds of metal weapons.  They are taken from the\n\
Smithy by a servant boy to the equipment shop every once in a\n\
while");
     add_item(({ "rack", "rear", "weapons rack" }), "\
Shiny, hot weapons hang from the rear rack against the wall");
     add_item("basin", "\
The wooden basin has been constructed out of a thick, hard\n\
wood.  Gallons of cool, fresh water floats inside of it");
     add_item("metal rack", "\
Heavy slabs of unforged metal rest on this thick metal rack");
     add_item("slabs", "\
The thick slabs of metal are still virgin against the heated,\n\
high degree flames of the forge");
     add_item("corner", "\
A wooden stool sits here");
     add_item("stool", "\
An extremely short stool about 9 inches off the ground, for\n\
a very small creature to sit upon");
     set_chance(1);
     add_msg("Flames burst from the forge momentarily.");
     add_object("/players/vertebraker/misc/nhall/smithy");
     add_exit("/players/softly/nhall/rooms/n1", "north");
     add_listen("main", "\
The molten metal within the forge bubbles and rolls around,\n\
creating an interesting symphony.");
     add_smell("main", "\
Acrid smoke and heavy amounts of unhealthy gases.");
}

string
realm()
{
    return "NT";
}

status
query_no_fight()
{
    return 1;
}

status
cmd_read(string str)
{
    if(str == "the sign" || str == "sign")
    {
      command("l at sign", this_player());
      return 1;
    }
    return 0;
}

status
cmd_list()
{
    command("l at sign", this_player());
    return 1;
}

void
init()
{
    ::init();
    if(!present("sign", this_object())) move_object(clone_object("/players/vertebraker/misc/nhall/sign"), this_object());

    add_action("cmd_read", "read");
    add_action("cmd_list", "list");
}
