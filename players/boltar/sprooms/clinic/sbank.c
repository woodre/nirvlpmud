init() {
  add_action("donate"); add_verb("donate");
  add_action("turnin","turnin");
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
     add_action("look", "read");
  add_action("south"); add_verb("south");
  add_action("north"); add_verb("north");
  add_action("west"); add_verb("west");
  add_action("east"); add_verb("east");
  add_action("down"); add_verb("down");
 }
reset(arg) {
   if(!find_living("nurse"))
 starta_nurse();
 if(!arg)
  set_light( 1);
}
 short() {
    return "The sperm bank";
  }
 long() {
    write("You have entered what apears to be a very clean medical facility.\n"+
    "There is a counter at the far end of the room and a small sign above it.\n"+
    "Behind the counter it appears to be a nurse's station. A door to the east\n"+
    "is marked 'cryogenic freezing', a door to the west is marked 'surgery\n"+
    "room A3, implantation'. There is a line of cheap vinyl chairs on the\n"+
    "south wall near the room's entrance. Behind the counter to the north\n");
    write("there is a door marked private. There is a small set of stairs leading down.\n");
  }
west() {
  call_other(this_player(), "move_player", "west#players/boltar/sprooms/clinic/implant.c");
  return 1;
  }
down() {
  call_other(this_player(), "move_player", "down#room/abort.c");
  return 1;
  }
east() {
  call_other(this_player(), "move_player", "east#players/boltar/sprooms/clinic/freezer.c");
  return 1;
 }
 north() {
  call_other(this_player(), "move_player", "north#players/boltar/sprooms/clinic/private");
  return 1;
}
 south() {
  call_other(this_player(), "move_player", "south#players/boltar/sprooms/clinic/lobby");
  return 1;
}
look(str) {
   if (!str) {
   return 0;
  }
 if (str == "sign" || str == "at sign") {
  write("The sign reads:\n");
  write("               The Village Hospital Fertility Clinic\n");
  write("               Sperm donations pay 10 coins per level of the donor\n");
  write("               up to 190 coins.  Implantation costs 20 coins per\n");
  write("               level of the donar up to 380 coins plus a 1000 coin\n");
  write("               doctor's fee. Use <donate> or <donate anonymous> to\n");
  write("               donate sperm.  To be implanted first go east to\n");
  write("               look in the freezer to choose a donor then enter\n");
  write("               the surgery room for implantation.\n");
  write("               We have an 85% success rate.\n");
  write("\n");
  write("               You may 'turnin' your paternity test kits here.\n");
  write("               Kits may be purchased in the shop upstairs.\n");
  write("\n");
   return 1;
  }
return 0;
}

turnin() {
  object kit;
  string result;
  kit = present("paternity test kit",this_player());
  if(!kit) {
    write("You don't have a kit!\n");
   return 1;
  }
  if(kit->query_teststatus() < 2) {
    write("Both test samples have not been collected.\n");
    return 1;
  }
  say(this_player()->query_name()+" turns in a test kit.\n");
  write("You turn in the test kit.\n");
  result = kit->results();
  write("RESULTS:\n");
  write(result+"\n");
  destruct(kit);
  return 1;
}

donate(str) {
  string name,race;
  int cash,ht_ft,ht_in,wt,lv,b;
  b=0;
  name=this_player()->query_real_name();
  if(call_other("/players/boltar/sprooms/clinic/freezer","check_names",name)) {
      write("Your sperm is currently on file, we do not need more.\n");
      return 1;
   }
   if(this_player()->query_gender()=="female") {
     write("It is biologically impossible for you to donate sperm.\n");
     return 1;
    }
   lv=this_player()->query_level();
  race=this_player()->query_race();
  ht_ft=this_player()->query_phys_at(1);
  ht_in=this_player()->query_phys_at(2);
  wt=this_player()->query_phys_at(3);
  if(str=="anonymous") b = 1;
  call_other("/players/boltar/sprooms/clinic/freezer","add_donor",name,race,ht_ft,ht_in,wt,lv,b);
   write("You are ushered into the room to the north maked private.\n");
  call_other(this_player(), "move_player", "north#players/boltar/sprooms/clinic/private");
   say(name+" is ushered into the room to the north marked 'private'.\n");
   write("You do your thing and donate your sperm.\n");
   cash=lv*10;
   if(cash > 190) cash = 190;
   this_player()->add_money(cash);
   return 1;
}
starta_nurse() {
object nurse,unif;
    if(!nurse || !find_living("nurse")) {
	nurse = clone_object("obj/monster.c");
call_other(nurse, "set_name", "nurse");
call_other(nurse, "set_short", "A nurse");
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
	move_object(nurse, "players/boltar/sprooms/clinic/sbank");
	call_other(nurse, "set_chat_chance", 3);
	call_other(nurse, "load_chat", "The nurse says: Hello and welcome.\n");
	call_other(nurse, "load_chat", "The nurse says: " +
		   "Hello there!\n");
	call_other(nurse, "load_chat", "The nurse says: " +
                   "We have the best rates in land.\n");
	call_other(nurse, "load_chat", "The nurse says: " +
                   "We have the best selection possible.\n");
call_other(nurse, "load_chat", "The nurse says: " +
   "Please be seated, while you wait.\n");
	call_other(nurse, "load_chat", "The nurse says: " +
		   "Who are you?\n");
	call_other(nurse, "load_chat", "The nurse says: " +
                   "Are you ready?\n");
	call_other(nurse, "load_chat", "The nurse says: " +
                   "We pay our donors very well.\n");
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

