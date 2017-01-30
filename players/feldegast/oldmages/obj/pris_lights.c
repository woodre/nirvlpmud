#define ATTACK_STRENGTH 10+random(10)
#include "/obj/clean.c"
#include "/players/feldegast/defines.h"
string name, alias, long_desc;


string *colors;
string *col_name;

string type;
int worn, ac;
object worn_by;
object next;
string info;
int set_ac_flag;

int charges;

void reset(int arg)
{
    if(arg) return;
    set_light(1);
    name="prismatic lights";
    alias="lights";
    type = "light";
    long_desc=
"Prismatic lights gyrate around you within a radius of a few meters.\n\
You can <"+HIY+"blast"+NORM+"> somebody with the light if you wish.\n";
    ac=1;
    set_light(1);
    call_out("remove",200+random(150),"prismatic lights");
    col_name=({ "red","yellow","green","blue","magenta" });
    colors=({ HIR, HIY, HIG, HIB, HIM });
    charges=5;
}

extra_look() {
  return environment(this_object())->query_name()+" is surrounded by "+HIY+"dancing light"+NORM;
}
remove_color(n) {
  col_name-=col_name[n..n];
  colors-=colors[n..n];
}
call_armor_special(owner) {
  int bonus;
  int c;

  if(this_player() &&
     owner!=this_player() &&
     !random(8-charges)
    ) {
    c=random(charges);
    write(colors[c]+"You are blinded by dancing light!\n"+NORM);
    tell_object(owner,colors[c]+TPN+" is blinded by your prismatic lights.\n"+NORM);
    tell_room(environment(owner),colors[c]+TP->query_name()+" is blinded by "+owner->query_name()+"'s dancing light.\n"+NORM,
      ({ TP, owner }));
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
  add_action("remove","de");
  add_action("cmd_attack","blast");
  add_action("no_casting","cast");
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
    tell_object(environment(this_object()),"The lights surrounding you fade and then wink out one by one.\n");
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
int cmd_attack(string str) {
  object targ;
  int c;

  notify_fail("Blast who?\n");
  if(!str) return 0;
  targ=present(str,environment(TP));
  if(!targ) return 0;
  if(!living(targ)) return 0;
  if(TP->query_spell_dam()) return 0;
  c=random(charges);
  tell_object(targ,colors[c]+TPN+" blasts you with a focused beam of "+col_name[c]+" light!\n"+NORM);
  write(colors[c]+"You blast "+targ->query_name()+" with a focused beam of "+col_name[c]+" light!\n"+NORM);
  tell_room(environment(TP),colors[c]+TPN+" blasts "+targ->query_name()+" with "+col_name[c]+" light.\n"+NORM,({ TP, targ }));
  remove_color(c);
  charges--;
  TP->spell_object(targ,"prism",ATTACK_STRENGTH,5,"");
  if(charges <=0) remove("lights");
  return 1;
}
int no_casting(string str) {
  write("You cannot cast any more spells while you are maintaining\n"+
        "the prismatic lights.  If you wish, you may 'nullify' the\n"+
        "lights.\n");
  return 1;
}
