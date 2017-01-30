#include "/players/feldegast/defines.h"

inherit "obj/weapon";


int fails;
int parrying;

int worn;
object worn_by;
object next;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_type("sword");
  set_class(18);
  set_name("samiel");
  set_alias("broadsword");
  set_short(RED+"Samiel"+NORM+", the "+YEL+"Desert Wind"+NORM);
  set_long(
"  This is Samiel, also known as the Desert Wind, a might two-handed\n\
broadsword that is said to possess the power of the great sandstorms\n\
that move the desert itself.  The air around the sword's silvery blade\n\
shimmers from its heat.\n"
  );
  set_weight(5);
  set_value(8000);
  set_hit_func(this_object());
}

void attack_me()
{
  object curr;
  curr=first_inventory(environment(TP));
  while(curr)
  {
    if(curr!=this_player() && curr->is_npc())
      curr->attacked_by(this_player());
    curr=next_inventory(curr);
  }
}

int weapon_hit(object attacker)
{
  int bonus;

  fails-=2;
  if(fails < 0) fails=0;

  if(parrying)
  {
    parrying=0;
    return 0;
  }

  if(!random(8))
    tell_object(attacker,"A swirling cloud of sand enfulfs you.\n");
  if(!random(10))
    tell_room(environment(this_player()),TPN+" unleashes a swirling storm of sand!\n");

  if(random((int)this_player()->query_attrib("wil")) > 18)
  {
    tell_room(environment(this_player()), HIY+TPN+" summons a sandstorm to scour "+TPG2+" foes!\n"+NORM);
    bonus+=2;
  }
  if(random((int)this_player()->query_attrib("pie")) > 18)
  {
    tell_object(attacker, HIR+"Your eyes sting as you are blinded by wind and sand!\n"+NORM);
    tell_room(environment(attacker),
      (string)attacker->query_name()+" stumbles about, blinded by wind and sand!\n",
      ({ attacker }));
    bonus+=2;
  }
  if(random((int)this_player()->query_attrib("luc")) > 18)
  {
    tell_room(environment(attacker),
      YEL+(string)attacker->query_name()+" falls to "+(string)attacker->query_possessive()+" knees as "+
      (string)attacker->query_pronoun()+" is buffeted by wind and sand.\n"+NORM); 
    bonus+=2;
  }
  if(random((int)this_player()->query_attrib("int")) > 18)
  {
    tell_room(environment(attacker),
      RED+(string)attacker->query_name()+" screams in pain as the desert sands scour flesh from bone!\n"+NORM);
    bonus+=2;
  }

  if(random((int)this_player()->query_attrib("wil")) < 3)
  {
    write(BOLD+"You struggle to control the sword.\n"+NORM);
    this_player()->add_spell_point(-random(6));
    fails++;
  }
  if(random((int)this_player()->query_attrib("wil")) < 3)
  {
    write(BOLD+"Your heart beats loudly as you sense the sword's malignant spirit\n"+
          "begin to stir within the blade.\n"+NORM);
    this_player()->add_hit_point(-random(6));
    fails++;
  }
  if(fails >= 6)
  {
    write(
RED+"You fall to the ground in agony as the sword takes hold of your body\n\
and sends needles of pain rushing through your flesh.  Sand fills your\n\
nostrils and blinds your eyes as your own weapon wreaks an unholy revenge\n\
upon you.\n"+NORM);
    say(HIR+TPN+" falls to the ground in agony.\n"+NORM);
    TP->add_hit_point(50+random(20));
    return -10;
  }
  attack_me();
  return bonus;
}

call_armor_special(owner) {
  int bonus;
  if(owner->query_attrib("ste") > random(60)) {
    tell_object(owner,"You parry.\n");
    tell_room(environment(owner),owner->query_name()+" parries.\n",({ owner }));
    parrying=1;
    bonus+=2;
  }
  if(next)
    bonus+=next->call_armor_special(owner);
  return bonus;
}

int weapon_breaks()
{
  object curr;
  ::weapon_breaks();
  tell_room(environment(environment(this_object())),
    "The spirit within "+query_name()+" breaks free, unleashing a torren\n"+
    "wind and chaos!\n");
  curr=first_inventory(environment(this_player()));
  while(curr)
  {
    tell_object(curr,"You are blasted by the wind!\n");
    curr->hit_player(random(60));
    curr=next_inventory(curr);
  }
  return 1;
}
  
link(ob)
{
    next = ob;
}

remove_link(str)
{
    object ob;

    if (str == query_name()) {
	ob = next;
	next = 0;
	return ob;
    }
    if (next)
	next = call_other(next, "remove_link", str);
    return this_object();
}

rec_short()
{
    if(next)
	return query_name() + ", " + call_other(next, "rec_short");
    return query_name();
}

test_type(str)
{
    if(str == "shield")
	return this_object();
    if(next)
	return call_other(next, "test_type", str);
    return 0;
}

tot_ac()
{
    if(next)
	return call_other(next, "tot_ac");
    return 0;
}

query_type() { return type; }

query_worn() { return worn; }

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

take_off() {
   worn_by = 0;
   worn = 0;
   return 1;
}
wield(str) {
  if(!::wield(str)) return 0;
  if(TP->query_weapon()==this_object())
    wear(this_player());
  return 1;
}
stopwield() {
  call_other(worn_by, "stop_wearing",query_name());
  worn_by = 0;
  worn = 0;
  ::stopwield();
  return 1;
}