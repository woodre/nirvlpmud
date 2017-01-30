#include "/players/mythos/closed/guild/def.h"
int talent, glevel, fae, sacrifice, dblade, dring, md;
int sim_on, ward_on, c_area_on, shatter_on, bow_on, pact1, pact2, devil;
int imag_on, ban_on, send_on, pow_on, rev_on;
int helper, sif, dis_on;
string dtitle, ctitle;
static int tides, dates, qw, ascr, defence, jjp;
static int ggt, switchs, vs, light_see;
object ob, ob2, own;

query_auto_load() { return "/players/mythos/closed/guild/hunger.c:"; }
    
id(str) { return str == fear; }

drop() {return 1;}
get() {return 0;}

reset(arg) {
  if(arg) return;
  md = 0;
  tides = light_see = 0;
  dates = jjp = 0;
  defence = ascr = 0;
  ggt = 0;
  sacrifice = 0;
  vs = 0;
  switchs = 1;
  call_out("hb",10);
}

init_arg() {
  if(restore_object(MEM+tpn)) {
  write(BLU);
  cat("/players/mythos/closed/guild/guild_news");
  write(NORM);
  own = tp;
  if(tgl != glevel) { vs = tgl; own = tp; set_dark_level(glevel); }

  /*Here the dreams and task dreams are given*/
  if(0 == random(2)) {
    write("You wake from a good dream....  You feel refreshed.\n");
    if(0==random(100)) { write("A truly good dream...  You feel whole....\n");
      if(fae < 20) { fae = fae +1; save_dark();  }
      else { tp->heal_self(1000); } }
    } 
    else { write("You wake from a bad dream....  \n");
     if(0 == random(100)) {
      write("The dream was so terrible....  You know you have lost vitality.\n");
     tp->lower_attrib(); }
    }
  
  if(tgl == 1 && tl > 5) {
    write("\nYou feel as if something is calling you deep in the forest.\n\n"); }
  
  if(tgl == 2 && tl > 6) {
   write("\nThe Library calls....  Find the scribe and 'ask' him what is needed.\n\n"); }
    
  if(tgl == 3 && tl > 7 && fae > 4) {
    write("\nThe fae whisper as you wake,'Find the Jewel of Darm....'\n\n"); }
  
  if(tgl == 4 && tl > 8 && fae > 4){
    write("\nTouch Masakado's tomb.....\n\n"); }
    
  if(tgl == 5 && tl > 9 && fae > 4) {
    write("\nSomething tells you to go into the Black Cavern.....\n\n"); }
  
  if(tgl == 6 && tl > 14 && fae > 9) {  
     write("\nFind the DEMON Keeper....\n\n"); }
    
  if(tgl == 7 && tl > 15 && fae > 9) {
    write("\nFind the HUNTER....\n\n"); }
  
  if(tgl == 8 && tl > 16 && fae > 9) {  
    write("\nGo to the Chamber and go to the hills.\n\n"); }
  
  if(tgl == 9 && tl > 17 && fae > 14) {
    write("\nGo to the Frozen Cave and do what must be done...\n\n"); }
    
      /* object is monitor thingy */
  
  if(!present(pact,tp)) {
  move_object(clone_object("/players/mythos/closed/guild/ob.c"),tp);}
  } /*
  else {
  write("You feel a sudden burst of energy and something whispers:\n"+
        "Welcome to the DARK....\n");
  sim_on = 0; ward_on = 0; c_area_on = 0; shatter_on = 0; bow_on = 0;
  imag_on = 0; ban_on = 0; send_on = 0; pow_on = 0; 
  glevel = 1; fae = 1; pact1 = 0; pact2 = 0;
  devil = 0; dblade = 0; dring = 0; md = 0; rev_on = 0; helper = 0; sacrifice = 0;
  ctitle = ""; dtitle = "the initiate"; sif = 0; dis_on = 0; dring = 0;
  save_dark();} */
}

