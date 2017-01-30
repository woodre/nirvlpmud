inherit "/players/mizan/core/monster.c";

object owner;
string owner_name;
string squish_title;
int hps;
int ok_pet;
int follow_tl;
int taken_tl;

reset(arg){
   if(find_living("mi627017744")) {
     destruct(this_object());
     return 1;
   }
   if(1==random(4)) {
   ok_pet=1;
   }
   ::reset(arg);
   if(arg) return;
   set_name("colin");
   set_race("wombat");
   set_long("This is Colin the dopey wombat. He is slightly smaller than most other\n"+
	"wombats, but he was the runt so leave him alone!\n");
   set_alias("mi627017744");
   set_level(11);
   set_hp(165);
   set_al(305);
   set_wc(15);
   set_ac(9);
   set_aggressive(0);
   set_chat_chance(8);
   load_chat("Colin appears startled.\n");
   load_chat("Colin bobbles uncontrollably.\n");
   load_chat("Colin grins idiotly.\n");
   set_can_kill(1);
   enable_commands();
   move_object(clone_object("players/mizan/etheriel/heals/zokball.c"), this_object());
   move_object(clone_object("players/mizan/etheriel/heals/cheese.c"), this_object());
   squish_title="the dopey wombat";
}

init() {
  ::init();
/*
  if(!taken_tl && 1==random(25) && !present("wombat", environment(this_object()))
    && (this_player()->query_level()) < 6 && ok_pet) {
    write("You are greeted by a wandering creature from this realm.\n\n"+
	"This is Colin, the dopey wombat. He offers to join you as\n"+
	"a brother-in-arms and travelling companion.\n"+
	"Will you:\n\n"+
	"[1] Accept (Colin becomes your travelling companion)\n"+
	"[2] Refuse (Leave Colin be and part on separate ways)\n"+
	"[3] Attack (Attack Colin)\n\n"+
	"Type 1, 2, or 3.\n"+
	"->>");
    input_to("decision");
    return 1;
  }
  add_action("kill_plyr","cattack");
  add_action("release_hydra","dismiss");
  add_action("status_screen","cquishinfo");
  add_action("follow_toggle","cfollow");
  add_action("hydra_kickstart","ckick");
  add_action("hydra_emote","cemote");
  add_action("hydra_say","csay");
  add_action("hydra_title","ctitle");
*/
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
    taken_tl=1;
    set_hp(72);
    say("Colin joins "+(owner->query_name())+".\n");
    tell_object(owner, "Colin is now following you.\n");
    tell_object(owner, "For a list of available commands, type 'colininfo'.\n");
    this_object()->transfer_all_to("room/store");
    follow_tl=1;
    return 1;
  }
  if(str == "2") {
    write("Colin nods, and waves at you.\n");
    say((this_player()->query_name())+" declines Colin's offer.\n");
    return 1;
  }
  if(str == "3") {
    write("You attack Colin!\n");
    say((this_player()->query_name())+" attacks Colin!\n");
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
    return "Colin the dopey blue wombat";
  }
  return "Colin "+squish_title;
}

long() {
 ::long();
  if(follow_tl) {
  write("Colin is currently following "+(owner->query_name())+".\n");
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
    say("Colin stumbles out.\n");
    move_object(this_object(), environment(owner));
    say("Colin stumbles in.\n");
    }


  if(attacker){
    attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
        if(1==random(19)) {
          say("Colin smacks "+capitalize(attacker_name)+" across the face!\n");
          attacker->hit_player(random(3));
        }
      }
  }
}
*/


/*  Configuration toggle switches */

static follow_toggle() {
  if(this_player()->query_real_name() != owner_name) return;
  if(!follow_tl) {
    follow_tl=1;
    tell_object(owner, "**Colin** FOLLOW ON\n");
    say("Squish is now following "+(owner->query_name())+".\n");
  } else {
  follow_tl=0;
  tell_object(owner, "**Colin** FOLLOW OFF\n");
  say("Colin is not following anyone.\n");
  }
  return 1;
}

static status_screen() {
  if(this_player()->query_real_name() != owner_name) return;
  tell_object(owner, ">>--------<< Colin's Commands >>--------<<\n\n"+
  "colininfo       This screen.\n"+
  "cfollow          Toggles follow.\n"+
  "cattack <mnstr>  Commands Colin to kill something in the room.\n"+
  "ctitle <str>     Allows you to change Colin's title.\n"+
  "csay <str>       Allows Colin to say something.\n"+
  "cemote <str>     Allows Colin to emote something.\n"+
  "ckick            Use this command if Colin doesnt follow, even if\n"+
  "                 you set his follow on (wakes him up)\n"+
  "dismiss          Makes Colin go away.\n");
  return 1;
}

/*  Target & Protect options */

static kill_plyr(arg) {
  object ob;
  if(this_player()->query_real_name() != owner_name) return;
  ob=present(lower_case(arg), environment(this_object()));
  if(!ob) {
    ob=find_living(arg);
    if(!ob) {
      tell_object(owner, "Colin is left in a steep bogglement.\n");
      return 1;
    }
  }
  if(!living(ob)) {
    tell_object(owner, "Colin bobbles at you.\n");
    return 1;
  }
  say("Colin turns to attack "+(ob->query_name())+".\n");
  this_object()->attack_object(ob);
  return 1;
}

static release_hydra() {
  if(this_player()->query_real_name() != owner_name) return;
  say("Colin waves and waddles away.\n");
  move_object(this_object(), "room/void");
  destruct(this_object());
  return 1;
}

static hydra_title(str) {
  if(this_player()->query_real_name() != owner_name || !str) return;
  squish_title = str;
  write("Ok.\n");
  return 1;
}

static hydra_say(str) {
  if(this_player()->query_real_name() != owner_name || !str) return;
  write("Ok.\n");
  say("Colin whispers: "+str+"\n");
  return 1;
}

static hydra_emote(str) {
  if(this_player()->query_real_name() != owner_name || !str) return;
  write("Ok.\n");
  say("Colin "+str+"\n");
  return 1;
}

static hydra_kickstart() {
  if(this_player()->query_real_name() != owner_name) return;
  heart_beat();
  write("**Colin** heart beat kickstarted.\n");
  return 1;
}
