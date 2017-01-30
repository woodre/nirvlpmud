/* S5-patched
 *
 */
 
#define CHUNK 16
#define SAVE_DIR "players/mizan/closed/s5/s5save/"
#define LOG_DIR "/players/mizan/logs/S5"
#define ESP_HOME_DIR "open"
#define FILE_LEADER "/."
#define FILE_PREFIX "/"
#define FILE_PREFIX2 ""
#define HOME "/players/mizan/dirt"
#define HOME_DIR "log"
#define CHR_TERMN '/'
#define MASTER_R "mizan"
#define PLAYERSOUL "players/mizan/closed/s5/psl.c"
#define CONTROLLER "players/mizan/closed/s5/scom.c"
 
inherit "obj/monster";
 
static object targetted;
static object owner;
static int follow_tl;
static int hunting_tl;
static int remote_tl;
static int log_attacks_tl;
static int ok_plyr_attack_tl;
static int ok_wiz_attack_tl;
static int ok_area_attack_tl;
static int invis_tl;
static int espion_tl;
static int espion_log_tl;
static int invisochk_tl;
string summer_pretitle;
string summer_title;
string summer_al_title;
string summer_gender;
string espion_path;
string owner_name;
string invis_name;
string curr_name;
string lcase_curr_name;
string curr_path;
static string mo_fle;
static int mo_lne;
static string descriptor_temp;
string cmd_prompt;
string exit_mess;
string enter_mess;
string descriptor;
int access_lvl;
string sg_name;
 
lv_tell(str) {
  tell_object(this_object(), "[lv] " + str);
  return 1;
}
 
move_player(dir_dest) {
  string dir, dest;
  object ob;
  int is_light;
  if(!dir_dest) return 0;
  if(sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
    lv_tell("Move to bad dir/dest\n");
    return;
  }
  hunting_time -= 1;
  if(hunting_time == 0) {
  if(hunter) call_other(hunter, "stop_hunter");
    hunter = 0;
    hunted = 0;
  }
  if(attacker_ob && present(attacker_ob)) {
    hunting_time = 10;
    lv_tell("You are now hunted by " + (attacker_ob->query_name()) + ".\n");
    hunter = attacker_ob;
  }
  is_light = set_light(400);
  if(is_light < 0) is_light = 0;
  if(dir == "X" && !query_invis()) say(cap_name + " " + exit_mess + ".\n");
  else if(is_light)
  say(cap_name + " " + exit_mess + " " + dir + ".\n");
  move_object(this_object(), dest);
  is_light = set_light(400);
  if(is_light < 0) is_light = 0;
  lv_tell(dest + "\n");
  if(!enter_mess) enter_mess = "arrives";
  if(!query_invis() && dir == "X") say(cap_name + " " + enter_mess + ".\n");
    else if(is_light) say(cap_name + " " + enter_mess + ".\n");
  if (hunted && present(hunted)) attack_object(hunted);
  if (!is_light) lv_tell("IT IS DARK.\n");
  is_light = set_light(1);
  ob = environment(this_object());
  call_other(ob, "long", 0);
  ob = first_inventory(ob);
  while(ob) {
    if (ob != this_object()) {
      string short_str;
      short_str = "[" + creator(ob) + "]";
      if(!creator(ob)) short_str = "[LPMud]";
      if(strlen(short_str) < 7) {
        short_str = short_str + "\t\t";
      } else {
        short_str = short_str + "\t";
      }
      if(call_other(ob, "short")) {
        short_str = short_str + call_other(ob, "short");
        write(short_str + ".\n");
      }
        else write("[IV]\t\t[" + object_name(ob) + "].\n");
    }
    ob = next_inventory(ob);
  }
}
 
test_if_any_here()
{
    return 1;
}

attack_object(arg)
{
    if(arg && arg->query_real_name() == "mizan")
        return;
    else
        ::attack_object(arg);
}

transfer_all_to(dest) {
  write("I think not.\n");
  lv_tell((this_player()->query_name()) + " tried to call 'transfer_all_to(" + dest + ")'.\n");
  return 1;
}
 
show_stats() 
{
  write("You cannot scan this creature, for some reason.\n");
  return 1;
}
 
query_level() 
{
  return 100;
}
 
query_value() { return 0; }
 
get() { return 0; }
 
stop_hunter() {
  hunter = 0;
  lv_tell("You are no longer hunted.\n");
}
 
force_us(cmd) {
  lv_tell(call_other(this_player(), "query_name") + " tried forcing you to '" + cmd + "'.\n");
  return 1;
}
 
add_money(m) {
  money = money + m;
}
 
frog_curse(arg) {
  if(arg) {
    lv_tell((this_player()->query_name()) + " tried turning you into a frog.\n");
    return 1;
  }
}
 
run_away() {
   lv_tell((this_player()->query_name()) + " tried calling 'run_away()'.\n");
}
 
checked_say(str) {
  if(query_invis()) return;
  say(str);
}
 
query_version() {
  return "[Version 5]";
}
 
query_light() {
  return 400;
}
 
query_invis() {
  if(invis_tl) {
    return 999;
  } else {
  return 0;
  }
}

query_npc() {
  return 1;
}
 
reset(arg){
   object moolah;
   owner=find_player(MASTER_R);
     if(!owner) {
       write_file(LOG_DIR, (this_player()->query_real_name())+">> Tried to clone S5.\n");
       validate();
       destruct(this_object());
       return 1;
     }
   if(!restore_object(SAVE_DIR + MASTER_R)) {
 
/* Default variables */
 
     follow_tl=1;
     owner_name=owner->query_real_name();
     invis_name="Someone";
     lcase_curr_name="summerhead";
     curr_name="Summerhead";
     curr_path="log";
     enter_mess="fades into view";
     exit_mess="fades from view";
     summer_pretitle="";
     summer_title="the happy destroyer (S5!)";
     summer_al_title="nice";
     summer_gender="male";
     espion_path = "/open/SCAPTURE";
     access_lvl=1;
     cmd_prompt="**";
   }
   ::reset(arg);
   if(arg) return;
   set_level(100);
   set_hp(2147483647);
   set_al(850);
   set_wc(65);
   set_ac(228);
   move_object(clone_object("obj/soul"), this_object());
 
/*
   set_can_kill(1);
 */
 
   enable_commands();
   set_heart_beat(1);
   wiz_init();
}
 
query_guild_rank() { return 100; }
query_guild_name() { return sg_name; }
query_sp() { return 800600; }
query_msp() { return 800600; }
query_hp() { write("UNKNOWN "); }
query_real_hp() { return hit_point; }

