inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

int invis_flag;
string tmp_short;

reset(arg) {
string adj;
   ::reset(arg);
   if(arg) return;
   adj=({"grotesque","deformed","squat","mutated","bloody","writhing","black","green",
      "rippling","irate","snivelling","decayed","screaming","horrible","putrid",
      "smelly","yellow","rotting","horned","huge","barbed","infuriated","maniacal",
      "pestulent","scaled","angry","insane","wailing","psychotic","deranged","cackling"});
	
  set_name("vampire");
  set_alias("vamp");
  set_race("demon");
  set_short("A "+HIR+""+adj[random(sizeof(adj))]+" "+NORM+"Vampire");
  /* Save for when we go vis */
  tmp_short = short_desc;
  set_long(
    " A long black cape covers most of this figures body. Long fangs protrude \n"+
    " from its mouth, blood covers most of its body. Red eyes glare and pierce \n"+
    " the soul.\n");
  move_object(clone_object("/players/sami/area/GPO/obj/vmace.c"),this_object());
  init_command("wield mace");
  set_level(23);
  set_hp(750+random(250));
  set_al(-800);
  set_heal(10,2);
  add_money(5000+random(4000));
  set_ac(random(10)+40);
  set_wc(random(15)+30);
  set_aggressive(0);
  invis_flag = 10 + random(10);

  add_spell("claw_swipe",
    HIK+"#MN#'s"+NORM+" claws flays your skin with "+HIY+"deadly"+HIB+" percision"+NORM+".\n",
    HIK+"#MN#"+NORM+" tears into #TN#'s "+HIY+"flesh"+NORM+" with his jagged claws.\n",
    35,80,"physical");
  
  add_spell("blood_feed",
     HIK+"#MN#"+NORM+" feeds on your "+HIR+"\n"+ "B\n"+ "L\n"+ "O\n"+ "O\n"+ "D"+NORM+"\n",
     HIK+"#MN#"+NORM+" feeds on #TN#'s "+HIR+"\n"+ "B\n"+ "L\n"+ "O\n"+ "O\n"+ "D"+NORM+"\n",
     35,80,"physical");

   set_a_chat_chance(5);
   set_chat_chance(2);
   load_chat("Vampire whispers: Only death is here for you.\n");
   load_a_chat("Vampire snarls: You shall pay with your life.\n");
}

id(str) {
  if( !short_desc )
    return 0;
  else
    return ::id(str);
}

calm() {
  object enemy, ob;
  int x;

  ob = all_inventory(environment());
  x = 0;
  while(x < sizeof(ob)) {
    if(ob[x]->query_attack()) {
      enemy = ob[x]->query_attack();
      ob[x]->stop_fight();
      ob[x]->stop_fight();
      ob[x]->stop_hunter();
      enemy->stop_fight();
      enemy->stop_fight();
      enemy->stop_hunter();
    }
    x += 1;
  }
  tell_room(environment(), this_object()->short()+ " fades into the "+HIK+"Shadows"+NORM+".\n");
  set_heal( 30, 2 );
  set_short(0);
  /* No chatting while hiding invis */
  set_chat_chance(0);
  call_out( "Vis", 20+random(15) );
}

heart_beat() {
  ::heart_beat();
  if( invis_flag )
    invis_flag--;

  if( invis_flag < 0 )
    invis_flag = 0;
 
  /* Only when we are vis, health is < 4/10, and cooldown is done **/
  if( query_hp() * 100 / query_mhp() < 40 && short_desc && !invis_flag )
    calm();
}

Vis() {
  invis_flag = 30+random(20);
  set_heal( 10, 5 );
  set_short( tmp_short );
  set_chat_chance(2);
  tell_room(environment(), this_object()->short()+ " steps out from the "+HIK+"Shadows"+NORM+".\n");
}

query_long() {
  string str;
  str = ::query_long();
  if( !this_player() || this_player()->query_level() < 21 )
    return str;
  return str += "Invis Flag: "+invis_flag+"\n";
}
