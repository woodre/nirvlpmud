string name;
short() {return "Fuck off";}

long() { 
write("You have entered Paula's workroom. There is makeup all over\n"+
"the place.  She is obviously a complete slob.  You see a large bed in\n"+
"the corner, and wonder who sleeps there.  This room is obviously very\n"+
"booring and lacks detail, but who really cares? Right?\n"+
"The office is open for business\n"+
"The obvious exits are sol, pub, church, shop, guild, and castle (for\n"+
"the castle entrance)\n");
}

init() {
   add_action("church"); add_verb("church");
    add_action("sol");  add_verb("sol");
   add_action("shop"); add_verb("shop");
add_action("party"); add_verb("party");
   add_action("pub"); add_verb("pub");
   add_action("castle"); add_verb("castle");
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
pub() {
   this_player()->move_player("pub#room/pub2");
   return 1;
}
party() {
this_player()->move_player("party#/players/scooter/r/party");
return 1;
}
castle() {
    this_player()->move_player("castle#/players/paulasx/castle");
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
}

im_daemons() { return 1; }
