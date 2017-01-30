#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/mons/un_knight2.c"),this_object());
move_object(clone_object("/players/daranath/mons/un_knight1.c"),this_object());
  if(!arg){
    
    set_light(1);
    short_desc= "Mausoleum Chamber";
    long_desc=
  "Small amounts of light filter about the area here, bringing some\n"+
  "vision to your eyesight. Rows of bodies are set into the walls here,\n"+
  "knights and other such honored dead. Each such body has a small niche\n"+
  "cut into the walls, which remain the same white marble as found elsewhere\n"+
  "within the complex. The gravesite continues to the north from\n"+
  "here.\n";

    items=({
      "shadows", "The shadows run deep in this area, playing tricks with\n"+
                 "your mind",
  });

    dest_dir=({
      "/players/daranath/underdark/crypt/war2.c","north",
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
