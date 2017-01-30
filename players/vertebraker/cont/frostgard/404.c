#include <ansi.h>

#define RNUM 404
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "an ice sheet";
set_light(1);
rtype = "ice sheet";
long_desc = 
"                [34m~[0m [1;37mn[0m [1;37mn[0m [1;37mn[0m [47;1mM[0m [47;1mM[0m [47;1mM[0m \n"+
"                [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;37mn[0m [1;37mn[0m [1;37mn[0m [47;1mM[0m    N\n"+
"                [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;37mX[0m [1;36m@[0m [1;37mn[0m [1;37mn[0m   /|\n"+
"                [36m#[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m    | \n"+
"                [36m#[0m [1;36m@[0m [1;36m@[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/372.c","north",
"/players/vertebraker/cont/frostgard/373.c","northeast",
"/players/vertebraker/cont/frostgard/371.c","northwest",
"/players/vertebraker/cont/frostgard/436.c","south",
"/players/vertebraker/cont/frostgard/437.c","southeast",
"/players/vertebraker/cont/frostgard/435.c","southwest",
"/players/vertebraker/cont/frostgard/405.c","east",
"/players/vertebraker/cont/frostgard/403.c","west",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }
