/* Equipment donation room */

#include "/players/jaraxle/define.h"
inherit "room/room";

reset(arg) {
   if (arg) return;
   
   set_light(1);

/* Room descriptions modified by Jara */

   short_desc = ""+HIW+"Equipment Room ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM;
   long_desc =
    "  There is little decoration adorning the walls of this room. Several\n"+
    "racks capable of storing weapons are pushed back against the stone\n"+
    "walls. Shelves above the racks have space for smaller items, and the\n"+
    "corner area has hooks and mannequins for various armors. There is a\n"+
    "golden plaque hung on the wall.\n";
   
MOCO("/players/jaraxle/templar/mobs/templar_security.c"),TO);
MOCO("/players/jaraxle/templar/mobs/templar_security.c"),TO);
MOCO("/players/jaraxle/templar/mobs/templar_security.c"),TO);
MOCO("/players/jaraxle/templar/mobs/templar_security.c"),TO);
MOCO("/players/jaraxle/templar/mobs/templar_security.c"),TO);
   items = ({
         "plaque","A golden plaque with delicately embossed lettering. You may "+GRN+"read"+NORM+" it",
         "shelves","The sturdy oak shelves are well worn from use",
         "hooks","Large iron hooks to hold armor",
});
   
   dest_dir = ({
"players/jaraxle/templar/rooms/storage.c","east",
"players/jaraxle/templar/rooms/adv_guild.c","west",
"players/jaraxle/templar/rooms/command_post.c","up",
"players/jaraxle/templar/rooms/adv_inner.c","down",
});
   
   no_castle_flag = 1;
}

realm() { return "NT"; }


query_dont_clean_obs_here(){ return 1; }

init() {
   ::init();
   add_action("read","read");
   add_action("down","down");
   add_action("up","up");
}

up(){
        if(!present("EliteTemplar",this_player())){
 write("Something blocks you from moving in that direction.\n");
 return 1; }
}
read(str) {
   if(!str) { write("Read what?\n"); return 1; }
   if(str == "sign" || str == "plaque") {
      write("\n"+
         "A golden plaque that reads:\n"+
         "   \n"+
         "\t"+HIY+"Faith, Honor, and Trust."+NORM+"\n");
      return 1; }
}

down() {
   if(!present("KnightInvite",TP)) {
      write("You are not allowed access to this room.\n");
      return 1; }
   TP->move_player("down#players/jaraxle/templar/rooms/adv_inner.c");
   return 1;
}
