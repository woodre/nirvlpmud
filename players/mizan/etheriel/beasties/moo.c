#define HOME "/players/mizan/etheriel/ROOMS/moo"

inherit "/players/mizan/core/monster.c";

object owner;
string owner_name;
string squish_title;
int hps;
int ok_pet;
int follow_tl;
int taken_tl;
int call_flag_tl;

is_pet() { return 1; }

reset(arg){
   if(!arg) {
     move_object(this_object(), HOME);
   }
   if(1==random(3)) {
   ok_pet=1;
   }
   ::reset(arg);
   if(arg) return;
   set_name("moo");
   set_long("This is Moo the happy wombat. He likes to eat grass, sleep, and\n"+
	"dig holes. Sounds like a pretty harmless animal? I think not!\n"+
	"This is the most feared of the wombats, Moo.\n");
   set_alias("mi627017726");
   set_race("wombat");
   set_level(15);
   set_hp(225);
   set_al(301);
   set_wc(20);
   set_ac(12);
   set_aggressive(0);
   set_chat_chance(8);
   load_chat("Moo chomps on some dirt.\n");
   load_chat("Moo burps.\n");
   load_chat("Moo grins biggly.\n");
   set_can_kill(1);
   enable_commands();
   move_object(clone_object("players/mizan/etheriel/items/cardboard-tube.c"), this_object());
   move_object(clone_object("players/mizan/etheriel/items/styrofoam-helm.c"), this_object());
   squish_title="the happy wombat";
}

init() {
  if(!taken_tl && 1==random(8) && !present("wombat", environment(this_object()))
    && (this_player()->query_level()) < 10 && ok_pet && !call_flag_tl) {
 /*
if(this_player()->query_real_name() == "mizan" && !call_flag_tl && ok_pet && !taken_tl) {
 */
    write("You are greeted by a wandering creature from this realm.\n\n"+
	"This is Moo, the happy wombat. He offers to join you as\n"+
	"a brother-in-arms and travelling companion.\n"+
	"Will you:\n\n"+
	"[1] Accept (Moo becomes your travelling companion)\n"+
	"[2] Refuse (Leave Moo be and part on separate ways)\n"+
	"[3] Attack (Attack Moo)\n\n"+
	"Type 1, 2, or 3.\n"+
	"->>");
    call_flag_tl=1;
    input_to("decision");
    return 1;
  }
  if(owner_name) this_object()->heart_beart();
  add_action("kill_plyr","mkill");
  add_action("release_hydra","dismiss");
  add_action("status_screen","mooinfo");
  add_action("follow_toggle","mfollow");
  add_action("hydra_kickstart","mkick");
  add_action("hydra_emote","memote");
  add_action("hydra_say","msay");
  add_action("hydra_title","mtitle");
}

static decision(str) {
  if(!str) {
    write("You must pick 1, 2, or 3.\n"+"->>");
    input_to("decision");
    return 1;
  }
  if(str == "1") {
    owner=this_player();
    owner_name=this_player()->query_real_name();
    this_object()->set_hp(130);
    taken_tl=1;
    say("Moo joins "+(owner->query_name())+".\n");
    tell_object(owner, "For a list of available commands, type 'mooinfo'.\n");
    this_object()->transfer_all_to("room/store");
    follow_tl=1;
    return 1;
  }
  if(str == "2") {
    write("Moo nods, and goes along his business.\n");
    say((this_player()->query_name())+" declines Moo's offer.\n");
    return 1;
  }
  if(str == "3") {
    write("You attack Moo!\n");
    write("Oh, you cheap bastard!\n");
    say((this_player()->query_name())+" attacks Moo!\n");
    this_player()->attack_object(this_object());
    this_object()->attack_object(this_player());
    return 1;
  }
  write("You must pick 1, 2, or 3.\n"+"->>");
  input_to("decision");
  return 1;
}

short() {
  if(!squish_title) {
    return "Moo the happy wombat";
  }
  return "Moo "+squish_title;
}

long() {
  ::long();
  if(follow_tl) {
  write("Moo is currently following "+(owner->query_name())+".\n");
  }
}

