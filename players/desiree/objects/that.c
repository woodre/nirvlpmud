inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("that");
   set_short("a that");
   set_long("blah\n");
}

init() {
   add_action("new_this","new_this");
}

new_this() {
   destruct(present("this",this_player()));
   move_object(clone_object("/players/desiree/objects/this"),this_player());
   return 1; }
