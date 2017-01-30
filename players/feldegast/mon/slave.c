
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_long(
"This wretched humanoid has been conscripted by the\n"+
"quadrians to work in their mines as a slave.  Life\n"+
"is harsh in the mines and this poor soul is covered\n"+
"in dirt, grime, and sweat.\n");
  set_alt_name("slave");
  set_type(random(3));
  set_gender(random(1)?"male":"female");
  set_level(11);
  set_wc(15);
  set_ac(9);
  set_hp(165);
  set_al(500);
}
set_type(R) {
  switch(R) {
    case 0: set_name("A human slave");
            set_race("human");
            break;
    case 1: set_name("An elven slave");
            set_race("elf");
            break;
    case 2: set_name("A dwarven slave");
            set_race("dwarf");
            break;
  }
}
