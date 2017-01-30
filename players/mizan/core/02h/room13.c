inherit "/room/room.c";
object ob;
object catapult;
object flexgun;
object ammo;
object slippers;

void reset(int arg) 
{
    
    if(!catapult)
    {
        catapult = clone_object("/players/mizan/closed/poly/guild-catapult.c");
        move_object(catapult, this_object());
    }



    if(arg) return;
    set_light(1);

    short_desc = "02h Nexus Laboratories West";
    long_desc =
    "    You are in a simple, super-sparse white room that resembles a racquetball\n"+
    "  court in appearance and size. The walls are almost a glowing white however.\n"+
    "  A variety of testing equipments and other assorted gadgetry is here sitting\n"+
    "  on a large white granite workbench.\n";   

    items = ({

        "floor",
        "The floor appears to be made of some sort of milky white obsidian.",

        "sign",
        "The white cardboard sign left on one of the benches says 'reload' to\n"+
        "reload all equipment in this space",
    });

    dest_dir = 
    ({
        "/players/mizan/core/02h/room12.c", "east",
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

    if(!flexgun || environment(flexgun) != this_object())
    {
        flexgun = clone_object("/players/mizan/etheriel/items/spuck-flexgun.c");
        move_object(flexgun, this_object());
        tell_room(this_object(), flexgun->short() + " materializes into the room.\n");
    }

    if(!ammo || environment(ammo) != this_object())
    {
        ammo = clone_object("/players/mizan/etheriel/items/spuckballs-extinf.c");
        move_object(ammo, this_object());
        tell_room(this_object(), ammo->short() + " materializes into the room.\n");
    }

    if(!slippers|| environment(slippers) != this_object())
    {
        slippers = clone_object("/players/mizan/etheriel/items/bunny-slippers.c");
        move_object(slippers, this_object());
        tell_room(this_object(), slippers->short() + " materializes into the room.\n");
    }

}
