#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("voice")) {move_object(clone_object("/players/francesco/quest/mobs/voice_production.c"),this_object()); }
if (!present("silent")) {move_object(clone_object("/players/francesco/quest/items/silent.c"),this_object()); }

set_light(1);

long_desc =
 "   You are in the production systems area of the library.  This is an\n"+
 "aisle that is surrounded on both sides by metallic shelves.  On these\n"+
 "shelves are several books.  A tag is suspended on the left shelf.\n",

items = ({
     "shelves","The metallic shelves are very simple and robust to hold several books",
     "shelf","You can see a tag suspended on it and a button that can be pushed to lift\n"+
             "it up in order to show other books",
     "tag","Some strange words are written on the tag.  It might be useful to read it",
     "aisle","The sides of the aisle are made by the shelves",
     "books","Most of them are magenta",
     "button","A red button which can lift the shelf",
});
}


init() {
  ::init();
  add_action("read","read");
  add_action("push","push");
}

push(str){
  if(!str) {notify_fail("Push what?\n"); return 0;}
  if(str=="button") { write("The shelf moves up.\n"); return 1;}
  write("You cannot push "+str+".\n");
return 1;}

read(str){
    if(!str){
      write("Read what?\n");
      return 1; }
    if(str=="tag"){
      write(
     "                     P R O D U C T I O N    S Y S T E M S \n"+
     "\nLo studio dei sistemi di produzione    The study of the production systems\n"+
     "e' un aspetto avanzato della  tecno-   is an advanced aspect of the manu-\n"+
     "logia meccanica.  Non analizza sola-   facturing engineering.  Not only does\n"+
     "mente i processi ma soprattutto la     it analyze the single processes\n"+
     "loro integrazione all'interno della    but mainly their integration\n"+
     "fabbrica.                              within the industry.\n\n");
return 1;}
}

realm(){ return "NT"; }

short() {return ""+"Production Systems";}  