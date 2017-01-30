inherit "room/room";
reset(arg) {
   if(!arg) {
   set_light(1);
      short_desc = "Alcove";

      long_desc =
     "You are in small dark alcove between two doors. Torches\n"+
     "on the wall are lit by an eternal blue flame.\n";

   items = ({
     "torches","They shine with a cold flame",
  });

  dest_dir = ({ 
      "/players/arrina/workroom.c","north",
      "/players/arrina/palace/study.c","south",
      "/players/arrina/palace/masterbed.c","east",
  });
} }