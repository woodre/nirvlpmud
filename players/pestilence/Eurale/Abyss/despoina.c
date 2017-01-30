/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */
#include "/players/eurale/defs.h"
inherit "obj/monster.c";
inherit "/obj/user/one_chan.c";
object player;

object gold;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("despoina");
  set_alias("despoina");
  set_race("diva");
set_short(BOLD+"Despoina, the Abyss Diva"+NORM);
set_long(
  "  You struggle with the overwhelming fear that has you in its grip\n"+
  "as you look upon Despoina, the Abyss Diva.  She has the ability\n"+
  "to appear in various forms, each one an appealing apparition to\n"+
  "seduce and kill her intended victim.  The beautiful woman you see\n"+
  "before you makes you LUST for her.  Her beckoning, outstretched\n"+
  "arms invite you to come to her.  Her thin lips curve upward on the\n"+
  "ends forming a wicked looking smirk.  And the whole while you begin\n"+
  "to feel weaker and less able to control your thoughts.  She knows\n"+
  "you've come to kill her and she intends to keep that from happening!\n");
set_hp(2400 + random (300));
set_level(30);
set_al(-1000);
add_money(35000 + random(10000));

if(!present("mace")) {
  move_object(clone_object("players/eurale/Abyss/OBJ/mace"),TO); }
init_command("wield mace");
set_wc(78);
/*
set_wc_bonus(22);
*/
set_ac(29);
set_ac_bonus(14);
set_heal(15,5);
set_aggressive(0);
set_gender("female");
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("Despoina hisses, 'Welcome to the Abyss.. MY Abyss!\n");
  load_chat("The Diva beckons you with outstretched arms...\n");
  load_chat("You are gripped by overwhelming FEAR!\n");
set_a_chat_chance(10);
  load_a_chat("Despoina howls like a banshee....\n");
  load_a_chat("You feel INTENSE PAIN as her mace hits its mark!\n");
  load_a_chat("MUHAHAHAHA...screams the Diva.\n");
  load_a_chat("Despoina easily avoids your attack...\n");

/*
set_chance(14);
set_spell_dam(70 + random(25));
set_spell_mess1(
	BOLD+"\n           Despoina mumbles some arcane words....\n"+
	"           Black turbulance begins to bubble....\n"+
	"           You feel the air being sucked out of you...\n"+
	"           You feel the air being sucked out of the room..\n"+
	"           You clutch your BURNING chest!!"+NORM+"\n\n");

set_spell_mess2(
	BOLD+"\n          Despoina mumbles some arcane words....\n"+
	"          Black turbulance begins to bubble...\n"+
	"          You feel the air being sucked out of you...\n"+
	"          You CLUTCH your BURNING chest!!!"+NORM+"\n\n");
*/


add_spell("arcane",
        BOLD+"\n          Despoina mumbles some arcane words....\n"+
        "          Black turbulance begins to bubble...\n"+
        "          You feel the air being sucked out of you...\n"+
        "          You CLUTCH your BURNING chest!!!"+NORM+"\n\n",
        BOLD+"\n           Despoina mumbles some arcane words....\n"+
        "           Black turbulance begins to bubble....\n"+
        "           You feel the air being sucked out of you...\n"+
        "           You feel the air being sucked out of the room..\n"+
        "           You clutch your BURNING chest!!"+NORM+"\n\n",
14,"70-95","other|magic",0);

add_spell("drain",
"#MN# starts to chant!\n",
"#MN# starts to chant\n",
25,"20-60","other|magic",0,"drain_heal");


add_spell("charm",
"\n\n\n\n\n\n\n#MN# puts a charm on you!\nYou have an urge to attack yourself!\n",
"#MN# puts a charm on #TN#\n",
25,"5-40",0,0,"self_attack");

/* used add_money and updated with new level
gold = clone_object("obj/money");
gold->set_money(random(500)+3500);
move_object(gold,this_object());
*/
}

init() {
  ::init();
  add_action("No_insanity","insanity");
}

No_insanity() {
  write("Despoina CACKLES LOUDLY and grins at you....\n");
  return 1; }

