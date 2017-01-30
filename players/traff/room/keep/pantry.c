
inherit "room/room";

reset(arg){

  if(!present("trainer"))  {
  move_object(clone_object("/players/traff/mon/trainer.c"),this_object());  }

  if(!arg){

    set_light(0);
    short_desc="Pantry";
    long_desc=
("This is a storage area for food brought in from the surrounding\n"+
"farms.  There are a number of sacks piled around and some\n"+
"shelves used for storage.\n");

    items=({
"floor","The floor is packed dirt",
"shelves","The shelves are stocked with canned fruits and vegetables",
"sacks","Burlap bags containing various items such as potatos and carrots",
 });

    dest_dir=({
      "/players/traff/room/keep/scullery.c","south",
      "/players/traff/room/courtyd.c","west",
      });
    }
  }

init()  {
 ::init();
  add_action("search","search");
}

search(str)  {

  if(!str) {
    write("Search what?\n");
    return 1; }

  write("You search the "+str+" but find nothing of interest.\n");
  return 1; }
