#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/keep/mon/ghoul2.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/keep/mon/ghoul.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/keep/mon/ghoul.c"),this_object());
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
   "/players/daranath/qualtor/keep/serv9.c","south",
   "/players/daranath/qualtor/keep/serv7.c","west",
    });

    }
  }

    init(){
      ::init();
add_action("search","search");
add_action("dar_south","south");
    }

search() {
write("Bits and pieces of the ruined servants quarters lies about the area.\n");
return 1;
 }

dar_south() {
if(present("ghoul")) {
write("The ghouls block you from continuing south!\n");
return 1; }
return 0;
}


