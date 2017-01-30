#include <ansi.h>
#include "/players/sparrow/areas/shadow_cont/includes/shadow_cont.h"

/* GLOBAL VARIABLES */
int *Room_coords;
string *Sc_map;
string *Sc_exits;
string Sc_long;
string Sc_short;

inherit "room/room";
inherit "obj/clean";
  reset(arg){
  if(!arg){
    set_light(1);
    items=({
      "nothing", "Yep, yer right. There is nothing here yet.",
    });
    dest_dir=Sc_exits;
  }   
}

init()  {
 ::init();
  add_action("search_room","search");
}

search_room() {
  write("You find nothing in this room... yet.\n");
  say (this_player()->query_name() +" searches the nothingness.\n");
  return 1;  
}

short() {
 return Sc_short; 
}

long() {
  write(Sc_long);
}

north() {
  if(!member(Sc_exits, "north") == -1) {
    attempt_to_move("north");
  }
  else {
    write("You are "+RED+"unable"+NORM+" to move north!\n");
  }
  return;
}

east() {
  if(!member(Sc_exits, "east") == -1) {
    attempt_to_move("east");
  }
  else {
    write("You are "+RED+"unable"+NORM+" to move east!\n");
  }
  return;
}

south() {
  if(!member(Sc_exits, "south") == -1) {
    attempt_to_move("south");
  }
  else {
    write("You are "+RED+"unable"+NORM+" to move south!\n");
  }
  return;
}

west() {
  if(!member(Sc_exits, "west") == -1) {
    attempt_to_move("west");
  }
  else {
    write("You are "+RED+"unable"+NORM+" to move west!\n");
  }
  return;
}

northeast() {
  if(!member(Sc_exits, "northeast") == -1) {
    attempt_to_move("northeast");
  }
  else {
    write("You are "+RED+"unable"+NORM+" to move northeast!\n");
  }
  return;}

northwest() {
  if(!member(Sc_exits, "northwest") == -1) {
    attempt_to_move("northwest");
  }
  else {
    write("You are "+RED+"unable"+NORM+" to move northwest!\n");
  }
  return;}

southeast() {
  if(!member(Sc_exits, "southeast") == -1) {
    attempt_to_move("southeast");
  }
  else {
    write("You are "+RED+"unable"+NORM+" to move southeast!\n");
  }
  return;
}

southwest() {
  if(!member(Sc_exits, "southwest") == -1) {
    attempt_to_move("southwest");
  }
  else {
    write("You are "+RED+"unable"+NORM+" to move southwest!\n");
  }
  return;
}

void
attempt_to_move(string dir) {
  int x_mod,y_mod,i,j;
  object *room_clones;
  object obj;
  x_mod = y_mod = 0;
  switch(dir) {
    case "north":
      y_mod = -1;
      break;
    case "east":
      x_mod = 1;
      break;
    case "south":
      y_mod = -1;
      break;
    case "west":
      x_mod = -1;
      break;
    case "northeast":
      y_mod = -1;
      x_mod = 1;
      break;
    case "northwest":
      y_mod = -1;
      x_mod = -1;
      break;
    case "southeast":
      y_mod = 1;
      x_mod = 1;
      break;
    case "southwest":
      y_mod = 1;
      x_mod = -1;
      break;
    default:
  }
  room_clones = clones(BLUEPRINT);
  i=0;
  j=sizeof(room_clones);
  while(i < j){
    if(room_clones[i]->query_room_coords() == ({Room_coords[0]+x_mod,Room_coords[1]+y_mod})) {
      obj = room_clones[i];
      i = j;
    }
    i++;
  }
  if(obj) {
    say(this_player()->query_name()+" leaves "+dir+".\n");
    move_object(this_player(),obj);
    call_out("remove_me",30);
    return;
  }
  obj = clone_object(BLUEPRINT);
  obj->initialize_room_from_map(Room_coords[0]+x_mod,Room_coords[1]+y_mod);
  move_object(this_player(),obj);
  say(this_player()->query_name()+" leaves "+dir+".\n");
  call_out("remove_me",30);
  return;
}

