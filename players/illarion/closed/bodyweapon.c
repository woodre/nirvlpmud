inherit "obj/weapon";
#include "/players/illarion/dfns.h"

mapping poss_moves;
string curr_move;
object curr_att;
int hand;

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
  poss_moves = ([
    "jab":       ({"jab","elbow","knee","kick",}),
    "elbow":     ({"jab","palm","knee","back kick","backhand"}),
    "knee":      ({"jab","palm","elbow","kick"}),
    "kick":      ({"jab","knee","kick","face kick","back kick"}),
    "palm":      ({"jab","elbow","knee","back kick"}),
    "backhand":  ({"jab","palm","kick",}),
    "back kick": ({"jab","elbow","face kick","spin kick","backhand"}),
    "face kick": ({"jab","kick","spin kick"}),
    "spin kick": ({"jab","kick"}),
  ]);
  curr_move="jab";
}

weapon_hit(object att) {
  if(att != curr_att) {
    curr_move="jab";
    hand=0;
    curr_att=att;
  }
}
weapon_breaks() { /* usual effect doesn't make sense for unarmed */
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
  curr_move="jab";
  hand=0;
  return ::count_misses();
}
count_hit_made(w) {
  if(curr_att) {
    string *moves;
    moves=poss_moves[curr_move];
    curr_move=moves[random(sizeof(moves))];
    hand=!hand;
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
  mess[0]+=" with a "+(hand?"left":"right")+" "+curr_move;
  return mess;
}
