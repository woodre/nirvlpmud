#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/bguard4.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/bguard4.c"),this_object());
  if(!arg){
    
    set_light(1);
    short_desc= "Inside the Mountain Tent";
    long_desc=
"In the front half of the tent, a soft candle light reflects off the dark\n"+
"red interior, bathing the area in a crimson glow. Various items are scattered\n"+
"about the tent itself, most nothing more then cheap items stolen at\n"+
"one point or another. You can move further back into the tent.\n";
                                                                      
    items=({
"candle","candles are burning here for a light source",
"items","A variety of cheap good are spread about the tent",
"tent","The tent is dark red and made of soft leather",
"light","The light comes from candles in the tent itself",
    });

    dest_dir=({
"/players/daranath/clearing/mtent2.c","forward",
      "/players/daranath/clearing/mtent.c","exit",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_forward","forward");
    }

    search(){
write("It would take too long to go through the items and see if anything is\n"+
      "worth taking.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_forward(){
if(present("guard")){
write("The crimson guardsman prevents you from moving further into the tent.\n");
return 1; }
return 0;
}

