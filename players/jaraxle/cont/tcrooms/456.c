#include "/players/jaraxle/ansi.h"
#define RNUM 456
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a forest";
set_light(1);
rtype = "forest";
long_desc = 
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m \n"+
"                [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m    N\n"+
"                [1mM[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;31mX[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m   /|\n"+
"                [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    | \n"+
"                [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/424.c","north",
"/players/jaraxle/cont/tcrooms/425.c","northeast",
"/players/jaraxle/cont/tcrooms/423.c","northwest",
"/players/jaraxle/cont/tcrooms/488.c","south",
"/players/jaraxle/cont/tcrooms/489.c","southeast",
"/players/jaraxle/cont/tcrooms/487.c","southwest",
"/players/jaraxle/cont/tcrooms/457.c","east",
"/players/jaraxle/cont/tcrooms/455.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
