#include "/players/anshar/sage/def.h"

inherit "room/room";
 
reset(arg){
 
 if(!arg){
 
 set_light(1);
  short_desc="stuff";
 long_desc=
 "stuff.\n";
 
items=({
 "stuff", "stuff",
            });
 
  dest_dir=({
 "/players/anshar/workroom.c","south",
      });
  }   }
 
 init() {
  ::init();
  add_action("become_sage","join");
}

become_sage(str) {
  string myname;
  if(!str) { notify_fail("Join what?\n"); return 0; }
  if(str == "sage" || str == "sages") {
      if(present(GID, TP)) {
        write("You are already a sage.\n");
        return 1; }
      if(TP->query_guild_name() == "sage") {
        write("You are given your card.\n");
        move_object(clone_object("players/anshar/sage/gob"),TP);
        return 1; }
      myname = TP->query_real_name();
      if(TP->query_level() < 5) {
        write("You must be more powerful if you are to be a sage!\n\n");
        return 1; }
      if(TP->query_level() < 20) {
      if(query_guild(TP)) {
        write("You are already a member of a guild");
        return 1; } }
      write("You join the sages guild");
      add_to_guild(TP); return 1; }
    notify_fail("Join what?\n"); return 1; }

query_guild(ob) {
  if(!ob || !ob->is_player()) return 1;
  if(ob->query_guild_name() != "none" && ob->query_guild_name()) return 1;
  if(ob->query_guild_exp()) return 1;
  if(ob->query_guild_rank()) return 1;
  else return 0; }

add_to_guild(ob) {
  object gob;
  if(!ob || !ob->is_player()) return 1;
  ob->save_me();
  ob->reset();
  gob = clone_object("/players/anshar/sage/gob.c");
  write_file("/players/anshar/sage/JOIN",ctime(time())+" "+
  TP->query_real_name()+"\n");
  move_object(gob, ob);
      write("You are a member of the sage guild.\n");
      return 1; }
