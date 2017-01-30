#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
move_object(clone_object("/players/daranath/qualtor/mon/chld_light.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/chld_light.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/chld_light.c"),this_object());
    
    set_light(1);
    short_desc= "Mountain Cave";
    long_desc=
      "The mountain cave is lit by candles running the length of both\n"+
      "walls here, giving the area a dim luminesence. The children of\n"+
      "light wait here in hiding until the time when they can bring\n"+
      "Qual'tor back to its former state of glory.\n";

    items=({
     "candle", "The candles give off the only light in the cave",
     "cave", "The cave is very plain and simple",
     "mouth", "The cave mouth is filled with shadows",
    });

    dest_dir=({
      "/players/daranath/clearing/marea6.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing of interest within the cave.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


