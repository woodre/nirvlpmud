#include <ansi.h>  /* Rumplemintz */
#define FINAL 741070800
#define QFACT present("Dopple-Faction",this_player())
#define NOPET QFACT->query_pet_allow()
#define GCLVL 20
#define BZDAMAGE 60
#define BZWAIT 10
#define GLEVEL this_player()->query_guild_rank()
#define RES_TIME 300
#define corpse_heal 5*GLEVEL
#define news_date 123 
#define HIT 5*GLEVEL
#define WAIT 2
#define MORPH "players/grimm/object/morph"
#define NAME this_player()->query_real_name()
#define CNAME capitalize(NAME)
#define THIS environment(this_object())
#define NAME_MORPH environment(this_player())->morph_name
#define STRIP(XXX,YYY,ZZZ) sscanf(XXX,"%s#%s",YYY,ZZZ)
#define ENVIRONMENT file_name(environment(this_player()))
#if 0
#define ESC ""
#endif

int shaddup, morphed, bztime, follow, damage, res_time, no_hit, monitor, wait, flag_check, temp, attack_wait, new_news, LEVEL, registered;
int which_drain, wimp_num, wimp_cent, current_call, last_read;
int sleep_amt, sleep_time, shift_flag;
int fang_hit, cloaked, allowem;
object morph, temp_ob, ob, safe_ob, oldenv, env, loc, plaenv, location;
string fname, inv, items, victim, place, next_out, out, morph_name, local_env, trash;
string g_title;
int gate1,gate2,gate3,gate4,gate5;
object g1,g2,g3,g4,g5;

query_morphed() { return morphed; }

set_wimp_cent(x) {
wimp_cent=x;
return x;
}

set_last_read(x) {
  last_read=x;
  return 1;
}

set_res_time(x) {
res_time=x;
return x;
}

query_allowem() { return allowem; }

set_bz_time(x) {
bztime=x;
return x;
}


set_set_morph(mname) {
morph_name=mname;
return mname;
}

set_gate1(x) { gate1 = x; return x; }
set_gate2(x) { gate2 = x; return x; }
set_gate3(x) { gate3 = x; return x; }
set_gate4(x) { gate4 = x; return x; }
set_gate5(x) { gate5 = x; return x; }
set_g1(it) { g1 = it; return 1; }
set_g2(it) { g2 = it; return 1; }
set_g3(it) { g3 = it; return 1; }
set_g4(it) { g4 = it; return 1; }
set_g5(it) { g5 = it; return 1; }

query_shaddup() { return shaddup; }

/* query_guild_title added by Rumplemintz */
string query_guild_title() {
  string result;

  switch(GLEVEL) {
  case 1: result = HIW + "Fledgeling" + NORM; break;
  case 2: result = HIW + "Zombie" + NORM; break;
  case 3: result = HIW + "Doppleganger" + NORM; break;
  case 4: result = HIW + "Master Doppleganger" + NORM; break;
  case 5: result = HIW + "Senior Doppleganger" + NORM; break;
  case 6: result = HIW + "Disciple of Darkness" + NORM; break;
  case 7: result = HIW + "Master of Darkness" + NORM; break;
  case 8: result = HIW + "Lord of Darkness" + NORM; break;
  case 9: result = HIW + "Overlord" + NORM; break;
  case 10..19: result = HIW + "Faction Doppleganger" + NORM; break;
  case 20..29: result = RED + "Guild Commander" + NORM; break;
  case 30..49: result = RED + "Guild Senior" + NORM; break;
  case 50..99: result = HIB + "Guild Wiz" + NORM; break;
  case 100..199: result = HIB + "Commanding Guild Wiz" + NORM; break;
  case 200..999: result = HIB + "Senior Commanding Guild Wiz" + NORM; break;
  case 1000: result = HIR + "Guild Master" + NORM; break;
  default: result = "";
  }
  return result;
}


reset(arg) {
/* Don't think we need this, gives the player(s) information they can use
   to know when mobs are going to spawn
  tell_object(find_living(NAME),"The badge just reset.\n");
*/
  if(arg) return;
  set_light(1);
  which_drain = 0;
  shift_flag = 0;
  sleep_time = time();
  sleep_amt = 0;
  LEVEL = this_player()->query_level();
  wimp_cent = 10;
  morphed = 0;
  fang_hit = HIT;
  cloaked = 0;
  safe_ob = 0;
  gate1 = 0;
  gate2 = 0;
  gate3 = 0;
  gate4 = 0;
  gate5 = 0;
  allowem = 0;
  follow = 0;
  short();
  bztime = time();
  res_time=time();
  monitor=1;
  shaddup=0;
  set_heart_beat(1);
  morph_name = "Bat";
  g_title = query_guild_title();
/*
  if(GLEVEL>999) g_title = red("(Guild Master)");
  else if(GLEVEL>199) g_title = red("(Senior Commanding Guild Wiz)");
  else if(GLEVEL>99) g_title = red("(Commanding Guild Wiz)");
  else if(GLEVEL>49) g_title = red("(Guild Wiz)");
  else if(GLEVEL>29) g_title = red("(Guild Senior)");
  else if(GLEVEL>(GCLVL-1)) g_title = red("(Guild Commander)");
  else if(GLEVEL>8) g_title = white("(Overlord)");
  else if(GLEVEL>7) g_title = white("(Lord of Darkness)");
  else if(GLEVEL>6) g_title = white("(Master of Darkness)");
  else if(GLEVEL>5) g_title = white("(Disciple of Darkness)");
  else if(GLEVEL>4) g_title = white("(Senior Doppleganger)");
  else if(GLEVEL>3) g_title = white("(Master Doppleganger)");
  else if(GLEVEL>2) g_title = white("(Doppleganger)");
  else if(GLEVEL>1) g_title = white("(Zombie)");
  else g_title = white("(Fledgling)");
*/
  call_out("every_so_often",10);
}

every_so_often() {
  int i;
  if(!environment(this_object())) return 1;
  i = THIS->query_mhp();
  wimp_num = (THIS->query_mhp()*wimp_cent)/100;
  call_out("every_so_often",5);
}

heart_beat() {
string tmp;
if(THIS->query_level()<20)
{
#if 0
sscanf(g_title,"(%s)",tmp);
THIS->set_al_title("["+tmp+"]");
#else
  THIS->set_al_title("[" + g_title + "]");
#endif
}
if(!present("Dopple-Faction",THIS))
THIS->set_guild_name("doppleganger");
if(THIS->query_attack() && THIS->query_hp()<wimp_num) {
  tell_object(THIS,"You freak out and run out of the room.\n");
  THIS->run_away();
  follow=0;
}
if((present("badge of dopplegangers guild",THIS))->query_morphed() && follow==1) {
  tell_object(THIS,"You cannot follow anybody while in morph form.\n");
  follow = 0;
}
if(follow==1) {
  if(!find_living(fname)) {
    follow=0;
    tell_object(THIS,"The person you were following is not on the game.\n");
  } else {
    if(!present(fname, environment(THIS))) {
      tell_object(THIS,"You follow "+capitalize(fname)+".\n");
    move_object(THIS,environment(find_living(fname)));
    command("look",THIS);
  }
  }
 }
if(THIS->query_attack() && monitor==1) {
tell_object(THIS,"HP-> "+THIS->query_hp()+
            "/"+THIS->query_mhp()+
  "  SP-> "+THIS->query_sp()+
  "/"+THIS->query_msp());
  if(present("pet",environment(THIS))) {
    if(present("pet",environment(THIS))->query_owner()==THIS->query_real_name()) {
      tell_object(THIS,"  PET HP-> "+
       (present("pet",environment(THIS))->query_hp())+"/"+
       (present("pet",environment(THIS))->query_mhp()));
    }
   }
  tell_object(THIS,"\n");
}
if(gate1 && !g1) { gate1 = 0; }
if(gate2 && !g2) { gate2 = 0; }
if(gate3 && !g3) { gate3 = 0; }
if(gate4 && !g4) { gate4 = 0; }
if(gate5 && !g5) { gate5 = 0; }
}

drop() { return 1; }

get() { return 1; }

date_it() {
  int date, month_deci;
}

short() {
  string nm;
  nm = "Badge of the Doppleganger's Guild ";
  if (cloaked) return;
/* Rumplemintz
  return nm+g_title;
*/
  return nm + "(" + g_title + ")";
/*
  if(GLEVEL>100)
    return nm+red("(Guild Master)");
  else if(GLEVEL>9)
    return nm+red("(Guild Commander!)");
  else if(GLEVEL>8)
    return nm+white("(Lord of Darkness)");
  else if(GLEVEL>7)
    return nm+white("(Master of Darkness)");
  else if(GLEVEL>6)
    return nm+white("(Disciple of Darkness)");
  else if(GLEVEL>5)
    return nm+white("(Overlord)");
  else if(GLEVEL>4)
    return nm+white("(Senior Doppleganger)");
  else if(GLEVEL>3)
    return nm+white("(Master Doppleganger)");
  else if(GLEVEL>2)
    return nm+white("(Doppleganger)");
  else if(GLEVEL>1)
    return nm+white("(Zombie)");
  else return nm+white("(Fledgling)");
*/
}

cloak() {
  if(GLEVEL<5) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(cloaked) {
    write("Badge UN-cloaked.\n");
  } else
    write("Badge cloaked.\n");
  cloaked = !cloaked;
  return 1;
}


long() { 
  write ("This is a badge of darkness.  Only the most evil may posses it!\n"+
         "     type \"help_badge\" or \"hb\" for a list of commands\n");
}

id(str) {
  return str == "badge" || str == "badge of dopplegangers guild" ||
         str == "GUILD" || str == "V-GUILD";
}

hp() {
if(monitor==1) {
  monitor=0;
  write("Hit Point Monitor: OFF\n");
  return 1;
}
write("Hit Point Monitor: ON\n");
monitor=1;
return 1;
}

