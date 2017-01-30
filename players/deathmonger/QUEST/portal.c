

#include "std.h"

object pieces;
reset(arg){
     if(!arg){
     set_light(1);
     if(!present("pieces")){
     pieces = clone_object("players/deathmonger/QUEST/pieces");
     move_object(pieces, this_object());
     }
    }
}

short(){ return "The Portal"; }
long(){
write("You stand before the Abyssal Portal, ready to banish it forever.\n");
write("Now all you have to do is figure out how to assemble the pieces.\n");
write("There is one obvious exit: do it right.\n");
}
init(){
add_action("assemble","assemble");
}

assemble(str){
     if(!str){ write("Assemble what?\n"); return 1; }
     if(str == "statue" && present("left arm", this_player()) && 
     present("right arm", this_player()) && present("adam head", this_player())
     && present("pieces", this_player())){
       this_player()->set_quest("adamantite");
       write("Hey now, you solved that quest!\n");
       write("Cheeze Whiz tells you: Congrats!\n");
       write("Cheeze Whiz tells you: I'm gonna send you to the church now.\n");
       write("Cheeze Whiz tells you: Unfortunately, for that delicate process\n");
       write("Cheeze Whiz tells you: We're gonna have to strip you naked...\n");
       write("Cheeze Whiz tells you: sorry...have a nice day %^)\n");
       this_player()->destruct_inventory();     /*     <cackle>     */
       move_object(this_player(), "room/church");
      return 1;
      }
       else {
       write("Sorry, you're missing something important.\n");
       return 1;
       }
}
