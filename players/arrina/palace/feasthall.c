inherit "room/room";
reset(arg) {
   if(!arg) {
   set_light(1);
      short_desc = "Feast Hall";

      long_desc =
     "You have entered a grand hall prepared for a feast.\n"+  
     "A central table runs the length of the hall, decorated\n"+ 
     "with ivy and fruits. Silver candelabra light the room.\n"+   
     "Behind each chair on the east and west walls hang\n"+ 
     "tall banners representing legendary Paladins. Also set\n"+ 
     "into the east wall are solid double doors. Behind the\n"+ 
     "chair at the head of the table to the north hangs the\n"+ 
     "symbol of a burning sword. Behind the chair to the\n"+ 
     "south hangs the symbol of a dark crystalline orb.\n";

   items = ({
     "table","The long table is prepared for a bountiful feast",
     "ivy","Green trailing ivy decorates the table",
     "fruit","Scattered fruit brings color and a sweet aroma to the table",
     "candelabra","Many tall candelabra, each holding five white candles,\n"+
     "are set along the table",
     "banners","Each banner contains the crest and name of a Paladin\n"+
     "upon a field of blue",
     "doors","Thick double doors lead to the east",
     "sword","The banner to the north contains the symbol of a flaming\n"+
     "sword on a field of grey",
     "orb","The banner to the south depicts a dark crystalline orb on a\n"+
     "field of red"
  });

  dest_dir = ({
      "/players/arrina/palace/scullery.c","north",
      "/players/arrina/palace/sitting.c","south",
      "/players/arrina/palace/courtyard.c","east",
  });
} }
