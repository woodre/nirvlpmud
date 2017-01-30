
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_alias("quad");
  set_race("quadrian");
  set_type(random(5));
  set_level(15);
  set_wc(16);
  set_ac(11+random(2));
  set_hp(200+random(50));
  set_al(-200);
  add_money(800+random(100));
}
heart_beat() {
  ::heart_beat();
  if(attacker_ob) {
    already_fight=0;
    attack();
    already_fight=0;
    attack();
    already_fight=0;
    attack();
  }
}
set_type(R) {
  switch(R) {
    case 0: set_name("Quadrian Worker");
            set_alt_name("worker");
            set_short("Quadrian Worker");
            set_long(
"This quadrian has a smaller build, but larger limbs than\n"+
"the typical warrior.  His hair is cut shorter and he wears\n"+
"a leather harness for carrying tools.\n");
            set_gender("male");
            break;
    case 1: set_name("Quadrian Matron");
            set_alt_name("matron");
            set_long(
"This quadrian woman's grey and tangled hair falls almost\n"+
"to the floor.  She has likely seen many battles and raids\n"+
"throughout her lifetime and is now a respected elder among\n"+
"her people.\n");
            set_gender("female");
            break;
    case 2: set_name("Quadrian Trapper");
            set_alt_name("trapper");
            set_long(
"This former hunter has been reduced to setting snares and\n"+
"traps due to the onset of old age and the swelling of his\n"+
"many joints.\n");
            set_gender("male");
            break;
    case 3: set_name("Quadrian Hunter");
            set_alt_name("hunter");
            set_long(
"This four limbed creature was neither powerful enough\n"+
"to be a warrior, nor skilled enough to be a blacksmith\n"+
"so he is given the task of gathering meat for his fellows\n"+
"during nocturnal journeys outside the cave.\n");
            set_gender("male");
            break;
    case 4: set_name("Quadrian Child");
            set_alt_name("child");
            set_long(
"This immature quadrian's four arms are thin and frail.  It's\n"+
"back is slightly curved under the weight of its four arms,\n"+
"but it still has the potential to become a fierce warrior.\n");
            set_gender(random(1)?"male":"female");
            break;
  }
}
