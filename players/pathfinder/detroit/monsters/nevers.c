inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("nevers");
   set_race("human");
   set_alias("officer");
   set_ep(100000);
   set_short("Officer Larry Nevers");
   set_long("\n"+
"  You look at Officer Larry Nevers, he is one of the people convicted\n"+
"in the slaying of Malice Green.  He doesn't look like he is in a mood to\n"+
"take any of your crap right now.\n");   
   set_level(17);
   set_hp(250+ random(300));
   set_al(400);
   set_wc(25);
   set_ac(15);
   set_chance(15);
   set_spell_dam(11);
   set_spell_mess1("Nevers blows chunks out of you with his pistol.\n");
   set_spell_mess2("Nevers knocks you to your knees with a chop to your neck.\n");
   set_chat_chance(2);
   load_chat("Nevers says: Hey Walter, that was one fun night wasn't it?\n");
   load_chat("Nevers says: Here Walter, catch!\n");
   load_chat("Nevers kicks Malice Green's head across the room.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(400)+1000);
   move_object(gold,this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/9mm"), this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/clipb"), this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/clipb"), this_object());
   call_out("radio",7);
}
   
 
radio() {
  if((this_player()->query_attack()) && (random(20) < 7)) {
    move_object(this_player(),"players/pathfinder/detroit/rooms/cell.c");
    say("You see Nevers radio for backup and here they come now!\n");
    say("You are overwelmed by the masses of police that are surrounding\n");
    say("you as you are thrown into a cell.\n");
    }
}
