inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/mesa/"


reset(arg) {
     move_object(clone_object("/players/dreamspeakr/mesa/NPC/eagle.c"), this_object());
     if(arg) return;
     set_light(1);

     short_desc = HIG+"Mesa Verda Cliffside"+NORM;
     long_desc =
         "\n"+
         "\tStrong winds make climbing more difficult as the top \n"+
         "of the mesa comes within reach.  The sounds of singing become \n"+
         "louder and more distinct.  The dark holes, used to climb this \n"+
         "wall, seem larger and easier to grip.  There is a small rope \n"+
         "hanging over the side of the mesa.\n"+
         "\n"
;

     items = ({
         "top","It's within reach, you can just barely make out the \n"+
            "crest of the mesa.  Suddenly you see something hurl by your \n"+
            "head and plummet to the ground below you.  You feel a certain \n"+
            "fear of what might await you",
         "mesa","Looking up toward the mesa you see small sprigs of grass \n"+
            "spilling over the side.  You notice the grass seems to be \n"+
            "moving slightly",
         "grass","Healthy green grass flows over the side of the cliff \n"+
            "tickling your nose slightly as you climb.  Be sure not to \n"+
            "sneeze, you wouldnt want to alert anyone above you of your \n"+
            "approach",
         "holes","They appear to be quite large.  You get the impression \n"+
            "that this wall is more traveled then what first met the eye",
         "wall","Your long journey up this treacherous wall seems to be \n"+
            "close to the end.  Your body tires as you approach the top",
         "rope","A strong hemp rope hangs over the edge of the mesa.  \n"+
            "Maybe you could 'pull' it to get over the ledge of the mesa",
         "side","Fear overwhelms you as you look at the side of this \n"+
            "large mesa.  Small sprigs of grass hang over the side almost \n"+
            "giving you cover from detection from those above you",
});

dest_dir = ({
    PATH+"mv4.c","descend",
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
    add_action("pull_rope","pull");
    add_action("listen","listen");
}

int pull_rope(string str){
    if (!str || str != "rope"){
      notify_fail("What would you like to use to pull yourself up with?\n");
    return 0;
}

    write("You grab the hemp rope tightly and pull yourself up to \n"+
          "the top of the mesa.\n");
    say(this_player()->query_name()+" begins scaling the cliff to the top.\n");
    move_object(this_player(),"/players/dreamspeakr/mesa/mv6.c");
    command("look",this_player());
    say(this_player()->query_name()+" climbs over the top of the cliffside.\n");
    return 1;
    }

listen() {
    write("You close your eyes and listen.... you hear a festival \n"+
          "going on above you.  Echos of people singing and chanting \n"+
          "seem to surround you. \n");
  return 1; 
}
