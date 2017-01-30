#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/mesa/"
inherit "room/room";

reset(arg) {
int i;
  i = random(2);
    if(i == 1){
    for(i=0 ; i < random(2)+1 ; i++){
    move_object(clone_object("/players/dreamspeakr/mesa/NPC/anasazi.c"),this_object());
    }
}

if(arg)return;
     set_light(1);

     short_desc = HIG+"Atop Mesa Verde"+NORM;
     long_desc =
         "\tThe long journey to the top of this majestic mesa has  \n"+
         "finally ended.  A breathtaking sight to behold, the landscape \n"+
         "below seems so small and distant down in the canyon.  Trees \n"+
         "and lush green grass compliment the canyon slope just off the \n"+
         "side of the cliff palaces built into the rock to the north, \n"+
         "northeast and northwest. In front of the homes there is what \n"+
         "appears to be a kiva. \n";

              items = ({
         "mesa","Colors spring at you from every direction you look  \n"+
              "The thriving people of the mesa must never want to leave \n"+
              "the beauty and tranquility of this heavenly place",
         "landscape","Over 7,000 feet below you, you can barely make \n"+
              "out where you came from.  The view is so captivating you \n"+
              "could almost get lost in it",
         "canyon","As you look down at the canyon below all you can \n"+
              "make out are the beautiful colors of the landscape",
         "slope","The blanket of grass and towering trees take your \n"+
             "breath away as you look down this mountain slope",
         "trees","Beautiful Douglas Fir, Gambel Oak Serviceberry and \n"+
             "Mountain Mahogany trees stand high above the mountain brush \n"+
             "along the mesa top",
         "grass","Healthy Cheatgrass blankets the ground in shades of \n"+
             "green, swaying to and fro as the strong winds wisk it around",
         "palaces","Connected together these three story homes, known as \n"+
             "Cliff Palace, could probably house over 50 people",
         "rock","Gritty hard stone alcoves formed in the side of the \n"+
             "mountain top give shelter to the homes built within its \n"+
             "confinement",
         "kiva","Large sandstone bricks border this large covered pit. \n"+
             "There appears to be some kind of ritual going on inside it",
         "bricks","Placed along the edge of the Kiva large hand chipped \n"+
             "bricks decorate the temple below",

});

dest_dir = ({
    PATH+"mv7.c","north",
    PATH+"mv10.c","northwest",
    PATH+"mv13.c","northeast",
    PATH+"mv16.c","kiva",
    PATH+"mv5.c","descend",
});

}

listen() {
  write("You close your eyes and listen.... you hear the chant \n"+
         "of the Anasazi tribesmen performing an ancient tribal  \n"+
         "ceremony.  The wind whistles as it moves its way thru \n"+
         "the trees. \n");
  return 1; 
}
