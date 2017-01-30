/* I have added a check in the tie command to check vs if dropable, if gettable, if no weight and if auto_load...
  alos for the fly to command i have made it so the pigeon can not send to wizes
 - Mythos <2-26-96>
*/
#define MAX_WEIGTH     11 
int local_weight;

long() {
    object tied;
    write("A traveller pigeon. You can do the follow commands:\n"+
    "tie <object> to foot\nuntie <object> from foot\n"+
    "untie all from foot\nfly pigeon to <player>\n");
    if (first_inventory(this_object()))   {
        write("He has something tied to his foot.\n");
	tied=first_inventory(this_object());
	while(tied)   {
		write(call_other(tied,"short")+".\n");
		tied=next_inventory(tied);
		}
	}
    else
        write("You can tie something to his foot.\n");
}

reset(arg) {
    if (arg)
        return;
    local_weight = 0;
}

init() {
    add_action("tie", "tie");
    add_action("untie", "untie");
    add_action("send", "fly");
}

tie(str)   {
string what;
object tied;
if(!str || !(sscanf(str,"%s to foot",what)))   {
	notify_fail("Usage: tie <object> to foot.\n");	
	return 0;
	}
tied=present(what,this_player());
if(!tied)  {
	notify_fail("What do you want to tie?\n");
	return 0;
	}
  if(tied->query_auto_load() || tied->query_weight() == 0 || !(tied->get()) || tied->drop()) { write("You can not tie that.\n"); return 1;}
if ((call_other(tied,"query_weight")+local_weight) > MAX_WEIGTH)  {
	notify_fail("The pigeon can't carry anymore.\n");
        return 0;
	}
local_weight += call_other(tied,"query_weight");
write("You tied a "+what+" to pigeon's foot.\n");
say(this_player()->query_name()+" tied a "+what+" to the foot of his pigeon.\n");
move_object(tied,this_object());
return 1;
}

untie(str)   {
string what;
object untied;
if(!str || !(sscanf(str,"%s from foot",what)))   {
	notify_fail("Usage: untie <object> from foot.\n");
	return 0;
	}
if(what == "all")   {
	untied=first_inventory(this_object());
	while(untied)    {
		write("You untied a "+call_other(untied,"query_name")+" from pigeon's foot.\n");
		say(this_player()->query_name()+" untied a "+call_other(untied,"query_name")+" from pigeon's foot.\n");
		move_object(untied,this_player());
		untied=first_inventory(this_object());
		}
	local_weight=0;
	return 1;
	}
untied=present(what,this_object());
if(!untied)   {
	notify_fail("What do you want to untie?\n");
	return 0;
	}
local_weight -=call_other(untied,"query_weight");
write("You untied a "+what+" from pigeon's foot.\n");
say(this_player()->query_name()+" untied a "+what+" from pigeon's foot.\n");
move_object(untied,this_player());
return 1;
}

send(str)   {
string who;
object flyed;
if(!str || !(sscanf(str,"pigeon to %s",who)))  {
	notify_fail("Usage: fly pigeon to <player>\n");
	return 0;
	}
flyed=find_player(who);
if(!flyed)  {
	notify_fail("No "+who+" on the MUD.\n");
	return 0;
	}

if(flyed->query_invis()) {
   notify_fail("No "+who+" on the MUD.\n"); return 0; }
  if(environment(flyed)->query_lock()) {
   write("You can't fly a pigeon into a locked room.\nGoober.\n");
    return 1;
  }
if(environment(flyed)->realm() == "NT") { write("You cannot fly the pigeon there.\n"); return 1; }
if(environment(this_player())->realm() == "NT") { write("The pigeon can not fly out.\n"); return 1; }
if(flyed->query_level() > 19) { write("Cant fly to a wiz\n"); return 1;}
write("You let fly your little pigeon trying to find "+flyed->query_name()+".\n");
tell_object(flyed,"A little pigeon arrives from "+this_player()->query_name()+".\n");
move_object(this_object(),flyed);
return 1;
}

query_weight() {
    return 1;
}

short() {
    return "A traveller pigeon";
}

id(str) {
    return str == "pigeon";
}

query_value() {
    return 200;
}

get() {
    return 1;
}

prevent_insert() {
    if (local_weight > 0) {
        write("You can't when there are things in the bag.\n");
        return 1;
    }
    return 0;
}
