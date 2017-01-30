#include "/players/francesco/univ/ansi.h"
inherit "obj/armor.c";

reset(arg){
   if (arg) return;
   set_id("frateller");
}
init(){add_action("fratell","fratell");}

fratell(str) {
  object player;
   if(!str) {write("Tell Francesco what?\n"); return 1;}
      player = find_player("francesco");
       	if(!player) {write("Francesco is not online now.\n"); return 1; }
	  tell_object(player, this_player()->query_name()+" politely speaks: "+str+" \n");
          write("You tell Francesco: "+str+"\n");
return 1;}