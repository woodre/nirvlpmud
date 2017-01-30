inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "A huge room that seems to be a temple, its dimensions suggest you that it must\n"+
              "have been very important some ages ago, but now it's completely naked and \n"+
              "deprived of all his importance.\n";
    short_desc = "A huge temple";
    dest_dir = ({
		"players/trix/castle/quest/Edof7","south",
                  "/players/trix/castle/quest/dod6","northwest"
                                                        });
}
realm(){return "NT";}
