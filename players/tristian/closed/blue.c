#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "tristian";
  cap_owner = "Tristian";
  color = BOLD+HIY;
}
query_auto_load() 
{ 
return basename(this_object())+":0";
}
init() {
     if (this_player()->query_real_name()=="tristian") {
add_action("gwand","gwand");
}
}

gwand(){
	move_object(clone_object("/players/tristian/closed/shank.c"),this_player());
	return 1;
}