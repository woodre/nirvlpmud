#include "/players/wocket/closed/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()

string uncrime_player;
int charges;
reset(arg){
uncrime_player = 0;
    if(arg) return;
charges = 3;
}

init(){
    add_action("intake","eat");
    add_action("juggle","juggle");
}



id(str){
    return str == "orange" || str == "fruit" || str == "an orange" || str == "oranges" || str == "rotten orange";
}
short(){
  return YEL+"An orange"+NORM+" (rotten) *"+HIB+charges+NORM+"*";
}
long(){
    write("This is a rotten orange.  You may wish to 'eat' it to gain some healing.  Or\nyou might, if you have enought, want to 'juggle' it.\n");
}

intake(str){

if(!charges) return;

if(!str || !id(str)){
    notify_fail("What would you like to eat?\n");
    return 0;
}

if(environment() != this_player()){
  notify_fail("You must have the orange in order to eat it.\n");
  return 0;
}
if(TP->query_stuff()+8 > TP->query_max_stuff()){
    notify_fail("You are so stuffed you couldnt eat another bite.\n");
    return 0;
}
if(TP->query_soaked()+8 > TP->query_max_soak()){
    notify_fail("You are much to soaked to eat another bite.\n");
    return 0;
}
call_other(TP,"eat_food",8);
call_other(TP,"drink_soft",8);


charges--;
TP->heal_self(random(20)-10);

write("You take a large bite from the orange.\nJuices flow down your cheek.\n");
write(HIR+"EWwww.. It's rotten.\n"+OFF);
write("You may bite the orange "+charges+" more times.\n");
say(TPN+" takes a bite from an orange.\n");
write(HIB+"<qm> "+NORM+"hp: "+TP->query_hp()+" sp: "+TP->query_spell_point());
write(HIB+"\tI: "+NORM+((TP->query_intoxination()*100)/(TP->query_max_intox()) ) );
write(HIB+"  F: "+NORM+((TP->query_stuffed()*100)/(TP->query_max_stuff()) ) );
write(HIB+"  S: "+NORM+((TP->query_soaked()*100)/(TP->query_max_soak()) ) );
write("\n");
if(charges == 0){
    write("You have devoured the entire orange.\n");
    TP->recalc_carry();
    destruct(this_object());
}
	return 1;
}

juggle(str){
int i;
    if(!str || !id(str)){
    notify_fail("What would you like to juggle?\n");
return 0;
}
if(!present("orange 3",this_player())){
    notify_fail("You do not have enought oranges to juggle.\n");
return 0;
}
if(present("hoopak",this_player()) || present("medallion",this_player())){
    write("You begin to juggle the oranges.\n");
    say(TPN+" begins to juggle the oranges.\n");
i=random(4);
switch(i){
case 0:
    write("With one quick move you twirl around.\n");
    say("With one quick move, "+TPN+" twirls around.\n");
break;
case 1:
    write("An orange flys up from behind your back.\n");
    say("An orange flys up from behind "+TPN+"'s back.\n");
break;
case 2:
    write("You take a quick nibble from the orange as it passes by your mouth.\n");
    say(TPN+" takes a quick nibble from an orange as the others are in the air.\n");
break;
case 3:
    write("You lean back and close your eyes.\n");
    say(TPN+" leans back and closes "+TP->query_possessive()+" eyes.\nThe oranges sail through the air flawlessly.\n");
break;
}
    write("You catch all of the oranges.\nYou bow.\n");
    say(TPN+" catches all of the oranges and takes a bow.\n");
return 1;
}
write("You begin to try to juggle, but fumble as oranges collide in midair.\n");
    write("You have made a fool of yourself.\n");
   say(TPN+" tries to juggle, but as he tosses the oranges in he air they collide.\n"+TPN+" blushes.\n");
return 1;
}

query_value(){ return 10*charges; }
query_weight(){
   if(charges == 0) return 0;
   if(charges < 3) return 1;
    else return charges/3;
}

query_save_flag(){ return 1; }


get(){ return 1; }
