inherit "/obj/monster";

#define MAXSPELL 10
#define MAXCHAT 10


int p_kill,aggressive,percept;
object kill_ob;
int chat_chance;
string chat;
int chat_att_chance;
string chat_att;
int spell_chanced, spell_damd;
string spell_telld, spell_messd;
object me,dead_ob;
static int mchat,mchatat,mspt,doo;

reset(arg)
{
  ::reset(arg);
    if (arg) return;
    can_kill = 0;
    is_npc = 1;
    p_kill = 1; 
    percept = 50;
    aggressive = 0;
    enable_commands();
    me = this_object();
message_hit=({"massacre"," to small fragments","smashed",
" with a bone crushing sound","hit"," very hard","hit",
" hard","hit","","grazed","","tickled"," in the stomach"});
  spell_chanced = allocate(MAXSPELL);
  spell_damd = allocate(MAXSPELL);
  spell_telld = allocate(MAXSPELL);
  spell_messd = allocate(MAXSPELL);
  chat = allocate(MAXCHAT);
  chat_att = allocate(MAXCHAT);
  mchat = mchatat = mspt = doo = 0;
}



heart_beat()
{
    int c;
     int mm;
    ::heart_beat();
    if(!doo) { setup(); doo = 1; }

    already_fight = 0;
    /* If there is none here test_if_any_here will turn of heat_beat  */

    if (attacker_ob && present(attacker_ob, environment(this_object()))) {
     spell_attack(attacker_ob); 
    }
    if(alt_attacker_ob && present(alt_attacker_ob,environment(this_object()))) {
        if(attacker_ob != alt_attacker_ob) spell_attack(alt_attacker_ob); 
      }
    attack();
    chats();
}


/*
 * Now some functions for setting up spells !
 */
/*
 * The percent chance of casting a spell.
 */

setup() { 
int n;
          for(n=0;n<MAXCHAT;n++) if(chat[n]) mchat = mchat + 1;
          for(n=0;n<MAXCHAT;n++) if(chat_att[n]) mchatat = mchatat + 1;
          for(n=0;n<MAXSPELL;n++) if(spell_chanced[n]) mspt = mspt + 1;
         } 

set_chance(int c,int cc) {
int ccc;  if(!cc) ccc = 0; else ccc = cc;
    spell_chanced[ccc] = c;
}
/* Message to the victim. */

set_spell_tell(string m,int mm) {
int mmm;  if(!mm) mmm = 0; else mmm = mm;
    spell_telld[mmm] = m;
}
set_spell_mess(string m,int mm) {
int mmm;  if(!mm) mmm = 0; else mmm = mm;
    spell_messd[mm] = m;
}
set_spell_dam(int d,int dd) {
int ddd;  if(!dd) ddd = 0; else ddd = dd;
    spell_damd[dd] = d;
}

spell_attack(object ob) {
int k;
    if(mspt) {
    for(k=0;k<mspt;k++) {
    if(spell_chanced[k] > random(100)) {
    if(spell_telld[k]) tell_object(ob,spell_telld[k]+"\n");
    if(spell_messd[k]) say(spell_messd[k]+"\n",ob);
    if(spell_damd[k]) ob->hit_player(spell_damd[k]); } } }
	}


/* Load chat */

set_chat_chance(c) {
    chat_chance = c;
}

/* Load attack chat */

set_chat_att_chance(c) {
    chat_att_chance = c;
}

set_chat_mess(string c,int cc) {
int ccc;  if(!cc) ccc = 0; else ccc = cc;
  chat[ccc] = c;
}

set_chat_att_mess(string c,int cc) {
int ccc;  if(!cc) ccc = 0; else ccc = cc;
  chat_att[ccc] = c;
}

chats() {
    if(attacker_ob) {
    if(mchatat) {
    if(chat_att_chance > random(100)) {
    tell_room(environment(this_object()),chat_att[random(mchatat)]); } }
	} else {
    if(mchat) {
    if(chat_chance > random(100)) {
    tell_room(environment(this_object()),chat[random(mchat)]); } } }
}

set_aggressive(n) { aggressive = n; }
set_perception(n) { percept = n; }

init() {
int ste;
  ::init();
    if(this_player() == me) return;
    if (attacker_ob) {
	set_heart_beat(1); /* Turn on heart beat */
    }
    if(this_player() && !call_other(this_player(),"query_npc")) {
	set_heart_beat(1);
    }
    if (aggressive > random(100)) {
     ste = call_other(this_player(), "query_attrib", "ste");
     if (ste < random(percept)) kill_ob = this_player();
   }
}

