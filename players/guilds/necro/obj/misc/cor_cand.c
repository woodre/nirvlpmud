/* Taken from Saber's Eternal Torch with persmission */

#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg) {
  if(arg) return;

   set_id("candle");
   set_short("A corpse candle");
   set_long("A dark red candle made from tallow and blood.\n"+
            "You may light and extinguish the corpse candle.\n");
   set_weight(1);
   set_value(0);
   set_light(0);
}

init() {
  add_action("light_candle","light");
  add_action("extinguish_candle","extinguish");
}

light_candle(str)  {
if(!str) { write("What do you want to light?\n");
  return 1; }
if(str == "candle") {
write("You light the corpse candle.\n"+
      "An erie glow falls over the area.\n");
say(tp+" lights a small, dark red candle.\n");
set_light(1);
    return 1;   }
}

extinguish_candle(str)  {
if(!str) { write("What do you want to extinguish?\n");
  return 1; }
if(str == "candle")  {
write("You extinguish the corpse candle\n"+
      "The light in the room seems to increase....\n");
say(tp+" extinguishes the dark red candle.\n");
set_light(-1);
  return 1;
}
}
