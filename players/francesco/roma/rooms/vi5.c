#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
object tourist;

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "New area, under construction" ;
long_desc =
     "   Ci deve essere il turista (via5)\n",

items = ({
   });

dest_dir = ({
  "/players/francesco/roma/rooms/vi4.c","west",
  "/players/francesco/roma/rooms/vi6.c","east"
});
   starta_tourist();
}


init(){
      ::init();
      }


starta_tourist() {
    if(!tourist || !living(tourist)) {
        tourist= clone_object("obj/monster");
        call_other(tourist, "set_name", "tourist");
        call_other(tourist, "set_alias", "man");
        call_other(tourist, "set_short", "Visiting tourist");
        call_other(tourist, "set_long", "The tourist is dressed with very comfortable items.  He is wearing\n"+
              "sandals, large shorts and an armless top with several patch pockets.\n"+
              "He is carrying a backpack on his shoulders, a camera held on his \n"+
              "neck with a thin belt, a foldable map in his left hand and a walking\n"+
              "cane on his right one.  Notwithstanding he is well on in years, he still\n"+
              "looks very healthy: his movements are fast, his cane is continuosly waved\n"+
              "around like a brandished sword. Also his gaze is menacing, like if he \n"+
              "wanted to fear people off himself. Definately, he wants only to go wandering\n"+
              "around the world, he does not want to be diverted from his goal, beware.\n");
        call_other(tourist, "set_ac", 17);
        call_other(tourist, "set_level",20);
        call_other(tourist, "set_al",0);
        call_other(tourist, "set_hp",500);
        call_other(tourist, "set_wc",30);
        call_other(tourist, "set_aggressive", 0);
        move_object(tourist, "/players/francesco/roma/rooms/vi5.c");
        call_other(tourist, "set_object", this_object());
        call_other(tourist, "set_chat_chance",20);
        call_other(tourist, "set_a_chat_chance", 33);
        call_other(tourist, "load_chat", "The tourist readies his camera and takes a picture of the surroundings.\n");
/*       call_other(tourist, "set_random_pick", 20); */
        call_other(tourist, "set_move_at_reset", 0);
        call_out("muovi",1);
    }
}
muovi()
 {
  if(tourist) tourist->random_move();
  call_out("muovi",16);
  return 1;
}

