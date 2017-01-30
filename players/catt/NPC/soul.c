
inherit "obj/monster";
reset(arg){
     object soul;
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
init(){
      add_action("west","dw");
     add_action("east","de");
     add_action("north","dn");
     add_action("south","ds");
     add_action("down","dd");
     add_action("up","up");
     add_action("duckto","duckto");
     add_action("dlook","dl");
     add_action("dsay","dsay");
     add_action("duckemote", "a:");
     add_action("waddle","waddle");
     add_action("soul","d");
     add_action("flap","flap");
     add_action("dtell","dtell");
     add_action("quack","quack");
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
duckemote(str){
     say("Dargoth "+str+"\n");
     write("Duck emotes: "+str+"\n");
     return 1;
}

waddle(){
     say("A duck waddles around.\n");
     say("Duck waddles.\n");
     return 1;
}

flap(){
     say("A duck flaps its wings.\n");
     write("Duck flaps its wings.\n");
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
duckto(str){
    object target;
     target = find_player(str);
    move_object(this_object(), environment(target));
    write("Dargoth teleports to "+str+".\n");
    return 1;
}
quack(){
     say("A duck quacks.\n");
     say("QUACK!\n");
     return 1;
}
dsay(str){
say("Dargoth says: "+str+"\n");
write("Dargoth says: "+str+"\n");
return 1;
}
dtell(str){
   string who, what;
    object who1;
if(sscanf(str, "%s %s", who, what) == 2){
who1 = find_player(who);
tell_object(who1, "Dargoth tells you: "+what+"\n");
write("Dargoth tells "+who+": "+what+"\n");
return 1;
}
}

dlook(){
    move_object(this_player(), environment(this_object()));
    command("look", this_player());
     move_object(this_player(), "players/catt/workroom");
    return 1;
}
catch_tell(str){
   string s1;
     tell_object(find_player("catt"),
     "$"+str+"\n");
   if(sscanf(str, "catt tells you: %s", s1) != 1) return;
     if(s1 == "dw") {
        command("west", this_object());
                    }
      if(s1 == "de") { command("east", this_object()); }
     if(s1 == "ds") { command("south", this_object()); }
  if(s1 == "dn") { command("north", this_object()); }
    if(s1 == "dd") { command("down", this_object()); }
    if(s1 == "up") { command("up", this_object()); }
     return 1;
}
