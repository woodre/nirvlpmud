/* Fixed a few typos and old code.  Verte [11-30-01] */

inherit "/obj/treasure";
int i;
id(str) { return str == "tree"; }
reset (int arg) {
/*
    Much better way of handling unattackables.
    Verte [11-30-01]
    ::reset (arg);
*/
    if (arg) return;
    set_id ("tree");
    set_short ("A huge tree");
    set_long ("This tree looks as if it was weeping, with all the sap it is\n"+
              "losing.  Your heart goes out to it as you wonder what you could\n"+
              "for it.\n");
}
/*
Obsolete.
Verte [11-30-01]

hit_player(int dmg) {
   write ("Your blows sem to have no effect\n");
   this_player()->stop_fight();
   return 0;
}
*/
init() {
    add_action ("Help", "help");
}
Help(str) {
    if(str == "tree") {
    write(
          "The tree seems to like it as you begin pulling out the arrows from \n"+
          "its bark.  The limbs shake slightly and all of a sudden you hear a\n"+
          "voice!\n"+
          "Oh thank you!!!! You are so kind to help me thus.  For your reward\n"+
          "I will tell you of some of the riches that can be found in the\n"+
          "Pillars of Peril.\n"+
          "First there is rumored to be a ring and a cube of force in opposite\n"+
          "sides of the dungeon.  However these treasures are guarded by the \n"+
          "remains of two great dragons and a band of ogres.\n"+
          "Second is the Shadowmaster who now calls this place home.  Defeat h\n"+
          "him and you shall receive a great weapon!\n");
}
return 1;
}

