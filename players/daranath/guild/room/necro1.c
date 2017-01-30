#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Necromancer Stronghold";
    long_desc=
     "The entrance to the Necromancer Stronghold. The main body\n"+
     "of the guild hall lies to the north. Nothing much of note\n"+
     "is about this area.\n";

    items=({
     "guild","The guild hall of the Necromancers is to the north",
    });

    dest_dir=({
      "/players/daranath/guild/room/necro2.c","north",
      "/players/daranath/qualtor/necro_entry.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_north","north");
    }

    search(){
    write("Bits of bone and areas of dried blood are all about the room.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    dar_north() {
    if(!present("necro_ob",this_player())) {
    write("You must be a Necromancer to go any further into the guild hall.\n");
    return 1; }
    return 0; 
    }

realm() { return "NT"; }
