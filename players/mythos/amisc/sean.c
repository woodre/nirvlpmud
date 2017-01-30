#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
#define user environment(this_object())
#define att user->query_attack()
#define attname att->query_name()

  int q;
query_auto_load() {
    return "/players/mythos/amisc/tsolin.c:"; }
id(str) {return str == "brand"; }
short() {
    return "A Brand in the shape of Om"; }
long() {
    write("A brand in the palm of the hand.\n"+"Power seems to eminate from it.\n"+"\tThe name is "+CYN+"Suteinshion"+NORM+"\n"+"The brand may be 'erase'ed.\n");
}
drop() {return 1;}
init() {
  call_out("hb",3);
add_action("call_sutei", "suteinshion");
add_action("erase_brand", "erase");
}

hb() {
    call_other(user,"add_spell_point",-4);
    call_other(user,"add_hit_point",-4);
    call_out("hb",3);
return 1;
}

call_sutei() {
  object ob3, ob4;
    if(this_player()->query_sp() > 19) {
  q=5;
  ob4=first_inventory(environment(this_player()));
  while(ob4) {
    if(living(ob4)) {
  ob3=clone_object("/players/mythos/amisc/stopper.c");
    move_object(ob3,ob4);
    }
    ob4=next_inventory(ob4);
    ob4;
    }
    call_other(user,"add_spell_point",-20);
    call_other(user,"add_hit_point",-10);
    say(tp+" holds up his hands and in a quiet voice speaks THE WORD.\n"+
    "A field of shimmering colors surrounds "+this_player()->query_objective()+".\n");
    write("You hold up your hands and in a quiet voice you say Suteinshion.\n"+
    "A field of shimmering colors surrounds you.  You feel safer.\n");
      write("You feel Suteninshion suck some of your essence to live...\n");
    call_out("acer",1);
  return 1; }
    else {
      write("You have no power left!\n");
      call_other(user,"add_hit_point",-10);
      call_other(user,"add_spell_point",-30);
      write("You feel the strain of using power too much....\n"+
        "You feel weak and you topple.....\n");
      say("You see "+tp+" topple over in weakness!\n");
    return 1; }
return 1;
}

erase_brand() {
  if(this_player()->query_current_room()=="players/mythos/aroom/shrinear5.c") {
  object ob;
  ob=first_inventory(environment(this_player()));
  while(ob) {
    if(ob->query_name()=="Priest") {
    write("The Priest softly incants something.....\n"+
      "He then takes out a knife and cuts the brand out of you rhand!\n");
    say("The Priest intones softly....\n"+
      "He takes out a knife and cuts out the brand!");
    call_other(user,"add_hit_point",-10);
    call_other(user,"add_spell_point",-20);
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

acer() {
  int ar;
  if(q<1) {
  destruct(present("field"));
  write("The glowing shield evaporates.\n");
  say("You see the glowing shield around "+user->query_name()+" vanish!\n");
  return 1; }
  else {
  q= q-1;
  ar=random(11);
  user->set_ac(ar);
  call_out("acer",20);
  return 1;}
return 1;}
