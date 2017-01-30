#define tp this_player()->query_name()
inherit "obj/monster";
reset(arg)  {
  object ob;
  ::reset(arg);
  if(arg) return;
  set_name("qurd mage");
  set_alias("qurd");
  set_race("demon");
  set_alt_name("qurd");
  set_short("Qurd Mage");
  set_long("This Qurd is obviously a mage!  Magical power \n"+
    "radiates from him and he moves as if floating on some \n"+
    "invisible dark energy.  His body is covered with fur, \n"+
    "his hands have lethal-looking claws where humans have\n"+
    "fingernails.  You sense carefully controlled violence\n"+
    "beneath his calm exterior visage.\n");
  set_hp(900);
  set_level(21);
  set_al(-900);
  set_wc(35);
  set_ac(17);
  set_aggressive(1);
  set_whimpy();
  ob=clone_object("/players/arrina/armor/sveil.c");
  move_object(ob,this_object());


  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The mage stares at you.\n");
  load_chat("The earth power flows around the mage.\n");
  load_a_chat("The mage raises his hand and points at you.\n");
  load_a_chat("You feel magical energy moving toward you.\n");

  set_chance(35);
  set_spell_dam(random(75));
  set_spell_mess1("Earth power snakes from the mage and surrounds you.\n"+
    "\n\n          > >  >  W H O O S H   <  < <\n\n"+
    "You see "+tp+" recoil from it's force.\n");
  set_spell_mess2("The mage gathers up power and sends it at you\n"+
    "\n\n          > >  >  F W E E E E  <  < <\n\n"+
    "You scream in agony...pain engulfs you....\n");
  enable_commands();
  if(root()) call_out("destme", 1);
  call_out("random_move",20 + random(30));
}

status random_move() {
  int n;
  string msg;
  if(!environment(this_object())) return 1;
  if(!query_attack()) {
  n = random(4);
switch(n) {
  case 0 : init_command("north");
           break;
  case 1 : init_command("east");
           break;
  case 2 : init_command("south");
           break;
  case 3 : init_command("west");
           break;
}
}

  call_out("random_move",10+random(30));
  return 1;
}

status id(string str) {
  return (::id(str) || str == alt_name || str == "mage")
  ;
}

destme() { destruct(this_object()); }
