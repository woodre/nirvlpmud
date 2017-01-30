#include "/players/mythos/closed/guild/def.h"
#define tgg this_player()->query_possessive()

inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("egg");
  set_short("A strange looking egg");
  set_long("A wierd looking egg.  It is a dark "+GRN+"green"+NORM+
  " color.\n"+"Legend says that blood must flow to hatch it.\n");
  set_weight(2);
  set_value(10);
}
init() { ::init();
 /*  add_action("flow_blood","flow"); */
  add_action("invoke","invoke");
}

flow_blood(str) {
  object mon;
  if(str == "blood")  {
  write("You cut your finger and let a few drops of blood drip\n"+
      "down onto the egg.\n");
  say(tpn+" cuts "+tgg+" and finger and lets the blood drip onto the egg.\n");
  write(HIR+"Drip\n\n");
  write("   Drip\n\n");
  write("      Drip\n\n");
  write("         Drip\n\n");
  write(NORM+"The blood soon covers the egg....THEN....\n");
  write("\n        s  ~  m  ~  o  ~  k  ~  e\n\n");
  write("\n When it all clears you see the egg gone...and in its place is a monster!\n");
  say("\n\n      s  ~  m  ~  o  ~  k  ~  e\n\n");
  say("When it clears.... a monster is in the place where the egg was!\n");
  mon=clone_object("/players/mythos/amon/tochau.c");
  if(!living(environment(this_object()))){
  move_object(mon,environment(this_object()));
  destruct(this_object());  return 1;}
  move_object(mon, environment(environment(this_object())));
  destruct(this_object());
  return 1;  }
}

invoke() {
 if(pp) {
   if(random(2)==0) {
     write("You feel powerful!\n"+
           "Blood flows from your fingers as the egg cuts into you.\n"+
           "You feel a great power descend upon you!\n"+
           "The Symbols of Power seep into you!\n");
     pp->set_pow(1);
     pp->save_dark();
     command("uu",tp);
     write("To use type <symbol <type>>\n");
     write_file("/players/mythos/closed/guild/task_spell",
    ctime(time())+" "+(this_player())->query_real_name()+
    "  symbol\n");
   }
   else {
   write("Chance is against you!\nThe egg flares!\n");
   tp->zap_object(tp);
   write_file("/players/mythos/closed/guild/task_spell",
    ctime(time())+" "+(this_player())->query_real_name()+
    "  DIED\n");
   }
   destruct(this_object());
   return 1;}
}
