/* song_curse.c
   prevents the bard from doing any damage at all, but lowers the target's
   resistance to the specified damage type.  not so good in solo combat,
   but nice in parties
*/

#define OBNAME "bard_song_curse_object"

string dtype;
object last_target;
object user;
int strength;

status id(string str) {
  return str=="generic_wc_bonus" || str==OBNAME || str=="no_msg_hit";
}

short() {
  if(!user || user!=environment())
    destruct(this_object());
}

status get() { return 1; }
status drop() { return 1; }

int gen_wc_bonus(object target) {
  /* remove the armor from the last target if that target still exists */
  if(last_target && last_target!=target) {
    last_target->RemoveArmor(this_object());
    last_target=target;
  }
  target->RegisterArmor(this_object(),({dtype,0,-strength,0}));
  return -100;
}

set_user(u) {
  user=u;
}

set_strength(s) {
  strength=s;
}

set_dtype(str) {
  dtype=str;
}
