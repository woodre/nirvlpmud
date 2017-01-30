/* verte [8.3.01] */
/* boosted spell and wc, ac, took out is_player() crap. */
/*  10/08/06 - Rumplemintz
      Moved inherit above #include statement
*/

inherit "obj/monster";
#include "/players/mythos/closed/guild/def.h"
#include "/players/beck/MortalKombat/MKQuestNPC.h" 
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("masakado");
  set_race("sorceror");
  set_short("Masakado");
  set_long("Here is the fabled sorceror/warrior himself- Masakado.\n"+
           "It is said that he controls the winds.  He is a stern\n"+
           "looking man with wild black hair and a thick beard.\n");
  set_hp(1500);
  set_level(19);
  move_object(clone_object("/players/mythos/awep/forest/air.c"),this_object());
  init_command("wield air");
  set_al(-650);
  set_dead_ob(this_object());
  set_wc(75 + random(15));
/* Because of the air this monster has no ac
  set_ac(25);
*/
/* however, that makes his exp value too low */
  set_ac_bonus(15);
  set_aggressive(1);
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("Masakado says: Bow before me!\n");
  load_chat("A strange wind blows...\n");
  load_a_chat(" Masakado shouts: None shall survive my wrath!\n");
  load_a_chat("The wind screams...\n");
  set_chance(40);
  set_spell_dam(170);
  set_spell_mess1("The wind throws Masakado's attacker into a wall!\n");
  set_spell_mess2("You are flung back into the wall by the wind!\n");
  gold = clone_object("obj/money");
  gold->set_money(random(1000)+2000);
  move_object(gold,this_object());
  call_out("fig",1);
  move_object(clone_object("/players/dragnar/MKScar/scar.c"),this_object());
}
/* this plays with too much stuff

   - verte

is_player() { return 1;}
query_npc() { return 0;}
query_interactive() { return 1;}
*/

monster_died() {
object ob;
ob=clone_object("/players/mythos/amon/forest/ryo3.c");
ob->set_haunt((this_object()->query_attack())->query_real_name());
move_object(ob,environment(this_object()));
tell_room(environment(this_object()),"Masakado yells out:  I curse ye!  I curse ye!\n");
/*
write_file("/players/mythos/logs/tower",ctime(time())+" "+(this_object()->query_attack())->query_real_name()+"  MASAKADO\n");
*/
if(present(fear,this_object()->query_attack())) {
    present(fear,this_object()->query_attack())->set_ban(1);
    present(fear,this_object()->query_attack())->save_dark();
    command("uu",this_object()->query_attack());
    tell_object(this_object()->query_attack(),
      "You feel power flood you!\n"+
      "Demons, spirits, deamons, avatars have much to fear from you!\n"+
      "True Banish is your to use!\n"+
      "To cast type <true_banish  <type>>\n");
write_file("/players/mythos/closed/guild/task_spell",
    ctime(time())+" "+(this_object()->query_attack())->query_real_name()+
    "  true_banish\n");

  }
return 0;
}

fig() {
object he;
int pl;
if(!environment(this_object())) return 1;
if(query_attack())
   if(query_attack() == this_object()) {
     heal_self(100000);
}
he = all_inventory(environment(this_object()));
if(!(this_object()->query_attack())) {
  for(pl=0;pl<sizeof(he);pl++) {
    if(he[pl] != this_object() && living(he[pl]) && !(he[pl]->query_npc())) {
   if(interactive(he[pl]))
      this_object()->attack_object(he[pl]);
    call_out("fig",10);
    return 1;}
    }
  call_out("fig",10);
return 1;}
call_out("fig",10);
return 1;}

#include "/players/mythos/amon/hb_ag.h"
