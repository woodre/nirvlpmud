#include "/obj/clean.c"
/*
  * This is a modified 'treasure.c' from standard /obj.
  * It has been modified for the Bardic shaping ability.
 */

string short_desc, long_desc, info;
int save_flag, value, local_weight;
string name, alias_name, alt_name, read_msg;
string extra_look;
int line_flag;

reset()
{
	line_flag = 0;
}

id(str)
{
	return str == name || str == alias_name || str == alt_name;
}

short()
{
	return short_desc;
}

long()
{
	write(long_desc);
}

query_value()
{
	return value;
}

set_name(str)
{
	local_weight = 1;
	name = str;
}

set_alias(str)
{
	alias_name = str;
}

set_alt_name(str)
{
	alt_name = str;
}

set_short(str)
{
	short_desc = str;
	long_desc = "You see nothing special.\n";
}

set_long(str)
{
	long_desc = str;
}

set_value(v)
{
	value = v;
}

set_weight(w)
{
	local_weight = w;
}

set_read(str)
{
	read_msg = str;
}

get()
{
	return 1;
}

query_weight()
{
	return local_weight;
}

init()
{
	if (!read_msg)
		return;
	add_action("read");
	add_verb("read");
}

read(str)
{
	if (str != name && str != alias_name)
		return 0;
	write(read_msg);
	return 1;
}

set_info(str)
{
	info = str;
}

query_info()
{
	return info;
}

save_thing(str)
{
	save_object(str);
	return 1;
}

restore_thing(str)
{
	restore_object(str);
	return 1;
}

set_save_flag()
{
	save_flag = 1;
}

query_save_flag()
{
	return save_flag;
}

set_extra_look(str)
{
	extra_look = str;
	line_flag = 1;
}

extra_look()
{
	object ob7;

	ob7 = environment(this_player())->query_name();
	if (line_flag) {
		write(ob7 + " " + extra_look + ".\n");
	}
}

query_extra_look()
{
	return extra_look;
}

set_light(str)
{
	return str;
}

query_name()
{
	return name;
}

query_short()
{
	return short_desc;
}

query_alt_name()
{
	return alt_name;
}

query_bardic_mark()
{
	return 1;
}
