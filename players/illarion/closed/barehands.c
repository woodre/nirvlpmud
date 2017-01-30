inherit "obj/weapon";
#include "/players/illarion/dfns.h"

int seq_count;
string *seq_attacks;
object curr_att;

void reset(int arg) {
  if(arg) return;
  
  set_name("body");
  set_short(0);
  set_class(18);
  set_long("Skill at unarmed fighting comes only after long practice,\n"+
           "and even then requires great fortitude and concentration for\n"+
           "true success.  A warrior must persevere.  Your body has been\n"+
           "trained in the right disciplines.\n");
  set_weight(1);
  set_value(0);
  set_hit_func(this_object());
  seq_attacks=({"with a jab","with a knee","with an elbow",
                "with a back kick","with a spin kick"});
}
weapon_hit(object att) {
  if(att != curr_att) {
    curr_att=att;
    write("You begin to study your new opponent.\n");
    seq_count-=2;
    if(seq_count>-2) seq_count=-2;
  }
  if(seq_count) {
    seq_count++;
    if(seq_count >= 6) {
      write("You have finished your attack sequence.\n");
      seq_count=0;
      return 0;
    }
    if(seq_count>0)
      write("You position yourself for the next attack in your sequence.\n");
  } else if(random(60) < (int)TP->query_attrib("luc")) {
    seq_count = 1;
    write("You begin a potentially devastating system of sequenced attacks.\n");
  }
  return 0;
}
weapon_breaks() { /* classic effect doesn't make sense for unarmed */
              /* will drain str and con instead, if player lets it happen */
  object obj;
  obj=environment(this_object());
  tell_object(obj,
"Your limbs have become bruised and tired.  Your overall health suffers.\n");
  obj->raise_strength(-1);
  obj->raise_stamina(-1);
  misses /=2;
  hits /=2;
}
count_misses() {
  if(seq_count>0) {
    write("You loose concentration, and your series collapses.\n");
    seq_count=0;
  }
  return ::count_misses();
}
count_hit_made(w) {
  if(curr_att && seq_count>0) {
    int tmp;
    tmp=(seq_count*5)+5;   /* min 10, max 30 */
    wielded_by->spell_object(curr_att,"hit",random(tmp),tmp/2,
curr_att->query_name()+" reels from the blow.\n",
"You reel from the blow.\n",
curr_att->query_name()+" reels from the blow.\n");
  }
  return ::count_hit_made(w);
}
long() {
  write(long_desc);
  if(wielded_by)
    write(extra_look()+".\n");
}
extra_look() {
  int wear;
  object them,env;
  string ret;
  if(!wielded_by) return 0;
  env=environment(this_object());
  if(!env) return 0;
  wear=query_wear();
  if(env==TP) ret="Your body ";
  else ret=env->query_name()+"'s body ";
  switch(wear) {
    case 0..39:    return ret+"is strong and in top shape";
    case 40..99:   return ret+"is a little scratched and bruised";
    case 100..199: return ret+"has some impresive cuts and bruises";
    case 200..399: return ret+"is looking pretty beat up";
    default:       return ret+"is looking very beat up.";
  }
}    
string *query_message_hit(int dam) {
  string *mess;
  mess= (mixed)::query_message_hit(dam);
  if(seq_count>0)
    mess[0]+=(" "+seq_attacks[seq_count-1]);
  return mess;
}
