#define tp this_player()->query_name()

inherit "room/room";
string *found_roll;

reset(arg){

  if(!present("cook"))  {
  move_object(clone_object("/players/traff/mon/cook.c"),this_object());  }

  if(!present("helper"))  {
  move_object(clone_object("/players/traff/mon/cookhelp.c"),this_object());  }

  if(!arg){

    found_roll = ({ }); /* allocate starting point */
    set_light(1);
    short_desc="Kitchen";
    long_desc=
("This is where the meals are prepared for the keep residents.\n"+
"A large wood burning stove dominates the center of the room.  At the\n"+
"side of the stove is a long counter.  There is a tray of fresh\n"+
"dinner rolls on the counter.  There are pots and pans on the\n"+
"stove, and various utensils scattered around the room.\n");

    items=({
"floor","The floor is rough flagstone from the mountains",
"stove","A wood burning stove",
"oven","A large oven, it is part of the stove",
"counter","It looks like a cutting board, but about 6 feet long",
"rolls","They loo and smell great.  Several are missing already",
"tray","A large tray full of rolls, a few are missing",
"pots","Full of soups and vegatables you guess",
"pans","More food cooking for the next meal",
"utensils","You know, knives, forks, spoons, ladles and such",
 });

    dest_dir=({
      "/players/traff/room/scullery.c","north",
      "/players/traff/room/easthall.c","south",
      });
    }
  }

init()  {
 ::init();
  add_action("search","search");
  add_action("swipe","swipe");
}

search(str)  {

  if(str=="room" || str=="floor" || str=="pots"  || str=="pans"
      || str=="oven" || str=="counter" || str=="tray" || str=="utensils"
        || str=="stove" || str=="walls")  {
  write("You search the "+str+" but find nothing of interest.\n");
    return 1; }

    write("Search what?\n");
  return 1; }

swipe(str) {
object food;
  if(!str) {
    write("You can't do that.\n");
    return 1; }
    if(member_array(tp, found_roll)==0) {
      write("Don't be so greedy!\n");
    return 1; }
    food = clone_object("/players/traff/misc/roll.c");
    if (!call_other(this_player(), "add_weight",
	call_other(food, "query_weight"))) {
	write("You can't carry more.\n");
	destruct(food);
	return 1;
    }
    move_object(food, this_player());
    write("You swipe a roll.\n");
    say(call_other(this_player(), "query_name",)+" swipes a roll.\n");
    found_roll += ({ tp });
    return 1;
}

