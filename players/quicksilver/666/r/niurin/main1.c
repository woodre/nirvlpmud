#include "/players/quicksilver/666/include/std.h"

inherit ROOM;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_light(1);
   set_short("Niurin  <Main Road>");
   set_long("   People walk around you, stopping momentarily to glare as they traverse\n"+
   "the main road, going from shop to shop.  You hear all the typical sounds of\n"+
   "commerce in all of the clamor.  If you are in need of any equipment for\n"+
   "adventuring, it is very likely that someone here can get it for you...for a\n"+
   "price.\n"+
   "   You see shops to both the east and west.  The latter appears to be an inn\n"+
   "and the former is an armory.");
   add_item("sign", "Please specify which sign you wish to look at: 'inn sign' or 'armory sign'.");
   add_item("armory sign", "The sign reads:  Yn Shapp Eilley");
   add_item("inn sign", "The sign reads:  Kione y Chollagh Vuc");
   add_item("armory", "The village armory is a large brick building, very square-ish by design.  You\ncan hear the rythmic clanging of armor being forged comming from within.  You\nalso note a large iron forged sign hanging above the entry.");
   add_item("inn", "The village inn is where travelers and locals alike can dine and socialize.\nUnlike a tavern, the inn also rents out rooms to travelers.\nA large sign hangs above the door, proudly displaying the establishment's name.");
   add_item("road", "Don't you have anything more interesting to do than look at the road?  If you\nmust know, it is a dirt road.");
   add_exit(ROOM_DIR+"niurin/entry", "north");
   add_exit(ROOM_DIR+"niurin/main2", "south");
   add_exit(ROOM_DIR+"niurin/armory","east");
   add_exit(ROOM_DIR+"niurin/inn",   "west");
}

init() {
   ::init();
}
