inherit "room/room";
#define tp this_player()->query_name()

reset(arg){
    if(!arg){

    set_light(-1);
    short_desc="Cave within the Darkenwood";
    long_desc=
 "The dark walls of the cave press down upon you just the the Darkenwood\n"+
 "does with a sense of forboding and anxiety. The dark grey stone is\n"+
 "barely visible and something large lies upon the floor in the northern\n"+
 "end of the cave itself.\n";

items=({
 "walls", "The dark grey colored stone enhances the sense of danger here\n",
 "something", "Looks like something is on the floor just to the north\n"+
              "from here",
 "stone", "The stone is a dark grey color and cold to the touch",
 "floor", "A thick layer of dirt covers the floor of the cave, with many\n"+
          "footprints running across it",
 "footprints", "The prints run into the room, but none leave",
 });


dest_dir=({
 "/players/daranath/clearing/cave2.c","north",
 "/players/daranath/clearing/clear10.c","exit",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find tracks leading to the north end of the cave.\n");
say(tp +" searches the area.\n");
  return 1;
}

arate() { return "YES"; }