/*
heart_beat() {
  int dam;
  object attacker,ob,room;
  string attacker_name;
  ::heart_beat();
  hps=this_object()->query_hp();
  room=environment(this_object());
  attacker=this_object()->query_attack();

    if(!taken_tl && !owner) {
      string feedme;
      feedme=call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
      command(feedme, this_object());
    }


    if(!owner && taken_tl && owner_name) {
      owner=find_player(owner_name);
      if(!owner) return 1;
    }

    if(follow_tl && !present(owner, room)) {
    say("Moo stumbles out.\n");
    move_object(this_object(), environment(owner));
    say("Moo stumbles in.\n");
    }

  if(this_object()->query_hp() < 50 && 1 == random(4) && !taken_tl) { 
    say("Moo flees in panic!\n");
    this_object()->run_away();
  }


  if(attacker){
    attacker_name=attacker->query_name();
      if(present(attacker_name,environment(this_object()))){
        if(1==random(11)) {
          say("Moo pounds "+capitalize(attacker_name)+".\n");
          checked_hit(3);
        }
        if(1==random(11)) {
          say("Moo bites "+capitalize(attacker_name)+"!\n");
          checked_hit(5);
        }
      }
  }
}
*/


/*  Configuration toggle switches */

static follow_toggle() {
  if(this_player() != owner) return;
  if(!follow_tl) {
    follow_tl=1;
    tell_object(owner, "Moo is now following you.\n");
    say("Moo is now following "+(owner->query_name())+".\n");
  } else {
  follow_tl=0;
  say("Moo is not following anyone.\n");
  }
  return 1;
}

static status_screen() {
  if(this_player() != owner) return;
  tell_object(owner, ">>--------<< Moo's Commands >>--------<<\n\n"+
  "mooinfo          This screen.\n"+
  "mfollow          Toggles follow.\n"+
  "mkill <mnstr>    Commands Moo to kill something in the room.\n"+
  "mtitle <str>     Allows you to change Moo's title.\n"+
  "msay <str>       Allows Moo to say something.\n"+
  "memote <str>     Allows Moo to emote something.\n"+
  "mkick            Use this command if Moo doesnt follow, even if\n"+
  "                 you set his follow on (wakes him up)\n"+
  "dismiss          Makes Moo go away.\n");
  return 1;
}

/*  Target & Protect options */

kill_plyr(arg) {
  object ob;
  if(this_player() != owner) return;
  ob=present(lower_case(arg), environment(this_object()));
  if(!ob) {
    ob=find_living(arg);
    if(!ob) {
      tell_object(owner, "Moo peers at you quizzically.\n");
      return 1;
    }
  }
  if(!living(ob)) {
    tell_object(owner, "Moo is left in a steep bogglement.\n");
    return 1;
  }
  if(!ob->query_npc()) {
    say("Moo sniffs " + (ob->query_name()) + " from head to toe.\n");
    write("Moo decides it's not worth attacking " + (ob->query_name()) + " .\n");
    return 1;
  }
  say("Moo turns to attack "+(ob->query_name())+".\n");
  this_object()->attack_object(ob);
  return 1;
}

static release_hydra() {
  if(this_player() != owner) return;
  say("Moo waves and burrows into the ground.\n");
  move_object(this_object(), "room/void");
  destruct(this_object());
  return 1;
}

hydra_title(str) {
  if(this_player() != owner) return;
  squish_title = str;
  write("Ok.\n");
  return 1;
}

hydra_say(str) {
  if(this_player() != owner) return;
  write("Ok.\n");
  say("Moo says: "+str+"\n");
  return 1;
}

hydra_emote(str) {
  if(this_player() != owner) return;
  write("Ok.\n");
  say("Moo "+str+"\n");
  return 1;
}

hydra_kickstart() {
  if(this_player() != owner) return 0;
  heart_beat();
  write("You kick Moo in the belly, and his eyes nearly pop out of his head.\n"+
  "At least he's alert now.\n");
  return 1;
}

checked_hit(arg) {
  int a_hp,a_dam;
  object a_attack;
  a_attack=this_player()->query_attack();
  if(a_attack) {
    a_hp=a_attack->query_hp();
    a_dam=random(arg);
    if(a_hp < a_dam || a_hp == a_dam) a_dam = a_hp - 1;
    a_attack->hit_player(a_dam);
  }
}

