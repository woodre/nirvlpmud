#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Council Chamber of Mages";
long_desc=
"You have entered a swirling dimension of magic.  Only those who have mastered\n"+
"the ways of magic can enter here else the immense powers of this chamber may\n"+
"tear the mortal body apart.  The chamer has no walls, no floor, no ceiling.\n"+
"There are no physical properties that can define and limit the power here.\n"+
"It is here in the sancticity of this chamber that the Council of Mages may\n"+
"meet to determine the fate of the world.\n";

 if(!present("gc_board", this_object()))
 move_object(clone_object("players/pavlik/guild/mages/obj/gc_board"), this_object());


dest_dir=({
 "/players/pavlik/guild/mages/rooms/guild_room3", "north",
});

   }
}

query_mguild(){ return "Council Chamber"; }

init(){
  ::init();
  if(this_player()->query_guild_rank() < 72)
  {
    write("You are pushed out of the room by an unseen force.\n");
    say(this_player()->query_name()+" is pushed out of the room by an unseen force.\n");
    move_object(this_player(), "players/pavlik/guild/mages/rooms/guild_room3");
    return 1;
  }
  add_action("guild_move","gm");
  mage_check();
}
