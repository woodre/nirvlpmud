#include "/players/jaraxle/ansi.h"
#define RNUM 340
inherit "players/jaraxle/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "foothills";
set_light(1);
rtype = "hills";
long_desc = 
"                [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m \n"+
"                [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [34m~[2;37;0m    N\n"+
"                [34m~[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;31mX[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m   /|\n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1mM[2;37;0m    | \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [33mn[2;37;0m [33mn[2;37;0m    | \n";
dest_dir = ({
"/players/jaraxle/cont/tcrooms/372.c","south",
"/players/jaraxle/cont/tcrooms/373.c","southeast",
"/players/jaraxle/cont/tcrooms/371.c","southwest",
"/players/jaraxle/cont/tcrooms/339.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
