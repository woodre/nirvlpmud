#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"
inherit "room/room.c";

object new;

reset(arg) {
  move_object(clone_object("/players/dreamspeakr/CASTLE/OBJ/tatsign.c"),this_object());
  if(arg) return;
  set_light(1);
}

short(){
    return HIB+"Mark of the Gods Tattoo Studio"+NORM;
}

long(){
    write("     Bright white counters line the walls about this\n");
    write("room where the tattoos are performed.  A very comfortable \n");
    write("looking chair floats in the center of the room.  A small  \n");
    write("white stool sits on rollers next to the chair.  It appears \n");
    write("that the room is all set up for an artist to perfom the \n");
    write("delicate art of tattooing.\n");
    write("\n");
    write("The only obvious exit is:  north.");
    write("\n");
}

look(str){
    if( str == "at counters"){
      write("The are very clean and sterile looking. \n");
      return 1;
    }
    if(str == "at walls"){
      write("A beautiful depiction of a dragon and castle decorate \n");
      write("the wall directly in front of you.\n");
      return 1;
    }
    if(str == "at chair"){
      write("It looks quite comfortable.  Maybe you should '"+HIG+"sit"+NORM+"' in it!\n");
      return 1;
    }
    if(str == "at stool"){
      write("A small white stool where the artist must sit to perform \n");
      write("the tattoos.\n");
      return 1;
    }
}

init() {
    add_action("moo_north");
    add_verb( "north");
    add_action("moo");
    add_verb("sit");
    add_action("look");
    add_verb("look");
    add_action("look");
    add_verb("l");
}

moo_north() {
  move_object(this_player(), "/players/dreamspeakr/CASTLE/c127.c");
  command("look",this_player());
  if( present("thanatos",environment(this_player())) ){
     destruct_object("thanatos");
  return 1;
  } 
}

moo(str){
  object mon;
  if(!str){
    write("Where do you want to sit?\n");
    return 1;
  }
  if(str == "stool"){
    write("Ahhhh so you think your an artist huh?  \n");
    write("All of a sudden you hear a deep voice from out of no where say:\n");
    write("\n");
    write(HIR+"          G E T   O F F   M Y  S T O O L!!!!\n"+NORM);
    write("\n");
    write("You quickly jump up, so as not to anger the artist further.\n");
    write("After all, you don't wanna piss off the man with the needle!\n");
    write("\n");
    mon=clone_object("/players/dreamspeakr/CASTLE/NPC/thanatos.c"),this_object();
    move_object(mon),this_object();
    command("look",this_player());
    return 1;
  }
  if(str == "chair"){
    if(present("dream_tattoo", this_player())){
    write("\n");
    write("You already have a tattoo, what do you want to be... a FREAK?  Geesh!\n");
    return 1;
    }
    move_object(clone_object("/players/dreamspeakr/CASTLE/NPC/thanatos2.c"),this_object());
    write("You sit in the chair and immediately the servant straps you in.\n");
    write("\n");
    write("      Suddenly you begin to "+HIR+"P A N I C"+NORM+".  Fear overwhelms you!\n");
    write("\n");
    write("Thanatos enters the room and stands before you with an evil\n");
    write("grin on his face.\n");
    write("\n");
    return 1;
    }
}
realm() { return "NT"; }

