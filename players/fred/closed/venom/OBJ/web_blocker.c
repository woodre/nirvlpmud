#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
string no_exit;
string no_exit2;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_name("webbing");
set_alt_name("web_symbiotes");
set_level(1);
set_hp(100);
set_al(0);
set_wc(0);
set_ac(0);
no_exp_value = 1;
set_dead_ob(this_object());
set_heart_beat(1);
call_out("destroy_me", 100);
}

destroy_me(){
tell_room(environment(),
"The webbing wears away and disappears.\n");
destruct(this_object());
return 1;
}

monster_died(){
tell_room(environment(),
"The webbing is destroyed!\n");
if(present("corpse", environment())){
destruct(present("corpse", environment()));
}
return 1;
}

long(str){
write(
"  This is a thick sticky webbing that covers the "+no_exit+"\n"+
"exit.  You cannot go through it, but you can 'kill' it to\n"+
"break through. It looks like its in "+shape()+" shape.\n");
return 1;
}

short(){ return BOLD+"Webbing covering the "+no_exit+" exit"+NORM; } 

shape(){
if(hit_point > 99) return "perfect";
else if(hit_point > 50) return "good";
else if(hit_point > 20) return "bad";
else return "terrible";
}

set_no_exit(str){ no_exit = str; }
query_no_exit(){ return no_exit; }
set_no_exit2(str){ no_exit2 = str; }
query_no_exit2(){ return no_exit2; }


init(){
::init();
add_action("tear_it", "tear");
#ifndef __LDMUD__
add_action("no_exit_func"); add_xverb("");
#else
add_action("no_exit_func", "", 3);
#endif
}

heart_beat(){
return 1;
}

tear_it(){
if(present("venom_object", this_player())){
  write("You grip the webbing and shread it with your bare hands!\n");
  say(this_player()->query_name()+" tears the webbing to pieces!\n");
  destruct(this_object());
  return 1;
  }
return 0;
}

no_exit_func(str){
if(str == no_exit || str == no_exit2){
  write("You attempt to go through the webbing and fail!\n");
  return 1;
  }
return;
}
