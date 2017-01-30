inherit "obj/monster";
  object owner, target;
  int level, hp, wc, ac;
  reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("hireling");
    set_alias("assassin hireling");
    set_short("assassin hireling");
    set_long("An assassin hireling to do your dirty work.\n");
    set_level(20);
    set_hp(200);
    set_wc(10);
    set_ac(10);
    enable_commands();
    set_heart_beat(1);
          }
  /* now we go to the init or command section */

init() {
  ::init();
  if(this_player() != owner) return;
  add_action("fight","fight");
  add_action("call_off","call");
   }

     /* the next part consists of the actual command functions */

fight(str) {
   object target;
   if (!str) return 0;
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write("Hireling says: dip shit, get a life.\n");
      return 1;
          }
   write("Hireling screams in blood lust: KILL KILL!!\n");
   say(owner->query_name()+"'s hireling attacks "+
       target->query_name()+"\n");
this_object()->attack_object(target);
  return 1;
         }

call_off() {
  object target;
  write("Hireling comes and stands just behind you.\n");
  say("Hireling goes to stand at "+owner->query_name()+"'s shoulder.\n");
  target = this_object()->query_attack();
  if(target) {
  this_object()->stop_fight();
  target->stop_fight();
          }
  return 1;
        }


      /* now we put in the heart beat so he can follow owner */

heart_beat() {
  ::heart_beat();
  if(environment(this_object()) != environment(owner)) {
  tell_room(environment(this_object()), this_object()->query_name()+
           " sighs and follows "+owner->query_name()+".\n");
  tell_room(environment(owner), this_object()->query_name()+
          " sneaks in following "+owner->query_name()+".\n");
  move_object(this_object(),environment(owner));
            }
   if(query_attack()) {
      attack(target->query_real_name());
                      }
      return 1;
            }

       /* now we put in the set_owner func to set the owner */

set_owner(ob) {
  owner = ob;
  write("Hireling bows saying: "+owner->query_name()+" is my boss.\n");
  say("hireling bows saying: "+owner->query_name()+" is my boss.\n");
  return 1;
               }