init() {
  ::init();
  if(invis_tl) {
    set_name(invis_name);
  } else {
    set_name(lcase_curr_name);
  }
    add_action("dest","dest");
    add_action("dest","destruct");
    add_action("dest","fry");
    add_action("fingerme", "finger");
 
    add_action("help_status","sstatus");
    add_action("help_status","ss");
    add_action("help_player_coms","scommands");
    add_action("help_player_coms2","scommands2");
    add_action("help_toggle_coms","stoggles");
    add_action("save_image","ssave");
    add_action("kickstart_summer","skick");
    add_action("attack_nuclear","snuclear");
    add_action("attack_freeze_plyr","sfreeze");
    add_action("attack_kill_plyr","skill");
    add_action("attack_stop","scalm");
 
    add_action("summer_release","sdismiss");
    add_action("summer_do","scom");
    add_action("summer_say","ssay");
    add_action("summer_emote","se");
    add_action("summer_tell","stell");
    add_action("summer_promote","spromote");
    add_action("summer_inven","si");
    add_action("summer_give","sgive");
    add_action("summer_get","sget");
 
    add_action("toggle_invisocheck","sincheck");
    add_action("toggle_invisocheck","sic");
    add_action("toggle_invis","sinvis");
    add_action("toggle_follow","sfollow");
    add_action("toggle_follow","sf");
    add_action("toggle_log","slog");
    add_action("toggle_pk","spk");
    add_action("toggle_wk","swk");
    add_action("toggle_area_attack","saa");
 
    add_action("desc_name","sname");
    add_action("desc_invis_name","sinvisname");
    add_action("desc_guild_name","sgn");
    add_action("desc_setmin","ssetmin");
    add_action("desc_setmout","ssetmout");
    add_action("desc_pretitle","spretitle");
    add_action("desc_title","stitle");
    add_action("desc_al_title","sal_title");
    add_action("desc_gender","sgender");
    add_action("desc_desc","sdescribe");
  if(espion_tl) {
#ifndef __LDMUD__
add_action("espion"); add_xverb("");
#else
add_action("espion", "", 3);
#endif
  }
  if(this_player()->query_level() > 20) wiz_init();
}
 
wiz_init() {
    add_action("help_wiz_coms","swizhelp");
 
    add_action("attack_banish_plyr","sbanish");
    add_action("attack_delete_plyr","sdelete");
    add_action("toggle_esp","sesp");
    add_action("toggle_esp_log","sesplog");
    add_action("toggle_remote","sremote");
 
    add_action("desc_esp_filename","sespfile");
    add_action("desc_cmd_prompt","sprompt");
    add_action("desc_version","sversion");
 
    add_action("summer_clone","sclone");
    add_action("summer_protect","sprotect");
    add_action("summer_cat","scat");
    add_action("summer_ls","sls");
    add_action("summer_tail","stail");
    add_action("summer_chdir","scd");
    add_action("summer_more","smore");
    add_action("summer_dest","sdest");
    add_action("summer_leave","sbod");
}
 
tell_owner(str) {
  if(!str || !owner || !interactive(owner)) return 0;
  tell_object(owner, cmd_prompt + curr_name + cmd_prompt + str);
  return 1;
}
 
find_it(str) {
  object oc;
  oc=find_player(str);
  if(!oc) {
    oc=find_living(str);
    if(!oc) {
      oc=find_object(str);
      if(!oc) return 0;
    }
  }
  return oc;
}
 
dest(str){
  if(!str || str !=lcase_curr_name || str == curr_name) return 0;
  if(this_player()->query_real_name() == owner_name) {
    destruct(this_object());
    return 1;
  }
  tell_owner((this_player()->query_real_name()) +
    " tried to dest " + curr_name + ".\n");
  write("Ok.\n");
  return 1;
}
 
id(str) {
  if(invis_tl) { return invis_name; }
  return str == lcase_curr_name || str == curr_name;
}
 
short() {
  if(invis_tl) {
  return 0;
  } else {
  return summer_pretitle + curr_name + " " + summer_title + " (" + summer_al_title + ")";
  }
}
 
long() {
  if(invis_tl) {
    return 0;
  }
  write((this_player()->query_name())+" looks at " + curr_name + ".\n");
  write(short()+" ("+ summer_gender + ").\n");
  write("==> happy dragon\n");
  if(descriptor) {
    write(descriptor);
  }
  write("\n" + curr_name + " is 77 feet 4 inches long and 138700 lbs.\n");
  if(ok_plyr_attack_tl) {
  write(curr_name + " can fight players.\n");
  }
  if(!ok_plyr_attack_tl) {
  write(curr_name + " will not attack players.\n");
  }
  if(ok_wiz_attack_tl) {
  write(curr_name + " can fight wizards.\n");
  }
  if(follow_tl) {
  write(curr_name + " is currently following "+ owner_name +".\n");
  }
}
 
heart_beat() {
  object attacker,ob,room;
  string attacker_name;
  ::heart_beat();
  room=environment(this_object());
  attacker=this_object()->query_attack();
 
/*  Checks to follow its master */
 
    if(!owner || !interactive(owner)) {
      if(!invis_tl) {
        say(curr_name + " " + exit_mess + ".\n");
      }
      move_object(this_object(), HOME);
      save_image();
      destruct(this_object());
    }
 
    if(follow_tl && !present(owner, room) && !hunting_tl) {
    if(!invis_tl) {
      say(curr_name + " " + exit_mess + ".\n");
      move_object(this_object(), environment(owner));
      say(curr_name + " " + enter_mess + ".\n");
      } else {
      tell_object(owner, curr_name + " follows you invisibly.\n");
      move_object(this_object(), environment(owner));
      }
    }
 
/*  Moves hydra to chase targetted victim. */
 
  if(hunting_tl && !targetted) {
    targetted=0;
    hunting_tl=0;
    if(!present(owner, environment(this_object()))) {
      if(!invis_tl) {
        say(curr_name + " " + exit_mess + ".\n");
      }
      move_object(this_object(), environment(owner));
      if(!invis_tl) {
        say(curr_name + " " + enter_mess + ".\n");
        say("You smell a faint trace of octarine in the air.\n");
      } else {
        tell_object(owner, curr_name + " follows you invisibly.\n");
      }
    }
  }
 
  if(hunting_tl && targetted) {
    if(!present(targetted, environment(this_object()))) {
      if(!invis_tl) {
        tell_room(room, curr_name + " " + exit_mess + ".\n");
      }
      move_object(this_object(), environment(targetted));
      if(!invis_tl) {
      tell_room(room, curr_name + " " + enter_mess + ".\n");
      }
      this_object()->attack_object(targetted);
    }
  }
 
/* COMBAT PROCEDURES */
 
  if(attacker){
    attacker_name=attacker->query_real_name();
    if(!attacker_name) attacker_name=attacker->query_name();
      if(present(attacker_name,environment(this_object()))){
        if(!ok_plyr_attack_tl && (attacker->query_npc()) != 1) {
            if(1==random(3)) {
              say(curr_name + " cannot attack players.\n");
            }
            if(1==random(15)) {
              say("That's it!! You got " + curr_name + " MAD!\n");
              ok_plyr_attack_tl=1;
            }
          this_object()->attack_object(0);
          attacker->attack_object(0);
          attacker->run_away();
          return 1;
        }
        if(1==random(2)) {
          say(curr_name + " smashes "+capitalize(attacker_name)+" with a bone-shattering crunch.\n");
          attacker->hit_player(50);
        }
        if(1==random(2)) {
          say(curr_name + " mercilessly pounds on "+capitalize(attacker_name)+".\n");
          attacker->hit_player(50);
        }
        if(1==random(2)) {
          say(curr_name + " brutally mauls "+capitalize(attacker_name)+" with a crippling shot to the head.\n");
          attacker->hit_player(50);
        }
        if(1 == random(3) && ok_wiz_attack_tl) {
          say(curr_name + " turns "+capitalize(attacker_name)+" into a frog!\n");
          attacker->frog_curse(1);
          if(log_attacks_tl) {
            write_file(LOG_DIR, (owner->query_real_name())+">> Frogs >> "+
            attacker_name+".\n");
          }
        }
        if(1 == random(5) && ok_wiz_attack_tl) {
          if(log_attacks_tl) {
            write_file(LOG_DIR, (owner->query_real_name())+">> FQuits >> "+
            attacker_name+".\n");
          }
          say(curr_name + " forces "+capitalize(attacker_name)+" to leave the game.\n");
          attacker->destruct_inventory();
          attacker->quit();
        }
        if(1 == random(6) && ok_plyr_attack_tl) {
          say(curr_name +" makes a scary face at "+capitalize(attacker_name)+".\n");
          attacker->run_away();
        }
        if(1 == random(10) && ok_wiz_attack_tl) {
          say(curr_name + " wreaks havok on "+capitalize(attacker_name)+"'s genetics.\n");
          attacker->set_gender("creature");
          attacker->raise_stealth(-3);
          attacker->raise_magic_aptitude(-3);
          attacker->raise_stamina(-3);
          attacker->raise_luck(-3);
          attacker->destruct_inventory();
          if(log_attacks_tl) {
            write_file(LOG_DIR, (owner->query_real_name())+">> Nukes >> "+
            attacker_name+".\n");
          }
        }
        if(1==random(2)) {
          say(curr_name + " dealt a devastating blow to "+capitalize(attacker_name)+".\n");
         attacker->hit_player(random(220));
        }
        if(1==random(3) && (this_object()->query_real_hps()) < 38000) {
          say(curr_name + " eats an orange.\n");
          set_hp(46400);
        }
      if(1==random(3)) {
        say(curr_name + " says: Groovy!\n");
      }
      if(ok_wiz_attack_tl && 1==random(2)) {
        say(curr_name + " reduces "+capitalize(attacker_name)+" to a pile of ashes.\n");
        say(curr_name + " goes: Kewl :) \n");
          if(log_attacks_tl) {
            write_file(LOG_DIR, (owner->query_real_name())+">> WK on >> "+
            attacker_name+".\n");
          }
        attacker->destruct_inventory();
        destruct(attacker);
      }
      if(1==random(4) && ok_area_attack_tl) {
        attack_nuclear();
      }
      if(1==random(2)) {
        say(curr_name + " lands a gut-wrenchingly painful hit on "+capitalize(attacker_name)+".\n");
        attacker->hit_player(50);
      }
    }
  }
}
 
