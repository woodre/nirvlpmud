/* /players/wizardchild/liquid/masterob.c: Liquid Metal master object */
/* Again, this file is here for debugging and checking purposes only  */
#define THERE(s) present("metallic skin", s)
#define ROOT "players/wizardchild/liquid/"
#define TOP_KILLERS "players/wizardchild/liquid/toplist"
#define ME this_player()
#define ENV(ob) environment(ob)
#define CNAME(ob) (THERE(ob)->query_shape()?\
        (THERE(ob)->query_shape())->query_name():ob->query_name())
#define BLANKS\
"                                                                              "
inherit "players/wizardchild/liquid/object.c";
/* functions */
right_align(str, fieldsize) {
  int x;
  string out;
  x = fieldsize-strlen((str+" \b"));
  while(x) {
    if(!out) out = " ";
    else out += " ";
    x--;
  }
  out += str;
  return out;
}
checked_present(str, where) {
  object ob;
  if(THERE(ME)->query_shape())
    ob = present(str, ENV(THERE(ME)->query_shape()));
  else
    ob = present(str, where);
  return ob;
}
srandom(x) {
  /* lower chances if higher rank */
  if(THERE(ME)->query_rank()) x *= 3;
  return random(x);
}
remove_shape() {
  object ob;
  ob = THERE(ME)->query_shape();
  move_object(ME, environment(ob));
  destruct(ob);
  THERE(ME)->set_shape(0);
}
remove_target() {
  object ob;
  ob = THERE(ME)->query_target();
  if(present("liquid_combat_ob", ob))
    destruct(present("liquid_combat_ob", ob));
  THERE(ME)->set_target(0);
}
handle_kill(died, killer) {
  log_something(killer->query_real_name()+" killed "+died->query_real_name());
  killer->add_kill(1);
  TOP_KILLERS->add_kill(killer);
}
handle_death(dead_guy) {
  log_something(dead_guy->query_real_name()+" died");
  dead_guy->add_died(1);
  TOP_KILLERS->add_death(dead_guy);
}
log_something(str) {
  write_file(ROOT+"COMBAT","["+ctime(time())+"]: "+str+"\n");
}
/* commands */
lmmon(str) {
  int x;
  if(str == "on" || str == "combat")
    THERE(ME)->set_pkmon(1);
  else if(str == "always on")
    THERE(ME)->set_pkmon(2);
  else if(str == "off")
    THERE(ME)->set_pkmon(0);
  x = THERE(ME)->query_pkmon();
  write("Your PK monitor is now ");
  write((x==0?"off":(x==1?"in combat mode":"always on"))+".\n");
  return 1;
}
/* guild status */
lmstats() {
  int x;
  string hp, sp, xp, lv, kl, de, tt, kd, cm, mn, rn;
  string ta, sh;
  hp = extract("< Hit points: "+ME->query_hp()+" of "+ME->query_mhp()+BLANKS,0,78);
  sp = extract("< Spell pnts: "+ME->query_sp()+" of "+ME->query_msp()+BLANKS,0,78);
  lv = extract("< Level/Xlev: "+ME->query_level()+", "+ME->query_extra_level()+BLANKS,0,78);
  xp = extract("< Experience: "+ME->query_exp()+BLANKS,0,78);
  kl = extract("< PK Kills:   "+THERE(ME)->query_kills()+BLANKS,0,78);
  de = extract("< PK Death:   "+THERE(ME)->query_died()+BLANKS,0,78);
  tt = extract("< Targeted:   "+THERE(ME)->query_targeted()+BLANKS,0,78);
  x  = THERE(ME)->query_died()+THERE(ME)->query_kills();
  if(x) x = (THERE(ME)->query_kills()*100)/x;
  kd = extract("< Kill/Death: "+x+"%"+BLANKS,0,78);
  x  = THERE(ME)->query_targeted();
  if(x) x = (THERE(ME)->query_kills()*100)/x;
  cm = extract("< Completion: "+x+"%"+BLANKS,0,78);
  x  = THERE(ME)->query_pkmon();
  mn = (x==0?"Off":(x==1?"Combat mode":"Always on"));
  mn = extract("< PK Monitor: "+mn+BLANKS,0,78);
  rn = (THERE(ME)->query_rank()?"Expert":"Novice");
  rn = extract("< Guild Rank: "+rn+BLANKS,0,78);
  if(THERE(ME)->query_target()) ta = (THERE(ME)->query_target())->query_name();
  else ta = "Nobody";
  ta = extract("< Targeting:  "+ta+BLANKS,0,78);
  if(THERE(ME)->query_shape()) sh = (THERE(ME)->query_shape())->short();
  else sh = "Normal";
  sh = extract("< Your Shape: "+sh+BLANKS,0,78);
  write(" ______________________________________________________________________________\n");
  write("< ___________________Liquid Metal (Terminator) Guild Status___________________ >\n");
  write("</__________________/                                      \\__________________\\>\n");
  write(hp+">\n"); write(sp+">\n"); write(lv+">\n"); write(xp+">\n");
  write(kl+">\n"); write(de+">\n"); write(tt+">\n"); write(kd+">\n");
  write(cm+">\n"); write(mn+">\n"); write(rn+">\n"); write(ta+">\n");
  write(sh+">\n");
  write("<>____________________________________________________________________________<>\n");
  return 1;
}
/* guild help */
lmhelp(str) {
  if(!str) str = "liquid";
  if(file_size(ROOT+"help/"+str) < 1)
    write("There is no help on that topic.\n");
  else
    cat(ROOT+"help/"+str);
  return 1;
}
/* special kill */
kill(str) {
  object ob, ob2;
  if(!str) {
    write("Kill what?\n");
    return 1;
  }
  ob = checked_present(str, ENV(ME));
  if(!ob) {
    write("That is not here.\n");
    return 1;
  }
  if(ob == ME) {
    write("What? Attack yourself?\n");
    return 1;
  }
  if(ob == ME->query_attack()) {
    write("You are already fighting them.\n");
    return 1;
  }
  if(!living(ob)) {
    write(capitalize(str)+" is not a living thing!\n");
    say(this_player()->query_name()+" foolishly tries to attack "+str+".\n");
    return 1;
  }
  if(ob->is_player() || ob->crime_to_attack()) {
    ME->set_crime();
    if((ob2 = ME->query_weapon()))
      log_file("BAD_PLAYER",file_name(ob2)+"-->"+creator(ob2));
    log_file("BAD_PLAYER", "----"+ME->query_real_name()+" attacked "+str+"\n");
  }
  if(ob->is_player() && !ME->valid_attack(ob))
    clear_crime();
  else if(ob->is_player()) {
    ob2 = 0;
    if((ob2 = ob->query_attack())) {
      if(THERE(ob2) || present("liquid_combat_ob", ob))
        write("You are allowed to fight this person, but will not get a kill.\n");
    } else if(!(ob2 = THERE(ME)->query_target())) {
      write("You must target a person first.\n");
      return 1;
    }
    if(ob != ob2) {
      write("You must first kill the person you have targeted.\n");
      return 1;
    }
    /* there is no need to check validity, since targeting does that */
    if(!ME->query_weapon()) {
      write("You should wield your weapon first.\n");
      return 1;
    }
  }
  if(!ME->attack_object(ob))
    write("You can't attack "+capitalize(str)+"!\n");
  return 1;
}
/* set a target */
lmtarget(str) {
  object who, ob;
  if(!str) {
    write("Usage: lmtarget <who>\n");
    return 1;
  }
  if(THERE(ME)->query_target()) {
    write("You already target someone!\n");
    return 1;
  }
  if(!(who = find_player(str)) || who->query_invis() > 99) {
    write("Player not found.\n");
    return 1;
  }
  if(who->query_level() > 19) {
    write("You cannot target a Wizard!\n");
    return 1;
  }
  if(who == ME) {
    write("You cannot target yourself.\n");
    return 1;
  }
  if(!who->query_pl_k()) {
    write("That person is not a player killer.\n");
    return 1;
  }
  if(present("liquid_combat_ob", who)) {
    write("That person is already being targeted.\n");
    return 1;
  }
  if(ME->query_sp() < 10) {
    write("You lack the strength to focus upon someone.\n");
    return 1;
  }
  write("Player found. Targeting.\n");
  ob = clone_object(ROOT+"combatob");
  ob->set_targeted_by(ME);
  ME->add_spell_point(-10);
  THERE(ME)->add_targeted(1);
  move_object(ob, who);
  write(capitalize(str)+" is in "+environment(who)->short()+".\n");
  /* be nice and give them a hint..snicker */
  if(!srandom(5))
    tell_object(who, "You feel as if you are suddenly being watched.\n");
  return 1;
}
lmblock(str) {
  /*******REQUIRES room/room**********/
}
lmtouch(str) {
  object what;
  object *touched;
  if(!str) {
    write("Usage: lmtouch <what>\n");
    return 1;
  }
  what = checked_present(str, ENV(ME));
  if(!what || !what->short()) { /* if they can't see it, they can't touch it */
    write("That is not here.\n");
    return 1;
  }
  touched = THERE(ME)->query_touched();
  if(has_element(touched, what)) {
    write("You already have touched that item.\n");
    return 1;
  }
  if(num_elements(touched) == sizeof(touched)) {
    write("You cannot touch any more items.\n");
    return 1;
  }
  if(what->is_player() && what->query_level() > 19) {
    write("You cannot touch a Wizard!\n");
    return 1;
  }
  if(ME->query_spell_point() < 20) {
    write("You are too weak right now.\n");
    return 1;
  }
  ME->add_spell_point(-20);
  write("You touch "+str+".\n");
  write("From the information you gather, you can now adjust your shape to resemble\n");
  write("that of "+str+".\n");
  /* chance of detection */
  if(living(what) && !srandom(20))
    tell_object(what, CNAME(ME)+" touches you in a strange way.\n");
  THERE(ME)->set_touched(add_element(THERE(ME)->query_touched(), what));
  return 1;
}
lmhall() {
  if(ENV(ME)->realm()) {
    write("You cannot remove yourself from this room.\n");
    return 1;
  }
  write("You liquify yourself and slowly recede into the ground.\n");
  say(CNAME(ME)+" liquifies and slowly recedes into the ground.\n");
  move_object(this_object(), ROOT+"ghall");
  say("A silvery ooze solidifies into "+CNAME(ME)+".\n");
  command("look", ME);
  return 1;
}
lmlist() {
  object *arr;
  int i;
  arr = THERE(ME)->query_touched();
  if(!sizeof(arr)) {
    write("You have not touched any items.\n");
    return 1;
  }
  write("You have touched the following item(s):\n");
  for(i = 0; i < sizeof(arr); i++) {
    if(arr[i] != 0)
      write((i+1)+": ["+arr[i]->short()+"]\n");
  }
  write("Done.\n");
  return 1;
}
lmmelt(str) {
  object *arr;
  object ob;
  object mirror;
  int x;
  arr = THERE(ME)->query_touched();
  arr = sort_arr(arr);
  if(!str) {
    write("Usage: lmmelt <objectname>  or  lmmelt <objectnum>\n");
    return 1;
  }
  if(THERE(ME)->query_shape()) {
    write("You already have a shape. Use \"lmmeltoff\" to return to normal.\n");
    return 1;
  }
  if(ME->query_sp() < 40) {
    write("You lack the power to change shapes.\n");
    return 1;
  }
  if(sscanf(str, "%d", x)) {
    x--;
    if(x < 0 || x >= sizeof(arr)) {
      write("Number out of bounds.\n");
      return 1;
    }
    if(arr[x] == 0) {
      write("No such shape.\n");
      return 1;
    }
    ob = arr[x];
  } else {
    /* i'm sorry, this is inefficient */
    for(x = 0; x < sizeof(arr); x++) {
      if(arr[x] != 0 && arr[x]->id(str)) {
        ob = arr[x];
        break;
      }
    }
  }
  if(!ob) {
    write("No such shape.\n");
    return 1;
  }
  write("You have chosen "+ob->short()+" as a shape.\n");
  write("Slowly, and with much effort, you adjust your body to look like it.\n");
  mirror = clone_object(ROOT+(living(ob)?"liveob":"deadob"));
  mirror->set_mirror_of(ob);
  if(!srandom(30))
    say("Something in the room has changed...\n");
  move_object(mirror, ENV(ME));
  move_object(ME, mirror);
  ME->add_spell_point(-40);
  THERE(ME)->set_shape(mirror);
  return 1;
}
lmmeltoff() {
  object ob;
  if(!(ob = THERE(ME)->query_shape())) {
    write("You are already in your normal state.\n");
    return 1;
  }
  if(ME->query_sp() < 15) {
    write("You are too weak to alter your physical appearance.\n");
    return 1;
  }
  write("You stress yourself, and slowly, your appearance changes from that of\n");
  write(ob->short()+" to your own.\n");
  ME->add_spell_point(-15);
  move_object(ME, ENV(THERE(ME)->query_shape()));
  destruct(THERE(ME)->query_shape());
  THERE(ME)->set_shape(0); /* just in case.. */
  if(!srandom(20))
    say(CNAME(ME)+" returns to "+ME->query_possessive()+" state.\n");
  return 1;
}
lmwho() {
  string nm, rn, en, ta;
  object ob, t;
  int i;
  ob = users();
  write(" _____________________________________________________________________________\n");
  write("< ____________________________Liquid Metal Guild_____________________________ >\n");
  write("</_Name__________Rank________/     target?      \\____Room____________________\\>\n");
  for(i = 0; i < sizeof(ob); i++) {
    if(THERE(ob[i]) && ob[i]->query_invis() < ME->query_level()) {
      nm = extract("< "+ob[i]->query_name()+BLANKS, 0, 15);
      rn = extract((THERE(ob[i])->query_rank()?"Expert":"Novice")+BLANKS,0,17);
      t  = THERE(ob[i])->query_target();
      ta = (t?t->query_name():"None");
      ta = extract(ta+BLANKS,0,17);
      if(ENV(ob[i])) en = ENV(ob[i])->short();
      else en = "No location";
      en = extract(en+BLANKS,0,24);
      write(nm+rn+ta+en+" >\n");
    }
  }
  write("<\\___________________________________________________________________________/>\n");
  return 1;
}
lmudw() {
  string nm, lv, gn, en;
  object ob, t;
  int i;
  ob = users();
  write(" _____________________________________________________________________________\n");
  write("< ________________________________Nirvana Who________________________________ >\n");
  write("</_Name__________Level___________/ Guildname \\________Room___________________\\>\n");
  for(i = 0; i < sizeof(ob); i++) {
    if(ob[i]->query_invis() < ME->query_level()) {
      nm = extract("< "+ob[i]->query_name()+BLANKS, 0, 14);
      lv = ob[i]->query_level();
      lv = extract(right_align(lv,8)+BLANKS,0,18);
      gn = ob[i]->query_guild_name();
      if(!gn) gn = "None";
      else gn = capitalize(gn);
      gn = extract(gn+BLANKS, 0, 18);
      if(!ENV(ob[i])) en = "No location";
      else en = ENV(ob[i])->short();
      en = extract(en+BLANKS,0,23);
      write(nm+lv+gn+en+" >\n");
    }
  }
  write("<\\___________________________________________________________________________/>\n");
  return 1;
}
lmt(str) {
  string msg;
  object ob;
  int i;
  ob = users();
  if(!str) {
    write("Usage: lmt <str>  or  lmt :<str>  or  lmt off  or  lmt on\n");
    return 1;
  }
  if(str == "off" || str == "on") {
    THERE(ME)->set_chan((str=="off"?0:1));
    write("You concentrate briefly, and your ears ");
    write((THERE(ME)->query_chan()?"form":"melt away")+".\n");
    return 1;
  }
  if(str[0] == ':') {
    sscanf(str, ":%s", msg);
    msg = "<Liquid> "+ME->query_name()+" "+msg;
  } else
    msg = "<"+ME->query_name()+">: "+str;
  for(i = 0; i < sizeof(ob); i++) {
    if(THERE(ob[i]) && THERE(ob[i])->query_chan())
      tell_object(ob[i], msg+"\n");
  }
  return 1;
}
mblock(str) {
 /*******REQUIRES room/room*********/
}
lmuntouch(str) {
  object ob;
  object *arr;
  int i;
  if(!str) {
    write("Usage: lmuntouch <objectname>  or  lmuntouch <objectnum>\n");
    return 1;
  }
  if(ME->query_sp() < 10) {
    write("You are too weak to use your powers.\n");
    return 1;
  }
  arr = THERE(ME)->query_touched();
  arr = sort_arr(arr);
  if(sscanf(str, "%d", i)) {
    i--;
    if(i < 0 || i >= sizeof(arr)) {
      write("Number out of bounds.\n");
      return 1;
    }
    if(arr[i] == 0) {
      write("No such shape.\n");
      return 1;
    }
    ob = arr[i];
  } else {
    for(i = 0; i < sizeof(arr); i++) {
      if(arr[i] != 0 && arr[i]->id(str)) {
        ob = arr[i];
        break;
      }
    }
  }
  if(!ob) {
    write("No such shape.\n");
    return 1;
  }
  if(THERE(ME)->query_shape() == ob) {
    write("You cannot forget a shape you currently hold.\n");
    return 1;
  }
  ME->add_spell_point(-10);
  write("You concentrate briefly, and all knowledge of that form is lost forever.\n");
  if(!(arr = remove_element(arr, ob)))
    write("Error forgetting shape.\n");
  else
    THERE(ME)->set_touched(arr);
  return 1;
}
see_touched(str) {
  object who, *arr, sh;
  int x, i;
  if(!str) {
    write("Usage: see_touched <who>\n");
    return 1;
  }
  if(!(who = find_player(str))) {
    write("Player not found.\n");
    return 1;
  }
  if(!THERE(who)) {
    write("Player is not of this guild.\n");
    return 1;
  }
  arr = THERE(ME)->query_touched();
  write(capitalize(str)+" has touched the following items:\n");
  for(i = 0; i < sizeof(arr); i++) {
    if(arr[i] != 0)
      write(" ["+file_name(arr[i])+"]: "+arr[i]->short()+".\n");
  }
  sh = THERE(ME)->query_shape();
  write("Current shape: "+(sh?sh->short():"none")+".\n");
  return 1;
}
lmstat(str) {
  object who;
  int x;
  string hp, sp, xp, lv, kl, de, tt, kd, cm, mn, rn;
  string ta, sh;
  if(!str) {
    write("Usage: lmstat <who>\n");
    return 1;
  }
  if(!(who = find_player(str)) || !THERE(who)) {
    write("Player not found/not a member.\n");
    return 1;
  }
  hp = extract("< Hit points: "+who->query_hp()+" of "+who->query_mhp()+BLANKS,0,78);
  sp = extract("< Spell pnts: "+who->query_sp()+" of "+who->query_msp()+BLANKS,0,78);
  lv = extract("< Level/Xlev: "+who->query_level()+", "+who->query_extra_level()+BLANKS,0,78);
  xp = extract("< Experience: "+who->query_exp()+BLANKS,0,78);
  kl = extract("< PK Kills:   "+THERE(who)->query_kills()+BLANKS,0,78);
  de = extract("< PK Death:   "+THERE(who)->query_died()+BLANKS,0,78);
  tt = extract("< Targeted:   "+THERE(who)->query_targeted()+BLANKS,0,78);
  x  = (THERE(who)->query_kills()*100)/THERE(who)->query_died();
  kd = extract("< Kill/Death: "+x+"%"+BLANKS,0,78);
  x  = (THERE(who)->query_kills()*100)/THERE(who)->query_targeted();
  cm = extract("< Completion: "+x+"%"+BLANKS,0,78);
  x  = THERE(who)->query_pkmon();
  mn = (x==0?"Off":(x==1?"Combat mode":"Always on"));
  mn = extract("< PK Monitor: "+mn+BLANKS,0,78);
  rn = (THERE(who)->query_rank()?"Expert":"Novice");
  rn = extract("< Guild Rank: "+rn+BLANKS,0,78);
  ta = extract("< Targeting:  "+(THERE(who)->query_target())->query_name()+BLANKS,0,78);
  sh = extract("< Your Shape: "+(THERE(who)->query_shape())->query_name()+BLANKS,0,78);
  write(" _____________________________________________________________________________\n");
  write("< ___________________Liquid Metal (Terminator) Guild Status__________________ >\n");
  write("</__________________/                                      \_________________\>\n");
  write(hp+">\n"); write(sp+">\n"); write(lv+">\n"); write(xp+">\n");
  write(kl+">\n"); write(de+">\n"); write(tt+">\n"); write(kd+">\n");
  write(cm+">\n"); write(mn+">\n"); write(rn+">\n"); write(ta+">\n");
  write(sh+">\n");
  write("<>___________________________________________________________________________<>\n");
  return 1;
}
lmpatch(str) {
  mixed *m; /* we'll try to cheat reality */
  object gob;
  string who, func, arg;
  int iarg;
  m = allocate(1);
  if(!str) {
    write("Usage: lmpatch <who> <func> [arg]\n");
    return 1;
  }
  if(sscanf(str, "%s %s %s", who, func, arg) == 3) ;
  else if(sscanf(str, "%s %s %s", who, func, arg) < 2) {
    write("Incorrect usage.\n");
    return 1;
  }
  if(!find_player(who)) {
    write("Player "+who+" not found.\n");
    return 1;
  }
  if(!(gob = THERE(who))) {
    write("Player not a member.\n");
    return 1;
  }
  write("Who: "+who+"\nFunc: "+func+"\nArg: "+arg+"\n");
  if(arg && sscanf(arg, "%d", iarg))
    m[0] = call_other(gob, func, iarg);
  else
    m[0] = call_other(gob, func, arg);
  write("Returns: "+m[0]+"\n");
  return 1;
}



