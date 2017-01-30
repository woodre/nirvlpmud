inherit "room/room";
#include "/players/boltar/things/esc.h"

reset(arg)
{
   object sil;
   int i;
   if(arg) return;
   set_light(1);
   long_desc = "You are in the middle of a party, coloured card stripes hang from the walls\n"+
   "and cross in the middle of the room from every direction. Baloons of different\n"+
   "shapes and colours float in the air all around you, while a loud and happy\n"+
   "music comes from the speakers of a huge hi-fi system at the four corners of\n"+
   "the room. Lots of food is spread on little tables all around the room for you\n"+
   "to grab and taste with the finest champagne produced in the heart of France.\n"+
   "              a huge sign hanging from a wall says:\n"+
   "                     "+
   esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+
   "HAPPY BIRTHDAY, KARMA!!!!"+esc+"[0m"+"\n";
   short_desc = "Karma's Party!!!";
   dest_dir = ({ "/players/trix/workroom.c", "church"});
   for(i=0;i<=10;i++){
   sil = clone_object( "/players/trix/castle/dismonst/machine/champagne");
   move_object( sil, this_object() );
   sil = clone_object( "/players/trix/castle/dismonst/machine/pizza");
   move_object( sil, this_object() );
   }
   sil = clone_object( "/players/trix/example/sylvia.c" );
   move_object( sil, this_object() );
   
}
