#include "/players/mythos/bounty/def.h"
#include "/players/mythos/closed/guild/name.h"
string form;
int level, glevel;
string gblevel, addb;
int add;

id(str) { return str == "cloak" || str == "bounty_hunter" ||
                 str == "bgo"; }

drop() { return 1; }
get() { return 0; }
query_weight() { return 0; }
query_prevent_shadow() { return 1; } 

query_auto_load() { return "/players/mythos/bounty/cloak.c:"; }

short() { if(form == "tech") return RED+"Cloak- Type #666"+NORM; 
          else return RED+"Hunter's Cloak"+NORM; }
          
long() { 
  if(form == "tech") write("\n");
  else write("\n");
  write("'recall' calls up the help files.\n");
}

reset(arg) { 
  if(arg) return;
  form = "medival";
  addb = gblevel = "null";
  glevel = 0;
  level = 1; 
  add = allocate(10);
  call_out("check_guild",5);
  call_out("autosave",100);
}

init_arg() {
  if(RO) {
    write(RED);
    cat("/players/mythos/bounty/news");
    write(NORM);
  } else {
    destruct(this_object());
  }
return 1; }

init() {
  if(tp == ep) {
    
    /* Set if player has no guild at all */
    
    if(tl < 20 && !tp->query_guild_name() && !tgl && 
       !tp->query_guild_exp() && !tp->query_guild_file()) {
         RO;
         tp->add_guild_exp(666);
         tp->set_guild_name("Hunter");
         tp->add_guild_rank(666);
         tp->save_me();
         SO;
     }
    
    if(!RO) { if(tpn == "mythos") { level = 20; SO; }
              else { destruct(this_object()); return 1;} }
    
    /* check on guild levels etc */
    
    if(!glevel && tl < 20) {
     if(tp->query_guild_name()) {
       switch(lower_case(tp->query_guild_name())) {
         case "ranger": break;
         case "vampire": glevel = tp->query_level(); 
                         break; 
         case "mage": if(!present("mage_obj",tp)) { destruct(this_object()); return 1;} 
                      gblevel = present("mage_obj",tp)->query_spells();
                      add[0] = present("mage_obj",tp)->query_my_exp();
                      add[1] = present("mage_obj",tp)->query_donation();
                      add[2] = present("mage_obj",tp)->query_conjuration();
                      add[3] = present("mage_obj",tp)->query_enchantment();
                      add[4] = present("mage_obj",tp)->query_evocation();
                      add[5] = present("mage_obj",tp)->query_illusion();
                      add[6] = present("mage_obj",tp)->query_necromancy();
                      add[7] = present("mage_obj",tp)->query_weapons();
                      break;
         case "monk": if(!present("mrobe",tp)) { destruct(this_object()); return 1;}
                      glevel = tgl; 
                      add[0] = tp->query_guild_exp();
                      add[1] = present("mrobe",tp)->query_guild_loan();
                      break;
         case "undead": if(!present("soul-undead",tp)) { destruct(this_object()); return 1;}
                        glevel = present("soul-undead",tp)->guild_level();
                        add[0] = tp->query_guild_exp();
                        break;
         case "bard": if(!present("bard_obj",tp)) { destruct(this_object()); return 1;}
                      gblevel = present("bard_obj",tp)->query_bard_level();
                      addb = present("bard_obj",tp)->query_bard_xp();
                      break;
         case "shardak": if(!present("shardak_mark",tp)) { destruct(this_object()); return 1;}
                         glevel = present("shardak_mark",tp)->query_guild_class(); 
                         break;
         case "cyberninja": if(!present("CyberNinja Implants",tp)) { destruct(this_object()); return 1;}
                            glevel = present("CyberNinja Implants",tp)->guild_lev(); 
                            add[0] = present("CyberNinja Implants",tp)->guild_exp();
                            add[1] = present("CyberNinja Implants",tp)->query_art_level();
                            add[2] = present("CyberNinja Implants",tp)->balance();
                            add[3] = present("CyberNinja Implants",tp)->query_degree();
                            break;
         case "knights templar": if(!present("KnightTemplar",tp)) { destruct(this_object()); return 1;}
                                 glevel = tp->query_guild_rank(); 
                                 add[0] = present("KnightTemplar",tp)->query_skill("knife");
                                 add[1] = present("KnightTemplar",tp)->query_skill("sword");
                                 add[2] = present("KnightTemplar",tp)->query_skill("axe");
                                 add[3] = present("KnightTemplar",tp)->query_skill("club");
                                 add[4] = present("KnightTemplar",tp)->query_skill("bow");
                                 add[5] = present("KnightTemplar",tp)->query_skill("polearm");
                                 add[6] = present("KnightTemplar",tp)->query_skill("shield");
                                 break;
         case "polymorph": glevel = tgl; break;
         case "hunter": glevel = 666; break;
     } }
     else { glevel = tp->query_guild_rank() ; }
    }
    
    /* guild line */
    
    POWER->listener(tp,1);
    
    /* replacement or overlay of normal actions in game */
    
    add_action("gquit","quit");
    
    /* base guild actions */
    
    add_action("gsave","save_bounty");
    add_action("update_me","update_bounty");
    add_action("note","check_note");
    add_action("enhance","benhance");
    add_action("recall","recall");
    add_action("tele_officer","grounding");
    add_action("ration","ration");
    add_action("grenade","grenade");
    add_action("smoke","smoke");
    add_action("muffle","muffle_bounty");
    add_action("line_on","bounty_on");
#ifndef __LDMUD__
    add_action("gline");add_xverb("bh");
#else
   add_action("gline", "bh", 3);
#endif
    add_action("guild_leave","leave_bounty_hunters");
  }
}

