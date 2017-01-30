#include "/players/maledicta/ansi.h"

id(str){ return str == "dock" || str == "city_object"; }

short(){ return "a dock"; }


long(str){
write("This is a small dock with many boats stationed along its\n"+
      "length.  You may 'sail' to the continent of Hirandea at any\n"+
      "time.\n");
return 1;
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","sail");
   }

enter_tower(str){
if(!str){
write("Enter what?\n");
return 1;
}
if(str == "tower"){
  if(!present("KnightInvite", this_player())){
   write("You are not allowed into the Tower.\n");
   return 1;
   }
  tell_room(environment(this_player()),
  this_player()->query_name()+" enters the Tower of Hope.\n", ({ this_player() }));
  tell_object(this_player(),
  "You enter the Tower of Hope.\n");
    move_object(this_player(), "/players/maledicta/hope/rooms/hmain.c");
  command("look", this_player());
  tell_room(environment(this_player()),
  this_player()->query_name()+" arrives.\n", ({ this_player() }));
  return 1;
  }
write("Enter what?\n");
return 1;
}



enter(str){
  write("You climb aboard a boat and sail to Hirandea.\n");
  this_player()->move_player("onto a boat#players/maledicta/cont/rooms/606.c");
  write(HIW+"\nPlease type, 'key' for a listing of symbol meanings.\n\n");
  write(NORM);
  return 1;
  }