init() {
if(tp == ep) {
restore_object(MEM+tpn);
  tp->add_guild_exp(1);
  
  if(!light_see) {   
  /* Shadow for seeing */
  
  ob2=clone_object("/players/mythos/closed/guild/tlight.c");
  ob2->start_see_shadow(this_player());
  light_see = 1;
  }
  
  /* added mag for fae <i wished to avoid adding things into player.c>
   * basically i wished to give a bit of extra sp to members  
   * this gives 4 extra sp per fae after mag 20 */
  
  if(tp->query_attrib("mag") < 31) {
  if(fae > 0 && tp->query_attrib("mag") > 19 && 
     tp->query_attrib("mag") != 20+fae/2) {
    tp->set_attrib("mag",20+fae/2);
  } }
  
  /*  actions   */
  
    /* Banned actions*/
  
  add_action("ddrink","drink");
  add_action("ddrink","sip");
  if(tpn == "myrkrn") {
    add_action("ckill","kill");
  }
  
  
    /*replacing mi,sh,fi,so spells*/
    
  if(tl > 4) { add_action("dmissle","missile",2);}
  if(tl > 9) { add_action("dshock","shock",2);}
  if(tl > 14) { add_action("dfireball","fireball",2);}
  if(tx > 4) { add_action("dsonic","sonic",2); }
  
    /*Guild level dependant powers*/
  
      /* 1 */

  add_action("dgossip","gossip");
  add_action("drisque","risque");
  add_action("dfeed","feed");
  add_action("dfollow","dfollow");
  add_action("dlead","lead");
  add_action("dwho","dwho");
  add_action("dark_tell"); add_xverb("=>");
  add_action("dhelp","dhelp");
  add_action("dquit","quit");
  add_action("save_dark","dsave");
  add_action("dscore","ss");
  add_action("update_me","uu");
  add_action("sacrifice","sacrifice");
  add_action("dark_talk"); add_xverb("dt");
  add_action("muffle_dark","mdark");
  add_action("leaver","leave_guild");
  add_action("fix_title","fix_title");
  
      /* 2 */
  if(switchs) {
  if(tgl > 1 ) {
    add_action("chill_shield","cshield");
    add_action("nightmare_min","dark_dream");
    add_action("dismiss","dismiss");}
    
      /* 3 */
  
  if(tgl > 2 ) {
    add_action("mesmerize","mes");
    add_action("dwhip","whip");
    add_action("myst","myst");}
    
      /* 4 */
      
  if(tgl > 3 ) {
    add_action("identify","identify");
    add_action("terror","terror"); 
    add_action("ownership","ownership");
    add_action("remove_ownership","remove_ownership");
    if(!pact1) { add_action("demon_pact","demon_pact");}}
    
      /* 5 */
  
  if(tgl > 4 ) {
    add_action("cold_shield","csh");
    add_action("darkness","darkness");
    add_action("duplicate","duplicate");
    add_action("knowing","knowing");
    add_action("imagery","image");}
    
      /* 6 */
  
  if(tgl > 5 ) {
    add_action("flare","flare");
    add_action("nightmare_maj","nightmare");
    add_action("distraction","distraction");
    if(!helper) {
    add_action("night","night");} }
    
      /* 7 */
      
  if(tgl > 6 ) {
    add_action("cause_miss","freeze");
    add_action("weather","weather");
    if(!dblade) { add_action("empower","empower");}
    if(!dring) { add_action("demon_bind","demon_bind");}
    if(!pact2) { add_action("demon_spell","demon_spell");}
    }
    
      /* 8 */
      
  if(tgl > 7 ) {
    add_action("true_darkness","true_darkness");
    add_action("grand_circle","grand_circle");
    add_action("gate","gate");}
    
    /* 9 */
    
  if(tgl > 8 ) {
    add_action("spirit_meld","spirit_meld");
    add_action("drain","drain");
    add_action("withering_hand","wither");
    if(!present("friend_ob",tp)) {
    move_object(clone_object("/players/mythos/closed/guild/forest_ob.c"),tp);
    }}
    
    /* 10 */
    
  if(tgl > 9 ) {
    add_action("flash_fire","flash");
    add_action("shape_change","change");}
  
    /* talent powers */
    
  if(talent) {
    if(tgl > 2) { add_action("tidal_flare","tidal_flare"); }
  }
  
      /*GC powers - object is the guild commander object*/
  
  if((tgl > GC && !(tp->query_guild_name())) || epn == "mythos" || 
      epn == "arrina") {
    if(!(present("dgc",tp))) {
    move_object(clone_object("/players/mythos/closed/guild/gob.c"),tp);}
    }
    
    /*Task dependant powers (toggles)*/
    
  if(sim_on) {add_action("simulacrum","simulacrum");}
  if(ward_on){ add_action("ward","ward");}
  if(c_area_on){add_action("cold_area","cold_area");}
  if(shatter_on){ add_action("shatter","shatter"); }
  if(bow_on) { add_action("dblood","wound");}
  if(dis_on) { add_action("imbue","imbue");}
  if(imag_on) { add_action("chaos","chaos");}
  if(rev_on) {add_action("reverse","reverse");}
  if(ban_on){ add_action("true_banish","true_banish");}
  if(send_on){ add_action("creeping_doom","creeping_doom");}
  if(pow_on){ add_action("power_word","symbol");}
  if(devil) {add_action("devil_pact","devil_pact");}
  if(sif) {add_action("siphon","siphon");}
  }
}
}