init() {
  if(NAME=="sweetness" ||
         NAME == "merlyn" ||
     NAME=="scathe") { destruct(this_object()); }
/*
  if(!registered) {
    registered=1;
    "/players/grimm/guild"->register();
  }
*/
/*
  add_action("cru","cru");
*/
  add_action("commander_emote","commander_emote");
  add_action("commander_emote","ce");
  add_action("meltem","melt");
  add_action("horde","horde");
  add_action("strikeem","strike");
  add_action("blast","blast");
  add_action("blade","blade");
  add_action("allow_tog","allow_toggle");
  add_action("allow_tog","at");
  add_action("commander_tell","ct");
  add_action("commander_tell","commander_tell");
  add_action("cloak","cloak");
  add_action("fang_set","fang_set");
  add_action("fang_set","fs");
  add_action("vandalize","vandalize");
   add_action("setmylev","setem");
  add_action("fang","fang");
  add_action("berserk","berserk");
  add_action("help_badge3","hb3");
  add_action("guard","guard");
  add_action("sleep","sleep");
  add_action("summon","summon");
  add_action("pet","pet");
/*
  add_action("jump","jump");
*/
  add_action("shift","shift");
  add_action("spice","spice");
  add_action("jerky","jerky");
  add_action("safe","hide");
  add_action("bak_hide","return");
  add_action("coat","coat");
  add_action("step","step");
  add_action("calm","calm");
  add_action("date_news","date_news");
  add_action("smelt","smelt");
  add_action("drain_toggle","drain_toggle");
  add_action("drain_toggle","dt");
  add_action("commander_help","chb");
  add_action("commander_help","commander_help_badge");
  add_action("query_them","query");
  add_action("badgify","badge");
  add_action("promote","promote");
  add_action("revoke","revoke");
  add_action("new_commands","new_commands");
  add_action("wimp_set","whimpy");
  add_action("direct","direct");
  add_action("other_guild","other_who");
  add_action("other_guild","ow");
  add_action("title","new_title");
#ifndef __LDMUD__
  add_action("sayit"); add_xverb("'");
#else
  add_action("sayit", "'", 3);
#endif
  add_action("sayit","say");              
  add_action("follow_em","follow");
  add_action("shaddup","guild_tell_shaddup");
  add_action("score","score");
  add_action("score","sc");
  add_action("shaddup","gts");
  add_action("gate","gate");
  add_action("tonic","tonic");
  add_action("hp","hp");
  add_action("bite","bite");              
  add_action("emote","emote");
  add_action("guild_emote","guild_emote");
  add_action("guild_emote","ge");
  add_action("emote",":",1);
  add_action("update","renew");
  add_action("tellem","guildtell");
  add_action("tellem","guild_tell");
  add_action("tellem","gt");
  add_action("guild_who","guild_who");
  add_action("guild_who","gw");
  add_action("guild_all","guild_all");
  add_action("guild_all","ga");
  add_action("guild_wiz","guild_wiz");
  add_action("guild_wiz","gz");
  add_action("note","note");
  add_action("appraise","appraise");
  add_action("appraise","app");
  add_action("scan","scan");
  add_action("check_al","check_al");
  add_action("gget","gget");
  add_action("ginv","ginv");
  add_action("gput","gput");
  add_action("drain","drain");
  add_action("rescue","rescue");
  add_action("move","",1);                
  add_action("change_me","change");          
  add_action("change_me","ch");
  add_action("look","l");                 
  add_action("look","look");              
  add_action("s","south");
  add_action("n","north");
  add_action("e","east");
  add_action("w","west");
  add_action("nw","northwest");
  add_action("now","nw");
  add_action("ne","northeast");
  add_action("noe","ne");
  add_action("se","southeast");
  add_action("soe","se");
  add_action("sw","southwest");
  add_action("sow","sw");
  add_action("d","down");
  add_action("u","up");
  add_action("examine","la");                
  add_action("examine","exa",1);             
  add_action("help_badge","help_badge");
  add_action("help_badge","hb");
  add_action("help_badge2","help_badge2");
  add_action("help_badge2","hb2");
  add_action("guild_news","guild_news");  
  add_action("morph_menu","set_morph");
  add_action("quit","quit");              
/*
  add_action("nope","shock",2);             
  add_action("nope","missile",2);           
  add_action("nope","fireball",2);          
*/
  add_action("extra_move","mv");
}

drain_toggle() {
  if(GLEVEL<2) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(which_drain==1) {
    write("Drain now set for Hit points.\n");
    which_drain = 0;
    return 1;
  }
  write("Drain now set for Spell points.\n");
  which_drain = 1;
  return 1;
}

shaddup() {
if(shaddup==1) {
  write("Guild Tell messages: ON\n");
  shaddup=0;
  return 1;
}
write("Guild Tell messages: OFF\n");
shaddup=1;
return 1;
}

valid_direction(str) {
  if( str == "north" || str == "n" ||
      str == "south" || str == "s" ||
      str == "east" || str == "e" ||
      str == "west" || str == "w" || 
      str == "northwest" || str == "nw" ||
      str == "southwest" || str == "sw" ||
      str == "northeast" || str == "ne" ||
      str == "southeast" || str == "se" ||
      str == "up" || str == "u" ||
      str == "down" || str == "d"
    ) return 1;
/*
write("Checkpoint\n");
*/
  return 0;
}

player_env() {
  if(living(environment(this_player())))
    STRIP(ENVIRONMENT,local_env,trash);
  else local_env = ENVIRONMENT;
  return local_env;
}

s() {
  extra_move("south");
  return 1;
}

n() {
  extra_move("north");
  return 1;
}

e() {
  extra_move("east");
  return 1;
}

w() {
  extra_move("west");
  return 1;
}

nw() {
  extra_move("northwest");
  return 1;
}

ne() {
  extra_move("northeast");
  return 1;
}

se() {
  extra_move("southeast");
  return 1;
}

sw() {
  extra_move("southwest");
  return 1;
}

d() {
  extra_move("down");
  return 1;
}

u() {
  extra_move("up");
  return 1;
}

sow() {
  command("southwest",this_player());
  return 1;
}

soe() {
  command("southeast",this_player());
  return 1;
}

now() {
  command("northwest",this_player());
  return 1;
}

noe() {
  command("northeast",this_player());
  return 1;
}

extra_move(str) {
  if (player_env() == MORPH) {
    oldenv = environment(environment(this_player()));
    environment(this_player())->invis(1);
    if(!command(str,environment(this_player()))) { 
      write("You can't move that way.\n");
      environment(this_player())->invis(0);
      return 1;
    }
    tell_room(oldenv,"An evil "+morph_name+" leaves the room.\n");
    tell_room(environment(environment(this_player())),"An evil "+
              morph_name+" enters the room.\n");
    environment(this_player())->invis(0);
    look();
    return 1;
  }
  return 0;
}

move() {
  string verb;     
  if(player_env() == MORPH && this_player()->query_level() < 20)
#if 0 /* Rumplemintz */
    this_player()->setal("[1m"+morph_name+"[m");
#else
    this_player()->setal(BOLD+morph_name+NORM);
#endif
  else if (this_player()->query_level() < 20)
#if 0 /* Rumplemintz */
    this_player()->set_title(this_player()->query_title()+" "+ESC+"[1m[Disciple of Darkness]"+ESC+"[0m");
#else
    this_player()->set_title(this_player()->query_title() + " " + BOLD +
                             "[Disciple of Darkness]" + NORM);
#endif
  if(this_player()->query_name()=="grimm") {
#if 0 /* Rumplemintz */
    this_player()->set_title(this_player()->query_title()+" "+ESC+"[1m[Prince of Darkness]"+ESC+"[0m");
#else
    this_player()->set_title(this_player()->query_title()+ " " + BOLD +
                             "[Prince of Darkness]" + NORM);
#endif
  }
  verb = query_verb();
  if(verb == "u") verb = "up";
  if(verb == "d") verb = "down";
  if (verb && valid_direction(verb) && player_env() == MORPH) {
    oldenv = environment(environment(this_player()));
    environment(this_player())->invis(1);
    if(!command(verb,environment(this_player()))) { 
      write("You can't move that way.\n");
      environment(this_player())->invis(0);
      return 1;
    }
    tell_room(oldenv,"An evil "+morph_name+" leaves "+verb+"\n");
    tell_room(environment(environment(this_player())),"An evil "+
              morph_name+" enters the room.\n");
    environment(this_player())->invis(0);
    look();
    return 1;
  }
}

fang(str) {
  if(GLEVEL < 2) {
    write("You are a high enough level to do that yet.\n");
    return 1;
  }
  if(GLEVEL<50) {
    if((this_player()->query_sp()<fang_hit) && (LEVEL<50)) {
    write("You do not have enough spell points to do that.\n");
    return 1;
}
}
  if(player_env()==MORPH) {
    write("You must be human to do this.\n");
    return 1; }
  out = " fangs ";
  next_out = "You sink your fangs into ";
  wait = WAIT;
  do_damage(str);
  return 1;
}

do_damage(str) {
  object ob;
  int r;
  if (this_player()->query_ghost()) {
    write("You are dead!\n");
    return 1; 
  }
  if (no_hit >= time() && GLEVEL<9) {
    write("You're still swallowing the blood!\n");
    return 1;
  }
  if (!str || str == "") ob=this_player()->query_attack();
  else ob=present(str,environment(this_player()));
  if(!ob || !living(ob) || environment(ob) != environment(this_player())) {
    write("Fang who?\n");
    return 1;
  }
  if (!this_player()->valid_attack(ob)) {
    write("Your body rejects the blood.\n");
    return 1;
  }
  if(!ob->query_npc()) {
    write("That is not a monster.\n");
    return 1;
  }
  victim = ob->query_name();
  out = this_player()->query_name() + out;
  if (!flag_check) {
    next_out = next_out + "the neck of " + victim + ".\n";
    out = out + victim + " in the neck.\n";
    flag_check = 0;
  }
  if(!this_player()->query_attack()) this_player()->attack_object(ob);
  if(present("GUILD",ob) && !present("V-GUILD",ob)) damage += 10;
  ob->hit_player(fang_hit);
  if(GLEVEL<50) {
    lessp(fang_hit);
 }
  write(next_out);
  write("Your blood starts to boil as you drain the blood of your victim!\n");
  say(out);
  no_hit = wait + time();
  return 1;
}

nope() {
   write("Dopplegangers are not allowed to use spells.\n");
   return 1;
}

quit() {
  write("Destroying your gates.\n");
  say(capitalize(NAME)+" seals a rip behind his shadow.\n");
  if(gate1) { gate1 = 0; destruct(g1); }
  if(gate2) { gate2 = 0; destruct(g2); }
  if(gate3) { gate3 = 0; destruct(g3); }
  if(gate4) { gate4 = 0; destruct(g4); }
  if(gate5) { gate5 = 0; destruct(g5); }
  if(player_env() == MORPH) {
    write("You cannot quit while being a morph. Change out and try again.\n");
    return 1;
  }
  else return;
}

examine(str) {
  if (player_env() != MORPH) return;
  if (!str) return;
  if(!present(str,environment(environment(this_player())))) {
    write("That is not in the room\n");
    return 1;
  }
  env = environment(this_player());
  move_object(this_player(),environment(environment(this_player())));
  command("examine "+str,this_player());
  move_object(this_player(),env);
  return 1;
}

