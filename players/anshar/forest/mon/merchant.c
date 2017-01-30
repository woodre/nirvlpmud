#include "/players/anshar/closed/mydef.h"
inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("merchant");
  set_short("A merchant");
  set_alias("man");
  set_race("human");
  set_long("The man is of average height and build. Dark\n"+
    "hair and eyes mark a face lined only with signs of \n"+
    "laughter and happiness. He seems calm and assured of\n"+
    "himself as he stands examining you. He looks as though\n"+
    "he might have a good store of knowledge, it might be\n"+
    "good to 'ask' him what he knows of certain things.\n");
  set_hp(450);
  set_level(18);
  set_al(250);
  set_wc(26);
  set_ac(15);
  set_aggressive(0);

  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("The merchant hums to himself.\n");
  load_chat("The man says: I may have more to offer later, check back.\n");
  load_chat("The man smiles at you.\n");
  load_a_chat("The man says: Why do you attack me?!?\n");
}
  id(str) {return (str == "dmerchant" || str == "merchant" || str == "man"); }

init() {
  ::init();
  add_action("ask","ask");
    }
 
ask(str) {
  if(!str){
  notify_fail("Ask what?\n");
  return 0; }
  if(str != "delit"){
  notify_fail("Ask what?\n");
  return 0; }
  tell_room(environment(TO),
     "The merchant says: Ah, yes, I am interested in aquiring the tails\n"+
     "of the beasts.\n");
  return 1;}

