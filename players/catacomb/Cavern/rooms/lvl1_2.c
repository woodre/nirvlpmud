#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="The Durkor caverns";
 long_desc =(
 "  Along the ceilings of the passageway, stalactites reach to\n"+
 "the ground providing ample cover for an ambush.  The Durkor are\n"+
 "all but noble warriors, they are always looking for an easy \n"+
 "kill.  There is very little light in these upper levels of the\n"+
 "cavern, giving them even more of an advantage with their ability\n"+
 "to see in the dark.\n");

 items = ({
   "passageway",
   "The stalagmites provide little movement through the passageways", 
   "ceilings",
   "The stalagmites reach down to the ground making movement difficult", 
   "ceiling",
   "The stalagmites reach down to the ground making movement difficult",
   "stalagmites",
   "The stalagmites reach down providing cover for any creature lurking in wait",
   "stalagmite",
   "The stalagmites reach down providing cover for any creature lurking in wait",
   "ground",
   "The ground makes movement trecherous"
   });

 dest_dir = ({
   "/players/catacomb/Cavern/rooms/lvl1_1.c","west",
   "/players/catacomb/Cavern/rooms/lvl1_3.c","east", 
   });

}
