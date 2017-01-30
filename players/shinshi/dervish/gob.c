#include <ansi.h>
#include "defs.h"


string title;
int ingame;
int spell_delay, beats, sand_points;
int sand_transfer;
int attack_spell;
status bravery, brave;
object offwep, firstwep;
int spell_attacks;

/* EXPERIENCE VARIABLES */
int guild_exp, guild_level, dual_exp, mystic_exp, mystic_percent;

/* SKILL VARIABLES */
int parry, offparry, skill_pt, skill_pts;

id(str){
	return str == "dervish_tattoo" || str == "tattoo" || str == "generic_wc_bonus" || str == "pro_object" || str == "GI"; }
	
short() { return RED+BOLD+"Dervish Tattoo"+OFF+OFF; }

long() { write(RED+BOLD+"A coiling whirlwind.\n\n"+OFF+OFF+
						"To know your powers, "+BOLD+"dervish"+OFF+"\n"); return 1; }

get() {
   return 1;
}

drop() {
   return 1;
}

reset(arg){
	if(arg) return;
	set_heart_beat(1);
	call_out("dervish_resett", 1800);
}

init() {
	int c;
	string *spells, cmd;
	
	if(!environment()) return;
	restore_object(PFILE+"/"+environment(this_object())->query_real_name());
	if(environment(this_object())->query_level() < 100){
          environment(this_object())->set_guild_name("dervish");
          environment(this_object())->set_guild_file(basename(this_object()));
	}
	
	
   /** CHATOB->resetchannel(); **/
   
   	
   setup(environment(this_object()));
   c = sizeof(spells = get_dir(GUILDSPELL+"/"+"*.c"));
   while(c--)
   {
	   sscanf(spells[c], "%s.c", cmd);
	   add_action("cmd_hook", cmd);
   }
   
   add_action("sand_missile","mi");
   add_action("sand_missile","missile"); 
   add_action("sand_shock","sh");
   add_action("sand_shock","shock"); 
   add_action("sand_fireball","fi");
   add_action("sand_fireball","fireball"); 
   add_action("sand_sonic","so");
   add_action("sand_sonic","sonic");
   add_action("no_go", "wimpy");
   add_action("quit", "quit");
}

mixed cmd_hook(string str)
{
	string go;
	
	go = GUILDSPELL+"/"+query_verb()+".c";
	
	if(file_size(go) > 0)
		return (mixed) go->main(str, this_object(), this_player());
		return 0;
}
	
quit()
{
	save_me();
	logoutmsg();
	this_player()->do_quit();
	return 1;
}

guild_login() {
  loginmsg();
  if( environment() && environment()->query_whimpy() )
    environment()->set_whimpy( 0 );
}

loginmsg()
{
	string mess, mess2, entermess;
	
	mess = BOLD+"*"+RED+"DERVISH"+OFF+BOLD+"*";
	mess2 = environment()->query_name()+" enters the game.";
	
	entermess = mess+" "+mess2+" "+mess+OFF+"\n";
	
	if(environment()->query_level() < 20) {
	  /** CHATOB->send_msg(entermess); **/
    CHAND->transmit_message( CHAN_NAME, entermess);
  }
}

logoutmsg()
{
	object me;
	string mess, mess2, leavemess;
	
	me = environment();
	
	if(!me) return;
	
	mess = BOLD+"*"+RED+"DERVISH"+OFF+BOLD+"*";
	mess2 = me->query_name()+" leaves the game.";
	leavemess = mess+" "+mess2+" "+mess+OFF+"\n";
	
	if(me->query_level() < 20) {
	  /** CHATOB->send_msg(leavemess); **/
    CHAND->transmit_message( CHAN_NAME, leavemess );
    CHAND->remove_channel( CHAN_NAME, me );
  }
}
	
no_go()
{
	write("You cannot do that.\n");
	return 1;
}

gen_wc_bonus(){
  int xl, sandp, amt;
  object weapon, me;
  string weaponname, color;
  object *weps;
  mapping weapons;

  xl = (int)this_player()->query_extra_level();
  sandp = (int)this_object()->query_sand_points();
  amt = (xl / 10 + (sandp > random(100000) ? 5 : 0));
  sandp /= 1000;
  if( sandp > random(500 + sandp*4 ) ) {
    me = environment();
    if( !me )
      return 0;
    switch( amt ) {
      case 13..1000:
        color = BOLD+RED;
        break;
      case 8..12:
        color = RED;
        break;
      case 5..7:
        color = BOLD+WHITE;
        break;
      default:
        color = WHITE;
        break;
    }
    weapons = me->QueryWeapons();
    if( !weapons )
      return amt;

    weps = keys( me->QueryWeapons() );
    if( !sizeof(weps) )
      return amt;
    weapon = weps[ random(sizeof(weps)) ];
    weaponname = capitalize(weapon->query_name());
    switch( random(amt)+1 ) {
      case 1..3:
        TE(me, color+"You feel at one with the Sands.\n"+OFF);
        tell_room( environment(me), color+me->query_name()+" is at one with the Sands.\n"+OFF, ({me}) );
        break;
      case 4..6:
        TE(me, color+"The Sands bless your "+weaponname+".\n"+OFF);
        tell_room( environment(me), color+"The Sands bless "+me->query_name()+"'s "+weaponname+".\n"+OFF, ({me}) );
        break;
      case 7..9:
        TE(me, color+"The Sands swirl in the ecstasy of Death.\n"+OFF);
        tell_room( environment(me), color+"The Sands swirl around "+me->query_name()+" in the ecstasy of Death.\n"+OFF, ({me}) );
        break;
      case 10:
        TE(me, color+"Chaotic forces burn inside you.\n"+OFF);
        tell_room( environment(me), color+"Chaotic forces burn inside "+me->query_name()+".\n"+OFF, ({me}) );
        break;
      case 11:
        amt += 1;
        TE(me, color+"Your "+weaponname+OFF+color+" twirls with the force of the Sands.\n"+OFF);
        tell_room( environment(me), color+me->query_name()+"'s "+weaponname+OFF+color+" twirls with the force of the Sands.\n"+OFF, ({me}) );
        break;
      case 12:
        amt += 2;
        TE(me, color+"Your "+weaponname+OFF+color+" glows with the power of the Sands.\n"+OFF);
        tell_room( environment(me), color+me->query_name()+"'s "+weaponname+OFF+color+" glows with the power of the Sands.\n"+OFF, ({me}) );
        break;
      case 13:
        if( sizeof(weps) > 1 ) {
          amt += 3;
          TE(me, color+"Your weapons spin in twin dances of Death.\n"+OFF);
          tell_room( environment(me), color+me->query_name()+"'s weapons spin in twin dances of Death.\n"+OFF, ({me}) );
        }
        else
          amt -= 5;
        break;
      case 14:
        amt += 4;
        TE(me, color+"Your "+weaponname+OFF+color+" merges in the chaos of Sand.\n"+OFF);
        tell_room( environment(me), color+me->query_name()+"'s "+weaponname+OFF+color+" merges in the chaos of Sand.\n"+OFF, ({me}) );
        break;
      default:
        amt += 5;
        TE(me, color+"You twirl your "+weaponname+OFF+color+" with deadly skill.\n"+OFF);
        tell_room( environment(me), color+me->query_name()+" twirls "+me->query_possessive()+ " "+weaponname+" with deadly skill.\n"+OFF, ({me}) );
        break;
    }
  }
  
  return amt;
}

heart_beat(){
	object me, myenv, ob;
	me = environment();
	if(!me || !me->is_player()) return;
	myenv = environment(me);
	if(!myenv) return;
	ob = present(GID, me);
	if(me->query_attack() && !brave) test_attack();
	if(me->query_level() < 20) test_stats();
	
	if(sand_transfer && myenv->query_sandstorm()) sand_transference(me);
	if(spell_delay < 0) spell_delay = 2;
	if(spell_delay)
	{
		spell_delay--;

                if( me->query_prestige_level() ) {
		  spell_delay--;
                }

		if(present("go_go", me) )
		{
                  spell_delay -= 2;
		}

                if(spell_delay < 0) 
                  spell_delay = 0;

		if(!spell_delay) TE(me,
			BOLD+RED+"\n\tThe power of the Sands is again within you.\n\n"+OFF);
	}
	beats++;
   if(!myenv->query_sandstorm() && !present(SANDSTORM, myenv) ) check_sand();
	check_spatt();
	return 1;
}

