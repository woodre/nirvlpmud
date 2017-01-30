#include "/obj/clean.c"
#include "/players/boltar/things/esc.h"
#include "/obj/ansi.h"

int moving_time;
object deadman;

short() {
  string sh;
  sh = BOLD+HIW+"A tunnel of white light"+NORM;
  return sh;
}

reset() {
  call_out("self_destruct", 60);
}

query_value() { return 0; }
query_weight() {   return 3; }

long() {
   short();
   write("It is about 12 feet in diameter and there is no visible end.\n");
   write("It is appears to be a tunnel that only the dead may pass through.\n");
}

init() {
     add_action("light", "enter");
}

id(str) {
    return str == "tunnel" || str == "tunnel of white light" ||
    str == "white tunnel" || str == "light tunnel" || str=="light";
}

light(str) {
    object here;
    if (str && !id(str)) return 0;
    if(!this_player()->query_ghost()) {
      write("You bounce off the tunnel for you are not dead.\n");
      say(this_player()->query_name()+" bounces off the tunnel opening.\n");
      return 1;
    }
    deadman=this_player();
    here=environment(this_object());
    move_object(deadman,this_object());
    tell_room(here,this_player()->query_name()+" enters into the tunnel"+
      " of light and vanishes into it.\n");
    tell_room(here,"The tunnel of light collaspes and winks out.\n");
    move_object(this_object(),"room/test");
    write("\n\n");
    write("You enter the tunnel of light.\n");
    write("There is no color here, everything is bright white.\n");
    write("You are no longer in the world of the living.\n\n\n");
    moving_time = 5;
    set_heart_beat(1);
    
    return 1;
}

get() {return 0;}

heart_beat() {
    if (moving_time <= 0)
        return;
    moving_time -= 1;
    if (moving_time > 0) {
      say("You feel yourself sucked along by the tunnel...\n\n");
      return;
    }
    say("Leo the Archwizard appears and taps you on the head..\n");
    say("Leo vanishes!\n");
    set_heart_beat(0);
    say("\n");
    say("You see the tunnel opening up in front of you, there is the\n"+
        "color of life, of the living once again.\n\n");
    say("You are sucked out of the tunnel before the village church.\n");
    tell_room("room/vill_green", "A bright white tunnel opens up.\n");
    move_object(this_object(),"room/vill_green");
    tell_room("room/vill_green", deadman->query_name()+ 
      " arrives through the tunnel.\n");
    move_object(deadman,"room/vill_green");  
    tell_room("room/vill_green", "The tunnel collaspes into a dot and "+
      "winks out.\n");
    destruct(this_object());
}

self_destruct() {
  object here;
  here=first_inventory(this_object());
  if(here && here->is_player()) {
   call_out("self_destruct", 60);
   return 1;
  }
  here=environment(this_object());
  if(here)
  tell_room(here,"The tunnel of light collaspes and winks out.\n");
  destruct(this_object());
  return 1;
}

