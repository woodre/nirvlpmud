#include "/obj/clean.c"
#include "/players/feldegast/defines.h"
string name, alias, long_desc;

string type;
int worn, ac;
object worn_by;
object next;
string info;
int set_ac_flag;

reset(arg)
{
    if(arg) return;
    set_light(1);
    name="blur field";
    alias="field";
    type = "blur_field";
    long_desc=
"A blurry haze surrounds your body.  You may <"+BOLD+"nullify"+NORM+"> it if you wish.\n";
    ac=2;
    call_out("remove",70+random(50),"blur field");
}

extra_look() {
  return environment()->query_name()+" appears blurry and indistinct";
}

int call_armor_special(object owner) {
  int bonus;
  if(random((int)owner->query_attrib("wil")) > 17) {
    tell_object(owner,
this_player()->query_name()+" misses you by a wide margin.\n");
    tell_object(this_player(),
"You miss "+owner->query_name()+" by a wide margin.\n");
    bonus+=1;
    owner->add_spell_point(-random(5));
  }
  if(random((int)owner->query_attrib("int")) > 18) {
    tell_object(owner,
this_player()->query_name()+" appears baffled by your blurry image.\n");
    tell_object(this_player(),
HIB+owner->query_name()+" appears blurry and indistinct.\n"+NORM);
    bonus+=1;
    owner->add_spell_point(-random(5));
  }
  if(next)
    bonus+=(int)next->call_armor_special(owner);
  return bonus;
}

link(ob)
{
    next = ob;
}

remove_link(str)
{
    object ob;

    if (str == name) {
	ob = next;
	next = 0;
	return ob;
    }
    if (next)
	next = call_other(next, "remove_link", str);
    return this_object();
}

init() {
  add_action("remove","nullify");
}
rec_short()
{
    if(next)
	return name + ", " + call_other(next, "rec_short");
    return name;
}


long(str) {
    write(long_desc);
}

id(str)
{
    return str == name || str == alias || str == type;
}

test_type(str)
{
    if(str == type)
	return this_object();
    if(next)
	return call_other(next, "test_type", str);
    return 0;
}

tot_ac()
{
    if(next)
	return ac + call_other(next, "tot_ac");
    return ac;
}

query_type() { return type; }

query_worn() { return worn; }

query_name() { return name; }

armor_class() { return ac; }

int wear(object ob)
{

    int tmp;

    next = 0;
    ob = (object)call_other(ob, "wear", this_object());
    if(!ob) {
	worn_by = this_player();
	worn = 1;
	return 1;
    }
    return 1;
}

get() { return 0; }

drop(silently) {
    return 1;
}

remove(str) {
    if (!id(str))
	return 0;
    if (!worn) {
	return 0;
    }
    call_other(worn_by, "stop_wearing",name);
    worn_by = 0;
    worn = 0;
    tell_object(environment(this_object()),"Your blur field slowly fades.\n");
    destruct(this_object());
    return 1;
}

query_weight() { return 0; }

take_off() {
   worn_by = this_player();
   worn_by = 0;
   worn = 0;
    return 1;
}
