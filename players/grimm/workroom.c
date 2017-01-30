string name;
short() { return "Grimm's workroom (if you call it work)"; }

long() { 
write("You have entered Grimm's workroom. There is a pile of dog bones\n"+
"lying in the corner.  On the wall you can see pictures of Grimm (mostly\n"+
"the strips from the paper) and a picture of Lassie with the word 'WIMP'\n"+
"scribbled all over it. In another corner you can see a fire hydrant that\n"+
"seems...uhm...well used.\n"+
"The obvious exits are sol, post, pub, church, shop, guild, and castle (for\n"+
"the castle entrance)\n");
}

init() {
   add_action("chron","chron");
   add_action("barb","barb");
   add_action("myst","myst");
   add_action("church"); add_verb("church");
    add_action("sol");  add_verb("sol");
   add_action("shop"); add_verb("shop");
   add_action("pub"); add_verb("pub");
   add_action("castle"); add_verb("castle");
   add_action("post"); add_verb("post");
   add_action("guild"); add_verb("guild");
}
church() {

    this_player()->move_player("church#room/church");
    return 1;

}

shop() {
    this_player()->move_player("shop#room/shop");
    return 1;
}
post() {
    this_player()->move_player("post#room/post");
    return 1;
}
pub() {
   this_player()->move_player("pub#room/pub2");
   return 1;
}
castle() {
    this_player()->move_player("castle#/players/grimm/castle");
     return 1;
}
guild() {
     this_player()->move_player("guild#players/grimm/guild");
     return 1;
}
sol () {
      this_player()->move_player("into solitude#/players/grimm/solitude");
      return 1;
}
reset(arg) {
    if(!arg)
    set_light(1);
    if(!present("gboard")) {
      move_object(clone_object("/players/grimm/closed/obj/badge_stuff/board"),this_object());
    }
}

im_daemons() { return 1; }


chron() {
  this_player()->move_player("to the chrons#/players/scooter/closed/g/ghall");
  return 1;
}

barb() {
  this_player()->move_player("to the barbs#/players/grimm/bguild");
  return 1;
}

myst() {
  this_player()->move_player("to the mystiscs#/players/grimm/mguild");
  return 1;
}
