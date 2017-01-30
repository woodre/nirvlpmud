inherit "/obj/treasure";
#include "/players/zeus/closed/all.h"
string xy;

reset(arg){

 set_id("bug");
 set_short("A tiny bug");
 set_long(
"This is a tiny black bug.  It has four little legs, two\n"+
"bulging little eyes, and a wide, cavernous mouth.  It also\n"+
"has two little wings on the top of its body, allowing it to\n"+
"fly around.  It has a hard little body.\n");
 set_weight(0);
 set_value(0);
 set_heart_beat(1);
}

void init(){
  ::init();
  add_action("squash_cmd", "squash");
  add_action("squash_cmd", "crush");
}

status squash_cmd(string str){
  if(!str) return 0;
  if(str == "bug")
  {
    write("You cruely squash a tiny bug.\n");
    destruct(TO);
    return 1;
  }
  else return 0;
  return 1;
}

drain(){
  if(!environment())
    return ;
  if(!sscanf(file_name(environment(environment(this_object()))), 
    "players/zeus/museum/arena/%s", xy))
    destruct(this_object());
  else {
    if(!present("bs_z_p", environment()))
      MO(CO("/players/zeus/museum/OBJ/poison.c"), environment());
    tell_object(environment(),
      "A bug bites your flesh, sucking your blood...\n");
    environment()->hit_player(5+random(20));
  }
  return 1;
}

heart_beat(){
  if(!environment()) return ;
  if(!environment()->is_player() && environment()->query_ghost())
    destruct(this_object());
  else if(!random(3))
    drain();
}

drop(){	write("The bug clings to your body!\n");  return 1; }
