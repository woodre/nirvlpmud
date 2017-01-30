inherit "obj/monster";
 
object pobj;
int following, telling;
string master;
 
init() {
 
   ::init();
}
 
catch_tell(str) {
string s1, s2, s3;
 
   if (!pobj) return;
   if (pobj && telling) {
      tell_object(pobj, "%% "+str);
   }
   if (sscanf(str, "%s %s: %s", s1, s2, s3) == 3) {
      if (s1 == master && s2 == "says") {
         if (s3 == "come\n" || s3 == "follow\n") {
            say("The zombie says: Ok master.\n");
            following = 1;
            return;
         }
         if (s3 == "stay\n") {
            say("The zombie says: Ok master.\n");
            following = 0;
            return;
         }
         if (s3 == "spy\n") {
            say("The zombie says: Ok master.\n");
            telling = 1;
            return;
         }
         if (s3 == "nospy") {
            say("The zombie says: Ok master.\n");
            telling = 0;
            return;
         }
 
      }
   }
}
 
reset(arg) {
   ::reset(arg);
   if (arg) return;
   enable_commands();
 
   move_object(clone_object("obj/soul"), this_object());
   set_name("zombie");
   set_alias("zombie of "+lower_case(name));
   set_race("undead");
   set_short("The zombie of "+name);
   set_long("The zombies eye seem to follow you!\n");
   set_level(20);
   set_hp(666);
   set_ac(13);
   set_al(-666);
   set_wc(19);
   set_can_kill(1);
   set_heart_beat(1);
}
 
 
set_pobj(obj) {
   pobj = obj;
   following = 1;
   telling = 1;
   master = call_other(pobj, "query_name");
}
 
set_str(str) {
   set_pobj(find_player(str));
}
 
heart_beat() {
 
   ::heart_beat();
   if (following && (environment(pobj) != environment(this_object())) ) {
      say("The zombie shuffles off for the master.\n");
      move_object(this_object(), environment(pobj));
      say("A zombie arrives.\n");
      return;
   }
}
