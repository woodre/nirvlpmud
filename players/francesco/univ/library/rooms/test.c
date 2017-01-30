#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc= "Within the shelves";

long_desc =
      "Solamente scaffali pieni di libri.     Only shelves filled with books.\n"+
      "C'e' una piccola etichetta in cima.    There is a small tag atop of them.\n";

items = ({
      "shelves","Made by grey metal, about 1.5 meter tall and 3 meters long",
      "books","Oh my! How many are they?",
      "tag","It has some wording on it, readable",
        });
}

init() {
add_action("read_tag","read");
}

read_tag(str) {
    if(!str){
       write("Read what?\n");
       return 1;}

   if(str=="tag") {    
    write(
     "                              C O R R O S I O N \n"+
     "\nLa corrosione e' la graduale distru-   The corrosion is the gradual\n"+
     "zione di un metallo o di una lega a    destruction of a metal or alloy due \n"+
     "causa di processi chimici o elettro-   to chemical or electrochemical pro-\n"+
     "chimici connessi con fattori           cesses connected with environmental\n"+
     "ambientali.                            factors.\n\n");
  if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/library/mob/voice_corr.c"),
	this_object());  }
  return 1; }

  write("You cannot read it.\n"); 
  return 1; 
}


realm(){ return "NT"; }

