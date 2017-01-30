
inherit "room/room";

reset(arg){

  if(!present("minion"))  {
  move_object(clone_object("/players/traff/mon/minion.c"),this_object());  }

  if(!present("gwen"))  {
  move_object(clone_object("/players/traff/mon/gwen.c"),this_object());  }

  if(!present("william"))  {
  move_object(clone_object("/players/traff/mon/william.c"),this_object());  }

  if(!present("girl"))  {
  move_object(clone_object("/players/traff/mon/girl.c"),this_object());  }

  if(!arg){

    set_light(1);
    short_desc="East Hall";
    long_desc=
("This is the main gathering place of the keep.  It is used for meals\n"+
"and social gatherings.  There are long rows of tables and chairs here.\n"+
"There is a huge fireplace , and another one of the many paintings\n"+
"that decorate the keep.  To the north is the entrance to the\n"+
"kitchen, and west is the entrance hall.\n");

    items=({
"floor","The floor is polished marble from the mountains",
"tables","Well crafted tables in long rows",
"table","Each table is about 8 feet long and 3 feet wide",
"fireplace","A really big fireplace, with a roaring fire",
"fire","You can feel the heat from here",
"chairs","Fine wood frames with cushioned seats",
"chair","It looks pretty nice, and comfortable",
"kitchen","You can't see much from here, but you can smell food",
"painting","A young man dressed in bornze armor.  Under his left\n"+
"arm is a bronze helmet and in his right hand a magnificent\n"+
"bronze sword",
 });

    dest_dir=({
      "/players/traff/room/keep/kitchen.c","north",
      "/players/traff/room/kentry.c","west",
      });
    }
  }

init()  {
 ::init();
  add_action("search","search");
}

search(str)  {

  if(str=="room" || str=="floor" || str=="chairs"  || str=="tables"
        || str=="painting" || str=="walls")  {
  write("You search the "+str+" but find nothing of interest.\n");
    return 1; }

    write("Search what?\n");
  return 1; }
