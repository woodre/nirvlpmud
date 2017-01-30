inherit "room/room";

reset(arg) {
if(arg) return;

if (!present("slippery")) {
  move_object(clone_object("/players/pestilence/blue/mob/slippery.c"),
        this_object()); }
short_desc = "bathroom";
long_desc =
"    A bathroom just like every other normal bathroom.  There is a sink\n"+
"with a medicine cabinet over it.  A combination bathtub and shower is\n"+
"on the south wall.  There are a lot of water toys for the tub on\n"+
"the floor.\n";
set_light(1);

items = ({
"sink","A white ceramic sink",
"bathtub","A ceramic bathtub with a shower head",
"shower","A ceramic bathtub with a shower head at the top, and a shower curtain that goes across",
"floor","The floor is made of white ceramic tiles.",
"tub","A ceramic bathtub with a shower head",
"ducky","A small yellow ducky that squeaks",
"curtain","A blue shower curtain hanging in the shower",
"boats","Toy boats that are good for the tub",
"tiles","White ceramic tiles covering the floor",
"mirror","You see yourself in the mirror",
"toys","There is a rubber ducky and some little boats",
"cabinet","A cabinet that holds medicine inside and has a mirror on the outside",
});

dest_dir = ({
"/players/pestilence/blue/rooms/hall.c","north",
});
}
