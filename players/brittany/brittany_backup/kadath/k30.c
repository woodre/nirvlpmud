#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
status pile;
status bones;

reset(arg) {

   pile = 1;
   bones = 1;
    if(arg) return;

    set_light(0);   
    short_desc = MAG+"Kadath"+NORM;
    long_desc =
   "     The vault has a high arch and is made of basalt.  There is a\n"+
   "large crevice in the corner wall, that spreads wider at the base.\n"+
   "Some huge bones are stacked into a pile on the floor.\n";
    items = ({
         "arch","The arch is curved at the top and 50 feet high",
"crevice","A large crack forming an opening, maybe you can 'squeeze' through",
         "bones","The huge bones piled on the floor are the color of ivory",
         "wall","The wall is made out of basalt",
         "crack","A large split in the corner of the wall",
"vault","The vault is made of some kind of hardened rock",
"pile","The pile of bones seems to cover something on the floor",
"floor","A pile of bones is covering something, maybe you could 'move' it",
         "that meet at an apex",
          });

    dest_dir = ({
"/players/brittany/kadath/k29.c","out",
          });  }

init() {
    ::init();
    add_action("squeeze_opening","squeeze");
    add_action("squeeze_crack","squeeze");
    add_action("squeeze_crevice","squeeze");
    add_action("move_pile","move");
    add_action("move_bones","move");
   add_action("out","out");
    }

squeeze_opening(str) {
    if(present("ghast",this_object())) {
        write("The ghast blocks your way.\n");
        return 1; }
    if(!str || str != "opening") {
        notify_fail("Squeeze what?\n");
        return 0; }
    write("You  S Q U E E Z E  into the crevice.\n");
    say(tpn+"  S Q U E E Z E S  into the crevice and enter a dark tunnel.\n");
    tp->move_player("into the crevice#/players/brittany/kadath/k35.c");
    return 1;
}

squeeze_crack(str) {
    if(present("ghast",this_object())) {
        write("The ghast blocks your way.\n");
        return 1; }
    if(!str || str != "crack") {
        notify_fail("Squeeze what?\n");
        return 0; }
    write("You  S Q U E E Z E  into the crevice.\n");
    say(tpn+"  S Q U E E Z E S  into the crevice and enter a dark tunnel.\n");
    tp->move_player("into the crevice#/players/brittany/kadath/k35.c");
    return 1;
}

squeeze_crevice(str) {
    if(present("ghast",this_object())) {
        write("The ghast blocks your way.\n");
        return 1; }
    if(!str || str != "crevice") {
        notify_fail("Squeeze what?\n");
        return 0; }
    write("You  S Q U E E Z E  into the crevice.\n");
    say(tpn+"  S Q U E E Z E S  into the crevice and enter a dark tunnel.\n");
    tp->move_player("into the crevice#/players/brittany/kadath/k35.c");
    return 1;
}
move_pile(str){
    if(!str || str != "pile") {
       notify_fail("What do you want to move?\n");
        return 0; }
   if(pile){
    write("The pile of bones tumbles and something "+HIR+"RISES"+NORM+" from under them.\n");
 move_object(clone_object("/players/brittany/kadath/NPC/ghast.c"),this_object());  
     pile = 0;
   }
   else write("Nothing happens.\n");
   return 1; }

move_bones(str){
   if(!str || str != "bones"){
      notify_fail("what do you want to move?\n");
       return 0; }
    if(bones){
    write("The pile of bones tumbles and something "+HIR+"RISES"+NORM+" from under them.\n");
 move_object(clone_object("/players/brittany/kadath/NPC/ghast.c"),this_object());
   bones = 0; }
   else write("Nothing happens.\n");
   return 1; }

out(str){
   write("You leave the vault.\n\n");
   say(tpn+" leaves the vault.\n");
  tp->move_player("vault#/players/brittany/kadath/k29.c");
  return 1; }
