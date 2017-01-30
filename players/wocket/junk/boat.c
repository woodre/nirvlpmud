#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  set_id("boat");
  set_short("Das Boat");
  set_long("Yes its the wonderfull boat.\n");
enable_commands();
}

init(){
  if(environment(this_player()) == this_object()){
add_action("altlook","look");
add_action("sail","sail");
add_action("leave","leave");
}
else
add_action("board","board");
}

board(string str){
  if(str != "boat"){
  notify_fail("What would you like to board?\n");
  return 0;
  }
write("You board the boat.\n");
say(this_player()->query_name()+" boards the boat.\n");
move_object(this_player(),this_object());
return 1;
}

leave(string str){
  if(str != "boat"){
  notify_fail("What would you like to leave?\n");
  return 0;
  }
write("You leave the boat.\n");
say(this_player()->query_name()+" leaves the boat.\n");
move_object(this_player(),environment(this_object()));
return 1;
}

altnorth(){
write("Moving north");
command("north",this_object());
return 1;
}

altsouth(){
write("Moving south");
command("south",this_object());
return 1;
}

altlook(string str){
object ob;
  if(!str){
  environment(this_object())->long();
ob = first_inventory(environment(this_object()));
while(ob){
  write(ob->short()+"\n");
  ob = next_inventory(ob);
}
  return 1;
}
return 0;
}

sail(string str){
if(!str){
  write("Where would you like to sail to?\n");
  return 1;
}
if(str != ("south" || "north" || "west" || "east")){
  notify_fail("You many not sail that direction");
  return 0;
}
  command(str,this_object());
  return 1;
}

move_player(dest_dir){
string dir,dest;
  if(sscanf(dest_dir,"%s#%s",dir,dest) != 2){
  return 0;
  }
  tell_object(find_player("wocket"),"MOVE PLAYER CALLED.\n");
  move_object(this_object(),dest);
  return 1;
}
