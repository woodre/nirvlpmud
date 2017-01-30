/* bkroom.c: storage from items in shop */
#define ROOM_DIR "/players/wizardchild/closed/logger/room/"
inherit "room/room";
reset(arg) {
  object ob;
  if(arg) return 0;
  set_light(1);
  short_desc = "Shop's back room";
  long_desc  = "This is the back room for the shop. All the items sold at the shop are\n"
              +"stored here.\n";
  dest_dir = 
  ({
  "/players/wizardchild/closed/logger/room/shop.c", "south"
  });
  ob = clone_object("/obj/torch.c");
  ob->set_name("torch");
  ob->set_fuel(20);
  move_object(ob, this_object());  
}
init() {
  if(!(ROOM_DIR+"checkok")->query_ok(this_player())) {
    write_file("/players/wizardchild/closed/logger/room/ILLEGAL_ENTRY",
    "<"+ctime(time())+"> "+this_player()->query_real_name()+", bkroom\n");
    move_object(this_player(), "room/plane12");
  }
  ::init();
}
has_item(str) {
  return present(str, this_object());
}
