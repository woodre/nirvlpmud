#include "/players/wocket/closed/ansi.h"
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
GRN+"   Grey trees grow from a gloomy fog that covers the ground.  The\n"+
    "path is water soaked and dew drips from the evergreen branches\n"+
    "above.  Dim light filters through as rays, illuminating only parts\n"+
    "of the walkway.  Dead and coroded branches litter the area.\n"+
    "Everything seems to be alive and whispering.\n"+OFF;
    break;
case 1:  long_desc = ""+
GRN+"   The fog covers everything about a foot off the ground.  Rays of\n"+
    "light manage to break through the overhead cover of the evergreens.\n"+
    "Broken and rotting branches carpet the soggy ground.  Living death\n"+   
    "seems to emminate from everything.  Shadows move across the backdrop\n"+
    "of grey.\n"+OFF;  
    break;
case 2:  long_desc = ""+
GRN+"   Grey wraps the area in gentle warm.  Only the slight hue of the\n"+
    "ghostly evergreens bring any variety.  Their dead branches litter the\n"+
    "waterlogged ground.  Undescovered paths lead in all directions only\n"+
    "hidden by the fog which resides along the ground.  Rays of light, as\n"+
    "glimmers of hope, seem to break through the canopy.\n"+OFF;
    break; 
case 3:  long_desc = ""+
GRN+"   Fallen branches snap as pressure is applied to them.  The gentle\n"+
    "squish of water screams from the brush, as a reminder of life.  Something\n"+
    "quite forgetable in this devode area.  The constant sight of grey brings\n"+
    "a desturbing peace as shadows dance along the misty fog.\n"+OFF;
    break;
case 4:  long_desc = ""+
GRN+"   Evergreens surround the area.  They seems to grow straight from the\n"+
    "fog which covers the ground.  The fragments of light that does manage\n"+
    "to make it through the thick canopy over head casts eery shadows across\n"+
    "the grey bushes.  Decaying life fills the air.\n"+OFF;
    break;
case 5:  long_desc = ""+
GRN+"  Grey trees fill the area.  Evergreens reach far into the air blocking out\n"+
    "all but the smallest of light.  Eerie shadows move slowly across the fallen\n"+
    "fog.  Broken branches and dead needles carpet the pathway which leads in\n"+
    "all directions.  Silence abounds.\n"+OFF;
   break;
case 6:  long_desc = ""+
GRN+"   Death emminates from the rotting evergreens which fill the area.  A\n"+
    "grey haze floods the ground hiding many of the broken branches.  The\n"+
    "water soaked path appears and disappears as one scans the area for life.\n"+
    "Light rays cast more shadows then they illuminate.  Death whispers through\n"+
    "the air.\n"+OFF;
  break;
}
return long_desc;
}