#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Mausoleum Entrance";
    long_desc=
  "Small amounts of light filter about the area here, bringing some\n"+
  "vision to your eyesight. Rows of bodies are set into the walls here,\n"+
  "knights and other such honored dead. Each such body has a small niche\n"+
  "cut into the walls, which remain the same white marble as found elsewhere\n"+
  "within the complex. The gravesite continues to the north and south\n"+
  "from here.\n";

    items=({
      "shadows", "The shadows run deep in this area, playing tricks with\n"+
                 "your mind",
});

    dest_dir=({
      "/players/daranath/underdark/crypt/war1.c","north",
      "/players/daranath/underdark/crypt/war3.c","south",
      "/players/daranath/underdark/crypt/hall1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    }

    search(){
    write("You find nothing amongst the graves.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



arate() { return "YES"; }
