#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/brittany/room";

reset(arg) {
   if(arg) return;
set_light(1);
   
short_desc = RED+"Inferno"+NORM;
   long_desc =
   "     You are standing on the other side of a black wall with a high\n"+
   "arch.  In front of the wall, on the ground, you notice a long\n"+
   "fissure.\n";

move_object(clone_object("/players/brittany/inferno/OBJ/sign.c"),this_object());

   items = ({
"wall","A black stone wall with an arch about 50 feet high",
"fissure","A narrow opening in the ground",
"ground","There is a crack in the ground, you could possibly 'squeeze through'",
"crack","A split in the ground, something looks odd, as though passage was possible",
});

   dest_dir = ({   
         "/players/brittany/inferno/fire.c","out",
          });
}
init() {
   ::init();
  add_action("squeeze_crack","squeeze");
  add_action("out","out");
  add_action("read","read");
}
 
out(str) {
   this_player()->move_player("out#/players/brittany/xanth/fire.c");
   return 1;
}
squeeze_crack(str) {
    if(!str || str != "through crack") {
        write("Squeeze what?\n");
        return 1; }
    write("You  S Q U E E Z E  through the crack.\n");
    say(tpn+"  S Q U E E Z E S  through the crack.\n");
tp->move_player("into the unknown#/players/brittany/inferno/inf1.c");
    return 1;
}
