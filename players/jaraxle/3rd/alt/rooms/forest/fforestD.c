#include <ansi.h>
#include "defs.h"
string *rooms;
string *new_rooms;

int sinjaroom;

add_room(str){
   rooms += ({str,});
   if(sizeof(rooms) > MAXROOMS)  clean_room();
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

get_long(){
string long_desc;
switch(random(7)){
case 0:  long_desc = ""+
BLK+BOLD+"   Dark grey trees grow from a gloomy fog that covers the\n"+
         "ground.  The path is water soaked and the fog slowly drifts\n"+
         "between the trees.  Dead and corroded branches litter the area.\n"+
         "Everything seems to be dead, yet whispering.\n"+OFF;
    break;
case 1:  long_desc = ""+
BLK+BOLD+"   The fog covers everything about a foot off the ground.\n"+
    "Broken and rotting branches carpet the soggy ground.  Living death\n"+   
    "seems to emanate from everything.  Shadows move across the backdrop\n"+
    "of grey.\n"+OFF;  
    break;
case 2:  long_desc = ""+
BLK+BOLD+"   Grey wraps the area in gentle warm.  Only the dark shadows of\n"+
    "the ghostly trees bring any variety.  Their dead branches litter the\n"+
    "waterlogged ground.  Undiscovered paths lead in all directions only\n"+
    "hidden by the fog which resides along the ground.\n"+OFF;
    break; 
case 3:  long_desc = ""+
BLK+BOLD+"   Fallen branches snap as pressure is applied to them.  Something\n"+
    "quite forgettable in this devode area.  The constant sight of grey brings\n"+
    "a disturbing peace as shadows dance along the misty fog.\n"+OFF;
    break;
case 4:  long_desc = ""+
BLK+BOLD+"   Huge, dark, and grey trees surround the area.  They seems to\n"+
    "grow straight from the fog which covers the ground.  Eerie sounds escape\n"+
    "from beyond the forest.  Decaying life fills the air.\n"+OFF;
    break;
case 5:  long_desc = ""+
BLK+BOLD+"  Grey trees fill the area.  Eerie shadows move slowly across the\n"+
    "fallen fog.  Broken branches and dead leaves carpet the pathway which\n"+
    "leads in all directions.  Silence abounds.\n"+OFF;
   break;
case 6:  long_desc = ""+
BLK+BOLD+"   Death emanates from the rotting trees which fill the area.  A\n"+
    "grey haze floods the ground hiding many of the broken branches.  The\n"+
    "water soaked path appears and disappears as one scans the area for life.\n"+
    "Death whispers through the air.\n"+OFF;
  break;
}
return long_desc;
}
