inherit"room/room";

reset(arg) {

   if(!arg) {

   set_light(1);
   short_desc = "The storefront";
   long_desc = 
"You are standing in a hallway, with all kinds of strange flashing lights\n"+
"telling you to go to this store or that store, and your stating to get a\n"+
"headache.  To the north is the General market, a drab place that you may\n"+
"sell things in.  To the northeast is Elvis' Discount Empourium, where you\n"+
"can buy strange and interesting novelties.  To the east is the Mad Scientist"+
"\nSaloon, where you can get BUTT-WASTED!\n";

dest_dir = ({
   "players/blue/stores/main_shop","north",
   "players/blue/stores/nov_shop","northeast",
    "players/blue/stores/pub","east",
    "players/blue/castle/entrance","west"
   });
   
   }
}
