inherit "players/illarion/high/mon/imm_mon";
#include "/players/illarion/dfns.h"
int return_hit;
string last_att_type;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("hercules");
  set_race("human");
  set_gender("male");
  set_short("A large, muscular man");
  set_long(
"A tall, blue-eyed man dressed in leathers and bracers.  His mostly bare\n"+
"arms show an impressive musculature, and his manner indicates a lot of\n"+
"confidence.  Despite his war-like appearance, he carries no sword or\n"+
"similar large weapon.\n");
  set_level(20);
  set_wc(50);
  set_ac(40);
   set_multi_attack(1);
  set_hp(1500);
}
hit_player(x) {
  if(!random(4)) {
    tell_room(environment(),
      "Hercules dodges "+TPN+"'s attack.\n",({TP}));
    write("Hercules dodges your attack.\n");
    if(!random(4)) {
      return_hit+=x;
    }
    ::hit_player(0);
  } else
    return ::hit_player(x);
}
get_land() {
  string place;
  while(!place) place=call_other("obj/base_tele","teleport");
  return "/"+place;
}
/*
heart_beat() {
  string nasty_landing;
  if(return_hit)
    if(attacker_ob && present(attacker_ob,environment())) {
      tell_object(attacker_ob,
"Hercules slams you with the force of a dodged attack.\n");
      tell_room(environment(this_object()),
"Hercules slams "+attacker_ob->query_name()+" with a dodged attack.\n",
      ({attacker_ob}));
      attacker_ob->hit_player(return_hit);
      return_hit=0;
    }
  ::heart_beat();
  if(!random(10))
    if(attacker_ob && present(attacker_ob,environment())) {
      tell_object(attacker_ob,
"Hercules grabs you by the back of your waist and neck, swings you back\n"+
"and forth a couple of times, and then sends you flying through the air.\n");
      tell_room(environment(attacker_ob),
"Hercules grabs "+attacker_ob->query_name()+" and throws "+
attacker_ob->query_objective()+" headlong\n"+
"through the air and out of sight.\n",({attacker_ob}));
      nasty_landing=get_land();
      transfer(attacker_ob,nasty_landing);
      tell_object(attacker_ob,"\n\n\n"+
"You land with stunning force, and no idea of where you are.\n");
      tell_room(environment(attacker_ob),
attacker_ob->query_name()+" drops out of the sky.\n",({attacker_ob}));
    }
}
*/
query_message_hit(x) {
  string att_type;
  string hit_str;
  string hit_str2;
  att_type=({"kick","kick","punch","punch","double kick","double punch"})
    [random(6)];
  if(att_type == last_att_type) /* chance of different attack */
  att_type=({"kick","kick","punch","punch","double kick","double punch"})
    [random(6)];
  switch(x) {
    case 1:      hit_str="barely grazed"; break;
    case 2..3:   hit_str="lightly grazed"; break;
    case 4..5:   hit_str="hit"; hit_str2="lightly "; break;
    case 6..8:  hit_str="hit"; hit_str2="solidly "; break;
    case 9..11: hit_str="hit"; hit_str2="hard "; break;
    case 12..15: hit_str="lightly injured"; break;
    case 16..20: hit_str="injured"; break;
    case 21..25: hit_str="heavily injured"; break;
    case 26..30: hit_str="lightly stunned"; break;
    case 31..35: hit_str="stunned"; break;
    case 36..40: hit_str="heavily stunned"; break;
  }
  last_att_type=att_type;
  if(!hit_str)
    return ({" with a "+att_type,"nearly destroyed"});
  else
    return ({" "+(hit_str2?hit_str2:"")+"with a "+att_type,hit_str});
}
