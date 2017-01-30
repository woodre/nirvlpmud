/* rat.c: typical rat */
inherit "obj/monster";
reset(arg) {
  if(arg)
    return ;
  ::reset(arg);
  set_name("rat");
  set_short("A rat");
  set_long("A foot long little rodent, with a sharp set of teeth and a few small claws\n"
          +"left. He seems to be (unsucsesfully) looking for some food.\n");
  load_chat("The rat scurries.\n");
  set_chat_chance(16);
  set_level(6);
  set_hp(35);
  set_wc(8);
  set_ac(2);
  set_ep(400);
  set_al(-20);
}
id(str) { return str == "rat"; }
