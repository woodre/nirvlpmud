/* Orginal code from Bern's Clerics, 
   Modified to become The Knight's Templar by Boltar.
*/
#include "security.h"
#include "/players/boltar/things/esc.h"
#define TP this_player()
#define CHUNK 20
#define num_skill 22
int sword,knife,axe,club;
static int listen;
static string more_file;        /* Used by the more command */
static int more_line;
int ref_flag;
int bow,polearm;
int shield;
int horse;
static string skills;
static int teleport_ok,fear_ok;
static object current_wep;
static string current_skill;
int block;           /* Block templar channel */
static int shieldsumm;      /* Tell if shield has been summoned */
static int worn;
static int spell_ok;
static int death;
int donation;
static object owner;
static object me;
static object helper;
static int notyet;
string locked;


id(str) {
object teee,yeee;
yeee=environment(this_object());
if(yeee)
teee=environment(yeee);
if(teee) {
  if(present("cross",teee)) 
    return str == "ND" || str == "GI" || str == "ND" || str == "KnightTemplar" || str == "templar cross";
}
   return str == "ND" || str == "cross" || str == "GI" ||
   str == "cross" || str == "KnightTemplar";
}

reset(arg) {
   if (arg) return;
   death = 0;
   worn = 0;
   shieldsumm = 0;
   teleport_ok=1;
   notyet = 0;
   owner = TP;
   skills = allocate(num_skill+1);
   skills[0]="sword";
   skills[1]="knife";
   skills[2]="axe";
   skills[3]="club";
   skills[4]="bow";
   skills[5]="polearm";
   skills[6]="shield";
   skills[7]="dagger";
   skills[8]="blade";
   skills[9]="spear";
   skills[10]="staff";
   skills[11]="gun";
   skills[12]="trident";
   skills[13]="katana";
   skills[15]="hammer";
   skills[16]="swords";
   skills[17]="blades";
   skills[18]="stick";
   skills[19]="horse";
   skills[20]="mace";
   skills[21]="pole";
   skills[22]="morningstar";
   if(TP){
   if (TP->query_guild_exp() == 1234) call_out("destroy_me",0);
   restore_object("players/boltar/templar/members/"+this_player()->query_real_name());
    if(!ref_flag)
    if(!TP->query_invis() && TP->query_level() < 1000) 
   sende("has entered the game.",5);
   }
}

destroy_me() {
destruct(this_object());
}
get() { return 1; }

drop() {
   if (query_verb() == "drop")
      write("You don't want to drop your cross!\n");
   return 1;
}

init() {
   add_action("cure","cure");
   add_action("lock_member","suspend");
   add_action("unlock_member","restore");
   add_action("calm","calm");
   add_action("sponsor","sponsor");
   add_action("compare","compare");
   add_action("quit","quit");
   add_action("home","home");
   add_action("crush","crush");
   add_action("gstat","gstat");
/*
   add_action("leave","retire");
*/
   add_action("helpercom","command");
add_action("refresh","crefresh");
   add_action("wear","wear");
   add_action("remove","remove");
   add_action("resurrect","resurrect");
   add_action("decorpse","decorpse");
   add_action("shield","shield");
   add_action("teleport","castle");
   add_action("death","death");
   add_action("revive","revive");
   add_action("alignment","alignment");
   add_action("electric","electric");
   add_action("electric","elec");
   add_action("light","createlight");
   add_action("blast","blast");
   add_action("ice","ice");
   add_action("helper","summon");
   add_action("info","info");
   add_action("record","record");
   add_action("read_record","read_record");
   add_action("tail_record","tail_record");
   add_action("send","tc");
   add_action("guildwho","templar");
   add_action("guildwho","tw");
   add_action("minor","minor");
   add_action("major","major");
   add_action("fear","fear");
   add_action("peek","peek");
   add_action("bless","bless");
   add_action("fixtitle","fixtitle");
   add_action("block","block");
   add_action("I","I");
   add_action("sende","tce");
   if(TP) {
     me=environment(this_object());
    if(TP==environment() && !TP->query_guild_name())
      TP->set_guild_name("Knights Templar");
/*
cat("/players/boltar/templar/info/news");
*/
}
}

wear(str) {
   if (!id(str)) return 0;
   if (worn) {
      write("You are already wearing your cross.\n");
      return 1;
   }
   worn = 1;
   write("You feel a surge of power as you don your cross.\n");
   say(TP->query_name()+" wears "+
      TP->query_possessive()+" Cross of the Knights Templar.\n");
   write("Ok.\n");
   return 1;
}

remove(str) {
   if (!id(str)) return 0;
   if (!worn) {
      write("You are not wearing your cross.\n");
      return 1;
   }
   worn = 0;
   write("You feel weakened.\n");
   say(TP->query_name()+" removes "+
      TP->query_possessive()+" Cross of the Knights Templar.\n");
   write("Ok.\n");
   return 1;
}

short() {
   if (!owner) return "Someone's Cross of the Knights Templar";
   if (worn) return owner->query_name()+"'s Cross of the Knights Templar (worn)";
   return owner->query_name()+"'s Cross of the Knights Templar";
}

long() {
   write("The Red on White cross of The Knights Templar.\n");
   write("For a list of commands, type info.\n");
   write("For a list of Templar titles, type info titles.\n");
}

test_piety(i) {
 int flag,gr;
 gr = this_player()->query_guild_rank();
 if(i > 17 && gr < 7) flag = 1;
 if(i > 15 && gr < 6) flag = 1;
 if(i > 13 && gr < 5) flag = 1;
 if(i > 11 && gr < 4) flag = 1;
 if(i > 9 && gr < 3) flag = 1;
 if(i > 8 && gr < 2) flag = 1;
 if(flag) {
   write("You must be of higher guild rank before using this spell.\n");
   return 0;
 }
   if (TP->query_attrib("pie") >= i) return 1;
   else write("You must increase your piety before using this spell.\n");
   return 0;
}

