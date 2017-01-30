#define timeset 5

string lv1,lv2;
int one_time;

id(str) { str == "daemon" || str == "mon_daem"; }

short() { return 0; }

reset(arg) {
if(arg) return;

two_time = 0;
                 /* allocation of mem for each level set */
lv1 = allocate(10);
lv2 = allocate(10);
                 /* list of mons */
lv1[0] = "/players/daranath";


call_out("cycle",60 * timeset);  /* cycle initiates
                                    every timeset min 
                                    timeset should be
                                    the shortest time */
}

cycle() {
object ob;
int h;
string moo;
object env,targ;
  if(environment(this_object())) { destruct(this_object());
      return 1; }  /* this allows only the loaded single */
  
  ob = users();
  for(h=0;h<sizeof(ob);h++) {
    env = environment(ob[h]);
    if(creator(env) == "daranath") {
      if(sscanf(env,"players/daranath/underdark/level1/%s",moo)) {
   if(one_time == 1) {
   if(random(10) < 3) {
      targ = clone_object(lv1[random(10)]);
      move_object(targ,env);
   } 
   one_time = 0;}
if(sscanf(env,"players/daranath/underdark/level2/%s",moo)) {
     if(random(10) < 3) {
       targ = clone_object(lvl2[random(10)]);
       targ->set_aggressive(1);
       move_object(targ,env);
     
     /* or 
        targ = clone_object(lvl2[random(10)]);
        move_object(targ,env);
        targ->attack_object(ob[h]);
     */
   }}

  one_time++;
call_out("cycle",60 * timeset);
return 1; }
