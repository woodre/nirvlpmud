#include <ansi.h>
inherit "obj/treasure";
#define ME capitalize(me->query_name())

object *rabid;

reset(arg){
  move_object(this_object(), "players/pavlik/waste_room");
  rabid = ({ });
  get_all_rabid();
  call_out("crazy", 50 + random(50));
}

id(str){ return str == "rabies-master"; }

short(){ return "The Rabies Master Object"; }
long(){ write("The Rabies Master Object.\n"); return; }
get() { return 1; }
drop() { return 1; }

add_rabid(ob) { rabid += ob; }

get_all_rabid() {
  object *ob;
  int i;

  ob = users();
  for(i=0; i<sizeof(ob); i++) {
	if(present("rabies", ob[i])) {
		rabid += present("rabies", ob[i]);
	}
  }
}

rabies_help(){
  write(
  "You have been infected with rabies!\n"+
  "This disease can be spread by biting other people.\n"+
  "There are several commands avaliable with this disease:\n"+
  "    'rabid' will tell you who else is infected.\n"+
  "    'rchat <msg>' to talk to other rabid players.\n"+
  "    'CURE' will get rid of the rabies.\n"+
  "    'shush' will toggle the rabies emotes on and off.\n"+
  "    'rbite' is the rabies bite command for vampires.\n"+
  "\n");
  return 1;
}

rabies(str){
  string vrb;
  vrb = query_verb();
  if(vrb == "shush") shush();
  if(vrb == "bite")  bite(str);
  if(vrb == "rbite") bite(str);
  if(vrb == "rabid") rabid_who(str);
  if(vrb == "CURE")  cure_rabies();
  if(vrb == "rchat") rabies_tell(str);
  return 1;
}

shush(){
  int sh;
  sh = present("rabies", this_player())->query_shush();
  if(sh == 0){
	write("You shush those annoying rabies emotes.\n");
	present("rabies", this_player())->set_shush(1);
  }
  else {
	write("You will now hear the rabies emotes again.\n");
	present("rabies", this_player())->set_shush(0);
  }
  return 1;
}

crazy() {
  object me, room;
  int i, str;

  for(i=0; i<sizeof(rabid); i++) {
	if(!rabid[i]) {
		rabid -= rabid[i];
		continue;
	}

	me = environment(rabid[i]);
   if(me)
	room = environment(me);

	if(!me || !room) {
		rabid -= rabid[i];
		continue;
	}

	str = call_other(me, "query_attrib", "str");

	/* make sure we are really here */
	if(!(me->query_interactive())) {
		continue;
	}
	/* if we fail the check, attack something */
	if(random(200) < str) {
		go_crazy(me);
		continue;
	}
	/* if shushes then just go to the next object */
	else if(rabid[i]->query_shush()) {
		continue;
	}
	/* give a message back */
	else {
	    switch(random(10)) {
		case 0 :
		   tell_room(room, ME+" begins to foam at the mouth.\n");
		   break;
		case 1 :
		   tell_room(room, ME+" begins to twitch uncontrolably.\n");
		   command("cackle", me);
		   break;
		case 2 :
		   tell_room(room, ME+" stares at you hungrily.\n");
		   break;
		case 3 :
		   tell_room(room, ME+" begins to make strange growling noises.\n");
		   break;
		case 4 :
		   tell_room(room, ME+" starts slobbering uncontrolably.\n");
		   break;
		case 5 :
		   tell_room(room, ME+" starts pulling grass from the ground and eating it.\n");
		   break;
		case 6 :
		   command("moan", me);
		   break;
		case 7 :
		   tell_room(room, ME+" begins howling and pawing at the ground.\n");
		   tell_object(me, "Have your knuckles always been this hairy?\n");
		   break;
		case 8 :
		   tell_room(room, ME+" starts chewing on "+me->query_possessive()+" leg.\n");
		   tell_object(me, "You begin to gnaw on your own leg...not a good sign.\n");
		   break;
		case 9 :
		   tell_room(room, ME+" gets a feverish look in "+me->query_possessive()+" eyes.\n");
		   break;
	   }
	}
  }
  call_out("crazy", 30 + random(80));
  return 1;
}

