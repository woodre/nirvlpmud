inherit "/players/mizan/core/monster.c";

object owner;
string owner_name;
string squish_title;
int hps;
int follow_tl;
int taken_tl;

reset(arg){
    if(find_living("mi627017723")) {
     destruct(this_object());
     return 1;
   }
   ::reset(arg);
   if(arg) return;
   set_name("squish");
   set_alias("mi627017723");
   set_level(14);
   set_hp(210);
   set_al(580);
   set_wc(18);
   set_ac(11);
   set_aggressive(0);
  move_object(clone_object("players/mizan/etheriel/items/squishweapon.c"), this_object());
  move_object(clone_object("players/mizan/etheriel/items/squisharmor.c"), this_object());
   move_object(clone_object("obj/soul"), this_object());
   squish_title="the awesome blue wombat";
   set_chat_chance(8);
   load_chat("Squish smiles happily.\n");
   load_chat("Squish dribbles on your feet.\n");
   load_chat("Squish licks you.\n");
   set_can_kill(1);
   enable_commands();
}

init() {
  ::init();
/*
  if(!taken_tl && 1==random(32)) {
    write("You are greeted by a wandering creature from this realm.\n\n"+
	"This is Squish, the blue wombat. He offers to join you as\n"+
	"a brother-in-arms and travelling companion.\n"+
	"Will you:\n\n"+
	"[1] Accept (Squish becomes your travelling companion)\n"+
	"[2] Refuse (Leave Squish be and part on separate ways)\n"+
	"[3] Attack (Attack Squish)\n\n"+
	"Type 1, 2, or 3.\n");
    input_to("decision");
    return 1;
  }
  add_action("kill_plyr","sattack");
  add_action("release_hydra","dismiss");
  add_action("status_screen","info");
  add_action("follow_toggle","sfollow");
  add_action("hydra_kickstart","skick");
  add_action("hydra_emote","semote");
  add_action("hydra_say","ssay");
  add_action("hydra_title","stitle");
*/
}

static decision(str) {
  if(!str) {
    write("You must pick 1, 2, or 3.\n");
    input_to("decision");
    return 1;
  }
  if(str == "1") {
    owner=this_player();
    owner_name=owner->query_name();
    taken_tl=1;
    say("Squish joins "+(owner->query_name())+".\n");
    tell_object(owner, "Squish is now following you.\n");
    tell_object(owner, "For a list of available commands, type 'info squish'.\n");
    this_object()->transfer_all_to("room/store");
    follow_tl=1;
    return 1;
  }
  if(str == "2") {
    write("Squish nods, and waves at you.\n");
    say((this_player()->query_name())+" declines Squish's offer.\n");
    return 1;
  }
  if(str == "3") {
    write("You attack Squish!\n");
    say((this_player()->query_name())+" attacks Squish!\n");
    this_player()->attack_object(this_object());
    this_object()->attack_object(this_player());
    return 1;
  }
  write("You must pick 1, 2, or 3.\n");
  input_to("decision");
  return 1;
}

short() {
  if(!squish_title) {
    return "Squish the awesome blue wombat";
  }
  return "Squish "+squish_title;
}

long() {
  write("This is Squish the awesome blue wombat. He seems to be permanently\n"+
	"happy, with a goofy smile locked on his face. But wait! This is\n"+
	"no _ordinary_ wombat! This is the mighty Squish!\n");
  if(follow_tl) {
  write("Squish is currently following "+(owner->query_name())+".\n");
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


    if(!owner && owner_name && 1==random(5)) {
      owner=find_player(owner_name);
      return 1;
    }
    if(follow_tl && !present(owner, room)) {
    say("Squish stumbles out.\n");
    move_object(this_object(), environment(owner));
    say("Squish stumbles in.\n");
    }


  if(attacker){
    attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
        if(1==random(11)) {
          say("Squish bites "+capitalize(attacker_name)+" in the butt!\n");
          attacker->hit_player(random(3));
        }
        if(1==random(11)) {
          say("Squish dealt a devastating blow to "+capitalize(attacker_name)+".\n");
          attacker->hit_player(random(7));
        }
      }
    }
  }
*/

/*  Configuration toggle switches */

static follow_toggle() {
  if(!follow_tl) {
    follow_tl=1;
    tell_object(owner, "**Squish** FOLLOW ON\n");
    say("Squish is now following "+(owner->query_name())+".\n");
  } else {
  follow_tl=0;
  tell_object(owner, "**Squish** FOLLOW OFF\n");
  say("Squish is not following anyone.\n");
  }
  return 1;
}

status_screen(str) {
  if(str != "squish" || !str) return 0; 
  tell_object(owner, ">>--------<< Squish's Commands >>--------<<\n\n"+
  "info squish      This screen.\n"+
  "sfollow          Toggles follow.\n"+
  "sattack <mnstr>  Commands Squish to kill something in the room.\n"+
  "stitle <str>     Allows you to change Squish's title.\n"+
  "ssay <str>       Allows Squish to say something.\n"+
  "semote <str>     Allows Squish to emote something.\n"+
  "skick            Use this command if Squish doesnt follow, even if\n"+
  "                 you set his follow on (wakes him up)\n"+
  "dismiss          Makes Squish go away.\n");
  return 1;
}

/*  Target & Protect options */

static kill_plyr(arg) {
  object ob;
  if(this_player()!=owner) {
    write("Squish ignores you.\n");
    return 1;
    }
  ob=present(lower_case(arg), environment(this_object()));
  if(!ob) {
    ob=find_living(arg);
    if(!ob) {
      tell_object(owner, "Squish looks at you and shrugs helplessly.\n");
      return 1;
    }
  }
  if(!living(ob)) {
    tell_object(owner, "Squish giggles inanely.\n");
    return 1;
  }
  say("Squish nods and turns to attack "+(ob->query_name())+".\n");
  this_object()->attack_object(ob);
  return 1;
}

static release_hydra() {
  if(this_player()!=owner) {
    write("Squish ignores you.\n");
    return 1;
  }
  say("Squish waves and trudges away.\n");
  move_object(this_object(), "room/void");
  destruct(this_object());
  return 1;
}

static hydra_title(str) {
  if(!str) return 0;
  squish_title = str;
  write("Ok.\n");
  return 1;
}

static hydra_say(str) {
  if(!str || this_player()!=owner) return 0;
  write("Ok.\n");
  say("Squish says: "+str+"\n");
  return 1;
}

static hydra_emote(str) {
  if(!str || this_player()!=owner) return 0;
  write("Ok.\n");
  say("Squish "+str+"\n");
  return 1;
}

static hydra_kickstart() {
  heart_beat();
  write("**Squish** heart beat kickstarted.\n");
  return 1;
}
