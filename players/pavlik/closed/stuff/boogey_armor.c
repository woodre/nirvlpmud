#include <ansi.h>
#define dream_wait 120
inherit "obj/armor";
int dream_next;

reset(arg) {
 if(arg) return;
  set_ac(4);
  set_short(GRN+"Boogey Armor"+NORM);
  set_alias("boogey armor");
  set_long("This strange looking plate armor once belonged to the horried\n"+
  "Boogey Man!  Now it is all yours.  The Boogey Man used\n"+
  "this enchanted armor to <haunt> his enemies.\n");
  dream_next=time();
  set_type("armor");
  set_weight(1);
  set_value(20000);
  set_save_flag(0);
}

init() {
 ::init();
  add_action("dream","haunt");
}
dream(str) {
   object target, mon;
 if(!str) {
     write("What do you want to haunt?\n");
       return 1;
     }

  if(!present(str, environment(this_player()))) {
    write(capitalize(str)+" is not here.\n");
       return 1;
     }

  if(dream_next > time()) {
   write("You must give the Nightmare time to regenerate.\n");
      return 1;
    }

  if(!this_player()->query_attack()){
    write("You must be in battle to use this command.\n");
    return 1;
    }

   target = present(str, environment(this_player()));
   if(find_player(str)) {
  write("This poor fool has enough problems.\n");
      return 1;
    }

  if(present("nightmare", environment(this_player()))) {
   write("You have already summoned the nightmare!\n");
     return 1;
     }


  write(
  "You summon a horried "+HIR+"Nightmare"+NORM+" from a dark plane.\n"+
  "The nether-demon springs from the ground and joins the battle!\n");
  say(capitalize(this_player()->query_name())+
  " summons a "+HIR+"Nightmare"+NORM+" to haunt his enemy.\n"+
  "A terrible nether-demon springs from the ground and joins the battle!\n");
   mon = clone_object("players/pavlik/closed/stuff/mare.c");
   move_object(mon, environment(this_player()));
   mon->attacked_by(target);
   mon->attack_object(target);
      dream_next = time() + dream_wait;
      return 1;
 }
