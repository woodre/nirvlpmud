#include "../defs.h"

inherit "room/room";
 
reset(arg){
 
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
 HALLPATH+"/desert5.c","south",
      });
  }   }
 
 init() {
  ::init();
  add_action("embrace_sand","embrace");
  add_action("read_inscription","read"); }

read_inscription(str) {
  if(!str) { notify_fail("Read what?\n"); return 0; }
  if(str == "inscription" || str == "obelisk" || str == "stone" ||
     str == "inscriptions") {
    write("You read the Obelisk's inscription..\n\n");
    cat(GUILDPATH+"/lore6.txt");
    return 1; }
  notify_fail("Read what?\n"); return 0; }

embrace_sand(str) {
  string myname;
  if(!str) { notify_fail("Embrace what?\n"); return 0; }
  if(str == "sand" || str == "sands" || str == "storm") {
    if(present(GID, TP)) {
      write("You embrace the sands that are your home.\n");
      move_object(TP,HALLPATH+"/hall.c");
      command("look",TP);  return 1; }
    if(TP->query_guild_name() == "dervish") {
      write("Your Tattoo is burned into you.\n");
      TP->hit_player(5);
      move_object(clone_object("players/snow/dervish/gob"),TP);
      write("You embrace the sands that are your home.\n");
      move_object(TP,HALLPATH+"/hall.c");
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
 ob->set_extra_level(0);
  ob->save_me();
  ob->reset();
  gob = clone_object(GUILDPATH+"/gob.c");
  write_file(GUILDPATH+"/JOIN",ctime(time())+" "+
  TP->query_real_name()+"\n");
  move_object(gob, ob);
      write("You embrace the sands that are your home.\n");
      move_object(TP,HALLPATH+"/hall.c");
      command("look",TP);  return 1; }
