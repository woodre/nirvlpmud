#include "/players/snow/dervish/def.h"

inherit "room/room";
 
reset(arg){

  if(!present("talker")) {
  /* move_object(clone_object(ROOT+"npc/desert6talker.c"), this_object()); */ 
  }

 if(!arg){
 
 set_light(1);
  short_desc="The desert";
 long_desc=
 "You are walking through a burning-hot, sandy rift in the desert.\n\
The sides rise up about you like quicksilver. You could not hope to\n\
move in any direction but south. There is a large obelisk in\n\
the center of the path. A swirling storm of sand rises in front of you.\n";
 
items=({
 "rift", "A rift in the desert - the path you have taken",
 "sides","The sides of the rift glow with heat",
 "obelisk","A large, grey stone rising out of the ground. It looks like\n\
 you could read the inscriptions on it",
 "path","The path is a rift in the desert",
 "desert","A horribly dry and hot desert. Right now you are in a deathly-\n\
hot rift",
 "storm","You can see nothing inside the storm. It writhes darkly and sand\n\
 sprays about you",
 "sand","Grains of sand fly about you. They seem to draw you nearer",
            });
 
  dest_dir=({
 "/players/snow/dervish/hall/desert5.c","south",
      });
  }   }
 
 init() {
  ::init();
  add_action("embrace_sand","embrace");
  add_action("read_inscription","read");
  add_action("cmd_listen","listen"); /* added by 2003.09.08 -forbin */
  add_action("cmd_seek","seek");}    /* added by 2003.09.08 -forbin */

read_inscription(str) {
  if(!str) { notify_fail("Read what?\n"); return 0; }
  if(str == "inscription" || str == "obelisk" || str == "stone" ||
     str == "inscriptions") {
    write("You read the Obelisk's inscription..\n\n");
    cat("/players/snow/dervish/lore6.txt");
    return 1; }
  notify_fail("Read what?\n"); return 0; }

embrace_sand(str) {
  string myname;
  if(!str) { notify_fail("Embrace what?\n"); return 0; }
  if(str == "sand" || str == "sands" || str == "storm") {
    if(present(GID, TP)) {
      write("You embrace the sands that are your home.\n");
      move_object(TP,"/players/snow/dervish/hall/hall.c");
      command("look",TP);  return 1; }
    if(TP->query_guild_name() == "dervish") {
      write("Your Tattoo is burned into you.\n");
      TP->hit_player(5);
      move_object(clone_object("players/snow/dervish/gob"),TP);
      write("You embrace the sands that are your home.\n");
      move_object(TP,"/players/snow/dervish/hall/hall.c");
      command("look",TP);  return 1; }
    myname = TP->query_real_name();
    if(TP->query_level() < 5) {
      write(BOLD+RED+"\n\nTHE SANDS CAST YOU OUT!\n\n"+OFF+OFF);
      TP->hit_player(60); return 1; }
    if(query_guild(TP)) {
      write(BOLD+RED+"\n\nTHE SANDS TEAR YOU APART!\n\n"+OFF+OFF);
      TP->hit_player(200); return 1; }
    if(TP->query_wimpy() || TP->query_ac()) {
      write("You are not bold enough to truly embrace the sands.\n");
      return 1; }
    write(BOLD+RED+"\n\nTHE SANDS EMBRACE YOU!\n\n"+OFF+OFF);
    add_to_guild(TP); return 1; }
  notify_fail("Embrace what?\n"); return 1; }

query_guild(ob) {
  if(!ob || !ob->is_player()) return 1;
  if(ob->query_guild_name() != "none" && ob->query_guild_name()) return 1;
  if(ob->query_guild_exp()) return 1;
  if(ob->query_guild_rank()) return 1;
  else return 0; }

add_to_guild(ob) {
  int myexp;
  object gob;
  if(!ob || !ob->is_player()) return 1;
  myexp = ob->query_exp();
  ob->add_exp(-myexp);
  ob->add_exp(5885);
  ob->set_level(5);
  ob->save_me();
  ob->reset();
  gob = clone_object("/players/snow/dervish/gob.c");
  write_file("/players/snow/dervish/JOIN",ctime(time())+" "+
  TP->query_real_name()+"\n");
  move_object(gob, ob);
      write("You embrace the sands that are your home.\n");
      move_object(TP,"/players/snow/dervish/hall/hall.c");
      command("look",TP);  return 1; }

/*
 * start addition 2003.09.08 -forbin 
 * -listen and seek functions required for dervish trial
 */
cmd_listen(string str) {
  if(!str) { 
    write("You hear a whisper on the wind.\n");
    say(this_player()->query_name()+"'s ears perk up.\n");
      return 1;
  }
  if(str == "wind" || str == "the wind" || 
     str == "winds" || str == "the winds" ||
     str == "to the wind" || str == "to the winds") {
    write("The wind caresses your ear, softly whispering:\n\n"+
          "     \"Seek the path and you may find what you desire.\"\n");
    say(this_player()->query_name()+"'s ears perk up.\n");
      return 1;
  }
  notify_fail("You listen intently to "+str+", but don't hear anything.\n");
  say(this_player()->query_name()+"'s ears perk up.\n"); 
    return 1;
}

cmd_seek(string str) {
  if(!present(GID, this_player())) {
    notify_fail("What?\n");
      return 1;
  }
  if(this_player()->query_level() < 19) {
    notify_fail("What?\n");
      return 1;
  }
  if(this_player()->query_extra_level() < 21) {
    notify_fail("What?\n");
      return 1;
  }    
  if(!str || (str != "path" && str != "the path")) {
  notify_fail("What?\n");
    return 1;
  }
  write("You place your hand on a wall of sand, only to notice it\n"+
        "passes right through.  Bravely you step toward it...\n"+
        "              and your destiny...\n\n");
  say(this_player()->query_name()+" disappears into the sands.\n");
  move_object(this_player(),"/players/snow/dervish/trials/trial1/rms/entrance.c");
  write("\nYou step through the sand into a strange place...\n\n");
  say(this_player()->query_name()+" arrives.\n");
  write(BOLD+"\n\n       Please note that this area makes use of extended\n"+
        "     soul commands.  While here you will be able to look,\n"+
        "     listen, touch, taste, and search - among many other\n"+ 
        "     things.  Most of the mobs in the area are able to\n"+ 
        "     communicate with you (meaning that they may be able\n"+
        "     to respond to tells, says, and things you ask them).\n"+ 
        "     Keep in mind that there are many hidden and vague\n"+ 
        "     clues about.  So pay close attention, look around,\n"+ 
        "     and explore your surroundings as you venture forth\n"+ 
        "     in search of Nar-Tuith.\n\n"+OFF); 
  command("look",TP);
    return 1; 
}
/* end addition 2003.09.08 -forbin */

