inherit "obj/monster";
 reset(arg)  {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("nikki");
  set_race("dog");
  set_alias("dog");
  set_short("Nikki--Arrina's loyal companion");
  set_long("Nikki, a Champion Rhodesian Ridgeback--he is a\n"+
    "large red hound, bred in Africa to hunt lions, but he is also\n"+
    "very sweet, and an excellent pet.  He moves with great grace, \n"+
   " for one so large, and sometimes is very playful.\n");
  set_level(1);
  set_hp(100000);
  set_al(100);
  weapon = clone_object("/players/arrina/closed/teeth.c");
  move_object(weapon,this_object());
  init_command("wield teeth");
  set_wc(30);
  set_ac(2);
  set_aggressive(0);
  set_chat_chance(2);
  set_a_chat_chance(10);
  load_chat("Nikki walks up to you and wants to be petted.\n");
  load_chat("Nikki yawns lazily...\n");
  load_chat("Nikki climbs into the chair and goes to sleep.\n");
  load_chat("Nikki finds a stray piece of paper and shreds it.\n");
  load_chat("Nikki looks at you with his soft eyes, wanting a treat.\n");
  load_a_chat("A low growl issues from Nikki's throat.\n");
  load_a_chat("GGGGGRRRRRRRRRRR......\n");
}