hb() {
int muff;
int is_light;
  vs = egl;
  own = ep;
  muff = md;
  if(!present("still",own)) {
  if(jjp > 2 && own->query_level() < 20) {
  move_object(this_object(),"/room/void.c");
  md = muff;
  jjp = 0; }
  else { jjp = jjp + 1; }
  move_object(this_object(),own); 
  md = muff;}
  if(present("symbol",ep)) { destruct(present("symbol",ep));}
  if(present("processor",ep)) { destruct(present("processor",ep));}
  if(ep->query_intoxination() > 0) { 
    ep->add_intoxination(-(ep->query_intoxination()));
  }
  if(own->query_ghost() && !ggt) {
    move_object(clone_object("/players/mythos/closed/guild/death/ddeath.c"),ep);
    ggt = 1;
  }
  if(present("disease",ep)) { destruct(present("disease",ep)); }
  if(present("infection",ep)) { destruct(present("infection",ep)); }
  if(present("poison",ep)) { destruct(present("poison",ep)); }
  if(present("bubble",ep)) { destruct(present("bubble",ep)); }
  if(present("torch",ep)) { destruct(present("torch",ep)); }
  if(present("light",ep)) { destruct(present("light",ep)); }
  is_light = set_light(0);
  if(present("weather",environment(ep))) { is_light =  0; }
  if(present("dark_cloak",ep)) { is_light = -1; }
  if(present("myst",environment(ep))) { is_light = is_light - 1; }
  if(present("darkness",environment(ep))) { is_light = is_light - 2; }
  if(present("mailread",ep)) { is_light = 0; }
  if(ep->query_interactive() && !ep->query_ghost() && ep->query_level() < 20) {
      ep->heal_self(-(is_light)); 
  if(is_light > 1) { tell_object(ep,
                   "You feel great pain as light burns into you!\n");}
  if(is_light < -2) { tell_object(ep,
                   "You feel a cool touch as the darkness heals you.\n"); }
  }
  is_light=0;
  /*
  if(ep->query_attack() && !((ep->query_attack())->query_npc()) &&
   !present("wimpy_check",ep)) {
    object wimp, run;
    wimp = clone_object("/players/mythos/closed/guild/wimpy.c");
    wimp->set_attacker((ep->query_attack())->query_real_name());
    move_object(wimp,ep); 
    run = clone_object("/players/mythos/closed/guild/run.c");
    run->set_attacker(epn);
    move_object(run,ep->query_attack());
  }
  */
  if(talent) {  
    tides = call_other("/players/mythos/closed/guild/forest/misc/xb.c",
                       "query_day",0);
  } 
call_out("hb",5);
return 1;} 

dquit() {
   save_dark();
   if(present("dgc",tp)) { destruct(present("dgc",tp)); }
   if(tl > 20) {
   tp->do_quit(); }
   else { 
   if(!present("deathmark",tp)) {
   tp->set_home("/players/mythos/closed/guild/assembly.c"); }
   tp->save_me();
   tp->quit(); }
return 1;}

save_dark() {
  save_object(MEM+own->query_real_name());
  tell_object(own,BOLD+"Guild stats saved....\n"+NORM);
  if(own->query_level() < 20) {
  own->set_home("/players/mythos/closed/guild/assembly.c");
  }
return 1;}
  
update_me() {
  restore_object(MEM+own->query_real_name());
  if(vs != glevel) { set_dark_level(glevel); }
  tell_object(own,HIR+"Guild Object Updated....\n"+NORM);
  if(present("dgc",own)) { destruct(present("dgc",own)); }
  destruct(ob);
  move_object(this_object(),"/room/void.c");
  move_object(this_object(),own);
return 1;}

set_dark_level(d) {
if(d > 13) d = 13;
if(d < 0) d = 0;
if(own->query_real_name() == "mythos") d = 13;
  glevel = d;
  vs = own->query_guild_rank();
  own->add_guild_rank(d-vs);
  if((d > -1 && d <12) || own->query_real_name() == "mythos") {
  if(d >= 0 && d < 4) { ctitle = ""; dtitle = "the initiate"; }
  if( d > 3 && d < 7) { ctitle = CYN; dtitle = "the apprentice"; }
  if( d > 6 && d < 10) { ctitle = BOLD; dtitle = "the Learned"; }
  if( d == 10) { ctitle = RED; dtitle = "the Dark One"; }
  if(own->query_real_name() == "mythos") { ctitle = ""; dtitle = "the Prophet"; }
  own->set_title(ctitle+dtitle+NORM); }
  save_dark();
return 1;}

