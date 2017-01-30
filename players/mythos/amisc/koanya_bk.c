#include "/players/mythos/closed/ansi.h"
#define ob this_player()
#define tp this_player()->query_name()
#define user environment(this_object())
#define att user->query_attack()
#define attname att->query_name()

query_auto_load() {
    return "/players/mythos/prac/yokai.c:"; }
id(str) {return str == "brand"; }
short() {
    return "A Brand in the shape of Om"; }
long() {
    return "A brand in the shape of the sign OM.\n"+"Power seems to pour from it.\n"+HIY+"\tThe name is KOANYA\n"+NORM+"\n"+"It may be 'clean'ed off.\n"; }
drop() {return 1;}
init() {
  call_out("hb",3);
add_action("call_koanya", "koanya");
add_action("erase_brand", "clean");
}

hb() {
    call_other(user,"add_spell_point",-3);
    call_other(user,"add_hit_point",-3);
    call_out("hb",3);
return 1;
}

call_koanya() {
  if(att->query_npc()) {
    if(ob->query_sp() > 29) {
    say(tp+ "calls out a word of command!\n");
    say("\t\t K  O  A  N  Y  A  !!!!\n");
    say(HIY+"\tF   L   A   S   H!"+NORM+"\n");
    write("You call out the name of the creauture:  Koanya!\n");
    write(HIY+"\tF    L    A    S    H"+NORM+"\nGreat power seethes forth from your arm and strikes "+attname+" with a bolt of pure light!\n");
    att->heal_self(-(random(15) + 35));
    call_other(user,"add_spell_point",-30);
    call_other(user,"add_hit_point",-20);
  return 1; }
    else {
      write("You have no power left!\n");
      call_other(user,"add_hit_point",-50);
      call_other(user,"add_spell_point",-50);
      write("You feel the aftermath of using power hit you!\n"+
        "You feel weak and you topple.....\n");
      say("You see "+tp+" topple over in weakness!\n");
    return 1; }
  return 1; }
  else {
    write("You may not call upon this power against another player!\n");
    call_other(user,"add_hit_point",-30);
    call_other(user,"add_spell_point",-15);
  return 1; }
return 1;
}

erase_brand() {
object ob;
  if(this_player()->query_current_room()=="players/mythos/aroom/shrinear5.c") {
  ob=first_inventory(environment(this_player()));
  while(ob) {
    if(ob->query_name()=="Priest") {
    write("The Priest softly incants something.....\n"+
      "He takes out a knife and cuts your brand out!\n");
    say("The Priest intones softly....\n"+
      "he then takes out a knife and cuts out the brand!\n");
    call_other(user,"add_hit_point",-20);
    call_out(user,"add_spell_point",-30);
    destruct(this_object());
}
ob=next_inventory(ob);
ob;
}
return 1;}
  else {
  write("You need a Shinto Priest to do that!\n");
return 1;}
return 1;}
