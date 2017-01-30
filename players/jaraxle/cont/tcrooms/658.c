#include "/players/jaraxle/ansi.h"
#define RNUM 658
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a large plain";
set_light(1);
rtype = "plain";
long_desc = 
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m \n"+
"                [34m~[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    N\n"+
"                [32m#[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [1;31mX[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [32m#[2;37;0m   /|\n"+
"                [32m#[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n"+
"                [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [32m#[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/625.c","northwest",
"/players/jaraxle/cont/tcrooms/690.c","south",
"/players/jaraxle/cont/tcrooms/689.c","southwest",
"/players/jaraxle/cont/tcrooms/657.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