look(str) {
  object monster;
  string at;
  int longdesc, num;
  string desc;
  int x;
  if(player_env() != MORPH) return;
   if(set_light(0)) { x = 1; } else { x = 0; }
#if 0 /* Rumplemintz */
  write("[1m(You're a "+morph_name+")[m\n");
#else
  write(BOLD +"(You're a " + morph_name + ")" + NORM + "\n");
#endif
  if(!str) {
      environment(environment(this_player()))->long();
    inv=first_inventory(environment(environment(this_player())));
    while(inv) {
      if(inv->short() && inv != environment(this_player()))
        write(inv->short()+"\n");
      inv=next_inventory(inv);
      }
    return 1;
  }
  sscanf(str,"%s %s",at,monster);
  if(at != "at") {
    examine(str);
    return 1;
  }
  if(!present(monster,environment(environment(this_player())))) {
    write("That is not in the room\n");
    return 1;
  }
  env = environment(this_player());
  move_object(this_player(),environment(environment(this_player())));
  command("look at "+monster,this_player());
  move_object(this_player(),env);
  return 1;
}

sayit(str) {
  string it;
  string dummy;
  if(!str) {
  write("Say what?\n");
  return 1;
}
  it = "say";
  if(sscanf(str,"%s!",dummy)) it = "exclaim";
  if(sscanf(str,"%s?",dummy)) it = "ask";
  if(player_env() != MORPH) {
    say(capitalize(NAME)+" "+it+"s: "+str+"\n");
    write("You "+it+": "+str+"\n");
    return 1;
  }
  if(!str) {
    write("Say what?\n");
    return 1;
  }
  tell_room(environment(environment(this_player())),"A "+morph_name+" "+it+"s: "+str+"\n");
  return 1;
}

bite(str) {
  if(!str) {
    write("Bite whom?\n");
    return 1;
  }
  if(player_env()==MORPH) {
    write("You must be human to do this.\n");
    return 1;  }
  if (!present(str,environment(this_player()))) {
    write("That player is not here.\n");
    return 1;
  }
  if (this_player()->query_ghost()) {
    write("You fail.\n");
    return 1;
  }
  ob=(present(str,environment(this_player())));
  if(str=="grimm") {
    write("As you try to bite your master he grabs you by the head and rips out your fangs!!\n");
    say("As "+this_player()->query_name()+" tries to bite Grimm his fangs are ripped out from his mouth!\n",ob);
    tell_object(ob,this_player()->query_name()+" tries to bite you.\n");
    return 1;
  }
  tell_object(ob,this_player()->query_name()+" grabs you by the neck"+" and sucks a pint of blood from your body!\n");
  say(this_player()->query_name()+" bites "+capitalize(str)+" in the neck!\n",ob);
  tell_object(this_player(),"You bite "+capitalize(str)+" in the neck!\n");
  return 1;
}

cru() {
  object ob;
  if(GLEVEL<5) {
    write("You are not a high enough level to do that.\n");
    return 1;
  }
  if(present("crucible",this_player())) {
    write("You are only allowed to have 1 crucible at a time.\n");
    return 1;
  }
  if(this_player()->query_sp()<50) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  ob = clone_object("/players/grimm/closed/obj/crucible");
  move_object(ob,this_player());
  ob->reset(1);
  write("Ok.\n");
  return 1;
}

change_me(i) {
  object player,morphenv, attacker, two, three;
  if(no_hit>time()) {
    write("You are busy drinking the blood of your victim.\n");
    return 1;
  }
  if(this_player()->query_attack()) {
    write("Your adrenalyn is pumping to fast to morph in the heat of battle.\n");
    return 1;
  }
  env = environment(environment(this_player()));
  plaenv = environment(this_player());
  attacker = this_player()->query_attack();
  if(attacker && attacker->query_npc()==0) {
    write("You can't seem to concentrate right now!\n");
    attack_wait = time() + 10;
    return 1;
  } 
  if(time() < attack_wait) {
    write("The adrenalyn in your body is making you lose concentration!\n");
    return 1;
  }
  if(plaenv->no_change()) {
    write("As you try to transform you lose your concentration.\n");
    return 1;
  }
  if(player_env() != MORPH) {
   if(!i) {
    write("As you raise your hands your body transforms into a "+morph_name+"!\n");
    say(this_player()->query_name()+" spins in a circle and transforms into a "+morph_name+"!\n");
    }
    morphed = 1;
    if("players/grimm/object/morphroom"->monflag()==0) {
      morph = clone_object("players/grimm/object/morph");
      NAME_MORPH(morph_name);
      morph->name(this_player()->query_real_name());
      move_object(morph,environment(this_player()));
      move_object(this_player(),morph);
      location = environment(this_player());
    }
    else {
      move_object(this_player(),"players/grimm/object/morphroom");
      morph = present("morph",environment(this_player()));
      morph->name(this_player()->query_real_name());
      move_object(this_player(),morph);
      NAME_MORPH(morph_name);
      morph->name(this_player()->query_real_name());
      move_object(morph,plaenv);
      morphenv = environment(this_player());
      location = environment(this_player());
    }
    return 1;
  }
  if(player_env() == MORPH) {
   if(!i) {
    write("You concentrate on your original form and become human again.\n");
    }
    morphed = 0;
    morphenv = environment(this_player());
    morphenv->name("nobody");
   if(!i) {
    tell_room(env,"You sense an evil being as a "+morph_name+" transforms into "+this_player()->query_name()+".\n");
    }
    move_object(this_player(),environment(environment(this_player())));
    move_object(morphenv,"players/grimm/object/morphroom");
    if(this_player()->query_attack() && present(this_player()->query_attack(),environment(this_player()))) {
      this_player()->query_attack()->stop_fight();
      this_player()->stop_fight();
      attacker->attack_object(this_player());
    }
    return 1;
  }
}

help_badge() {
  cat("/players/grimm/closed/obj/badge_stuff/badge_menu1");
  return 1;
}

help_badge3() {
  cat("/players/grimm/closed/obj/badge_stuff/badge_menu3");
  return 1;
}

help_badge2() {
/*
  if(GLEVEL<3) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
*/
  cat("/players/grimm/closed/obj/badge_stuff/badge_menu2");
  return 1;
}

morph_menu(str) {
  if(str) {
    set_morph(str);
    return 1;
  }
  write("Your choices are:\n");
  write("-----------------\n");
  if(this_player()->query_real_name()=="grimm")
    write("    siren\n    swirl\n");
  if (GLEVEL > 4) write("    gargoyle\n    shadow\n");
  if (GLEVEL > 3) write("    werewolf\n    werebear\n");
  if (GLEVEL > 2) write("    wraith\n    ghoul\n");
  if (GLEVEL > 1) write("    orc\n    stalker\n");
  write("    bat\n    rat\n");
  write("Enter choice: ");
  input_to("set_morph");
  return 1;
}

set_morph(str) {
  if(!str) return;
  if(str == "bat"||str =="rat") morph_name = str;
  else if((str =="orc"||str=="stalker") && GLEVEL > 1) morph_name =str;
  else if((str =="wraith"||str =="ghoul") && GLEVEL > 2) morph_name =str;
  else if((str =="werewolf"||str =="werebear") && GLEVEL > 3) morph_name =str;
  else if((str =="gargoyle"||str =="shadow") && GLEVEL > 4) morph_name =str;
  else if((str =="siren"||str=="swirl") && this_player()->query_name()=="grimm") morph_name =str;
  else {
    write("That is not a valid choice.\n");
    return 1;
  }
  morph_name = capitalize(morph_name);
  if(player_env() == MORPH) { 
    NAME_MORPH(morph_name);
    morph->name(this_player()->query_real_name());
  }
  return 1;
}

guild_news() {
  cat("/players/grimm/closed/obj/badge_stuff/guild_news");
  last_read=time();
  return 1;
}

check_al() {
  if(this_player()->query_alignment() < 0) write("Your alignment is Evil.\n");
  else write("Your alignment is Good.\n");
  return 1;
}

query_auto_load() { 
  return "/players/grimm/closed/obj/badge:"+morph_name+"#"+last_read+"#"+
         cloaked+"#"+registered;
}

note(str) {
if(!str) { write("What do you want to put in the suggestion box?\n"); return 1;}
write_file("/players/grimm/closed/LOGS/ideas",capitalize(NAME)+" wrote you:\n"+str+"\n--------------------------------------\n");
write("The note has been dropped in the box, thank you very much!\n");
return 1;
}

init_arg(str) {
  int x;
  string i,j;
  sscanf(str,"%s#%d#%d#%d",morph_name,last_read,cloaked,registered);
  if(!morph_name) morph_name = "Bat";
  i=read_file("/players/grimm/closed/obj/badge_stuff/newsdate",1);
  sscanf(i,"%d",x);
  if(x>last_read)
  guild_news();
  else write("No new guild news.\n");
}

drain() {
int x;
object corp;
if(this_player()->query_sp()<2) {
  write("You do not have enough spell points to do that.\n");
  return 1;
}
if(GLEVEL < 2) {
  write("You are not a high enough level to do that yet.\n");
 return 1;
}
if(!present("corpse",environment(this_player()))) {
  write("There is no corpse in this room.\n");
  return 1;
}
corp = present("corpse",environment(this_player()));
destruct(corp);
if(which_drain==1) {
  lessp(-(corpse_heal)); }
  else
this_player()->add_hit_point(corpse_heal);
lessp(2);
write("You feel revitilized by the corpse.\n");
say(capitalize(this_player()->query_real_name())+" drains the essence out of the corpse.\n");
return 1;
}

whois(low,hi) {
object people;
string sex;
string bfact,cfact,mfact;
object bad;
int a,n,cnt;
cnt=0;
people = users();
write("-Name-\t\t-F- -Sex- -Lvl- -Location-\n");
for(n=0; n<sizeof(people); n++) {
  if(present("badge of dopplegangers guild",people[n])) {
    if(people[n]->query_invis() > this_player()->query_level()) {
      write("");
    } else {
    if(people[n]->query_guild_rank()<hi && people[n]->query_guild_rank()>low) {
      cnt++;
      write(capitalize(people[n]->query_real_name()));
      if(strlen(people[n]->query_real_name())>7) { write("\t"); }
      else { write("\t\t"); }
      bfact="-"; cfact="-"; mfact="-";
      if(present("Dopple-Barbarian",people[n])) bfact="B";
      if(present("band-Scooter",people[n])) cfact="C";
      if(present("Dopple-Mystic",people[n])) mfact="M";
      sex=people[n]->query_gender();
      if(sex=="male") sex="M";
      else if(sex=="female") sex="F";
      else sex="C";
      write(bfact+cfact+mfact+"   ");
      write(sex+"\t   ");
      write(people[n]->query_guild_rank()+"\t ");
      if(present("badge of dopplegangers guild",people[n])->query_morphed()) {
        write(environment(people[n])->short()+" -> "+environment(environment(people[n]))->short());
      } else {
        write(environment(people[n])->short());
      }
      if(people[n]->query_invis() > 0) write("  (invis)");
      if(query_idle(people[n]) > 120)
         write("  (idle:"+(query_idle(people[n])/60)+")");
      bad = present("badge of dopplegangers guild",people[n]);
      if(bad->query_shaddup()==1) write("  (muffled)");
      write("\n");
    }
    }
  }
}
write(">>> "+cnt+" people listed.\n");
return 1;
}

guild_who() {
  whois(0,(GCLVL+11));
  return 1;
}

guild_all() {
  whois(0,1001);
  return 1;
}

guild_wiz() {
  whois((GCLVL+10),1001);
  return 1;
}

tellem(str) {
object people;
object bad;
int n, x;

if(GLEVEL<1) {
  write("You are not a high enough level to do that yet.");
  write("\n");
  return 1;
}
if(!str) {
  write("Tell guildmembers what?\n");
  return 1;
}
people = users();
for(n=0; n<sizeof(people); n++) {
  if(present("badge of dopplegangers guild",people[n])) {
    bad = present("badge of dopplegangers guild",people[n]);
    if(bad->query_shaddup()==0 && people[n]->query_guild_rank()>0) {
#if 0
    tell_object(people[n],"["+capitalize(this_player()->query_real_name())+"]: "+str+"\n");
#else
    switch(GLEVEL) {
    case 1..19:
    tell_object(people[n], HIW + "[" + this_player()->query_name() + "]: " +
                NORM + str + "\n");
      break;
    case 20..49:
      tell_object(people[n], RED + "[" + this_player()->query_name() + "]: " +
                  NORM + str + "\n");
      break;
    case 50..999:
      tell_object(people[n], HIB + "[" + this_player()->query_name() + "]: " +
                  NORM + str + "\n");
      break;
    default:
      tell_object(people[n], HIR + "[" + this_player()->query_name() + "]: " +
                  NORM + str + "\n");
      break;
    }
#endif
    }
  } else {
    x = random(10);
    if(x<5 && present(people[n],environment(this_player())) && people[n]->query_level() < 20) {
      tell_object(people[n],"You hear whispering from behind your back.\n");
    }
   }
  }
return 1;
}

lessp(i) {
  this_player()->add_spell_point((-1 * i));
  return 1;
}

update() {
object bad;
if(this_player()->query_attack()) {
  write("It wouldn't really be a good idea to renew while in combat.\n");
  return 1;
}
if(shift_flag == 1) {
  write("You are still concentrating on shifting! Wait a second.\n");
  return 1;
}
bad = clone_object("/players/grimm/closed/obj/badge");
bad->set_res_time(res_time);
bad->set_last_read(last_read);
bad->set_wimp_cent(wimp_cent);
bad->set_bz_time(bztime);
bad->set_set_morph(morph_name);
bad->set_gate1(gate1);
bad->set_gate2(gate2);
bad->set_gate3(gate3);
bad->set_gate4(gate4);
bad->set_gate5(gate5);
bad->set_g1(g1);
bad->set_g2(g2);
bad->set_g3(g3);
bad->set_g4(g4);
bad->set_g5(g5);
move_object(bad, this_player());
bad->change_me("1");
bad->change_me("1");
destruct(this_object());
return 1;
}

guild_emote(str) {
  int i;
  object people;
  string mand,rest;
  int lev;
  if(str) {
    if(sscanf(str,"%sGC20>< %s",mand,rest)) {
      lev=GCLVL;
      str=rest;
    } else lev=4;
  }
  if(GLEVEL<lev) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(!str) {
    write("What do you want to emote?\n");
    return 1;
  }
  people = users();
  if(lev<GCLVL) lev=0;
  for(i=0;i<sizeof(people);i++) {
    if((present("badge of dopplegangers guild",people[i])
      && people[i]->query_guild_rank()>(lev-1))
      || people[i]->query_real_name()=="redwine") {
      if(!present("badge of dopplegangers guild",people[i])->query_shaddup()) {
      if(lev)
        tell_object(people[i],"\n>>>"+capitalize(NAME)+" "+str+"\n");
      else
      tell_object(people[i],"\n->>"+capitalize(NAME)+" "+str+"\n");
      }
    }
  }
  lessp(2);
  if(lev)
    write("You commander_emote:\n"+capitalize(NAME)+" "+str+
    "\n");
  else
  write("You guild_emote:\n"+capitalize(NAME)+" "+str+"\n");
  return 1;
}

emote(str) {
if(!str) {
  write("What do you want to emote?\n");
  return 1;
}
say(capitalize(this_player()->query_name())+" "+str+"\n");
write("You emote:\n"+capitalize(this_player()->query_name())+" "+str+"\n");
return 1;
}

commander_emote(str) {
  if(GLEVEL<GCLVL) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(!str) {
    write("Commander emote what?\n");
    return 1;
  }
  guild_emote("><GC20>< "+str);
  return 1;
}

/* Fixed this so it actually costs twice as much sps now - Rumplemintz */
tonic(i) {
int x, amt;
sscanf(i,"%d",amt);
/* Here....
x = amt;
*/
  x = amt*2;
if(GLEVEL < 2) {
  write("You are not a high enough level to do that yet.\n");
  return 1;
}
if(amt==0) {
  write("Usage is:\ntonic X\nWhere X is the amount of healing you need\nfor X*2 spell points.\n");
  return 1;
}
if(amt < 0){
write("You cannot tonic a negative amount.\n");
return 1;}
#if 0
if(this_player()->query_spell_point()< (int)x) {
#else
  if (this_player()->query_spell_point() < x) {
#endif
  write("You do not have enough spell points for that amount.\n");
  return 1;
}
this_player()->add_hit_point(amt);
lessp(x);
write("Done.\n");
return 1;
}

follow_em(str) {
  if(GLEVEL<2) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(!str) {
    if(follow==1) {
      follow=0;
      write("You are no longer folowing anybody.\n");
    } else {
      write("You weren't following anybody.\n");
      follow=0;
    }
    return 1;
  }
  if(this_player()->query_sp()<15) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(!present(str,environment(this_player()))) {
    write("That person is not here right now.\n");
    follow=0;
    return 1;
  }
  fname=str;
  lessp(15);
  follow=1;
  write("You are now following "+capitalize(fname)+".\n");
  return 1;
}

gput(str) {
object item;
  if(this_player()->query_sp()<5) {
    write("You do not have enough spell points to do that.\n");
    return 1;
  }
  if(GLEVEL <3) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(!str) {
   write("What do you want to put in the locker?\n");
   return 1;
  }
  item=present(str,this_player());
  if(!item) {
    write("You do not have one of those.\n");
    return 1;
  }
  if(str=="speedster" ||
     str=="badge" ||
     str=="quicktyper" ||
     item->query_auto_load()) {
    write("You cannot put that in there.\n");
    return 1;
  }
  if(item->armor_class()) {
    item->remove(str);
  }
  if(item->weapon_class()) {
    item->stopwield(str);
  }
  move_object(item,"/players/grimm/closed/obj/badge_stuff/locker");
  write("Ok.\n");
  lessp(5);
  say(capitalize(NAME)+" puts a "+str+" in a locker.\n");
  call_other(this_player(),"reset",1);
  return 1;
}

gget(str) {
object item,locker_room;
string locker;
  if(this_player()->query_sp()<5) {
    write("You do not have enough spell points to do that.\n");
    return 1;
  }
  if(GLEVEL<3) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
/* Below added by Rumplemintz */
  if (!str) {
    write("Usage: gget <item>\n");
    return 1;
  }
/* To here */
  locker="/players/grimm/closed/obj/badge_stuff/locker";
  locker_room=find_object(locker);
  item=present(str,locker_room);
  if(!item) {
    write("There isn't a "+str+" in the locker.\n");
    return 1;
  }
  move_object(item,this_player());
  say(capitalize(NAME)+" takes a "+str+" from his locker.\n");
  write("Ok.\n");
  lessp(5);
  call_other(this_player(),"reset",1);
  return 1;
}

ginv(str) {
string xhmm;
object item,locker_room;
string locker;
int i;
  if(GLEVEL<4) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  locker="/players/grimm/closed/obj/badge_stuff/locker";
  locker_room=find_object(locker);
if(!locker_room) {
  write("The locker currently contains:\n  Nothing.\n");
  return 1;
}
  item=first_inventory(locker_room);
  write("The locker currently contains:\n");
  say(capitalize(NAME)+" looks in his locker.\n");
  i=0;
  while(item) {
    if(item->id(str) || !str ||
      (item->weapon_class() && str=="weapons"))
    { i++;
    write(item->short()+"\n");
    }
    item=next_inventory(item);
  }
  if(i==0) {
    write("  Nothing.\n");
  }
  write("\n");
  return 1;
}

appraise(str) {
int ac, wc, value;
if(this_player()->query_sp()<10) {
  write("You do not have enough spell points to do that.\n");
  return 1;
}
if(GLEVEL<4) {
  write("You are not a high enough level for that yet.\n");
  return 1;
}
if(!present(str,this_player())) {
  write("That is not here.\n");
  return 1;
}
ob = present(str,this_player());
ac = ob->armor_class();
wc = ob->weapon_class();
value = ob->query_value();
if(!ac) write("This would make some terrible armor.\n");
  else if(ac==1) write("This would make some ok armor.\n");
  else if(ac==2) write("This would make some decent armor.\n");
  else if(ac==3) write("This would make some pretty good armor.\n");
  else if(ac==4) write("This would make some very good armor.\n");
  else if(ac==5) write("This would make some awesome armor.\n");
if(!wc) write("This would be a terrible weapon.\n");
  else if(wc<3)
       write("This would be worse than using just your hands for a weapon.\n");
  else if(wc>2 && wc<6)
       write("This would be a very poor choice for a weapon.\n");
  else if(wc>5 && wc<9)
       write("This would be an ok choice for a weapon.\n");
  else if(wc>8 && wc<12)
       write("This would be a decent choice for a weapon.\n");
  else if(wc>11 && wc<15)
       write("This would be a pretty good choice for a weapon.\n");
  else if(wc>14 && wc<18)
       write("This would be a very good choice for a weapon.\n");
  else if(wc>17 && wc<20)
       write("This would be an awesome choice for a weapon.\n");
  else if(wc>19)
       write("This is a weapon of choice for the gods!\n");
lessp(10);
return 1;
}
rescue() {
if(GLEVEL <2) {
  write("You are not a high enough level to do that yet.\n");
  return 1;
}
if(present("badge of dopplegangers guild",THIS)->query_morphed()) {
    write("You cannot rescue while in morph form.\n");
    return 1;
  }
if(this_player()->query_spell_point() <40) {
  write("You do not have enough spell points to do that.\n");
  return 1;
}
if(res_time>time()) {
  write("It has not been 15 minutes since your last rescue.\n");
  return 1;
}
if(environment(this_player())->realm()=="NT") {
  write("You cannot rescue out of this room.\n");
  return 1;
}
res_time=time()+RES_TIME;
write("You step behind your shadow and arrive in the guild.\n");
lessp(40);
this_player()->move_player("by stepping behind his shadow#/players/grimm/closed/obj/badge_stuff/guild_pr");
return 1;
}

scan(str) {
  int hp,mhp,cent;
object ob;
if(GLEVEL<5) {
  write("You are not a high enough level to do that yet.\n");
  return 1;
}
if(this_player()->query_sp()<5) {
  write("You do not have enough spell points to do that.\n");
  return 1;
}
if(!str) {
  write("What do you want to scan?\n");
  return 1;
}
if(!present(str,environment(this_player()))) {
  write("That is not here.\n");
  return 1;
}
ob = present(str,environment(this_player()));
hp = call_other(ob,"query_hp");
mhp= call_other(ob,"query_mhp");
cent=100*hp/mhp;
write(capitalize(str)+" has "
+cent+
"% of its hit points left.\n");
lessp(5);
return 1;
}

gate(str) {
  string XX;
if(GLEVEL<3) {
  write("You are not a high enough level to do that yet.\n");
  return 1;
}
  if(!str) {
    write("Try 'gate help' for information on the gate functions.\n");
    return 1;
  }
  if(str=="list") {
    gate_list();
    return 1;
  }
  if(str=="drop") {
    gate_drop();
    return 1;
  }
  if(str=="help") {
    gate_help();
    return 1;
    }
  if(str=="enter") {
    gate_enter();
    return 1;
  }
  if(str=="remove") {
    gate_remove();
    return 1;
  }
  if(sscanf(str,"enter %s",XX)) {
    x(XX);
    return 1;
  }
  write("What?\n");
return 1;
}

gate_list() {
  write("Gate listing:\n");
  if(!gate1) write("1.  <Not Placed>\n");
    else     write("1.  "+environment(g1)->short()+"\n");
  if(!gate2) write("2.  <Not Placed>\n");
    else     write("2.  "+environment(g2)->short()+"\n");
  if(!gate3) write("3.  <Not Placed>\n");
    else     write("3.  "+environment(g3)->short()+"\n");
  if(!gate4) write("4.  <Not Placed>\n");
    else     write("4.  "+environment(g4)->short()+"\n");
  if(!gate5) write("5.  <Not Placed>\n");
    else     write("5.  "+environment(g5)->short()+"\n");
  write("\n");
return 1;
}

gate_help() {
  cat("/players/grimm/closed/obj/badge_stuff/gate_menu");
  return 1;
}

gate_enter() {
  gate_list();
  write("Enter the gate to enter: ");
  input_to("x");
return 1;
}

x(str) {
  int i;
  object ob;
  sscanf(str,"%d",i);
  if(!i) {
    write("You need to supply the gate to enter.\n");
    return 1;
  }
  if(i==1) ob = g1;
  else if(i==2) ob = g2;
  else if(i==3) ob = g3;
  else if(i==4) ob = g4;
  else if(i==5) ob = g5;
  else {
    write("That is an invalid choice.\n");
    return 1;
  }
  if(!ob) {
    write("That gate does not exist.\n");
    return 1;
  }
  if(this_player()->query_sp()<30) {
    write("You do not have enough spell points to do that yet.\n");
    return 1;
  }
  if(environment(this_player())->realm()=="NT") {
    write("The gate cannot open in this room.\n");
    return 1;
  }
  lessp(30);
  say(capitalize(NAME)+" steps behind his shadow and disappears.\n");
  write("You step behind your shadow and arrive in a new place.\n");
  move_object(this_player(),environment(ob));
  command("look",this_player());
  say(capitalize(NAME)+" steps out from behind his shadow.\n");
  return 1;
}

gate_drop() {
  int i;
  object ob;
  if(this_player()->query_sp()<35) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(environment(this_player())->realm()=="NT") {
    write("You cannot drop a gate in this room.\n");
    return 1;
  }
  ob = clone_object("/players/grimm/closed/obj/badge_stuff/gate");
  move_object(ob,environment(this_player()));
  if(!gate1) { gate1 = 1; g1 = ob; }
  else if(!gate2) { gate2 = 1; g2 = ob; }
  else if(!gate3) { gate3 = 1; g3 = ob; }
  else if(!gate4) { gate4 = 1; g4 = ob; }
  else if(!gate5) { gate5 = 1; g4 = ob; }
  else {
    write("You have dropped your limit.  Remove one of your gates.\n");
    destruct(ob);
    return 1;
  }
  lessp(35);
  write("You drop the gate.\n");
  say(capitalize(NAME)+" rips a hole behind his shadow.\n");
}

gate_remove() {
  gate_list();
  write("\nRemove which gate: ");
  input_to("y");
  return 1;
}

y(str) {
  int i;
  sscanf(str,"%d",i);
  if(!i) {
    write("Which gate do you want to remove?\n");
    return 1;
  }
  if(i==1) { if(g1) { gate1 = 0; destruct(g1); }
             else { write("That gate was not dropped.\n"); }}
  else if(i==2) { if(g2) { gate2 = 0; destruct(g2); }
                  else { write("That gate was not dropped.\n"); }}
  else if(i==3) { if(g3) { gate3 = 0; destruct(g3); }
                  else { write("That gate was not dropped.\n"); }}
  else if(i==4) { if(g4) { gate4 = 0; destruct(g4); }
                  else { write("That gate was not dropped.\n"); }}
  else if(i==5) { if(g5) { gate5 = 0; destruct(g5); }
                  else { write("That gate was not dropped.\n"); }}
  else { write("That is an invalid selection.\n"); }
return 1;
}

score() {
  this_player()->score();
  write("Guild Level: "+GLEVEL+"     Amount swapped: "+this_player()->query_guild_exp()+"\n");
  write("Current morph: "+capitalize(morph_name)+"\n");
  write("Current time:     "+ctime(time())+"\n");
  if(res_time>time()) { write("Next rescue time: "+ctime(res_time)+"\n"); }
  else { write("Next rescue time: Now\n"); }
  if(allowem) write("Allowing summons and steps.\n");
  else write("NOT Allowing summons and steps.\n");
  write("Drain set for: ");
  if(which_drain==1) {
    write("Spell points\n");
  } else {
    write("Hit points\n");
  }
  write("Wimpy Percent set at: "+wimp_cent+"%\n");
  write("Fang set at: "+fang_hit+"\n");
  return 1;
}

berserk() {
  object room,ob;
  int amt,dmg;

  if(GLEVEL<5) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(this_player()->query_spell_point() < 75) {
    write("You do not have enough spell points to attempt that.\n");
    return 1;
  }
  if(bztime>time()) {
    write("You are too tired from doing that a minute ago.\n");
    return 1;
  }
  if(!this_player()->query_attack()) {
    write("You aren't attacking anybody right now.\n");
    return 1;
  }
  amt = random(this_player()->query_sp());
  amt = (amt/4)*3;
  room = environment(this_player());
  bztime = time()+BZWAIT;
  lessp(amt);
  say(capitalize(NAME)+" goes berserk!\n");
  write("You go berserk!\n");
  ob = first_inventory(room);
  while(ob) {
    if(!present("badge of dopplegangers guild",ob)) {
      if(ob->query_npc() && !ob->query_pet()) {
        dmg = amt+random(30);
        write("You hit "+capitalize(ob->short())+".\n");
        say(capitalize(NAME)+" hits "+capitalize(ob->short())+".\n");
        if(ob!=this_player()->query_attack()) {
          if(ob->query_attack()) ob->stop_fight();
        }
        if(random(100)>50)
          ob->attack_object(this_player());
        ob->hit_player(dmg);
      }
    }
    if(!ob) {
      ob = find_object("sdlfkjsdlfkj");
      write("The death sooths your savage onslaught.\n");
    } else
      ob=next_inventory(ob);
  }
  write("You gasp for breath.\n");
  return 1;
}

title(str) {
if(GLEVEL<3) {
  write("You are not a high enough level to do that yet.\n");
  return 1;
}
if(this_player()->query_sp()<5) {
  write("You do not have enough spell points to do that.\n");
  return 1;
}
if(!str) {
  write("What do you want your new title to be?\n");
  return 1;
}
if(LEVEL>19) { this_player()->set_title(str); }
  else {
this_player()->set_title(str+" (p)");
 }
lessp(5);
write("Your title has been changed.\n");
return 1;
}

echo(str) {
if(GLEVEL < 2) {
  write("You are not a high enough level to do that yet.\n");
  return 1;
}
if(this_player()->query_sp()<2) {
  write("You do not have enough spell points to do that.\n");
  return 1;
}
if(!str) {
  write("What do you want to echo?\n");
  return 1;
}
say(str+"\n");
write("You echoed:\n"+str+"\n");
lessp(2);
return 1;
}

new_commands() {
  cat("/players/grimm/closed/obj/badge_stuff/new_commands");
  return 1;
}

other_guild() {
  string sex;
  string pk;
  object people, item;
  int i;
   string it;
  if(GLEVEL<4) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  write("\nPerson\t\tSex\tPK\tGuild\t\tLocation\n");
  write("------\t\t---\t--\t-----\t\t--------\n");
  people=users();
  for(i=0;i<sizeof(people);i++) {
/* Changed the following - Rumplemintz
    if(present("seal",people[i])) it="Mason";
    else if(present("pentagram",people[i])) it="Alchemist";
    else if(present("mages_guild_object",people[i])) it="Mages";
    else if(present("thief guild",people[i])) it="Thief";
    else if(present("Dopple-Faction",people[i]) && FINAL < time()) { it="D-"+present("Dopple-Faction",people[i])->query_dopp_ow(); }
    else if(present("badge of dopplegangers guild",people[i])) it="DOPPLE!";
    else if(present("license",people[i])) it="Assassin";
    else if(present("robes",people[i])) it="Cleric";
    else if(present("vampirefangs",people[i])) it="Vampire";
    else if(present("books",people[i])) it="Necro";
    else it="None";
*/
    switch(people[i]->query_guild_name()) {
    case "doppleganger": it = "DOPPLE!"; break;
    case "Knights Templar": it = "Knight"; break;
    case "rangers": it = "Ranger"; break;
    case "polymorph": it = "Poly"; break;
    case "fallen": it = "Fallen"; break;
    case "vampires": it = "Vampire"; break;
    case "warrior": it = "Warrior"; break;
    case "necromancer": it = "Necro"; break;
    case "dervish": it = "Dervish"; break;
    case "mage": it = "Mage"; break;
    case "samurai": it = "Samurai"; break;
    case "bloodfist": it = "Bloodfist"; break;
    case "shardak": it = "Shardak"; break;
    case "neo symbiote": it = "Neos"; break;
    case "black circle": it = "BC Mage"; break;
    case "cyberninja": it = "Cybers"; break;
    case "healer": it = "Healer"; break;
    case "bard": it = "Bard"; break;
    case "monks": it = "Monk"; break;
    default: it = "None"; break;
    }
/*
    if(!people[i]->query_invis() || LEVEL > 19 ) {
*/
    if(people[i]->query_invis()<LEVEL) {
      if(!people[i]->query_invis()) {
      write(capitalize(people[i]->query_real_name()));
      } else {
        write("("+capitalize(people[i]->query_real_name())+")"); }
      if(strlen(people[i]->query_real_name())>7) write("\t");
      else write("\t\t");
      sex=people[i]->query_gender();
      if(sex=="male") sex="M";
      else if(sex=="female") sex="F";
      else sex="C";
      write(sex+"\t");
      if(people[i]->query_pl_k()) write("Y \t");
      else write("N \t");
      write(it);
      if(strlen(it)>7) write("\t");
      else write("\t\t");
      if(!environment(people[i])) { write("<Logging In>\n"); }
      else
      write(environment(people[i])->short()+"\n");
    }
    }
return 1;
}

direct(str) {
  string person;
  int x;
  object ob;
  if(GLEVEL<5) {
    write("You do are not a high enough level to do that yet.\n");
    return 1;
  }
  sscanf(str,"%d %s",x,person);
  if(!str || !x || !person) {
    write("Usage is:\ndirect <X> <player>\n");
    return 1;
  }
  if(x>this_player()->query_sp()) {
    write("You do not have that many spell points.\n");
    return 1;
  }
  if(!find_player(person)) {
    write("That person is not on right now.\n");
    return 1;
  }
  if(!present("badge of dopplegangers guild",find_player(person))) {
    write("That person is not in the guild.\n");
    return 1;
  }
  if(x < 0) {
    write("Negative inputs are illegal.\n");
    return 1;
  }
  lessp(x);
  write("You direct "+x+" of your spell points at "+capitalize(person)+".\n");
  ob = find_player(person);
  tell_object(ob,capitalize(NAME)+" directs "+x+" spell points at you.\n");
  ob->add_spell_point(x-(x/10));
  return 1;
}

wimp_set(str) {
  int x;
  if(!str) {
    write("What percentage do you want to set wimpy at?\n");
    return 1;
  }
  sscanf(str,"%d",x);
  wimp_cent = x;
  write("Wimpy set at: "+wimp_cent+"%\n");
  return 1;
}

demontouch(str) {
  int i,j,k;
  object it;
  if(GLEVEL<9) {
    write("You are not a high enough level to do that.\n");
    return 1;
  }
  i = 200;
  j = this_player()->query_hp()-random(30)-random(30);
  if(j<30) j = 30;
  k = (i+j)*2;
  if(this_player()->query_sp()<i) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(!str && !this_player()->query_attack()) {
    write("What do you want to touch?\n");
    return 1;
  }
  if(!this_player()->query_attack()) it = present(str,environment(this_player()));
  else it = this_player()->query_attack();
  if(!(it = present(str,environment(this_player())))) {
    write("That is not here.\n");
    return 1;
  }
  if(it->query_hp()<k) k = (it->query_hp()) - 25;
  if(!this_player()->query_attack()) this_player()->attack_object(it);
  it->hit_player(k);
  this_player()->add_hit_point(-j);
  lessp(i);
  return 1;
}
smelt(str) {
  object ob;
  int amt;
  if(GLEVEL<3) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<20) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(!str) {
    write("What do you want to smelt?\n");
    return 1;
  }
  ob = present(str,this_player());
  if(!ob) {
    write("You do not have one of those.\n");
    return 1;
  }
  amt = ob->query_value();
  if(amt>1000) {
    amt = 1000 + random(700);
  }
  this_player()->add_money(amt);
  command("drop "+str,this_player());
  destruct(ob);
  write("A small 'ganger comes and takes the item away from you and gives you "+amt+" coins.\n");
  say("A small 'ganger comes and takes an item away from "+capitalize(NAME)+" and \ngives him some coins for it.\n");
  lessp(20);
  return 1;
}


date_news() {
  string i;
  i=ctime(time());
  if(GLEVEL<1000) {
    write("YOU certainly didn't write the guild, forget it bub.\n");
    return 1;
  }
  rm("/players/grimm/closed/obj/badge_stuff/newsdate");
  write_file("/players/grimm/closed/obj/badge_stuff/newsdate",i);
  write("Done, Master.\n");
  write("Time is: "+ctime(time())+"\nLast read time is: "+ctime(last_read)+"\n");
  if(ctime(time()) > ctime(last_read)) write("Time is greater.\n");
  else write("Last read was greater.\n");
  return 1;
}

step(str) {
  object ob;
  if(GLEVEL<5) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(!str) {
    write("Who do you want to step out from behind?\n");
    return 1;
  }
  if(this_player()->query_sp()<65) {
    write("You do not have enough spell points to do that.\n");
    return 1;
  }
  if(!find_living(str)) {
    write("That player is not on the game right now.\n");
    return 1;
  }
  ob = find_living(str);
  if(query_morphed()) {
    write("You cannot step while in morph.\n");
    return 1;
  }
  if(ob->query_level()>19) {
    write("You cannot step to a wizard.\n");
    return 1;
  }
  if(!present("badge of dopplegangers guild",ob)) {
    write("That player is not a member of the guild.\n");
    return 1;
  }
  if(present("badge of dopplegangers guild",ob)->query_allowem()==0) {
    write("That person is not allowing steps right now.\n");
    return 1;
  }
  if(environment(ob)->realm()=="NT") {
    write("Something in that room is blocking you.\n");
    return 1;
  }
  if(environment(this_player())->realm()=="NT") {
    write("Something in this room is blocking you.\n");
    return 1;
  }
  lessp(65);
  write("You step behind your shadow and arrive next to "+capitalize(str)+".\n");
  say(capitalize(NAME)+" steps behind his shadow and disappears.\n");
  if(present("badge of dopplegangers guild",ob)->query_morphed()) {
    move_object(this_player(),environment(environment(ob)));
 } else
  move_object(this_player(),environment(ob));
  say(capitalize(NAME)+" steps out from behind "+capitalize(str)+"'s shadow.\n");
  return 1;
}


coat(str) {
  int was, to_be;
  object ob;
  string pre, post; /* Rumplemintz */

  if(GLEVEL<6) {
    write("You are not a high enough guild level to do that yet.\n");
    return 1;
  }
  if(!str) {
    write("What do you want to coat?\n");
    return 1;
  }

  ob = present(str, this_player());
  if (!ob) {
    write("You do not have one of those.\n");
    return 1;
  }
  was = ob->weapon_class();
  if (!was) {
    write("That is not a weapon.\n");
    return 1;
  }
  if(was>20) {
    write("That weapon is powerful enough.\n");
    return 1;
  }
  if (sscanf(ob->short(), "%s [Poison tipped]%s", pre, post) == 2) {
    write("That weapon is already coated in poison.\n");
    return 1;
  }
  to_be=was+1;
  if(this_player()->query_sp()<75) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  ob->set_short(ob->short() + " [Poison tipped]");
  call_out("remove_poison", 1800, ob);
  lessp(75);
  ob->set_class(to_be);
  write("You coat the weapon with poison.\n");
  write("Be sure to wield your weapon again.\n");
  ob->stopwield();
  say(this_player()->query_name() + " coats " +
      this_player()->query_possessive() + " weapon with poison.\n");
  return 1;
}

int remove_poison(object obj) { /* Rumplemintz */
  string pre, post;

  if (!obj) return 1;
  if (sscanf(obj->short(), "%s [Poison tipped]%s", pre, post) != 2)
    return 1;
  obj->set_class((int)obj->weapon_class() - 1);
  obj->set_short(pre + post);
  tell_object(environment(obj),
    "The poison on " + obj->short() + " wears off.\n");
  obj->stopwield();
  return 1;
}

safe() {
  if(GLEVEL<7) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<40) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  safe_ob = environment(this_player());
  if(safe_ob->realm()=="NT") {
    write("Something in the room prevents you from hiding.\n");
    return 1;
  }
  say(capitalize(NAME)+" ducks behind his shadow running for cover.\n");
  move_object(this_player(),"/players/grimm/closed/obj/badge_stuff/hide");
  say(capitalize(NAME)+" arrives.\n");
  command("look",this_player());
  write("You run for cover and arrive in the guild's hiding place.\n");
  lessp(40);
  return 1;
}

bak_hide() {
  if(GLEVEL<7) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(!environment(this_player())->query_hiding_place()) {
    write("You are not in the guild's hiding place.\n");
    return 1;
  }
  if(!safe_ob) {
    write("Your return room is messed up...sending you to the church.\n");
    say(capitalize(NAME)+" disappears.\n");
    move_object(this_player(),"/room/church");
    command("look",this_player());
    say(capitalize(NAME)+" arrives.\n");
    return 1;
  }
  say(capitalize(NAME)+" disappears.\n");
  move_object(this_player(),safe_ob);
  safe_ob=0;
  command("look",this_player());
  write("You go back to your origin point.\n");
  say(capitalize(NAME)+" arrives.\n");
  return 1;
}


