inherit "room/room";

reset(arg) {
   if(!arg) {
     set_light(1);
     short_desc = "A Courtyard";
     long_desc = 
"This is a beautiful clearing enclosed by the castles walls.  To the west \n"+
"is a large tree rising up over the courtyard walls, and to the north a \n"+
"passageway leads into the inner castle.\n";

   dest_dir = ({
   "players/blue/castle/tree1","west",
   "players/blue/castle/fountain","east",
   "players/blue/castle/entry1b","south",
   "players/blue/castle/courtyard2","north"
             });
       }
}
