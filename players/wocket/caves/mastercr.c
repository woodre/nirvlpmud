#include "/players/wocket/closed/ansi.h"
#define MAXROOMS 40
string *rooms;
string *new_rooms;

int sinjaroom;

void add_room(string str) {
   rooms += ({str,});
  if (sizeof(rooms) > MAXROOMS)
    this_object()->clean_room();
}

remove_room(str){
object rob;
object rob2;
int i,size;
size = sizeof(rooms);
new_rooms = "";
for(i=1;i<size;i++){
rob2 = find_object(rooms[i]);
    if(str != rooms[i]){
  if(rob2) new_rooms += ({rooms[i],});
    }
else{
    rob = find_object(str);
  if(rob) rob->clean_up();
}
}
rooms = new_rooms;
}


list_rooms(){
int i,size;
size = sizeof(rooms);
for(i=1;i<size;i++){
    write(rooms[i]+"\n");
}
write(size-1+"\n");
return 1;
}

check_room(str){
object *inv,rob;
int i,size;

rob = find_object(str);
if(!rob) return 0;
inv = all_inventory(find_object(str));
size = sizeof(inv);
for(i=0;i<size;i++){
  if(inv[i]->is_player()){
    return 1;
  }
}
return 0;
}

clean_room(int i){
string str;
  if(!i){
    i = 2; 
  }
  str = rooms[i];
  if(!check_room(str)){ 
    remove_room(str);
  }
  else{
    i++; 
    clean_room(i);
  }
}

clean_area(){
int i,size;
object rob;
for(i=1,size=sizeof(rooms);i<size;i++){
  rob=find_object(rooms[i]);
  if(rob){
     write(rooms[i]+" cleaned.\n");
     rob->clean_up();
  }
}
rooms = "";
}

set_sinjaroom(int i){ sinjaroom = i; }
query_sinjaroom(){
object sinroom;
sinroom = find_object("/players/wocket/caves/sinjaroom");
if(sinroom) return 1;
else
return 0;
}

get_long(){
string long_desc;
switch(random(7)){
case 0:  long_desc = ""+
MAG+"   The walls are covered with a slimy mucus giving off a soft\n"+
    "violet glow, creating shadows which flicker in every direction.\n"+
    "The ruff walls are made of dirt and stone and the ground is\n"+
    "covered in lose rocks.  Small strange white plants feed off\n"+
    "the darkness.\n"+NORM;    
    break;
case 1:  long_desc = ""+
MAG+"   A soft glow emminates from the mucus which textures the already\n"+
    "ruff dirt walls.  A small amount of violet light casts shadows\n"+
    "making everything seem alive.  White plants grow in abundance in\n"+
    "the intense darkness.\n"+NORM;
    break;
case 2:  long_desc = ""+
MAG+"   Violet light from a strange mucus, casts shadows against the rocky\n"+
    "walls.  The ground is littered in loose rocks and white plants that\n"+
    "seem to be at home in this cold, dark place.  The mucus covers everything\n"+
    "making an explorers walk a slippery one.\n"+NORM;
    break; 
case 3:  long_desc = ""+
MAG+"   The walls are covered in small plantlife.  The plants are a dull\n"+
    "white and seem very fragile.  They shrink back from the light of the\n"+
    "violet mucus which seems to cover everything.  Small rocks litter\n"+
    "the ground addding more to the danger of tripping.\n"+NORM; 
    break;
case 4:  long_desc = ""+
MAG+"   White plants grow in abundance down here.  Some can be found in every\n"+
    "little crack or hole in the walls.  They seem to feed off the darkness\n"+
    "itself.  A mucus covers the majority of things, giving off a soft violet\n"+
    "glow, which the plants hide from.  The walls are sharp with jagged rocks,\n"+
    "though many have come loose and now lay upon the ground.\n"+NORM;
    break;
case 5:  long_desc = ""+
MAG+"   The walls are covered in a slimy mucus which gives off a soft \n"+
    "violet glow.  The light casts shadows against the rocky surface\n"+
    "giving refuge for the dark loving plants who grow in abundance here.\n"+
    "Loose rocks acumulate in the corners of the cavern, knocked off from\n"+
    "the walls.\n"+NORM;
   break;
case 6:  long_desc = ""+
MAG+"   The soft violet glows from the mucus spread around the room, casting\n"+
    "shadows against the rocky walls.  White plants shrink back and hide in\n"+
    "thier life giving darkness.  Fallen rocks from the walls loosely scatter\n"+
    "around on the ground as everything grows slimy.\n"+NORM;
  break;
}
return long_desc;
}
