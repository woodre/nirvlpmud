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
   if(!find_living("bmaster"))
 starta_master();
if(!arg)
  set_light( 1);
}
 short() {
    return "Templar Stables";
  }
 long() {
   write("This is quite clearly a horse stable. Just beyond your access\n"+
   "you can see and hear horses. It appears the area is specially designed\n"+
   "such that only the stable master can reach the horses. The area\n"+
   "is clean and well kept. It seems a very healthy place for the horses\n"+
   "that are kept here.\n"+
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
starta_master() {
object master,unif;
    if(!bmaster || !find_living("master")) {
	master = clone_object("obj/monster.c");
call_other(master, "set_name", "stablemaster");
call_other(master, "set_short", "Stable Master");
call_other(master, "set_alt_name","bmaster");
call_other(master, "set_long", "An old stable master.\n"+
          "He seems to be 'one' with the horses.\n"+
          " ");
	call_other(master, "set_ac", 0);
	call_other(master, "set_level",3);
	call_other(master, "set_al",50);
	call_other(master, "set_hp",66);
	call_other(master, "set_wc",5);
	call_other(master, "set_aggressive", 0);
call_other(master, "add_money", 238);
	move_object(master, "players/boltar/templar/stable");
	call_other(master, "set_chat_chance", 3);
	call_other(master, "load_chat", "The master says: Hello and welcome.\n");
	call_other(master, "load_chat", "The master says: " +
		   "Hello there!\n");
	call_other(master, "load_chat", "The master says: " +
                   "We have the best rates in land.\n");
	call_other(master, "load_chat", "The master says: " +
                   "We have the highest quality work.\n");
call_other(master, "load_chat", "The master says: " +
   "Please be seated, while you wait.\n");
	call_other(master, "load_chat", "The master says: " +
		   "Who are you?\n");
	call_other(master, "load_chat", "The master says: " +
                   "Are you ready?\n");
	call_other(master, "load_chat", "The master says: " +
                   "We have the lowest prices.\n");
	call_other(master, "load_chat", 
		   "The master grins evilly.\n");
        call_other(master, "load_chat", "The master smiles.\n");

	unif = clone_object("obj/armor");
	call_other(unif, "set_name", "uniform");
	call_other(unif, "set_short", "A master's uniform");
	call_other(unif, "set_alias", "uniform");
        unif->set_long("A tight white master's uniform with a short skirt\n");
        unif->set_size(1);
	call_other(unif, "set_value", 20);
	call_other(unif, "set_weight", 1);
	call_other(unif, "set_ac", 1);
	call_other(unif, "set_type", "armor");
move_object(unif, master);
call_other(master, "init_command", "wear uniform");
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
  tell_room(this_object(), "The master calls Dr. Bob\n");
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
  tell_room(this_object(), "The master calls Dr. Bob\n");
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
