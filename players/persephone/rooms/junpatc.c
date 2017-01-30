inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
object vines, vine;
reset(int arg){
if(!present("rabbit")) {
  move_object(clone_object("players/persephone/monster/rabbit"), TOB);
 }
 if (!arg) {
  set_light(0);
  short_desc="Jungle Path";
  long_desc="The path is getting much rougher and the trees in this part of the jungle\n" +
            "are crowding in on the path almost as if they are warning you against\n" +
            "proceeding any further. Perhaps it would be safer going back to the west.\n" +
            "The path however does continue east and there is another path to the\n" +
            "south both to the south and east you hear a wolflike howling.\n" +
            "\n";
  items=({"trees","The trees are almost black with very large leaves on some of the\n" +
                  "trees however are large vines",
          "leaves","They appear to be green but in this light you cannot be sure",
          "path","The path is extremely rocky and looks darker to both the south\n" +
                   "east",
          "rocks","Come on a rock is a rock and well these look rocklike and they\n" +
                  "definately not pebbles. One of the rocks however glimmers brightly\n" +
                  "sort of like gold",
          "sky","You must be joking you cannot see the sky all that you can see above is\n" +
                "the bottom of the jungle canopy",
          "vines","The vines look like you could swing from them however this would be unwise",
        });
  dest_dir=({"players/persephone/rooms/junpatb","west",
             "players/persephone/rooms/junpat6","south",
             "players/persephone/rooms/junpatd","east",
           });
 }
}
init(){
 ::init();
  add_action("choose1","find");
  add_action("choose1","choose");
  add_action("choose1","select");
  add_action("swing","swing");
}
choose1(str){
 if(str=="vines" || str=="vine"){
  write("You find a vine that you think you can swing from\n");
  say(capitalize(this_player()->query_name())+" chooses one of the vines to swing from\n");
  vine = this_player();
  return 1;
 }
}
swing(){
 if(vine==this_player()){
  write("You swing, like Tarzan, on the vine, you chose, north\n");
  this_player()->move_player("swinging from a vine north#"+"players/persephone/rooms/junpath4");
  return 1;
 }
 write ("You have not found a suitable vine to swing from\n");
 return 1;
}
