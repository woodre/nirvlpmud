#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Mountain Cliff";
    long_desc=
     "The edge of the mountain drops suddenly, creating a huge cliff\n"+
     "facing that rises several hundred feet above the hills below.\n"+
     "You can see the ruined city of Qual'tor from here, as well as\n"+
     "the DarkenWood and its many dangers.\n"+
     "A tall wooden pole sticks from the ground here.\n";

    items=({
     "edge","The edge of the mountain drops to the ground below",
     "mountain","The mountain its seems very angry, with the dark clouds\n"+
                "milling about its apex",
     "cliff","The cliff overlooks the land below",
     "city","The ruined city of Qual'tor is just to the east of the mountain path",
     "darkenwood","The fabled DarkenWood is a place of many dangers and horrors,\n"+
                  "just waiting for you to try your luck. A small\n"+
                  "village sits in the far southern corner of it",
"pole","The wooden pole is set into the ground as some sort of sacrifical\n"+
     "device. A set of mancles are attached to the pole itself, bringing\n"+
     "about a vision of a maiden being held captive against her will",
     "manacles","The manacles are covered in blood and rust",
     "hills","The hills are far below your position",
    });

    dest_dir=({
      "/players/daranath/clearing/marea4.c","north",
      "/players/daranath/clearing/mpeak.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find little bits of blood stained cloth here.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


