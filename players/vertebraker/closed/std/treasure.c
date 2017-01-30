/* mwahaha . verte[2001] */

inherit "/obj/treasure";

string *aliases;

void
add_id(string str)
{
    if(!aliases) aliases = ({ });
    aliases += ({ str });
}

status
id(string str)
{

    if(::id(str)) return 1;
    if(!aliases)
      return 0;
    if(member_array(str, aliases) != -1)
      return 1;
}

string
query_name() { return name; }

void
set_name(string aoo) { aoo = name; }

