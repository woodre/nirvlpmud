#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="The Durkor caverns";
 long_desc =(
 "  The cavern weaves this way and that with no rhyme or reason.\n"+
 "Small cracks can be seen in the sides of the cave.  With each \n"+
 "passing step the bats become more and more upset.  In the passage\n"+
 "to the west huge webs of some sort can be seen.  In each of the \n"+
 "webs a large cocoon of some sort is embedded.  The passage reaks \n"+
 "of death.\n");

 items = ({
   "cavern",
   "The bats on the ceiling are few and far between but the webs make up for the lack of bats", 
   "cracks",
   "Just cracks in the walls from years of aging", 
   "crack",
   "Just cracks in the walls from years of aging", 
   "wall",
   "The wall is full of cracks from the years", 
   "walls",
   "The walls are littered with cracks",
   "sides",
   "The sides of the passageway seem to fall apart before your eyes", 
   "side",
   "The sides of the passageway seem to fall apart before your eyes", 
   "bats",
   "There are only a few bats visible in this section",
   "bat",
   "There are only a few bats visible in this section",
   "ceiling",
   "There are only a few bats visible in this section",
   "passage",
   "The webs become very thick to the west",
   "web",
   "They look almost like spider webs",
   "coccon",
   "The only remnants of past adventurers",
   "webs",
   "The webs become very thick to the west",
   "cocoons",
   "The only remnants of past adventurers",
   "coccons",
   "The only remnants of past adventurers"
  
   });

 dest_dir = ({
   "/players/catacomb/Cavern/rooms/lvl1_7.c","west",
   "/players/catacomb/Cavern/rooms/lvl1_3.c","north" 
   });

}
