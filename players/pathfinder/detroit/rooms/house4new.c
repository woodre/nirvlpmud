i
/* players/pathfinder/detroit/rooms/house4 */
 
inherit "room/room";
 
int i;
 
reset(arg) {
if(!present("geezer")) {
  move_object(clone_object("players/pathfinder/detroit/monsters/geezer"), this_object()); 
    }
 
if(!arg) {
set_light(1);
short_desc = "Ordinary House";
long_desc = "\n"+
"  You step into the house and find it ordinarily plain and well lived\n"+
"in but clean, there is not smoke to be seen and nothing to be picked\n"+
"up, the furniture looks like it could be replaced and the tv is a bit\n"+
"small but other than that this house looks ordinary until you hear the\n"+
"blast of a shotgun in your direction.  It seems like you have stepped\n"+
"into an ordinary house, but the owner doesn't take too kindly to people\n"+
"walking in uninvited and has chosed to be judge, jury and executioner\n"+
"and you look like the plaintiff.\n";
dest_dir = ( {
"players/pathfinder/detroit/rooms/hood2", "leave",
});
items = ({
  "furniture", "Looks like the type of furniture you'd find in any house.", 
  "tv", "A 17 inch tv, not a bad size, but a bit small.",
        });
}
}
 
init() {
  ::init();
  if(!this_player()->query_hit_points() < 100) {
    write("You are shot in the ass by the old man as you run for your life!\n");
    say(capitalize(this_player()->query_name()+" runs for their life as the old man\n");
    say("shoots them in the ass!\n");
    call_other(this_player(),"move_object","running#players/pathfinder/detroit/rooms/pstation");
    return 1;
  } else {
    this_player()->heal_self(-25);
    write("You are shot in the ass as you enter the room!\n");
    say(capitalize(this_player()->query_name())+" is shot in the ass as they enter the room!\n");
    return 1;
  }
  
}
 
 

