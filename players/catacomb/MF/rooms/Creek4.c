inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short("A small clearing");
set_long(
 " The clearing gives off a sense of serenity to all who enter it.\n"+
 "The Shamot elves come here to spend time together with the ones\n"+
 "they love.  The trees to the north provide ample shade to the \n"+
 "people who enter.  Small rocks are scattered around the clearing\n"+
 "to provide seating for the visitors.  To the south is bank of the\n"+
 "pond.  A path leads off to the southwest.\n");

items = ({
	"path",
	"A simple dirt path leads off to the southwest",
	"pond",
	"The bank of the pond lie to the south",
	"bank",
	"The bank of the pond lie to the south",
	"tree",
	"Large trees provide visitors with shade",
	"trees",
	"Large trees provide visitors with shade",
	"clearing",
	"The clearing provides a place for lovers to meet each other on a beautiful day",
	"rock",
	"The small rocks appear to be carved in the form of benches",
	"rocks",
	"The small rocks appear to be carved in the form of benches",
	"benches",
	"The small rocks appear to be carved in the form of benches",
	"bench",
	"The small rocks appear to be carved in the form of benches"
	});
dest_dir = ({
	"/players/catacomb/MF/rooms/Creek3.c","path",
	"/players/catacomb/MF/rooms/Creek5.c","bank"
	});
}
