#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Central Qual'tor";
    long_desc=
     "The dark pathway continues along the southern edge of the ruined\n"+
     "keep within Qual'tor. The pathway continues east and west\n"+
     "from here.\n";

    items=({
     "wall","The stone wall stands in pieces about the keep",
     "pathway","The pathway leads around the southern side of the keep",
     "darkness","OOoooo....  darkness",
     "area","The small area was part of a courtyard of sorts",
     "keep","The blackened and burnt keep is a reminder of the former\n"+
            "glory of Qual'tor",
    });

    dest_dir=({
      "/players/daranath/qualtor/keep/area2.c","north",
      "/players/daranath/qualtor/keep/path3.c","east",
      "/players/daranath/qualtor/keep/path1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of the East Road brings nothing of value.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


