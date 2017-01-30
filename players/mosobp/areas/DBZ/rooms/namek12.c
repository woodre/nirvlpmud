inherit "room/room";
reset(arg){
    if(arg) return;

short_desc = "A Namekian road";
long_desc = 
"You stand at the entrance to the castle and see a long bridge and a gate\n"+
"at the end of the bridge. You notice water under the bridge flowing pretty good\n"+
"for a moat. The bridge looks like it never closes.\n";
 items = ({
"bridge","It looks stable enough, but better hope you don't fall anyways\n"+
"it looks like there is something in the water",
"water","The water is crystal clear, and it looks like there are aligators in the moat",
"moat","Crystal clear water surrounding the castle. It looks like there\n"+
"are alligators in the water",
"alligators","These alligators arent just normal alligators, they are 15 \n"+
"feet long and have huge mouths",
"gate","The gate to the castle",
"castle","The home of King Saichoryo",
});
set_light(1);
dest_dir = ({
"players/mosobp/areas/DBZ/rooms/namek13.c","north",
});
}
