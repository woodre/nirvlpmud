inherit "/room/room.c";
object ob;
object radio;
object pda;
object meter;
object goggles;
object detector;

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "Tyrell Corporation - NLAX Madera Laboratory";
   long_desc =
   "    This is a large, brightly lit but ultimately very cold and unforgiving\n"+
   "  sort of a room. There are no windows, only large, heavy looking doors that\n"+
   "  face the north and west exits. A shimmering portal lies open to the south.\n"+
   "  Equipment and materials lie in large organized bins all over the eastern\n"+
   "  wall. Large workstations stand with half-completed projects in the works.\n"+
   "  For some reason, you are very nervous standing in this room.\n";
   
  items = ({
    "door",
    "This is a locked, heavy metal blast door.\n"+
    "You need the proper key to unlock and open it from the inside.",

    "floor",
    "The floor appears to be made of steel, but has a scuff-proof paint on it.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/core/02h/room08.c", "south",
  });

  set_no_clean(1);
}

init()
{
   ::init();
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