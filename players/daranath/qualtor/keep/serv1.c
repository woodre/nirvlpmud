#define tp this_player()->query_name()
inherit "room/room";
   int a;

reset(int arg){
   a=0;
  if(!arg){

    set_light(1);
    short_desc= "Ruined Servant's Quarters";
    long_desc=
     "The dark pathway turns to the north here, leading up to the\n"+
     "burnt out shell of the ruined keep. The shadow from the keep\n"+
     "casts a pall over this area, keeping you on your toes.\n";

    items=({
   "pathway","The pathway runs from the ruined keep to the protective wall",
   "keep","The keep was destroyed during the downfall of Qual'tor",
   "shadow","The shadow of the keep cloaks this area in darkness",
   "shell","The shell of the blackened keep stands as a reminder of the former glory of Qual'tor",
   "toes","You know what your toes look like",
    });

    dest_dir=({
     "/players/daranath/qualtor/keep/serv2.c","east",
     "/players/daranath/qualtor/keep/path3.c","exit",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search() {
write("Bits and pieces of the ruined servants quarters lies about the area.\n");
return 1;
 }
