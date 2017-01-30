/* controller for virtual rooms.  creates new ones, and moves players
   between them
*/
#include "/players/illarion/dfns.h"

#define WIDTH_MIN 5
#define HEIGHT_MIN 5
#define MAX_LEVEL 15
#define ITEM_RAND !random(10)
#define VROOM "/players/illarion/maze/room/vroom"
#define MON "/players/illarion/maze/mon/"
#define CONTROLLER "/players/illarion/maze/room/vroomcon"
#define BRIDGE "/players/illarion/maze/room/bridgeroom"

string theme;
object *rooms;
object down_room;
string *room_directions;
int HEIGHT,WIDTH;
int *stairs_up;
int *stairs_down;
/* Thanks to Mizan for the idea of multiple floors */
object next_level;
int level_number;

/* Uses a growing tree algorithm to create the maze
   Each time a new cell is carved, it's added to the unfinished_rooms list
   Then a random unfinished_room is picked, and carves to an open cell beside it.
   If it has no open cells beside it, it's now a finished room and is removed
   from the list
*/

void add_monsters(object room);

string *find_open_adjacents(int current_room) {
  string *open_adj;
  int row,col;
  open_adj=({});
  row=1+current_room/WIDTH;
  col=1+current_room%WIDTH;
  if(row>1 && room_directions[current_room-WIDTH]=="")
    open_adj+=({"n"});
  if(row<HEIGHT && room_directions[current_room+WIDTH]=="")
    open_adj+=({"s"});
  if(col>1 && room_directions[current_room-1]=="")
    open_adj+=({"w"});
  if(col<WIDTH && room_directions[current_room+1]=="")
    open_adj+=({"e"});
    
  return open_adj;
}

void create_floorplan(int level) {
  int *unfinished_rooms;
  int current_room,new_room;
  int x;
  string *open_adjacents;
  int up_quad,down_quad;
  
  level_number=level;
  /* Thanks to Khrell for the idea of basing floor size on which floor it is */
  WIDTH=WIDTH_MIN+level_number;
  HEIGHT=HEIGHT_MIN+level_number;

  up_quad=random(4);
  down_quad=random(4);
  while(up_quad==down_quad)
    down_quad=random(4);
  
  switch(up_quad) {
    case 0: stairs_up=({1+random(WIDTH/2),1+random(HEIGHT/2)});
    break;
    case 1: stairs_up=({WIDTH-random(WIDTH/2),1+random(HEIGHT/2)});
    break;
    case 2: stairs_up=({1+random(WIDTH/2),HEIGHT-random(HEIGHT/2)});
    break;
    case 3: stairs_up=({WIDTH-random(WIDTH/2),HEIGHT-random(HEIGHT/2)});
    break;
  }
  switch(down_quad) {
    case 0: stairs_down=({1+random(WIDTH/2),1+random(HEIGHT/2)});
    break;
    case 1: stairs_down=({WIDTH-random(WIDTH/2),1+random(HEIGHT/2)});
    break;
    case 2: stairs_down=({1+random(WIDTH/2),HEIGHT-random(HEIGHT/2)});
    break;
    case 3: stairs_down=({WIDTH-random(WIDTH/2),HEIGHT-random(HEIGHT/2)});
    break;
  }
  
  rooms=allocate(HEIGHT*WIDTH);
  
  room_directions=allocate(HEIGHT*WIDTH); 
  x=sizeof(room_directions);
  while(x--)
    room_directions[x]="";
  unfinished_rooms=({1+random(HEIGHT*WIDTH)}); 
  while(sizeof(unfinished_rooms)>0) {
    if(random(4))
      current_room=unfinished_rooms[random(sizeof(unfinished_rooms))];
    else
      current_room=unfinished_rooms[sizeof(unfinished_rooms)-1];
    open_adjacents=find_open_adjacents(current_room);
    if(sizeof(open_adjacents)) {
      string new_dir;
      new_dir=open_adjacents[random(sizeof(open_adjacents))];
      switch(new_dir) {
        case "n":
          new_room=current_room-WIDTH;
          room_directions[current_room]=set_bit(room_directions[current_room],1);
          room_directions[new_room]=set_bit(room_directions[new_room],2);
          break;
        case "s":
          new_room=current_room+WIDTH;
          room_directions[current_room]=set_bit(room_directions[current_room],2);
          room_directions[new_room]=set_bit(room_directions[new_room],1);
          break;
        case "w":
          new_room=current_room-1;
          room_directions[current_room]=set_bit(room_directions[current_room],3);
          room_directions[new_room]=set_bit(room_directions[new_room],4);
          break;
        case "e":
          new_room=current_room+1;
          room_directions[current_room]=set_bit(room_directions[current_room],4);
          room_directions[new_room]=set_bit(room_directions[new_room],3);
          break;
      }
      unfinished_rooms+=({new_room});
    } else { /* No open rooms beside it, therefore this room is finished */
      unfinished_rooms-=({current_room});
    }    
  }
}


