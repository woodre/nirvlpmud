inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/mesa/"


reset(arg) {
     move_object(clone_object("/players/dreamspeakr/mesa/NPC/lizard.c"), this_object());
     if(arg) return;
     set_light(1);

     short_desc = HIG+"Mesa Verde Cliffside"+NORM;
     long_desc =
         "\n"+
         "\tThe climb up this wall becomes more difficult, small \n"+
         "holes in the wall continue to be the only source of scaling \n"+
         "the cliffside.  The air becomes thinner and slightly cooler. \n"+
         "'Peer'ing down now might prove to be quite dangerous. \n"+
         "\n"
;

     items = ({
         "holes","Dark and forbodding you feel a little leary \n"+
            "as you carefully place your hands and feet in each one \n"+
            "to scale the cliff. Above you an soars the sky searching \n"+
            "for a resting spot",
         "wall","Rocky sandstone wall that goes straight up, giving\n"+
            "you the impression that it almost reaches the clouds",
         "cliffside","A soft stone surface bears the markings of many \n"+
            "travelers",
         "eagle","Its cry echos through the canyon as it gracefully \n"+
            "soars above you",

});

dest_dir = ({
    PATH+"mv5.c","climb",
    PATH+"mv3.c","descend",
});

}
init(){
int i;
if (!dest_dir) return;
i = 1;
while(i < sizeof(dest_dir)){
    add_action("move",dest_dir[i]);
    i+=2;
  }
    add_action("peer_down","peer");
    add_action("listen","listen");
}

int peer_down(string str){
    if (!str || str != "down"){
      notify_fail("What would you like to peer at?\n");
    return 0;
    }

    write("As you look down, fear overwhelms you.  You notice \n"+
          "that the river seems so tiny.  Your grip loosens and your \n"+
          "knees begin to quiver.  The ground swells up toward you as \n"+
          "your body plummets to the canyon bottom.\n");
    say(this_player()->query_name()+" plummits to the ground below.\n");
    move_object(this_player(),"/players/dreamspeakr/mesa/mv2.c");
    command("look",this_player());
    say(this_player()->query_name()+" falls to the bottom of the canyon.\n");
    this_player()->add_hit_point(-5-random(20));
    return 1;
    }

listen() {
    write("You close your eyes and listen.... you hear sounds of people \n"+
          "singing.  Eagles squawk as they fly above your head.\n");
    return 1; 
}
