#include "/players/jaraxle/ansi.h"
#define RNUM 632
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a large plain";
set_light(1);
rtype = "plain";
long_desc = 
"                [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m \n"+
"                [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    N\n"+
"                [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;31mX[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m   /|\n"+
"                [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n"+
"                [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/600.c","north",
"/players/jaraxle/cont/tcrooms/601.c","northeast",
"/players/jaraxle/cont/tcrooms/599.c","northwest",
"/players/jaraxle/cont/tcrooms/664.c","south",
"/players/jaraxle/cont/tcrooms/665.c","southeast",
"/players/jaraxle/cont/tcrooms/663.c","southwest",
"/players/jaraxle/cont/tcrooms/633.c","east",
"/players/jaraxle/cont/tcrooms/631.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
