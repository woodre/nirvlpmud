
inherit "room/room";

reset(arg){

  if(!present("boy"))  {
  move_object(clone_object("/players/traff/mon/scullboy.c"),this_object());  }

  if(!arg){

    set_light(1);
    short_desc="Scullery";
    long_desc=
("This is where the dishes are done, as well as some of the\n"+
"preliminary food preperation.  There is a large tub of water\n"+
"here, with a stack of dishes next to it.  In the corner is\n"+
"a large sack of potatos.\n");

    items=({
"floor","The floor is rough flagstone from the mountains",
"tub","A large wooden tub filled with soapy water",
"dishes","They look like they have just been washed",
"potatos","They are round and white, as if freshly peeled",
"sack","A burlap bag nearly full of potatos",
 });

    dest_dir=({
      "/players/traff/room/pantry.c","north",
      "/players/traff/room/kitchen.c","south",
      });
    }
  }

init()  {
 ::init();
  add_action("search","search");
}

search(str)  {

  if(str=="room" || str=="floor" || str=="potatoes"  || str=="sack"
      || str=="dishes" || str=="water" || str=="bag" || str=="utensils"
        || str=="tub" || str=="walls")  {
  write("You search the "+str+" but find nothing of interest.\n");
    return 1; }

    write("Search what?\n");
  return 1; }
