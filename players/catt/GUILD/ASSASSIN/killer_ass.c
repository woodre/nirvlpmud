inherit "obj/monster";
object owner;
int level, hp, wc, ac, test;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("assassin");
  set_alias("assassin");
  set_alt_name("death assassin");
  set_short("Death Assassin");
  set_long("Death assassin sent to kill you. Not even a godfather\n"+
           "could defeat it. You should not have left the guild!\n");
  set_level(25);
   set_hp(500);
   set_wc(15);
   set_ac(15);
   set_heart_beat(1);
    enable_commands();
}
catch_tell(str) {
  string s1;
  if(sscanf(str, "%s must be exterminated!", s1) != 1) return;
   owner = find_player(s1)->query_name();
   write("I, the death assassin, am here to kill you!\n");
   say("I, the death assassin, am here to kill "+owner+"\n");
   test = 1;
return 1;
   }
heart_beat() {
  ::heart_beat();
  if(environment(this_object()) != environment(owner)) {
    tell_room(environment(this_object()),
      "You notice a slight chill as death brushes past you.\n");
    tell_room(environment(owner->query_name()),
     "The Death Assassin stalks you patiently.\n");
     move_object(this_object(), environment(owner));
      }
if(query_attack()) {
  attack(owner->query_real_name());
  if(random(100) > 80) {
     owner->hit_player(30);
     tell_object(owner,
     "Death Assassin hits you with a black throwing dagger.\n"+
     "OUCH!!! that hurt.\n");
   } } }
