inherit "room/room";
object nurse, poppy;

reset(arg)
{
    if (arg) return;
    set_light(1);
    if (!nurse || !living(nurse))
    {
    nurse = clone_object("players/morgoth/MONSTERS/nurse");
    poppy = clone_object("players/morgoth/OBJ/poppy");
    move_object(poppy, nurse);
    move_object(nurse, this_object());
    }
    short_desc = "Penny Lane";
    long_desc = "Behind the shelter in the middle of a roundabout,\n" +
                "a pretty nurse is selling poppies from a tray.\n" +
                "And though she feels as if she's in a play,\n" +
                "She is anyway...\n";
    dest_dir = 
    ({
        "players/morgoth/CASTLE/pen_lane1", "east",
         "players/morgoth/CASTLE/field1", "south",
        "players/morgoth/CASTLE/main_gate", "north"
    });
}
