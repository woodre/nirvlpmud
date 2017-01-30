#include "/players/mizan/closed/Tracking-D.c"
#include <esc.h>
#define BLINK esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"
#define UNBLINK esc+"[0m"
inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("Sarawak");
   set_race("sarawak");
   set_short("A hungry-looking Sarawak");
   set_long("Sarawak looks like a smaller version of Spuck. It seems to\n"+
   "like engulfing things, almost anything, so you should be careful when\n"+
   "you stay nearby. Don't hover too close or linger around too long or\n"+
   "your fate may match that of the poor Spuckball it just sucked up!\n");
   set_level(15);
   set_hp(225);
   set_al(-670);
   set_wc(20);
   set_ac(12);
   set_chance(10);
   set_spell_dam(15);
   set_spell_mess1("Sarawak "+BLINK+"noggles"+UNBLINK+" you uncontrollably!");
   set_spell_mess2("You are caught in the shrapnel of Sarawak exploding.");
   set_chat_chance(20);
load_chat("Sarawak makes a low, throbbing beat.\n");
load_chat("Sarawak bobbles.\n");
load_chat("Sarawak appears to be hungry.\n");
   gold=clone_object("obj/money");
   gold->set_money(1);
   move_object(gold,this_object());
}

init() {
  remove_call_out("ingestion");
   call_out("ingestion", 10 + random(55));
    if(this_player() && environment(this_player()) &&
    environment(this_player()) == this_object()) {
    add_action("tickle","tickle");
}
}

ingestion() {
  object ob;
  ob=first_inventory(environment(this_object()));
  while(ob) {
    object oc;
    oc=ob;
    oc=next_inventory(ob);
    if(living(oc) && 1 == random(5) && oc->query_level() > 5) {
      if(oc != this_object()) {
      say((oc->query_name())+" is absorbed by Sarawak.\n");
      move_object(oc,this_object());
      call_out("digestion", (20 + random(20)));
      return 1;
         }
    }
  }
   call_out("ingestion", (10 + random(10)));
  return 1;
}

digestion() {
  object ob2;
  ob2=first_inventory(this_object());
  while(ob2) {
    object oc2;
    oc2=ob2;
    oc2=next_inventory(ob2);
    if(living(oc2)) {
      say((oc2->query_name())+" is digested by Sarawak.\n");
        if(oc2->query_interactive()) {
      oc2->save_me();
        }
      destruct(oc2);
    }
  }
  say("Sarawak burps.\n");
  return 1;
}

query_realm() { return "NT"; }
tickle() {
  int slim;
  slim = random(10);
  if(slim < 2) {
    write("You tickle the sarawak and it spews you out!\n");
  this_player()->move_player("X#players/mizan/etheriel/ROOMS/spuck.c");
    return 1;
  } else return 0;
}
