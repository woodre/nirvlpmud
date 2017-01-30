#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/mesa/"

inherit "room/room";

reset(arg) {
    if(!present("wall", this_object())){
       move_object(clone_object("/players/dreamspeakr/mesa/OBJ/bull_board.c"), this_object());
    }
    if(arg) return;

     set_light(1);

     short_desc = HIG+"Mancos Canyon"+NORM;
     long_desc =
         "		The cliff known as Mesa Verde towers high above here.  \n"+
         "Juniper bushes lay all about the ground. It appears that this \n"+
         "is a well traveled path, as there are tracks coming and going \n"+
         "in several directions.  Beside the path the river rustles\n"+
         "onward toward the bottom of the canyon.\n";

     items = ({
         "cliff","Ripple marks left on this once ancient seashore can be \n"+
            "seen in the stone wall before you.  Touching it you can feel what \n"+
            "appears to be some kind of hole.  Maybe you should 'look' closer \n"+
            "into it",
         "bushes","Hard wood bushes filled with colorful berries",
         "berries","Beautiful blue-green Juniper berries look quite \n"+
            "appetizing.  Myth says that they even have medicinal values",
         "ground","A sandy path winding around the lush green bushes.  In the \n"+
            "corner of your eye you notice a scorpion scurring in the sand trying \n"+
            "to burrow itself under a rock", 
         "path","This path seems to have been traveled by many men.  You have\n"+
            "heard tales of the Anasazi indians being in these parts",
         "tracks","They appear to be that of a human.  A shiver runs up your \n"+
            "spine at the thought of running into one of the indians you \n"+
            "suspect might have made them",  
         "river","Crystal clear waters that wind their way down through \n"+
            "the canyon.  Occasionally you see a large fish jump out to \n"+
            "catch a bug from atop the water", 
         "bottom","A rocky sandstone bottom winds alongside the riverbank",
         "canyon","Lush greens and tans fill the area.  Breathtaking as it is \n"+
            "you become quite curious as to what might be on the top of the mesa \n"+
            "before you",
         "hole","Thinking of what might be inside, you wonder if you should risk\n"+
            "sticking your fingers into this dark hole to 'grip' it",

});

dest_dir = ({
    PATH+"mv1.c","south",
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
    add_action("grip_hole","grip");
    add_action("listen","listen");
}

int grip_hole(string str){
   if (!str || str != "hole"){
     notify_fail("What would you like to grip?\n");
   return 0;
   }

   write("\n"+
          "\n"+
          "You slip your fingers into the small hole and pull \n"+
          "yourself up the cliff.\n"+
          "\n");
   say(this_player()->query_name()+" begins scaling the cliff wall.\n");
   move_object(this_player(),"/players/dreamspeakr/mesa/mv3.c");
   command("look",this_player());
   say(this_player()->query_name()+" climbs the cliff wall.\n");
   return 1;
   }

listen() {
  write("You close your eyes and listen.... you hear the babbling\n"+
        "river and the whisper of the wind through the pines.  Echos\n"+
        "of people singing seem to surround you. \n");
  return 1; 
}