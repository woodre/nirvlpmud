inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="The Bamf Room";
dest_dir=({
"/room/shop.c","shop",
"/room/church.c","church",
"players/unsane/closed/hell/circle1.c","unsane",});
long_desc =
"  This is the bamf room.  Nightcrawler always teleports here before he bamfs\n"+
"to another room.  It is a featureless black void, but you get the feeling\n"+
"that you could teleport to the shop, church or hell from here.  Anyplace would\n"+
"would be fine actually, because this place is creepy.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("smell","sniff");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("You search and find nothing.\n");
say(tp+" searches around and finds nothing.\n");
return 1;
}
smell(){
write("It smells strongly of brimstone here.\n");
say(tp+" takes a deep breath of the air.\n");
return 1;
}
listen(){
write("You can hear a high pitched whining here.\n");
say(tp + " perks up their ears.\n");
return 1;
}

