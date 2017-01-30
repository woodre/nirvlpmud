/* to change the PRAY name --> lines 68 & 87  */

#include "/players/eurale/defs.h"
inherit "room/room";
int orb,fire;  /* (orb) 1=in, 0= gone, (fire) 1=safe, 0=burn  */

reset(arg) {
if(!present("shaman")) {
move_object(clone_object("players/eurale/Keep/NPC/disir_shaman"),TO); }
if(!present("riverfire")) {
move_object(clone_object("players/eurale/Keep/NPC/fire_mess"),TO); }
  orb = 1;
  fire = 0; 
  /* moved above for more usage */
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You stand in a large hollowed out room cut into this massive\n"+
	"stone.  Running through the rear of the room is literally a \n"+
	"river of fire.  There is a large throne sitting in the center\n"+
	"of the room and a long sacrificial table next to the river.\n";

items = ({
	"river","It looks like a river of flames.  The flames jump and\n"+
		"lick at the ceiling of the room but surprisingly you\n"+
		"feel very little heat",
	"throne","A high-backed stone chair with real skulls adorning\n"+
                "it's pedestal back",
	"table","A long, smooth, stone table elevated from the floor\n"+
		"next to the river.  It is stained with the blood of\n"+
		"it's many offerings and covered with a crusty material\n"+
		"that one can only assume are body innards.  What\n"+
		"secrets might it hold if you were to clean it?\n",
});

dest_dir = ({
	"players/eurale/Keep/k16.c","up",
});

}

init() {
  ::init();
  add_action("listen","listen");
  add_action("clean","clean");
  add_action("pray","pray");
  add_action("extract","extract");
}

listen(str) {
if(!str || str == "hissing") {
  write("It sounds very much like a roaring fire now.\n");
  return 1; }
}

clean(str) {
if(present("shaman")) {
  write("The Shaman glances quickly at the fire and it surrounds the\n"+
        "the table protecting it...\n");
  return 1; }
if(!present("shaman")) {
  if(!str) { write("What would you try to clean?\n"); return 1; }
  if(str == "table") {
    write("You scrub the dried blood and matter off the top of the \n"+
          "table and it reveals the following carved into the smooth\n"+
	  "stone.....\n\n"+
	  "Pray to the God of Fire, Fzendatu\n"+
	  "To 'extract' the orb without fear of burning\n"+
	  "Then offer it as a sacrifice\n"+
	  "To receive assistance from the River of Fire.\n\n");
    return 1; }
return 1; }
}

pray(str) {
if(present("shaman")) {
  write("As you close your eyes to pray, the Shaman slaps you hard\n"+
	"across the face and says: Do Not attempt to pray to a God\n"+
	"that has no use for you, mortal!!\n");
  say("The Shaman slaps "+capitalize(TPRN)+" hard.\n");
  this_player()->heal_self(-random(20));
  return 1; }
if(!present("shaman")) {
  if(!str) { write("You pray but noone hears you....\n");
    return 1; }
  if(str == "fzendatu" || str == "Fzendatu") {
    write("You pray to the God of Fire for protection....\n");
say(capitalize(TPRN)+" prays for "+this_player()->query_possessive()+" life...\n");
    fire = 1;
    return 1; }
return 1; }
return 1;
}

extract(str) {
if(present("shaman")) {
  write("The Shaman grabs your wrist...\n"); return 1; }

else {
if(!str) { write("Extract what?\n"); return 1; }
  if(str == "orb" && fire == 0) {
    write("You reach your hand into the flames.....\n"+
          "and "+HIR+"INTENSE BURNING"+NORM+" peels the skin from\n"+
          "your arm......\n");
    say(capitalize(TPRN)+" screams as the flames burn "+this_player()->query_objective()+"...\n");
    this_player()->heal_self(-(90 + random(50)));
    return 1; }
  if(str == "orb" && fire == 1 && orb == 1) {
    write("You carefully put your hand into the flaming river\n"+
	  "and feeling no pain, extract a burnished orb...\n");
    move_object(clone_object("players/eurale/Keep/OBJ/burnished_orb"),TP); 
    orb = 0;
    fire = 0;
    return 1; }
  if(str == "orb" && fire == 1 && orb == 0) {
    write("You carefully reach into the flames and find the orb gone..\n");
    fire = 0;
    return 1; }
 return 1; }
}
