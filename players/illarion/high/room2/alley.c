inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

int broken_escape;

void reset(int arg) {
  if(arg) return;
  set_light(0);
  set_short("A cluttered alley");
  set_long("Boxes and old garbage cans are strwen across the asphault "+
           "street and piled up against the sides of the buildings to "+
           "either side.  The buildings themselves quickly vanish into "+
           "the gloom above, the only visible feature a rusting fire "+
           "escape attached to the building to the east.  To the north, "+
           "a fence blocks most of the alley, but there is a hole large "+
           "enough to allow a hasty exit, and the alley continues to the "+
           "south.");

  add_item("boxes","Cardboard and wooden boxes are strewn all over the "+
                   "ground.  They all seemed to be smashed and useless, "+
                   "and some are soaked in things you do not want to "+
                   "identify.");
  add_item("cans","Old metal garbage cans.  Some of them have garbage in "+
                  "them, but this seems more an accident, because as many "+
                  "are empty or upside down.");
  add_item("street","The alley was paved once, long ago, and the chunks "+
                    "of asphault are as much hazard to mobility as help now.");
  add_item("buildings","Annonyomous big city buildings, faceless and "+
                       "uncaring.  There are no windows near the street.");
  add_item("fire escape","$&escape_desc$&");
  add_item("fence","This board fence seems almost to serve as a retaining "+
                   "wall to keep the junk in the alley from spilling into "+
                   "the street.  A few boards in the center are missing, "+
                   "allowing exit to a clearer-looking street.");
  add_item("alley","Dark and smelly, this alley is just the sort of place "+
                   "you wouldn't want to meet anyone at all.");
  add_item("hole","A hole in the fence created by missing boards.");
  
  add_exit("north",HROOM2+"nystreet");
  add_exit("south",HROOM2+"alley2");
}
void init() {
  ::init();
  add_action("cmd_scramble","scramble");
}
string escape_desc() {
  if(broken_escape)
    return "The end of a fire escape hulks over the alleyway here, "+
           "dangerously broken and twisted.  It seems it has given all "+
           "it can and a bit more besides.";
  else
    return "The end of a rusty fire escape hulks over the "+
           "alleyway.  Its advanced state of decay probably "+
           "makes it worse than useless now, but a quick "+
           BLD("scramble")+" up one of the piles of refuse "+
           "would bring it into reach.";
}
int cmd_scramble(string str) {
  if(!str || str != "up pile") FAIL("Scramble up what?\n");
  if(broken_escape) {
    write("The fire escape is broken.  Attempting to use it now would be\n"+
          "futile and probably dangerous.");
    return 1;
  }
  write("You scramble up one of the shifting piles of refuse and make a\n"+
        "grab for the fire escape.\n");
  say(TPN+" scrambles up one of the shifting piles of refuse and makes a\n"+
        "grab for the fire escape.\n");
  if(random(4)) {
    write("Your hands fall short, and you slide down the pile back into\n"+
          "the alley.\n");
    say(TP->query_pronoun()+" just misses the grab, and slides back to\n"+
          "more solid ground.\n");
  }
  else {
    write("Success!  You grab the fire escape and pull yourself up onto\n"+
          "the lowest level.  Just as you are congratulating yourself,\n"+
          "though, an ominous creaking sound starts.\n");
    write("Just as you begin to consider escape, the creaking changes to\n"+
          "a high-pitched squeal, and you are thrown off the fire escape\n"+
          "and through the air.\n");
    write("After an all too brief trip, you land HARD on the ground below.\n");
    TP->hit_player(random(30)+30);
    say(format(
            TPN+" manages to grab the fire escape and clamber up, but then, "+
            "almost faster than you can follow, the escape breaks and "+
            TP->query_pronoun()+" is thrown to the ground.\n",70));
  }
  return 1;
}
