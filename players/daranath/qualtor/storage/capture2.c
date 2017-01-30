#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/captured.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/hogre2.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/hogre2.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"(*unknown*)");
    long_desc=
     "A pile of furs and old cloaks are centered within this small\n"+
     "chamber, surrounded by boxes and crates of all sizes. It looks\n"+
     "as if someone lives here, although the area does not allow much\n"+
     "comfort at all. The only exit is back through the dark\n"+
     "building.\n";

    items=({
     "furs","Old animal furs help create a makeshift bed",
     "cloaks","Old cloaks lies about the pile, helping to soften the bed",
     "box","The boxes make the area seem like a warehouse",
     "boxes","The boxes make the area seem like a warehouse",
     "crate","The crates make the area seem like a warehouse",
     "crates","The crates make the area seem like a warehouse",
    });

    dest_dir=({
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing about the small chamber.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

