#include <ansi.h>

#define RNUM 434
inherit "players/vertebraker/cont/inherit/fgard_room";


string rtype;

reset(arg){
  ::reset(arg);
  if(arg) return;

short_desc = "a large glacier";
set_light(1);
rtype = "glacier";
long_desc = 
"                [34m~[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;37mn[0m [1;37mn[0m \n"+
"                [36m#[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m    N\n"+
"                [34m~[0m [34m~[0m [36m#[0m [1;37mX[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m   /|\n"+
"                [34m~[0m [34m~[0m [36m#[0m [1;36m@[0m [1;36m@[0m [36m#[0m [1;36m@[0m    | \n"+
"                [34m~[0m [34m~[0m [36m#[0m [1;36m@[0m [1;36m@[0m [1;36m@[0m [36m#[0m    | \n";
dest_dir = ({
"/players/vertebraker/cont/frostgard/402.c","north",
"/players/vertebraker/cont/frostgard/403.c","northeast",
"/players/vertebraker/cont/frostgard/401.c","northwest",
"/players/vertebraker/cont/frostgard/466.c","south",
"/players/vertebraker/cont/frostgard/467.c","southeast",
"/players/vertebraker/cont/frostgard/465.c","southwest",
"/players/vertebraker/cont/frostgard/435.c","east",
"/players/vertebraker/cont/frostgard/433.c","west",
});
}

status is_cont_frostgard(){ return 1; }
string query_room_type(){ return rtype; }
int query_room_num(){ return RNUM; }
