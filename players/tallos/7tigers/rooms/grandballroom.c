#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) { 
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Grand Ballroom"+NORM;
long_desc = "      "+YEL+"The "+HIC+"Grand Ballroom"+NORM+""+NORM+""+YEL+" is a sight to behold.  Nearly\n"+
            "350 ft in length and 300 ft wide this marvel is one of\n"+
            "the wonders of the planes.  Vaulted "+CYN+"ceilings"+YEL+" with very\n"+ 
            "large "+HIY+""+BLK+"skylights"+NORM+""+NORM+""+YEL+", show every detail of "+HIY+""+BLK+"night"+NORM+""+NORM+""+YEL+" sky.   The\n"+
            ""+HIM+"dance floor"+NORM+""+NORM+""+YEL+" is full of "+HIB+"lords"+NORM+""+YEL+" and "+NORM+""+MAG+"ladies"+YEL+" dancing to the\n"+
            "waltz being played by "+HIC+"animated "+HIB+"instruments"+NORM+""+NORM+""+YEL+" on "+HIG+"stage"+NORM+""+NORM+""+YEL+" at\n"+
            "the far end of the "+HIY+"hall"+NORM+""+YEL+". The "+NORM+""+NORM+""+GRN+"music"+YEL+" is catchy and makes\n"+
            "you want to join in."+NORM+"\n";
    add_object("/players/tallos/7tigers/mobs/customer1.c",2);
    add_object("/players/tallos/7tigers/mobs/elvenwizard1.c");            
items = ({
  "lords","They are dressed in the best the planes have to offer and waltz with\n"+
  "Their ladies.",
  "hall",
  "The grand ballroom. It is a breathtaking sight to behold. There's nothing else\n"+
  "like it anywhere else.",
  "ladies",
  "Dressed in beatiful gowns that span the colors of the "+HIR+"r"+HIY+"a"+HIG+"i"+HIB+"n"+HIM+"b"+HIR+"o"+HIY+"w"+NORM+".",
  "night",
  "At the moment the skylights display the deep dark night sky as seen from\n"+
  "the Uglarian star cluster on planet Elor home of the space elves.",
  "stars",
  "They are breathtaking. A beautiful spread of stars from a distant star cluster.",
  "stage",
  "A large stage which has floating instruments playing without a need of a person.",
  "floor",
  "The dance floor is large and covered with runes. Several people dance\n"+
  "about on it.",
  "skylights",
  "At the top of the ceiling are large skylights that open up and show\n"+
  "the night sky and all it's glory. You can see every star in the sky.",
  "ceiling",
  "It's vaulted and goes up hundreds of feet, some of which is covered in\n"+
  "murals.",
  "instruments",
  "Several instruments play by themselves on stage.",
  "runes",
  "Several different runes of magic inscribed on the floor seem to pulse\n"+
  "with magical energy.",
  "paintings",
  "A wonderful seletion of paintings from artists all over the multiverse.",
  "inn",
  "The 7 Tigers Inn is one of the most famous hotels in all of the Forgotten\n"+
  "Realms.  It links itself to many different planes and appears there as it\n"+
  "does here.", 
  "murals",
  "The large ceiling lays acres of stone canvas for several scenes displaying\n"+
  "a multitude of different planes and dimensions of existence.",
  });
  add_listen("main","The sound of beautiful music");
  add_listen("music","The waltz for sure. It's catchy beat is enough to get your foot tapping");
  add_smell("main","The wonderful smell of "+HIR+"roses"+NORM+" is in the air");
  add_smell("roses","The whole hall seems to produce this wonderful "+HIR+"f"+HIY+"l"+HIG+"o"+HIB+"w"+NORM+""+MAG+"e"+HIR+"r"+HIY+"y"+NORM+" odor");


dest_dir = ({
    PATH+"/lounge.c","south",
    PATH+"/mainhall.c","east",
  });
set_light(1);
}
