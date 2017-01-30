inherit "/room/room.c";
object ob;
object radio;
object pda;
object meter;
object goggles;
object detector;

reset(int arg) 
{

    if(arg) return;
    set_light(1);

    short_desc = "02h Nexus Laboratories East";
    long_desc =
    "    You are in a simple, super-sparse white room that resembles a racquetball\n"+
    "  court in appearance and size. The walls are almost a glowing white however.\n"+
    "  A variety of testing equipments and other assorted gadgetry is here sitting\n"+
    "  on a large white granite workbench. On the workbench is a simple sign.\n";   

    items = ({

        "floor",
        "The floor appears to be made of some sort of milky white obsidian.",

        "sign",
        "The white cardboard sign left on one of the benches says 'reload' to\n"+
        "reload all equipment in this space",

    });

    dest_dir = 
    ({
        "/players/mizan/core/02h/room11.c", "up",
        "/players/mizan/core/02h/room13.c", "west",
    });


    set_no_clean(1);

    call_out("load_my_stuff", 1);

}

query_no_fight() { return 1; }

init()
{
   ::init();
  if(this_player() && this_player()->query_level() < 20)
    {
      this_player()->hit_player(5000000);
    }
   add_action("on_reload","reload");
}

on_reload()
{
    write("You push the reload button.\n");
    say(this_player()->query_name() + " pushes the reload button.\n");
    load_my_stuff();
    return 1;
}

load_my_stuff()
{

    if(!detector || environment(detector) != this_object())
    {
        detector = clone_object("/players/mizan/core/02h/item-roomdetector.c");
        move_object(detector, this_object());
        tell_room(this_object(), detector->short() + " materializes into the room.\n");
    }

    if(!radio || environment(radio) != this_object())
    {
        radio = clone_object("/players/mizan/mbv2/items/walkie-talkie.c");
        move_object(radio, this_object());
        tell_room(this_object(), radio->short() + " materializes into the room.\n");
    }

    if(!pda|| environment(pda) != this_object())
    {
        pda = clone_object("/players/mizan/mbv2/items/pda.c");
        move_object(pda, this_object());
        tell_room(this_object(), pda->short() + " materializes into the room.\n");
    }

    if(!meter|| environment(meter) != this_object())
    {
        meter = clone_object("/players/mizan/mbv2/items/balance.c");
        move_object(meter, this_object());
        tell_room(this_object(), meter->short() + " materializes into the room.\n");
    }

    if(!goggles|| environment(goggles) != this_object())
    {
        goggles = clone_object("/players/mizan/mbv2/items/goggles.c");
        move_object(goggles, this_object());
        tell_room(this_object(), goggles->short() + " materializes into the room.\n");
    }

}
