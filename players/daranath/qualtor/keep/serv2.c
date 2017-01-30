#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!present("undead")) {
  int a; a = 0;
   while(a<4) {
   int b; b = random(5);
if(b == 0) move_object(clone_object("/players/daranath/qualtor/keep/mon/zombie1.c"),this_object());
if(b == 1) move_object(clone_object("/players/daranath/qualtor/keep/mon/zombie1.c"),this_object());
if(b == 2) move_object(clone_object("/players/daranath/qualtor/keep/mon/zombie2.c"),this_object());
if(b == 3) move_object(clone_object("/players/daranath/qualtor/keep/mon/zombie2.c"),this_object());
if(b == 4) move_object(clone_object("/players/daranath/qualtor/keep/mon/ghoul.c"),this_object());
  a++; }
}
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
   "/players/daranath/qualtor/keep/serv4.c","north",
   "/players/daranath/qualtor/keep/serv3.c","south",
   "/players/daranath/qualtor/keep/serv6.c","east",
   "/players/daranath/qualtor/keep/serv1.c","west",
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
