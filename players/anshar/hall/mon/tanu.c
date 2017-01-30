#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
inherit "obj/monster";
int Y;

reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("tanu");
  set_short("A man with dark haunted eyes");
  set_alias("man");
  set_race("god");
  set_long("     An aura of darkness surrounds this small man. His gaze shifts\n"+
           "nervously from one thing to the next. His deep brown eyes pass\n"+
           "over you with a look of distrust, and perhaps even contempt that\n"+
           "crosses his creased face. The look is gone so quickly you fear\n"+
           "you might be mistaken. There is no mistaking, though, the ease\n"+
           "at which he seems to dismiss you as an obvious threat.\n");
  set_hp(600);
  set_level(20);
  set_al(-1000);
  set_wc(40);
  set_ac(30);
  set_aggressive(0);
/*  call_out("rebeat",10); */

  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("Tanu glares at you as he looks about the room.\n");
  load_chat("You hear a snicker of disdain as Tanu looks you over.\n");
  load_a_chat("Tanu leaps around nimbly, taking advantage of your every weakness.\n");

  set_chance(30);
  set_spell_dam(50);
  set_spell_mess1("Tanu stabs deep into his opponent's chest with a dagger of "+BLU+"blue energy"+NORM+".\n");
  set_spell_mess2("The blade of "+BLU+"blue energy"+NORM+" sizzles as it presses into you. Pain and cold\n"+
    "sear you to the marrow.\n");

}
init() {
  ::init();
  add_action("take_ring","take");
  add_action("take_ring","steal");
    }

take_ring(str) {
    if(!str || str != "ring") { notify_fail("What?\n");
    return 1; }
    if(Y==0 || this_object()->query_attack()); {
    tell_room(environment(this_object()),
    "The ring is ripped from Tanu's finger and disintegrates immediately\n");
    Y++;
    return 1; }
    tell_room(environment(this_object()),
    "You fail.");
    return 1; }    

heart_beat() {
  ::heart_beat();
    if(this_object()->query_hp() < 600) 
	heal_tanu();
return 1;
}

heal_tanu() {
  int X;

  X = random(12);
  if(Y==0) {
  call_other(this_object(),"heal_self",X);
  if(X > 8) {
    say("Tanu touches a ring, and his wounds seem to close by themselves.\n");
    }
  return 1;
  }
 return 1;
}
