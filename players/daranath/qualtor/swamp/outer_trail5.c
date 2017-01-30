#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Eastern Roadway ends";
    long_desc=
     "The small roadway ends here, a huge tree fallen across its width.\n"+
     "Tall reeds have grown in on the far side of the tree, causing\n"+
     "the roadway to literally disappear from sight. The only way\n"+
     "to go is back to the south.\n";

    items=({
     "road","The roadway is in poor shape and rarely travelled",
     "roadway","The roadway is in poor shape and rarely travelled",
     "rock","Large chunks of rock from the damaged wall are strewn about the area",
     "rocks","Large chunks of rock from the damaged wall are strewn about the area",
     "weeds","The weeds grow everywhere, everywhere!!!",
    });

    dest_dir=({
     "/players/daranath/qualtor/swamp/outer_trail4.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You just cannot find any way around the fallen tree.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


