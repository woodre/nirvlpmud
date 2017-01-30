inherit "obj/treasure";
object ob,ob2;
reset(arg) {
  if(arg) return;
    set_id("shadowcon");
    set_alias("control");
    set_short();
    set_long("To use type <shadow_me>\n"+
             "To destruct type <soff>\n");
    set_weight(1);
    set_value(0);
}
 init() {
   ::init();
   add_action("shadow","shadow_me");
   add_action("soff","soff");
   }
   
shadow() {
ob=clone_object("/players/mythos/prac/shadower.c");
ob->set_owner(this_player()->query_real_name());
ob2 = ob;
move_object(ob,environment(this_player()));
write("You are now shadowed.\n");
return 1;}

soff() {
destruct(ob2);
write("Shadow is gone.\n");
return 1;}