void show_map() {
  int x,y,r,exitval;
  int *playerloc;
  int playercol,playerrow;
  string map;
  string *lines;
  if(!room_directions) {
    write("No map has been generated.\n");
    return;
  }
  map="";
  for(x=0;x<HEIGHT;x++) {
    map+=" ";
    for(y=0;y<WIDTH;y++) {
      map+="+";
      if(test_bit(room_directions[r],4))
        map+=("====");
      else
        map+=("    ");
      r++;
    }
    map+=(" \n ");
    r-=WIDTH;
    for(y=0;y<WIDTH;y++) {
      if(test_bit(room_directions[r],2))
        map+=("|    ");
      else
        map+=("     ");
      r++;
    }
    map+=(" \n ");
    r-=WIDTH;
    for(y=0;y<WIDTH;y++) {
      if(test_bit(room_directions[r],2))
        map+=("|    ");
      else
        map+=("     ");
      r++;
    }
    map+=(" \n");
  }
  lines=explode(map,"\n");
  playercol=stairs_up[0]-1;
  playerrow=stairs_up[1]-1;
  lines[playerrow*3]=lines[playerrow*3][0..playercol*5]+"<"+
                     lines[playerrow*3][playercol*5+2..100];
  if(level_number<MAX_LEVEL) {
    playercol=stairs_down[0]-1;
    playerrow=stairs_down[1]-1;
    lines[playerrow*3]=lines[playerrow*3][0..playercol*5]+">"+
                       lines[playerrow*3][playercol*5+2..100];
  }
  playerloc=(mixed)environment(this_player())->query_location();
  if(sizeof(playerloc)==2) {
    playercol=playerloc[0]-1;
    playerrow=playerloc[1]-1;
    lines[playerrow*3]=lines[playerrow*3][0..playercol*5]+"P"+
                       lines[playerrow*3][playercol*5+2..100];
  } 
  write("\n"+implode(lines,"\n")+"\n");
}

/*
void reset(int arg) {
  if(arg) return;
}
*/

object find_room(int row, int column) {
  if(row<1 || row >HEIGHT || column <1 || column > WIDTH) return 0;
  return rooms[(row-1)*WIDTH+(column-1)];
}
  
object make_room(int row,int column) {
  object newroom,broom;
  string exit_code;
  string *exits;
  string long, adjective;
  
  newroom=clone_object(VROOM);
  newroom->set_controller(this_object());

