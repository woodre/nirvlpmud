#include "/players/jaraxle/ansi.h"
#define RNUM 559
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a forest";
set_light(1);
rtype = "forest";
long_desc = 
"                [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m \n"+
"                [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    N\n"+
"                [32m#[2;37;0m [33m=[2;37;0m [32m#[2;37;0m [1;31mX[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m   /|\n"+
"                [34m~[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    | \n"+
"                [34m~[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [34m~[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/528.c","northeast",
"/players/jaraxle/cont/tcrooms/591.c","south",
"/players/jaraxle/cont/tcrooms/592.c","southeast",
"/players/jaraxle/cont/tcrooms/590.c","southwest",
"/players/jaraxle/cont/tcrooms/560.c","east",
"/players/jaraxle/cont/tcrooms/558.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