test_attack() {
	object me, it;
	string *mess;
	int damage;
	me = environment();
	it = environment()->query_attack();
	if(!me || !it) return;
	if(!environment(me)) return;
	if(!present(it, environment(me))) return;
	if(me->query_ghost()) return 1;
	if(!it->query_attack()) { it->attack_object(me); return 1; }
	if(it->query_attack() != me) {
		if(present("dervish_tattoo", it->query_attack())) {
		damage = me->hit_player(random(it->query_wc()));
		if(!damage) return 1;
		mess = it->query_message_hit(damage);
		TE(me, "You step into "+it->query_name()+"'s attack.\n");
		tell_room(environment(me),
			it->query_name()+" "+mess[1]+" "+me->query_name()+mess[0]+"\n");
			return 1; }
		tell_object(me, "You must lead the fight!\n");
		tell_object(environment(me),me->query_name()+
			" leaps forward to lead the fight!\n");
		if(it->query_hp() >= (it->query_mhp() / 10)) it->attack_object(me);
		return 1;
		}
	return 1;
}

test_stats() {

/* Due to the raising of stats to 30 instead of 20
   I raised the current possible max str from 15 to
   20, and the max sta from 15 to 18.
   -Jaraxle [11/11/02] */

/* Changed so max sta is 20 and limited mag to 25
   [12-3-03]  Fred  */

  object me;
  int mystr, mysta, mymag;
  me = environment();
  if(!me) return;
  mymag = me->query_attrib("mag");
  mystr = me->query_attrib("str");
  mysta = me->query_attrib("sta");
  if(mystr > 20) {
    TE(me, BOLD+RED+"\nThe Sands take away your excess physical strength.\n"+OFF+OFF);
  me->set_attrib("str",20);
    me->save();
    me->reset(); }
  if(mysta > (14 + (int)me->query_total_level() / 10)) {
    TE(me, BOLD+RED+"\nThe Sands take away your excess endurance.\n"+OFF+OFF);
   me->set_attrib("sta", 14 + ((int)me->query_total_level() / 10));
    me->save();
    me->reset(); }
  if(mymag > 25) {
    TE(me, BOLD+RED+"\nThe Sands take away your excess magical powers.\n"+OFF+OFF);
  me->set_attrib("mag",25);
    me->save();
    me->reset(); }
  return 1; }
  
sand_transference(ob) {
  int myhp, mysp;
  myhp = ob->query_hp();
  mysp = ob->query_sp();
  if(mysp < 1) return;
  if(myhp == ob->query_mhp()) return;
  ob->add_spell_point(-1);
  if(random(3)) ob->add_hit_point(1);
  return 1; }

check_sand() {
  object me;
  me = environment();
  if(!me || !me->is_player() || me->query_level() > 19) return;
  if(!me->query_interactive() || !environment(me)) return;
  if(me->query_ghost()) return 1;
  if(me->query_level() > 18 && sand_points > 10000) {
    if(!bravery) {
    toggle_bravery();
    tell_object(me,BOLD+"\n\tYour bravery has been rewarded!\n\n"+
         "\tLEAD is at your command!\n\n"+OFF);
         brave = 1;
    sand_points -= 9900;
    save_me();
    dervish_reset();
    }
  }
  if(sand_points < 1) {
    tell_object(me, "The sand takes your blood as its sacrifice.\n");
    me->add_hit_point(-10);
    sand_points += (21 - me->query_level())*10;
    if(me->query_hp() < 1) kill_me(me);
    return 1; }
  sand_points --;
  return 1; }

check_spatt() {
  if(spell_attacks > 3) {
  sand_points -= 100; }
  spell_attacks = 0;
  return 1; }

kill_me(ob) {
  object sand;
  sand=clone_object(GUILDPATH+"/objects/sands");
  TE(ob, BOLD+RED+"\n\n\tTHE SAND TAKES YOUR LIFE!\n\n"+OFF+OFF);
  sand_points += ob->query_level()*25;
/*
  sand->zap_object(ob); return 1; }
*/
  move_object(sand, environment(ob));
  ob->attacked_by(sand);
  ob->hit_player(100000, "other|snow");
  sand->emit_chan(ob);
  destruct(sand);
  return 1;
}

check_skills(){
 object me, myob;
 int amt, skills;
  me = this_player();
  myob = present(GID, me);
  amt = myob->query_mystic_exp();
  skills = myob->query_skill_pts();
  if((amt - (amt/skills)) > 150000){
    write("\n"+BOLD+RED+"The sands reward your for your dedication with a skill point!!\n"+OFF+OFF);
    myob->add_skill_pt(1);
    myob->add_skill_pts(1);
    myob->dervish_resett();
    return 1; 
  }
}

refund(){
  object me, myob;
  int amt;
  me = this_player();
  myob = present(GID, me);
  amt = myob->query_mystic_exp();
  amt = amt - 1500000;
  me->add_exp(amt);
  myob->add_mystic_exp(-amt);
  myob->dervish_resett();
  return 1; 
}

/* The purpose of this code is to hopefully stop Dervish guild
 * members from using their auto-lead drawback to attack a very
 * weak monster, become the tank, and steal any exp.
 * If they attempt to attack a monster below 15% of max hp
 * and the monster is already fighting someone else, the
 * attack will fail
 *  Illarion  10/30/02
 */
check_dervish_attack(object meat) {
  object room,meat_attacker;
  int meat_hp,meat_mhp;
  if(!meat)
    return 0;
/* This check doesn't apply to PK.  It won't allow PK either, it just
 * doesn't forbid it.
 */
  if(meat->is_player())
    return 1;
  room=environment(meat);
  if(!room)
    return 0;
  meat_attacker=meat->query_attack();
/* If the monster isn't fighting anyone else, is fighting the dervish,
 * or the person they're fighting is gone then we can allow the fight.
 */
  if(!meat_attacker || !present(meat_attacker,room) || meat_attacker == this_player())
    return 1;

  meat_hp=meat->query_hp();
  meat_mhp=meat->query_mhp();
/* If the monster has no max_hp set we can't calculate */
  if(meat_mhp==0) return 1;
/* The Dervish is attacking a weakened monster someone else is already
 * fighting.  Don't allow it. */
  if(100*meat_hp/meat_mhp <= 15) {
    return 0;
  }
/* Otherwise, it should now be okay. */
  return 1;
}

static sand_missile(str) {
  object meat;
  int dmg;
  if(this_player()->query_level() < 5) return 0;
  if(this_player()->query_spell_dam()) {
    write("The Sands are already lending strength to your attack.\n");
  spell_attacks ++;
    return 1; }
  if(str) meat = present(str, environment(TP));
/* If the spell is being used to start combat, see if the monster
 * is already low on hps and being attacked by someone else.
 */
  if(meat) if(!check_dervish_attack(meat)) {
    write("The sands stay your arm, and bid you find a worthy opponent.\n");
    return 1;
  }
  if(!meat) meat = TP->query_attack();
  if(!meat) { write("Attack what?\n"); return 1; }
  dmg = 5+random(10);
  TP->spell_object(meat,"",dmg,10,
      get_at_msg(meat,dmg),"",get_rm_msg(meat,dmg));
  TP->set_spell_dtype("other|earth");
  return 1; }

static sand_shock(str) {
  object meat;
  int dmg;
  if(this_player()->query_level() < 10) return 0;
  if(this_player()->query_spell_dam()) {
    write("The Sands are already lending strength to your attack.\n");
  spell_attacks ++;
    return 1; }
  if(str) meat = present(str, environment(TP));

/* If the spell is being used to start combat, see if the monster
 * is already low on hps and being attacked by someone else.
 */
  if(meat) if(!check_dervish_attack(meat)) {
    write("The sands stay your arm, and bid you find a worthy opponent.\n");
    return 1;
  }

  if(!meat) meat = TP->query_attack();
  if(!meat) { write("Attack what?\n"); return 1; }
  dmg = 8+random(14);
  TP->spell_object(meat,"NAME",dmg,15,
      get_at_msg(meat,dmg),"",get_rm_msg(meat,dmg));
  TP->set_spell_dtype("other|earth");
  return 1; }

