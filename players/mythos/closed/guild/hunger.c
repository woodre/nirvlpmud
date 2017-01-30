#include "/players/mythos/closed/guild/def.h"

int talent, glevel, fae, sacrifice, dblade, dring, md;
int sim_on, ward_on, c_area_on, shatter_on, bow_on, pact1, pact2, devil;
int imag_on, ban_on, send_on, pow_on, rev_on;
int helper, sif, dis_on;
string dtitle, ctitle;
static int tides, dates, qw, ascr, defence, jjp;
static int ggt, switchs, vs, light_see;
object ob, ob2, own;
static own_;

query_auto_load() { return "/players/mythos/closed/guild/hunger.c:"; }
query_prevent_shadow() { return 1; } 
    
id(str) { return str == fear || str == "gob" || str == "dark_sight_object"; }

drop() {return 1;}
get() {return 1;} 

reset(arg) {
  if(arg || root()) return;
  md = 0;
  tides = light_see = 0;
  dates = jjp = 0;
  defence = ascr = 0;
  ggt = 0;
  sacrifice = 0;
  vs = 0;
  switchs = 1;
  call_out("hb",3);
  call_out("light_dam",3);
  call_out("death_check",3);
  call_out("banisher",10);
}

init_arg()
{
  if(restore_object(MEM+tpn))
  {
    write(HIB);
    cat("/players/mythos/closed/guild/guild_news");
    write(NORM);
    own = tp;
    if(tgl != glevel)
    {
      vs = tgl;
      own = tp;
      set_dark_level(glevel);
    }
    own_ = tpn;
    /*Here the dreams and task dreams are given*/
    if(0 == random(2))
    {
      write("You wake from a good dream....  You feel refreshed.\n");
      if(0==random(100))
      {
        write("A truly good dream...  You feel whole....\n");
        if(fae < 20) {  fae = fae + 1;  }
        else { tp->heal_self(1000); }
      }
    } 
    else
    {
      write("You wake from a bad dream....  \n");
      if(0 == random(100))
      {
        write("The dream was so terrible....  You know you have lost vitality.\n");
        tp->lower_attrib();
      }
    }
  
    if(tgl == 1 && tl > 5)
    {
      write("\nYou feel as if something is calling you deep in the forest.\n\n");
    }
  
    if(tgl == 2 && tl > 6)
    {
      write("\nThe Library calls....  Find the scribe and 'ask' him what is needed.\n\n");
    }
    
    if(tgl == 3 && tl > 7 && fae > 4)
    {
      write("\nThe fae whisper as you wake,'Find the Jewel of Darm....'\n\n");
    }
  
    if(tgl == 4 && tl > 8 && fae > 4)
    {
      write("\nTouch Masakado's tomb.....\n\n");
    }
    
    if(tgl == 5 && tl > 9 && fae > 4)
    {
      write("\nSomething tells you to go into the Black Cavern.....\n\n");
    }
  
    if(tgl == 6 && tl > 14 && fae > 9)
    {  
      write("\nFind the DEMON Keeper....\n\n");
    }
    
    if(tgl == 7 && tl > 15 && fae > 9)
    {
      write("\nFind the HUNTER....\n\n");
    }
  
    if(tgl == 8 && tl > 16 && fae > 9)
    {  
      write("\nGo to the Chamber and go to the hills.\n\n");
    }
  
    if(tgl == 9 && tl > 18 && tx > 4 && fae > 17)
    {
      write("\nGo to the Frozen Cave and do what must be done...\n\n");
    }
    
    if(!present(pact,tp))
    {
      move_object(clone_object("/players/mythos/closed/guild/obb.c"),tp);
    }
  } 
}