monster_died() {
object ob;
  ob = present("quest_holy_avenger",attacker_ob);
if(attacker_ob->query_weapon() && attacker_ob->query_weapon() == ob) {
  write("\n");
  write("The Diva screams in agony as the Holy Avenger takes her\n"+
	"life... as she crumbles to the floor she mutters, 'You\n"+
	"have done well and earned the quest points you deserve for\n"+
   "relieving me of my life with the Holy Avenger.. Quest Completed!\n\n");
  write_file("/players/eurale/Abyss/LOG/abyss",
  attacker_ob->query_real_name()+"    "+ctime(time())+"   Abyss Quest Credit\n");
  attacker_ob->set_quest("despoina");
  if(!present("abyss_mark",attacker_ob)) {
    move_object(clone_object("players/eurale/Abyss/OBJ/mark"),attacker_ob); }
chan_msg(
  "\nFrom deep in the bowels of Nirvana comes a guttural SCREAM..\n"+
  "and then silence as "+BOLD+"Despoina, Diva of the Abyss,"+NORM+
  " dies by\n"+
  "the blade of "+capitalize(query_attack()->query_real_name()+
  "\n\n"),"msg");
    }
else {
  write("\n\nThe Diva screams in a agony as the her life is ended!\n\n");
  if(!present("abyss_mark",this_player())) {
    move_object(clone_object("players/eurale/Abyss/OBJ/mark"),TP); }
chan_msg(
  "\nFrom deep in the bowels of Nirvana comes a guttural SCREAM...\n"+
  "and then silence as "+BOLD+"Despoina, Diva of the Abyss,"+NORM+
  " dies by the\n"+
  "hand of "+capitalize(query_attack()->query_real_name()+
  ".\n\n"),"msg");
  write_file("/players/eurale/Abyss/LOG/abyss",
  TP->query_real_name()+"     "+ctime(time())+"     Despoina\n");
  }
return 0; }

heart_beat() {
  ::heart_beat();
if(!environment()) return;
if(TO->query_wc() < 78) set_wc(78);
if(TO->query_ac() < 29) set_ac(29);
if(present("darkness",environment(TO))) {
  call_out("no_dark",1);
  return 1; }
if(present("freeze.c",TO)) {
  call_out("no_fear",1);
  return 1; }
  if(query_attack()) {
if(present("cycle",query_attack())) {
  call_out("no_sym_fear",1);
  return 1; }
if(present("reverse",query_attack())) {
  call_out("no_reverse",1);
  return 1; }
}
}

drain_heal( object target, object room, int damage ) {
string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say(HIY+"Despoina steals "+ATT_NAME+"'s life, making it her own!\n"+NORM);
       tell_object(attacker_ob,
HIY+"Despoina steals your life, making it her own!\n"+NORM);
heal_self(20+random(15));
}

self_attack( object target, object room, int damage ) {
  int wep;
  int dam_amt;
  string pname;
  string *amess;

  if( !target || !environment() )
    return;

  wep = target->query_name_of_weapon();
  pname = target->query_name();
  dam_amt = 15 + random (20);
  if( !wep ) {
  tell_room(environment(),
    pname+" massacres "+pname+" into tiny fragments.\n");
  return 1;
  }
  else {
   amess =  wep->query_message_hit( dam_amt );
   tell_room(environment(), pname+" "+amess[1]+" "+pname+amess[0]+".\n");
  return 1;
  }
}
self_attack_old( object target, object room, int damage ) {
int wep;
int dam_amt;
string amess;
amess =  wep->query_message_hit( dam_amt );
dam_amt = 15 + random (20);
wep = target->query_name_of_weapon();
if( !wep ) { 
tell_room(environment(),
  target->query_name()+" massacres "+target->query_name()+" into tiny fragments.\n");
return 1;
}
else {
 tell_room(environment(),amess+"\n");
return 1;
}
}

no_dark() {
object dob;
dob = present("darkness",environment(TO));
tell_room(environment(this_object()),
  "\nDespoina cackles and a "+HIY+"BOLT OF LIGHTING"+NORM+
  " springs from her fingers\n"+
  HIY+"LIGHTING"+NORM+" the darkness.....\n\n");
  destruct(dob);
return 1; }

no_fear() {
object nof;
nof = present("freeze.c",TO);
tell_room(environment(this_object()),
  "Despoina scoffs at your attempt to make her "+BOLD+"FEAR ANYTHING"+
  NORM+".\n");
  destruct(nof);
return 1; }

no_sym_fear() {
object nsf;
nsf = present("cycle",query_attack());
tell_room(environment(this_object()),
  "\n"+BOLD+"M U H A H A H A"+NORM+"..... chortles the Diva\n"+
  "She laughs, 'You think your PUNY mortal spells will have any\n"+
  "effect on one with MY POWERS?'\n\n");
  destruct(nsf);
return 1; }

no_reverse() {
object nrv;
nrv = present("reverse",query_attack());
tell_room(environment(this_object()),
  "Despoina looks down and with a "+HIC+"FLASH OF BLUE"+NORM+
  "\n     she SEVERS the thin black line between you and her!\n");
  destruct(nrv);
return 1; }
