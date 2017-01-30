#define cost 200
inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg)
	return;
    set_name("limo");
    set_level(19);
    set_hp(99999);
    set_wc(0);
    set_ac(1000);
    set_short();
    set_long("A small man in a white collar shirt and dress pants.\n");
    set_alias("limo");
}

catch_tell(str) {
    string who, what, whe;
    if(sscanf(str,"%s tells you: %s\n",who,what) == 2) {
    if(environment(find_player(lower_case(who)))->realm() == "NT") {
    tell_object(find_player(lower_case(who)),
    "You can not hail a taxi from where you are\n");
    return 1;}
    if(what != "where" && what != "shrine" && what != "shop" && what != "church" &&
      what != "hotel" && what != "post" && what != "chamber" && what != "library" &&
      what != "juliana" && what != "akihabara") {
      tell_object(find_player(lower_case(who)),"That is not a destination.\n");
    return 1;}
    if(what == "where") {
    tell_object(find_player(lower_case(who)),
    "Calling a Limo:\n"+
    "         shop hotel shrine post\n"+
    "         chamber library juliana\n"+
    "         akihabara\n"); 
    return 1;}
    if(what == "shop") { whe = "room/shop.c"; }
    if(what == "church") { whe = "/room/church.c"; }
    if(what == "shrine") {  whe = "/players/mythos/aroom/shrinear4.c"; }
    if(what == "hotel") {  whe = "/players/boltar/hotel/hotel.c"; }
    if(what == "post") {  whe = "/room/post.c"; }
    if(what == "chamber") {  whe = "/players/mythos/enterance.c"; }
    if(what == "library") {  whe = "/players/mythos/lroom/hall.c"; }
    if(what == "juliana") {  whe = "/players/mythos/mroom/juliana.c"; }
    if(what == "akihabara") {  whe = "/players/mythos/mroom/akihabara1.c"; }
    tell_object(find_player(lower_case(who)),
    "You call for a limo.....\n");
    if(find_player(lower_case(who))->query_money() < cost) {
     tell_object(find_player(lower_case(who)),"But you dont have the money....\nSo you decide to walk....\n");
    return 1; }
    tell_room(environment(find_player(lower_case(who))),
    "\nA sleek black limo drives up.  "+capitalize(who)+" gets\n"+
    "in and the limo drives off.\n\n");
    move_object(find_player(lower_case(who)),whe);
    find_player(lower_case(who))->add_money(-cost);
    tell_room(environment(find_player(lower_case(who))),
    "\nA sleek black limo drives up.  "+capitalize(who)+" gets\n"+
    "out and the limo drives off.\n\n");
    command("look",find_player(lower_case(who)));
    return 1;}
}
