#include "/players/snow/dervish/def.h"

inherit "room/room";
 
reset(arg){
 
 if(!arg){
 set_light(1);
  short_desc=BOLD+RED+"SandStorm"+OFF+OFF;
 long_desc=
"The "+BOLD+RED+"SandStorm"+OFF+OFF+" whirls about you.\n\
Flecks of sand whisper against your cheek, scourge your skin,\n\
and embrace you with the solid caress of a confident lover. Every\n\
crease in your skin, every orifice is filled with sand.  You are\n\
at home, one with the storm.\n";
 
items=({
 "storm","You can see nothing inside the storm. It writhes darkly and sand\n\
 sprays about you",
            });
 
  dest_dir=({
 "/players/snow/dervish/hall/desert6.c","out",
 "/players/snow/gate.c","nexus",
      });
  }   }

init() {
  ::init();
  if(this_player()->is_player()) {
    if(this_player()->query_ip_number() == "134.129.239.13") {
      move_object(this_player(),"/room/church"); 
    }
  }
  if(present(GID,TP)) {
    add_action("guild_leave","LeaveDervish");
    this_player()->set_home("/players/guilds/dervish/hall/hall.c");
    move_object(this_player(),"/players/guilds/dervish/hall/hall");
  }
 }

guild_leave(str) {
  object gob;
  gob = present("dervish_tattoo", TP);
  if(!gob) { write("You don't have a Tattoo.\n"); return 1; }
  if(TP->query_level() > 19) {
    write("Dest your guild object instead.\n"); return 1; }
  write(BOLD+"\n\n\tYou forsake the Sands.\n"+OFF);
  write(BOLD+RED+"\n\nYou are ripped to shreds by the Anger of the Sands!\n\n");
  write(OFF+OFF);
  destruct(gob);
  TP->set_guild_name(0);
  TP->set_home("/room/church.c");
  if(TP->query_exp() > 5885) {
  TP->add_exp(-(TP->query_exp() - 5885));
  TP->set_level(5);
  TP->set_extra_level(0);
  }
  TP->set_guild_file(0);
  TP->save_me();
  TP->reset();
  write("\n\nYou feel fresh and new, free of all obligations.\n");
  move_object(TP, "/room/church.c");
  CHATOB->resetchannel();
  rm("/players/snow/dervish/member/"+TP->query_real_name()+".o");
  return 1; }

offer_object(string str) {
  object ob;
  if(!str) {
    notify_fail("What would you like to offer?\n"); return 0; }
  ob = present(str, this_player());
  if(!ob) { notify_fail("You do not have "+str+".\n"); return 0; }  if(!ob->drop()) {
    notify_fail("That item cannot be offered.\n"); return 0; }
  write_file("/players/snow/log/offer",ctime(time())+" "+
    this_player()->query_real_name()+" "+ob->short()+" "+
    file_name(ob)+"\n");
  write("You offer "+BOLD+capitalize(str)+OFF+" to the Sands.\n");
  command("drop "+str, this_player());
  if(ob) destruct(ob);
  return 1; }
 
realm() { return "NT"; }
feel() { return "no"; }
query_sandstorm() { return 1; }

query_no_fight() { return 1; }
