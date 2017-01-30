inherit "/room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"

reset(arg) {
  move_object(clone_object("/players/dreamspeakr/CASTLE/OBJ/tatsign.c"),this_object());
  if(arg) return;
set_light(1);

}
short() {
    return HIB+"Mark of the Gods Tattoo Studio"+NORM;
}

init() {
add_action("moo_north", "north");
add_action("order", "order");
add_action("order", "buy");
add_action("look", "look");
add_action("look", "l");
}

long() {
    write("     A massive grey-white marble counter stands next \n");
    write("to the far wall dominating the room.  A shimmering \n");
    write("barrior appears to protect a door just beyond the \n");
    write("counter.  Holographic images roam the studio showing \n");
    write("their tattoos to the customers.  A bright neon sign \n");
    write("floats freely about the room.\n");
    write("\n");
    write("The only obvious exit is:  north.\n");
}

look(str) {
    if( str == "at counter"){
       write("Swirls of grey and black enhance the beauty of this \n");
       write("counter made from the finest marble in the lands.\n");
       return 1;
    }
    if( str == "at wall"){
       write("Bright white walls display many moving images of a\n");
       write("wide variety of tattoos in which you can choose from.\n");
       return 1;
    }
    if( str == "at barrior"){
       write("You wonder what that is for?  Might not be a good \n");
       write("idea to attempt to 'sneak a peak', wouldn't wanna \n");
       write("anger the Gods by interrupting their work. \n");
       return 1;
    }
    if( str == "at door"){
       write("A shimmering barrior blocks the passage to the other \n");
       write("side of this strange door.\n");
       return 1;
    }
    if( str == "at walls"){
       write("Bright white walls display many holographic images of\n");
       write("beautiful women sporting sexy tattoos. \n");
       return 1;
    }
    if( str == "at images"){
       write("You stand in awe as the images move from one to another.\n");
       write( "Sexy male and female holograms becon you to watch them \n");
       write("as their tattoos transform from one pattern to another.\n");
       return 1;
    }
    if( str == "at image"){
       write("You stand in awe as the images move from one to another.\n");
       write("Sexy male and female holograms becon you to watch them \n");
       write("as their tattoos transform from one pattern to another\n");
       return 1;
    }
}

moo_north() {
  move_object(this_player(), "/players/dreamspeakr/CASTLE/c109.c");
  command("look",this_player());
  return 1;
} 

order(str) {
   if(!str){
     write("What would you like to order?\n");
     return 1;
   }
   if(str != "tattoo"){
     write("You can't buy that here!");
     return 1;
   }
   if(present("dream_tattoo", this_player())){
   write("\n");
   write("You already have a tattoo, what do you want to be... a FREAK?  Geesh!\n");
    return 1;
   }
   if (call_other(this_player(), "query_money", 0) < 10000) {
     write("Your tattoo will cost 10,000 coins, which you don't have.\n");
     return 1;
   }
   call_other(this_player(), "add_money", - 10000);
   write("You pay 10,000 gold to the salesman for a special tattoo just for you!\n");
   write("A sexy servant comes in and takes you by the hand escorting you \n");
   write("into the operations room.  She points to the chair and tells you \n");
   write("to have a seat.\n");
   write("\n");
   say( this_player()->query_cap_name() + " orders a tattoo.\n" );
   say("A servant enters the room and escorts "+ this_player()->query_cap_name() +" into the operations room.\n");
   if (str == "tattoo") {
     move_object(this_player(), "/players/dreamspeakr/CASTLE/studio.c");
   command("look",this_player());
   return 1;
   }
} 
