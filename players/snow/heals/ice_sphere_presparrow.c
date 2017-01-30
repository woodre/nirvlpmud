/*
A nice, melting heal that doesn't store and is found on
/players/snow/MONSTERS/snow_demon.c
*/

inherit "/obj/treasure.c";
status flag_melt; /* 04/01/06 Earwax */
/* 04/01/06 Earwax: added so this shows up as a heal in inv */
is_heal() { return 1; }
query_save_flag() { return 1; }
id(str) { return str == "ice sphere" || str == "sphere"; }
short() { return "An Ice Sphere"+(flag_melt ? " (melting)":""); }
long() {
  write(
"This is a sphere of bluish ice. It glows with a strange magical power.\n"+
"You become aware that you are able to 'apply sphere' to heal your wounds.\n");
return 1;
}
query_weight() { return 1; }
get() { return 1; }
value() { return 0; }
init() {
  if(query_ip_number(this_player()) == "134.129.239.13" && this_player()->query_real_name() != "budah") {
    command("drop sphere", this_player()); return 1; }
  add_action("apply_sphere","apply");
}
int healnum;
reset(arg) {
  if(!arg) healnum = 3;
}
apply_sphere(str) {
  if(!str) { write("Apply what?\n"); return 1; }
  if(str == "sphere") {
    if(environment() != this_player()) return 0;
  write(
"You apply the sphere to your wounds and they instantly feel much better.\n");
  if(healnum == 3) {
/*
    write_file("/players/snow/log/heals",ctime(time())+" "+
          this_player()->query_real_name()+" used ice sphere.\n");
*/
    write(
"The Ice Sphere begins to melt quickly... soon it will be gone.\n");
flag_melt = 1;
call_out("melt",200);
  }
  say(
capitalize(this_player()->query_name())+" applies an Ice Sphere.\n");
call_other(this_player(),"heal_self",100);
  healnum --;
  if(healnum < 1) {
   write("You have just used up the last heal of the Ice Sphere. It is gone.\n");
     destruct(this_object()); this_player()->recalc_carry();
return 1;
  }
return 1;
  }
}
 
melt() {
  object ob;
  ob = environment();
  if(!ob) return;
  tell_object(ob, "Your Ice Sphere melts away into nothing!\n");
    destruct(this_object());
  if(ob->is_player()) ob->recalc_carry();
return 1;
}

quest_ob() { return 1; }
query_charges() { return healnum; }
