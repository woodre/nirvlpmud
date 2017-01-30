
inherit "room/room";
int i;

reset(arg) {

set_light(1);

short_desc="Keating";

long_desc=
"You enter the northern half of keating.  Around you are a bunch of Army\n"+
"cadets. These guys think they are pretty bad, but you know better.\n"+
"Go on, kill 'em.\n";
extra_reset();

dest_dir= ( {
    "players/lew/newbie/field","west",
    "players/lew/newbie/keating1","south",
    } );
}
extra_reset() {
   object seaman;
   int i;
    if(!present("cadet")) {
   i = 0;
   while(i<8) {
    i += 1;
    move_object(clone_object("players/lew/newbie/cadet"), this_object());
    }
}

}
