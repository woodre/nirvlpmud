#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "King's Garden";
    long_desc=
"Within the middle of the open, grassy area to the west of the\n"+
"ruined Qual'tor keep, a small garden of flowers grows here. The\n"+
"flowers certainly seem out of place, given the blackened and\n"+
"burnt condition of the surrounding area. The garden continues\n"+
"to the north, while the keep's remains rise to the east.\n";

    items=({
"flowers","A variety of flowers grow here, well kept and in good health",
"flower","A variety of flowers grow here, well kept and in good health",
"grass","The grass is thick and tasty (for a horse)",
     "wall","The stone wall stands in pieces about the keep",
     "pathway","The pathway leads around the southern side of the keep",
     "darkness","OOoooo....  darkness",
     "area","The small area was part of a courtyard of sorts",
     "keep","The blackened and burnt keep is a reminder of the former\n"+
            "glory of Qual'tor",
    });

    dest_dir=({
      "/players/daranath/qualtor/keep/gard2.c","north",
      "/players/daranath/qualtor/keep/area1.c","south",
      "/players/daranath/qualtor/keep/area3.c","east",
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


