#include <ansi.h>

#define RNUM 466
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "an ice sheet";
set_light(1);
rtype = "ice sheet";
long_desc = 
"                [36m#[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m \n"+
"                [34m~[0m [34m~[0m [36m#[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m    N\n"+
"                [34m~[0m [34m~[0m [36m#[0m [1;37mX[0m [1;36m@[0m [36m#[0m [1;36m@[0m   /|\n"+
"                [34m~[0m [34m~[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [36m#[0m    | \n"+
"                [34m~[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/434.c","north",
"/players/vertebraker/cont/frostgard/435.c","northeast",
"/players/vertebraker/cont/frostgard/433.c","northwest",
"/players/vertebraker/cont/frostgard/498.c","south",
"/players/vertebraker/cont/frostgard/499.c","southeast",
"/players/vertebraker/cont/frostgard/497.c","southwest",
"/players/vertebraker/cont/frostgard/467.c","east",
"/players/vertebraker/cont/frostgard/465.c","west",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }
