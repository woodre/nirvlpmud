#include "std.h"

object sandra,money,teddy;
int count;

#undef EXTRA_RESET
#define EXTRA_RESET\
        starta_sandra();

ONE_EXIT("players/boltar/lv2/wildwest.c","north",
	 "Bedroom",
 "This is a large beautiful bedroom with a large round bed in the center of\n" +
 "it.  There is a sign that reads: payment in advance on the back of the door.\n", 1)

starta_sandra() {
int wt,ht,prg;
object boobs;
    if(!sandra || !living(sandra)) {
        wt=random(230)+90; ht=random(12); prg=random(100);
	sandra = clone_object("obj/monster");
	call_other(sandra, "set_name", "sandra");
	call_other(sandra, "set_alias", "hooker");
        call_other(sandra,"set_gender","female");
	call_other(sandra, "set_short", "Sandra the seductress");
	call_other(sandra, "set_long",
        "She looks like everything you have ever dreamed of and more.\n"+
        "She looks expensive, but worth every penny. She looks like\n"+
        "someone you wouldn't want to mess with.\n\n"+
        "Sandra is a human, 5 feet "+ht+" inches tall, "+wt+" lbs.\n");
        if(prg<9 && prg > 3)
        call_other(sandra, "set_long",  
        "She looks like everything you have ever dreamed of and more.\n"+
        "She looks expensive, but worth every penny. She looks like\n"+
        "someone you wouldn't want to mess with.\n\n"+
        "Sandra is a human, 5 feet "+ht+" inches tall, "+wt+" lbs.\n"+
        "Sandra looks about "+prg+" months pregnant.\n");
        else prg = 0;
	call_other(sandra, "set_al",125);
        call_other(sandra, "set_heal", 20, 3);
	call_other(sandra, "set_hp",999);
        call_other(sandra, "set_random_pick", 20);
	call_other(sandra, "set_wc",29);
        call_other(sandra, "set_ac", 19);
	call_other(sandra, "set_aggressive", 0);
        call_other(sandra, "set_level", 19);
	move_object(sandra, "players/boltar/lv2/hookerroom");
	money = clone_object("obj/money");
        money->set_money(1000+random(1000));
        move_object(money, sandra);
        boobs=clone_object("players/boltar/sprooms/clinic/boobs");
        boobs->set_boobs("supple 28 AAA");
        boobs->add_cup(random(20));
        boobs->add_bust(wt/20);
        move_object(boobs,sandra);
        teddy = clone_object("players/boltar/things/sarmor.c");
        call_other(teddy, "set_id", "teddy");
        call_other(teddy, "set_name", "A red lace teddy"); 
        call_other(teddy, "set_alias", "teddy");
        call_other(teddy, "set_weight",1);
        call_other(teddy, "set_value",2100);
        call_other(teddy, "set_type", "underwear");
        call_other(teddy, "set_ac", 1+random(3));
        call_other(teddy, "set_short", "A red lace teddy");
   call_other(teddy, "set_long", "A red lace teddy of high quality, it seems to be magic.\n");
        move_object(teddy, sandra);
        call_other(sandra, "init_command", "wear teddy"); 
        call_other(teddy, "set_size", teddy->find_size_npc(5,ht,wt,2000*prg,"female",sandra));
	call_other(sandra, "set_object", this_object());
	call_other(sandra, "set_function", "smiles");
	call_other(sandra, "set_type", "smiles");
	call_other(sandra, "set_match", " happily.");
	call_other(sandra, "set_type", "arrives");
	call_other(sandra, "set_match", "");
	call_other(sandra, "set_function", "say_hello");
	call_other(sandra, "set_type", "arrives");
	call_other(sandra, "set_match", "");
	call_other(sandra, "set_function", "test_say");
	call_other(sandra, "set_type", "says:");
	call_other(sandra, "set_match", " ");
	call_other(sandra, "set_type", "tells you:");
	call_other(sandra, "set_match", " ");
	call_other(sandra, "set_function", "gives");
	call_other(sandra, "set_type", "gives");
	call_other(sandra, "set_match", " ");
	
	call_other(sandra, "set_chat_chance", 10);
	call_other(sandra, "set_a_chat_chance", 33);
	call_other(sandra, "load_chat", "Sandra says: Hi there, big boy.!\n");
	call_other(sandra, "load_chat", "Sandra says: " +
		   "Hello there!\n");
	call_other(sandra, "load_chat", "Sandra says: " +
		   "Are you sure your in the right room?\n");
	call_other(sandra, "load_chat", "Sandra says: " +
		   "Can I do anything for you?\n");
	call_other(sandra, "load_chat", "Sandra says: " +
		   "Hey big boy are you sure you don't want to?\n");
	call_other(sandra, "load_chat", 
		   "Sandra smiles.\n");
	call_other(sandra, "load_a_chat", "Sandra says: " +
		   "Many have tried to rob me, all have FAILED!!\n");
	call_other(sandra, "load_a_chat", "Sandra says: " +
		   "You will die!\n");
	call_other(sandra, "load_a_chat", "Sandra says: " +
		   "Get out now, while you are still alive.\n");
	call_other(sandra, "load_a_chat", "Sandra says: " +
		   "so you want it rough, eh?\n");
	call_other(sandra, "load_a_chat", "Sandra says: " +
		   "It's not nice to try to take a working girl's money, I'll teach    you a lesson or two!\n");
	call_other(sandra, "load_a_chat", "Sandra says: " +
		   "Some tough guy, beating up on a poor, defenseless girl.\n");
call_other(sandra, "set_chance", 70);
call_other(sandra, "set_spell_dam", 65);
call_other(sandra, "set_spell_mess1", "Sandra casts a fireball\n");
call_other(sandra, "set_spell_mess2", "Sandra casts a fireball at you! OUCH!\n");
    }
}

notify(str) {
    say(str);
    write(str);
}
	
smiles(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "sandra" || who == "Sandra")
	return;
    if (sscanf(str, "%s smiles happily", who) == 1 &&
	who != "Sandra") {
	notify("Sandra smiles happily.\n");
    }
}
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
	notify( "Sandra says: Hi " + who + "!  If it's fun you want you have come to the right place.\n");
    }
}
    
test_say(str) {
    string a, b, message;

    sscanf(str, "%s %s", a, b);
    if(a == "sandra" || a == "Sandra")
	return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }
    str = b;

    if (sscanf(str, "%sSandra%s", a, b) == 2)
	message = "Sandra nods enthusiastically.\n";
    if(message)
	notify(message);
}

gives(str) {
    string who, what, whom;
    string amount, cash;
    int rand;
    int spent;
    object obj, next_obj;
    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
	return;
     sscanf(what, "%s %s", amount, cash);
         if (cash == "coins" && whom == "Sandra") {
       sscanf(amount, "%d", spent);
     }
    if(whom != "Sandra")
	return;
    else if(what == "corpse") {
	notify("Sandra says: Hey, do I look like a mortician or something?\n");
	obj = first_inventory(sandra);
	while(!call_other(obj, "id", what))
	    obj = next_inventory(obj);
	transfer(obj, find_living(lower_case(who)));
	notify("Sandra returned the " + what + " to " + who + ".\n");
    } else if (what == "2 coins") {
        notify("Sandra says: 2 coins?  Who do you think I am? That cheap tramp Trixie.\n");
	notify("Sandra pouts.\n");
    } else if (spent > 799 && spent < 1000) {
notify(" Sandra smiles, takes off her clothes, exposing her beautiful features to the" +
"\n" +
"light. Then she removes " + who + "'s clothes and he has the best" +
"\n" +
"time of his life.\n");
	notify("Sandra gives " + who + " one last long kiss.\n");
notify("Sandra says: " + who + " you're the greatest.\n");
call_other(find_living(lower_case(who)), "heal_self", spent/60);
call_other(sandra, "heal_self", 2000);
   } else if (spent > 999) {
notify(" Sandra smiles, takes off her clothes slowly, exposing one small part of " +
"\n" +
"her body at a time. Then she rips off " + who + "'s clothes and they" +
"\n" +
"both have a great time.\n");
if(find_living(lower_case(who))->query_gender()=="female") {
notify("Sandra wears a rather odd looking object and climbs on top of "+who+"\n");
if(!find_player(lower_case(who))->query_pregnancy())
if(random(100) < 15) find_living(lower_case(who))->set_pregnancy("Sandra");
}
notify("Sandra gives " + who + " one last real long kiss.\n");
notify("Sandra says: " + who + " you're the best yet.\n");
call_other(find_living(lower_case(who)), "heal_self", spent/55);
call_other(sandra, "add_money" -spent*50/100);
call_other(sandra, "heal_self", 920);
    } else {
notify("Sandra says: it will cost you at least 800 coins, paid in advance.\n");
	/* De-frog the person if necessary */
	if (call_other(find_living(lower_case(who)), "query_frog"))
		call_other(find_living(lower_case(who)), "frog_curse", 0);
    }
}
