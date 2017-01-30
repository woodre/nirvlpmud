 
 
inherit "obj/monster";
 
object notice;
 
 
init() {
 
   ::init();
}
 
reset(arg) {
 
   ::reset(arg);
   if (arg) return;
 
   set_short("A government flunky");
   set_long("You can hardly tell that he is of true Mongol descent. \n");
   set_name("flunky");
   set_alias("man");
   set_race("man");
   set_al(-500);
   set_level(7);
   set_hp(130);
 
   if (!present("notice", this_object())) {
      notice = clone_object("/players/astaroth/evict");
      move_object(notice, this_object());
      call_other(this_object(), "init_command", "wield notice");
   }
 
   set_chat_chance(10);
   load_chat("The government flunky says: \"You shouldn't to be here, civilian!\"\n");
   load_chat("The government flunky says: \"We're making a bypass, you gotta build bypasses!\"\n");
 
 
}
 
