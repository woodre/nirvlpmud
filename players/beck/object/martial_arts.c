#define KARATEDIR "players/beck/save/martial_arts/"
int karate_level;
id(str) { return str=="karate_belt" || str=="belt"; }
reset(){
   call_out("karate_attack", 4);
}
short() {
      return "A White Belt";
}
long() {
write("This belt signifies your training in the martial arts.\n"+
"You can tell how much you have learned by the color of the belt.\n"+
"");
}


set_karate_level(arg) {
   karate_level = arg;
   return 1;
}
query_karate_level() {
   return karate_level;
}
query_auto_load() {return "/players/beck/object/martial_arts:";}
init_arg() {
   if(restore_object(KARATEDIR+this_player()->query_real_name()))
      write("You meditate to restore your martial arts powers...\n");
   else{
      save_belt();
   }
   return;
}
init() {
   add_action("quit","quit");
}
get() {
   return 1;
}
drop() {return 1;}
query_weight() { return 0; }
query_value() { return 0; }
save_belt() {
   save_object(KARATEDIR+this_player()->query_real_name());
   write("Writing your workouts in your training log...\n");
   return 1;
}
restore_belt() {
   restore_object(KARATEDIR+this_player()->query_real_name());
   write("Reading your workouts from your training log...\n");
   return 1;
}
karate_attack(){
   object target;
   object tp;
   int level;
   int damage;
   tp = environment(this_object());
   target = tp->query_attack();
   damage = (((present("gym_membership", tp))->query_strength_level())/20);
   damage += ((present("karate_belt", tp))->query_karate_level());
   if(damage < 1){
      damage = 1;
   }
   level = (present("gym_membership", tp))->query_strength_level();
   level += (present("karate_belt", tp))->query_karate_level();
   if(!target){
      call_out("karate_attack", 4);
      return 1;
   }
   if(target->query_hp() < damage){
      call_out("karate_attack", 4);
      return 1;
   }
   if(level > random(20)){
      target->hit_player(damage);
say("You give "+target->query_name()+ " a chop to the head.\n");
      call_out("karate_attack", 4);
      return 1;
   }
   call_out("karate_attack", 4);
   return 1;
}
quit(){
   save_belt();
   return;
}
