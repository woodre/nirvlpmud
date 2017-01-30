inherit "/room/room";

#define OBJ "/players/guilds/necro/obj"

reset(arg){
    if(!present("boneportal", this_object()))
	move_object(clone_object(OBJ+"/misc/boneportal.c"), this_object());
    if(arg) return;
    set_light(1);
    short_desc="Village Church's Graveyard";
    long_desc =" "+
    "This is the village churches graveyard.\n";
    dest_dir=({
      "/room/church.c","southeast",
    });
}
