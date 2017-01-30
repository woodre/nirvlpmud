#include "/players/mythos/closed/guild/def.h"
object ob, ob2, ob3, ob4;
int nh, n, cn, ch;
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(-10);
    short_desc = BOLD+"THE NEXUS"+NORM;
    long_desc =
    "THE NEXUS\n";
      call_out("check",100+random(100));
} }
realm() {return "NT"; }
init() {
  ::init();
  this_player()->set_fight_area();
  if(pp) { pp->set_defence(1); return 1;}
}

check(){
  cn = 0;
  ob3 = users();
  for(n=0;n<sizeof(ob3);n++) {
  if(present("nexus gate",environment(ob3[n]))){
  nh = present("nexus gate",environment(ob3[n]))->query_num();
  if(cn < nh) { cn = nh; }
  } }
  ch = random(cn);
  for(n=0;n<sizeof(ob3);n++) {
  if(present("nexus gate",environment(ob3[n]))){
  nh = present("nexus gate",environment(ob3[n]))->query_num();
  if( ch == nh) { ob4 = present("nexus gate",
  environment(find_player(ob3[n]->query_real_name()))); }
  } }
  if(ob4) {
  call_out("out",3); return 1;}
  call_out("check",3); return 1;
  }
  
out(){
int o;
  ob=all_inventory(this_object());
  for(o=0; o<sizeof(ob); o++) {
  if(living(ob[o])) {
  if(ob[o]->query_level() + random(10) > random(300)) {
  move_object(ob[o],environment(ob4));
  tell_room(environment(ob4),ob[o]->short()+" enters from the GATE!\n");
  } }
  }
call_out("check",random(1000));
return 1;}
