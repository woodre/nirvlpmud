inherit "room/room";
reset(arg) {
   if(!arg) {
   set_light(1);
      short_desc = "Scullery";

      long_desc =
     "You have entered the scullery where servants run around\n"+ 
     "making final preparations for tonight's feast. A wild boar turns\n"+ 
     "on a spit in the far wall above a roaring fire. Great ovens\n"+ 
     "to the west produce the scent of baking breads and fruit.\n"+  
     "Servants rush in and out of a door to the east where other\n"+ 
     "preparations for the feast are being made.\n"+  
     "They do not let you pass.\n";

   items = ({
     "servants","Watch out! They are very busy",
     "boar","It's the spitting image of a boar",
     "fire","This is plain cooking fire, not holy fire",
     "ovens","All of the ovens are in use for the feast",
  });

  dest_dir = ({
      "/players/arrina/palace/feasthall.c","south",
  });
} }

