inherit "room/room";
#define tp this_player()->query_name()

reset(arg){

    if(!arg){

    set_light(1);
    short_desc="Dar's War Room";
    long_desc=
  "A baren landscape perfect for the art of war.\n";

items=({
  "landscape", "The baren landscape is rocky and flat",
 });


dest_dir=({
  "/players/daranath/closed/portal.c","portal",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the landscape.\n");
say (tp +" searches the area.\n");
  return 1;
}