jerky() {
  object ob;
  string nme;
  if(GLEVEL<6) {
    write("You are not a high enough guild level to do that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<5) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  ob=present("corpse",this_player());
  if(!ob) ob = present("corpse",environment(this_player()));
  if(!ob) {
    write("There is no corpse here.\n");
    return 1;
  }
  sscanf(ob->short(),"corpse of %s",nme);
  if(!nme) {
    write("The name of the corpse was not found...aborting...\n");
    return 1;
  }
  lessp(5);
  environment(ob)->add_weight(-(ob->query_weight()));
  destruct(ob);
  ob = clone_object("/players/grimm/closed/obj/badge_stuff/jerky");
  ob->set_nme(nme);
  move_object(ob,this_player());
  say(capitalize(NAME)+" makes jerky out the corpse of a "+capitalize(nme)+".\n");
  write("You make jerky out of the corpse of a "+capitalize(nme)+".\n");
  return 1;
}

spice() {
  object ob;
  int x;
  if(GLEVEL<7) {
    write("You are not a high enough level for that yet.\n");
    return 1;
  }
  if(!(ob = present("jerky",this_player()))) {
    write("You do not have any jerky on you.\n");
    return 1;
  }
  if(this_player()->query_sp()<5) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  x = ob->query_jerk();
  if(x>40) {
    write("The jerky is already spicy enough to kill a rhino!\n");
    return 1;
  }
  ob->add_jerk(4);
  lessp(5);
  write("You spice up some "+ob->short()+".\n");
  say(capitalize(NAME)+" spices up some "+ob->short()+".\n");
  return 1;
}

shift() {
  if(shift_flag==1) {
    write("You are already shifting.\n");
    return 1;
  }
  if(GLEVEL<8) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<25) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  lessp(25);
  this_player()->add_ac(4);
  shift_flag=1;
  write("You begin to distort yourself, making it harder for you to be hit.\n");
  say("Your vision of "+capitalize(NAME)+" blurs as he distorts his figure.\n");
  call_out("stop_shift",90,this_player());
  return 1;
}

stop_shift(ob) {
  shift_flag = 0;
  ob->add_ac(-4);
  tell_object(ob,"You stop distorting yourself due to exhaustion.\n");
  return 1;
}

jump(str) {
  object ob;
  if(GLEVEL<8) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<75) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(!str) {
    write("Who do you want to jump to?\n");
    return 1;
  }
  if(!(ob=find_player(str))) {
    write("That player is not on right now.\n");
    return 1;
  }
  if(environment(ob)->realm()=="NT") {
    write("Something in that room is blocking you from jumping.\n");
    return 1;
  }
  if(environment(this_player())->realm()=="NT") {
    write("Something in this room is blocking you from jumping.\n");
    return 1;
  }
  if(ob->query_level()>19) {
    write("You cannot jump to wizards.\n");
    return 1;
  }
  say(capitalize(NAME)+" takes a flying leap behind his shadow.\n");
  move_object(this_player(),environment(ob));
  say(capitalize(NAME)+" takes a flying leap out from behind "+capitalize(str)+"'s shadow.\n");
  write("You jump out from behind "+capitalize(str)+"'s shadow.\n");
  lessp(75);
  return 1;
}

summon(str) {
  object ob;
  if(GLEVEL<7) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<65) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(!str) {
    write("Who do you want to summon?\n");
    return 1;
  }
  if(!(ob=find_player(str))) {
    write("That player is not on right now.\n");
    return 1;
  }
  if(environment(ob)->realm()=="NT" || environment(this_player())->realm()=="NT") {
    write("Something is blocking you from summoning that player.\n");
    return 1;
  }
  if(!present("badge of dopplegangers guild",ob)) {
    write("That player is not a member of the guild.\n");
    return 1;
  }
  if(present("badge of dopplegangers guild",ob)->query_allowem()==0) {
    write("That player is not allowing summons at this time.\n");
    return 1;
  }
  if(ob->query_attack()) {
    write("That person is attacking at the moment.\n");
    return 1;
  }
  if(ob->query_level()>19) {
    write("You cannot summon a wizard.\n");
    return 1;
  }
  tell_room(environment(ob),"A hand pops out from behind "+
            capitalize(ob->query_name())+" and pulls "+
            "him through.\n");
  tell_object(ob,"A hand pops out from behind your "+
              "shadow and pulls you through.\n");
  write("You reach behind your shadow and pull "+
        capitalize(ob->query_name())+
              " out of it.\n");
  lessp(65);
  say(capitalize(NAME)+" reaches behind his "+
      "shadow and pulls "+capitalize(ob->query_name())+
            " from it.\n");
  move_object(ob,environment(this_player()));
  return 1;
}

sleep(str) {
  int x;
  if(GLEVEL<8) {
    write("You are not a high enough level for that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<50) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(this_player()->query_attack()) {
    write("You are attacking something! You are in no mood to sleep.\n");
    return 1;
  }
  if(!str) {
    write("How long do you want to sleep?\n");
    return 1;
  }
  if(!(sscanf(str,"%d",x))) {
    write("That was an invalid choice.\n");
    return 1;
  }
  lessp(50);
  sleep_time = (x*60) + time();
  sleep_amt = (x*60) / 5;
  this_player()->add_hit_point(sleep_amt);
  write("You fall into a deep sleep.\n");
  write("->> ");
  say(capitalize(NAME)+" falls into a deep sleep.\n");
  input_to("sleepin");
  return 1;
}

sleepin(str) {
  if(str=="wake" || str=="Wake" || str=="WAKE") {
    write("You startle from your sleep and sprain your back in the process.\n");
    say(capitalize(NAME)+" is startled from his sleep and jumps as he wakes up.\n");
    if((sleep_time - time())/5 > this_player()->query_hp()) {
      this_player()->add_hit_point(this_player()->query_hp()-1);
    } else
    this_player()->add_hit_point(-((sleep_time - time())/5));
    return 1;
  }
  if(time()>sleep_time) {
    write("You wake from a peaceful slumber.\n");
    say(capitalize(NAME)+" wakes from a long sleep.\n");
    return 1;
  }
  write("You are asleep! To wake up prematurely type \"wake\".\n");
  write("The time is currently:      "+ctime(time())+"\n");
  write("Wake time is scheduled for: "+ctime(sleep_time)+"\n");
  write("->> ");
  input_to("sleepin");
}

guard(str) {
  object ob;
  if(GLEVEL<6) {
    write("You are not a high enough level for that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<10) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(!str || !present(str,environment(this_player()))) {
    write("That is not here.\n");
    return 1;
  }
  lessp(10);
  ob = clone_object("/players/grimm/closed/obj/badge_stuff/marker");
  ob->set_owner(this_player()->query_real_name());
  ob->set_monster(str);
  move_object(ob,environment(this_player()));
  ob->go();
  write("You drop a marker to guard a "+capitalize(str)+".\n");
  say(capitalize(NAME)+" drops a marker to guard a "+capitalize(str)+".\n");
  return 1;
}

pet() {
  if(GLEVEL<6) {
    write("You are not a high enough level for that yet.\n");
    return 1;
  }
  if(player_env()==MORPH) {
    write("You must be human to do this.\n");
    return 1;
  }
  if(QFACT)
  if(NOPET) {
    write("Your faction does not allow normal pets.\n");
    return 1;
  }
  if(present("pet",environment(this_player()))) {
    if(present("pet",environment(this_player()))->query_owner()==this_player()->query_real_name()) {
    write("You already have a pet.\n");
    return 1;
  }
  }
  if(this_player()->query_sp()<100) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  say(capitalize(NAME)+" summons his pet to his side.\n");
  write("You summon a pet.\n");
  ob = clone_object("/players/grimm/closed/obj/badge_stuff/pet");
  ob->set_owner(this_player()->query_real_name());
  move_object(ob,environment(this_player()));
  ob->go();
  lessp(100);
  return 1;
}
setmylev(str) {
  int x;
  string who;
  if(GLEVEL<(GCLVL+10) && this_player()->query_name()!="grimm") {
    write("NOT!\n");
    return 1;
  }
  if(!sscanf(str,"%s %d",who,x)) {
    write("Try again.\n");
    return 1;
  }
  if(!find_living(who)) {
    write("Aint on the game dood.\n");
    return 1;
  }
  find_living(who)->add_guild_rank(x-(find_living(who)->query_guild_rank()));
  write("Done.\n");
  return 1;
}

commander_tell(str) {
  object people;
  object bad;
  int n, x;
  if(GLEVEL<GCLVL) {
    write("You are not a guild commander!\n");
    return 1;
  }
  people=users();
  for(n=0;n<sizeof(people);n++)
    if(present("badge of dopplegangers guild",people[n]) && people[n]->query_guild_rank()>(GCLVL-1))
      if(present("badge of dopplegangers guild",people[n])->query_shaddup()==0)
#if 0
      tell_object(people[n],">>"+capitalize(this_player()->query_real_name())+
                  "<<: "+str+"\n");
#else
      tell_object(people[n], HIR + ">>" + this_player()->query_name() +
                  "<<: " + NORM + str + "\n");
#endif
  return 1;
}
/* commandershit */
commander_help() {
  if(GLEVEL<GCLVL) {
    write("You are not a guild commander.\n");
    return 1;
  }
  cat("/players/grimm/closed/obj/badge_stuff/commander_help");
  return 1;
}

query_them(str) {
  object per;
  if(GLEVEL<GCLVL) {
    write("You are not a guild commander.\n");
    return 1;
  }
  if(!str) {
    write("Who do you want to get a query of?\n");
    return 1;
  }
  if(!find_living(str)) {
    write("That person is not on right now.\n");
    return 1;
  }
  per = find_living(str);
  if(!present("badge of dopplegangers guild",per)) {
    write("That player is not a guild member.\n");
    return 1;
  }
  write("Name:         "+capitalize(per->query_real_name())+"\n");
  write("Guild Exp:    "+per->query_guild_exp()+"\n");
  write("Guild Level:  "+per->query_guild_rank()+"\n");
  write("Actual Level: "+per->query_level()+"\n");
  return 1;
}

badgify(str) {
   object bad, per;
  if(GLEVEL<GCLVL) {
    write("You are not a guild commander.\n");
    return 1;
  }
  if(!str) {
    write("Who do you want to badgify?\n");
    return 1;
  }
  if(!find_living(str)) {
    write("That player is not online right now.\n");
    return 1;
  }
  bad = clone_object("/players/grimm/closed/obj/badge");
  per = find_living(str);
  if(per->query_level() < 3) {
    write("A player must be at least level 3 to join a guild.\n");
    return 1;
  }
  per->add_guild_exp(1);
  per->set_guild_name("doppleganger");
  move_object(bad,find_living(str));
  write_file("/players/grimm/closed/LOGS/badgify",capitalize(NAME)+" just gave "+capitalize(per->query_real_name())+" a badge.\nThe time is: "+ctime(time())+"\n------------------------\n");
  write("Done.\n");
  tell_object(find_living(str),"You now have a Doppleganger badge!\n");
  return 1;
}

revoke(str) {
  object bad, per;
  int exp,minus;
  if(GLEVEL<GCLVL) {
    write("You are not a guild commander.\n");
    return 1;
  }
  if(!str) {
    write("Who's badge do you want to revoke?\n");
    return 1;
  }
  if(str=="grimm" ||
     str=="blue" ||
     str=="darq" ||
     str=="pavlik" ||
     str=="hawkeye" ||
     str=="hellbent") {
    write(capitalize(str)+" laughs in your face!\n");
    return 1;
  }
  if(!find_living(str)) {
    write("That player is not online right now.\n");
    return 1;
  }
  per = find_living(str);
  bad = present("badge of dopplegangers guild",per);
  exp = per->query_exp();
  minus = exp/6;
  per->add_exp(-minus);
  destruct(bad);
  per->add_guild_rank(-(per->query_guild_rank()));
  per->set_guild_name(0);
  per->add_guild_exp(-(per->query_guild_exp()));
  tell_object(per,"Your badge has been revoked!\n");
  write_file("/players/grimm/closed/LOGS/revoked",capitalize(NAME)+" just revoked "+capitalize(per->query_real_name())+"\nThe time is: "+ctime(time())+"\n-----------------------\n");
  write("Done.\n");
/*
  "/players/grimm/guild"->scrap("REVOKED");
*/
  return 1;
}

promote(str) {
  int x;
  string son;
  object per;
  if(GLEVEL<GCLVL) {
    write("You are not a guild commander.\n");
    return 1;
  }
  if(!str) {
    write("Usage is:\npromote <player> <amount>\n");
    return 1;
  }
  sscanf(str,"%s %d",son,x);
  if(!find_living(son)) {
    write("That person is not on the game right now.\n");
    return 1;
  }
  per = find_living(son);
  if(per->query_guild_rank()>15) {
    write("You cannot touch that person.\n");
    return 1;
  }
  if(per->query_guild_rank()+x>15) {
    write("You can only promote somebody to level 15 max.\n");
    return 1;
  }
  if(per->query_guild_rank()+x<1) {
    write("Level 1 is the lowest that they can go.\n");
    return 1;
  }
  per->add_guild_rank(x);
  tell_object(per,capitalize(NAME)+" promoted you in the guild.\n");
  write_file("/players/grimm/closed/LOGS/promoted",capitalize(NAME)+" just promoted "+capitalize(per->query_real_name())+"\nby "+x+" levels.\nThe time is: "+ctime(time())+"\n------------------------------\n");
  write("Done.\n");
  return 1;
}

banish(str) {
  object ob;
  if(GLEVEL<GCLVL) {
    write("You are not a guild commander!\n");
    return 1;
  }
  if(!str) {
    write("Who do you want to banish?\n");
    return 1;
  }
  if(!find_player(str)) {
    write("That player isnt online right now.\n");
    return 1;
  }
  ob = find_player(str);
  if(!present("badge of dopplegangers guild",ob)) {
    write("That player is not a member of the guild.\n");
    return 1;
  }
  revoke(str);
  ob->add_guild_exp(123);
  tell_object(ob,"See Grimm for any problems.\n");
  write_file("/players/grimm/closed/LOGS/banished",capitalize(NAME)+" just banished "+capitalize(ob->query_real_name())+"\nThe time is: "+ctime(time())+"\n---------------------\n");
  write("That player has been banished from all guilds.\nTell them to go to Grimm if they bitch.\n");
  return 1;
}
#if 1 /* Rumplemintz */
white(str) { return str; }
red(str) { return str; }
#else
white(str) { return HIW + str; }
red(str) { return RED + str; }
#endif

calm() {
  object ob;
  if(GLEVEL<9) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<50) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  lessp(50);
  ob = first_inventory(environment(this_player()));
  while(ob) {
    if(ob->query_attack())
     {   ob->query_attack()->stop_fight();
      ob->stop_fight();
    }
    ob = next_inventory(ob);
  }
  write("You raise your hands in a magical gesture and stop all fighting in the room.\n");
  say(capitalize(NAME)+" raises his hands in a magical gesture and stops all\nfighting in the room.\n");
  return 1;
}

vandalize() {
  object ob;
  if(GLEVEL<9) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<20) {
    write("You do not have enough spell points to do that yet.\n");
  return 1;
  }
  ob = clone_object("/players/grimm/closed/obj/badge_stuff/vandal");
  ob->set_nme(this_player()->query_real_name());
  ob->reset();
  move_object(ob,environment(this_player()));
  write("You spray your name all over the walls.\n");
  say(capitalize(this_player()->query_real_name())+" sprays his name all over the walls.\n");
  lessp(20);
  return 1;
}

