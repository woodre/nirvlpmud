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
     "/players/daranath/qualtor/keep/serv2.c","south",
     "/players/daranath/qualtor/keep/serv5.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_west","west");
    }

dar_west(){
  if(a == 0) {
  if(!present("necro_ob",this_player())) {
move_object(clone_object("/players/daranath/guild/mon/skel_guardian.c"),this_object());
write("As you try to pass through the area, something climbs from the gound!\n");
say("As "+tp+" walks through the area, something attacks!!!\n");
    a++;
 return 1; }
write("\nThe shadow of the ruined keep falls about the area.\n\n");
}
  if(a>0) {
write("\nThe shadow of the ruined keep falls about the area.\n\n");
say(tp +" searches the area.\n");
 return 1;
    }
}

search() {
write("Bits and pieces of the ruined servants quarters lies about the area.\n");
return 1;
 }
