inherit "room/room";
int i,s;
object cross,plate,drink;

reset(arg) {
if(!present("wade",this_object())) 
move_object(clone_object("players/lew/southhall/wade"),this_object());
if(arg) return;
set_light(1);
short_desc="Third south";
long_desc =
"You enter Third south.  Rightaway you realize you don't want to be here.\n"+
"It 'semblance of a prison sends chills through your spine.\n"+
"How could anyone live here?  And how could they be so...so...cheary.\n";

dest_dir = ( {
     "players/lew/southhall/stairway", "down",
     "players/lew/southhall/tfloor", "west",
} );
}
init() {
::init();

    add_action("search","search");
}
search(str) {
    object will;
    will=clone_object("players/lew/southhall/will");
    if(s==1) return 0;
if(present("wade")) {
  write("Wade steps on your hand and laughs.... hehe!\n");
  return 1; }
    if(!str) { write("Search where?\n"); return 1; }
    if(str != "room") { write("You really should try searching the room here.\n");
    return 1; }
    plate=clone_object("players/lew/elof/plate");
    move_object(plate, environment(this_player()));
    i = 0;
    while(i<1) {
     i+=1;
      move_object(clone_object("players/lew/drinks/mystic"), will);
    }
    move_object(will, this_object());
    write("You have found several things.  Look to see what you have found.\n");
    s = 1;
    return 1;
}
