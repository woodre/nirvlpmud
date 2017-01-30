/* players/pathfinder/detroit/rooms/house5 */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("dj")) {
  move_object(clone_object("players/pathfinder/detroit/monsters/dj"), this_object()); 
    }
 
if(!arg) {
set_light(1);
short_desc = "House Party";
long_desc = "\n"+
"  You walk into the house stuggling to move forward toward the music.  After\n"+
"several enduring minutes of struggling to get into the house you can see \n"+
"DJ MixMaster sitting there cutting up the jams with the bass.  You can see\n"+
"being thrown away from the house everytime the speakers kick.  You wonder\n"+
"if you will be one of them...\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/hood2", "leave",
});
items = ({
  "speakers", "24 inch monsters that could blow your head off if you were too close.",
        });
}
}
 
init() {
  ::init();
  if(!this_player()->query_hit_points() > 100) {
    write("You hear the deafening sound of the bass drum in your ear as you\n");
    write("hurled back into the street.\n");
    say("You see the bass drum thump as you see "+capitalize(this_player()->query_name())+" thrown out\n");
    say("into the street!\n");
    call_other(this_player(),"move_object","running#players/pathfinder/detroit/rooms/hood2");
    return 1;
  } else {
    this_player()->heal_self(-25);
    write("You catch a shot of bass in the face as you enter the house!\n");
    say(capitalize(this_player()->query_name())+" catches a thunderclap of bass as they enter the house!\n");
    return 1;
  }
  
}
 
 

