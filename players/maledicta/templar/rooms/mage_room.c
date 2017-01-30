#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
object owner;
reset(arg) {
if(!present("templar_mage")){
	owner = clone_object("/players/maledicta/templar/mobs/templar_mage.c");
	move_object(owner, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "a large laboratory";
long_desc =
"  You stand in a very large laboratory. Along the walls are numerous\n"+
"shelves and racks, each covered in bottles and vials with body parts\n"+
"and chemicals contained within. Tables with vast amounts of equipment\n"+
"can be found scattered around the room. A dark stairway leads back up\n"+
"to the hallway.\n";

items = ({
"walls",
"Dark walls of crude stone",
"shelves",
"Wooden shelves containing numerous bottles and vials",
"racks",
"Steel racks with numerous bottles and vials scattered across them",
"bottles",
"Looking closely you see numerous animal parts and components",
"vials",
"Small vials with powerful chemicals within",
});

dest_dir = ({
  "/players/maledicta/templar/rooms/dark_stair","up"
});

}

init(){
  ::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }


realm(){ return "NT"; }

