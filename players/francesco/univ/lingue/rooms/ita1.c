#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int contatore;

reset(arg) {
  if(arg) return;
if (!present("voice")) {
  move_object(clone_object("/players/francesco/univ/lingue/mob/voice_calc.c"),
	this_object());  }

set_light(1);

short_desc = "Audiovisual room" ;
long_desc =
     "\nQuesta stanza permette di svolgere     This room permits to give\n"+
     "lezioni con l'aiuto di moderni         lessons with the aid of modern\n"+
     "mezzi, quali videoregistratore,        tools, like videotape,\n"+
     "musicassette e calcolatore,            cassette player and computer,\n"+
     "al fine di facilitare                  in order to make it easier\n"+
     "l'apprendimento di lingue straniere.   to learning foreign languages.\n\n",

items = ({
   "videoregistratore","A videotape",
   "calcolatore","A modern computer",
   "musicassette","A cassette player",
   });

}

init(){
       add_action("answer","answer");
      }

answer(str) {
   int lev;
   if(!str){
       write("What is the answer?\n");
       return 1;   
           }
   if(str=="computer") 
    {
    if(contatore == 1){
    write(tpn+", you have already answered,  prove your fighting ability now.\n");
    return 1; }
    write("Well done, "+tpn+", you now have a chance of leaving this room.\n"+ 
          "Yet, you must prove also your figthing ability against the termite.\n");
    contatore++;
    lev = tp->query_level();
    lev++;
    move_object(clone_object("/players/francesco/univ/lingue/mob/mons"+lev+".c"),
	this_object());  
    return 1;
    }
    write("Sorry, "+tpn+", your answer is not correct.\n"); 
    return 1; 
}


realm(){ return "NT"; }
  