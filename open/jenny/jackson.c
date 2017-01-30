inherit "/obj/monster";
#include "/players/jenny/define.h"
int x, play;
id(str) { return str == "michael jackson" ||  str == "michael" || str == "jackson" || str == "singer"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Michael Jackson");
    set_race("human");
set_gender("male");
    set_al(60+random(55));
    set_level(13);
    set_hp(175+random(20));
    set_wc(17+random(2));
MOCO("/players/jenny/80s/items/glove.c"),this_object());
init_command("wear glove");
    set_ac(11+random(2));
    set_short(BOLD+HIR+"Michael Jackson"+NORM);
    set_long(
      "Michael Jackson is a skinny black man with very feminine features.\n"+
      "He is wearing a red leather jacket, with chains and zippers on it.\n"+
      "Michael was probably the most popular musician of the 80's.  His \n"+
     "'Thriller' album smashed sales records of the time.  He doesn't look\n"+
     "very good right now, since his hair recently caught on fire filming a \n"+
     "pepsi commercial.  If you "+BOLD+"pay "+NORM+"him 5 coins, he might sing a song for you.\n");
  gold=clone_object("obj/money");
  gold->set_money(450+random(200));
  move_object(gold,this_object());
}

init() {
   ::init();
   add_action("music","pay");
}
music() {
   if(this_player()->query_money() < 5) {
      write(RED+"Michael says: "+NORM+"I'm sorry, but i'll need 5 coins.\n");
      return 1; }
   if(play) { write("He's already singing.\n"); return 1; }
   tell_room(ENVTP,BOLD+"Michael picks up the microphone."+NORM+"\n");
   TP->add_money(-5);
   play = 1; call_out("song",3);
   return 1; }

song(){
   sing_it();
   x += 1;
   if(x<50) call_out("song",4);
   else { play = 0; x = 0; }
   return 1; }

sing_it() {
   string lyric;
   switch(x) {
      case 0: lyric = "It's close to midnight and something evil's lurking in the dark"; break;
      case 1: lyric = "Under the moonlight you see a sight that almost stops your heart"; break;
      case 2: lyric = "You try to scream but terror takes the sound before you make it"; break;
      case 3: lyric = "You start to freeze as horror looks you right between the eyes"; break;
      case 4: lyric = "You're paralyzed"; break;
      case 5: lyric = "Cause this is thriller, thriller night"; break;
      case 6: lyric = "And no one's gonna save you from the beast about strike"; break;
      case 7: lyric = "You know it's thriller, thriller night"; break;
      case 8: lyric = "You're fighting for your life inside a killer, thriller"; break;
      case 9: lyric = "tonight"; break;
      case 10: lyric = "You hear the door slam and realize there's nowhere left to run"; break;
      case 11: lyric = "You feel the cold hand and wonder if you'll ever see the sun"; break;
      case 12: lyric = "You close your eyes and hope that this is just imagination"; break;
      case 13: lyric = "But all the while you hear the creature creepin' up behind"; break; 
      case 14: lyric = "You're out of time"; break;
      case 15: lyric = "Cause this is thriller, thriller night"; break;
      case 16: lyric = "There ain't no second chance against the thing with forty eyes"; break;
      case 17: lyric = "You know it's thriller, thriller night"; break;
      case 18: lyric = "You're fighting for your life inside of killer, thriller"; break;
      case 19: lyric = "tonight"; break; 
      case 20: lyric = "Night creatures call"; break;
      case 21: lyric = "And the dead start to walk in their masquerade"; break;
      case 22: lyric = "There's no escapin' the jaws of the alien this time"; break;
      case 23: lyric = "This is the end of your life"; break;
      case 24: lyric = "They're out to get you, there's demons closing in on every side"; break;
      case 25: lyric = "They will possess you unless you change the number on your dial"; break; 
      case 26: lyric = "Now is the time for you and I to cuddle close together"; break; 
      case 27: lyric = "All thru the night I'll save you from the terror on the screen"; break; 
      case 28: lyric = "I'll make you see"; break;
      case 29: lyric = "That this is thriller, thriller night"; break;
      case 30: lyric = "Cause I can thrill you more than any ghost would dare to try"; break;
      case 31: lyric = "Girl, this is thriller, thriller night"; break;
      case 32: lyric = "So let me hold you tight and share a killer, diller, chiller Thriller here tonight"; break;
      case 33: lyric = RED+"Darkness falls across the land"; break; 
      case 34: lyric = RED+"The midnite hour is close at hand"; break;
      case 35: lyric = RED+"Creatures crawl in search of blood"; break;
      case 36: lyric = RED+"To terrorize y'awl's neighbourhood"; break;
      case 37: lyric = RED+"And whosoever shall be found"; break;
      case 38: lyric = RED+"Without the soul for getting down"; break;
      case 39: lyric = RED+"Must stand and face the hounds of hell"; break; 
      case 40: lyric = RED+"And rot inside a corpse's shell"; break;
      case 41: lyric = RED+"The foulest stench is in the air"; break;
      case 42: lyric = RED+"The funk of forty thousand years"; break;
      case 43: lyric = RED+"And grizzy ghouls from every tomb"; break; 
      case 44: lyric = RED+"Are closing in to seal your doom"; break; 
      case 45: lyric = RED+"And though you fight to stay alive"; break;
      case 46: lyric = RED+"Your body starts to shiver"; break;
      case 47: lyric = RED+"For no mere mortal can resist"; break;
      case 48: lyric = RED+"The evil of the thriller"; break; 
      case 49: lyric = "Michael breaks into a manical laugh, and exposes his "+RED+"blood "+NORM+BOLD+"drenched fangs."; break; }


    tell_room(ENVTP,BOLD+lyric+NORM+"\n");
   return 1; }