init()
{
  if(tp == ep)
  {
    restore_object(MEM+tpn);
    tp->add_guild_exp(1);
    own = tp;
    own_ = tpn;
  
    /* added mag for fae <i wished to avoid adding things into player.c>
      * basically i wished to give a bit of extra sp to members  
      * this gives 4 extra sp per fae after mag 20 */
  
    if(tp->query_attrib("mag") < 31)
    {
      if(fae > 0 && tp->query_attrib("mag") > 19 && 
        tp->query_attrib("mag") != 20+fae/2)
      {
        tp->set_attrib("mag",20+fae/2);
      }
    }
    
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
/*
    add_action("dlead","lead");
*/
    add_action("dwho","dwho");
  
    add_action("dhelp","dhelp");
    add_action("dquit","quit");
    add_action("save_dark","dsave");
    add_action("dscore","ss");
    add_action("update_me","uu");
    add_action("sacrifice","sacrifice");
#ifndef __LDMUD__
    add_action("dark_talk"); add_xverb("dt");
#else
   add_action("dark_talk", "dt", 3);
#endif
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
        if(!pact1) { add_action("demon_pact","demon_pact");}
      }
    
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
        add_action("gate","gate");
        add_action("replicate","replicate");}
    
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
  
      if((tgl > GC && !(tp->query_guild_name())) || epn == "vertebraker" || 
        epn == "arrina")
      {
        if(!(present("dgc",tp)))
        {
          move_object(clone_object("/players/mythos/closed/guild/gob.c"),tp);
        }
      }
    
       /* Task dependant powers (toggles)*/
    
      if(sim_on) {add_action("simulacrum","simulacrum");}
      if(ward_on){ add_action("ward","ward");}
      if(c_area_on){add_action("cold_area","cold_area");}
      if(shatter_on){ add_action("shatter","shatter"); }
      if(bow_on) { add_action("dblood","wound");}
      if(dis_on) { add_action("imbue","imbue");}
      if(imag_on) { add_action("chaos","chaotic");}
      if(rev_on) {add_action("reverse","reverse");}
      if(ban_on){ add_action("true_banish","true_banish");}
      if(send_on){ add_action("creeping_doom","creeping_doom");}
      if(pow_on){ add_action("power_word","symbol");}
      if(devil) {add_action("devil_pact","devil_pact");}
      if(sif) {add_action("siphon","siphon");}
    }
  }
}

hb()
{
  int muff;

  if(!ep) return;
  if(ep)
  {
    if(md) muff = 1;
    else muff = 0;
    if(ep->query_intoxination() > 0)
    { 
      if(ep->query_intoxination() > 5)
      {
        tell_object(ep,"\n\n\t\t Using Intox somehow!?!?!\n\n\n");
        ep->death("Intoxication");
      }
    }
    ep->add_intoxination(-(ep->query_intoxination()));
  }
  if(!present("still",ep))
  {
    move_object(this_object(),ep);
    md = muff;
  }
  
  call_out("hb",3);
}

light_dam()
{
  int is_light;
  
  if(!ep) return;
  is_light = set_light(0);
  if(present("weather",ep)) { is_light =  0; }
  if(present("dark_cloak",ep)) { is_light = -1; }
  if(present("myst",ep)) { is_light --; }
  if(present("darkness",ep)) { is_light -= 2; }
  if(present("mailread",ep)) { is_light = 0; }
  if(ep->query_interactive() &&
    !ep->query_ghost() && ep->query_level() < 21)
  {
    ep->heal_self(-(is_light)); 
    if(is_light > 1)
    {
      tell_object(ep,
                   "You feel great pain as light burns into you!\n");
    }
    if(is_light < -2 && 
      ep->query_hp() < ep->query_mhp())
    {
      tell_object(ep,
        "You feel a cool touch as the darkness heals you.\n");
    }
  }
  call_out("light_dam", 3);
}

death_check()
{
}

dquit() {
  save_dark();
  if(tp->query_level() < 21)
  {
    if(!present("deathmark",tp) && !present("bold",tp))
    {
      tp->set_home("/players/mythos/closed/guild/assembly.c");
    }
    if(present("deathmark",tp) && !present("bold",tp))
    {
      tp->set_home("/players/mythos/closed/guild/death/death.c");
    }
    if(present("bold",tp))
    {
      tp->set_home("/players/mythos/closed/guild/task/horlach/home.c");
    }
  }
  return 0;
}

save_dark()
{
  save_object(MEM+ep->query_real_name());
  tell_object(ep,BOLD+"Guild stats saved....\n"+NORM);
  return 1;
}

update_me()
{
  restore_object(MEM+ep->query_real_name());
  if(vs != glevel)
  {
    set_dark_level(glevel);
  }
  tell_object(ep,HIR+"Guild Object Updated....\n"+NORM);
  if(present("dgc",ep))
  {
    destruct(present("dgc",ep));
  }
  move_object(clone_object("/players/mythos/closed/guild/hunger.c"),ep);
  destruct(this_object());
  return 1;
}

set_dark_level(d)
{
  if(ep)
  {
    if(d > 13) d = 13;
    if(d < 0) d = 0;
    if(ep->query_real_name() == "vertebraker")
      d = 13;
    glevel = d;
    vs = ep->query_guild_rank();
    ep->add_guild_rank(d-vs);
    fix_title();
    save_dark();
  }
  return 1;
}

