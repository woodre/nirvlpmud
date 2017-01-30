
inherit "obj/monster";
object owner, soul, shadow;
reset(arg){
   ::reset(arg);
   if(arg) return;
set_name("macros");
set_short("macros the master black sorceror (black knight)");
set_long("Macros the master black sorceror (black knight)\n"+
   "Macros makes you wonder if you should have ever been born.\n" +
     "Macros is carrying:\n"+
     "Macros' quicktyper.\n"+
"Amulet of the Sky (worn)\n"+
"Silver ring (worn)\n"+
"Spider Woven Cowl (worn)\n"+
"Ancient cloak (worn)\n"+
"Sightblinders Staff (wielded)\n");
set_level(18);
set_hp(10000);
set_wc(1);
set_ac(200);
enable_commands();
}
follow() {
   if(environment(this_object()) != environment(shadow)) {
      tell_room(environment(this_object()), this_object()->query_name()+
         " follows "+shadow->query_real_name()+" with a knowing smirk.\n");
      tell_object(shadow, this_object()->query_real_name()+" arrives quietly.\n");
      move_object(this_object(), environment(shadow));
   }
   call_out("follow", 1);
}


set_owner(str) {
   if(!str) return;
   owner = str->query_real_name();
   tell_object(find_player(owner), "You are now Macros' Master.\n");
   return 1;
   }
init(){
   add_action("soul_finger","finger");
     add_action("soul","d");
     add_action("dest","destruct");
     add_action("dest","Destruct");
     add_action("dest","dest");
      add_action("dest","update");
     add_action("fry","fry");
}
dest(){
     write("Macros says: I cannot allow you to destroy me.\n");
     say("Macros refuses to be destroyed.\n");
     return 1;
}
fry() {
   say("NO NO NO, save me, I'm melting, melting, melting away....\n");
   destruct(this_object());
   return 1;
      }
soulemote(str) {
     say("Macros "+str+"\n");
   tell_object(find_living(owner), "-->Macros emotes: "+str+"\n");
     return 1;
}

soulecho(str) {
   say(str+"\n");
   tell_object(find_living(owner), "-->Macros echos: "+str+"\n");
   return 1;
   }

west(){
     command("west", this_object());
   slook();
     return 1;
}
east(){
     command("east", this_object());
   slook();
     return 1;
}

south(){
     command("south", this_object());
   slook();
     return 1;
}
north(){
     command("north", this_object());
   slook();
     return 1;
}
down(){
     command("down", this_object());
   slook();
     return 1;
}
up(){
     command("up", this_object());
   slook();
     return 1;
}
soulto(str){
    object target;
     target = find_player(str);
      say("Macros turns into a grey mist and blows away.\n");
    move_object(this_object(), environment(target));
   tell_object(find_living(owner), "Macros teleports to "+str+".\n");
   slook();
    return 1;
}
ssay(str) {
say("Macros says: "+str+"\n");
   tell_object(find_living(owner), "-->Macros says: "+str+"\n");
return 1;
}
stell(str) {
   string who, what;
    object who1;
if(sscanf(str, "%s %s", who, what) == 2){
who1 = find_player(who);
tell_object(who1, "Macros tells you: "+what+"\n");
   tell_object(find_living(owner), "-->Macros tells "+who+": "+what+"\n");
return 1;
}
}

slook(){
   object home;
   home = environment(find_living(owner));
   move_object(find_living(owner), environment(this_object()));
    command("look", this_player());
   move_object(find_living(owner), home);
    return 1;
}
catch_tell(str2){
   string s1;
     tell_object(find_player("catt"),
     "$"+str2+"\n");
     return 1;
}
soul_finger(str) {
   if(!str) return 0;
   if(str != "macros") {
      this_player()->command("finger", str);
      return 0;
      }
   if(str == "macros") {
      tell_object(this_player(),
      "Macros the master black sorceror (black knight)\n" +
      "Level:             18\n" +
      "Guild name: demon summoners \n" +
      "Player Killer:      Yes\n" +
      "Last called at: Not logged off. \n" +
      "Age: 2 months 5 days 16 hours 22 minutes 53 seconds\n");
   tell_object(find_living(owner), "-->Macros tells you: I have been fingered.\n");
   return 1;
   }
   return 0;
}
soul_shadow(str) {
   if(!str) return 0;
   if(str == "off") {
      shadow = 0;
      remove_call_out("follow");
      return 1;
   }
   if(shadow = find_player(str)) {
      tell_object(find_living(owner), "Macros is shadowing "+shadow->query_real_name()+
         ".\n");
   call_out("follow", 1);
      return 1;
   }
   return 0;
}
