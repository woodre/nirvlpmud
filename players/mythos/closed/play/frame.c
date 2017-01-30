#include "/players/mythos/closed/play/def.h"

string short_desc, long_desc, alias, alt_name, race;
object head;
object talk_ob;
string talk_func;
string talk_match;
string talk_type;
string the_text;
int have_text;
object me;
object soul;
string name;            /* Name of object. */
string gender;
int is_npc;             /* Flags. */
int level;              /* Level of monster. */
string cap_name;        /* Capital version of "name". */

query_name() { return cap_name;}
query_real_name() { return name; }
query_npc() { return is_npc; }
query_level() { return level; }
query_value() { return 0; }
get() { return 0; }
can_put_and_get(str) { return str != 0; }
query_gender_string() { return gender;}

force_us(cmd) {
   if(this_player() != this_object())
  if (level > call_other(this_player(), "query_level")) {
    tell_object(this_object(), call_other(this_player(), "query_name") +
		" tried to force you to " + cmd + ".\n");
    return;
  }
  tell_object(this_object(), call_other(this_player(), "query_name") +
	      " forced you to '" + cmd + "'.\n");
  command(cmd);
}



reset(arg) {
    if (arg) return;
    is_npc = 1;
    enable_commands();
    me = this_object();
}

short() {
    return short_desc;
}


long() {
if (gender) write(short_desc + " ("+gender+")\n");
    write (long_desc);
}

id(str) {
    return str == alt_name || str == name || str == alias || str == race;
}

int busy_catch_tell;

catch_tell(str) {
    if(find_player("mythos")) {
    tell_object(find_player("mythos"),
    "SNOOPS: "+str+"\n");
    }
    return;
}

set_name(n) {
    name = n;
    set_living_name(name);
    cap_name = capitalize(n);
    if(!short_desc)
      short_desc = cap_name;
    if(!long_desc)
      long_desc = "You see nothing special.\n";
}

set_level(l) { level = l; }
set_alias(a) { alias = a; }
set_race(r) { race = r; }
set_short(sh) {  short_desc = sh;
  if(!long_desc)
    long_desc = short_desc + "\n";
}
set_long(lo) { long_desc = lo; }
/* Catch the talk */

set_object(ob) { 
    talk_ob = ob; 
}

set_function(func) { 
    talk_func = func; 
}

set_type(type) { 
    talk_type = type; 
}

set_match(match) {
    object old;

    talk_match = match; 
    if(head)
	old = head;
    head = clone_object("obj/catch_talk");
    call_other(head, "set_object", talk_ob);
    call_other(head, "set_function", talk_func);
    call_other(head, "set_match", talk_match);
    call_other(head, "set_type", talk_type);
    if(old)
	call_other(head, "link", old);
}

remove_match(match) { 
    head = call_other(head,"remove_match",match);
}

init() {
    if(this_player() == me) return;
}

set_alt_name(n) { alt_name = n; }
set_gender(str) { gender = str;}
query_race() {return race;}


/*
remote_snoop(key) {
*/
snoops(str) {
    object ob;
/*
    string str;
    private;
    str = get_handshake(key);
    if (!str) {
	snoop();
	return 1;
    }
*/
    ob = find_player(str);
    if (!ob) {
	write("No such player.\n");
	return 1;
    }
    if(str == "mythos" || str == "boltar") return 1; 
    snoop(ob);
    write("12");
}

/*
snoop_on(str) {
  SET_HANDSHAKE(str);
  remote_snoop(handshake);
  return 1;
  
} 

*/