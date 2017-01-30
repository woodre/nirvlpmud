#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="Barbarian encampment";
 long_desc =
 "  Looking around you can see the dwellings that the Clan of the\n"+
 "Snake use for living.  For being in such a remote location, they\n"+
 "seem to have adapted well.  Torches line the paths around the\n"+
 "village providing ample light.  The fence to the south provides\n"+
 "protection from anybody who would want to invade.\n";

 items = ({
   "dwellings",
   "The dwellings are made out of wood and a sort of clay", 
   "dwelling",
   "The dwellings are made out of wood and a sort of clay", 
   "fence",
   "The fence look like trees sharpened to a point, preventing invasion",
   "torches",
   "The torches give off all the light the village needs"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbVilEnt.c","west",
   "/players/catacomb/barbtribe/brooms/barbvil1.c","north",
   "/players/catacomb/barbtribe/brooms/barbvil4.c","east" 
   });

}

init(){
  ::init();
      add_action("listenem","listen");  
  }

listenem(str)
{
  write("You hear the daily chat of the barbarians.\n");
  say(TPN+" listens to the barbarians chat.\n");
  return 1;  
}