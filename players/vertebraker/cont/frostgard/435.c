#include <ansi.h>

#define RNUM 435
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "an ice sheet";
set_light(1);
rtype = "ice sheet";
long_desc = 
"                [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;37mn[0m [1;37mn[0m [1;37mn[0m \n"+
"                [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;37mn[0m    N\n"+
"                [34m~[0m [36m#[0m [36m#[0m [1;37mX[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m   /|\n"+
"                [34m~[0m [36m#[0m [1;36m@[0m [1;36m@[0m [36m#[0m [1;36m@[0m [1;36m@[0m    | \n"+
"                [34m~[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [36m#[0m [36m#[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/403.c","north",
"/players/vertebraker/cont/frostgard/404.c","northeast",
"/players/vertebraker/cont/frostgard/402.c","northwest",
"/players/vertebraker/cont/frostgard/467.c","south",
"/players/vertebraker/cont/frostgard/468.c","southeast",
"/players/vertebraker/cont/frostgard/466.c","southwest",
"/players/vertebraker/cont/frostgard/436.c","east",
"/players/vertebraker/cont/frostgard/434.c","west",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }