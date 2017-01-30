#include "/players/mythos/closed/ansi.h"
#define ob this_player()
#define tp this_player()->query_name()
#define user environment(this_object())
#define att user->query_attack()
#define attname att->query_name()

query_auto_load() {
    return "/players/mythos/prac/yokai.c:"; }
id(str) {return str == "koanya"; }
short() {
    return "A Scar in the shape of Om"; }
long() {
    return "A scar in the palm of the hand.\n"+"Power seems to pour from it.\n"+HIR+"\tThe name is Koanya\n"+NORM+"\n"; }
drop() {return 1;}
init() {
  call_out("hb",3);
    add_action("call_koanya", "koanya");
}

hb() {
    call_other(user,"add_spell_point",-2);
    call_other(user,"add_hit_point",-2);
    call_out("hb",3);
return 1;
}

call_koanya() {
  if(att->query_npc()) {
    if(ob->query_sp() > 75) {
    say(tp+ "calls out a word of command!\n");
    say("\t\t K  O  A  N  Y  A  !!!!\n");
    say(HIY+"\tF   L   A   S   H!"+NORM+"\n");
    write("You call out the name of the creauture:  Koanya!\n");
    write(HIY+"\tF    L    A    S    H"+NORM+"\nGreat power seethes forth from your arm and strikes "+attname+" with a bolt of pure light!\n");
    att->heal_self(-(random(20) + 30));
    call_other(user,"add_spell_point",-75);
  return 1; }
    else {
      write("You have no power left!\n");
      call_other(user,"add_hit_point",-50);
      call_other(user,"add_spell_point",-75);
      write("You feel the aftermath of using power hit you!\n"+
        "You feel weak and you topple.....\n");
      say("You see "+tp+" topple over in weakness!\n");
    return 1; }
  return 1; }
  else {
    write("You may not call upon this power against another player!\n");
    call_other(user,"add_hit_point",-25);
  return 1; }
return 1;
}
