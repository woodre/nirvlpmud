/*
   room 1   [] [] []
   hallway  =============
   room 2   [] [] []
*/

#define SAVEFILE "hallway"
#include "/players/wocket/closed/ansi.h"
#include "../def.h"
inherit ROOM;

static string *who;
static int    *where;
string *rooms1;
string *rooms2;
string *passwords;
string *descripts;

id(str){
int i;
  i = member_array(this_player()->query_real_name(),who);
  if(where[i] != 0){
    if(str == "plaque" || str == "plaque 1" || str == "plaque 2") return 1;
  }
  return ::id(str);
}

long(str){
int i,a;
  i = member_array(this_player()->query_real_name(),who);
  a = where[i]-1;
  if(str){ 
    if(where[i] != 0){
      if(str == "plaque"){
        write("Which plaque are you looking at?\n");
        return 0;
      }
      if(str == "plaque 1"){
      write("You see a small plaque with the name "+capitalize(rooms1[a])+" engraved upon it.\n");
        return 1;
      }
      if(str == "plaque 2"){
        write("You see a small plaque with the name "+capitalize(rooms2[a])+" engraved upon it.\n");
        return 1;
      }
    }   
    ::long(str);
    return 1;
  }
  i = member_array(this_player()->query_real_name(),who);
  if(where[i] == 0){
    long_desc = "   "+
   "A long hallway that extends to the east and west.  A soft plush carpet\n"+
   "lines the floor and dark stained oak molds the hall.  Wood panneling covers\n"+
   "the wall only to be broken up by the many doors which run parallell to one\n"+
   "another.  Soft lamps flicker against the walls bringing a warm sense to the\n"+
   "hallway.  To the north you can see the stairwell of the mysty tower.\n";
  write("You are at "+where[i]+"\n");
    dest_dir = ({
      "FAKE_DIR","north",
      "FAKE_DIR","east",
      "FAKE_DIR","west",
    });
  }  
  else{
    long_desc = "   "+
   "A long hallway that travels far to the east and west.  Soft plush carpet\n"+
   "lines the floor and dark stained oak molds the hall.  Wood panneling covers\n"+
   "the walls only to be broken up by the many doors which run parallel to one\n"+
   "another.  Soft lamps flicker against the walls bringing a warm sense to the\n"+
   "hallway. Two doors stand next to you, each made of a fine sturdy oak.  Each\n"+
   "holds a gold engraved plaque, with their respected names, above them.\n";
   write("You are at "+where[i]+"\n");
    dest_dir = ({
   "FAKE_EXIT1","east",
   "FAKE_EXIT2","west",
   });
  }
  ::long();
}

 
reset(arg){
  if(arg) return;
  short_desc = CYN+"A Long Hallway"+OFF;
  long_desc = "   "+
  "A long hallway that travels far to the east and west.  Soft plush carpet\n"+
  "lines the floor and dark stained oak molds the hall.  Wood panneling covers\n"+
  "the walls only to be broken up by the many doors which run parallel to one\n"+
  "another.  Soft lamps flicker against the walls bringing a warm sense to the\n"+
  "hallway. Two doors stand next to you, each made of a fine sturdy oak.  Each\n"+
  "holds a gold engraved plaque, with their respected names, above them.\n";
items = ({
  "hallway","A long hallway",
  "lamps","Old oil lamps that flicker in the darkness",
  });
  listens = ({
  "default","Silence fills the air",
  });
  smells = ({
  "default","You smell the fine sent of oil being burned",
  });
  pk = 1;
  set_light(1);
  who = ({});
  where = ({});
  rooms1 = ({ "wocket","neowocket", });
  rooms2 = ({ "feldegast","laera",  });
}

init(){
  ::init();
  if(this_player() && this_player()->is_player() && environment(this_player()) == this_object()){
    who += (string) this_player()->query_real_name();
    where += 0;
    add_action("move_me","west");
    add_action("move_me","east");
    add_action("leave","leave");
    add_action("enter","enter");
    add_action("knock","knock");

  }
}

exit(){
int i;
  ::exit();
if(this_player()){
  i = member_array(this_player()->query_real_name(),who);
  who -= who[i];
  where -= where[i];
  }
}

move_me(){
int i;
  if(!query_verb()) return;
  if(query_verb() == "west"){
   i = member_array(this_player()->query_real_name(),who);
   where[i]--;
   if(where[i] < 0)
     where[i] = sizeof(rooms1);
  }
  else{
   i = member_array(this_player()->query_real_name(),who);
  where[i] = where[i]+1;
   if(where[i] > sizeof(rooms1))
     where[i] = 0;
  }
  if(where[i] == 0){
    dest_dir = ({
     "FAKE_DIR","north",
     "FAKE_DIR","east",
     "FAKE_DIR","west",
    });
  }
  else{
    dest_dir = ({
      "FAKE_DIR","east",
      "FAKE_DIR","west",
    });
  }
  write("\n\nYou walk to the "+query_verb()+" but when you get there, you are were you were.\n\n");
  command("glance",this_player());
  return 1;
}

add_room(str){
int a;
  a = member_array("VACANT",rooms1);
  if(a != -1){
    rooms1[a] = str;
    return 1;
  }
  a = member_array("VACANT",rooms2);
  if(a != -1){
    rooms1[a] = str;
    return 1;
  } 
  if(sizeof(rooms1) > sizeof(rooms2)){
    rooms2 += str;
    return 1;
  }
  else{
    rooms1 += str;
    return 1;
  }
  return 0;
}

remove_room(str){
int a;
  a = member_array(str,rooms1);
  if(a != -1){
    rooms1[a] = "VACANT";
    return 1;
  }
  a = member_array(str,rooms2);
  if(a != -1){
    rooms2[a] = "VACANT";
    return 1;
  }
  return 0;
}