void
initialize_room_from_map(int coord_x, int coord_y) {
  string *map_temp;
  string map_string;
  int first, last, maplen,i,x,y;
  string longstring;
  int *ne_corner;
  int *nw_corner;
  int *se_corner;
  int *sw_corner;
  mapping long_map;
  mapping short_map;
  string room_char,room_short;
  short_map = mkmapping(SHORT_SYMBOL,SHORT_VALUES);
  long_map = mkmapping(KEY_SYMBOL,KEY_VALUES);
  
  /* Load map into global array */
  map_string = read_file(MAPPATH+"/shadow_cont.map");
  maplen = strlen(map_string);
  first = i = 0;
  last = first+(MAP_X -1);
  while (last < maplen) {
    map_temp[i] = map_string[first..last];
    i++;
    first = last+1;
    last = first+MAP_X;
  }
  
  Sc_map = map_temp;
  /* Load cooridinates into global array */
  Room_coords = ({coord_x,coord_y});
  /* Generate exits for the sake of display */
  if(!member(KEY_IMPASS,Sc_map[coord_x-1][coord_y]) == -1) {
    Sc_exits[sizeof(Sc_exits)] = "north";
    Sc_exits[sizeof(Sc_exits)] = BLUEPRINT;
  }
  
  if(!member(KEY_IMPASS,Sc_map[coord_x][coord_y+1]) == -1) {
    Sc_exits[sizeof(Sc_exits)] = "east";
    Sc_exits[sizeof(Sc_exits)] = BLUEPRINT;
  }
  
  if(!member(KEY_IMPASS,Sc_map[coord_x+1][coord_y]) == -1) {
    Sc_exits[sizeof(Sc_exits)] = "south";
    Sc_exits[sizeof(Sc_exits)] = BLUEPRINT;
  }
  
  if(!member(KEY_IMPASS,Sc_map[coord_x][coord_y-1]) == -1) {
    Sc_exits[sizeof(Sc_exits)] = "west";
    Sc_exits[sizeof(Sc_exits)] = BLUEPRINT;
  }
  
  if(!member(KEY_IMPASS,Sc_map[coord_x-1][coord_y]) == -1) {
    Sc_exits[sizeof(Sc_exits)] = "northeast";
    Sc_exits[sizeof(Sc_exits)] = BLUEPRINT;
  }
  
  if(!member(KEY_IMPASS,Sc_map[coord_x-1][coord_y]) == -1) {
    Sc_exits[sizeof(Sc_exits)] = "northwest";
    Sc_exits[sizeof(Sc_exits)] = BLUEPRINT;
  }
  
  if(!member(KEY_IMPASS,Sc_map[coord_x-1][coord_y]) == -1) {
    Sc_exits[sizeof(Sc_exits)] = "southeast";
    Sc_exits[sizeof(Sc_exits)] = BLUEPRINT;
  }
  
  if(!member(KEY_IMPASS,Sc_map[coord_x-1][coord_y]) == -1) {
    Sc_exits[sizeof(Sc_exits)] = "southwest";
    Sc_exits[sizeof(Sc_exits)] = BLUEPRINT;
  }
  
  ne_corner = nw_corner = se_corner = sw_corner = ({});
  /* Find the coordinates of the corners of the display area */
  if((Room_coords[0]+4) < (MAP_X-1)) {
    ne_corner[0] = Room_coords[0]+4;
    se_corner[0] = ne_corner[0];
  }
  else {
    ne_corner[0] = MAP_X-1;
    se_corner[0] = ne_corner[0];
  }
  if((Room_coords[0]-4) > -1) {
    nw_corner[0] = Room_coords[0]-4;
    sw_corner[0] = nw_corner[0];
  }
  else {
    nw_corner[0] = 0;
    sw_corner[0] = 0;
  }
  if((Room_coords[1]+3) < (MAP_Y-1)) {
    se_corner[1] = Room_coords[1]-3;
    sw_corner[1] = se_corner[0];
  }
  else {
    se_corner[1] = MAP_Y-1;
    sw_corner[1] = se_corner[1];
  }
  if((Room_coords[1]-3) > -1) {
    nw_corner[1] = Room_coords[1]-3;
    ne_corner[1] = nw_corner[1];
  }
  else {
    nw_corner[0] = 0;
    ne_corner[0] = 0;
  }
  
  /* Build short description of room */
  room_char = Sc_map[Room_coords[0]][Room_coords[1]];
  room_short = short_map[room_char];
  Sc_short = room_short;
  /* Build long description of room */
  longstring = "";
  x = y = 0;
  while(y < (se_corner[1]+1)) {
    while(x < (se_corner[0]+1)) {
      if((x == Room_coords[0]) && (y == Room_coords[1])) {
        longstring += HIR+"X"+NORM;
      }
      else {
        longstring += long_map[Sc_map[nw_corner[0]+x][nw_corner[1+y]]];
      }
      x++;
    }
    longstring += "\n";
    x = 0;
    y++;
  }
  Sc_long = longstring;
  return;
}

void
remove_me() {
  object *room_inv;
  int i;
  i=0;
  room_inv = all_inventory(this_object());
  while(i < sizeof(room_inv)) {
    if(member(users(), room_inv[i])) {
      return;
    }
    i++;
  }
  this_object()->remove();
  destruct(this_object());
  return;
}

int *
query_room_coords() {
  return Room_coords;
}