#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int mob;
reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A candy garden"+NORM;
   long_desc =
   "     The garden seems to come to an end on this path.  The bushes are\n"+
   "made of jelly-bean plants are on one side of the path.  On the other\n"+
   "side you see bushes with small puffy pods hanging from them.\n";
   
   items = ({
         "garden","A candy garden, with bushels of jelly-bean plants",
         "plants","Bushels of jelly-beans growing plants",
          "pods","Small white marshmallows, maybe you could 'pick' one",
         "bushes","Small bushes with marshmallow pods",
          "path","The end of a garden path",
          });

   dest_dir = ({
         "/players/brittany/xanth/garden1.c","west",
              });
}

init() {
   ::init();
   add_action("search","search");
   add_action("pick_marshmallow","pick");
}

search(str) {
  write("You search the room and find nothing.\n");
   return 1;
}

pick_marshmallow(str) {
   if(!str || str != "marshmallow") {
      notify_fail("What do you want to pick?\n");
      return 0; }
   write(
 "You pick a marshmallow and something happens.\n");
   say(tpn+"  pick a marshmallow.\n");
if(!mob) { move_object(clone_object("/players/brittany/xanth/NPC/gummy1.c"), this_object()); mob = 1; }
   return 1;
}
