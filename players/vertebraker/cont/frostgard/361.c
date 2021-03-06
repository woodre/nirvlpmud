#include <ansi.h>

#define RNUM 361
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "a large glacier";
set_light(1);
rtype = "glacier";
long_desc = 
"                [34m~[0m [34m~[0m [34m~[0m [34m~[0m [34m~[0m [34m~[0m [34m~[0m \n"+
"                [36m#[0m [36m#[0m [34m~[0m [34m~[0m [34m~[0m [34m~[0m [34m~[0m    N\n"+
"                [1;36m@[0m [1;36m@[0m [36m#[0m [1;37mX[0m [34m~[0m [34m~[0m [34m~[0m   /|\n"+
"                [1;36m@[0m [1;36m@[0m [36m#[0m [36m#[0m [36m#[0m [36m#[0m [34m~[0m    | \n"+
"                [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [36m#[0m [1;36m@[0m [1;36m@[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/393.c","south",
"/players/vertebraker/cont/frostgard/394.c","southeast",
"/players/vertebraker/cont/frostgard/392.c","southwest",
"/players/vertebraker/cont/frostgard/360.c","west",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }
