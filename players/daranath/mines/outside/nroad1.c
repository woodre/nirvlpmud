#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Mountain Roadway";
    long_desc=
     "The small clearing outside of the cave entrance lies just to the\n"+
     "south of here. A roadway opens up and travels far to the north\n"+
     "leading into some foothills. Clouds obscure a tall and uninviting \n"+
     "peak in the distance.\n";

    items=({
     "cave","The cave lies on the eastern side of the clearing to the south",
     "roadway","A wide roadway winds its way into the foothills to the north",
     "peak","The peak of a small mountain rises up between a couple of the hills.\n"+
           "Clouds around the peak obscure what you think might be a fortress\n"+
           "of some kind",
     "cloud","The clouds surround the tall peak in the distance, hiding something",
     "clouds","The clouds surround the tall peak in the distance, hiding something",
     "clearing","A small clearing lies to the south, just outside the mining cave",
     "foothills","Tall foothills rises along both sides of the roadway to the north",
    });

    dest_dir=({
      "/players/daranath/mines/outside/nroad2.c","north",
      "/players/daranath/mines/entry1.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Nothing in interest is found along the roadway into the foothills.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