static sand_fireball(str) {
  object meat;
  int dmg;
  if(this_player()->query_level() < 15) return 0;
  if(this_player()->query_spell_dam()) {
    write("The Sands are already lending strength to your attack.\n");
  spell_attacks ++;
    return 1; }
  if(str) meat = present(str, environment(TP));

/* If the spell is being used to start combat, see if the monster
 * is already low on hps and being attacked by someone else.
 */
  if(meat) if(!check_dervish_attack(meat)) {
    write("The sands stay your arm, and bid you find a worthy opponent.\n");
    return 1;
  }

  if(!meat) meat = TP->query_attack();
  if(!meat) { write("Attack what?\n"); return 1; }
  dmg = 12+random(16);
  TP->spell_object(meat,"NAME",dmg,20,
      get_at_msg(meat,dmg),"",get_rm_msg(meat,dmg));
  TP->set_spell_dtype("other|earth");
  return 1; }

static sand_sonic(str) {
  object meat;
  int dmg;
  if(this_player()->query_extra_level() < 5) return 0;
  if(this_player()->query_spell_dam()) {
    write("The Sands are already lending strength to your attack.\n");
  spell_attacks ++;
    return 1; }
  if(str) meat = present(str, environment(TP));

/* If the spell is being used to start combat, see if the monster
 * is already low on hps and being attacked by someone else.
 */
  if(meat) if(!check_dervish_attack(meat)) {
    write("The sands stay your arm, and bid you find a worthy opponent.\n");
    return 1;
  }

  if(!meat) meat = TP->query_attack();
  if(!meat) { write("Attack what?\n"); return 1; }
  dmg = 15+random(18);
  TP->spell_object(meat,"NAME",dmg,25,
      get_at_msg(meat,dmg),"",get_rm_msg(meat,dmg));
  TP->set_spell_dtype("other|earth");
  return 1; }

/* override the basic kill function too */
kill(str) {
  object meat;
  if(!str) return 0;
  meat=present(str,environment(TP));
  if(meat) if(!check_dervish_attack(meat)) {
    write("The sands stay your arm, and bid you find a worthy opponent.\n");
    return 1;
  }
  return 0;
}

get_at_msg(object meat, int num) {
  string meatn, msg;
  if(!meat) return;
  meatn = meat->query_real_name();
  if(!meatn) meatn = meat->query_name();
  if(!meatn) meatn = "something";
  meatn = capitalize(meatn);
  switch(num) {
  case 0..9:     msg = "A zephyr gives speed to your arm."; break;
  case 10..15:   msg = "The Sands lend power to your blow."; break;
  case 16..18:   msg = BOLD+"Particles of sand whip into "+meatn+"."; break;
  case 19..22:   msg = BOLD+"You attack with ungodly speed!"; break;
  case 23..25:   msg = RED+"The Scirocco whips into "+meatn+"!"; break;
  case 26..28:   msg = RED+"Winds flay the skin from "+meatn+"'s bones!"; break;
  case 29..31:   msg = RED+"Flecks of fire burn into "+meatn+"!"; break;
  case 32..34:   msg = BOLD+RED+meatn+" is hammered by the Sands!"; break;
  case 35..37:   msg = BOLD+RED+"Your motions blur as you rip into "+meatn+"!";
                 break;
  case 38..45:   msg = BOLD+RED+"The SandStorm blasts into "+meatn+"!"; break;
  }
  return msg+OFF+"\n";
}