autosave() {
if(ep) {
  if(epl > 19) return 1;
  SOE;
  POWER->listener();
  tell_object(ep,"Bounty stats autosaved....\n"); }
  call_out("autosave",1000);
return 1; }

check_guild() {
object gom;
if(ep) {
  if(epl > 19) return 1; 
  if(ep->query_guild_name()) {
    switch(lower_case(ep->query_guild_name())) {
      case "ranger": break;
      case "vampire": if(glevel != epl) {
                         ep->set_level(glevel);
                         ep->save_me();
                       } 
                     break;
      case "mage": if(present("mage_obj",ep)) {
                    gom = present("mage_obj",ep);
                    if(gblevel != gom->query_spells()) { 
                       gom->set_new_spell_list(gblevel);
                       gom->save_my_stats(); }
                    if(add[0] != gom->query_my_exp()) {
                       gom->set_my_exp(add[0]);
                       gom->save_my_stats(); }
                    if(add[1] != gom->query_donation()) {
                       gom->add_donation(add[1]);
                       gom->save_my_stats(); }
                    if(add[2] != gom->query_conjuration()) {
                       gom->raise_conjuration(add[2] - gom->query_conjuration());
                       gom->save_my_stats(); }
                    if(add[3] != gom->query_enchantment()) {
                       gom->raise_enchantment(add[3] - gom->query_enchantment());
                       gom->save_my_stats(); }
                    if(add[4] != gom->query_evocation()) {
                       gom->raise_evocation(add[4] - gom->query_evocation());
                       gom->save_my_stats(); }
                    if(add[5] != gom->query_illusion()) {
                       gom->raise_illusion(add[5] - gom->query_illusion());
                       gom->save_my_stats(); }
                    if(add[6] != gom->query_necromancy()) {
                       gom->raise_necromancy(add[6] - gom->query_necromancy());
                       gom->save_my_stats(); }
                    if(add[7] != gom->query_weapons()) {
                       gom->raise_weapons(add[7] - gom->query_weapons());
                       gom->save_my_stats(); }
                   }
                   break;
      case "monk": if(present("mrobe",ep)) {
                     gom = present("mrobe",ep);
                     if(glevel != egl) {
                       tp->add_guild_rank(glevel - egl); 
                       ep->save_me(); 
                       gom->set_guild_rank(glevel);
                     }
                     if(add[0] != ep->query_guild_exp()) { 
                       ep->add_guild_exp(add[0] - ep->query_guild_exp()); 
                       ep->save_me(); 
                       gom->set_guild_exp(add[0]);
                     }
                     if(add[1] != gom->query_guild_loan()) {
                       gom->set_guild_loan(add[1]);
                     }
                   }
                   break;
      case "undead": if(glevel != egl || add[0] != ep->query_guild_exp()) {
                       ep->add_guild_exp(add[0] - ep->query_guild_exp());
                       ep->save_me();
                     }
                     break;
      case "bard": if(present("bard_obj",ep)) {
                   gom = present("bard_obj",ep);
                     if(gblevel != gom->query_bard_level()) {
                        gom->set_bard_level(gblevel); gom->save_me(); }
                     if(addb != gom->query_bard_xp()) {
                        gom->set_bard_xp(addb); gom->save_me(); }
                   }
                   break;
      case "shardak": if(present("shardak_mark",ep)) {
                         gom = present("shardak_mark",ep);
                         if(glevel != gom->query_guild_class()) {
                           gom->set_guild_class(glevel);
                           gom->save_me(); }
                       }
                       break;
      case "cyberninja": if(present("CyberNinja Implants",ep)) {
                           gom =  present("CyberNinja Implants",ep);
                           if(glevel != gom->guild_lev()) { 
                             gom->set_rank(glevel); gom->save_me(); }
                           if(add[0] != gom->guild_exp()) {
                             gom->set_xp(add[0]); gom->save_me(); }
                           if(add[1] != gom->query_art_level()) {
                             gom->set_art_level(add[1]); gom->save_me(); }
                           if(add[2] != gom->balance()) {
                             gom->addToBalance(add[2] - gom->balance()); gom->save_me(); }
                           if(add[3] != gom->query_degree()) {
                             gom->set_degree(add[3]); gom->save_me(); }
                         }
                             break;
      case "polymorph": if(egl != glevel) { ep->add_guild_rank(glevel - egl); ep->save_me();}
                        break;
      case "knights templar": if(present("KnightTemplar",ep)) {
                       gom = present("KnightTemplar",ep);
                       if(glevel != egl) { ep->add_guild_rank(glevel - egl); ep->save_me(); }
                       if(add[0] != gom->query_skill("knife")) 
                           gom->add_skill("knife",add[0] - gom->query_skill("knife"));
                       if(add[1] != gom->query_skill("sword")) 
                           gom->add_skill("sword",add[1] - gom->query_skill("sword"));
                       if(add[2] != gom->query_skill("axe")) 
                           gom->add_skill("axe",add[2] - gom->query_skill("axe"));
                       if(add[3] != gom->query_skill("club")) 
                           gom->add_skill("club",add[3] - gom->query_skill("club"));
                       if(add[4] != gom->query_skill("bow")) 
                           gom->add_skill("bow",add[4] - gom->query_skill("bow"));
                       if(add[5] != gom->query_skill("polearm")) 
                           gom->add_skill("polearm",add[5] - gom->query_skill("polearm"));
                       if(add[6] != gom->query_skill("shield")) 
                           gom->add_skill("shield",add[6] - gom->query_skill("shield"));
                     }
                     break;
      case "hunter": break;
    } 
  } else { if(ep->query_guild_rank() != glevel && present(fear,ep)) 
             present(fear,ep)->set_dark_level(glevel); }
}
  call_out("check_guild",5);
return 1; }

