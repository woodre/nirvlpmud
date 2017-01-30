inherit "/players/mizan/core/monster.c";
#include "/players/bastion/closed/color.h"

reset(arg) 
{
    object weapon;
    ::reset(arg);
    if(arg) return;
    set_name("explodey");
    set_race("pup");
    set_short(RED + "Explodey the Pup" + OFF);
    set_level(11);
    set_hp(165);
    set_al(920);
    set_ac(15);
    set_wc(11);
    set_chance(20);
    set_chat_chance(14);
    load_chat(RED + "Explodey blinks.\n" + OFF);
    load_chat(RED + "Explodey sweats nervously.\n" + OFF);
    load_chat(RED + "Explodey peers intently around.\n" + OFF);
    set_spell_dam(25);
    set_spell_mess1(RED + "Explodey goes: Doooow!\n" + OFF);
    set_spell_mess2(RED + "Explodey swats helplessly at you.\n" + OFF);
    weapon=clone_object("players/mizan/etheriel/heals/dirtbag");
    move_object(weapon, this_object());
    move_object(clone_object("players/mizan/etheriel/items/bone"), this_object());
}

long() 
{
    write(RED + "Explodey appears to be a cartoon dog, drawn in a disjointed\n"+
    "and descontructionist way. Sweating profusely and obviously nervous\n"+
    "about something, you can only wonder what he is so paranoid about.\n" + OFF);
    if(this_player()->query_gender() == "female") {
        write(RED + "As drift closer to him, he mutters but a single phrase...\n"+
          "'Please dont kiss me...'\n" + OFF);
    }
}

init() {
  add_action("kiss","kiss");
  ::init();
}

kiss(str) {
  object ob;
  if(!str || str != "explodey") return 0;
  if(this_player()->query_gender() != "female") {
    write("You kiss Explodey.\n");
    say((this_player()->query_name()) + " kisses Explodey.\n");
    say(RED + "Explodey goes: Ack.\n" + OFF);
    return 1;
  } else {
  write("You kiss Explodey... and he explodes!\n");
  say((this_player()->query_name()) + " kisses Explodey.\n");
  say("Explodey is blown to bits.\n");
  ob=first_inventory(environment());
  while(ob) {
    object oc;
    oc=ob;
    ob=next_inventory(ob);
    if(living(oc)) {
      say(RED + (oc->query_name()) + " is zokked by the blast.\n");
      this_object()->attack_object(oc);
      if(oc->query_level() > 15) oc->hit_player(30);
      oc->hit_player(random(15));
      oc->run_away();
    }
  }
  this_object()->transfer_all_to("room/store");
  destruct(this_object());
  return 1;
 }
 return 0;
}

