#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Fucking Lost";
long_desc="You're Fucking Lost!\n";
dest_dir=({
  "/players/pavlik/guild/mages/rooms/mage_lobby", "hole",
});

   }
}

query_mguild(){ return "Fucking Lost"; }

init(){
 ::init();
  mage_check();
  add_action("guild_move","gm");
}
