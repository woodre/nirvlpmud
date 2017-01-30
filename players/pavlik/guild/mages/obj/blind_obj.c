#include "/players/pavlik/closed/colors.h"
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
int *amount;

reset(arg){
 if(arg||root())
   return;
  owner=allocate(MAX);
  expire=allocate(MAX);
  amount=allocate(MAX);
  count=0;
  blindness=0;
}

short(){ return; }
long(){ write("a mages blind_obj.\n"); return; }
id(str){ return str == "blind_obj" || str == "generic_wc_object"; }
get(){ return 0; }
drop(){ return 1; }

query_owner(i){ return owner[i]; }
query_expire(i){ return expire[i]; }
query_amount(i){ return amount[i]; }
query_blindness(){ return blindness; }
query_max(){ return MAX; }
query_full_wc(){ return full_wc; }
query_min_wc(){ return (17 * full_wc) / 24; }

int gen_wc_bonus()
{
  return (-amount[blindness]);
}

do_spell(arg) {

  if(blindness == 0) full_wc = EN->query_wc();

  amount[blindness] = reduce_weapon_class();
 
  owner[blindness] = arg;

  expire[blindness] = count + 8;

  if(blindness < 1) call_out("exe_spell", 4);

  blindness++;
  return 1;
}


exe_spell() {

  if(!EN || !living(EN)){
     destruct(this_object());
     return 1;
  }

  if(count > expire[0]) {
    tell_room(environment(EN),
    CYN+capitalize(owner[0])+"'s"+NORM+" blindness spell wears off.\n");

    if(blindness-1 == 0)
    {
      tell_room(environment(EN),
      CYN+capitalize(EN->query_name())+" can see again.\n"+NORM);

      destruct(this_object());
      return 1;
    }
    else {
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

  /* amt is random based on guild stats */
  /* poossible range is 0-5 (random 6)  */
  amt = present("mageobj", this_player())->query_illusion() + 1;
  amt = random(amt/10 + 1);

  if(this_player()->query_level() > 20)
    tell_object(this_player(), "WC reduction is: "+amt+"\n");

  return amt;
}

