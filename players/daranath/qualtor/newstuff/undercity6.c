#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+BOLD+"UnderCity"+NORM+")");
    long_desc=
"               "+BOLD+"Under the City of Qual'tor"+NORM+"\n"+
"Cave-ins within the sewer system were common place during the warfare\n"+
"that razed the city. Another one occured here, blocking travel to the\n"+
"south and leaving your only option to turn back.\n";

    items=({
"system","The sewer system once served the city of Qual'tor",
"city","You are currently under the city streets themselves",
"cavein","The cavein was caused by falling debris, probably during the massive warfare that\n"+
     "ravaged the once beautiful city",
"debris","Debris from the cavein is everywhere",
    });

    dest_dir=({
ROOT+"undercity1.c","north",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search() {
write("The debris about the area leaves little options to search.\n");
  say(tp +" searches the area.\n");
return 1;
}