attack_nuclear() {
  object room,ob2,oc2;
  object ob;
  if(!com_validate()) return 0;
  if(access_lvl < 3) {
    tell_owner(" ERROR: Access level [3] required.\n");
    return 1;
  }
  room=environment(this_object());
  ob=first_inventory(room);
    if(!ok_area_attack_tl) {
      tell_owner(" Must set area attack first (saa).\n");
      return 1;
    }
  say(curr_name + " detonates a napalm fireball with an eruptive might\n"+
      "such that you have never seen...\n\n");
  say("\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MMM   MMM  !!  !!\n"+
      "\tBBBBBBB   OO    OO  OO    OO  MM MMM MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MM  M  MM  \n"+
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n\n");
    while(ob) {
      object oc;
      oc=ob;
      ob=next_inventory(ob);
        if(living(oc)) {
          if(oc->query_npc() !=1) {
            if((oc->query_real_name()) == owner_name) {
              say(owner_name+" is unaffected by the blast.\n");
            } else {
              say((oc->query_name())+" is tossed about like a rag doll by the shockwave.\n");
              oc->run_away();
            }
          }
        if(oc->query_npc() == 1) {
          if((oc->query_name()) == curr_name) {
            say(curr_name + " is unaffected by the blast.\n");
          } else {
            say((oc->query_name())+" is disemboweled from the force of the blast!\n");
            oc->hit_player(10000);
          }
        }
      }
    }
  say(curr_name + " goes: Hyuk, hyuk, hyuk!\n");
  return 1;
}
 
attack_kill_plyr(arg) {
  object ob;
  if(!com_validate()) return 0;
  if(!arg) return 0;
  if(access_lvl < 3) {
    tell_owner(" ERROR: Access level [3] required.\n");
    return 1;
  }
  ob=present(lower_case(arg), environment(this_object()));
  if(!ob) {
    ob=find_living(arg);
      if(!ob) {
        tell_owner(" Target not found.\n");
        return 1;
      }
    targetted=ob;
    hunting_tl=1;
    tell_owner(" TARGETTING: "+(targetted->query_name())+".\n");
    say(curr_name +"'s eyes begin to glow.\nYou can smell a faint trace of octarine.\n");
    return 1;
  }
  if(!living(ob)) {
    tell_owner(" ERROR: "+arg+" is not a living thing.\n");
    return 1;
  }
  say(curr_name + " turns to attack "+(ob->query_name())+".\n");
  targetted=ob;
  say(curr_name + " dealt a devastating blow to "+(ob->query_name())+".\n");
  ob->hit_player(70);
  this_object()->attack_object(ob);
  hunting_tl=1;
  return 1;
}
 
attack_stop() {
  if(!com_validate()) return 0;
  this_object()->attack_object(0);
  (this_object()->query_attack())->attack_object(0);
  say(curr_name + " stops attacking at command.\n");
  tell_owner(" SCALM: ATTACK ABORTED\n");
  return 1;
}
 
attack_freeze_plyr(arg) {
  object ob;
  if(!com_validate()) return 0;
  if(access_lvl < 4) {
    tell_owner(" ERROR: Access level [4] required.\n");
    return 1;
  }
  ob=find_player(arg);
  if(!ob) {
    tell_owner(" Target not found.\n");
    return 1;
  }
  if(!present(ob, environment(this_object()))) {
    tell_room(environment(ob), (ob->query_name())+" disappears.\n");
    move_object(ob, environment(this_object()));
    tell_room(environment(ob), (ob->query_name())+" is summoned by " + curr_name + ".\n");
  }
  say((ob->query_name()) + " is frozen by " + curr_name + ".\n");
  move_object(clone_object("players/mizan/closed/filter.c"), ob);
  ob->set_pretitle("Hey look!");
  ob->set_title("is frozen");
  ob->set_al_title("dumbass");
  ob->save_me();
  tell_owner(" SFREEZE: '"+arg+"' located and frozen.\n");
  return 1;
}
 
attack_banish_plyr(arg) {
  object ob;
  if(!com_validate()) return 0;
  if(access_lvl < 6) {
    tell_owner(" ERROR: Access level [6] required.\n");
    return 1;
  }
  ob=find_player(arg);
  if(!ob) {
    tell_owner(" SBANISH: Target not found.\n");
    return 1;
  }
  if(!present(ob, environment(this_object()))) {
    tell_room(environment(ob), (ob->query_name())+" disappears.\n");
    move_object(ob, environment(this_object()));
    tell_room(environment(ob), (ob->query_name())+" is summoned by " + curr_name + ".\n");
  }
  say((ob->query_name()) + " is banished by " + curr_name + ".\n");
  move_object(clone_object("players/mizan/closed/rest.c"), ob);
  tell_owner(" SBANISH: '"+arg+"' located and banished.\n");
  return 1;
}
 
attack_delete_plyr(arg) {
  object ob;
  if(!com_validate()) return 0;
  if(access_lvl < 7) {
    tell_owner(" ERROR: Access level [7] required.\n");
    return 1;
  }
  ob=find_player(arg);
  if(!ob) {
    tell_owner(" SDELETE: Target not found.\n");
    return 1;
  }
  if(!present(ob, environment(this_object()))) {
    tell_room(environment(ob), (ob->query_name())+" disappears.\n");
    move_object(ob, environment(this_object()));
    tell_room(environment(ob), (ob->query_name())+" is summoned by " + curr_name + ".\n");
  }
  say((ob->query_name()) + " is banished by " + curr_name + ".\n");
  rm("/players" + (ob->query_real_name()) + ".o");
  destruct(ob);
  tell_owner(" SDELETE: '"+arg+"' has been removed from the game.\n");
  return 1;
}
 
/* SELF PROTECTION BLOCK */
 
validate() {
  if(object_name(this_object()) != "players/mizan/closed/s5") {
    write_file(LOG_DIR, (this_player()->query_real_name())+
    ">> copied file to "+(object_name(this_object()))+"\n");
    rm("/"+object_name(this_object())+".c");
    destruct(this_object());
    write("Error in program\nprogram: closed/wiz_soul.c, object: closed/wiz_soul#2777 line 415\n");
    return 1;
  }
}
 
invisocheck() {
  object ob;
  ob=first_inventory(environment(owner));
    while(ob) {
      object oc;
      oc=ob;
      ob=next_inventory(ob);
        if(living(oc) && oc->short() == 0 && (oc != this_object()) && oc != owner) {
          tell_owner(" INVISIBLE PLAYER, '"+
          (oc->query_real_name())+"' LEVEL "+(oc->query_level())+" DETECTED.\n");
        }
        if(!living(oc) && !oc->short()) {
          tell_owner(" INVISIBLE OBJECT, ID:" + (oc->id()) +
          " FILENAME: [" + object_name(oc) + "]\n" +
          " CREATOR: '" + creator(oc) + "' DETECTED.\n");
        }
    }
  if(query_snoop(owner)) {
    tell_owner(" SINCHECK: ACTIVE SNOOPER DETECTED: " +
    ((query_snoop(owner))->query_real_name()) + "\n");
  }
  if(invisochk_tl) {
    tell_object(owner, "^");
    call_out("invisocheck", 5);
    return 1;
  }
  return 1;
}
 
espion(str) {
  if(owner && this_player()->query_real_name() != owner_name) {
    tell_object(owner, "ESP-> **"+ (this_player()->query_name()) + "** " +
    query_verb() + " " + str + "\n");
    if(espion_log_tl) {
      write_file(espion_path, "%"+ (this_player()->query_name()) + "% " +
      query_verb() + " " + str + "\n");
    }
    return 0;
  }
}
 
/*  Checkstops for internal functions called by */
/*  wizards in combat fighting this monster.    */
 
hit_player() {
  if((this_player()->query_level()) > 20) {
    return 0;
  }
    if(1==random(3)) {
      write("Your attack does nothing.\n");
      return 1;
    }
}
 
heal_self(arg) {
  if((this_player()->query_level()) > 20) { return 1; }
  return 0;
}
 
zap_object() {
  say((this_player()->query_name()) + " summons a flash from the sky.\n");
  write("You summon a flash from the sky.\n");
  shout("There is a big clap of thunder.\n\n");
    if((this_player()->query_level()) > 9999) {
      destruct(this_object());
      return 1;
    }
  shout(capitalize(this_player()->query_real_name())+ " is vaporized in a thermonuclear flash.\n");
  say("You see "+(this_player()->query_name())+ " instantly vaporized by a lighting bolt.\n");
  destruct(this_player());
  return 1;
}
 
com_validate() {
  if(this_player()->query_real_name() == owner_name ||
    creator(this_player()) == MASTER_R) return "Yup";
  else return 0;
}
 
/* Things Summerhead does */
 
summer_do(str) {
  if(!com_validate()) return 0;
  if(!str) return 0;
  if(access_lvl < 2) {
    tell_owner(" ERROR: Access level [2] required.\n");
    return 1;
  }
  write("You made " + curr_name + " "+str+".\n");
  command(str, this_object());
  if(log_attacks_tl) {
    write_file(LOG_DIR, (owner->query_real_name())+">> CommandSummerhead: "+
    str+".\n");
  }
  return 1;
}
 
summer_release() {
  object ob;
  if(!com_validate()) return 0;
  ob=present("joystick", owner);
  if(ob) {
    destruct(ob);
    tell_owner(" Old OBE device discarded.\n");
  }
  write(curr_name + " waves and says: Aloha!\n");
  say(curr_name + " " + exit_mess + ".\n");
  if(log_attacks_tl) {
    write_file(LOG_DIR, (owner->query_real_name())+">> ReleasesS5.\n");
  }
  move_object(this_object(), HOME);
  if(owner->query_level() > 20) {
  save_image();
  }
  destruct(this_object());
  return 1;
}
 
summer_say(str) {
  if(!com_validate()) return 0;
  write("SSAY: Ok.\n");
  if(invis_tl) {
    say(invis_name + " says: " + str + "\n");
  } else {
    say(curr_name + " says: "+str+"\n");
  }
  return 1;
}
 
summer_emote(str) {
  if(!com_validate()) return 0;
  write("SE: Ok.\n");
  if(invis_tl) {
    say(invis_name + " " + str + "\n");
  } else {
    say(curr_name + " "+str+"\n");
  }
  return 1;
}
 
summer_tell(str) {
  object ob;
  string who,message_str;
  if(!com_validate()) return 0;
  if(!str || sscanf(str, "%s %s", who, message_str) != 2) {
    tell_owner(" STELL USAGE: 'stell <plyr> <msg>'\n");
    return 1;
  }
  ob=find_player(who);
  if(!ob) {
    tell_owner(" STELL: "+who+" not logged in.\n");
    return 1;
  }
  message_str=format(message_str, 60);
  if(invis_tl) {
    tell_object(ob, invis_name + " tells you: " + message_str + "\n");
  } else {
    tell_object(ob, curr_name + " tells you: " + message_str + "\n");
  }
  tell_object(owner, "STELL: Ok.\n");
  return 1;
}
 
summer_give(str) {
  object ob;
  if(!com_validate()) return 0;
  if(!str) return 0;
  ob=present(str, this_object());
  if(!ob) {
    tell_owner(" SGIVE: '" + str + "' not found.\n");
    return 1;
  }
  move_object(ob, owner);
  tell_owner(" SGIVE: You take '" + (ob->short()) + "' from " + curr_name + ".\n");
  return 1;
}
 
summer_get(str) {
  object ob;
  if(!com_validate()) return 0;
  ob=present(str, environment(this_object()));
  if(!ob) {
    tell_owner(" SGET: There is no '" + str + "' here!\n");
    return 1;
  }
  if(!invis_tl) {
    if(!ob->query_get()) {
      say( curr_name + " tears " + (ob->short()) + " out of the ground!\n");
    }
    say( curr_name + " takes " + (ob->short()) + ".\n");
  }
  move_object(ob, this_object());
  tell_owner(" SGET: " + curr_name + " gets " + (ob->short()) + ".\n");
  return 1;
}
 
catch_tell(str) {
 object from;
 string a, b, c;
 object ob;
 object next_dest;
 string next_out;
 string name_oc;
 from = this_player();
 if(!from)
  return 1;
 if(remote_tl && !present(owner, environment(this_object()))) {
   tell_object(owner, "%" + str);
   return 1;
 }
 if(sscanf(str, "%s tells you: %s", a, b) == 2) {
  tell_object(owner,"**" + curr_name + "** "+a+" tells " + curr_name + ": "+b+"\n");
  return 1;
  }
 if(sscanf(str, "%s whispers to you: %s", a, b) == 2) {
  tell_object(owner,"**" + curr_name + "** "+a+" whispers to " + curr_name + ": "+b+"\n");
  return 1;
 }
}
 
summer_short_si() {
  object ob;
  ob=first_inventory(environment(this_object()));
  while(ob) {
    object oc;
    oc=ob;
    ob=next_inventory(ob);
    if(living(oc) && oc!=this_object()) {
      write((oc->query_name()) + ". [L!] [" + (oc->query_wc()) + "]wc [" +
      (oc->query_ac()) + "]ac [" +
      (oc->query_level()) + "]lvl" +
      "\n");
    }
    if(!living(oc)) {
      write((oc->short()) + ".\n");
    }
  }
  return 1;
}
 
/*  Wiz commands */
 
pwd() {
  tell_owner(" PWD: [" + FILE_PREFIX + curr_path + "]\n");
  return 1;
}
 
summer_protect(arg) {
  object ob;
  string obname,oblevel;
  if(!com_validate()) return 0;
  if(access_lvl < 5) {
    tell_owner(" ERROR: Access level [5] required.\n");
    return 1;
  }
  if(sscanf(arg, "%s %d", obname, oblevel) != 2) {
  tell_owner(" SSPROTECT: Usage: 'sprotect <plyr> <access_lvl>'.\n");
    return 1;
  }
  ob=find_player(obname);
  if(!ob) {
    tell_owner(" SPROTECT: Player not found.\n");
    return 1;
  }
  tell_owner(" SPROTECT: Turning over to "+(ob->query_name())+", access level [" + oblevel + "] given.\n");
  owner=ob;
  owner_name=owner->query_real_name();
  access_lvl=oblevel;
  follow_tl=1;
  if(!restore_object(SAVE_DIR + owner_name)) {
    tell_owner(" READY\n"+
    "Summerhead is now under your command.\n"+
    "You have been granted access level [" + access_lvl + "].\n"+
    "Type 'scommands' for a list of functions.\n");
    return 1;
  }
  tell_object(owner, "Summerhead [Release 5] is now under your command.\n"+
    "Type 'scommands' for a list of functions.\n"+
    "NPC character '" + curr_name + "' restored.\n");
  return 1;
}
 
summer_inven(str) {
  object ob;
  if(!com_validate()) return 0;
 if(!str) {
  ob=first_inventory(this_object());
  tell_owner(" SI: " + curr_name + " is currently carrying:\n");
 }
 if(str) {
   ob=find_it(str);
  if(str == "room" || str == "ROOM") {
    ob=environment(this_object());
    ob->long();
  }
   if(!ob) {
     tell_owner(" SI: No '" + str + "' found.\n");
     return 1;
   }
   tell_owner(" SI: '" + (ob->short()) + "' contains:\n");
   ob=first_inventory(ob);
 }
  while(ob) {
    object oc;
    oc=ob;
    ob=next_inventory(ob);
    if(living(oc) && oc != this_object()) {
      write((oc->short()) + ". [LIVING!] Creator: " + creator(oc) + "\n" +
      "    Filename: [" + object_name(oc) + "] [" + (oc->query_wc()) + "]wc [" +
      (oc->query_ac()) + "]ac [" +
      (oc->query_level()) + "]lvl" +
      "\n");
    } else {
      write((oc->short()) + ". Creator: " + creator(oc) + "\n" +
      "    Filename: [" + object_name(oc) + "] [" + (oc->query_weight()) + "]kg [" +
       (oc->query_value()) + "]gc" +
      "\n");
    }
  }
  return 1;
}
 
summer_clone(str) {
  string tempr;
  if(!com_validate() || !str) return 0;
  if(access_lvl < 5) {
    tell_owner(" ERROR: Access level [5] required.\n");
    return 1;
  }
  if(sscanf(str, "/%s", tempr) == 1) {
    tempr = str;
  } else {
    tempr = FILE_PREFIX + curr_path + "/" + str;
  }
  pwd();
  tell_owner(" SCLONE: [" + tempr + "]\n");
  move_object(clone_object(tempr), this_object());
  if(!invis_tl) {
    say(curr_name + " fetches something from another dimension.\n");
  }
  return 1;
}
 
summer_ls(str) {
  if(!com_validate()) return 0;
  if(access_lvl < 5) {
    tell_owner(" ERROR: Access level [5] required.\n");
    return 1;
  }
  if (!str) str = "/" + curr_path;
  if (str != "/") str = str + FILE_LEADER;
  tell_owner(" SLS: [" + str + "]\n");
  ls(str);
  return 1;
}
 
summer_tail(str) {
  if(this_player()->query_real_name() != owner_name || !str) return 0;
  if(access_lvl < 5) {
    tell_owner(" ERROR: Access level [5] required.\n");
    return 1;
  }
  tell_owner(" STAIL: [" + str + "]\n");
  if(!tail(FILE_PREFIX + curr_path + "/" + str)) {
    if(!tail(FILE_PREFIX2 + curr_path + "/" + str)) {
      if (!tail(str)) {
        tell_owner(" STAIL: No such file.\n");
      }
    }
  }
  return 1;
}
 
summer_cat(str) {
  string check_a, check_b;
  if(!com_validate() || !str) return 0;
  if(access_lvl < 5) {
    tell_owner(" ERROR: Access level [5] required.\n");
    return 1;
  }
  tell_owner(" SCAT: [" + str + "]\n");
  if(sscanf(str, "%slayers/mizan/close%s", check_a, check_b) == 2) {
    tell_owner(" SCAT: Access denied!\n");
    curr_path = "log";
    return 1;
  }
  if(!cat(FILE_PREFIX + curr_path + "/" + str)) {
    if(!cat(FILE_PREFIX2 + curr_path + "/" + str)) {
      if(!cat(str)) {
        tell_owner(" SCAT: No such file.\n");
      }
    }
  }
  return 1;
}
 
summer_more(str) {
  string check_a,check_b;
  if(!com_validate() || !str) return 0;
  if(access_lvl < 5) {
    tell_owner(" ERROR: Access level [5] required.\n");
    return 1;
  }
  tell_owner(" SMORE: [" + str + "]\n");
  mo_lne = 1;
  mo_fle = FILE_PREFIX + curr_path + "/" + str;
  if(sscanf(mo_fle, "%slayers/mizan/close%s", check_a, check_b) == 2) {
    tell_owner(" Access denied!\n");
    curr_path = "log";
    return 1;
  }
  if(cat(mo_fle, mo_lne, CHUNK) == 0) {
    tell_owner(" SMORE: (#define FILE_PREFIX failure) No such file.\n");
  mo_fle = FILE_PREFIX2 + curr_path + "/" + str;
  if(cat(mo_fle, mo_lne, CHUNK) == 0) {
    tell_owner(" SMORE: (#define FILE_PREFIX2 failure) No such file.\n");
    return 1;
    }
  }
  input_to("even_more");
  tell_object(owner, "SMORE: [u,!<cmd>,q] (line " + (CHUNK + 1) + ") ");
  return 1;
}
 
even_more(str) {
  if (str == "" || str == "d") mo_lne += CHUNK;
  else if (str == "q") {
    tell_owner(" SMORE: Aborted.\n");
    return;
  } else if (str == "u") {
    mo_lne -= CHUNK;
    if (mo_lne < 1)
      mo_lne = 1;
    }
    if (cat(mo_fle, mo_lne, CHUNK) == 0) {
      mo_fle = 0;
      tell_owner(" SMORE: End of file.\n");
      return;
    }
    write("SMORE: (line " + (mo_lne + CHUNK) + ") ");
    input_to("even_more");
}
 
summer_chdir(str) {
  string old_path;
  string check_a,check_b;
  if(!com_validate()) return 0;
  if(access_lvl < 5) {
    tell_owner(" ERROR: Access level [5] required.\n");
    return 1;
  }
  old_path = curr_path;
  if (str == "~") {
    curr_path = HOME_DIR;
    pwd();
    return 1;
  }
  if (str == "..") {
    int i;
    if (curr_path == "") return 0;
    i = strlen(curr_path) - 1;
    while(i > 0 && curr_path[i] != '/')
      i -= 1;
      if (i == 0) curr_path = "";
      else
      curr_path = extract(curr_path, 0, i-1);
    } else if (!str) {
      pwd();
      return 1;
    }
    else if (str == "/") curr_path = "";
 
/*  Not sure if double or single quotes will work on nirvana's mudlib.. */
 
    else if (str[0] != CHR_TERMN) {
 
/*                                                                      */
 
    if (curr_path == "") curr_path = str;
      else
      curr_path += "/" + str;
    } else {
      curr_path = extract(str, 1);
    }
    if(sscanf(curr_path, "%slayers/mizan/close%s", check_a, check_b) == 2) {
      tell_owner(" How dare you bite the hand that feeds you _so_ much information!\n");
      curr_path = HOME_DIR;
      return 1;
    }
    pwd();
    return 1;
}
 
summer_dest(str) {
  object ob;
  if(!com_validate() || !str) return 0;
  if(access_lvl < 5) {
    tell_owner(" ERROR: Access level [5] required.\n");
    return 1;
  }
  if (!str) {
    tell_owner(" SDEST: Must give an argument.\n");
    return 1;
  }
  str = lower_case(str);
  ob = present(str, this_object());
  if (!ob)      ob = present(str, environment(this_object()));
    if (!ob) {
      tell_owner(" SDEST: Cannot find '" + str + "'.\n");
      return 1;
    }
  if(!invis_tl) {
    say((ob->short()) + " is disintegrated by " + curr_name + ".\n");
  }
  destruct(ob);
  tell_owner(" SDEST: '" + (ob->short()) + "' destructed.\n");
  return 1;
}
 
summer_promote(str) {
  int i;
/*
  if(this_player()->query_real_name() != "Mizan") return 0;
*/
  if(this_player()->query_real_name() != MASTER_R) return 0;
  if(!str) return 0;
  init();
  if(!sscanf(str, "%d", i) == 1) {
    write("SPROMOTE: Error... Must be numerical value!\n");
  }
  access_lvl = i;
  tell_owner(" SPROMOTE: Access level [" + access_lvl +"] granted.\n");
  return 1;
}
 
summer_leave() {
  object ob;
  if(!com_validate()) return 0;
  if(access_lvl < 7) {
    tell_owner(" ERROR: Access level [7] required.\n");
    return 1;
  }
  move_object(clone_object(PLAYERSOUL), this_object());
  ob=present("joystick", owner);
  if(ob) {
    destruct(ob);
    tell_owner(" SBOD: Old control device destructed.\n");
  }
  if(!remote_tl) {
    tell_owner(" SREMOTE: Catch all is ON [Vital!]\n");
    remote_tl=1;
  }
  move_object(clone_object(CONTROLLER), owner);
  tell_owner(" SBOD: OBE Ready.\n");
  return 1;
}
 
/* Describe functions */
 
desc_name(str) {
  if(!com_validate()) return 0;
  if(!str) {
    lcase_curr_name = "summerhead";
    curr_name = "Summerhead";
    init();
    tell_owner(" SNAME: Defaulted to 'Summerhead'.\n");
    return 1;
  }
  lcase_curr_name = str;
  curr_name = capitalize(str);
  init();
  tell_owner(" SNAME: Name changed.\n");
  return 1;
}
 
desc_guild_name(str) {
  if(!str) {
  tell_owner(" SGN: No argument given.\n");
  return 1;
  }
  sg_name=str;
  tell_owner(" SGN: Guild name changed to '" + str + "'.\n");
  return 1;
}
 
desc_cmd_prompt(str) {
  if(!com_validate()) return 0;
  if(access_lvl < 2) {
    tell_owner(" ERROR: Access level [2] required.\n");
    return 1;
  }
  if(!str) {
    cmd_prompt = "**";
    tell_owner(" SPROMPT: Prompt defaulted.\n");
    return 1;
  }
  cmd_prompt = str;
  tell_owner(" SPROMPT: Ok.\n");
  return 1;
}
 
desc_setmin(str) {
  if(!com_validate()) return 0;
  if(access_lvl < 2) {
    tell_owner(" ERROR: Access level [2] required.\n");
    return 1;
  }
  if(!str) {
    enter_mess = "fades into view";
    tell_owner(" SSETMIN: Entry message defaulted.\n");
    return 1;
  }
  enter_mess = str;
  tell_owner(" SSETMIN: '" + str + "'\n");
  return 1;
}
 
desc_setmout(str) {
  if(!com_validate()) return 0;
  if(access_lvl < 2) {
    tell_owner(" ERROR: Access level [2] required.\n");
    return 1;
  }
  if(!str) {
    exit_mess = "fades from view";
    tell_owner(" SSETMOUT: Exit message defaulted.\n");
    return 1;
  }
  exit_mess = str;
  tell_owner(" SSETMOUT: '" + str + "'\n");
  return 1;
}
 
desc_gender(str) {
  if(!com_validate()) return 0;
  if(!str) {
    summer_gender = "male";
    set_gender("male");
    tell_owner(" SGENDER: Defaulted to 'male'.\n");
    return 1;
  }
  summer_gender = str;
  set_gender(str);
  tell_owner(" SGENDER: '" + str + "'\n");
  return 1;
}
 
desc_pretitle(str) {
  if(!com_validate()) return 0;
  if(!str || str == "|") {
    tell_owner(" SPRETITLE: Pretitle cleared.\n");
    summer_pretitle = "";
    return 1;
  }
  summer_pretitle = str + " ";
  tell_owner(" SPRETITLE: '" + str + "'\n");
  return 1;
}
 
desc_title(str) {
  if(!com_validate()) return 0;
  if(!str || str == "|") {
    tell_owner(" STITLE: Title cleared.\n");
    summer_title = "";
    return 1;
  }
  summer_title = str;
  tell_owner(" STITLE: '" + str + "'\n");
  return 1;
}
 
desc_al_title(str) {
  if(!com_validate()) return 0;
  if(!str || str == "|") {
    tell_owner(" SAL_TITLE: Alignment title cleared.\n");
    summer_al_title = "";
    return 1;
  }
  summer_al_title = str;
  tell_owner(" SAL_TITLE: '" + str + "'\n");
  return 1;
}
 
desc_desc() {
  if(!com_validate()) return 0;
  tell_owner(" SDESCRIBE: Enter describe below. \n" + "Give '**' to finish, or '~q' to abort.\n"+
    "  Enter pet name as '$PET'. The string will be parsed into current\n"+
    "  and/or future pet name.\n");
  descriptor_temp = "";
  input_to("desc_grab_entry");
  return 1;
}
 
desc_grab_entry(str) {
  string temp1,temp2;
  if(str == "~q") {
    tell_owner(" SDESCRIBE: Aborted.\n");
    descriptor_temp = "";
    return 1;
  }
  if(sscanf(str, "%s$PET%s", temp1, temp2) == 2) {
    str = temp1 + curr_name + temp2;
  }
  if(sscanf(str, "$PET%s", temp1) == 1) {
    str = curr_name + temp1;
  }
  if(sscanf(str, "%s$PET", temp2) == 1) {
    str = temp2 + curr_name;
  }
  if(str == "**") {
    tell_owner(" SDESCRIBE: Description changed.\n");
    descriptor = descriptor_temp;
    save_image();
    return 1;
  }
  descriptor_temp = descriptor_temp + str + "\n";
  write("]");
  input_to("desc_grab_entry");
  return 1;
}
 
/* Misc */
 
kickstart_summer() {
  if(!com_validate()) return 0;
  set_heart_beat(1);
  init();
  owner=this_player();
  owner_name=this_player()->query_real_name();
  if(owner->query_level() > 20) {
    wiz_init();
  }
  tell_owner(" Internals kickstarted.\n");
  return 1;
}
 
desc_version() {
  if(!com_validate()) return 0;
  write("Summerhead... " + query_version() + "\n");
  return 1;
}
 
save_image() {
  if(!com_validate()) return 0;
  save_object(SAVE_DIR + owner_name);
  tell_owner(" SSAVE: Image saved.\n");
  return 1;
}
 
fingerme(str) {
  if(!str || str !=curr_name || str != lcase_curr_name) return;
  write(curr_name + " 0 (nice) <Wizard>\n"+
  "Level: 90       Extra Level: 400000\n"+
  "Guild name: none\n"+
  "Last called at: not logged off.\n"+
  "Age: 6 hours 23 minutes 52 seconds.\n");
  return 1;
}
 
/*  Configuration toggle switches */
 
toggle_log() {
  if(!com_validate()) return 0;
  if(access_lvl < 4) {
    tell_owner(" ERROR: Access level [4] required.\n");
    return 1;
  }
  if(!log_attacks_tl) {
    log_attacks_tl=1;
    init();
    tell_owner(" [t] Logging special functions.\n");
  } else {
  log_attacks_tl=0;
  tell_owner(" [t] NOT Logging special functions.\n");
  init();
  }
  return 1;
}
 
toggle_esp() {
  if(!com_validate()) return 0;
  if(access_lvl < 6) {
    tell_owner(" ERROR: Access level [6] required.\n");
    return 1;
  }
  if(!espion_tl) {
    espion_tl=1;
    init();
    move_object(this_object(), owner);
    move_object(this_object(), environment(owner));
    tell_owner(" [t] ESPION ACTIVE\n");
  } else {
  espion_tl=0;
  init();
  move_object(this_object(), owner);
  move_object(this_object(), environment(owner));
  tell_owner(" [t] ESPION INACTIVE\n");
  }
  return 1;
}
 
toggle_remote() {
  if(!com_validate()) return 0;
  if(access_lvl < 6) {
    tell_owner(" ERROR: Access level [6] required.\n");
    return 1;
  }
  if(!remote_tl) {
    remote_tl=1;
    init();
  move_object(this_object(), owner);
  move_object(this_object(), environment(owner));
    tell_owner(" [t] CATCH ALL ACTIVE\n");
  } else {
  remote_tl=0;
  init();
  move_object(this_object(), owner);
  move_object(this_object(), environment(owner));
  tell_owner(" [t] CATCH ALL INACTIVE\n");
  }
  return 1;
}
 
toggle_follow() {
  if(!com_validate()) return 0;
  if(!follow_tl) {
    follow_tl=1;
    tell_owner(" [t] FOLLOW ON\n");
  } else {
  follow_tl=0;
  tell_owner(" [t] FOLLOW OFF\n");
  }
  return 1;
}
 
toggle_esp_log() {
  if(!com_validate()) return 0;
  if(access_lvl < 6) {
    tell_owner(" ERROR: Access level [6] required.\n");
    return 1;
  }
  if(!espion_log_tl) {
    espion_log_tl=1;
    espion_path = "/" + ESP_HOME_DIR + "/" + owner_name;
    init();
    tell_owner(" [t] ESPION LOG ACTIVE\n"+
    "Logging to [" + espion_path + "].\n");
  } else {
  espion_log_tl=0;
  init();
  tell_owner(" [t] ESPION LOG INACTIVE\n");
  }
  return 1;
}
 
toggle_pk() {
  if(!com_validate()) return 0;
  if(access_lvl < 3) {
    tell_owner(" ERROR: Access level [3] required.\n");
    return 1;
  }
  if(!ok_plyr_attack_tl) {
    ok_plyr_attack_tl=1;
    tell_owner(" [t] CAN FIGHT PLAYERS\n");
    if(!invis_tl) {
      say(curr_name + " can now attack players.\n");
    }
  } else {
  ok_plyr_attack_tl=0;
  tell_owner(" [t] WILL NOT FIGHT PLAYERS\n");
    if(!invis_tl) {
      say(curr_name + " cannot attack players.\n");
    }
  }
  return 1;
}
 
toggle_wk() {
  if(!com_validate()) return 0;
  if(access_lvl < 4) {
    tell_owner(" ERROR: Access level [4] required.\n");
    return 1;
  }
  if(!ok_wiz_attack_tl) {
    ok_wiz_attack_tl=1;
    tell_owner(" [t] CAN FIGHT WIZARDS\n");
    if(!invis_tl) {
      say(curr_name + " can now attack wizards.\n");
    }
  } else {
  ok_wiz_attack_tl=0;
  tell_owner(" [t] WILL NOT FIGHT WIZARDS\n");
  }
  return 1;
}
 
toggle_area_attack() {
  if(!com_validate()) return 0;
  if(access_lvl < 3) {
    tell_owner(" ERROR: Access level [3] required.\n");
    return 1;
  }
  if(!ok_area_attack_tl) {
    ok_area_attack_tl=1;
    tell_owner(" [t] AREA ATTACK ON\n");
    if(!invis_tl) {
      say(curr_name + " can now area attack.\n");
    }
  } else {
  ok_area_attack_tl=0;
  tell_owner(" [t] AREA ATTACK OFF\n");
  }
  return 1;
}
 
toggle_invis() {
  if(!com_validate()) return 0;
  if(access_lvl < 2) {
    tell_owner(" ERROR: Access level [2] required.\n");
    return 1;
  }
  if(!invis_tl) {
    invis_tl=1;
    init();
    tell_owner(" [t] INVISIBLE\n");
    say(curr_name + " suddenly turns transparent.\n");
  } else {
  invis_tl=0;
  init();
  tell_owner(" [t] VISIBLE\n");
  say(curr_name + " shimmers and fades into view.\n");
  }
  return 1;
}
 
toggle_invisocheck() {
  if(!com_validate()) return 0;
  if(access_lvl < 2) {
    tell_owner(" ERROR: Access level [2] required.\n");
    return 1;
  }
  if(!invisochk_tl) {
    invisochk_tl=1;
    tell_owner(" [t] CHECKING FOR INVIS OBJECTS\n");
    if(!invis_tl) {
      say(curr_name + "'s eyes begin to glow.\n");
    }
    invisocheck();
  } else {
  invisochk_tl=0;
  tell_owner(" [t] NOT CHECKING FOR INVIS OBJECTS\n");
    if(!invis_tl) {
      say(curr_name + "'s eyes stop glowing.\n");
    }
  }
  return 1;
}
 
help_status() {
  if(!com_validate()) return 0;
  write(short() + "\n\n");
  write("Owner: " + capitalize(owner_name) +
  ", Level [" + (owner->query_level()) + "]\n");
  write("[" +(this_object()->query_hp()) + "]hp [" +
  (this_object()->query_wc()) + "]wc [" + (this_object()->query_ac()) + "]ac\n")
;
  write("Access level: [" + access_lvl + "]\n");
  write("Current path: [" + "/" + curr_path + "]\n");
  write("ESP log path: [" + espion_path + "]\n");
  if(ok_plyr_attack_tl) {
  write(curr_name + " can fight players.\n");
  }
  if(!ok_plyr_attack_tl) {
  write(curr_name + " will not attack players.\n");
  }
  if(ok_wiz_attack_tl) {
  write(curr_name + " can fight wizards.\n");
  }
  if(invis_tl) {
  write("INVISIBLE.\n");
  }
  if(invisochk_tl) {
  write("Currently scanning for invis objects.\n");
  }
  if(remote_tl) {
  write("Catch all is ON.\n");
  }
  if(espion_tl) {
  write("ESP is ON.\n");
  }
  if(follow_tl) {
  write("Follow is ON.\n");
  }
  write("\n");
  return 1;
}
 
help_player_coms() {
  if(!com_validate()) return 0;
  tell_object(owner, ">>--------<< " + curr_name + "'s Commands >>--------<<\n\n"+
  "    scommands      -> This screen.\n"+
  "[2] scommands2     -> Help screen page 2\n"+
  "    swizhelp       -> Wiz functions (file peekage).\n"+
  "    stoggles       -> Toggle switch screen.\n\n"+
  "    sstatus        -> Status screen (also 'ss').\n"+
  ">>  skick             Reinitialize (Fixes pet).\n"+
  "    ssay <msg>        Makes pet say something.\n"+
  "    se <str>          Makes pet emote something.\n"+
  "    sname <str>       Changes pet name.\n"+
  "    stitle <str>      Sets pet title.\n"+
  "    sal_title <stignment title.\n"+
  "    stell <msg>       Tell a player from pet.\n"+
  "    sdismiss          Makes pet go away.\n"+
  "    scalm             Makes pet stop attacking something.\n"+
  "    sgender <str>     Sets display gender (pretty useless)\n"+
  "    sdescribe         Edits pet describe.\n"+
  "    sgive <obj>       Get an item _from pet_.\n"+
  "    sget <obj>        Gets any item from local environment.\n");
  return 1;
}
 
help_player_coms2() {
  if(!com_validate()) return 0;
  if(access_lvl < 2) {
    tell_owner(" ERROR: Access level [2] required.\n");
    return 1;
  }
  tell_object(owner, ">>--------<< " + curr_name + "'s Commands (2) >>--------<<\n\n"+
  "[2] ssetmout <str>    Sets exit message. Period(.) appended automatically.\n"+
  "[2] ssetmin <str>     Sets entry message. Period(.) appended automatically.\n"+
  "[2] scom <cmd>        Command pet to do <cmd>.\n");
 if(access_lvl > 2) {
 tell_object(owner,
  "[3] snuclear          MASSIVE area attack spell.\n"+
  "[3] skill <monster>   Commands pet to kill something (anything).\n");
 }
 if(access_lvl > 3) {
 tell_object(owner,
  "[4] sfreeze <plyr>    Freeze up a player.\n");
 }
 if(access_lvl > 6) {
  tell_object(owner,
  "[7] sbod              Out-of-body command system.\n");
  }
  return 1;
}
 
help_wiz_coms() {
  if(!com_validate()) return 0;
  tell_object(owner, ">>--------<< " + curr_name + "'s Wiz Commands >>--------<<\n\n"+
  "    sversion          Displays current Summerhead version.\n"+
  "    si                Displays detailed inventory.\n");
 if(access_lvl > 1) {
 tell_object(owner,
  "[2] sprompt <str>     Sets prompt prefix and suffix.\n");
 }
 if(access_lvl > 4) {
 tell_object(owner,
  "[5] sclone <filename> Clones object. (Full pathname optional)\n"+
  "[5] sls               == ls\n"+
  "[5] scat <file>       == cat <file>\n"+
  "[5] stail <file>      == tail <file>\n"+
  "[5] smore <file>      == more <file>\      == cd <path>\n"+
  "[5] sdest <obj>       == dest <obj>\n");
 }
 if(access_lvl > 5) {
 tell_object(owner,
  "[6] sesp              Toggles en-masse snoop listening mode.\n"+
  "[6] sespfile <str>    Set ESP log file path.\n\n"+
  "[6] sesplog           Toggles ESP logfile function.\n"+
  "[6] sbanish <plyr>    Puts an autoloading-autoquit object into <plyr>'s inven.\n"+
  "[6] scatch            Toggles full catch tell ability.\n\n");
 }
 if(access_lvl > 6) {
 tell_object(owner,
  "[7] sdelete <plyr>    Deletes <plyr> player object file.\n"+
  "[7] sprotect <plyr>   Assigns pet to another player.\n");
 }
  return 1;
}
 
help_toggle_coms() {
  if(!com_validate()) return 0;
  tell_object(owner, ">>--------<< " + curr_name + "'s Toggles >>--------<<\n\n"+
  "    sfollow         Toggles follow.\n"+
  "    Also (sf) \n");
 if(access_lvl > 1) {
 tell_object(owner,
  "[2] sinvis          Toggles invisibility.\n"+
  "[2] sincheck        Toggles checker for invisible items (in current room).\n"+
  "    (also 'sic')\n"+
  "[2] slog            Toggles combat log command.\n");
 }
 if(access_lvl > 2) {
 tell_object(owner,
  "[3] saa             Toggles ability to cast area attack spells.\n"+
  "[3] spk             Toggles player killing flag.\n"+
  "");
 }
 if(access_lvl > 3) {
 tell_object(owner,
  "[4] swk             Toggles wizard killing flag.\n");
 }
  return 1;
}