get_rm_msg(meat, num) {
  string meatn, msg;
  if(!meat) return;
  meatn = meat->query_real_name();
  if(!meatn) meatn = meat->query_name();
  if(!meatn) meatn = "something";
  meatn = capitalize(meatn);
  switch(num) {
  case 0..9:     msg = "A zephyr gives speed to "+TP->query_name()+"'s arm."; break;
  case 10..15:   msg = "The Sands lend power to "+TP->query_name()+"'s blow."; break;
  case 16..18:   msg = BOLD+"Particles of sand whip into "+meatn; break;
  case 19..22:   msg = BOLD+TP->query_name()+" attacks with ungodly speed!"; break;
  case 23..25:   msg = RED+"The Scirocco whips into "+meatn+"!"; break;
  case 26..28:   msg = RED+"Winds flay the skin from "+meatn+"'s bones!"; break;
  case 29..31:   msg = RED+"Flecks of fire burn into "+meatn+"!"; break;
  case 32..34:   msg = BOLD+RED+meatn+" is hammered by the Sands!"; break;
  case 35..37:   msg = BOLD+RED+TP->query_name()+"'s motions blur as "+
                 TP->query_gender()+" rips into "+meatn+"!"; break;
  case 38..45:   msg = BOLD+RED+"The SandStorm blasts into "+meatn+"!"; break;
  }
  return msg+OFF+"\n";
}

dervish_reset() {
  object ob;
  if(!environment()) return;
  if(offwep) offwep->stop_wep_shadow();
  save_me();
  ob = clone_object(GUILDPATH+"/gob.c");
  write("Resetting Dervish whirlwind.\n");
  move_object(ob, environment());
  destruct(this_object());
  return 1; }
  
dervish_resett(){
  object ob;
  if(!environment()) return;
  save_me();
  return 1;
}

save_me(object ob) {
	string file;
	int tellme;
	if(ob) tellme++;
	if(!ob) ob = ENV();
	file = PFILE+"/"+ob->query_real_name();
	if(!save_object(file)){
		if(tellme) tell_object(ob, "Save error...\n");
		return 0;
	}
	if(tellme) tell_object(ob, "Saving Dervish whirlwind...\n");
	return 1;
}
	



/* COMBAT FUNCTIONS */
query_combat_method() { return 3; }
set_offwep(ob) { offwep = ob; }

/** Updated by Gnar 08/26/2014 **/
query_offwep() { 
  if(offwep) {
    if(( !offwep->query_offwielded()) || offwep->query_wielded_by() != environment())
      remove_offwep();
  }
  return offwep;
}

set_firstwep(ob) { firstwep = ob; }
query_firstwep() { return firstwep; }
remove_offwep() { offwep = 0; }
remove_firstwep() { firstwep = 0; }

/* SAND TRANSFER */
query_transfer() { return sand_transfer; }
set_transfer(num) { sand_transfer = num; }

/* SPELL DELAY */

add_spell_delay(num) { spell_delay += num; }
set_spell_delay(num) { spell_delay = num; }
query_spell_delay() { return spell_delay; }

/* MYSTIC EXP */

add_mystic_exp(num) { mystic_exp += num; }
query_mystic_exp() { return mystic_exp; }
set_mystic_exp(num) { mystic_exp = num; }

/* MYSTIC PERCENTAGE */

set_mystic_percent(num) { mystic_percent = num; }
query_mystic_percent() { return mystic_percent; }

/* PARRY SKILL */

set_parry(num) { parry = num; }
add_parry(num) { parry += num; }
query_parry() { return parry; }

/* OFFWIELD PARRY SKILL */

set_offparry(num) { offparry = num; }
add_offparry(num) { offparry += num; }
query_offparry() { return offparry; }

/* SKILL POINTS */

add_skill_pt(num) { skill_pt += num; }
set_skill_pt(num) { skill_pt = num; }
query_skill_pt() { return skill_pt; }
add_skill_pts(num) { skill_pts += num; }
set_skill_pts(num) {skill_pts = num; }
query_skill_pts() { return skill_pts; }


/* SAND POINTS */

query_sand_points() { return sand_points; }
add_sand_points(num) { sand_points += num; }
delete_sand_points(num)
{
  sand_points -= num;
 if(sand_points<=0)
  sand_points=0;
}
set_sand_points(num) { if(TP && check_me(TP)) sand_points = num; }