set_dark_title(str)
{
  sccanf(str,"%s %s",ctitle,dtitle);
  ep->set_title(ctitle+dtitle+NORM);
  return 1;
}

fix_title()
{
  int d;
  d = ep->query_guild_rank();
  if((d > -1 && d <12) || ep->query_real_name() == "vertebraker") {
    if(d >= 0 && d < 4) { ctitle = ""; dtitle = "the initiate"; }
    if( d > 3 && d < 7) { ctitle = CYN; dtitle = "the apprentice"; }
    if( d > 6 && d < 10) { ctitle = BOLD; dtitle = "the Learned"; }
    if( d == 10) { ctitle = RED; dtitle = "the Dark One"; }
    if(ep->query_real_name() == "vertebraker") { ctitle = ""; dtitle = "the Prophet"; }
    ep->set_title(ctitle+dtitle+NORM);
  }
  save_dark();
  ep->save_me();
  write("Ok.\n");
  return 1;
}

query_dark_title() { return ctitle+dtitle+NORM;}

muffle_dark()
{
  md = !md;
  
  write(BOLD+"Guild Channel "+(md?"Muffled.":"ON")+"\n"+NORM);
  return 1;
}

query_md() { return md; }

set_sacrifice(scr)
{
  restore_object(MEM+ep->query_real_name());
  sacrifice = scr;
  if(sacrifice < 0)
  {
    sacrifice = 0;
  }
  save_object(MEM+ep->query_real_name());
}

add_sacrifice(ascr)
{ 
  set_sacrifice(sacrifice + ascr);
}

query_sacrifice() { return sacrifice; }

leaver()
{
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
  tp->set_attrib("luc",1);
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
  log_file("GUILD", ctime(time()) + " " +tpn+" leaves Mythos's Guild\n");
  destruct(this_object());
  return 1;
}

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
set_dring(dr) {dr = dring;}
set_rev(re) { rev_on = re;}
set_help(he) { helper = he;}
query_help() { return helper;}
set_sif(sfs) { sif = sfs;}
set_ggt(n) { ggt = n; }
set_own(str) { own = find_player(str); }

set_switch(n) { 
 switchs = n; move_object(this_object(),ep); }
query_switch() { return switchs; }

set_defence(dfc) { defence = dfc;}
query_defence() { return defence;}

set_dates() { dates = 1;}
query_dates() { return dates;}

set_tides(td) { tides = td;}
query_tides() { return tides;}

set_talent(tn) {talent = tn;}
query_talent() { return talent;}

talker() { /* nothing */ }

set_fae(f)
{ 
  fae = f;
  if(fae < 0) { fae = 0;}
  write("Your fae is at "+fae+".\n");
  save_dark();
}

raise_fae(qw)
{ 
  fae = fae + qw;
  if(fae < 0) { fae = 0;}
  write("Your fae is at "+fae+".\n");
  save_dark();
}

query_fae() { return fae;}

dhelp(str) {
int n;
  if(!str) { cat("/players/mythos/closed/guild/help/help1"); return 1;}
  if(!cat("/players/mythos/closed/guild/help/"+str)) {
  write("Subject not found....\n"); }
return 1;}

static dmissle(str) {
string targ;
object ob;
    if (!str) {
	ob = tp->query_attack();
   if(!ob) { write("Who do you wish to attack?\n"); return 1; }
	targ = ob->query_name(); }
    else {
	ob = present(lower_case(str), environment(this_player()));
	targ = str; }
    if (!ob || !living(ob)) { write("At whom?\n"); return 1;}
	if(environment(ob) != environment(tp)) return 1; 
	if(tp->query_spell_dam()) return 1;
    tp->spell_object(ob,"ice missles",random(20),10,
        "< * > You send a volley of ice shards at "+capitalize(targ)+"!\n",
        "< * > Shards of ice fly into you causing damage!\n",
        "< * > "+capitalize(tpn)+" sends a volley of ice shards into "+ 
        capitalize(targ)+"!\n");
    tp->set_spell_dtype("other|ice");
    return 1;}
    
static dshock(str) {
string targ;
object ob;
    if (!str) {
	ob = tp->query_attack();
  if(!ob) { write("Who do you wish to attack?\n"); return 1; }
	targ = ob->query_name(); }
    else {
	ob = present(lower_case(str), environment(this_player()));
	targ = str; }
    if (!ob || !living(ob)) { write("At whom?\n"); return 1;}
	if(environment(ob) != environment(tp)) return 1; 
	if(tp->query_spell_dam()) return 1;
    tp->spell_object(ob,"shade spear",random(30),15,
        "You create a "+GRN+"SHADE SPEAR"+NORM+" and throw it at "+
        capitalize(targ)+"!\n",
        "A "+GRN+"SHADE SPEAR"+NORM+" pierces your side!\n",
        capitalize(tpn)+" creates a "+GRN+"SHADE SPEAR"+NORM+" and throws it at "+
        capitalize(targ)+"!\n");
      tp->set_spell_dtype("other|dark");
    return 1;}