resurrect(str) {
   object victim;
   if (!test_piety(18)) return 1;
   if (!str) {
      write("Resurrect whom?\n");
      return 1;
   }
   victim = present("ghost of "+str, environment(TP));
   if (!victim) {
      write("Your person is not here.\n");
      return 1;
   }
   if (!living(victim) || victim->query_npc()) {
      write("You find you cannot cast your spell on that.\n");
      return 1;
   }
   if(victim == this_player()) { 
    write("You cannot cast this spell on yourself.\n");
    return 1;
   }
   if(victim->query_dead() > 1) {
     write(str+" is not really dead.\n");
     return 1;
    }
   if (!victim->query_ghost()) {
      write("You cannot cast a resurrection spell on something that is alive.\n");
      return 1;
   }
   spell_cost(225);
   if (!spell_ok) {
      write("You lack the spell/donation points to cast that spell.\n");
      return 1;
   }
   write("You shudder as the mystical words of the resurrection spell\n"+
      "pass your lips. You feel a rush through you as the spell takes effect.\n");
   say(TP->query_name() + " focuses a resurrection spell on "+ str+".\n"+
      "You feel powerful forces at play here.\n");
   call_other(victim, "remove_ghost", 0);
   write("Ok.\n");
   return 1;
}

shield() {
   if (!test_piety(9)) return 1;
   if (shieldsumm) {
      write("You have already summoned a shield.\n");
      return 1;
   }
   if(TP->query_money() < 320) {
     write("You do not have the money that you must sacrifice.\n");
     return 1;
  }
   spell_cost(40);
   
   if (!spell_ok) {
      write("You lack the spell/donation points to cast that spell.\n");
      return 1;
   }
   write("You summon the shield preferred by more knights around the world...\n");
   say(TP->query_name()+ " tosses coins into the air and creates a shield.\n");
/*
   say(TP->query_name()+ " creates a shield out of thin air.\n");
*/
   shieldsumm = 1;
   call_out("unshield",600);
   move_object(clone_object("/players/boltar/templar/shield"), TP);
   command("wear shield", TP);
   TP->add_money(-320);
   return 1;
}

unshield() {
   shieldsumm = 0;
}


teleport(str) {
   object env;
 string where; 
   env = environment(TP);
   if(str && TP->query_level() > 20) return 0;
   if(env->realm()=="NT") {
      write("You cannot teleport from this locus...\n");
      return 1;
   }
   if(!teleport_ok) {
      write("You can't quite remember how to do that.\n");
      write("Maybe it'll come back to you later.\n");
      return 1;
   }
   spell_cost(55+random(5));
   if (!spell_ok) {
      write("You find yourself too weak for that spell.\n");
      return 1;
   }
     if(where = call_other("obj/base_tele","teleport")) {
               TP->move_player("with an astonished look#"+where);
        write("Something goes wrong.....\n");
        return 1;
      }
   write("You fly through the air and land in the Templar's hall.\n");
   TP->move_player("to the Templar's hall#/players/boltar/templar/adv_guild");
   teleport_ok=0;
   call_out("tele_ok",300);
   return 1;
}

tele_ok() { teleport_ok=1; }
fearok() { fear_ok = 0; }

alignment(str) {
   object victim;
   string tmpaln;
   int tmpal;
   spell_cost(3);
   if (!spell_ok) {
      write("You lack the spell/donation points to cast that spell.\n");
      return 1;
   }
   tmpal = TP->query_alignment();
   if (!str) {
      write("Your alignment: "+ aln(tmpal) + "\n");
      return 1;
   }
   victim = present(str, environment(TP));
   if (!victim) {
      write("That is not here.\n");
      return 1;
   }
   if (!living(victim)) {
      write("You can't do that!\n");
      return 1;
   }
   tmpal = victim->query_alignment();
   write(capitalize(str) + "'s alignment: " + aln(tmpal) + "\n");
   return 1;
}

aln(arg) {
if (arg > 10 * 64) {
        return "white lord";
    }
    if (arg > 10 * 32) {
        return "paladin";
    }
    if (arg > 10 * 16) {
        return "crusader";
    }
    if (arg > 10 * 8) {
        return "good";
    }
    if (arg > 10 * 4) {
        return "honorable";
    }
    if (arg > - 10 * 4) {
        return "neutral";
    }
    if (arg > - 10 * 8) {
        return "malicious";
    }
    if (arg > - 10 * 16) {
        return "evil";
    }
    if (arg > - 10 * 32) {
        return "infamous";
    }
    if (arg > - 10 * 64) {
        return "black knight";
    }
    return "lord of evil";
}

death() {
   object corpse;
   if (death) {
      write("You are already feigning death.\n");
      return 1;
   }
   if(TP->query_attack()) {
      write("You can't concentrate while being attacked.\nYou fail.\n");
      return 1;
   }
   corpse = clone_object("players/boltar/templar/corpse");
   corpse->set_name(TP->query_real_name());
   move_object(corpse, environment(TP));
   move_object(TP, corpse);
   write("You die.\n");
   tell_room(environment(corpse), TP->query_name()+ " dies.\n");
   death = 1;
   return 1;
}

revive() {
   object corpse;
   if (!death) {
      write("You are not feigning death.\n");
      return 1;
   }
   corpse = environment(TP);
   if (!corpse->id("body")) {
      death = 0;
      write("You are not feigning death.\n");
      return 1;
   }
   move_object(TP, environment(corpse));
   write("You revive.\n");
   say(TP->query_name()+" revives from death.\n");
   destruct(corpse);
   death = 0;
   return 1;
}

light() {
object it,light;
   if (!test_piety(9)) return 1;
   spell_cost(25);
   if (!spell_ok) {
      write("You lack the spell/donation points for the light spell.\n");
      return 1;
   }
/*
   move_object(clone_object("players/boltar/templar/light"), TP);
   call_out("dark",600);
*/
light = clone_object("obj/torch");
        call_other(light, "set_name", "light");
        call_other(light, "set_short", "A blazing ball of light");
        call_other(light, "set_fuel",600);
        call_other(light, "set_weight", 0);
        call_other(light, "set_value",0);
        call_other(light, "set_out_desc", "Your globe of light winks out.\n");
        move_object(light,TP);
        command("light light",TP);
   write("You clap your hands and a ball of light forms!\n");
   say(TP->query_name()+" summons light!\n");
   it = environment(this_player())->shardak_darkness(0);
   if(it) {
   write("The cloud of darkness is lifted.\n");
   say(this_player()->query_name() + " casts light upon the darkness, removing it.\n");
   destruct(it);
   }
   return 1;
}

