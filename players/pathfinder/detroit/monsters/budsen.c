inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("budsen");
   set_race("human");
   set_alias("officer");
   set_short("Officer Walter Budsen");
   set_long("\n"+
"  You look at Officer Walter Budsen, he is one of the people convicted\n"+
"in the slaying of Malice Green.  He doesn't look like he wants any of\n"+
"your crap right now.\n");   
   set_level(18);
   set_hp(200+ random(400));
   set_al(-100);
   set_wc(25);
   set_ac(15);
   set_chance(15);
   set_spell_dam(11);
   set_spell_mess1("Budsen blows chunks out of you with his pistol.\n");
   set_spell_mess2("Budsen knocks you to your knees with a chop to your neck.\n");
   set_chat_chance(2);
   load_chat("Budsen says: Hey Larry, that was one fun night wasn't it?\n");
   load_chat("Budsen says: Here Larry, catch!\n");
   load_chat("Budsen throws Malice Green's head across the room.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(400)+1000);
   move_object(gold,this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/9mm"), this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/clipb"), this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/clipb"), this_object());
/* removed by wocket (will move him to the church eventually) 5/27/01
   call_out("radio",5);
*/
}
   
 
radio() {
  if((this_player()->query_attack()) && (random(50) < 15)) {
    move_object(this_player(),"players/pathfinder/detroit/rooms/cell.c");
    say("You see Budsen radio for backup and here they come now!\n");
    say("You are overwelmed by the masses of police that are surrounding\n");
    say("you as you are thrown into a cell.\n");
    }
}

