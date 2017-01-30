#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ns2;

init() {
  ::init();
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ns3")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {
  if(!present("bug")) {
    for(i=0;i<2;i++) {
      move_object(clone_object("players/softly/newbie/mobs/bug.c"),this_object());
    }
  }
  if(!present("kit")) {
    for(i=0;i<2;i++) {
      move_object(clone_object("players/softly/newbie/mobs/kit.c"),this_object());
    }
  }
  if(!present("bee")) {
    move_object(clone_object("players/softly/newbie/mobs/bbee.c"),this_object()); 
  }  

  if(arg) return;
  set_chance(2);
  add_msg("A cool breeze wafts through the forest....");
  add_msg("A butterfly lands on your arm....");
  add_msg("hoooooo .... hoooooooo ....");
  add_msg("Chatter..Chatter..Chatter");
  add_msg("Suddenly there is a faint scream in the distance....");
  add_msg("meeEE ..  meeEE ..");
  add_msg("Crickets chirp in the distance....");

  set_light(1);

  short_desc = "Adventurer's School";
  long_desc =
    "  The forest is dense with closely spaced oaks and spruces.\n"+
    "A few wan flowers nestled amongst the fallen leaves and pine\n"+
    "needles dot the edge of the path.  Echoes of unknown sounds\n"+
    "filter through the trees.  As the narrow worn stone path turns\n"+
    "sharply, fierce wind rattles the limbs and swirls the leaves.\n"; 

  items = ({
    "edge",
    "Along the border of the stone path a few flowers grow",
    "wind",
    "Gusty breezes intermittently sweep through the forest",
    "limbs",
    "Tree branches rub against each other as the wind blows",
    "sounds",
    "Unfamiliar noises echo faintly",
    "needles",
    "Spruce needles mix with fallen leaves on the forest floor",
    "noises",
    "The unfamiliar noises echo through the trees",
    "arms",
    "The split path goes in three directions",
    "leaves",
    "A dense mat of fallen leaves pads the forest floor",
    "path",
    "The stone path is very worn, but clearly defines the way\n\
through the forest",
    "oaks",
    "Tall stately oaks dominate the forest.  They are very old",
    "spruces",
    "Dotted amongst the oak forest spruce trees reach toward the sky",
    "trees",
    "Oaks and spruces blend to create a haunting forest",
    "flowers",
    "A few pale trillium, laurel, and other woodland flowers\n\
line the path and are scattered through the forest",
    "forest",
    "The forest has large old trees, a mix of oaks and spruces.\n"+
    "The light is dim. A narrow stone path shows the way through",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ns4.c","west",
    "/players/softly/newbie/rooms/ns2.c","south",
  });
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" explains:\n"+
	      " A great deal of your time here will be spent fighting.  You will stay healthy\n"+
	      "longer if you have armor to protect you.  You can buy armor in shops or you\n"+
	      "might find some on the monsters along the way.  As long as you have not reached\n"+
	      "level 6 you can get free armor in the Adventurer's Hall.\n\n"+
	      " If you come across armor, type 'wear <armor>' or simply 'ready'.  Ready will\n"+
	      "have you wield a weapon and wear all of the armor that you have.\n\n");
  call_out("teach2",16,newbie);
}

void teach2(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" says:\n"+ 
	      " Using 'wimpy' will also help keep you safe.  Type 'wimpy 25%' to flee when\n"+
	      "your hitpoints reach 25% of the maximum.  Of course typing 'help wimpy' will\n"+
	      "tell you more about using the command.\n\n");

  guide->set_spoken("ns3");
}

adv_skool() { return 1; }
