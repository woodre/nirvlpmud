#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Just outside the Gardens";
    long_desc=
"Deep within the shadows that hide alongside the outer wall of\n"+
"the ruined keep, this small open area once grew rich with grass\n"+
"that is no more. A small garden still flourishes to the north,\n"+
"while the former entrance to the keep lies just to the north\n"+
"and east of here.\n";

    items=({
     "garden","The garden to the north seems to be well kept",
     "wall","The stone wall stands in pieces about the keep",
     "pathway","The pathway leads around the southern side of the keep",
     "darkness","OOoooo....  darkness",
     "shadows","The shadows are deepened by the crumbling wall",
     "area","The small area was part of a courtyard of sorts",
     "keep","The blackened and burnt keep is a reminder of the former\n"+
            "glory of Qual'tor",
    });

    dest_dir=({
      "/players/daranath/qualtor/keep/gard1.c","north",
      "/players/daranath/qualtor/keep/path1.c","south",
      "/players/daranath/qualtor/keep/area2.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
write("A search of the area brings nothing of interest.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


