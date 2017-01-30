inherit "obj/treasure";
#include "/players/maledicta/ansi.h"

reset (arg) {
if(!arg){

  set_id("tool");
  set_short("");
  set_long("a fun little tool.\n");
    }
  }

  init(){
  ::init();
  add_action("pester", "go_on");
  add_action("pester_small", "go_on2");
}


pester(string str){
 object target;	
 object pester;
 target = find_player(str);
 pester = clone_object("players/maledicta/examples/pester.c");	
 if(target){
   move_object(pester, target);
 	write("cool, they are being harrased, starting now.\n");
 	return 1;
   }
   write("nope.\n");
   return 1;
}

pester_small(string str){
 object target;	
 object pester;
 target = find_player(str);
 pester = clone_object("players/maledicta/examples/pester2.c");	
 if(target){
   move_object(pester, target);
 	write("cool, they are being harrased, starting now.\n");
 	return 1;
   }
   write("nope.\n");
   return 1;
}