#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int X;
int open;
reset(arg) {
if(!present("bear")) {   
    move_object(clone_object("/players/brittany/xanth/NPC/gummybear.c"),this_object());
   }
   open = 0;
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A candy garden"+NORM;
   long_desc =
   "     The garden continues through this small path.  Some small\n"+
   "jelly-bean plants are on one side of the path.  On the other\n"+
   "side you see bushes with small puffy pods hanging from\n"+
   "them.\n";
   
   items = ({
         "marshmallows","Sweeten confections from the root of the marsh mallow",
         "garden","The garden is made of candy",
         "lollipops","Lollipops are growing from the ground",
         "pods","Small white marshmallows",
         "licorice","The weeds are made of licorice",
         "house","The candy house is north of here, maybe you can enter it",
          });

   dest_dir = ({
         "/players/brittany/xanth/garden.c","west",
         "/players/brittany/xanth/garden2.c","south",
              });
}

init() {
   ::init();
   add_action("search","search");
}

search(str) {
  write("You search the room and find nothing.\n");
   return 1;
}
