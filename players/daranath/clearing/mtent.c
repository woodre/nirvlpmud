#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "room/room";
int a;

reset(int arg){
a = random(3);
if(!present("undead")){
if(a == 0) {move_object(clone_object(ROOT+"mon/un_guard1.c"),this_object()); }
if(a == 1) {move_object(clone_object(ROOT+"mon/un_guard2.c"),this_object()); }
}
  if(!arg){
    
    set_light(1);
    short_desc= "Mountain Tent";
    long_desc=
     "A dark red tent stands comforted by the shade of an overhanging\n"+
     "mountain cliff. Banners hang from the corners of the large tent,\n"+
     "lazily moving in the slight breeze. A soft glow comes from\n"+
     "within the entrance.\n";

    items=({
     "tent","The tent is a dark crimson color, the same as the uniforms\n"+
            "of the two guards that stand by the entrance",
     "banners","The Crimson banners have an oriental dragon upon them",
     "cliff","The cliff is part of the dangers of the mountain",
     "shade","The shadow of the cliff keeps the tent cool",
     "glow","The soft glow appears to be candle light from within the tent",
    });

    dest_dir=({
      "/players/daranath/clearing/marea2.c","north",
      "/players/daranath/clearing/mpeak.c","east",
      "/players/daranath/clearing/mtent3.c","tent",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_tent","tent");
    }

    search(){
    write("The area around the tent is kept clear of debris.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_tent() {
  if(present("kaya")) {
write("Kaya stands in your way, shaking her head slowly.\n");
  return 1; }
return 0;
}
