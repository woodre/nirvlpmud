inherit        "room/room";
 
object gd;
 
reset(arg) { 
  if(!present("guard")) {
    gd = clone_object("obj/monster");
    gd->set_name("guard");
    gd->set_alias("vogon guard");
    gd->set_alt_name("vogon");
    gd->set_short("A young vogon guard");
    gd->set_race("vogon");
    gd->set_long("This is a large, young vogon guard with instructions to\n"+
                 "throw you off of the space ship.\n");
    gd->set_level(12);
    gd->set_wc(11);
    gd->set_ac(9);
    gd->set_hps(120);
    gd->set_aggressive(0);
    gd->set_chat_chance(50);
    gd->load_chat("The young guard shouts: RESISTANCE IS USELESS!!!\n");
    gd->load_chat("The young guard says: I've got to throw you off of this ship.\n");
    gd->load_chat("The young guard shouts: RESISTANCE IS USELESS!!!\n");
    gd->load_chat("The young guard says: I really like shouting.\n");
    gd->load_chat("The young guard says: I really like shouting.\n");
    move_object(gd,this_object());
}
  if(!arg) {
  set_light(0);
  short_desc = "A gloomy storeroom";
  long_desc = 
   "You are now in the gloomy hold of a ship in the Vogon Constructor Fleet.\n"+
   "You have a feeling you aren't going to like it on this ship.\n"+
   "\n"+
   "You begin to wonder - who are these vogons?  will I get along with them?\n"+
   "do they have a good poetry club?\n"+
   "By the way, the guard should be along any moment.\n"+
   "\n";
  dest_dir = ({"players/astaroth/hhg/shall", "out"});
  }
}
telesay() {
   tell_room(this_object(),"Something shimmers into solidity.\n");
   return 1;
}