set_dark_title(str) {
  sccanf(str,"%s %s",ctitle,dtitle);
  ep->set_title(ctitle+dtitle+NORM);
return 1;}

fix_title() {
int d;
d = own->query_guild_rank();
if((d > -1 && d <12) || own->query_real_name() == "mythos") {
  if(d >= 0 && d < 4) { ctitle = ""; dtitle = "the initiate"; }
  if( d > 3 && d < 7) { ctitle = CYN; dtitle = "the apprentice"; }
  if( d > 6 && d < 10) { ctitle = BOLD; dtitle = "the Learned"; }
  if( d == 10) { ctitle = RED; dtitle = "the Dark One"; }
  if(own->query_real_name() == "mythos") { ctitle = ""; dtitle = "the Prophet"; }
  own->set_title(ctitle+dtitle+NORM); }
  save_dark();
  own->save_me();
write("Title fixed.\n");
return 1;}

query_dark_title() { return ctitle+dtitle+NORM;}

muffle_dark() {
 if(md == 0) { md = 1; }
 else { md = 0; }
 if(md == 1) { write(BOLD+"Guild Channel Muffled.\n"+NORM); 
 } else { write(BOLD+"Guild Channel ON\n"+NORM); }
return 1;}
query_md() { return md;}

set_sacrifice(scr) { 
  restore_object(MEM+own->query_real_name());
  sacrifice = scr;
  if(sacrifice < 0) { sacrifice = 0;}
  save_object(MEM+own->query_real_name());
  }
add_sacrifice(ascr) { 
  set_sacrifice(sacrifice + ascr);
  }
query_sacrifice() { return sacrifice;}

leaver() {
int numm, numr;
  tp->set_guild_name(0);
  tp->set_guild_rank(0);
  tp->set_guild_exp(0);
  tp->set_guild_file(0);
  numm=((int)tp->query_guild_exp());
  numr=((int)tp->query_guild_rank());
  tp->add_guild_exp(-numm);
  tp->add_guild_rank(-numr);
  command("dte leaves the Darkness.....",tp);
  if(present("dgc",tp)) { destruct(present("dgc",tp)); }
  if(present(pact,tp)) { destruct(present(pact,tp)); }
  write("Darkness overwhelms you!\n");
  move_object(clone_object("/players/mythos/amisc/forest/dark.c"),tp);
  tp->set_attrib("str",2);
  tp->set_attrib("sta",2); 
  tp->set_attrib("mag",1); 
  tp->set_attrib("pie",2); 
  tp->set_attrib("wil",1);
  tp->set_attrib("ste",2);
  tp->set_attrib("int",1); 
  tp->add_exp(-((tp->query_exp())*5/6));
  tp->set_home("/room/church.c");
  tp->reset(1);
  tp->save_me();
  write_file("/players/mythos/closed/guild/leave/"+tpn,ctime(time()));
  rm("/"+MEM+tpn+".o");
  if(present("black_orb",tp)) { command("drop black_orb",tp); }
  tp->move_player("in shame#room/church.c");
  destruct(this_object());
return 1;}

set_sim(si) { sim_on = si;}
set_ward(wo) {ward_on = wo;}
set_c_area(ca) {c_area_on = ca;}
set_shatter(sh) {shatter_on = sh;}
set_bow(bo) {bow_on = bo;}
set_image(im) {imag_on = im;}
set_ban(ba) {ban_on = ba;}
set_send(se) {send_on = se;}
set_pow(po) {pow_on = po;}
set_pact1(p1) {pact1 = p1;}
set_pact2(p2) {pact2 = p2;}
set_devil(dp) {devil = dp;}
set_dblade(db) {dblade = db;}
set_dring(dr) {dring = dring;}
set_rev(re) { rev_on = re;}
set_help(he) { helper = he;}
query_help() { return helper;}
set_sif(sfs) { sif = sfs;}
set_ggt(n) { ggt = n; }
set_own(str) { own = find_player(str); }

set_switch(n) { switchs = n; move_object(this_object(),own); }
query_switch() { return switchs; }

set_defence(dfc) { defence = dfc;}
query_defence() { return defence;}

set_dates() { dates = 1;}
query_dates() { return dates;}

set_tides(td) { tides = td;}
query_tides() { return tides;}

set_talent(tn) {talent = tn;}
query_talent() { return talent;}

set_fae(f) { fae = f;
  if(fae < 0) { fae = 0;}
  write("Your fae is at "+fae+".\n");
  save_dark();}
