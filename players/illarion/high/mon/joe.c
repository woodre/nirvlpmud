inherit "players/illarion/high/mon/imm_mon";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Joe Dawson");
  set_alias("joe");
  set_race("human");
  set_gender("male");
  set_short("A white-bearded man with a cane");
  set_long(
"A middle-aged man with bright, intelligent blue eyes, looking at\n"+
"home behind the bar despite his cane and extremely awkward gait.\n"+
"His hair and beard are liberally streaked with white, but he looks quite\n"+
"confident in himself.\n");
  set_level(18);
  set_hp(500);
  set_wc(30);
  set_ac(12);
  set_al(150);
  add_chat_response("hello",
"The man says, \"Hello.  Welcome to my bar.\"\n");
  add_chat_response("name",
"The man says, \"Joe Dawson.  Owner and proprietor.\"\n");
  add_chat_response("bar",
"The man asks, \"You like it?  I've put a lot into the place.\"\n");
  add_chat_response("watchers",
"The man says, \"Watching who?\"\n");
  add_chat_response("maccleod",
"The man says, \"It doesn't ring a bell, but a lot of people come here.\"\n");
  add_chat_response("immortals",
"The man says, \"Don't know what you mean,\" but he looks nervous.\n");
  add_chat_response("amulet",
"The man says, \"Oh...  it's just a family heirloom.\"\n");
  add_chat_response("back room",
"The man says, \"Sorry, Employees only.\"\n");
  add_chat_response("drink",
"The man says, \"If you want to order something, check the menu.  I \n"+
"forget some of the options sometimes.\"\n");
}
id(str) {
  return ::id(str) || str == "dawson" || str == "man";
}
long() {
  ::long();
  if(environment(this_object()))
    if(present(TP,environment(this_object())))
      call_out("greet_person",0,TP);
}
greet_person(object ob) {
  if(environment(this_object()))
    if(present(ob,environment(this_object())))
      tell_room(environment(this_object()),
"Joe says, \"Can I do something for you?\"\n",({this_object()}));
}
