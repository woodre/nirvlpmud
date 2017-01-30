#include "/players/jaraxle/ansi.h"
#define RNUM 444
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a large plain";
set_light(1);
rtype = "plain";
long_desc = 
"                [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [34m~[2;37;0m [34m~[2;37;0m \n"+
"                [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [34m~[2;37;0m    N\n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;31mX[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m   /|\n"+
"                [33mn[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m    | \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/412.c","north",
"/players/jaraxle/cont/tcrooms/413.c","northeast",
"/players/jaraxle/cont/tcrooms/411.c","northwest",
"/players/jaraxle/cont/tcrooms/476.c","south",
"/players/jaraxle/cont/tcrooms/477.c","southeast",
"/players/jaraxle/cont/tcrooms/475.c","southwest",
"/players/jaraxle/cont/tcrooms/445.c","east",
"/players/jaraxle/cont/tcrooms/443.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
