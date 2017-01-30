inherit "room/room";

reset(arg) {
	object skinner;
	if (!present("skinner", this_object())) {
	   skinner = clone_object("players/gowron/room/obj/principal");
           move_object(skinner, this_object());
	}
	if (arg)
	   return;
	short_desc = "Skinner Residence";
	long_desc = "You have entered the house of Seymour Skinner and his "+
		    "mother.  Seymour is the principal of Springfield "+
		    "Elementary School and is Bart Simpson's arch nemesis.  "+
		    "The house is not very big, but it is not a shack, either.  "+
		    "Skinner is right here, so you may want to have a look at him.\n";
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/room/road3", "south", });
 	set_light(1);
}
