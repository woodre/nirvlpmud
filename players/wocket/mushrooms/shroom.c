#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure";
int i;

reset(arg){
if (arg) return;
    set_id("shroom");
    set_short("A shroom");
    set_long("\
This is a shroom.  It has little value to anybody else, in fact\n\
you might have to pay them to take it.  On the other hand, shrooms\n\
hold great value to the Nonge.  They provide food, medicine, and trad.\n\
Not to mention may other purposes.  You might want to 'cash' them in.\n");
    set_value(0);
    set_weight(1);
}

init(){
    add_action("eat","eat");
     add_action("cash","cash");
}

set_money(int a){ i = a; }
cash(string str){
if(!str || str != "shroom"){
notify_fail("What would you like to cash in?\n");
return 0;
}
if(!present("hpnonge",environment(this_player())) && !present("lladious",environment(this_player())) ){
  notify_fail("There is noone here who seems to want to buy a shroom.\n");
  return 0;
}
if(present("hpnonge",environment(this_player()))){
  write("Nonge says: That is exactally what I've been looking for. I'll buy it\n"+
        "  from you.\n");
}
else{
  write("Lladious says: That is exactally what I've been looking for.  I'll buy it\n"+
        "  from you.\n");
}
say(this_player()->query_name()+" trades away "+this_player()->query_possessive()+" shroom.\n");
i = i + random(1000);
write("You cash in your shroom for "+i+" coins.\n");
say(this_player()->query_name()+" cashes in a shroom.\n");
this_player()->add_money(i);
destruct(this_object());
return 1;
}

int eat(string str){
if(!str || str != "shroom"){
notify_fail("What would you like to eat?\n");
return 0;
}
write("You begin to take a nibble of the shroom.\nYou spit out the chunk deciding it would be best to 'cash' it in.\n");
say(this_player()->query_name()+" spits out a chunk of shroom.\n");
return 1;
}
