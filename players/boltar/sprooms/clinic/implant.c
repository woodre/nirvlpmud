#define FREEZE "/players/boltar/sprooms/clinic/freezer"
short() {return "The surgery room"; }
long() {
   write("You have entered the implantation surgery room, there is a \n"+
         "standard operating table in the center of the room. The room\n"+
         "has a very anti-septic appearance and everything appears to be\n"+
         "in good order. After making your selection from the freezer\n"+
         "you can be implanted with it using the command implant <number>\n"+
         "There is a single exit to the east.\n");
   return 1;
 }
init() {
 add_action("east","east");
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
     add_action("implant", "implant");

 }
east() {
  call_other(this_player(), "move_player", "east#players/boltar/sprooms/clinic/sbank.c");
  return 1;
}
look(str) {
   if (!str) {
   return 0;
  }
 if (str == "table" || str == "at table") {
  write("An ordinary surgical table.\n");
  write("\n");
   return 1;
  }
return 0;
}
implant(arg){
  int num,cost;
   if(!arg || sscanf(arg, "%d", num)!=1) {
   write("You must specify a freezer number.\n");
   return 1;
   }
  if(!present("fertility doctor")) {
    write("You'll have to wait until the doctor returns.\n");
    return 1;
  }
   if(this_player()->query_gender()!="female") {
      write("It is biologically impossible for you to become pregnant.\n");
      return 1;
   }
   if(this_player()->query_pregnancy()){
     if(this_player()->query_age() - this_player()->query_pregnancy() < 4000) {
     if(random(10) < 5)
       write("The doctor says: You may already be pregnant. I cannot do the operation.\n");
     else
       write("The doctor says: I cannot operate, your condition is too fragile.\n");
       return 1;
      }
      write("You are already pregnant!\n");
      return 1;
   }
   if(call_other(FREEZE,"send_name",num) == "EMPTY" || !call_other(FREEZE,"send_name",num)) {
      write("There isn't anything stored under that number.\n");
      return 1;
   }
   cost=call_other("/players/boltar/sprooms/clinic/freezer","query_cost",num)+1000;
   if(this_player()->query_money() < cost) {
     write("You do not have enough money.\n");
     write("It will cost you "+cost+" coins\n");
     return 1;
   }
   this_player()->add_money(-cost);
  write("You are ushered on to the table.\n");
  say(this_player()->query_name()+" is placed on the surgical table.\n");
  say("The doctor draws a curtin around the operating table.\n");
  write("The doctor begins to operate, you can't quite see what he is doing.\n");
   if(random(1000)<850)
    {
  write("The doctor says: I think that should do it. You'll have the usual symptoms.\n");
   this_player()->set_pregnancy("The doctor through his medical skill");
    }
  else
  write("The operation is unsuccessful.\n");
  write("The doctor completes what he was doing, you are now free to go.\n");
  write("The operation costs "+cost+" coins.\n");
  call_other(FREEZE,"use_sample",num);
   return 1;
}
starta_doctor() {
object doctor,unif;
    if(!doctor || !find_living("fertility doctor")) {
	doctor = clone_object("obj/monster.c");
call_other(doctor, "set_name", "fertility doctor");
call_other(doctor, "set_short", "A doctor");
call_other(doctor, "set_race", "doctor");
call_other(doctor, "set_long", "A doctor (male).\n"+
         "An ordinary older man, wearing a lab coat\n"+
          "\n");
	call_other(doctor, "set_ac", 0);
	call_other(doctor, "set_level",3);
	call_other(doctor, "set_al",50);
	call_other(doctor, "set_hp",66);
	call_other(doctor, "set_wc",5);
	call_other(doctor, "set_aggressive", 0);
call_other(doctor, "add_money", 276);
	move_object(doctor, "players/boltar/sprooms/clinic/implant");
	call_other(doctor, "set_chat_chance", 3);
	call_other(doctor, "load_chat", "The doctor says: Hello and welcome.\n");
	call_other(doctor, "load_chat", "The doctor says: " +
		   "Hello there!\n");
	call_other(doctor, "load_chat", "The doctor says: " +
                  "hmmm.... what do we have here...\n");
call_other(doctor, "load_chat", "The doctor says: " +
   "Please get on to the table.\n");
	call_other(doctor, "load_chat", "The doctor says: " +
		   "Who are you?\n");
	call_other(doctor, "load_chat", "The doctor says: " +
                   "Are you ready?\n");
	call_other(doctor, "load_chat", 
		   "The doctor grins evilly.\n");
        call_other(doctor, "load_chat", "The doctor smiles.\n");

	unif = clone_object("obj/armor");
	call_other(unif, "set_name", "uniform");
	call_other(unif, "set_short", "A doctor's lab coat");
	call_other(unif, "set_alias", "coat");
        unif->set_long("A lab coat.\n");
        unif->set_size(3);
	call_other(unif, "set_value", 20);
	call_other(unif, "set_weight", 1);
	call_other(unif, "set_ac", 1);
	call_other(unif, "set_type", "armor");
move_object(unif, doctor);
call_other(doctor, "init_command", "wear uniform");
}
}

reset(arg) {
   if(!find_living("fertility doctor"))
 starta_doctor();
 if(!arg)
 set_light(1);
}
