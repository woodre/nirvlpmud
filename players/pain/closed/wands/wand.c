#include "/obj/clean.c"

status readied;
object readied_by;
string name_of_wand;
string cap_name;
string alt_name;
string alias_name;
string short_desc;
string long_desc;
string read_msg;
int save_flag,class_of_wand;
int value;
int local_weight;
object ready_func;
string info;

query_name() { return name_of_wand; }

long() {
       write(long_desc);

}

reset(arg) {
    if (arg)
     return;
    readied = 0; value = 0;
}

init() {
    if (read_msg) {
	add_action("read"); add_verb("read");
    }
    add_action("ready"); add_verb("ready");
    add_action("stopready"); add_verb("unready");
}

ready(str) {
    if (!id(str))
	return 0;
    if (environment() != this_player()) {
	/* write("You must get it first!\n"); */
	return 0;
    }
    if (readied) {
	write("The wand is readied for casting!\n");
	return 1;
    }
    if(ready_func)
	if(!call_other(ready_func,"ready",this_object()))
	    return 1;
    readied_by = this_player();
    call_other(this_player(), "ready", this_object());
    readied = 1;
    return 1;
}


short() {
   string tmp_short;
    if (call_other(this_player(), "query_level", 0) > 30) {
    if (readied)
	 return tmp_short + " (readied)";
	 return tmp_short;
     }
    if (readied)
	if(short_desc)
	    return short_desc + " (readied)";
    return short_desc;
}


id(str) {
   return str == name_of_wand || str == alt_name || str == alias_name || str == "wand" ;
}

drop(silently) {
    if (readied) {
	call_other(readied_by, "stop_readying");
	readied = 0;
	if (!silently)
	    write("You drop your readied wand.\n");
    }
    return 0;
}

un_ready() {
    if (readied)
	readied = 0;
readied_by = 0;
}

set_id(n) {
    name_of_wand = n;
    cap_name = capitalize(n);
    short_desc = cap_name;
    long_desc = "You see nothing special.\n";
}

set_name(n) {
    name_of_wand = n;
    cap_name = capitalize(n);
    short_desc = cap_name;
    long_desc = "You see nothing special.\n";
}

read(str) {
    if (!id(str))
	return 0;
    write(read_msg);
    return 1;
}

query_value() {
    return value;
}

get() { return 1; }

query_weight() { return local_weight; }



set_weight(w) { local_weight = w; }

set_value(v) { value = v; }

set_alt_name(n) { alt_name = n; }

set_ready_func(ob) { ready_func = ob; }

set_alias(n) { alias_name = n; }

set_short(sh) { short_desc = sh; long_desc = short_desc + "\n";}

set_long(long) { long_desc = long; }

set_read(str) { read_msg = str; }

set_info(i) {
    info = i;
}

query_info() {
    return info;
}
stopready() {
   call_other(this_player(), "stop_readying");
readied = 0;
readied_by = 0;
return 1;
}
save_thing(str){
     save_object(str);
     return 1;
  }
restore_thing(str){
      restore_object(str);
      return 1;
   }
set_save_flag() {
save_flag = 1;
 }
query_save_flag() {
return save_flag;
 }

