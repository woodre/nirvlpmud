#define tp this_player()

inherit "obj/monster";

id(str) {return str=="exiter";}

reset(arg){
  if(arg) return;}

init() {
       ::init();
       add_action("go_back","go");
       }

go_back(str){
  object ob;
  if(!str) { write("Go where?\n"); return 1;}
  if(str=="back") {
   tp->move_player("to back library#players/francesco/quest/rooms/back_library.c");
   return 1; }
   write("You cant go there.\n"); 
   return 1; 
}

