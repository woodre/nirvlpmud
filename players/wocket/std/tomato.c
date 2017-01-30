/* tomato heals - 4 charges 7soak 7stuff 35 healing per charge */

#include "/players/wocket/closed/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
int rotten;
int is_rotten;
int charges;
string uncrime_player;
reset(arg){
  if(arg){ 
    rotten++;
    if(rotten == 2){ 
      is_rotten = 1; 
      write_file("/players/wocket/closed/log/ROTTEN","rotten -"+ctime(time())+" - tomato\n");
    }
    return; 
  }
  charges = 4;
}

init(){
    add_action("intake","eat");
    add_action("juggle","juggle");
    add_action("bury","bury");
    add_action("throw","throw");
}



id(str){
  if(is_rotten && str == "rotten tomato") return 1;
    return str == "jugglefruit" || str == "tomato" || str == "veggie" || str == "a tomato" || str == "tomato";
}
short(){
string str;
 str = HIR+"A tomato "+NORM;
 if(is_rotten) str += "(rotten) ";
 str += "*"+HIY+charges+NORM+"*";
 return str;
}

long(){
    write("This is a");
    if(is_rotten) write(" rotten ");
    else write(" fresh ");
    write("tomato.  You may wish to 'eat' it to gain some healing. Or\n"+
          "you might, if you have enough, want to 'juggle' it.  If the\n"+
          "tomato has turned rotten, however, you may wish to 'bury' it.\n"+
          "Just remember 'throw'ing it at someone is always more fun.\n");
}


intake(str){

if(!charges) return;
/* Added by Snow 7/99 */
  if(environment() != this_player()){
    notify_fail("You must have the tomato in order to eat it.\n");
  return 0;
  }

if(!str || !id(str)){
    notify_fail("What would you like to eat?\n");
    return 0; 
}

if(TP->query_stuff()+7 > TP->query_max_stuff()){
    notify_fail("You are so stuffed you couldnt eat another bite.\n");
    return 0;
}
if(TP->query_soaked()+7 > TP->query_max_soak()){
    notify_fail("You are much to soaked to eat another bite.\n");
    return 0;
}
call_other(TP,"eat_food",7);
call_other(TP,"drink_soft",7);


charges--;
if(is_rotten) TP->heal_self(random(10)-10);
else
 TP->heal_self(35);

write("You take a large bite from the tomato.\nJuices flow down your cheek.\n");
if(is_rotten) write(HIR+"EWwww.. It's rotten.\n"+OFF);
write("You may bite the tomato "+charges+" more times.\n");
say(TPN+" takes a bite from a tomato.\n");
write(HIB+"<qm> "+NORM+"hp: "+TP->query_hp()+" sp: "+TP->query_spell_point());
write(HIB+"\tI: "+NORM+((TP->query_intoxination()*100)/(TP->query_max_intox()) ) );
write(HIB+"  F: "+NORM+((TP->query_stuffed()*100)/(TP->query_max_stuff()) ) );
write(HIB+"  S: "+NORM+((TP->query_soaked()*100)/(TP->query_max_soak()) ) );
write("\n");
if(charges < 1){
    write("You have devoured the entire tomato.\n");
    TP->recalc_carry();
    destruct(this_object());
}
        return 1;
}

bury(str){
  if(!str){
    notify_fail("What would you like to bury?\n");
    return 0; 
  }
  if(!id(str)){
    notify_fail("That is not something you can bury.\n");
    return 0;
  }
  write("You bury your tomato underneath the dirt.\n");
  say(this_player()->query_name()+" buries a tomato.\n");
  destruct(this_object());
  TP->recalc_carry();
  return 1;
}
 
juggle(str){
int i;
    if(!str || !id(str)){
    notify_fail("What would you like to juggle?\n");
return 0;
}
if(!present("jugglefruit 3",this_player())){
    write("You do not have enough fruit to juggle.\n");
    return 1;
}
if(present("hoopak",this_player()) || present("medallion",this_player())){
    write("You begin to juggle the fruit.\n");
    say(TPN+" begins to juggle the fruit.\n");
i=random(4);
switch(i){
case 0:
    write("With one quick move you twirl around.\n");
    say("With one quick move, "+TPN+" twirls around.\n");
break;
case 1:
    write("A tomato flys up from behind your back.\n");
    say("A tomato flys up from behind "+TPN+"'s back.\n");
break;
case 2:
    write("You take a quick nibble from the tomato as it passes by your mouth.\n");
    say(TPN+" takes a quick nibble from a tomato as the others are in the air.\n");
break;
case 3:
    write("You lean back and close your eyes.\n");
    say(TPN+" leans back and closes "+TP->query_possessive()+" eyes.\nThe tomato sail through the air flawlessly.\n");
break;
}
    write("You catch all of the fruit.\nYou bow.\n");
    say(TPN+" catches all of the fruit and takes a bow.\n");
return 1;
}
write("You begin to try to juggle, but fumble as fruit collide in midair.\n");
    write("You have made a fool of yourself.\n");
   say(TPN+" tries to juggle, but as he tosses the fruit in he air they collide.\n"+TPN+" blushes.\n");
return 1;
}

throw(str){
object sucker,airtomato;
string what,who;
  if(environment(this_object()) != this_player()) return 0;
  if(!str){
    notify_fail("What would you like to throw?\n");
    return 0;
  }
  sscanf(str,"%s at %s",what,who);
  if(!who) what = str;
  if(!id(what)){
      notify_fail("You do not have that to throw.\n");
      return 0;
  }
  if(!who){
    write("Who would you like to throw the tomato at?\n");
    return 1;
  }
  sucker = find_player(who);
  if(!sucker){ 
    write("You can not find "+capitalize(who)+" to throw at with a tomato.\n");
    return 1;
  }
  if(sucker->query_invis()){
    write("You can not find "+capitalize(who)+" to throw at with a tomato.\n");
    return 1;
  }
  if(sucker->query_level() > 19 && this_player()->query_real_name() != "wocket"){
    write("You should not throw things at wizards.\n");
    return 1;
  }
  write("You throw your "+HIR+"tomato"+OFF+" high into the air at "+sucker->query_name()+".\n");
  say(TPN+" throws a "+HIR+"tomato"+OFF+" high into the air at "+sucker->query_name()+".\n");
  airtomato = clone_object("/players/wocket/std/tomatoair.c");
  airtomato->set_sender(this_player());
  airtomato->set_receiver(sucker);
  move_object(airtomato,sucker);
  airtomato->warnplayer();
  destruct(this_object());
  TP->recalc_carry();
  return 1;
}

query_value(){ if(is_rotten) return 8*charges; return 261* charges; }
/* 35*8 == 280  261 is used because of reduction of cost from rotten ones - wocket */
query_weight(){
   if(charges == 0) return 0;
   if(charges < 3) return 1;
    else return charges/3;
}

set_rotten(i){ is_rotten = i; }

query_rotten(){ return is_rotten;}

query_save_flag(){ return 1; }

get(){ return 1; }

