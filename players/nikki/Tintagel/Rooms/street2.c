#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = YEL+"Market Way"+NORM;
long_desc = YEL+
 "   This part of the city seems rather crowded with people in search of the\n"+
 "best bargain along the market strip.  Shopkeepers shout out gibs at each\n"+
 "other as they attempt to seduce a potential customer into bargaining with\n"+
 "them for their unique items.  The small shop standing here at the end of the\n"+
 "the street seems to be the object of much attention.  There is a sign above\n"+
 "the shop. There are alleyways leading to each of the eastern towers.\n"+NORM;

items = ({
  "people","Many nobles and commoners alike are milling about in search of\n"+
           "a bargain",
  "shop","The warm toned wood adds to the sense of tranquility coming from\n"+
         "the shop, possibily aided by a ward or two to enhances it's charm",
  "sign","A brightly polished sign is hung above the shop.\n"+
         "Reading the sign will give you more information about it", 
  "strip","The strip has many shops that sell various items to anyone for\n"+
          "the right price",
  "shopkeepers","The shopkeepers are shrewd businessmen and are very good\n"+
                "at selling their wares",
  "shop","A small building at the end of the street beckons you to come inside",
  "building","A small shop at the end of the market strip",
  "alleyways","They are short little paths leading to the entrance of the\n"+
              "towers in each direction",
  "towers","There is a tower in each corner of this part of the city.\n"+
           "They both stand high above the market shops as if giving\n"+
           "their blessing on the goings on below",
});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/square.c", "backward",
    "players/nikki/Tintagel/Rooms/shop.c","forward",
    "players/nikki/Tintagel/Rooms/t1.c","right",
    "players/nikki/Tintagel/Rooms/t3.c","left",
    
});
}}

init() {
  ::init();
  add_action("read_sign","read");
  
}

/*  Read the sign  */
read_sign(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign") {
  write("\n\n\t"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^\n\n"+NORM);
  write("\t"+HIM+"                 <"+HIY+"<"+HIC+"Huzzah's Mercantile"+HIY+">"+HIM+">\n\n"+NORM);
  write("\t"+HIB+"    Blue Aura Special on all Winter Solstice Charms.\n"+NORM);
  write("\n\n\t"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^"+HIW+"="+HIY+"^"+HIW+"-"+HIY+"^\n\n"+NORM);
  return 1; }

}
