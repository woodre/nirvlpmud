inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short("A path along a Creek");
set_long(
 "  A light mist blankets the ground.  A small path follows\n"+
 "the creek to to the south.  Elves from the village of Shamot\n"+
 "come here to wash their tunics in it's crystal clear water.\n"+
 "On the opposite side a dark fog envelops the forest, known \n"+
 "by the Shamot elves as the death forest.  To the northwest is\n"+
 "is the village of Shamot.  The path continues along the creek\n"+
 "to the east.\n");

items = ({
	"mist",
	"A light mist is formed along the ground",
 	"ground",
	"The ground is covered in a plush green grass",
	"path",
	"A path leads along the creek to the west",
	"village",
	"Not much can be seen of the village to the northwest",
	"fog",
	"The fog is very thick across the creek",
	"creek",
	"A small crystal blue creek is to the south",
	"forest",
	"The dense fog makes it impossible to see into the forest",
	"water",
	"A small crystal blue creek is to the south",
	"trees",
	"The fog makes it impossible to see the trees in the forest to the south",
	"tree",
	"The fog makes it impossible to see the trees in the forest to the south",
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Creek2.c","east",
	"/players/catacomb/MF/rooms/Shamot1.c","village"
      });
}
