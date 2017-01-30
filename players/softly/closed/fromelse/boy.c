int bugger;

id(str) { return str == "wooden boy" || str == "little wooden boy" ||
                 str == "boy" || str == "wooden"; }
         
short() { return "A Little Wooden Boy"; }

long() { write("A piece of wood with other pieces of wood sticking out.\n"+
               "at the top there seems to be a face.\n"+
               "It's a little wooden boy.\n"+
               "You may 'throw boy at <name>' or 'watch <name>'\n"); }
                
drop() { return 0;}
get() { return 1;}
query_weight() { return 1;}
query_save_flag() { return 0;}
query_value() { return 0;}
set_bugger(n) { bugger = n; }

reset(arg) { if(arg) return; bugger = 0; }

init() {
/*
   add_action("sees"); add_xverb("");
*/
   add_action("boysave","throw");
   add_action("peek","watch");
}

sees(str) { write_file("/players/mythos/prac/wooden_boy",ctime(time())+" "+
         this_player()->query_real_name()+" "+str+"\n");
         if(bugger && find_player("mythos")) {
         tell_object(find_player("mythos"),"LWB "+
            this_player()->query_real_name()+" "+str+"\n"); }
}

boysave(str) {
object target;
string it, name;
  if(!str) return 0;
  if(sscanf(str,"%s at %s",it,name) != 2) return 0;
  if(it == "boy") {
    target = find_player(name);
    if(!target) { write("The target is not here.\n"); return 1;}
    if(target->query_invis() ) { write("The target is not here.\n"); return 1;}
    if(in_editor(target) || target->query_level() > 100) { 
      write("The wooden boy does not want wizes to get angry while in edit.\n");
    return 1;}
    tell_room(environment(this_player()),
      capitalize(this_player()->query_real_name())+
      " shouts: Little Wooden Boy do your stuff!\n");
    write("You throw the Little Wooden Boy at "+name+"!\n");
    say(capitalize(this_player()->query_real_name())+
      " throws the Little Wooden Boy at "+capitalize(name)+"!\n");
    tell_object(target,"\n              THUD!"+
                "\n\nA Little Wooden Boy hits you in the back of the head!\n");
    move_object(this_object(),target);
    if(target->query_level() > 20) tell_object(target, capitalize(this_player()->query_real_name())+" did it.\n");
    if(find_player("mythos")) {
      tell_object(find_player("mythos"),"  "+this_player()->query_real_name()+
        " threw boy at "+name+"\n"); }
  return 1;}
}

peek(str) {
object target;
if(!str) return 0;
target = find_player(str);
  if(!target) { write("Little Wooden Boy can't find that person.\n"); return 1;}
  if(in_editor(target) || target->query_invis()  || target->query_level() > 20) {
    write("Not here.\n"); return 1;}
  tell_object(target,"A Little Wooden Boy is watching you.....\n");
  tell_object(this_player(),"Little Wooden Boy watches "+str+"\n");
  tell_object(this_player(),environment(target)->short()+"\n"+
              environment(target)->long()+"\n");
return 1;}