dark() {
   write("Your globe of light winks out.\n");
   say("It grows darker.\n");
}

static electric(str) {
   object victim;
   if (!test_piety(12)) return 1;
   if (str) victim = present(str, environment(TP));
     else   victim = TP->query_attack();
   if(!str && !victim) return 0;
   if(!victim) { write("That is not here.\n"); return 1; }
/*
   if (!living(victim) || (!victim->query_npc() && victim->query_pl_k())) {
*/
    if (!living(victim)) {
      write("You cannot attack that!\n");
      say(TP->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
   spell_cost(14,1);
   if (!spell_ok) {
      write("You lack the spell/donation points for that spell.\n");
      return 1;
   }
TP->spell_object(victim,"electric weapon spell",random(26),14,"You boost your weapon with a flash of electric power\n",TP->query_name()+" charges "+TP->query_possessive()+" weapon with a flash of electricity.\n",
   TP->query_name()+" charges "+TP->query_possessive()+" weapon with electricity\n");
   return 1;
}

static blast(str) {
   object victim;
   if (!test_piety(15)) return 1;
   if (str) victim = present(str, environment(TP));
     else   victim = TP->query_attack();
   if(!str && !victim) return 0;
   if(!victim) { write("That is not here.\n"); return 1; }
/*
   if (!living(victim) || (!victim->query_npc() && victim->query_pl_k())) {
*/
   if (!living(victim)){
      write("You cannot attack that!");
      say(TP->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
   spell_cost(24,1);
   if (!spell_ok) {
      write("You lack the spell/donation points for that spell.\n");
      return 1;
   }
TP->spell_object(victim, "BLAST", random(25)+10, 24, "You blast "+victim->short()+" with a holy light\n", "You are hit by a blast of holy light from "+TP->query_name()+"\n", TP->query_name()+" with a holy light, blasts "+victim->short()+"\n");
/*
   write(TP->query_name()+" BLASTS " + victim->short()+"\n");
   say(TP->query_name()+" BLASTS " + victim->short()+"\n");
*/
   return 1;
}

static ice(str) {
   object victim;
   if (!test_piety(17)) return 1;
   if(str) victim = present(str, environment(TP));
     else   victim = TP->query_attack();
   if(!str && !victim) return 0;
   if(!victim) { write("That is not here.\n"); return 1; }
/*
   if (!living(victim) || (!victim->query_npc() && victim->query_pl_k())) {
*/
   if (!living(victim)) {
      write("You cannot attack that!\n");
      say(TP->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
   spell_cost(30,1);
   if (!spell_ok) {
      write("You lack the spell/donation points for that spell.\n");
      return 1;
   }
TP->spell_object(victim, "ice coating", random(26)+15, 30, "You give your weapon a coating of ice, shattering and sending shards upon impact \n", TP->query_name()+" casts a spell of ice upon "+TP->query_possessive()+" weapon, shards piercing your skin.\n", TP->query_name()+" coats a weapon with ice\n");
/*
   write(TP->query_name()+" fires ice arrows at " + victim->short()+"\n");
   say(TP->query_name()+" fires ice arrows at " + victim->short()+"\n");
*/
   return 1;
}

helper(i) {
   if(i != "helper" && i != "squire") return 0;
   if (!test_piety(9)) return 1;
   spell_cost(2);
   if (!spell_ok) {
      write("You lack the energy for that spell.\n");
      say(TP->query_name()+" tries to cast a spell, but fails.\n");
      return 1;
   }
   if (helper) {
      write("You already have a helper.\n");
      return 1;
   }
   write("You summon a helper.\n");
   write("Use 'info helper' for commands.\n");
   helper = clone_object("players/boltar/templar/helper");
   helper->set_owner(capitalize(TP->query_real_name()));
   move_object(helper, environment(TP));
   helper->sq_follow();
   return 1;
}

send(str) {
   object list;
   object cross;
   int i;
   string myname;
   if(block && block!=3) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   if (!str) { write("Send what?\n"); return 1; }
   list = users();
if(str == "block") {
for(i=0;i<sizeof(list);i++) {
cross = present("KnightTemplar",list[i]);
if(cross && cross->query_block()) {
write(list[i]->query_name()+" is blocking the Templar channel.\n");
}
}
return 1;
}
str=format(str,60);
myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], esc+"[0m"+esc+"[0m"+esc+"[32m"+
          "(templar) "+myname+esc+"[0m: "+
            str+"\n");
       }
   }
   /*
   for (i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && cross->query_block() && !list[i]->query_invis())
         write(list[i]->query_name() +" is blocking the templar channel.\n");
   }
  */
   return 1;
}

block(str) {
   if(str=="enter") {
   block = 3;
     write("Templar Channel on, enter/exit messages off.\n");
   return 1;
  }
   block = !block;
   write("Templar block: ");
   if (block) write("on\n");
   else write("off\n");
   return 1;
}

guildwho() {
   object list;
   string env;
   int namelen;
   int i;
   int b;
   int namlen;
   int spacelen;
   write("\n");
   cat("/players/boltar/templar/info/head");
   list = users();
   for(i=0; i<sizeof(list);i++) {
      if(present("KnightTemplar",list[i]) && !list[i]->query_invis()) {
         namlen = strlen(list[i]->query_name());
         spacelen = 15-namlen;
if(list[i]->query_level()>9) {
write("@   ["+list[i]->query_level()+"] "+list[i]->query_guild_rank()+
"\t"+list[i]->query_name());
}
if(list[i]->query_level()<10) {
write("@   [0"+list[i]->query_level()+"] "+list[i]->query_guild_rank()+
"\t"+list[i]->query_name());
}
         for(b=0;b<spacelen;b++) {
            write(" ");
         }
         env = environment(list[i])->short();
         namelen = strlen(env);
         spacelen = 47 - namelen;
         write(environment(list[i])->short());
         for(b=0;b<spacelen;b++) {
            write(" ");
         }
         write("@\n");
       }
   }
write("@                                                                             @\n");
write("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   write("\n");
   return 1;
}

minor(str) {
   object victim;
   if (!test_piety(11)) return 1;
   if (!str) victim = TP;
   if (!victim) victim = present(str, environment(TP));
   if (!victim && !living(victim)) {
      write("You cannot heal that!\n");
      return 1;
   }
/*
   if(TP->query_money() < 400) {
     write("You do not have the money that you must sacrifice.\n");
     return 1;
  }
*/
   spell_cost(25);
   if (!spell_ok) {
      write("You lack the energy for that spell.\n");
      return 1;
   }
   write("You cast a heal spell on "+victim->query_name()+"\n");
   say(TP->query_name() +" casts a heal spell on "+ victim->query_name() + "\n");
/*
   TP->add_money(-400);
*/
   victim->add_hit_point(20);
   /* extra so that the player spends the spell points */
   return 1;
}

major(str) {
   object victim;
   if (!test_piety(14)) return 1;
   if (!str) victim = TP;
   if (!victim) victim = present(str, environment(TP));
   if (!victim && !living(victim)) {
      write("You cannot heal that!\n");
      return 1;
   }
/*
    if(TP->query_money() < 900) {
     write("You do not have the money that you must sacrifice.\n");
     return 1;
  }
*/
   spell_cost(50);
   if(!spell_ok) {
      write("You lack the energy for that spell.\n");
      return 1;
   }
   write("You cast a major heal spell on "+victim->query_name()+"\n");
   say(TP->query_name() +
      " casts a major heal spell on "+ victim->query_name() + "\n");
   victim->add_hit_point(40);
   return 1;
}

spell_cost(i,f) {
   if(locked) {
     write("Your guild abilities have been suspended by "+locked+".\n");
     spell_ok = 0;
     return 1;
   }
   if (TP->query_alignment() < -5) {
      write("You find that the deities have forsaken you, your magical\n");
      write("power is crippled. You are without any special powers.\n");
      write("Prehaps if you changed your evil ways the deities will allow you to tap there source of magic agian.\n");
      spell_ok = 0;
      return 1;
   }
  if(TP->query_ghost()) {
    write("You cannot do that when you are dead.\n");
    spell_ok = 0;
    return 1;
   }
    if(!donation_check(i/10,0)) {
     spell_ok = 0;
     return 1;
    }
   if (TP->query_sp() < i) spell_ok = 0;
   else {
   if(!f)
   TP->add_spell_point(-i);
   spell_ok = 1;
   }
   return 1;
}

decorpse() {
  object blah;
   object corpse;
   string i;
   corpse = present("corpse", environment(TP));
   if (!corpse) {
      write("No corpse present.\n");
      return 1;
   }
   write("With a churning noise, "+corpse->short()+" is processed.\n");
   say(TP->query_name() + " processes "+ corpse->short()+"\n");
   if (sscanf(file_name(corpse),"obj/corpse%s",i)!=1) return 1;
   if (sscanf(corpse->short(),"%sSquire",i) != 1){
      blah=clone_object("players/boltar/templar/items/steak");
      blah->set_healval(corpse->heal_value());
       move_object(blah, environment(corpse));
    }
   destruct(corpse);
   return 1;
}


fear(str) {
   object victim;
   if(!str) {
     write("Fear who?\n");
     return 1;
    }
   if(fear_ok) {
     write("You must wait before summoning power for that spell again.\n");
     return 1;
   }
   if (!test_piety(14)) return 1;
   victim = present(str, environment(TP));
   if (!victim || !living(victim)) {
      write("You fail.\n");
      return 1;
   }
   spell_cost(30);
   if (!spell_ok) {
      write("You lack the energy for that spell.\n");
      say(TP->query_name()+" tries to cast a spell but fails.\n");
      return 1;
   }
   if(!victim->query_wimpy()) {
      write("Your victim withstands your fear.\n");
      return 1;
   }
   if(random(100 - victim->query_attrib("wil")) > 70) {
      write("You fail.\n");
      return 1;
   }
   write(capitalize(str)+" suddenly looks frightened.\n");
   victim->run_away();
   fear_ok = 1;
   call_out("fearok", 300);
   return 1;
}

peek(i) {
   object ob;
   int perc;
   if (!test_piety(10)) return 1;
   spell_cost(5);
   if (!spell_ok) {
      write("You lack the strength for that spell.\n");
      return 1;
   }
   if (!i) ob = TP->query_attack();
   else
      ob = present(i, environment(TP));
   if (!ob) return 0;
   if (!living(ob)) {
      write("You cannot 'peek' that.\n");
      return 1;
   }
   perc = ob->query_hp()*10 / ob->query_mhp();
   if (!i) i = ob->short();
   write("A sprite comes to you and whispers in your ear:\n"+
      capitalize(i) + " has " + perc + "/10 of its hitpoints left.\n");
   say(TP->query_name()+ " scrutinizes "+capitalize(i) +
      " carefully.\n");
   return 1;
}

bless(str) {
   object weapon;
   int old_class;
   int old_value;
   string a, b;
   if (!test_piety(16)) return 1;
   weapon = present(str, TP);
   if (!weapon) {
      write("You don't have "+str+" with you.\n");
      return 1;
   }
  if (TP->query_money() < 777) {
     write("You don't have enough money to sacrifice.\n");
     return 1;
   }
   spell_cost(80);
   if (living(weapon)) {
      write("Your spell balks.\n");
      return 1;
   }
   if (!spell_ok) {
      write("You lack the strength for that spell.\n");
      return 1;
   }
   TP->add_money(-777);
   old_class = weapon->weapon_class();
   old_value = weapon->query_value();
   if (!old_class) {
      write("Wild magicks destroy "+weapon->short()+".\n");
      say(weapon->short()+" goes up in a puff of smoke.\n");
      destruct(weapon);
      return 1;
   }
   if (present("blessing",weapon)) {
      write(weapon->short()+ " has already been blessed.\n");
      return 1;
   }
   if (sscanf(weapon->short(),"%swield%s",a,b) == 2)
      command("unwield "+weapon->query_name(), TP);
   if (random(50)>10) {
      weapon->set_class(old_class + 1);
      move_object(clone_object("players/boltar/templar/blessing"), weapon);
      write("You cast your blessing on "+weapon->short()+".\n");
      say(TP->query_name()+" casts "+
         TP->query_possessive()+" blessing on "+
         weapon->short()+".\n");
      if (old_class > 18 && random(12)>8) {
         write("CRACK! Your weapon broke in two!\n");
         destruct(weapon);
       }
      return 1;
   }
   write("Wild magicks destroy "+weapon->short()+".\n");
   say(weapon->short()+" goes up in a puff of smoke.\n");
   destruct(weapon);
   return 1;
}

info(str) {
   if (!str) {
      cat("/players/boltar/templar/info/basics");
      return 1;
   }
   if (file_size("/players/boltar/templar/info/"+str)) {
      cat("/players/boltar/templar/info/"+str);
      return 1;
   }
   write("There is no information on that.\n");
   return 1;
}

fixtitle() {
   string title;
   title = "players/boltar/templar/adv_guild"->query_title(TP);
   TP->set_title(title);
   write("Title fixed.\n");
   return 1;
}

list(i) {
   if (i!= "titles") return 0;
   cat("/players/boltar/templar/info/titles");
   return 1;
}

helpercom(i) {
   string a,b;
   object ob;
   if (!helper) { write("You don't have a helper.\n");
      return 1;
   }
  if(this_player()->query_ghost()) {
    write("The helper cannot hear you when you are a ghost.\n");
    return 1;
  }
   if (sscanf(i,"describe %s",b) == 1) {
      helper->describe(b);
      return 1;
   }
   if (sscanf(i,"emote %s",b) == 1) {
      write(helper->short()+" "+b+"\n");
      say(helper->short()+" "+b+"\n");
      return 1;
   }
   if (sscanf(i,"get %s",b) == 1) {
      if (b == "all") {
         helper->get_all();
         return 1;
       }
      if (sscanf(b,"all from %s",a) == 1) {
         helper->get_all(a);
         return 1;
       }
      ob = present(b, environment(helper));
      if (!ob) return 1;
      helper->pick_up(ob);
      return 1;
   }
   if (sscanf(i,"drop %s",b) == 1) {
      if (b == "all") {
         helper->drop_all();
         return 1;
       }
      if (b == "money" || b == "all money") {
         helper->drop_money();
         return 1;
       }
      ob = present(b, helper);
      if (!ob) return 1;
      helper->drop_thing(ob);
      return 1;
   }
   if(i == "call") {
   object gg;
   gg=find_living(lower_case(TP->query_name())+"'s squire");
   gg->sq_follow();
   write("You call for your squire.\n");
   return 1;
   }
   helper->do_cmd(i);
   return 1;
}

set_owner(i) { owner = i; }

refresh(arg) {
object jj;
if(helper) { 
  write("You must dispell your helper first\n");
  return 1;
}
if(death) {
  write("You must return to your normal state first.\n");
  return 1;
}
if(shieldsumm) {
  write("You must wait until the shield spell wears off.\n");
  return 1;
}
if(!arg || arg != 786) {
  ref_flag= 1;
  save_ob();
  jj=clone_object("/players/boltar/templar/templar.c");
  move_object(jj,environment(this_object()));
  jj->refresh(786);
  destruct(this_object());
  return 1;
  }
if(arg == 786) ref_flag = 0;
   owner = TP;
   write("Ok.\n");
   return 1;
}


query_block() { if (block == 3) return 0; else return block; }

query_guild_obj() { return 1; }

cure(str) {
   object victim;
   object poison, next;
   string a,b;
   if (!test_piety(16)) return 1;
   if (!str) victim = TP;
   else victim = present(str, environment(TP));
   spell_cost(40);
   if (!spell_ok) {
      write("You find yourself too weak for this spell.\n");
      return 1;
   }
   poison = first_inventory(victim);
   while (poison) {
      next = next_inventory(poison);
      if (sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
            poison->id("poison")) {
         destruct(poison);
         }
      poison = next;
   }
   write("You cast a cure spell on "+victim->query_name()+".\n");
   tell_object(victim,
      "You feel a soothing light bathe over you,\n"+
      "removing all traces of poison from your person.\n");
   tell_room(environment(TP),TP->query_name()+
      " casts a purifying light upon ");
   if (victim == TP)
      tell_room(environment(TP),
      TP->query_objective()+"self.\n");
   else tell_room(environment(TP),victim->query_name()+".\n");
   return 1;
}

rain() {
   object victim, next;
   if (!test_piety(14)) return 1;
   if (notyet) return 1;
   spell_cost(60);
   if (!spell_ok) {
      write("You find yourself too weak for this spell.\n");
      return 1;
   }
   victim = first_inventory(environment(TP));
   while (victim) {
      next = next_inventory(victim);
      if (victim->query_npc() && living(victim)) {
         victim->hit_player(35);
         victim->attacked_by(TP);
         }
      victim = next;
   }
   write("Your prayers summon holy rain down upon your enemies!\n");
   say("Holy rain comes crashing down in a fury!\n");
   notyet = 1;
   call_out("resetyet",3);
   return 1;
}

resetyet() { notyet = 0; }

leave() {
   int exp,minus;
   
   exp = TP->query_exp();
   minus = exp/6;
   TP->add_exp(-minus);
   TP->set_guild_file(0);
   TP->set_home(0);
   TP->set_guild_rank(0);
   TP->set_guild_name(0);
   TP->add_guild_exp(-TP->query_guild_exp());
   TP->add_guild_rank(-TP->query_guild_rank());
   write("The Knights Templar leave you to find your way alone.\n");
   sende("has left the Knights Templar");
   rm("/players/boltar/templar/members/"+TP->query_real_name()+".o");
   destruct(this_object());
   return 1;
}

crush() {
   object duh;
   duh = present(lower_case(TP->query_name())+"'s squire", environment(TP));
   if (!duh) {
      write("You don't have a helper to crush!\n");
      return 1;
   }
   destruct(duh);
   write("You have crushed your helper to smithereens!\n");
   say(TP->query_name()+" has crushed his helper to smithereens!\n");
   return 1;
}

I() {
int totvalu;
int length;
int wc,ac;
int weight,valu;
object next,ob;
string name;
int i,namelen,spacelen;
   totvalu=0;
   write("\n");
   write("Your Inventory:\n");
   for(i=0;i<37;i++) {
      write("=-");
   }
   write("\n");
   write("Name");
   for(i=0;i<35;i++) {
      write(" ");
   }
   write("Value\tWeight");
   for(i=0;i<9;i++) {
      write(" ");
   }
   write("Type\n");
   for(i=0;i<75;i++) {
      write("=");
   }
   write("\n");
   ob = first_inventory(this_player());
   while(ob) {
      weight = ob->query_weight();
      next = next_inventory(ob);
      name = ob->short();
      valu = ob->query_value();
      if(ob->short()) {
         namelen = strlen(name);
         spacelen = 40-namelen;
         write(name);
         for(i=0;i<spacelen;i++) {
            write(" ");
         }
         write(valu);
         write("\t");
         if(weight==0 || weight == 1) {
            write("Light");
            length=5;
         }
         if(weight==2 || weight == 3) {
            length=8;
            write("Moderate");
         }
         if(weight == 4 || weight == 5) {
            write("Heavy");
            length=5;
         }
         if(weight==6 || weight == 7) {
            write("Very Heavy");
            length=10;
         }
         if(weight>7) {
            write("Lead Weight");
            length=11;
         }
         for(i=0;i<(15-length);i++) {
            write(" ");
         }
         wc = ob->weapon_class();
         ac = ob->armor_class();
         if(wc>0) {
            write("Weapon\n");
         }
         if(ac>0) {
            write("Armour\n");
         }
         if(!wc>0 && !ac>0) {
            write("Item\n");
         }
         }
      totvalu=totvalu+valu;
      ob = next;
   }
   write("\nTotal Value: "+totvalu+".\n");
   return 1;
}
sende(str,arg) {
   object list;
   object cross;
   string myname;
   int i;
   if(block && block!=3) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   if (!str) { write("Send what?\n"); return 1; }
   list = users();
if(str == "block") {
for(i=0;i<sizeof(list);i++) {
cross = present("KnightTemplar",list[i]);
if(cross && cross->query_block()) {
write(list[i]->query_name()+" is blocking the Templar channel.\n");
}
}
return 1;
}
str=format(str,60);
myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && !cross->query_block()) {
      if(arg != 5 || !cross->query_eblock()) 
          tell_object(list[i], esc+"[0m"+esc+"[0m"+esc+"[32m"+
          "(templar) "+myname+esc+"[0m "+
            str+"\n");
       }
   }
    /*
   for (i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && cross->query_block() && !list[i]->query_invis())
         write(list[i]->query_name() +" is blocking the templar channel.\n");
   }
   */
   return 1;
}

query_skill(str) { 
 if(str=="knife") return knife;
 if(str=="dagger") return knife;
 if(str=="sword") return sword;
 if(str=="blade") return sword;
 if(str=="axe") return axe;
 if(str=="club") return club;
 if(str=="hammer") return club;
 if(str=="mace") return club;
 if(str=="bow") return bow;
 if(str=="staff") return club;
 if(str=="morningstar") return club;
 if(str=="polearm") return polearm;
 if(str=="spear") return polearm;
 if(str=="shield") return shield;
 if(str=="trident") return polearm;
 if(str=="katana") return sword;
 if(str=="swords") return sword;
 if(str=="blades") return sword;
 if(str=="stick") return polearm;
 if(str=="pole") return polearm;
 if(str=="gun") return bow;
 if(str=="horse") return horse;
 return;
}
add_skill(str,arg) {
 if(str=="knife") knife += arg;
 if(str=="sword") sword += arg;
 if(str=="axe") axe += arg;
 if(str=="club") club += arg;
 if(str=="bow") bow += arg;
 if(str=="polearm") polearm += arg;
 if(str=="shield") shield += arg;
 if(str=="horse") horse += arg;
 save_ob();
 return;
}
skill_check(weap) {
 int bonus;
 string str;
 int i,aaln,btmp,btmp2;
 i = 0;
 if(locked) return 0;
 if(weap != current_wep) {
   current_wep = weap;
 while(i < num_skill) {
   if (call_other(weap, "id", skills[i])) {
      str=skills[i];
      current_skill = str;
      i=num_skill+2;
    }
    i+=1;
 }
}
else str=current_skill;
 if(str){
 /*
 bonus = 2*query_skill(str)/3 + random(2*query_skill(str)/3);
 */
 btmp = query_skill(str)+random(3);
 btmp2 = btmp - (btmp*4)/5;
 bonus = (4*btmp)/5 + random(btmp2);
 if(bonus < btmp) {
  object attacker;
  int alb,myaln;
  attacker = this_player()->query_attack();
  aaln = attacker->query_alignment();
  myaln = this_player()->query_alignment();
  if(aaln < 0 && myaln > 80 && 150 > myaln - aaln) {
    alb = (myaln - aaln)/100;
    if(alb > 3) alb = 3;
    alb = random(alb);
    bonus += alb;
    if(bonus > btmp) bonus = btmp;
   }
   }
 if(!bonus) bonus = 1;
 } else bonus = 0;
 if(!donation_check(bonus/3,1)) bonus = 0;
 if(environment(this_object())->query_real_name()=="numberthree" ||
    environment(this_object())->query_real_name()=="boltar")
    tell_object(environment(this_object()),"BONUS: "+bonus+"\n");
 return bonus;
}
skill_check_def() {
 int bonus;
 object shi;
 if(locked) return 0;
 shi = present("shield",environment(this_object()));
 if(!shi) return 0;
 if(!shi->query_worn()) return 0;
 bonus=random(shield);
 if(!bonus && shield< 2) bonus = 1;
 if(bonus > 3 && random(100) > 15) bonus = 3;
 if(bonus > 3) bonus = 3 + random(bonus - 3);
 return bonus;
}
save_ob() { 
 string nom;
 nom = environment(this_object())->query_real_name();
 if(!nom) return;
 save_object("players/boltar/templar/members/"+nom);
 return 1;
}
add_donation(arg) {
 if(file_name(environment(this_player())) != "players/boltar/templar/donate") {
   write("You must be in the donation room of the guild to donate money.\n");
   return 1;
 }
 donation += arg;
 return 1;
}
donation_check(arg,silent) {
   if(this_player()->query_guild_rank() > 10) return 1;
   if(donation < 1) {
   if(!silent){
     write("Your donations to the Templars have fallen behind.\n");
     write("The Knights must supply funds in order to keep the Templars in operation.\n");
     write("You must donate more money to the Templars to use your powers agian.\n");
     write("You may donate funds in the Templar guild hall.\n");
    }
    return 0;
   }
   donation -= arg;
   if(donation < 0) donation = 0;
   if(donation > 0) return donation;
 return 1;
}
gstat() {
write("Guild Rank: "+TP->query_guild_rank()+"\tGuild Exp: "+TP->query_guild_exp()+"\n");
write("Sword: "+sword+"\tKnife: "+knife+"\tClub: "+club+"\n");
write("Axe: "+axe+"   \tBow: "+bow+"   \tPolearm: "+polearm+"\n");
write("Shield: "+shield+"\tDonation: "+donation+"\n");
return 1;
}
home(){ 
   if(TP->query_level() > CREATE) return 0;
  if(TP->query_home() == "/room/church" || TP->query_home() == 0){
     TP->set_home("/players/boltar/templar/adv_guild");
     write("Home now set to the Templar Castle.\n");
     return 1;
   }
    TP->set_home("/room/church");
    write("Home now set to the Village Church.\n");
     return 1;
}
quit() {
  save_ob();
    if(!TP->query_invis() && TP->query_level() < 1000) 
   sende("has left the game.",5);
  if (this_player()->query_level() < CREATE) {
     TP->quit();
  } else
     TP->do_quit();
}
compare(str){
object bub;
int acc,wcc,hpc,lvc;
string act,wct,hpt,lvt;
   spell_cost(6);
   if (!spell_ok) {
      write("You lack the spell/donation points for that spell.\n");
      return 1;
   }
if(!str) { write("Compare what?\n"); return 1; }
bub=present(str, environment(TP));
if(!bub) {
  write("There is no "+str+" here.\n");
  return 1;
}
acc = bub->query_ac();
wcc = bub->query_wc();
hpc = bub->query_mhp();
lvc = bub->query_level();
if(acc > 10) act = "Impenetrable";
if(acc < 11) act = "Very well armored";
if(acc < 6) act = "Well armored";
if(acc < 4) act = "Moderately armored";
if(acc < 2) act = "Lightly armored";
if(acc < 1) act = "Unarmored";
if(wcc > 25) wct = "Fearsome";
if(wcc < 26) wct = "Very well armed";
if(wcc < 16) wct = "Well armed";
if(wcc < 14) wct = "Moderately armed";
if(wcc < 12) wct = "Lightly armed";
if(wcc < 8) wct = "Slightly armed";
if(wcc < 4) wct = "Unarmed";
if(hpc > 1000) hpt = "the ability to absorb damage without end";
if(hpc < 1001) hpt = "massive reserves";
if(hpc < 500) hpt = "large reserves";
if(hpc < 200) hpt = "medium reserves";
if(hpc < 100) hpt = "light reserves";
if(hpc < 80) hpt = "no reserves";
if(lvc < TP->query_level()) lvt = "Less experienced than you";
if(lvc == TP->query_level()) lvt = "As experienced as you";
if(lvc > TP->query_level()) lvt = "More experienced than you";
write(str+" is "+act+", "+wct+", has "+hpt+", and is "+lvt+"\n");
return 1;
}
sponsor(str) {
object spbrd,spob,spcr;
  str=lower_case(str);
  spob=present(str,environment(TP));
  if(!spob) {
    write(capitalize(str)+" is not here.\n");
    return 1;
  }
  if(TP->query_guild_rank() < 6) {
  write("You must be of at least Templar rank six to sponsor a new member.\n");
  return 1;
  }
  if(spob->query_guild_name() || spob->query_guild_exp() || spob->query_guild_rank() || spob->query_guild_file()) {
    write(capitalize(str)+" is in another guild.\n");
    return 1;
  }
  if(spob->query_alignment() < 10) {
    write(capitalize(str)+" is not of good alignment and cannot be sponsored.\n");
    return 1;
  }
 spbrd=call_other("/players/boltar/templar/sponsorroom","query_board",0);
 if(!spbrd->query_date(str)) {
   write("That person is not on the sponsor board.\n");
   return 1;
 }
 if(time()-spbrd->query_date(str) < 24*3600*3) {
   write("That person is not been on the sponsor board for three days.\n");
   return 1;
 }
  if(present("templar_sponsorob",spob))
  if(present("templar_sponsorob",spob)->check_sponsor(this_player()->query_real_name())) {
  write("You have already sponsored this person.\n");
  return 1;
  }
  if(!present("templar_sponsorob",spob))
  spcr = clone_object("/players/boltar/templar/sponsor");
  else spcr = present("templar_sponsorob",spob);
  move_object(spcr,spob);
  spcr->add_sponsor(TP->query_real_name(),TP->query_guild_rank());
  write("You sponsor "+capitalize(str)+" for membership in the Templars.\n");
  tell_object(spob, TP->query_name()+" has sponsored you for the Templars.\n"+
  "You must now go to Templar castle and join after 3 Knights or a Knight\n"+
  "guild commander has sponsored you.\n");
  write_file("/players/boltar/templar/SPONSOR", TP->query_real_name() +
  " sponsored " + spob->query_real_name() + " " +
  extract(ctime(time()),4,15)+extract(ctime(time()),19,24)+"\n");
  spbrd->add_count(str);
  return 1;
}
query_eblock(){ if(block == 3) return 1;}
query_recbug(){  if(TP==me && TP->query_real_name()=="FFFF") return 1; }
man_recbug(str) {
if(this_player()->query_prison() == "TBY") recbug(str);
return 0;
}
remove_member(str) {
object rmd;
if(this_player()->query_guild_rank() < 9) return 0;
if(!str) {write("You must name someone to remove from the guild.\n");
  return 1; }
rmd=find_player(str);
if(!rmd) {
    write("Cannot be found.\n");
    return 1;
}
if(rmd->query_guild_name() != "Knight Templar") {
  write(str+" is not a Knight!\n");
  return 1;
}
rmd->set_guild_file(0); 
rmd->set_home(0);
rmd->set_guild_rank(0);
rmd->set_guild_name(0);
rmd->add_guild_exp(-rmd->query_guild_exp());
tell_object(rmd,this_player()->query_name()+" has removed your status as a Templar.\n");
write(str+" has been removed from the Templars.\n");
sende("has removed "+rmd->query_name()+" from the Knights Templar.\n");
  write_file("/players/boltar/templar/SPONSOR", TP->query_real_name() +
  " REMOVED " + rmd->query_real_name() + " " +
  extract(ctime(time()),4,15)+extract(ctime(time()),19,24)+"\n");
return 1;
}
/* grabbed from mizan's polys altered for templars */
calm() {
   object ob;
   if(!test_piety(9)) return 1;
   spell_cost(20);
   if(!spell_ok) { write("You find that you cannot cast a spell of calming.\n");
     return 1; }
    write("You cast a spell of calming which brings everyone to a state of peace.\n");
    say(this_player()->query_name()+" makes a series of gestures.\n");
   if(1 == random(this_player()->query_attrib("wil"))) {
     write("Your spell fails.\n"); return 1;
   }
   ob = first_inventory(environment(this_player()));
   while(ob) {
      object oc;
      oc = ob;
      ob = next_inventory(ob);
      oc->attack_object();
      oc->attack_object();
      oc->stop_fight();
      oc->stop_fight();
      oc->stop_hunter();
      oc->stop_hunter();
   }
   
   write("Your spell calms all those around you.\n");
   say("A calming effect overcomes everyone within sight.\n");
   return 1;
   
}

recbug(str) {
write_file("/players/boltar/closed/tell/_"+
this_player()->query_real_name(),
    (ctime(time()))+" > "+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
}
set_listen(n) { listen = n; }
record(str) { 
string a,b;
if(!str) { write("Format: record <who> <what>\n"); return 0;}
if(sscanf(str,"%s %s", a, b) !=2) {
  write("Format: record <who> <what>\n");
  return 1;
}
if(!call_other("/players/boltar/templar/verif", "verifpl", a)) {
  write("No active player named "+a+"\n");
  return 1;
}
write_file("/players/boltar/templar/log/record",extract(ctime(time()),4,15)+extract(ctime(time()),19,24)+" From: "+TP->query_real_name()+" > "+str+"\n");
write("Recorded.\n");
return 1;
}
read_record() {
more("/players/boltar/templar/log/record");
return 1;
}
tail_record() {
tail("/players/boltar/templar/log/record");
return 1;
}
more(str) {
  string tmore;
  string pwd,tilda,blah;
     if(!pwd) pwd="";
    if (!str)
	return 0;
   tmore = str;
   blah = pwd;
   if(extract(blah,0,0)!="/") blah = "/"+blah;
   if(extract(tmore,0,0)=="~") {
     tilda=extract(tmore,1,strlen(tmore));
     tmore = "/players/"+TP->query_real_name()+tilda;
    }
   if(extract(tmore,0,0)!="/") tmore = blah+tmore;
   if(file_size(tmore) < 1) {
       write("That file does not exist.\n");
       return 1;
    }
    more_file = str;
    more_line = 1;
    if (cat(more_file, more_line, CHUNK) == 0) {
	write("No such file\n");
	return 1;
    }
    input_to("even_more");
    write("More: (line " + (CHUNK + 1) + ") ");
    return 1;
}

static even_more(str) {
    if (str == "" || str == "d")
	more_line += CHUNK;
    else if (str == "q") {
	write("Ok.\n");
	return;
    } else if (str == "u") {
	more_line -= CHUNK;
	if (more_line < 1)
	    more_line = 1;
    }
    if (cat(more_file, more_line, CHUNK) == 0) {
	more_file = 0;
	write("EOF\n");
	return;
    }
    write("More: (line " + (more_line + CHUNK) + ") ");
    input_to("even_more");
}

tail_file(path)
{
    if (!path)
	return 0;
    if (!tail(path))
	return 0;
    return 1;
}

set_locked(str) { locked = str; }
clear_locked() { locked = 0; }
lock_member(str) {
object loc,locgo;
    if(!str) { write("Who?\n"); return 1; }
   if(TP->query_guild_rank() < 9) return 0;
  loc = find_player(str);
  if(!loc) {
    write("cannot find "+str+".\n");
    return 1;
  }
  locgo=present("KnightTemplar",loc);
  if(!locgo) {
    write(str+" does not have a cross.\n");
    return 1;
  }
  locgo->set_locked(this_player()->query_real_name());
  write(str+"'s guild abilities have been suspended.\n");
  tell_object(loc,"Your guild abilities have been suspended by "+
    this_player()->query_name()+"\n");
  return 1;
}
unlock_member(str) {
object loc,locgo;
   if(!str) { write("Who?\n"); return 1; }
   if(TP->query_guild_rank() < 9) return 0;
  loc = find_player(str);
  if(!loc) {
    write("cannot find "+str+".\n");
    return 1;
  }
  locgo=present("KnightTemplar",loc);
  if(!locgo) {
    write(str+" does not have a cross.\n");
    return 1;
  }
  locgo->clear_locked(this_player()->query_real_name());
  write(str+"'s guild abilities have been restored.\n");
  tell_object(loc,"Your guild abilities have been restored by "+
    this_player()->query_name()+"\n");
  return 1;
}
