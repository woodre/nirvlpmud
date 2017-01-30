inherit "players/illarion/high/mon/imm_mon";
#include "/players/illarion/dfns.h"


void reset(int arg) {
  if(arg) return;
  ::reset(arg);
  
  set_name("Kalas");
  set_alias("kalas");
  set_alt_name("man");
  set_race("immortal");
  set_gender("male");
  set_immortal(1);
  set_weapon_path(HOBJ+"kexcalibur");
  set_attacks(5);
  set_x_attack_chance(75);
  set_level(24);
  set_al(-900);
  set_wc(40);
  set_ac(30);
  set_hp(3333);
  set_deathblow_chance(100);
  set_deathblow_health(15);
  add_emote("deathblow",
  "$MN$ knocks you to the ground, reverses $MP$ sword, and stabs you in the chest!",
  "$MN$ knocks $TN$ to the ground, reverses $MP$ sword, and stabs $TN$ in the chest!");
  set_dodge_chance(20);
  add_emote("dodge","$MN$ deftly steps out of the way of your attack.","$MN$ deftly steps out of the way of $TN$'s attack.");
  set_counter_chance(33);
  add_emote("counter","$MN$ snarls hoarsely and unloads a powerful counterattack!","$MN$ snarls hoarsely and unloads a powerful counterattack at $TN$.");
  set_attack_weakest(1);
  add_emote("change_attack","$MN$ turns to attack you with a hoarse but savage snarl!",
                            "$MN$ turns to attack $TN$ with a hoarse but savage snarl!");
  set_short("A dangerous looking, sandy-haired man");
  set_long(
"This man's gaze is as cold as ice, and at least as unfriendly.  He seems\n"+
"aloof from all around him, but completely in control at the same time.  He\n"+
"moves with the grace and assurance of a master warrior.  His shoulder-\n"+
"length sandy-colored hair and neatly-cropped mustache do seem a a little\n"+
"out of date, but it's not something many people would mention to him.\n"+
"A black scarf is wound tightly around his neck.\n");
  add_chat_response("hello","The man glares and doesn't respond.");
  add_chat_response("name",
    "In a horse voice, the man snarls, \"None of your business!\"\n");
  add_chat_response("immortal",
    "In a horse voice, the man demands, \"Are you looking for trouble?\"\n");
  add_chat_response("fight",
    "The man's only answer is an insulting snarl.\n");
  add_chat_response("duncan",
    "The man almost smiles, though there is nothing friendly in the expression.\n"+
    "\"MacCleod took my voice,\" he rasps harshly, \"But he will soon pay.\"\n");
}
attack_object(ob) {
  if(ob == this_object()) {
    tell_room(environment(),"Kalas refuses to fight himself.\n");
    return;
  }
  return ::attack_object(ob);
}
attacked_by(ob) {
  if(ob==this_object()) {
    tell_room(environment(),"Kalas refuses to fight himself.\n");
    stop_fight();
    return;
  }
  return ::attacked_by(ob);
}
