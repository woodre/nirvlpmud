
inherit "room/room";

object heather, birds;
/*
object heather, bush, birds;
*/

reset(arg) {
/*
    if (!bush) {
          bush = clone_object("players/catwoman/bush");
          move_object(bush, this_object());
    }
*/
        if (!heather) {
                heather = clone_object("players/catwoman/monster/heather");
                move_object(heather, this_object());
        }
      if (!birds){
          birds = clone_object("players/catwoman/monster/birds");
          move_object(birds, this_object());
     }

        if (arg) return;

        set_light(1);

        short_desc = "The Garden of Delight";

        long_desc = "A lush garden, filled with exotic and tropical plants.\nYou hear the sound of love birds fullfilling their dreams.\nIn the center of the garden is a hot tub hewn from solid stone.\n";

        dest_dir = ({
             "players/catwoman/tl", "out",
             
                
        });

}

init() {

        ::init();

        say(this_player()->query_name()+" has joined you in the Garden.\n");

        write("Heather softly says: Welcome "+this_player()->query_name()+" to my garden of delight.\n");

}

