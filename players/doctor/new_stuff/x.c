#define ok return 1
#define call call_other
#define you this_player()
#define act add_action

short() {
       return "the staff of wizardry";
}

long() {
       write("It is an intricately carved staff of oak.\n"+
            "It hums softly with power.\n");
}

id(str) {
       return(str=="staff"||str=="staff of wizardry");
}

get() {
	ok;
}

query_value() {
       return 10000;
}

query_wieght() {
       return 0;
}

init() {
       act("echoall", "$!");
       act("echo", "$");
       act("at_player", "at");
       act("pocket", "pocket");
       act("bring", "bring");
       act("send", "send");
       act("teleport_to", "to");
       act("identify", "id");
       act("heal", "heal");
       act("call_reset", "rset");
       act("meteor_swarm", "meteor");
       act("trash", "trash");
       act("sober", "sober");
       act("get_cash", "cash");
       act("mini_force", "make");
       act("retitle", "retitle");
       act("frog", "frog");
       act("defrog", "defrog");
       act("patch", "patch");
       act("true_inventory", "inv");
       act("raise_dead", "raise");
       act("instructions", "staff");
}

echoall(str){
	if(!str)
		return 0;
	shout(str + "\n");
	return("You echoall: " + str + "\n");
}

echo(str){
	if(!str)
		return 0;
	say(str + "\n");
	return ("You echo: " + "\n");
}

at_player(str){}

pocket(str){
	object ob;
	if(!str)
		return 0;
	ob=find_living(str);
	if(!ob) {
		write("No such person or monster.");
		ok;
	}
	move_object(you, ob);
	write("You climb into " + call(ob, "query_name") + "'s pocket.\n");
	ok;
}

bring(str){
	object ob, old_room;
	string who;
	ob=find_living(str);
	if(!ob) {
		write("No such person or monster found.\n");
		ok;
	}
	who=call(ob, "query_name");
	old_room=environment(ob);
	tell_room(environment(you), who + " materializes.\n");
	move_object(ob, environment(you));
	tell_object(ob, "You suddenly find yourself elsewhere.\n");
	tell_room(old_room, who + " disappears in a flash of red light!\n");
	ok;
}

send(str){
     object ob, ob2, old_room;
     string who, where;
     if(sscanf(str, "%s %s", who, where)!=2) {
          write("Invalid parameters.\n");
          ok; }
     ob=find_living(who);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     who=call(ob, "query_name");
     old_room=environment(ob);
     if(!find_living(where)) {
          tell_room(where, who + " materializes.\n");
          move_object(ob, where);
          tell_room(old_room, who + " disappears in a flash of red light!\n");
          tell_object(ob, "You suddenly find yourself elsewhere.\n");
          ok; }
     ob2=environment(find_living(where));
     tell_room(ob2, who + " materializes.\n");
     move_object(ob, ob2);
     tell_room(old_room, who + " disappears in a flash of red light!\n");
     tell_object(ob, "You suddenly find yourself elsewhere.\n");
     ok;
}

teleport_to(str){
     object ob, ob2, old_room;
     string who, where;
     if(sscanf(str, "%s", where)!=1) {
          write("Invalid destination.\n");
          ok; }
     old_room=environment(ob);
     who=call(you, "query_name");
     if(!find_living(where)) {
          tell_room(where, who + " solidifies out of the ether.\n");
          move_object(you, where);
          tell_room(old_room, who + " fades from view.\n");
          call(you, "look");
          ok; }
     ob2=environment(find_living(where));
     tell_room(ob2, who + " solidifies out of the ether.\n");
     move_object(you, ob2);
     tell_room(old_room, who + " fades from view.\n");
     call(you, "look");
     ok;
}

identify(str){}

heal(str){}

call_reset(){}

meteor_swarm(str){}

trash(str){}

sober(str){}

get_cash(arg){}

mini_force(str){}

retitle(str){}

frog(str){}

defrog(str){}

patch(str){}

true_inventory(str){}

raise_dead(str){}

instructions(str){}
