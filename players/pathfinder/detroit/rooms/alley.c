/* players/pathfinder/detroit/rooms/alley */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("Skeeza")) {
  move_object(clone_object("players/pathfinder/detroit/monsters/skeeza"), this_object()); 
    }
  
 
if(!arg) {
set_light(1);
short_desc = "Alley";
long_desc = "\n"+
"You enter the alley.  It is a dimly lit, dirty place.  You notice the only \n"+
"source of light in here is from behind you.  As you venture deeper you see \n"+
"a huge single figure keeping his face out of the light.  He approaches you...\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/hood3", "back",
});
items = ({
"grafitti", "They look like gang symbols.",
"police", "Virtually non-existant around these parts.",
"gang", "Many gangs around here have daily shoot-outs over territory.",
"warzone", "This place honestly looks like it could be placed in Germany after WWII",
"drug", "Lots of drugs are pushed around these parts.",
"light", "A street light.  It is far behind you, providing little light.",
        });
}
 
 
}

