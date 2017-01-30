inherit "/obj/monster";
#include "/players/jenny/define.h"
int x, play;
id(str) { return str == "boy george" ||  str == "boy" || str == "george" || str == "singer" || str == "Boy George"; } 
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("Boy George");
   set_race("human");
   set_gender("male");
   set_al(45+random(40));
   set_level(13);
   set_hp(200);
   set_wc(16+random(3));
   set_ac(10+random(2));
    set_short(MAG+"Boy "+CYN+"George"+NORM);
   set_long(
      "Boy George is one of the strangest musicians to come out of the\n"+
      "1980's.  He has long brown hair, and is dressed like a woman,\n"+
      "wearing a black dress, top hat, makeup, eyeshadow, jewlery, etc.\n"+
      "He sang hit songs such as 'karma Chameleon' and 'Do you really\n"+
      "want to hurt me'.  If you "+BOLD+"pay "+NORM+"him 5 coins, he might sing\n"+
      "a song for you.\n");
   gold=clone_object("obj/money");
   gold->set_money(650+random(100));
   move_object(gold,this_object()); }

init() {
   ::init();
   add_action("music","pay");
}
music(arg) {
if(arg == "boy george" || arg == "george" || arg == "boy") {
   if(this_player()->query_money() < 5) {
      write(CYN+"Boy George says: "+NORM+"Sorry, but I really need the 5 coins.\n");
      return 1; }
   if(play) { write("He's already singing.\n"); return 1; }
   tell_room(ENVTP,BOLD+"Boy George gracefully picks up the microphone."+NORM+"\n");
   TP->add_money(-5);
   play = 1; call_out("song",3);
   return 1; }}

song(){
   sing_it();
   x += 1;
   if(x<28) call_out("song",4);
   else { play = 0; x = 0; }
   return 1; }

sing_it() {
   string lyric;
   switch(x) {
      case 0: lyric = "Desert loving in your eyes all the way"; break;
      case 1: lyric = "If I listen to your lies would you say"; break;
      case 2: lyric = "I'm a man without conviction"; break;
      case 3: lyric = "I'm a man who doesn't know how to sell a contradiction"; break;
      case 4: lyric = "You come and go"; break;
      case 5: lyric = "You come and go"; break;
      case 6: lyric = "Karma Karma Karma Karma Karma Chameleon"; break;
      case 7: lyric = "You come and go"; break;
      case 8: lyric = "You come and go"; break;
      case 9: lyric = "Loving would be easy if your colors were like my dream"; break;
      case 10: lyric = "Red, gold and green"; break;
      case 11: lyric = "Red, gold and green"; break;
      case 12: lyric = "Didn't hear your wicked words every day"; break;
      case 13: lyric = "And you used to be so sweet I heard you say"; break; 
      case 14: lyric = "That my love was an addiction"; break;
      case 15: lyric = "When we cling our love is strong"; break;
      case 16: lyric = "When you go you're gone forever"; break;
      case 17: lyric = "You string along"; break;
      case 18: lyric = "You string along"; break;
      case 19: lyric = "Every day is like a survival"; break; 
      case 20: lyric = "You're my lover not my rival"; break;
      case 21: lyric = "Every day is like a survival"; break;
      case 22: lyric = "You're my lover not my rival"; break;
      case 23: lyric = "I'm a man without conviction"; break;
      case 24: lyric = "I'm a man who doesn't know how to sell a contradiction"; break;
      case 25: lyric = "You come and go"; break; 
      case 26: lyric = "You come and go"; break; 
      case 27: lyric = "Boy George curtseys and thanks you for listening."; break; }

    tell_room(ENVTP,BOLD+lyric+NORM+"\n");
   return 1; }
