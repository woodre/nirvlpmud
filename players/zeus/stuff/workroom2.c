inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
 if(!arg){

  set_light(1);
  long_desc= RED+"-- -== -== =-- --- =-=-= -- --==  =--- =--- =-=- ==-- --\n"+NORM;
  dest_dir=({   "/players/zeus/workroom.c", "east",    });
} }
short(){ return ""; }
  void init(){
  ::init();
  add_action("clean_cmd", "clean");
  add_action("test2", "test2");
}


status clean_cmd(){
int i, c;
c = 0;
  if((string)TP->query_real_name() != "zeus") return 0;
while(c < 2){
object *wr;
 wr = all_inventory(TO);
  for(i=0; i<sizeof(wr); i++) {
   if(!wr[i]->is_player()){ destruct(wr[i]); destruct(wr[i]); }
 }
 c++;
}
 TR(TO, "A rippling shadow passes through the room...\n");
return 1; }

test2(){
tell_room(this_object(), "test2\n\n\n");
return 1; }
