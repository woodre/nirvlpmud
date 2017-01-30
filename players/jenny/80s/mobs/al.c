inherit "/obj/monster";
#include "/players/jenny/define.h"
int x, play;
id(str) { return str == "al yankovic" ||  str == "al" || str == "yankovic" || str == "singer" || str == "weird al" || str == "Al Yankovic"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Al Yankovic");
    set_race("human");
set_gender("male");
    set_al(100+random(60));
    set_level(13);
    set_hp(200+random(10));
    set_wc(17+random(2));
    set_ac(10+random(2));
    set_short(WHT+"Al Yankovic"+NORM);
    set_long(
      "Weird Al Yankovic is a tall, skinny, goofy looking guy with long,\n"+
      "dark, curly hair.  He made a name for himself spoofing other musicians\n"+
      "throughout the 80's.  Many of his spoofs were better than the originals.\n"+
     "He also starred in the movie UHF.  If you "+BOLD+"pay "+NORM+"him 5 coins, he might\n"+
     "sing a song for you.\n");
  gold=clone_object("obj/money");
  gold->set_money(150+random(100));
  move_object(gold,this_object());
MOCO("/players/jenny/80s/items/cube.c"),this_object());
}
init() {
   ::init();
   add_action("music","pay");
}
music() {
   if(this_player()->query_money() < 5) {
      write(WHT+"Wierd Al says: "+NORM+"You don't even have 5 coins for me?\n");
      return 1; }
   if(play) { write("He's already singing.\n"); return 1; }
   tell_room(ENVTP,BOLD+"Wierd Al picks up the microphone."+NORM+"\n");
   TP->add_money(-5);
   play = 1; call_out("song",3);
   return 1; }

song(){
   sing_it();
   x += 1;
   if(x<45) call_out("song",4);
   else { play = 0; x = 0; }
   return 1; }

sing_it() {
   string lyric;
   switch(x) {
      case 0: lyric = "How come you're always such a fussy young man"; break;
      case 1: lyric = "Don't want no Captain Crunch, don't want no Raisin Bran"; break;
      case 2: lyric = "Well don't you know that other kids are starving in Japan"; break;
      case 3: lyric = "So eat it, just eat it"; break;
      case 4: lyric = "Don't want to argue, I don't want to debate"; break;
      case 5: lyric = "Don't want to hear about what kind of food you hate"; break;
      case 6: lyric = "You won't get no desert till you clean off your plate"; break;
      case 7: lyric = "So eat it"; break;
      case 8: lyric = "Don't tell me you're full"; break;
      case 9: lyric = "Just eat it, eat it"; break;
      case 10: lyric = "Get yourself an egg and beat it"; break;
      case 11: lyric = "Have some more chicken, have some more pie"; break;
      case 12: lyric = "It doesn't matter if it's broiled or fried"; break;
      case 13: lyric = "Just eat it, eat it, just eat it, eat it"; break; 
      case 14: lyric = "Just eat it, eat it, just eat it, eat it"; break;
      case 15: lyric = "Your table manners are a crying shame"; break;
      case 16: lyric = "Your playin' with your food, this ain't some kind of game"; break;
      case 17: lyric = "Now if you starve to death you'll just have yourself to blame"; break;
      case 18: lyric = "So eat it, just eat it"; break;
      case 19: lyric = "You better listen, better do what you're told"; break; 
      case 20: lyric = "You haven't even touched your tuna casserole"; break;
      case 21: lyric = "You better chow down or it's gonna get cold"; break;
      case 22: lyric = "So eat it"; break;
      case 23: lyric = "I don't care if you're full"; break;
      case 24: lyric = "Just eat it, eat it"; break;
      case 25: lyric = "Open up your mouth and feed it"; break; 
      case 26: lyric = "Have some more yogurt, have some more Spam"; break; 
      case 27: lyric = "It doesn't matter if it's fresh or canned"; break; 
      case 28: lyric = "Just eat it, eat it"; break;
      case 29: lyric = "Don't you make me repeat it"; break;
      case 30: lyric = "Have a banana, have a whole bunch"; break;
      case 31: lyric = "It doesn't matter what you had for lunch"; break;
      case 32: lyric = "Just eat it, eat it, eat it, eat it"; break;
      case 33: lyric = "Eat it, eat it, eat it, eat it"; break; 
      case 34: lyric = "Just eat it, eat it"; break;
      case 35: lyric = "If it's getting cold reheat it"; break;
      case 36: lyric = "Have a big dinner, have a light snack"; break;
      case 37: lyric = "If you don't like it,you can't send it back"; break;
      case 38: lyric = "Just eat it, eat it"; break;
      case 39: lyric = "Get yourself an egg and beat it"; break; 
      case 40: lyric = "Have some more chicken, have some more pie"; break;
      case 41: lyric = "It doesn't matter if it's broiled or fried"; break;
      case 42: lyric = "Just eat it, eat it"; break;
      case 43: lyric = "Don't you make me repeat it"; break; 
      case 44: lyric = "Wierd Al gives you a big smile and thanks you for listening."; break; }


    tell_room(ENVTP,BOLD+lyric+NORM+"\n");
   return 1; }
