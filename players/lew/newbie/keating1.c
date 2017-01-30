
inherit "room/room";
int i;

reset(arg) {

set_light(1);

short_desc="Keating";

long_desc=
"After a little walk, you enter Keating hall, the gymnasium.  You see\n"+
"a lot of people running around in this area, most seem to be doing some\n"+
"form of physical training (pt).  In this area is the NAVY ROTC.  They are\n"+
"excellent for the newbie.  Go ahead and whack em.  Chances of them killin\n"+
"are slim.  To the north you hear more people training.  To the northwest you\n"+
"hear something intensely whimpy (must be the Air Force).\n";
extra_reset();

dest_dir= ( {
    "players/lew/newbie/keating2","north",
    "players/lew/newbie/enter","east",
    } );
}
extra_reset() {
   object seaman;
   int i;
    if(!present("cadet")) {
   i = 0;
   while(i<8) {
    i += 1;
    move_object(clone_object("players/lew/newbie/seaman"), this_object());
    }
}

}