  /* Stairs to the next level downward */
  if(level_number < MAX_LEVEL && column==stairs_down[0] && row==stairs_down[1]) {
    broom=clone_object(BRIDGE);
    broom->set_up_controller(this_object());
    broom->set_no_clean(1);
    down_room=broom;
    newroom->set_special_exit("down",file_name(broom));
  }
  /* Create the dest_dir */
  exits=({});
  exit_code=room_directions[(row-1)*WIDTH+(column-1)];
  if(test_bit(exit_code,4)) {
    exits+=({"east"});
  }
  if(test_bit(exit_code,3)) {
    exits+=({"west"});
  }
  if(test_bit(exit_code,2)) {
    exits+=({"south"});
  }
  if(test_bit(exit_code,1)) {
    exits+=({"north"});
  }
/* Determine how the room looks, based on the number of exits, and some random factors.
 */
  switch(sizeof(exits)) {
    case 1: case 3: case 4:
      newroom->set_short("A "+({"room","chamber","vault"})[random(3)]+" inside Undermountain");
      long = "This is one of the larger areas inside Undermountain.";
      break;
    case 2:
      newroom->set_short("A passageway through Undermountain");
      long = ("This underground passageway leads in two directions.");
      break;
  }   
/* some factors, like light, are determined when the room is created, becase of the
 * limitations of set_light
 */ 
  if(sizeof(exits)!=2) {
    if(ITEM_RAND) {
      adjective=({" faded","n old"," new"," brilliant"," torn"," ripped"," fancy"," plain"})[random(8)];
      long+="  A tapestry hangs on the wall.";
      newroom->add_item("tapestry","A"+adjective+" showing "+({
          "a dragon and a knight.",
          "a king holding court.",
          "a unicorn and a maiden in the woods.",
          "a spooky castle.",
          "a peaceful lake.",
          "a sword in a stone.",
          "two armies clashing on the field of battle."
          })[random(7)]);
    }
    if(ITEM_RAND) {
      long+="  A set of shackles is attached to the wall.";
      newroom->add_item("shackles",({
          "Fortunately, these iron shackles look like they haven't seen any use in a while.",
          "This rusted out set of shackles wouldn't hold a mouse at this point.",
          "Though rusted, these shackles still look pretty strong.",
          "Some bloodstains make it likely these shackles have seen recent use.",
          "These shackles are brand new, waiting to hold someone in place."
          })[random(5)]);
    }
  }
  newroom->set_long(long);
  newroom->create(column,row,exits);
 
  add_monsters(newroom);

  
  move_object(newroom, this_object());
  return newroom;
}

void add_monsters(object room) {
  int x, num, lev;
  object mon;
  if(theme=="goblin")
  {
    num = random(2)+random(2)+random(2);
    for(x=0; x< num; x++)
    {
      lev = 1 + random(2)+random(3)+random(4)+random(5)+random(5)+random(6);
      mon = (object)call_other(MON+"goblin_maker","make_goblin", lev);
      move_object(mon, room);
    }
  }
}


void move_me(object who,int column,int row,string dir,string spec_exit,string spec_target) {
  int index;
  switch(dir) {
    case "north": row--; break;
    case "south": row++; break;
    case "east": column++; break;
    case "west": column--; break;
  }
  index=(row-1)*WIDTH+(column-1);
  if(!rooms[index])
    rooms[index]=make_room(row,column);
  if(spec_exit && spec_target)
  rooms[index]->set_special_exit(spec_exit,spec_target);
  who->move_player(dir+"#"+file_name(rooms[index]));
}
/* Dests everything in the area except players, pets, kids, and their
   inventories- they're dumped in the village green. */

void clean_room(object room) {
  object *items;
  object *inv;
  int y,s,z;
  if(!room)
    return;
  items=all_inventory(room);
  s=sizeof(items);
  for(y=0;y<s;y++)
    if(items[y]->is_player() || items[y]->is_pet() || items[y]->is_kid()) {
      tell_object(items[y],
"The floor opens up beneath you!  You fall into a swirling disc of blue\n"+
"light, but land gently in the village green.\n");  
      items[y]->move_player("way, way down#/room/vill_green");
    } else {
      inv=deep_inventory(items[y]);
      z=sizeof(inv);
      while(z--)
        destruct(inv[z]);
      destruct(items[y]);
    }
  destruct(room);
}  
   
void destruct_area() {
  int x,s;
  object *items;
  for(x=0;x<WIDTH*HEIGHT;x++)
    clean_room(rooms[x]);
  items=all_inventory(this_object());
  s=sizeof(items);
  for(x=0;x<s;x++)
    clean_room(items[x]);

  destruct(this_object());
}

query_stairs_up() {
  return stairs_up;
}

query_stairs_down() {
  return stairs_down;
}

set_next_level(ob) {
  next_level=ob;
}

query_next_level() {
  return next_level;
}

set_level_number(x) {
  level_number=x;
}

query_level_number() {
  return level_number;
}

query_down_room() {
  return down_room;
}

set_theme(str) { theme=str; }
query_theme(str) { return theme; }
