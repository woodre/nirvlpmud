inherit "obj/monster";

int alive;


reset(arg) {
  ::reset(arg);
  if(arg) return;
  can_kill = 0;
  set_name("dragonette");
  set_short("A little golden dragonette");
  set_long("The dragonette snaps at you as you try to examine her.\n");
  set_race("dragonette");
  set_alias("orlith");
  set_hp(20000);
  set_ac(200);
  set_wc(200);
  set_chat_chance(5);
  load_chat("The dragonette croons softly.\n");
  load_chat("A golden glow fills the room.\n");
  load_chat("The golden dragonette shifts restlessly.\n");
  load_chat("You glance over at the dragonette.\n");
  load_chat("A burst of light flashes from the dragonette's eyes.\n");
  load_chat("The little dragonette looks around with wide eyes.\n");
  load_chat("You hear a rustle as the dragonette shakes out her wings.\n");
  set_heart_beat(1);
  alive = 1;
  enable_commands();
  }

heart_beat() {
  if(!alive) {
    set_heart_beat(0);
    return; }
  ::heart_beat();
  if(!present("mistress",environment(this_object())))
    if(find_player("mistress")) {
      say("The dragonette flies off to find her mistress.\n");
      move_object(this_object(),environment(find_player("mistress")));
      tell_room(environment(this_object()),"A small dragonette arrives.\n");
    } else
      set_heart_beat(0); }

init() {
  ::init();
    add_action("silence","silence");
    add_action("destruct","dest");
    add_action("destruct","kill");
    add_action("croon","croon");
    add_action("away","send");
    add_action("pet","pet");
   }

silence(str) {
  if(str == "dragonette" || str == "orlith") {
    if(this_player()->query_real_name() == "mistress") {
    write("Orlith falls silent.\n");
    say("The little dragonette sits quietly and watches from golden eyes.\n");
    set_heart_beat(0);
    alive = 0;
    return 1; }
    write("You can't do that.\n");
  return 0; }
  }
destruct(str) {
  if(str=="dragonette"||str=="orlith" && this_player()->query_real_name() != "mistress") {
       write("Now why do you wish to harm this cute little creature?\n");
       say(this_player()->query_name() + " tries to harm the dragonette.\n");
       return 1; }
  }
away(str) {
  if(str == "orlith home") {
    if(this_player()->query_real_name() == "mistress") {
     say("The dragonette leaps into the air and flies off.\n");
     move_object(this_object(),"/players/mistress/workroom");
     alive = 0;
     set_heart_beat(0);
     return 1; }
    write("You can't do that.\n");
     return 1; }
  }

croon(str) {
  if (str == "dragonette" || str == "orlith") {
    if(this_player()->query_real_name() == "mistress") {
      write("Orlith brightens with pleasure.\n");
      alive = 1;
      set_heart_beat(1);
      return 1; }
    write("You can't do that.\n");
    return 0; }
   }


pet(str) {
  if(str == "dragonette" || str == "orlith") {
    if(this_player()->query_real_name() == "mistress") {
      write("You gently pet Orlith.\n");
      say("The dragonette croons with pleasure as Mistress pets her.\n");
      return 1; }
    write("The little dragon closes her eyes as you pet her.\n");
    say(this_player()->query_name()+" pets the little dragonette.\n");
    return 1; }
   }


id(str) {
 if(this_player()->query_real_name() != "mistress" && str == "orlith") {
    write("Only Mistress knows the dragonette's name.\n");
    return 0; }
  return (::id(str)); }

query_real_name() {
  return "orlith"; }
