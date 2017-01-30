
inherit "room/room";

reset(arg){

if(!present("butler"))  {
move_object(clone_object("/players/traff/mon/butler.c"),this_object());  }
while(!present("minion 6"))  {
move_object(clone_object("/players/traff/mon/minion.c"),this_object());  }

 if(!arg){

 set_light(1);
 short_desc="Keep Entry";
 long_desc=
("This is the entrance hall of Delnoch Keep.  There are a few chairs\n"+
"here for the use of waiting guests.  The large windows are covered\n"+
"with thick velvet drapes.  To the east and west are the main wings\n"+
"of the keep.  To the north is an open courtyard.\n");

items=({
"floor","The floor is polished marble from the nearby mountains",
"chairs","Finely crafted chairs, the wood is polished and the upholstery plush",
"drapes","Golden velvet trimmed in brown.  They look expensive",
"windows","Large windows, you notice heavy wooden shutters that can be barred",
"courtyard","A large open courtyard full of flowers and shrubs",
 });

  dest_dir=({
"/players/traff/room/keep/courtyd.c","north",
"/players/traff/room/dmain.c","south",
"/players/traff/room/keep/easthall.c","east",
"/players/traff/room/keep/westhall.c","west",
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
