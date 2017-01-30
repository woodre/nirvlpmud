inherit "/players/jareel/room";
#include "/players/jareel/define.h"

      reset(arg) {

      if(!present("londros"))  {
        MOCO("/players/jareel/monsters/chaos/londros.c"),this_object());
      }
    
      if(arg) return;
      if(!present("tower"))  {
        MOCO("/players/jareel/general_stuff/tower.c"),this_object()); }
      
      set_light(1);
      short_desc=(GRN+"The Chaos Wood"+NORM);
      long_desc=
        ""+HIK+"@"+NORM+GRN+"#####"+NORM+"   Large colorful trees press up against the menacing tower.\n"+
        ""+HIK+"@"+NORM+"---"+BOLD+"X"+NORM+GRN+"#"+NORM+"   The path to the south and west lead deep into the Wood.\n"+
        ""+HIK+"@"+NORM+GRN+"#"+NORM+"|+|"+GRN+"#"+NORM+"   The trees allow only a few rays of light past their dense\n"+
        ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+NORM+GRN+"###"+NORM+"   canopy, creating deep shadows, that seem to anticipate\n"+
        ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   your every move.\n";
      items = ({
        "road","The road is made of a grayish dirt, it has seen a lot of travel",
        "shadow","The shadows flicker over the dirt road",
        "dirt","The fine gray dirt sifts between your fingers as you examine it",
        "canopy","Most of the sky is obscured here due to the large amount of trees",
        "sky","The sky is hard to see past the tree cover",
        "trees","The trees loom overhead menacing your every move",
        "path","The road is made of a grayish dirt, it has seen a lot of travel",
        "forest","Large gnarled intertwined branches make up the walls of the wood",
        "shadows","The shadows flicker over the dirt road",
        "wood","The trees loom overhead menacing your every move",
        "tree","The trees loom overhead menacing your every move",
        "light","The light is obscured by the canopy of trees",
        "rays","The light is obscured by the canopy of trees",
});

dest_dir = ({
      "/players/jareel/areas/chaos/forest7","west",
      "/players/jareel/areas/chaos/forest5","south",
      });
}

init() {
     ::init();
       add_action("tower","enter");
       add_action("Search","search");
       add_action("pass","pass");
}

tower(){
      TP->move_player("enters the tower.#players/jareel/areas/chaos/tower/floor1");
      return 1;
      }

pass(){
      TP->move_player("pushes into the forest.#players/jareel/areas/chaos/woods2/cwf11");
      return 1;
      }

Search(str) {
      if(!str) { write("Search what?\n"); return 1; }
        write("You search the "+str+" but find nothing special.\n");
        say(this_player()->query_name()+" searches around for something.\n");
      return 1;
}
