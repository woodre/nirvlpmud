/* SHAMROCK! */
 
id(str) { return str == "shamrock" || str == "clover"; }
short() { return "A shamrock <flourescent green>"; }
long() { 
  write("A shamrock! This must be your lucky day!\n"+
        "Sniff it and you might have a lucky heal!\n");
  write("'clover <player>' to send a shamrock to someone!\n");
return 1;
}
get() { return 0; }
drop() { return 0; }
init() {
  add_action("sniff_shamrock","sniff");
  add_action("share_shamrock","clover");
}
 
sniff_shamrock(arg) {
  if(!arg) { write("Sniff what?\n"); return 1; }
  if(arg == "shamrock" || arg == "clover") {
    if(this_player()->query_sp() < 1) {
      write("The shamrock withers as you try to sniff it!\n");
      destruct(this_object());
    return 1;
    }
    write("You sniff the shamrock...\n");
    say(capitalize(this_player()->query_name())+" sniffs a shamrock...\n");
    if(random(12) == 7) {
      tell_room(environment(this_player()),"   S H A M R O C K ! ! !\n");
      write("You are covered in a soothing green aura!\n");
      say(capitalize(this_player()->query_name())+
         " is covered in a soothing green aura!\n");
  if(this_player()->query_sp() > 15) {
      this_player()->add_hit_point(10);
    this_player()->add_spell_point(-15);
   }
    }
  return 1;
  }
}
 
share_shamrock(arg) {
  object ob,clo;
  write("This command disabled on demands of the MAN!!!\n");
  return 1;
clo = clone_object("/players/snow/ITEMS/shamrock.c");
  if(!arg) { write("Clover who?\n"); return 1; }
ob = find_player(arg);
  if(!ob) { write("That player is not on!\n"); return 1; }
  if(ob->query_level() > 20) {
    write("You cannot clover wizzes!\n");
  return 1;
  }
  if(present("clover",ob)) {
    write("That player already has a shamrock!\n");
  return 1;
  }
  tell_object(ob,"You have received a shamrock!\n");
  write("You send "+capitalize(arg)+" a shamrock!\n");
  move_object(clo,ob);
return 1;
}