raise_fae(qw) { fae = fae + qw;
  if(fae < 0) { fae = 0;}
  write("Your fae is at "+fae+".\n");
  save_dark();}
query_fae() { return fae;}

dhelp(str) {
int n;
  if(!str) { cat("/players/mythos/closed/guild/help/help1"); return 1;}
  if(!cat("/players/mythos/closed/guild/help/"+str)) {
  write("Subject not found....\n"); }
return 1;}

ddrink(str) {
if(str != "pepsi" && str != "ade") {
  write("You can not do that.\n");
return 1;}
}

/***  Powers called to power.c ***/

dmissle(str) { POWER2->dmissle(str); return 1;}
dshock(str) { POWER2->dshock(str); return 1;}
dfireball(str) { POWER2->dfireball(str); return 1;}
dsonic(str) { POWER2->dsonic(str); return 1;}
dgossip(str) { POWER2->dgossip(str); return 1;}
drisque(str) { POWER2->drisque(str); return 1;}
sacrifice(str) { POWER2->sacrifice(str); return 1;}
dfeed() { POWER2->dfeed(); return 1;}
dfollow(str) { POWER2->dfollow(str); return 1;}
dlead(str) { POWER2->dlead(str); return 1;}
dwho() { POWER2->dwho(); return 1;}
dscore() { POWER2->dscore(); return 1;}
dark_tell(str) { POWER2->dark_tell(str); return 1;}
chill_shield() { POWER2->chill_shield(); return 1;}
nightmare_min() { POWER2->nightmare_min(); return 1;}
dismiss() { POWER2->dismiss(); return 1;}
mesmerize(str) { 
  if(tpn == "myrkrn") { tp->add_spell_point(-5-random(3)); }
POWER2->mesmerize(str); return 1;}
dblood(str) { POWER2->dblood(str); return 1;}
myst() { POWER2->myst(); return 1;}
identify(str) { POWER2->identify(str); return 1;}
terror(str) { POWER2->terror(str); return 1;}
dark_talk(str) { POWER2->dark_talk(str); return 1;}
cold_shield() { POWER2->cold_shield(); return 1;}
darkness() { POWER2->darkness(); return 1;}
knowing(str) { POWER2->knowing(str); return 1;}
nightmare_maj() { POWER2->nightmare_maj(); return 1;}
distraction() { POWER2->distraction(); return 1;}
empower(str) { POWER2->empower(str); return 1;}
true_darkness() {POWER2->true_darkness(); return 1;}
demon_bind(str) { POWER2->demon_bind(str); return 1;}
grand_circle() { POWER2->grand_circle(); return 1;}
gate() { POWER2->gate(); return 1;}
chaos() { POWER2->chaos(); return 1;}
drain(str) { POWER2->drain(str); return 1;}
imbue(str) { POWER2->imbue(str); return 1;}
shape_change(str) { POWER2->shape_change(str); return 1;}
weather(str) { POWER2->weather(str); return 1;}
spirit_meld() { POWER2->spirit_meld(); return 1;}
simulacrum(str) { POWER2->simulacrum(str); return 1;}
ward(str) { POWER2->ward(str); return 1;}
cold_area(str) { POWER2->cold_area(str); return 1;}
shatter(str) { POWER2->shatter(str); return 1;}
dwhip(str) { POWER2->dwhip(str); return 1;}
imagery(str) { POWER2->imagery(str); return 1;}
true_banish(str) { POWER2->true_banish(str); return 1;}
power_word(str) { POWER2->power_word(str); return 1;}
reverse() { POWER2->reverse(); return 1;}
devil_pact() { POWER2->devil_pact(); return 1;}
demon_pact() { POWER2->demon_pact(); return 1;}
demon_spell() { POWER2->demon_spell(); return 1;} 
siphon(str) { POWER2->siphon(str); return 1;}
night() { POWER2->night(); return 1;}
cause_miss() { POWER2->cause_miss(); return 1;}
tidal_flare() { POWER2->tidal_flare(); return 1;}
flare(str) { POWER2->flare(str); return 1;}
creeping_doom() { POWER2->creeping_doom(); return 1;}
ckill(str) { POWER2->ckill(str); return 1;}
duplicate(str) { POWER2->duplicate(str); return 1;}
replicate(str) { POWER2->replicate(str); return 1;}
withering_hand(str) { POWER2->withering_hand(str); return 1;}
ownership(str) { POWER2->ownership(str); return 1;}
remove_ownership(str) { POWER2->remove_ownership(str); return 1;}
flash_fire(str) { POWER2->flash_fire(str); return 1;}
