#include "/players/illarion/dfns.h"
inherit "/players/illarion/high/mon/imm_mon";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Richie Ryan");
  set_short("A blond, punkish-looking kid");
  set_race("immortal");
  set_long(
    "A kid with a serious attitude problems looks back at you, not\n"+
    "unfriendly, but certainly not respectful in any way, either.  He wears\n"+
    "jeans and a motorcycle jacket, and moves as if he owns the place.\n");
  set_attacks(2);

  set_level(15);
  set_x_attack_chance(60);
  set_immortal(1);
  set_weapon_path(HOBJ+"rrapier");
  set_gender("male");
  set_hp(225);
  set_wc(20);
  set_al(200);
  set_ac(12);
  add_chat_response("hello","Richie says, \"Hello, welcome to the dojo.\"\n");
  add_chat_response("dojo",
"Richie says, \"Yeah, it's a pretty nice place, isn't it?  Course,\n"+
"Charlie's a bit standoffish when it comes to new members.\"\n");
  add_chat_response("charlie",
"Richie says, \"Charlie used to own the place 'till Mac bought it,\n"+
"and he still runs it.\"\n");
  add_chat_response("mac",
    "Richie says, \"Duncan MacLeod.  He owns the dojo.\"\n");
  add_chat_response("kicks you","$kick_back$");
  add_chat_response("goodbye","Richie waves, already forgetting you.\n");
  add_chat_response("duncan","Richie says, \"Mac's not here.\"\n");
  add_chat_response("nice sword",
    "Richie says, \"Sword?  What sword?\"\n");
  add_chat_response("name",
"Richard Ryan.  My friends call me Richie, but you can call me Richard.\n");
}
id(string str) {
  return ::id(str) || str == "kid" || str == "richie" || str == "punk";
}
kick_back(string str) {
  tell_room(environment(),"Richie kicks "+str+".\n");
}
