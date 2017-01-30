inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

     if(!present("guardian"))  {
       MOCO("/players/jareel/monsters/legends/legend_guardian.c"),this_object()); }
     if(!present("viewscreen"))  {
       MOCO("/players/jareel/general_stuff/viewscreen.c"),this_object()); }
     if(!present("dispenser"))  
       "/players/earwax/obj/loader"->load_it(this_object());
     if(arg) return;
     set_light(1);
     short_desc=(BOLD+"Hall of Legends"+NORM);
     long_desc=
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+GRN+"C"+NORM+"+"+BOLD+BLK+"M"+NORM+BLK+BRED+"@"+NORM+"     This is the entrance room to the Hall of Legends.  The room is\n"+ 
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+HIK+"B"+NORM+BLK+BRED+"@"+NORM+"     made of a dark stone similar to onyx, in which you can see a\n"+
       ""+BRED+BLK+"@"+NORM+HIB+"S"+NORM+"+"+HIR+"K"+NORM+BLK+BRED+"@"+NORM+"     reflection.  Passages lead to the north,east,west and a door\n"+
       ""+NORM+"-"+NORM+"-"+NORM+BOLD+"X"+NORM+"D"+BLK+BRED+"@"+NORM+"     leads out.  There is a view screen resting on a podium in the\n"+
       ""+BRED+BLK+"@@"+NORM+"E"+BLK+BRED+"@@"+NORM+"     middle of the room.  Out of the hall brings you to lance road.\n"+     
       "\n"+
       "E - Entrance/Exit : D - Depository  : "+HIB+"S"+NORM+" - Stone's Room  : "+HIR+"K"+NORM+" - Konya's Room\n"+	
       ""+HIB+"J"+NORM+" - Justin's Room : "+HIK+"B"+NORM+" - Bone's Room : "+GRN+"C"+NORM+" - Cooper's Room : "+BOLD+BLK+"M"+NORM+" - Magus's Room\n\n";
     items = ({
       "floor","The floor is made of a black stone",
       "wall","The wall is made of a black stone",
       "stone","The stone is as black as the night sky",
       "podium","you can read the viewscreen",
});

dest_dir = ({
     "/players/jareel/areas/statue/hall1.c","north",
     "/players/jareel/areas/statue/depository.c","east",
     "/players/jareel/areas/statue/lists.c","west",
});

}
init() {
     ::init();
       add_action("Get_the_fuck_out","out");
}

Get_the_fuck_out(){
     TP->move_player("leaves the hall of legends.#room/lanceroad4");
     return 1; 
}