scare(str) {
  object ob;
  if(GLEVEL<9) {
    write("You are not a high enough level for that yet.\n");
    return 1;
  }
  if(!str) {
    write("Who do you want to scare?\n");
    return 1;
  }
  if(this_player()->query_sp()<25) {
    write("You do not have enough spell points for that.\n");
     return 1;
  }
  if(!(ob=find_living(str))) {
    write("That player is not online.\n");
    return 1;
  }
  if(!present(str,environment(this_player()))) {
    write("That player is not in the room.\n");
    return 1;
  }
  tell_object(ob,capitalize(NAME)+" scares the hell out of you.\n");
  ob->run_away();
  lessp(25);
  write("You scare the hell out of "+capitalize(str)+".\n");
  say(capitalize(NAME)+" scares the hell out of "+capitalize(str)+".\n");
  return 1;
}

fang_set(str) {
  int x;
  if(!str) {
    write("What do you want your fang to be set at? (MAX: "+HIT+")\n");
    return 1;
  }
  if(!(sscanf(str,"%d",x))) {
    write("What?\n");
    return 1;
  }
  if(x>HIT) x = HIT;
  if(x<1) x = 1;
  fang_hit = x;
  write("Fang is now set to do "+fang_hit+" damage.\n");
  return 1;
}

allow_tog() {
  if(allowem) {
    allowem=0;
    write("NOT Allowing summons and steps.\n");
    return 1;
  }
  allowem=1;
  write("Allowing summons and steps.\n");
  return 1;
}

blade(str) {
  object ob;
  int ranum;
  if(GLEVEL<8) {
    write("You are not a high enough level for that.\n");
    return 1;
  }
  if(this_player()->query_sp()<20) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(this_player()->query_attack()) {
    if(!str) ob=this_player()->query_attack();
    else if(str==this_player()->query_attack()->query_name())
           ob=this_player()->query_attack();
         else if(present(str,environment(this_player())))
                ob=present(str,environment(this_player()));
              else {
                   write("That is not here.\n");
                   return 1;
                   }
  } else {
    if(!str) {
      write("Send bladestorm at what?\n");
      return 1;
    }
    if(present(str,environment(this_player())))
      ob=present(str,environment(this_player()));
    else
      { write("That is not here.\n");
        return 1;
      }
  }
  if(!ob->query_npc()) {
    write("That is not a monster.\n");
    return 1;
  }
  this_player()->attack_object(ob);
  ranum=random(100);
  if(ranum<50) {
    write("The bladestorm engulfs your prey.\n");
    say(capitalize(NAME)+" sends a bladestorm at "+capitalize(ob->query_name())+
        " tearing it to shreds.\n");
    ob->hit_player(20);
  }
  if(ranum>49 && ranum<75) {
    write("The bladestorm partially engulfs your prey.\n");
    say(capitalize(NAME)+" sends a bladestorm at "+capitalize(ob->query_name())+
        " but only partially engulfs it.\n");
    ob->hit_player(15);
  }
  if(ranum>74) {
    write("The bladestorm tears into your prey.\n");
    say(capitalize(NAME)+" sends a bladestorm at "+capitalize(ob->query_name())+
        " sending a fine red mist from it.\n");
    ob->hit_player(25);
  }
  lessp(20);
  return 1;
}

getem(GLEV,hit,sp,what,writemsg,saymsg) {
  object ob;
  if(GLEVEL<GLEV) {
    write("You are not a high enough level for that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<sp) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(present(what,environment(this_player())))
    ob=present(what,environment(this_player()));
  else { write("That is not here.\n");
          return 1;
    }
  if(!ob->query_npc()) {
    write("That is not a monster.\n");
    return 1;
  }
  this_player()->attack_object(ob);
  ob->hit_player(hit);
  lessp(sp);
  write(writemsg+".\n");
  say(saymsg+".\n");
  return 1;
}

blast(str) {
  string what,cwhat;
  if(str) what=str;
  else if(this_player()->query_attack())
         what=this_player()->query_attack()->query_name();
       else {
            write("Blast what?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  getem(7,15,15,what,"You blast a "+cwhat,CNAME+" blasts a "+cwhat);
  return 1;
}

strikeem(str) {
  string what,cwhat;
  if(str) what=str;
  else if(this_player()->query_attack())
         what=this_player()->query_attack()->query_name();
       else {
            write("Strike what?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  getem(9,40,40,what,"You strike down a "+cwhat,CNAME+" strikes a "+cwhat+
        " with the power of the ancients");
  return 1;
}

horde(str) {
  string what,cwhat;
  if(str) what=str;
  else if(this_player()->query_attack())
         what=this_player()->query_attack()->query_name();
       else {
            write("Send a horde on what?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  getem(6,30,30,what,"You send a horde of little dopples to beat the shit out of a "+cwhat,CNAME+" sends a horde of little dopplegangers against a "+cwhat);
  return 1;
}

meltem(str) {
  string what,cwhat;
  if(str) what=str;
  else if(this_player()->query_attack())
         what=this_player()->query_attack()->query_name();
       else {
            write("Melt who?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  getem(5,10,10,what,"You melt "+cwhat+"'s brain",CNAME+" melts "+cwhat+"'s brains");
  return 1;
}

speed() {
  object ob;
  if(GLEVEL<6) {
    write("You are not a high enough level for that yet.\n");
    return 1;
  }
  if(this_player()->query_sp()<20) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(present("speedster",this_player())) {
    write("You already have a Speedster.\n");
    return 1;
  }
  ob=clone_object("/players/grimm/closed/obj/speed");
  move_object(ob,this_player());
  write("You pull a speedster from your back pocket.\n");
  say(capitalize(NAME)+" pulls a Speedster out of his pocket.\n");
  lessp(20);
  return 1;
}
