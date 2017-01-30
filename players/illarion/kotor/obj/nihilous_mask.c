/*  nihilous_mask.c
    physical, mental, and magical protection, plus a feed special

    feed can be used 5 times based on a willpower check against
    the opponent's willpower/level.  After the charges are exausted
    the special is gone, but the mask is otherwise intact

    feed does mental damage to the target and heals the user

    the special function for mental damage allows a small chance
    based on wil to completely negate the attack and heal
    the wearer a small amount.

    found on /players/illarion/kotor/mon/nihilous.c
*/

#include "/players/illarion/dfns.h"
inherit "obj/armor";

int uses;
int last_feed;
int lightsaber_on;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("mask");
  set_short("The mask of "+HIK+"Darth"+HIW+" N"+HIR+"ih"+HIW+"il"+HIR+"ou"+HIW+"s"+NORM);
  set_long(
"This menacing white and red mask once belonged to the Sith Lord Darth\n"+
"Nihilous.  So much time in close proximity to a Sith Lord has given it\n"+
"a great deal of power of its own.  If you're strong enough to control\n"+
"that power, you might even be able to duplicate Nihilous' ability to\n"+
"'feed' on his foes, though the strain might damage the mask.\n");
  set_ac(2);
  set_params("magical",1,0,0);
  set_params("other|mental",0,15,"mental_absorb");
  set_type("misc");
  set_value("10000");
  set_weight(1);
  uses=5;
}

query_kotor_barter() { return 1; }

locker_arg() {
  return "uses:"+uses;
}

locker_init(str) {
  if(!str) uses=0;
  else sscanf(str,"uses:%s",uses);
}

long() {
  ::long();
  switch(uses) {
    case 5: return write("You can almost see the power pouring from the mask.\n");
    case 4: return write("The power of the mask seems slightly diminished.\n");
    case 3: return write("The power of the mask seems moderately diminished.\n");
    case 2: return write("The power of the mask is starting to run low.\n");
    case 1: return write("The power of the mask is almost gone.\n");
    default: return write("The mask seems empty of Nihilous' draining ability.\n");
  }
}

init() {
  ::init();
  add_action("cmd_feed","feed");
}

mental_absorb(object user) {
  /* 15% chance with wil of 30 */
  if(random(user->query_attrib("wil")) > random (100)) {
    write("Your mask allows you to complete absorb the mental attack!\n");
    user->heal_self(5);
    return 10000;
  }
}

status cmd_feed() {
  object victim;
  int wil;
  int res;
  int now;
  if(!worn) FAIL("You must be wearing the mask!\n");
  if(uses<=0) FAIL("The mask's powers have been drained; it can no longer be used to feed.\n");
  now=time();
  if(now <= last_feed+3) FAIL("You must wait before using the mask's power again.\n");
  victim=(object)TP->query_attack();
  if(!victim || !present(victim,ENV(ETO))) 
    FAIL("You must be in combat to use the mask to feed.\n");
  res=(int)victim->query_attrib("wil");
  if(!res) res=(int)victim->query_level();
  wil=(int)TP->query_attrib("wil");
  if(random(wil) > random(res)) {
    uses--;
    last_feed=now;
    write("Concentrating through Dark Nihilous's mask, you reach out and size hold of\n"+
        NAME(victim)+"'s mind, and RIP away a piece of it!\n");
    tell_object(victim,"A violent fource seizes hold of your mind, and rips away a piece\n"+
        "of it!\n");
    say(NAME(victim)+" staggers, looking dazed and pained!\n",victim);
    TP->heal_self((int)victim->hit_player(5+random(wil/3),"other|mental"));
    TP->add_alignment(-100);
    return 1;
  } else {
    write(NAME(victim)+" resists your attempt to feed from "+OBJ(victim)+"!\n");
    tell_object(victim,
"You feel a sudden and immense pressure on your mind, but manage to resist it!\n");
    return 1;
  }
}

