#include "/players/wocket/closed/ansi.h"
#define BRIBE 10000
inherit "obj/monster.c";
object hero;

reset(arg){
  ::reset(arg);
  if(arg) return;

set_name("kesner");
set_alt_name("mayor");
set_short(HIY+"Mayor Kesner"+NORM+" of Turtleville");
set_long("The mayor stands about five and half foot tall with a chubby little\n"+
    "belly.  He is dressed formally with many ribbons and sashes, tassles and\n"+
    "pins.  He has a soft mustache which comes to a twirl at the end.  He appears\n"+
    "to be friendly.\n");
set_level(14);
set_hp(210);
set_wc(18);
set_ac(11);
add_money(700+random(150));
set_chat_chance(10);
load_chat("Kesner smiles.\n");
load_chat("Kesner hugs you.\n");
load_chat("Kesner says: Hello stranger.\n");
load_chat("Kesner shakes your hand.\n");
load_chat("Kesner says: I'm so broke.\n");
load_chat("Kesner whispers to you: If you bribe me, I will clear you of your crimes.\n");
load_chat("Kesner whispers to you: If you bribe me, I will clear you of your crimes.\n");
load_chat("Kesner whispers to you: If you bribe me, I will clear you of your crimes.\n");

}

init(){
  ::init();
  add_action("give","give");
  add_action("ask","ask");
  add_action("bribe","bribe");
}

bribe(str){
  if((str != "mayor" && str != "kesner")){
    notify_fail("Who would you like to bribe?\n");
    return 0;
  }
  if(this_player()->query_money() < BRIBE){
    notify_fail("Kesner says: You expect me to be bribed with so little cash? pah!\n");
    return 0;
  }
  say(this_player()->query_name()+" whispers something to Kesner.\nKesner whispers something back.\n",this_player());
  write("Kesner quickly takes your money, slips it inside a pocket, and writes you out a pardon\n");
  write(BOLD+"Your crime has been cleared.\n"+OFF);
  this_player()->add_money(-BRIBE);
  this_player()->clear_crime();
  this_player()->save_me();
  return 1;
}

ask(str){
string first,last;
  if(!str){
    notify_fail("What would you like to ask?\n");
    return 0;
  }
  if(sscanf(str,"%s %s",first,last) != 2){ first = str; }
  if(first != "mayor" && first != "kesner"){
    notify_fail("Who would you like to ask?\n");
    return 0;
  }
  write("Kesner says: Oh, I'm so glad your here.  Turtleville is in trouble and\n"+
        "needs your help desperatly.  Long ago there was a giant worm that terrorized\n"+
        "this wonderful city but a brave knight trapped the worm in a cave.  It seems\n"+
        "the Sinja worm has escaped because I've been getting reports of sightings.\n"+
        "Lucky for us the worm hasn't attacked yet, but I can't afford to take any\n"+
        "chances.  I want for you to 'cut' into the 'corpse' and bring me the heart of\n"+
        "this Sinja worm so that I can know for sure this town is rid of the monster.\n"+
        "You will be well rewarded for your valiant efforts.  You might want to search\n"+
        "out Felic, the old knight.  It's rumored he is living in the marsh so you might\n"+
        "want to start your search there.  Make sure you 'ask him about the sinja worm'.\n"+
        "I sure hope you can help us.\n");
  return 1;
}

give(str){
object heart;
  if(str == "heart to mayor" || str == "heart to kesner"){  
    heart = present("sinja_heart",this_player());
    if(!heart){
      notify_fail("You do not have the Sinja's heart to give Kesner.\n");
      return 0;
    }  
write("You give heart to Kesner.\n");
destruct(heart);
write("Kesner says: Oh, So you have brought me the heart as I asked of you.\n"+
          "Very good...very good indead.  Thank you young warrior.\n"+
          "Kesner says: Oh oh yes.  The reward i promised you.  Well here it is.\n"); 
hero = this_player();
    write("\n       - "+BOLD+"YOU SOLVED THE QUEST"+NORM+" -\n");
    write_file("/players/wocket/closed/log/SINJA_QUEST",hero->query_name()+" "+hero->query_level()+" "+ctime()+"\n");
    this_player()->set_quest("sinja_quest");
call_out("moneygive",4);
return 1;
}
return 0;
}

moneygive(){
  say("Kesner gives 10000 coins to "+hero->query_name()+".\n");
  hero->add_money(10000);
}
