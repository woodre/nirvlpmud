#include <ansi.h>
inherit "room/room";

reset(arg){
   if(!present("gargoyle")) {
     move_object(clone_object("/players/snakespear/zultayne/critters/margar.c"),this_object());
   }
 if(arg) return;
set_light(0);
short_desc=HIW+"Marble "+NORM+"Chamber";
long_desc=
 "  This is a large room totally made from marble.  It's elaborate\n"+
 "decorations make this room very beautiful.  There is a statue in the\n"+
 "middle of the room.  There are several columns towering around the\n"+
 "room.  These columns don't extend all the way to the ceiling, so they\n"+
 "are not part of the room's supporting structure.  Rugs cover some of\n"+
 "the magnificent marble floor, but leave enough to show the extreme\n"+
 "beauty of this well built room.\n";

items=({
    "decorations","Banners, robes and gold etchings line the walls",
    "statue","A hand chiseled statue of Lady Turton.  There is a brass\n"+
             "plaque on the base.  Maybe you should read it",
    "columns","Giant greek columns made of pure marble",
    "ceiling","A large flat ceiling of marble",
    "rugs","Colorful, elaborate rugs neatly placed on the floor",
    "floor","A thick, white floor covered with gorgeous rugs",
    "banners","Long carpet-type banners used for decoration",
    "robes","The old robes of the King",
    "etchings","Pictorial etchings of battles from the past",
    "marble","A strong stone used for royality",
});

dest_dir=({
    "/players/snakespear/zultayne/rooms/room3.c","west",
    "/players/snakespear/zultayne/rooms/room9.c","north",
});
}

realm() { return "NT"; }

init() {
  ::init();
  add_action("read","read");
  add_action("search_room","search");
  add_action("listen","listen");
  add_action("smell","smell");
}
read(str) {
  if(!str) {
    write("What are you tyring to read?\n");
    return 1; }
  if(str == "plaque") { 
    write("\n  This statue is left in loving memory of Lady Turton.\n"+
          "  She brought our world joy and peace.  But when Her warm,\n"+
          "  caring soul brought all this to our lands, her life was\n"+
          "  stolen from her and us.  She feeds the strength and power\n"+
          "  into our family of warriors.  Memories are all we have,\n"+
          "  but that can never be taken from us.  God rest her loving\n"+
          "  soul and may she rest in everloving peace.\n");
    return 1; }
  else {
    write("You can't read the "+str+".\n");
    return 1; }
}

search_room(str) {
   if(!str) {
          write("What do you want to search?\n");
          return 1; }
   if(str == "rugs") {
          write("After lifting up some rugs, you still find nothing.\n");
          return 1; }
   else {
          write("You search the "+str+" but find nothing.\n");
          return 1; }  
}
smell(str) {
   if(!str) {
         write("What do you want to smell?\n");
         return 1; }
   if(str == "robes") {
	 write("The robes still hold the perfume of the King.\n");
	 return 1; }
   else {
	 write("You try to smell "+str+", but can't smell anything unusual.\n");
	 return 1; }  
}
listen(str) {
   if(!str) {
        write("What do you want to listen to?\n");
        return 1; }
   if(str == "gargoyle") {
	write("Gargoyle says: I have nothing to say to you.\n");
	return 1; }
   else {
	write("You strain to hear the "+str+", but never hear a thing.\n");
	return 1; }  
}
