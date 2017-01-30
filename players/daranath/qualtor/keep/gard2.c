#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("man")) {
move_object(clone_object("/players/daranath/qualtor/keep/mon/gardener.c"),this_object());
}
  if(!arg){
    
    set_light(1);
    short_desc= "King's Garden";
    long_desc=
"Within the northern end of the open, grassy area just to the west\n"+
"of the ruined Qual'tor keep, a small garden of flowers grows here.\n"+
"The flowers certainly seem out of place, given the blackened\n"+
"and burnt condiition of the keep and its surrounding area.\n";

    items=({
     "wall","The stone wall stands in pieces about the keep",
     "pathway","The pathway leads around the southern side of the keep",
     "darkness","OOoooo....  darkness",
     "area","The small area was part of a courtyard of sorts",
     "keep","The blackened and burnt keep is a reminder of the former\n"+
            "glory of Qual'tor",
    });

    dest_dir=({
      "/players/daranath/qualtor/keep/area7.c","north",
      "/players/daranath/qualtor/keep/gard1.c","south",
      "/players/daranath/qualtor/keep/area4.c","east",
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