static dfireball(str) {
string targ;
object ob;
    if (!str) {
	ob = tp->query_attack();
  if(!ob) { write("Who do you wish to attack?\n"); return 1; }
	targ = ob->query_name(); }
    else {
	ob = present(lower_case(str), environment(this_player()));
	targ = str; }
	talker(RED+"fireball "+str+NORM);
    if (!ob || !living(ob)) { write("At whom?\n"); return 1;}
	if(environment(ob) != environment(tp)) return 1; 
	if(tp->query_spell_dam()) return 1;
    tp->spell_object(ob,"fire ball",random(40),20,
        "You summon "+BLU+"COLD FIRE"+NORM+" and throw it at "+capitalize(targ)+"!\n",
        "You are hit by "+BLU+"COLD FIRE!\nPAIN"+NORM+" is what you feel!\n",
        capitalize(tpn)+" summons up "+BLU+"COLD FIRE"+NORM+" and throws it at "+
        capitalize(targ)+".\n");
    tp->set_spell_dtype("other|dark");
    return 1;} 

static dsonic(str) {
string targ;
object ob;
    if (!str) {
	ob = tp->query_attack();
   if(!ob) { write("Who do you wish to attack?\n"); return 1; }
	targ = ob->query_name(); }
    else {
	ob = present(lower_case(str), environment(this_player()));
	targ = str; }
	talker(RED+"sonic "+str+NORM);
    if (!ob || !living(ob)) { write("At whom?\n"); return 1;}
	if(environment(ob) != environment(tp)) return 1; 
	if(tp->query_spell_dam()) return 1;
    tp->spell_object(ob,"fae blast",20+random(25),25,
        "You summon up a mass of "+HIB+"DARK FAE"+NORM+" and fire it at "+
        capitalize(targ)+"!\n",
        "A mass of "+HIB+"DARK FAE"+NORM+" blasts into you!\n",
        capitalize(tpn)+" summons a mass of "+
        HIB+"DARK FAE"+NORM+" and fires it at "+capitalize(targ)+".\n");
   tp->set_spell_dtype("other|dark");
    return 1;}

/* function that checks if player is in a normal lib room - like 
    church etc.  If so then the spell doesnt go off */
    
int roomcheck() {
  if(environment(tp)) {
    if(!creator(environment(tp))) { 
      tell_object(tp,"You are in non-spell area [church,post,village\n"+
                     "green, etc] The spell does not work.\n");
      return 0; }
  return 1;}
return 1; }

/***  Powers called to power.c ***/

