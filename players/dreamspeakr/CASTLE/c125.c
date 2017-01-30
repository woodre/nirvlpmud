inherit "/room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"

reset(arg) {
  move_object(clone_object("/players/dreamspeakr/CASTLE/OBJ/marque.c"),this_object());
  if(arg) return;
  set_light(1);
}

init() {
   add_action("north", "north");
   add_action("look", "look");
   add_action("look", "l");
   add_action("darkcity", "darkcity");
}
short(){
    return HIB+"Cloud Nine Movie Theatre"+NORM;
}

long(){
    write("    The smell of fresh popcorn fills the air.  Lush red carpet\n");
    write("cushions the floors.  A large glass counter filled with candy \n");
    write("and goodies stand on the back wall of the room.  A large bright\n");
    write("marque hanging directly above the counter lists the movies that\n");
    write("are showing currently.\n");
    write("\n");
    write("The only obvious exit is:  north\n");
}

look(str){
    if(!str){
      write("What would you like to look at?");
      return 1;
    }
    if(str == "at carpet") {
      write("Plush red carpet feels so soothing under your feet.\n");
      return 1;
    }
    if( str == "at counter"){
      write("Thru the counter glass you can see loads of goodies to eat\n");
      return 1;
    }
    if ( str == "at candy"){
      write("Herseys, Snickers and many other candies look really good.\n");
      write("Too bad there isnt an attendant around to sell you some, \n");
      write("They look sooooo good!\n");
      return 1;
    }
    if( str == "at goodies"){
      write("They sure make you hungry just looking at them.  Now\n");
      write("where's that attendant at?\n");
      return 1;
    }
    if( str == "at wall"){
      write("There is a marque hanging on it.  Maybe you should look \n");
      write("at it.\n");
      return 1;
    }
}

north(){
    move_object(this_player(), "/players/dreamspeakr/CASTLE/c117.c");
    command("look", this_player());
    return 1;
}

darkcity(){
  move_object(this_player(), "/players/feldegast/darkcity/entrance.c");
  command("look",this_player());
  return 1;
} 
   
