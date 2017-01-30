#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
   ::reset(arg);
    if (arg) return;
    set_name("whip");
    set_type("whip");         /* set type added by Pavlik */
   set_alias("bullwhip");
   set_short("A long leather bullwhip");
   set_long("A long bullwhip made of fine black leather.\n"+
           "You could probably 'crack' people with it.\n");
    set_class(10);
    set_weight(1);
    set_value(150);
}
init() {
  ::init();
add_action("crack", "crack");
}
crack(str){
object ob;
if(!str){
 write("You crack the whip with a loud snap!\n");
say(tp+" cracks a whip with a loud snap.\n");
return 1;   }
ob = present(str,environment(this_player()));
if(!ob) {
write("Crack the whip at who?\n");
   return 1;
}
str = capitalize(str);
write("You crack the whip at "+str+".\n"+
   str+" jumps.\n");
say(tp+" cracks a whip at "+str+".\n"+
   str+" jumps.\n");
return 1;  }
