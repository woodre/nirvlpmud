#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("voice")) {move_object(clone_object("/players/francesco/quest/mobs/voice_comp.c"),this_object()); }
if (!present("silent")) {move_object(clone_object("/players/francesco/quest/items/silent.c"),this_object()); }

set_light(1);

long_desc =
 "   You are in the computer science area of the library.  This is an aisle\n"+
 "that is surrounded on both sides by metallic shelves.  On these\n"+
 "shelves are several books.  A tag is suspended on the left shelf.\n",

items = ({
     "shelves","The metallic shelves are very simple and robust to hold several books",
     "shelf","You can see a tag suspended on it and a button that can be pushed to lift\n"+
             "it up in order to show other books",
     "tag","Some strange words are written on the tag.  It might be useful to read it",
     "aisle","The sides of the aisle are made by the shelves",
     "books","Most of them are yellow",
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
     "                          C O M P U T E R   S C I E N C E\n"+
     "\nL'informatica e' lo studio della   The computer science is the study\n"+
     "teoria e delle applicazioni dei    of the theory and the application\n"+
     "calcolatori elettronici per        of computers for the acquisition,\n"+
     "l'acquisizione, l'analisi e        the analysis and the presentation\n"+
     "la presentazione di dati.          of data.\n\n");                           
return 1;}
}

realm(){ return "NT"; }

short() {return ""+"Computer science";}  