gquit() {
   gsave();
   POWER->listener(ep,0);
   POWER->listener();
   if(epl > 20) ep->do_quit(); 
   else { ep->save_me(); ep->quit(); }
return 1;}

gsave() {
  SOE;
  tell_object(ep,RED+"Bounty stats saved....\n"+NORM);
return 1;} 

update_me() {
  ROE;
  tell_object(ep,BLU+"Bounty Object Updated....\n"+NORM);
  move_object(clone_object("/players/mythos/bounty/cloak.c"),ep);
  destruct(this_object());
return 1;}

guild_leave() {
  command("bhe leaves the Bounty Hunters",ep);
  listener(ep,0);
  rm(MEM+epn);
  move_object(ep,"/room/church.c");
  ep->save_me();
  log_file("GUILD",ctime(time())+" --> "+capitalize(epn)+" has left the Bounty Hunters.\n");
  destruct(this_object());
return 1; }

set_form(str) { 
  if(str != "tech" && str != "medival") form = "medival";
  else form = str;
}

set_bounty_level(n) { level = n; gsave(); }
add_bounty_level(n) { level = level + n; gsave(); }

query_form() { return form; }
query_level() { return level; }

muffle() { POWER->listener(ep,0); return 1; }
line_on() { POWER->listener(ep,1); return 1; }

/* Powers in power.c */

note() { POWER->note(); return 1; }
enhance(str) { POWER->enhance(str); return 1; }
recall(str) { POWER->recall(str); return 1; }
tele_officer() { POWER->tele_officer(); return 1; }
ration(str) { POWER->ration(str); return 1; }
grenade(n) { POWER->grenade(n); return 1; }
smoke() { POWER->smoke(); return 1; }
gline(str) { POWER->gline(str); return 1; }
