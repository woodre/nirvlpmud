init() {
  add_action("buy"); add_verb("buy");
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
     add_action("look", "read");
  add_action("north"); add_verb("north");
 }
reset(arg) {
   if(!find_living("bnurse"))
 starta_nurse();
if(!arg)
  set_light( 1);
}
 short() {
    return "Dr. Bob's";
  }
 long() {
    write("You have entered what apears to be a very clean medical facility.\n"+
    "There is a counter at the far end of the room and a small sign above it.\n"+
    "Behind the counter it appears to be a nurse's station. There are many\n"+
    "photos on the wall that look to be satisified coustmers. There is a line\n"+
"of cheap vinyl chairs on the north near the room's entrance.\n"+
    "\n");
  }
 north() {
  call_other(this_player(), "move_player", "north#players/boltar/sprooms/clinic/lobby");
  return 1;
}
look(str) {
   if (!str) {
   return 0;
  }
 if (str == "sign" || str == "at sign") {
  write("The sign reads:\n");
  write("       Dr. Bob, The Magical Plastic surgon\n");
  write("       Speciallizing in plastic surgery for all races with a\n");
  write("       magical twist.\n");
  write("  Dr. Bob can for the listed fee:\n");
  write("  1. Give you magical breasts for 1000 coins\n");
  write("  2. Put some meat on your bones for 300 coins\n");
  write("\n");
  write("Just type buy <item number>\n");
  write("\n");
   return 1;
  }
return 0;
}
starta_nurse() {
object nurse,unif;
    if(!nurse || !find_living("nurse")) {
	nurse = clone_object("obj/monster.c");
call_other(nurse, "set_name", "nurse");
call_other(nurse, "set_short", "A nurse");
call_other(nurse, "set_alt_name","bnurse");
call_other(nurse, "set_long", "A beautiful nurse (female).\n"+
          "A nurse with beautiful long blond hair, she is wearing a nurse's\n"+
          "uniform with a short skirt with the top couple buttons undone\n"+
          "allowing you to see her ample cleaveage\n"+
          " ");
	call_other(nurse, "set_ac", 0);
	call_other(nurse, "set_level",3);
	call_other(nurse, "set_al",50);
	call_other(nurse, "set_hp",66);
	call_other(nurse, "set_wc",5);
	call_other(nurse, "set_aggressive", 0);
call_other(nurse, "add_money", 238);
	move_object(nurse, "players/boltar/sprooms/clinic/plastic");
	call_other(nurse, "set_chat_chance", 3);
	call_other(nurse, "load_chat", "The nurse says: Hello and welcome.\n");
	call_other(nurse, "load_chat", "The nurse says: " +
		   "Hello there!\n");
	call_other(nurse, "load_chat", "The nurse says: " +
                   "We have the best rates in land.\n");
	call_other(nurse, "load_chat", "The nurse says: " +
                   "We have the highest quality work.\n");
call_other(nurse, "load_chat", "The nurse says: " +
   "Please be seated, while you wait.\n");
	call_other(nurse, "load_chat", "The nurse says: " +
		   "Who are you?\n");
	call_other(nurse, "load_chat", "The nurse says: " +
                   "Are you ready?\n");
	call_other(nurse, "load_chat", "The nurse says: " +
                   "We have the lowest prices.\n");
	call_other(nurse, "load_chat", 
		   "The nurse grins evilly.\n");
        call_other(nurse, "load_chat", "The nurse smiles.\n");

	unif = clone_object("obj/armor");
	call_other(unif, "set_name", "uniform");
	call_other(unif, "set_short", "A nurse's uniform");
	call_other(unif, "set_alias", "uniform");
        unif->set_long("A tight white nurse's uniform with a short skirt\n");
        unif->set_size(1);
	call_other(unif, "set_value", 20);
	call_other(unif, "set_weight", 1);
	call_other(unif, "set_ac", 1);
	call_other(unif, "set_type", "armor");
move_object(unif, nurse);
call_other(nurse, "init_command", "wear uniform");
}
}

buy(str) {
  if(!str) return 0;
  if(str != "2" && str != "1") return 0;
  if(str == "1") {
  if(present("boobs",this_player())) {
    tell_object(this_player(), "The Nurse tells you: You already have a fine set.\n");
   return 1;
  }
  if(this_player()->query_money() < 1000) {
   tell_object(this_player(), "The Nurse tells you: Dr. Bob doesn't work for free you know.\n");
   return 1;
  }
  this_player()->add_money(-1000);
  log_file("Clinic",this_player()->query_real_name()+" boobs\n");
  tell_room(this_object(), "The nurse calls Dr. Bob\n");
  tell_room(this_object(), "A door appears on the south wall out of nowhere.\n");
  tell_room(this_object(), "Dr. Bob runs out of his office and zaps "+this_player()->query_name()+" with\na beam of light from an odd looking device.\n");
  move_object(clone_object("/players/boltar/sprooms/clinic/boobs"),this_player());
 tell_room(this_object(), "Dr. Bob says: Now becareful with those.\n");
 tell_room(this_object(), "Dr. Bob wanders back into his office, the door dissapearing behind him.\n");
 tell_object(this_player(), "The Nurse tells you: look at your boobs for instructions.\n");
  }
  if(str=="2") {
  if(this_player()->query_phys_at(3) > 350) {
  tell_object(this_player(), "The Nurse tells you: I think you've gotten big enough.\n");
   return 1;
   }
  if(this_player()->query_money() < 300) {
   tell_object(this_player(), "The Nurse tells you: Dr. Bob doesn't work for free you know.\n");
   return 1;
  }
  tell_room(this_object(), "The nurse calls Dr. Bob\n");
  tell_room(this_object(), "A beam of light appears in the middle of the room.  It fades and Dr. Bob\n");
  tell_room(this_object(), "appears. He pulls out a tube like device, points"+
" it at "+this_player()->query_name()+"\n");
  tell_room(this_object(), this_player()->query_name()+" gains weight suddenly.  Dr. Bob says: That should do it.\nHe puts away his device and dissapears the same way he came.\n");
   this_player()->add_phys_at(3,15+random(50));
   log_file("Clinic",this_player()->query_real_name()+" gain\n");
  this_player()->add_money(-300);
   return 1;
  }
 return 1;
}
