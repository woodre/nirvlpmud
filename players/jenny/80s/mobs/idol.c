inherit "/obj/monster";
#include "/players/jenny/define.h"
int x, play;
id(str) { return str == "billy idol" ||  str == "billy" || str == "idol" || str == "singer" || str == "Billy Idol"; } 
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("Billy Idol");
   set_race("human");
   set_gender("male");
   set_al(30+random(25));
   set_level(14);
   set_hp(180+random(20));
   set_wc(21);
   set_ac(10+random(2));
   set_short(BOLD+HIW+"Billy Idol"+NORM);
   set_long(
      "Billy Idol is a British musician with spiked white hair.  He is\n"+
      "Wearing black leather pants and a black leather jacket with no\n"+
      "shirt underneath.  He was popular for a while in the 80's.  He\n"+
      "had several hit songs, including 'Rebel Yell', and 'White Wedding'.\n"+
      "If you "+BOLD+"pay "+NORM+"him 5 coins, he might sing a song for you.\n");
   gold=clone_object("obj/money");
   gold->set_money(710+random(270));
   move_object(gold,this_object()); }

init() {
   ::init();
   add_action("music","pay");
}
music() {
   if(this_player()->query_money() < 5) {
      write(WHT+"Billy says: "+NORM+"Not til you come up with 5 coins.\n");
      return 1; }
   if(play) { write("He's already singing.\n"); return 1; }
   tell_room(ENVTP,BOLD+"Billy sneers and grabs the microphone."+NORM+"\n");
   TP->add_money(-5);
   play = 1; call_out("song",3);
   return 1; }

song(){
   sing_it();
   x += 1;
   if(x<43) call_out("song",5);
   else { play = 0; x = 0; }
   return 1; }

sing_it() {
   string lyric;
   switch(x) {
      case 0: lyric = "Last night a little dancer\ncame dancin' to my door"; break;
      case 1: lyric = "Last night a little angel\ncame pumpin cross my floor"; break;
      case 2: lyric = "She said, 'Come on baby I got a license for love"; break;
      case 3: lyric = "And if it expires pray help from above.'"; break;
      case 4: lyric = "In the midnight hour she cried-\nmore, more, more"; break;
      case 5: lyric = "With a rebel yell she cried-\nmore, more, more"; break;
      case 6: lyric = "In the midnight hour, babe, she cried-\nmore, more, more"; break;
      case 7: lyric = "With a rebel yell-\nmore, more, more"; break;
      case 8: lyric = "More, more, more."; break;
      case 9: lyric = "She don't like slavery,\nshe won't sit and beg"; break;
      case 10: lyric = "But when I'm tired and lonely\nshe sees me to bed"; break;
      case 11: lyric = "What set you free\nand brought you to me babe"; break;
      case 12: lyric = "What set you free\nI need you here by me"; break;
      case 13: lyric = "Because"; break; 
      case 14: lyric = "In the midnight hour she cried-\nmore, more, more"; break;
      case 15: lyric = "With a rebel yell she cried-\nmore, more, more"; break;
      case 16: lyric = "In the midnight hour, babe, she cried-\nmore, more, more"; break;
      case 17: lyric = "With a rebel yell-\nmore, more, more"; break;
      case 18: lyric = "More, more, more."; break;
      case 19: lyric = "He lives in his own heaven"; break; 
      case 20: lyric = "Collects it to go from the seven eleven"; break;
      case 21: lyric = "Well he's out all night to collect a fare"; break;
      case 22: lyric = "Just so long,\njust so long it don't mess up his hair."; break;
      case 23: lyric = "I walked the ward with you, babe"; break;
      case 24: lyric = "A thousand miles with you"; break;
      case 25: lyric = "I dried your tears of pain, babe"; break; 
      case 26: lyric = "A million times for you"; break; 
      case 27: lyric = "I'd sell my soul for you babe"; break;
      case 28: lyric = "For money to burn with you"; break;
      case 29: lyric = "I'd give you all,\nand have none, babe"; break;
      case 30: lyric = "Just, just, justa,\njusta to have you here by me"; break;
      case 31: lyric = "Because"; break; 
      case 32: lyric = "In the midnight hour she cried-\nmore, more, more"; break;
      case 33: lyric = "With a rebel yell she cried-\nmore, more, more"; break;
      case 34: lyric = "In the midnight hour, babe, she cried-\nmore, more, more"; break;
      case 35: lyric = "With a rebel yell-\nmore, more, more"; break;
      case 36: lyric = "More, more, more."; break;
      case 37: lyric = "Oh yeah little baby"; break;
      case 38: lyric = "she want more"; break;
      case 39: lyric = "More, more, more, more, more."; break; 
      case 40: lyric = "Oh yeah little baby"; break;
      case 41: lyric = "she want more"; break;
      case 42: lyric = "More, more, more, more."; break; }
    tell_room(ENVTP,BOLD+lyric+NORM+"\n");
   return 1; }
