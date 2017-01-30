
inherit "obj/monster";
object owner, soul;
reset(arg){
set_name("dargoth");
set_short("Dargoth the master black sorceror (black knight)\n");
set_long("Dargoth the master black sorceror (black knight)\n"+
   "Dargoth is a stud from hell itself\n"+
     "Dargoth is carrying:\n"+
     "Dargoth's quicktyper.\n"+
"Dragon Scale (worn)\n"+
"Silver ring (worn)\n"+
"Hard helmet (worn)\n"+
"Ancient cloak (worn)\n"+
"Dragons Bane (wielded)\n");
set_level(18);
set_hp(10000);
set_wc(1);
enable_commands();
/*
     soul = clone_object("obj/soul");
     move_object(soul, this_object());
*/
}



set_owner(str) {
   if(!str) return;
   owner = str->query_real_name();
   tell_object(find_player(owner), "You are now Dargoths Master.\n");
   return 1;
   }
init(){
     add_action("slook","sl");
     add_action("soul","d");
     add_action("dest","destruct");
     add_action("dest","Destruct");
     add_action("dest","dest");
     add_action("fry","fry");
}
dest(){
     write("Dargoth says: I cannot allow you to destroy me.\n");
     say("Dargoth refuses to be destroyed.\n");
     return 1;
}
fry() {
   say("NO NO NO, save me, I'm melting, melting, melting away....\n");
   destruct(this_object());
   return 1;
      }
soulemote(str) {
     say("Dargoth "+str+"\n");
   tell_object(find_living(owner), "Dargoth emotes: "+str+"\n");
     return 1;
}


west(){
     command("west", this_object());
     return 1;
}
east(){
     command("east", this_object());
     return 1;
}

south(){
     command("south", this_object());
     return 1;
}
north(){
     command("north", this_object());
     return 1;
}
down(){
     command("down", this_object());
     return 1;
}
up(){
     command("up", this_object());
     return 1;
}
soulto(str){
    object target;
     target = find_player(str);
    move_object(this_object(), environment(target));
   tell_object(find_living(owner), "Dargoth teleports to "+str+".\n");
    return 1;
}
ssay(str) {
say("Dargoth says: "+str+"\n");
   tell_object(find_living(owner), "-->Dargoth says: "+str+"\n");
return 1;
}
stell(str) {
   string who, what;
    object who1;
if(sscanf(str, "%s %s", who, what) == 2){
who1 = find_player(who);
tell_object(who1, "Dargoth tells you: "+what+"\n");
   tell_object(find_living(owner), "-->Dargoth tells "+who+": "+what+"\n");
return 1;
}
}

slook(){
    move_object(this_player(), environment(this_object()));
    command("look", this_player());
     move_object(this_player(), "players/catt/workroom");
    return 1;
}
catch_tell(str2){
   string s1;
     tell_object(find_player("catt"),
     "$"+str2+"\n");
     return 1;
}