go_crazy(me) {
  object ob, room;
  string name;

  room = environment(me);
  ob = first_inventory(room);

  tell_object(me, "\n"+
  "You can't take it any longer!  The rabies take control of your mind\n"+
  "and you can no longer resist the urge to attack!\n");
  tell_room(room,
  ME+" goes crazy!  Foaming at the mouth and dripping slobber all over\n"+
  "the room, "+ME+" lashes out in a crazed rage!!!\n");

  while(ob) {
	object cur;
	cur = ob;
	ob = next_inventory(ob);

	if(living(cur)) {
		if(cur == me) continue;
		if(cur->query_npc() == 0) {
			name = cur->query_real_name();
			if(random(3)==1) {
				if(me->query_guild_name() == "vampire") command("rbite "+name, me);
				else command("bite "+name, me);
			}
			if(cur->query_pl_k()==1 && me->query_pl_k()==1) {
				tell_object(cur, ME+" strikes out at you in his madness!\n");
				cur->attack_object(me);
				me->attack_object(cur);
			}
			else { 
				tell_object(cur, ME+" ignores you in his insane outburst.\n"); }
			}
			if(cur->query_npc() == 1) {
				cur->attack_object(me);
				me->attack_object(cur);
			}
	}
	if(!living(ob)){
		name = ob->query_name();
		if(name) {
			if(me->query_guild_name() == "vampire") command("rbite "+name, me);
			else command("bite "+name, me);
		}
	}
  }
  return 1;
}

cure_rabies(){
  write("You get rid of this stupid disease.\n");
  destruct(present("rabies", this_player()));
  return 1;
}

bite(str){
  object me, ob, rab, room;
  int x, st, xx;
  string name;

  if(!str) {
	write("Bite who?\n");
	return 1;
  }

  me = this_player();
  room = environment(me);
  ob = present(str, environment(me));

  if(!ob) {
	write(capitalize(str)+" is not here.\n");
	return 1;
  }
  if(present("rabies", ob)) {
	write(capitalize(str)+" already has rabies!\n");
	return 1;
  }
  if(!living(ob)) {
	write("You grab the "+str+" and gnaw on it hungrily.\n");
	say(ME+" grabs a "+str+" and gnaws on it.\n");
	return 1;
  }
  if(ob == this_player()){ 
	write("You gnaw on your leg.\n");
	say(capitalize(this_player()->query_name())+" gnaws on his leg.\n");
	return 1;
  }

  write("You bite "+capitalize(str)+"!\n");
  write("You grab "+capitalize(str)+"'s wrist and sink your teeth "+ob->query_possessive()+" arm!\n");
  say(ME+" grabs "+capitalize(str)+"'s wrist and sinks "+me->query_possessive()+" teeth into their arm!\n");
  tell_object(ob, ME+" grabs your arm and bits it!  Ouch!\n");

  if(ob->query_npc() == 0) {
	st = call_other(ob, "query_attrib", "str");
	if(random(60) > st) {
		rab = clone_object("players/pavlik/closed/stuff/rabies");
		move_object(rab, ob);
		tell_object(me, "You infect "+capitalize(str)+" with Rabies!\n");
		tell_object(ob, "You have been infected with Rabies!\n");
	}
  }
  return 1;
}

rabid_who(str) {
  object me;
  int i, count;
  string names;
  if(str && str == "help") {
	rabies_help();
	return 1;
  }

  count = 0;
  names = "";
  for(i=0; i<sizeof(rabid); i++) {
	if(!rabid[i]) {
		rabid -= rabid[i];
		continue;
	}
	me = environment(rabid[i]);
	if(!me) {
		rabid -= rabid[i];
		continue;
	}
	if(!me->query_invis()) {
		names += capitalize(me->query_name())+", ";
		count++;
	}
  }
  write("\nThere are "+count+" rabid players on : \n");
  write(names+"\n");
  return 1;
}

rabies_tell(str){
  object me;
  string name;
  int i;

  if(!str){
	write("Rabid what?\n");
	return 1;
  }
  if(present("rabies", this_player())->query_shush()) {
	write("You have to un-shush first.\n");
	return 1;
  }

  name = scrabble(this_player());

  for(i=0; i<sizeof(rabid); i++) {
	if(!rabid[i]) {
		rabid -= rabid[i];
		continue;
	}
	me = environment(rabid[i]);
	if(!me) {
		rabid -= rabid[i];
		continue;
	}
	if(rabid[i]->query_shush()) {
		continue;
	}
	tell_object(me, GRN+"["+YEL+"%^\\"+GRN+"] "+GRN+name+": "+NORM+str+"\n");
  }
  return 1;
}

scrabble(ob) {
  string name, letter;
  string msg, msg2;
  int i;

  name = ob->query_name();
  msg = "";
  msg2 = "";

  for(i=0; i<strlen(name); i++) {
	letter = extract(name, i, i);
	if(random(2)) letter = capitalize(letter);
	msg += letter;
  }

  if(!random(3)) {
	for(i=(strlen(name)-1); i>=0; i--) {
		letter = extract(msg, i, i);
		msg2 += letter;
	}
	msg = msg2;
  }
  return msg;
}

