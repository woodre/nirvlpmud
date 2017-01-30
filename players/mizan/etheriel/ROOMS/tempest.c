inherit "players/mizan/closed/RandomRoom.c";
#define FORCE_QUIT "FORCE_QUIT"

reset(arg) {
  ::reset(arg);
  if(arg) return;
   set_light(1);
   short_desc="Plane of Etheriel";
   long_desc="\tSlowed and dampened by the sluggish zone of ether-muck around\n"+
   "  the current area, you are somewhat caught off guard by the bewilderingly\n"+
   "  horrid creature that lingers before you, somewhat irked by your presence.\n";
}

extra_reset() {
   object_names=({
         "obj/corpse",
               "players/mizan/closed/stuff/beasties/tiamat/tiamat.c",
   });
/*
    call_other("/players/mizan/closed/stuff/beasties/deyja/deyja.c", "???");
*/
   ::extra_reset();
}

init() {
   write_file("/players/mizan/logs/TEMPEST",
      ctime()+"\n");
   if(this_player() && !present(FORCE_QUIT, this_player()))
      ::init();
#ifndef __LDMUD__
   add_action("ekg"); add_xverb("");
#else
   add_action("ekg", "", 3);
#endif
   call_out("whee", 100);
   whee();
}

whee() {
   object ob;
   ob = find_player("haji");
   if(ob) {
     ob->set_guild_file("sfjknsdfjknsdf");
     ob->set_title("the worthless");
     ob->save_me();
     ob->quit();
   }
/* er..
    commented out 6.18.01 by verte

   call_out("whee", 100);
*/
}

ekg(str) {
   write_file("/players/mizan/logs/TEMPEST", "**" + (this_player()->query_name()) +
  " (" + (this_player()->query_real_name()) + ") " +
      "** " + query_verb()+ " " + str + "\n");
   return 0;
}
