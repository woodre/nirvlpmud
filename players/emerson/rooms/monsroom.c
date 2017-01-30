inherit "room/room";
object customers;
reset(arg) {
  if(!arg) {
customers=clone_object("/players/emerson/mons/customer.c");
	move_object(customers, this_object());
set_light(1);
short_desc="Dining Area";
long_desc="You have entered the dining area of Pizza Hut. You watch as\n"+
"the customers enjoy their hot slices of pizza.  You begin\n"+
"to feel hunger pains build inside you, maybe you should try to kill a\n"+
"a customer and snag his pizza...\n";

dest_dir=({ "players/emerson/rooms/enter.c", "west",
"players/emerson/rooms/room3.c", "south",
});

   }
}
