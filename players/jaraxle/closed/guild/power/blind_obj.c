#include "/players/maledicta/closed/colors.h"
#define EN environment(this_object())
#define MAX 3

/* the target's full, unaffected weapon class */
int full_wc;

/* count until the spell expires */
int count;

/* number of people who have spell in effect */
int blindness;

/* arrays to track casting info */
string owner;
int expire;
int amount;

reset(arg){
 if(arg)
   return;
  owner=allocate(MAX);
  expire=allocate(MAX);
  amount=allocate(MAX);
  count=0;
  blindness=0;
}

short(){ return; }
long(){ write("a mages blind_obj.\n"); return; }
id(str){ return str == "blind_obj"; }
get(){ return 0; }
drop(){ return 1; }

query_owner(i){ return owner[i]; }
query_expire(i){ return expire[i]; }
query_amount(i){ return amount[i]; }
query_blindness(){ return blindness; }
query_max(){ return MAX; }
query_full_wc(){ return full_wc; }
query_min_wc(){ return (17 * full_wc) / 24; }

do_spell(arg) {

  /* note the original, unaffected weapon class */
  if(blindness == 0) full_wc = EN->query_wc();

  /* reduce the weapon class */
  amount[blindness] = reduce_weapon_class();
  EN->set_wc(EN->query_wc() - amount[blindness]);

  /* tag who's spells are active so they can't cast twice */
  owner[blindness] = arg;

  /* set when this person's spell will expire */
  expire[blindness] = count + 8;

  if(blindness < 1) call_out("exe_spell", 4);

  blindness++;
  return 1;
}


exe_spell() {

  /* if the target is gone dest this */
  if(!EN || !living(EN)){
     destruct(this_object());
     return 1;
  }

  /* is it time for blind to end? */
  if(count > expire[0]) {
    tell_room(environment(EN),
    CYN+capitalize(owner[0])+"'s"+NORM+" blindness spell wears off.\n");

    /* if is only blind in effect kill it all */
    if(blindness-1 == 0) {
      tell_room(environment(EN),
      CYN+capitalize(EN->query_name())+" can see again.\n"+NORM);

      /* always set wc back to the original stat */
      EN->set_wc(full_wc);

      destruct(this_object());
      return 1;
    }
    else {
      /* increase the target's weapon class */
      EN->set_wc(EN->query_wc() + amount[0]);

      /* shift the caster's data */
      shift_stuff();
      blindness--;
    }
  }

  tell_room(environment(EN),
  capitalize(EN->query_name())+" stumbles about blindly.\n");
  count++;
  call_out("exe_spell", 4);
  return 1;
}

shift_stuff() {
  owner[0] = owner[1];   expire[0] = expire[1];
  owner[1] = owner[2];   expire[1] = expire[2];
  owner[2] = 0;          expire[2] = 0;
}

/*
 * this function picks the number that the targets weapon class
 * will be reduced by.
 * the range of possibilty is 0 thru 5, or random 6
 * possible 100 divided by 10 then add 1
 * the sum of all effects can never reduce the target to
 * less than 17/24ths of its original weapon class
 */
reduce_weapon_class() {
  int max_effect;
  int amt;

  max_effect = EN->query_wc() - query_min_wc();

  /* amt is random based on guild stats */
  /* poossible range is 0-5 (random 6)  */
  amt = present("mageobj", this_player())->query_illusion() + 1;
  amt = random( (amt/10) + 1 );
  if(amt > 5) amt = 5;

  /* cannot lose more than 7/24 of original weapon class */
  if(amt > max_effect) amt = max_effect;

  if(this_player()->query_level() > 20)
    tell_object(this_player(), "WC reduction is: "+amt+"\n");

  return amt;
}

