#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("voice")) {move_object(clone_object("/players/francesco/quest/mobs/voice_electrotec.c"),this_object()); }
if (!present("silent")) {move_object(clone_object("/players/francesco/quest/items/silent.c"),this_object()); }

set_light(1);

long_desc =
 "   You are in the electrotechnics area of the library.  This is an aisle\n"+
 "that is surrounded on both sides by metallic shelves.  On these\n"+
 "shelves are several books.  A tag is suspended on the left shelf.\n",

items = ({
     "shelves","The metallic shelves are very simple and robust to hold several books",
     "shelf","You can see a tag suspended on it and a button that can be pushed to lift\n"+
             "it up in order to show other books",
     "tag","Some strange words are written on the tag.  It might be useful to read it",
     "aisle","The sides of the aisle are made by the shelves",
     "books","Most of them are pale red",
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
     "                  E L E C T R O T E C H N I C S \n"+
     "\nL'elettrotecnica e' la scienza     The electrotechnics is the science\n"+
     "dei metodi, processi, ed opera-    of the methods, processes and ope-\n"+
     "zioni attraverso cui l'elettri-    rations by which the electricity is\n"+
     "cita' e' applicata nella pratica   applied in the industrial activities.\n"+
     "industriale.\n\n");
return 1;}
}

realm(){ return "NT"; }

short() {return ""+"Electrotechnics";}  