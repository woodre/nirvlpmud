inherit "obj/monster.c";
string description;
string owner;
int shorton;
object ownerob;
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(8);
    set_alias("horse");
    set_race("horse");
    set_al(200);
    set_wc(13);
    set_hp(400);
    set_ep(0);
    set_dead_ob(this_object());
    set_long("A strong white warhorse with thick powerful legs.\n"+
          "The horse is dressed in the finest red and white combat colors.\n");
     if(!owner) { set_short("A war horse");
       set_name("horse"); 
     }
    enable_commands();
}

set_rider(ob,nam) {
if(!ob) {
  set_name(lower_case(nam)+"'s war horse");
  set_short(nam+"'s war horse");
  owner = nam;
  ownerob = find_player(lower_case(owner));
  shorton = 1;
}
if(ob) {
  ownerob = ob;
  owner = nam;
  shorton = 0;
  set_short(0);
}
}

sq_follow() {
  if (!ownerob) {
    say("The horse runs off fast for its freedom.\n");
    destruct(this_object());
    return 1;
  }
  if (!present(ownerob, environment(this_object()))) {
    if(shorton) {
   tell_room(environment(this_object()),
        short()+" leaves.\n");
    move_object(this_object(), environment(ownerob));
    tell_room(environment(ownerob), this_object()->short()+" arrives.\n");
    }
    else move_object(this_object(),environment(ownerob));
  }
  call_out("sq_follow",6);
}
ride(str) {

if(!str || str != "horse") return 0;
set_rider(this_player(), this_player()->query_real_name());
say(this_player()->query_name()+" jumps on to a horse.\n");
this_player()->set_mounted(this_object());
sq_follow();
return 1;
}
set_owner(arg) { owner = arg; ownerob = find_player(arg); }
on_what() { return "horseback"; }
init() {
::init();
add_action("ride","ride");
add_action("noget","get");
add_action("noget","take");
add_action("dismount","dismount");
}
dismount(str) {
if(!str) return 0;
if(str != "horse" && str != "Horse") return 0;
 set_rider(0,this_player()->query_real_name());
 this_player()->clear_mounted();
 say(this_player()->query_name()+" dismounts from horseback.\n");
 return 1;
}
monster_died(ob){
if(ownerob->query_mounted() == this_object()) {
command("dismount horse", ownerob);
}
}
noget(str) {
string a,b;
 if(ownerob != this_player()) return 0;
 if(this_object() != this_player()->query_mounted()) return 0;
 if(sscanf(str, "%sfrom%s", a,b) == 2) return 0;
 write("You must dismount to pick up items from the ground.\n");
 return 1;
}
