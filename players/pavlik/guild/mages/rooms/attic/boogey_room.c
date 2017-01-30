#include "/players/pavlik/guild/mages/rooms/ROOMS"
#include <ansi.h>
#define ME capitalize(this_player()->query_real_name())
inherit "room/room";
  object obj, sucker;
reset(arg) {
  if(!arg) {
sucker = 0;
set_light(1);
short_desc=GRN+"The Boogey Dimension"+NORM;
long_desc=
"You are a plane of existence exremely unlike your own.  You can barely discern\n"+
"The difference between the ground and the sky, night and day, life and death.\n"+
"Everything here seems to have a sinister quality to it.  Mischevious evil\n"+
"permeates the foreign air.  You are in .....\n"+
GRN+"   T H E  B O O G E Y  D I M E N S I O N! ! !\n"+NORM;

dest_dir=({
 "/players/pavlik/guild/mages/rooms/council_room", "escape",
});

  if(!present("boogey man", this_object())){
    obj = clone_object("players/pavlik/monsters/boogey");
    move_object(obj, this_object());
    }
   }
}

realm(){ return "NT"; }

init(){
 ::init();
 sucker_punch();
  add_action("get_the_hell_out_of_here","escape");
  add_action("no_way_jose","quit");
}

no_way_jose(){
    write(GRN+"The Boogey Man roars: Oh No you Don't!!!\n"+NORM);
    return 1;
}

get_the_hell_out_of_here(){
  int x;
  if(!present("boogey man", this_object())){
    write("You leave the realm of the Boogey Man.\n");
    move_object(this_player(), "players/pavlik/guild/mages/rooms/council_room");
    say(ME+" steps through the portal.\n");
    command("look", this_player());
    return 1;
    }
  x = random(99);
  write(
  "You get scared and make a break for the portal back to your own dimension!\n");
  write("You run across the room and dive for the portal ...\n");
  if(x < 50){
    write("   ... but the BOOGEY MAN grabs you by the collar and hauls you back!\n"+
    "Sinister laughter fills the room.\n");
    return 1;
    }
  else {
    write("   ... and make it through!!!  In the relative safety of your own\n"+
    "dimension you wipe the sweat from your forehead with a shaky hand.\n");
    move_object(this_player(), "players/pavlik/guild/mages/rooms/council_room");
    say(ME+" suddenly appears through the darkened portal!\n");
    present("portal", environment(this_player()))->set_busy(0);
    sucker = 0;
    if(present("boogey man", this_object()))
      present("boogey man", this_object())->heal_self(175);
    return 1;
  }
}

sucker_punch(){
  if(!sucker) return 1;
  if(!present("boogey man", this_object())) return 1;
  if(this_player() != sucker){
    write("You are magically zipped out of the room!\n");
    return 1;
  }
}

welcome_sucker(ob){
  sucker = ob;
  if(present("boogey man", this_object())){
  write(
  "You step through the portal into a different dimension.\n"+
  "Before you even get the chance to look around, a tall sinister shadow\n"+
  "surrounds you.  An evil being leaps from the shadows and attackes!!!\n");
  present("boogey man", this_object())->attack_object(ob);
  }
  return 1;
}
