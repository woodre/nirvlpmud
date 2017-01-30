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
    name="flame circle";
    alias="circle";
    type = "flameshield";
    long_desc=
"A wreath of twisting flames surrounds your body at about waist level.\n";
    ac=3;        
    call_out("remove",150+random(50),"circle");
}

extra_look() {
  return environment(this_object())->query_name()+" is surrounded by a "+RED+"CIRCLE OF FLAMES"+NORM;
}

call_armor_special(owner) {
  int bonus;

  if(this_player() &&
     owner!=this_player() &&
     random(owner->query_attrib("wil")) > 18 &&
     owner->query_sp() > 5
    ) {
    tell_object(owner,"Your "+RED+"circle of flames"+NORM+" lashes "+this_player()->query_name()+" with a tongue of fire.\n");
    write("A tongue of flame lashes out at you!\n");
    this_player()->hit_player(random(10));
    owner->add_spell_point(-random(5));
    bonus+=1;
  }
  if(random(owner->query_attrib("int")) > 18) {
    tell_object(owner,"The "+RED+"flames"+NORM+" flare up briefly.\n");
    tell_room(environment(owner),owner->query_name()+"'s "+RED+"circle of flames"+NORM+" FLARES up, blinding you with its light!\n");
    bonus+=2;
  }
  if(next)
    bonus+=next->call_armor_special(owner);
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

int wear(object me)
{
    object ob;
    int tmp;

    next = 0;
    ob=(object)call_other(me, "wear", this_object());

    if(!ob) {
	worn_by = me;
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
    tell_object(environment(this_object()),
"The "+RED+"circle of flames"+NORM+" surrounding you flares brightly and then disappears.\n");
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
