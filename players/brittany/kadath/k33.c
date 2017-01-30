#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
status symbols;

int light;
int X;
reset(arg) {
   symbols = 1;
   if(arg) return;
   set_light(1);
   
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
    "     A huge stone sits in the corner on the steps.  The tower is\n"+
    "the largest of all in the cyclopean cemetary.  The colossal doorway\n"+
    "is fixed with a monstrous symbol in bas-relief.  There is a small\n"+
    "clay sconce at the beginning of the stairs.\n";

move_object(clone_object("/players/brittany/kadath/OBJ/kothsign.c"),this_object());

   items = ({
         "tower","The tower is huge and made of stone",
         "bas-relief","A small sculpture, with a figure projected slightly in the\n"+
         "background",
"candle","A candle sits inside the clay sconce, maybe you could 'light' it",
         "figure","A pictorial of a human form",
         "stairs","The stone stairs lead up to a stone door",
         "cemetary","A city of the cursed ones",
         "doorway","The doorway is 30 feet high, and there is a symbol above it",
         "steps","The stone steps are monstrous, nearly a yard high.  A huge stone sits\n"+
         "in the corner",
         "sign","Maybe you should read the sign",
         "stone","A sign is etched into the stone, maybe you could 'read' it",
         "sconce","The clay sconce with a candle inside, is mounted on the wall maybe\n"+
         "you should 'light' it",
         "wall","Some symbols on the wall, maybe you could 'decipher' them",
         "symbols","The symbols are pictures, that can only be deciphered with the old\n"+
         "Pnakotic Manuscripts",
         "symbol","A hieroglyeric symbol above the doorway",
          });

   dest_dir = ({
         "/players/brittany/kadath/k32.c","out",
         "/players/brittany/kadath/k34.c","up",
          });
}
   
init() {
   ::init();
  add_action("light_candle","light");
  add_action("decipher_symbols","decipher");
  add_action("search","search");
   add_action("out","out");
  add_action("light_sconce","light");
}

light_candle(str) {
    if(!str || str != "candle") {
        notify_fail("What do you want to light?\n");
        return 0; }
    write(
"     The candle flickers softly, then lights up the stairs.  Some symbols\n"+
    "can be seen on the adjacent wall.\n");
}
light_sconce(str) {
    if(!str || str != "sconce") {
        notify_fail("What do you want to light?\n");
        return 0; }
    write(
"     The candle flickers softly, then lights up the stairs.  Some symbols\n"+
    "can be seen on the adjacent wall.\n");
}
 


decipher_symbols(str) {
    if(!present("manuscripts",this_player())) {
    notify_fail("You do not have the manuscripts!\n");
    return 0; }

 if(!str || str != "symbols") {  
    notify_fail("Decipher what?\n");
    return 0; }
    if(X==0) {
    write("The wall S L I D E S slowly, moving you into another room.\n");
    say(tpn+"   S L I D E S into the unknown.\n");
    tp->move_player("into the unknown#/players/brittany/kadath/k38.c");
    X++;
 symbols = 0;    
    return 1; }
   else write("Nothing happens.\n");
   return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

out(str){
   write("You leave the monolith.\n\n");
   say(tpn+" leaves the monolith.\n");
  tp->move_player("vault#/players/brittany/kadath/k32.c");
  return 1; }
