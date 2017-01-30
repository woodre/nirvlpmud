/* Fixed like 8 typos.  [11-30-01] Verte */
#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";
object hero;
int quest;

reset(arg){
  ::reset(arg);
  if(arg) return;
set_name("Felic");
set_alias("knight");
set_alt_name("felic");
set_short("An old knight");
set_long("A withered old man.  He is very crippled and has a couple\n"+
         "fingers missing from his left hand.  His clothes are tattered\n"+
         "though they seem like at one time they were very distinguished.\n"+
         "A small crest adorns his shirt.  A couple of scars mark his face\n"+
         "covered only by his long white beard.  He looks like he has a\n"+
         "of interesting stories to tell if you only asked him.\n");
set_chat_chance(10);
load_chat("Felic smiles.\n");
load_chat("Felic says: How are ya young fellow?\n");
load_chat("Felic hugs you.\n");
load_chat("Felic says: I have lots of old stories to tell.\n");
add_money(random(200));
set_level(13);
set_hp(195);
set_wc(17);
set_ac(10);
set_race("human");
}

init(){
  ::init();
add_action("ask","ask");
}

ask(str){
string first,last;
  if(!str){
     notify_fail("Who would you like to ask?\n");
    return 0;
  }
  if(sscanf(str,"%s %s",first,last) != 2){ first = str; }
  if(first != "felic" && first != "knight" && first != "him"){
    notify_fail("Who would you like to ask what?\n");
    return 0;
  }
  if(str != "felic about the sinja worm" && str != "knight about the sinja worm" && str != "him about the sinja worm"){
    notify_fail("Felic says: What do you want to know about?\n");
    return 0;
  }
write("Felic says: So you want to know about the Sinja worm, eh.  Vicious \n"+
      "creature, I tell ya.  I fought it once, and it nearly took my hand\n"+
      "off.  Luckily I survived the ordeal and lived to tell about it.  My\n"+
      "adventuring days are over, however.  Last I knew the worm was trapped\n"+
      "deep within the underground caverns.  I did learn something kinda\n"+
      "interesting though, it seems the blood of the pojoui is very deadly\n"+
      "to the worm.  Long ago the Nonge would 'cover' their weapons with it,\n"+
      "sometimes applying several coats to a weapon to make it as poisonous as\n"+
      "possible.  I sure wish I knew that back when I could still fight.\n");
if(quest == 1){
write("I did have this longsword I would have given you, but some other young\n"+
      "hero stopped by first and I gave it to them.\n");
return 1;
}
else{ 
write("Oh, I guess I have this sword I no longer use that I could give to you.\n"+
      "Perhaps it will do you more good than it did me.\n");
quest = 1;
hero = this_player();
call_out("giveme",4);
return 1;
}
}

giveme(){
  tell_object(hero,"Felic gives you a rusted longsword.\n");
say("Felic gives "+hero->query_name()+" a rusted longsword.\n",hero);
move_object(clone_object("/players/wocket/turtleville/OBJ/questsword.c"),hero);
return 1;
}
