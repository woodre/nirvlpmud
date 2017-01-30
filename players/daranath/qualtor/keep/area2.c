#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Open area near the Ruined Keep";
    long_desc=
     "Just to the eastern side of the protective wall surrounding the\n"+
     "ruined keep within Qual'tor, a small area opens up to the\n"+
     "east from here, a pathway leading into darkness.\n";

    items=({
     "wall","The stone wall stands in pieces about the keep",
     "pathway","The pathway leads around the southern side of the keep",
     "darkness","OOoooo....  darkness",
     "area","The small area was part of a courtyard of sorts",
     "keep","The blackened and burnt keep is a reminder of the former\n"+
            "glory of Qual'tor",
    });

    dest_dir=({
      "/players/daranath/qualtor/keep/area3.c","north",
      "/players/daranath/qualtor/keep/path2.c","south",
      "/players/daranath/qualtor/keep/path4.c","east",
      "/players/daranath/qualtor/keep/area1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
write("Grass actually seems to be growing in this small area.\n"+
      "A strange thing within the darkness of Qual'tor.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


