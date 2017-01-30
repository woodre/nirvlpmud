inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("noble");
set_alias("man");
set_alias("nobleman");
set_short("A Nobleman");
set_race("namekian");
set_long(
"The noble is wearing a long sleeved shirt with frilled sleeves\n"+
"and a vest over the shirt. Also he is wearing a pair of khaki pants\n"+
"and a pair of sandals. He also has a sword at his side ready\n"+
"to be used\n");
set_level(12);
set_ac(9);
set_hp(185);
set_al(0);
set_aggressive(0);
set_chat_chance(10);
load_chat("A Nobleman says: Oh what am I to do today? i wish my slaves would have shown up this morning.\n");
move_object(clone_object("/players/mosobp/areas/TEMPLE/OBJ/nsword.c"), this_object());
init_command("wield sword");
set_wc(10);
}