dgossip(str) { talker("GOS :"+str); POWER->dgossip(str); return 1;}
drisque(str) { talker("RIS :"+str); POWER->drisque(str); return 1;}
sacrifice(str) { POWER->sacrifice(str); return 1;}
dfeed() { talker(RED+"dfeed"+NORM); POWER->dfeed(); return 1;}
dfollow(str) { talker(BLU+"dfollow "+str+NORM); POWER->dfollow(str); return 1;}
dlead(str) { talker(BLU+"dlead "+str +NORM); POWER->dlead(str); return 1;}
dwho() { POWER->dwho(); return 1;}
dscore() { POWER->dscore(); return 1;}
dark_tell(str) { talker(BLU+"dark_tell "+str +NORM); POWER->dark_tell(str); return 1;}
chill_shield() { talker(MAG+"chillshield" +NORM); POWER->chill_shield(); return 1;}
nightmare_min() { if(roomcheck()) { talker(BOLD+"darkdream" +NORM); POWER->nightmare_min();} return 1;}
dismiss() { talker(MAG+"dismiss" +NORM); POWER->dismiss(); return 1;}
mesmerize(str) { talker(MAG+"mes" +NORM); POWER->mesmerize(str); return 1;}
dblood(str) { talker(RED+"wound "+str +NORM); POWER->dblood(str); return 1;}
myst() { talker(BLU+"myst" +NORM); POWER->myst(); return 1;}
identify(str) { talker(BLU+"identify "+str +NORM); POWER->identify(str); return 1;}
terror(str) { if(roomcheck()) { talker(MAG+"terror "+str +NORM); POWER->terror(str);} return 1;}
dark_talk(str) { talker(BLU+"dt "+str +NORM); POWER->dark_talk(str); return 1;}
cold_shield() { talker(MAG+"coldshield" +NORM); POWER->cold_shield(); return 1;}
darkness() { talker(BLU+"darkness" +NORM); POWER->darkness(); return 1;}
knowing(str) { talker(BLU+"knowing "+str +NORM); POWER->knowing(str); return 1;}
nightmare_maj() { if(roomcheck()) { talker(BOLD+"nightmare"+NORM); POWER->nightmare_maj(); } return 1;}
distraction() { if(roomcheck()) { talker(BLU+"distract" +NORM); POWER->distraction();}  return 1;}
empower(str) { POWER->empower(str); return 1;}
true_darkness() {POWER->true_darkness(); return 1;}
demon_bind(str) { POWER->demon_bind(str); return 1;}
grand_circle() { if(roomcheck()){ talker(BOLD+"grandcircle" +NORM); POWER->grand_circle();} return 1;}
gate() { if(roomcheck()) { talker(BOLD+"gate" +NORM); POWER->gate(); } return 1;}
chaos() { if(roomcheck()) { talker(MAG+"chaos" +NORM); POWER->chaos(); } return 1;}
drain(str) { if(roomcheck()) { talker(RED+"drain "+str +NORM); POWER->drain(str);} return 1;}
imbue(str) { talker(BLU+"imbue "+str +NORM); POWER->imbue(str); return 1;}
shape_change(str) { talker(BLU+"shapechange "+str +NORM); POWER->shape_change(str); return 1;}
weather(str) { if(roomcheck()) { talker(MAG+"weather "+str +NORM); POWER->weather(str); } return 1;}
spirit_meld() { if(roomcheck()) { talker(BOLD+"spiritmeld" +NORM); POWER->spirit_meld(); } return 1;}
simulacrum(str) { if(roomcheck()) { talker(BLU+"sim "+str +NORM); POWER->simulacrum(str); } return 1;}
ward(str) { if(roomcheck()) { talker(BOLD+"ward "+str +NORM); POWER->ward(str); } return 1;}
cold_area(str) { if(roomcheck()) { talker(MAG+"cold_area "+str +NORM); POWER->cold_area(str); } return 1;}
shatter(str) { if(roomcheck()) { talker(BLU+"shatter "+str +NORM); POWER->shatter(str);  }return 1;}
dwhip(str) { talker(RED+"whip "+str +NORM); POWER->dwhip(str); return 1;}
imagery(str) { talker(BLU+"image "+str +NORM); POWER->imagery(str); return 1;}
true_banish(str) { talker(BOLD+"banish "+str +NORM); POWER->true_banish(str); return 1;}
power_word(str) { if(roomcheck()) { talker(MAG+"symbol "+str +NORM); POWER->power_word(str); } return 1;}
reverse() { if(roomcheck()) { talker(MAG+"reverse" +NORM); POWER->reverse(); } return 1;}
devil_pact() { if(roomcheck()) POWER->devil_pact(); return 1;}
demon_pact() { if(roomcheck()) POWER->demon_pact(); return 1;}
demon_spell() { if(roomcheck()) POWER->demon_spell(); return 1;} 
siphon(str) { POWER->siphon(str); return 1;}
night() { if(roomcheck()) { talker(BOLD+"night" +NORM); POWER->night();} return 1;}
cause_miss() { if(roomcheck()) { talker(MAG+"freeze" +NORM); POWER->cause_miss();} return 1;}
tidal_flare() { POWER->tidal_flare(); return 1;}
flare(str) { talker(RED+"flare "+str +NORM); POWER->flare(str); return 1;}
creeping_doom() { if(roomcheck()) { talker(RED+"creepingdoom"+NORM); POWER->creeping_doom(); } return 1;}
duplicate(str) { talker(BLU+"duplicate "+str +NORM); POWER->duplicate(str); return 1;}
replicate(str) { if(roomcheck()) { talker(BLU+"replicate "+str +NORM); POWER->replicate(str);} return 1;}
withering_hand(str) { if(roomcheck()) { talker(RED+"wither "+str +NORM); POWER->withering_hand(str);} return 1;}
ownership(str) { POWER->ownership(str); return 1;}
remove_ownership(str) { POWER->remove_ownership(str); return 1;}
flash_fire(str) { if(roomcheck()) { talker(RED+"flash "+str +NORM); POWER->flash_fire(str); } return 1;}