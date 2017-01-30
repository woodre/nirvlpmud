inherit "obj/treasure";
  string owner, nme;
  int x, move_num;
reset(arg) {
 if(arg) return;
set_short("blah");
set_long("blah");
set_weight(667);
set_value(0);
  owner = "Nobody";
   move_num = 7;   x = 0;
}
id(str) { return str == "levtate_obj" || str == owner+"'s levtate"; }
set_owner(str) { owner = str; }
set_nme(str) { nme = str; }
get() { return; }
drop() { return; }
short() {
  return nme+" *levitating*"; }
long() {
  write("All you can see is the bottom of "+capitalize(owner)+
  "'s feet, levitating\n"+
  "in the air above you.\n"); }

init() {
::init();
if(present(this_player(), this_object())) {
add_action("down","down");
add_action("levitate","levitate");
add_action("quit","quit");
add_action("look","look");
add_action("look","l");
add_action("say_it","say");
add_action("say_it"); add_xverb("'");
add_action("fly","fly");
   }
add_action("look_at","look at");
}
quit() {
 write("You cannot quit while levitating.\n");
   return 1;
}
 
look_at(str) {
 if(str == owner) {
write("All you can see are the bottom of "+capitalize(owner)+
 "'s feet, floating above you.\n");
return 1; }
}
levitate() {
 write("You are already levitating!\n");
 return 1;
}

down() {
tell_room(environment(this_object()),
 capitalize(owner)+" gently floats to the ground.\n");
 write("You gently float back down to the ground.\n");
move_object(this_player(), environment(this_object()));
 destruct(this_object());
return 1;
}

look() {
  object me, ob;
me = this_player();
ob = this_object();
 if(x == 0) {
move_object(me, environment(ob));
x = 1;
command("look", me);
move_object(me, ob);
x = 0;
   return 1;
   }
}

catch_tell(str) {
tell_object(find_player(owner), str+"\n");
  return;
}
say_it(str) {
 if(!str) { write("Say what?\n"); return 1; }
write("You yell down: "+str+"\n");
tell_room(environment(this_object()), 
capitalize(this_player()->query_name())+" yells down: "+str+"\n");
return 1;
}

fly(str) {
  object me, ob, obj;
if(!str) { write("Usage: fly <dir>.\n"); return 1; }
if(move_num < 1) {
 write("You have moved as far as you can.  You do not have the\n"+
       "energy to go any farther.\n"); return 1; }
if(this_player()->query_sp() < 5) {
 write("You do not have the energy to move a direction right now.\n");
        return 1; }
me = this_player();
ob = this_object();
if(this_player()->query_guild_rank() < 20) {
move_num--;
if(move_num > 1) {
write("You fly '"+str+"'. ( You have "+move_num+" moves left. )\n"); }
if(move_num == 1) {
write("You fly '"+str+"'. ( You have only 1 move remaining. )\n"); }
if(move_num == 0) {
write("You fly '"+str+"'. ( You cannot fly any further. )\n"); }
   } else {
write("<< You fly '"+str+"' >>\n"); }
 move_object(me, environment(this_object()));
 command(str, me);
 move_object(ob, environment(me));
 move_object(me, ob);
 this_player()->add_spell_point(-5);
 return 1;
}
realm() { return "NT"; }
