/***************************************************
| Addition to immortal monster/interactive code:
| randomly steals 300 coins or an object during combat
***********************************************/
#include "/players/illarion/dfns.h"
inherit "/players/illarion/high/mon/imm_mon";

reset(arg) {
  if(!present("shift",this_object())) {
    move_object(clone_object(HOBJ+"ashift"),this_object());
  }
  ::reset(arg);
  if(arg) return;

  set_name("Amanda");
  set_short("An extremely attractive dark-haired woman");
  set_race("immortal");
  set_weapon_path(HOBJ+"arapier");
  set_long(
"Although clothed in rather flimsy, lacy garments, this woman looks as sure\n"+
"of herself as anyone could.  Her lack of clothing makes it very\n"+
"obvious that she is well-shaped, and her limbs suggest a certain\n"+
"amount of strength as well.\n");
  set_level(18);
  set_immortal(1);
  set_gender("female");
  set_hp(450+random(200));
  set_wc(26);
  set_al(-200);
  set_ac(15);
  set_chat_chance(7);
  load_chat("The woman adjusts her garments in a spurious fasion.\n");
  load_chat("The woman gives you a direct stare and asks, \"Well?\"\n");
  add_chat_response("hello","The woman murmurs, \"Well, hello yourself.\"\n");
  add_chat_response("clothes",
"Looking surprised, the woman asks, \"What's wrong with my clothes?\"\n");
  add_chat_response("thief",
"Looking offended, the woman says, \"Thief?  I'm not a thief!  How dare\n"+
"you?\"\n");
  add_chat_response("name","The woman says, \"I'm Amanda, of course.\"\n");
  add_chat_response("duncan",
"Trying to appear innocent, the woman says, \"Duncan?  I don't know anyone\n"+
"named Duncan.\"\n");
}
id(string str) {
  return ::id(str) || str == "amanda" || str == "woman" || str == "thief";
}
check_drop(object ob) {
  return !ob->drop();
}
check_take(object ob) {
  return ob->get();
}
do_pick_pocket() {
  object *things;
  int size;
  int x;
  if(!environment()) return;
  if(!present(attacker_ob,environment())) return;
  if(random(2)) {
    if(attacker_ob->query_money() > 300) {
      attacker_ob->add_money(-300);
      add_money(300);
    }
  } else {
    things=all_inventory(attacker_ob);
    things=filter_array(things,"check_take",this_object());
    things=filter_array(things,"check_drop",this_object());
    size=sizeof(things);
    if(size)  {
      x=random(size);
      IBUG("trying to steal "+things[x]->query_name()+"\n");
      transfer(things[x],this_object());
    }
  }
  if(attacker_ob->query_attrib("luc") > random(50))
    tell_object(attacker_ob,"You feel a ghostly touch tug at you.\n");
}
heart_beat() {
  ::heart_beat();
  if(attacker_ob && !random(5)) do_pick_pocket();
}
