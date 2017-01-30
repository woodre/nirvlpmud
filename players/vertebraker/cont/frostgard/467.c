#include <ansi.h>

#define RNUM 467
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "an ice sheet";
set_light(1);
rtype = "ice sheet";
long_desc = 
"                [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;37mn[0m \n"+
"                [34m~[0m [36m#[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m    N\n"+
"                [34m~[0m [36m#[0m [1;36m@[0m [1;37mX[0m [36m#[0m [1;36m@[0m [1;36m@[0m   /|\n"+
"                [34m~[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [36m#[0m [36m#[0m    | \n"+
"                [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [36m#[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/435.c","north",
"/players/vertebraker/cont/frostgard/436.c","northeast",
"/players/vertebraker/cont/frostgard/434.c","northwest",
"/players/vertebraker/cont/frostgard/499.c","south",
"/players/vertebraker/cont/frostgard/500.c","southeast",
"/players/vertebraker/cont/frostgard/498.c","southwest",
"/players/vertebraker/cont/frostgard/468.c","east",
"/players/vertebraker/cont/frostgard/466.c","west",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }
