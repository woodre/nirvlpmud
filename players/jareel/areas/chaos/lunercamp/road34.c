inherit "/players/jareel/room";
#include "/players/jareel/define.h"

#define l1 "[ ] - Gate House"
#define l2 "S  - Lunar Shop"
#define l3 "T  - Temple of the Seven Mothers"
#define l4 "C  - Crimson Bat Temple"
#define l5 "K  - Barracks"
#define l6 "M  - Mess Hall"
#define l7 "B  - Lunar Bar"
#define l8 "H  - Lunar First Aid"
#define l9 "A  - Lunar Armorer"
#define l10 "F  - Lunar Forge"

reset(arg) {

     

     if(arg) return;
     set_light(1);
     short_desc=(RED+"The Luner Encampment"+NORM);
     long_desc=
YEL+"%%%%%%%%%%%%%%%%"+NORM+"\n"+
YEL+"%"+NORM+"+------------+"+YEL+"%    "+NORM+l1+"\n"+
YEL+"%"+NORM+"|"+RED+"@@@@@"+NORM+"|"+RED+"@@@@@@"+NORM+"|"+YEL+"%     "+NORM+l2+"\n"+
YEL+"%"+NORM+"|"+RED+"@"+NORM+"+---|"+RED+"@@@@"+NORM+""+RED+"@@"+NORM+"|"+YEL+"%     "+NORM+l3+"\n"+
YEL+"%"+NORM+"|"+RED+"@"+NORM+"|"+RED+"@@@"+NORM+"+----+-+"+YEL+"%     "+NORM+l4+"\n"+
YEL+"%"+NORM+"+B+T"+RED+"@@"+NORM+"M"+RED+"@@@@"+NORM+"F"+RED+"@"+NORM+"|"+YEL+"%     "+NORM+l5+"\n"+ 
YEL+"%"+NORM+"X"+RED+"@@@@@"+NORM+"K"+RED+"@@@"+NORM+"A"+RED+"@@"+NORM+"|"+YEL+"%     "+NORM+l6+"\n"+ 
YEL+"%"+NORM+"|"+RED+"@@@@"+NORM+"S+---+--+"+YEL+"%     "+NORM+l7+"\n"+
YEL+"%"+NORM+"|"+RED+"@"+NORM+"C---|"+RED+"@@@"+NORM+"H"+RED+"@@"+NORM+"|"+YEL+"%     "+NORM+l8+"\n"+
YEL+"%"+NORM+"|"+RED+"@@@@@"+NORM+"|"+RED+"@@@@@@"+NORM+"|"+YEL+"%     "+NORM+l9+"\n"+
YEL+"%"+NORM+"+-----+------+"+YEL+"%     "+NORM+l10+"\n"+
YEL+"%%%%%%"+HIK+"["+NORM+"|"+HIK+"]"+NORM+YEL+"%%%%%%%"+NORM+"\n";
     items = ({

     });
 
dest_dir = ({

     "/players/jareel/areas/chaos/lunercamp/road36","north",
     "/players/jareel/areas/chaos/lunercamp/road25","south",

});
}

init() {
     ::init();
       add_action("Search","search");
}

Search(str) {
     if(!str) { write("Search what?\n"); return 1; }
       write("You search the "+str+" but find nothing special.\n");
       say(this_player()->query_name()+" searches around for something.\n");
     return 1;
}