/* BRAVERY */
query_bravery() { return bravery; }
toggle_bravery() { bravery = !bravery; }
query_brave() { return brave; }
toggle_brave() { brave = !brave; }

check_me(ob) {
  if(ob->query_real_name() == "shinshi") return 1;
  if(ob == environment()) return 1;
  else return 0; }

/* DERVISH GUILD SETUP FUNCTIONS */
setup(object ob) {
  if(!ENV()) return 0;
  if(!ENV()->is_player()) return 0;
  ob->RegisterArmor(this_object(), ({"physical",0,0,"do_special"}));
  if(!restore_me(ob)) save_me(ob);
  reset();
  return 1; }

restore_me(object ob) {
  string file;
  file = PFILE+"/" + ob->query_real_name();
  if(!restore_object(file)) {
    tell_object(ob,"Dervish whirlwind restoration error...\n");
    return 0;
    }
  tell_object(ob,"Your whirlwind whips about you...\n");
  CHAND->add_channel(CHAN_NAME, ob );
  return 1;
}

do_special(owner)
{
  int lev;
  if(!owner) return;
  return - ((int)owner->query_ac());
}

check_desert(object ob) {
  object myenv;
  string sdesc, ldesc;
  if(!ob) return;
  if(myenv != environment(ob)) return;
  ldesc = myenv->query_long();
  sdesc = myenv->query_short();
  if(sscanf(ldesc, "%sdesert%s") || sscanf(ldesc, "desert%s") || sscanf(ldesc, "%sdesert") ||
      sscanf(ldesc, "%ssand%s") || sscanf(ldesc, "%ssand") || sscanf(ldesc, "sand%s") ||
      sscanf(sdesc, "%sdesert%s") || sscanf(sdesc, "%sdesert") || sscanf(sdesc, "desert%s") ||
      sscanf(sdesc, "%ssand%s") || sscanf(sdesc, "%ssand") || sscanf(sdesc, "sand%s") ) return 1;
  else return 0; }
  
get_title(num) {
	if(num > 19) return "Deity";
	if(num < 10) return "Initiate";
	if(num < 19) return "Mystic";
	return "Master";
}

dervishes() {
	int b, level;
	string title, place;
	object * iter;
	object ob;

	write("\n");
	write(BOLD+"********************************************************"+
	    "***********************\n"+OFF);
	write(BOLD+BLUE+pad("Dervish",     15)+
	    pad("Level",       11)+
	    pad("Title",       15)+
	    pad("Location",    30)+"\n"+OFF+OFF);
	write(BOLD+"********************************************************"+
	    "***********************\n\n"+OFF);

  iter = CHAND->on_channel( CHAN_NAME );
	if(!iter) { write("Derv malfunction 2.\n"); return 1; }
	for(b=0;b<sizeof(iter);b+=1)  {
    if(!iter[b]->query_invis()) {
        ob     = iter[b];
        write(pad(ob->query_name(), 15));
        level = ob->query_level();
        write(pad(level, 11));
        if(level < 10) write(YELLOW);
        if(level >= 10 && level < 19) write(BOLD);
        if(level >= 19) write(BOLD+RED);
        title = get_title(level);
        write(pad(title, 15));
        write(OFF+OFF);
        place = environment(ob)->short();
        write(OFF+OFF);
      write(place);
        write("\n");
    }
	}

	write(BOLD+"\n********************************************************"+
	    "***********************\n"+OFF);
	return 1;
}

show_weapons() {
  int gob;
  string fwep, owep;

  if(this_object()->query_firstwep()) fwep = this_object()->query_firstwep()->short();
  if(this_object()->query_offwep()) owep = this_object()->query_offwep()->short();
  if(!fwep) fwep = "none or not offwielding";
  if(!owep) owep = "none";
  write("Wielding "+fwep+"\nOffwielding "+owep+"\n");
  return 1;
}

ncom(string str) {
  if( (member_array(str, CAN_DO) == -1) && 
      TPRN != "snow" ) {
    write("You cannot ~~RUN~~ ["+str+"]\n");
    return;
  }
  command(str, TP);
}
