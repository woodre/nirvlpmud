#define tp this_player()->query_name()
inherit "obj/monster";
reset(arg)  {
  object ob;
  ::reset(arg);
  if(arg) return;
  set_name("unicorn");
  set_alias("unicorn");
  set_race("beast");
  set_short("A beautiful Black Unicorn");
  set_long("The one horned beast is of incredible beauty.  Its black hide radiates\n"+
    "an aura of tranquility.  Its black mane ruffles in the wind\n"+
    "and its horn gleams with an inner light.\n");
  set_hp(500);
  set_level(20);
  set_al(-500);
  set_wc(35);
  set_ac(17);
  set_aggressive(0);
  set_whimpy();
  ob=clone_object("/players/mythos/amisc/forest/horn.c");
  move_object(ob,this_object());


  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The unicorn turns its head and seems to look at you.\n");
  load_chat("The wind ruffles the unicorn's mane.\n");
  load_a_chat("The unicorn charges - a fury of horn and hoof.\n");
  load_a_chat("The unicorn's horn glistens- you are frightened.\n");

  set_chance(35);
  set_spell_dam(random(75));
  set_spell_mess1("The unicorn tosses its head- the horn momentarily brightens.\n"+
    "\n\n          > >  >  C R U N C H  <  < <\n\n"+
    "You see "+tp+" cry out in pain as the horn rips into "+tp+".\n");
  set_spell_mess2("The unicorn tosses its head- its horn momentarily brightens.\n"+
    "\n\n          > >  >  C R U N C H  <  < <\n\n"+
    "You cry out in pain...the unicorn's horn shines with your blood.\n");
  call_out("random_move",20 + random(30));
}

status random_move() {
  int n;
  string msg;
  n = random(4);
 if(!environment(this_object())) return 1;
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
/*
tell_room(environment(this_object()),"Unicorn enters the room.\n");
*/
  call_out("random_move",10+random(30));
  return 1;
}
