inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("qurd");
  set_short("Qurd");
  set_alias("qurd");
  set_race("demon");
  set_long("The Qurd is something that appears to be somewhat\n"+
    "human, yet somewhat animal.  His tall, strong body is\n"+
    "human in shape, but is covered with fur.  His fingers\n"+
    "end in long, lethal looking claws.  His eyes are large\n"+
    "to accomodate his vision in the darkness.  He gives off\n"+
    "a strange, dank odor, and he seems to be able to use\n"+
    "some of the ever-present earth-power to his advantage.\n");
  set_hp(500);
  set_level(20);
  set_al(-1000);
  set_wc(41);
  set_ac(17);
  set_whimpy();
  set_dead_ob(this_object());
  set_aggressive(0);

  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("The Qurd eyes you with disdain and veiled anger...'\n");
  load_chat("Screams in the distance break the silence.\n");
  load_a_chat("You feel latent earth-energy swirling around the\n"+
            "room and you know FEAR!\n");

  set_chance(30);
  set_spell_dam(20);
  set_spell_mess1(" The force of the Qurd's hatred engulfs you!\n");
  set_spell_mess2("The Qurd directs the earth-energy at you and you reel with pain!\n");
   

  gold=clone_object("obj/money");
  gold->set_money(random(4000)+3000);
        /*  Point of note: 3000 +random(4000)  averages 5000 coins i.e. legal limit */
  move_object(gold,this_object());

call_out("random_move",20 + random(20));
}
monster_died() {
object ob;
ob=clone_object("/players/arrina/tmon/qurd3.c");

move_object(ob,environment(this_object()));
tell_room(environment(this_object()),"DEATH shall be AVENGED, foolish mortal!!!!!!\n");
}

status random_move() {
  int n;
  string msg;
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

  call_out("random_move",10+random(30));
  return 1;
}
