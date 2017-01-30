inherit "/room/room.c";
object sock01, sock02, sock03, sock04;

void reset(int arg) 
{
    if(!sock01) sock01 = clone_object("/players/mizan/etheriel/subrealms/sockworld/beasties/sock.c");
    move_object(sock01, this_object());

    if(!sock02) sock02 = clone_object("/players/mizan/etheriel/subrealms/sockworld/beasties/sock.c");
    move_object(sock02, this_object());

    if(!sock03) sock03 = clone_object("/players/mizan/etheriel/subrealms/sockworld/beasties/sock.c");
    move_object(sock03, this_object());

    if(!sock04) sock04 = clone_object("/players/mizan/etheriel/subrealms/sockworld/beasties/sock.c");
    move_object(sock04, this_object());
    
    if(arg) return;
    set_light(1);

    short_desc = "Inside a GIANT pile of socks";
    long_desc =
    "    The chamber is largest here, and it seems that the air is almost\n"+
    "  breathable. Then on the ground you see what appear to be athletic tube\n"+
    "  socks and you're not quite so sure.\n";

    items = ({
        "ground",
        "The ground is soft and squishy. It is all made of LEFT socks.",

    });

    dest_dir = 
    ({
        "/players/mizan/etheriel/subrealms/sockworld/ROOMS/room04.c", "north",
        "/players/mizan/etheriel/subrealms/sockworld/ROOMS/room05.c", "east",
        "/players/mizan/etheriel/subrealms/sockworld/ROOMS/room01.c", "west",
    });
}
