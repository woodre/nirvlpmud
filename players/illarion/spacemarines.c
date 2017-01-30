/* Space Marines.
 * This monster represents a whole squad, meaning it must be killed several
 * times.
 */

inherit "/obj/monster.c";
int marines;

void calculate_wc();

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  marines=8;
  
  calculate_wc();
  set_ac(20);
  set_hp(400);
  set_name("marines");
  set_alt_name("marine");
  set_race("human");
  
  set_short("A squad of space marines.");
  
  set_long("\
Heavily augmented, armored, and trained, a squad of space marines fights\n\
as a single unit.  While each individual marine is a dealy soldier, they are\n\
all the more deadly in a squad.\n");
}

string short() {
  return ::short()+"["+marines+"]";
}

void long() {
  ::long();
  write("There "+(marines>1?"are":"is")+" "+(marines)+" marine"+(marines>1?"s":"")+" remaining.\n");
}

second_life() {
  marines --;
  if(marines > 1) {
    calculate_wc();
    heal_self(400);
    return 1;
  }
  return 0;
}

calculate_wc() {
  set_wc(marines+marines*5);
}
