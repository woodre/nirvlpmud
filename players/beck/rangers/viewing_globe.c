string messages, new_hd, new_body;
int num_messages;
object who;
string *ranger_names;
string *ranger_colors;
string *ranger_animals;
string *ranger_thunderzords;
string *ranger_weapons;
string *ranger_levels;
string *colors;
string *animals;
string *weapons;
int member_number;

#include "/players/beck/rangers/defs.h"

id(str) { return str=="globe" || str=="viewing globe"; }
reset(arg) {
   if (arg)
      return;
   restore_object("players/beck/save/rangers/globe");
}
short() {
   return "The Viewing Globe";
}
long() {
   write("To see a list of guild members type 'Rangers'.\n");
   if(COMM){
      write(""+
         "There are currently "+member_number+" Power Rangers.\n"+
         "The maximum number of guild members allowed is 25.\n"+
         "To leave the guild type 'leave', but I hope you won't.\n"+
         "");
      write("You can set up new notes with the command 'note headline'.\n");
      write("Read a note with 'read num', and remove an old note with\n");
      write("'remove num'.\n");
      if (num_messages == 0) {
         write("It is empty.\n");
         return 1;
         return;
      }
      write("The bulletine board contains " + num_messages);
      if (num_messages == 1)
         write(" note:\n\n");
      else
         write(" notes:\n\n");
      say(call_other(this_player(), "query_name") +
         " studies the Viewing Globe.\n");
      headers();
      return;
   }
   write("Welcome to the Power Ranger Command Center.\n"+
      "If you wish to become a Power Ranger just type 'info' for information.\n"+
      "There are currently "+member_number+" Power Rangers.\n"+
      "The maximum number of guild members allowed is 25.\n"+
      "If you wish to join the guild type 'join'.\n"+
      "You must be between levels 5 and 10 to join as a full member.\n"+
      "If you wish to become an honorary member only type 'join honorary'.\n"+
      "Honorary membership allows you to talk on the guild channel.\n"+
      "Have a nice day.\n"+
      "");
}
init() {
   add_action("ranger_info","info");
   add_action("join_power_rangers","join");
   add_action("ranger_roster","Rangers");
   if(COMM){
      add_action("leave_power_rangers","leave");
      add_action("new","note");
      add_action("read","read");
      add_action("remove","remove");
      update_ranger_roster();
   }
   if(this_player()->query_real_name() == "beck"){
      add_action("update_ranger_roster","UPDATE");
      add_action("add_color","ADDCOLOR");
      add_action("add_animal","ADDANIMAL");
      add_action("add_weapon","ADDWEAPON");
      add_action("remove_color","REMCOLOR");
      add_action("remove_animal","REMANIMAL");
      add_action("remove_weapon","REMWEAPON");
   }
}

get() {
   return 0;
}
query_weight() { return 0; }
query_value() { return 5000; }
ranger_info(str){ MASTER->ranger_help(str);
   write("TYPE INFO AND SUBJECT (instead of ranger + subject)!!!!\n");
   return 1;
}


headers() {
   string hd, body, rest;
   int i, tmp;
   
   i = 1;
   rest = messages;
   while(rest != 0 && rest != "") {
      tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
      if (tmp != 2 && tmp != 3) {
         write("Corrupt.\n");
         return;
         }
      write(i + ":\t" + hd + "\n");
      i += 1;
   }
}

new(hd) {
   if (!hd)
      return 0;
   if (who && environment(who) == environment(this_object())) {
      write(call_other(who, "query_name") + " is busy writing.\n");
      return 1;
   }
   if (num_messages == 10) {
      write("You have to remove an old message first.\n");
      return 1;
   }
   if (strlen(hd) > 50) {
      write("Too long header to fit the paper.\n");
      return 1;
   }
   new_hd = hd;
   input_to("get_body");
   write("Give message, and terminate with '**'.\n");
   write("]");
   new_body = "";
   return 1;
}

get_body(str) {
   if (str == "**") {
      new_hd = new_hd + "(" + capitalize(call_other(this_player(), "query_real_name")) +
      " the "+present("ranger_communicator", this_player())->query_ranger_color()+
      " Ranger"+
      ")";
      messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
      num_messages += 1;
      new_body = 0;
      new_hd = 0;
      save_object("players/beck/save/rangers/globe");
      write("Ok.\n");
      who = 0;
      return;
   }
   new_body = new_body + str + "\n";
   write("]");
   input_to("get_body");
}

read(str) {
   string hd, body, rest;
   int i, tmp;
   
   if (str == 0 || (sscanf(str, "%d", i) != 1 &&
            sscanf(str, "note %d", i) != 1))
   return 0;
   if (i > num_messages) {
      write("Not that number of messages.\n");
      return 1;
   }
   rest = messages;
   while(rest != 0 && rest != "") {
      i -= 1;
      tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
      if (tmp != 2 && tmp != 3) {
         write("Corrupt.\n");
         return;
         }
      if (i == 0) {
         say(call_other(this_player(), "query_name") +
            " reads a note titled '" + hd + "'.\n");
         write("The note is titled '" + hd + "':\n\n");
         write(body);
         return 1;
         }
   }
   write("Hm. This should not happen.\n");
}

remove(str) {
   string hd, body, rest;
   string jun2,jun;
   int i, tmp;
   
   if (str == 0 || (sscanf(str, "%d", i) != 1 &&
            sscanf(str, "note %d", i) != 1))
   return 0;
   if (i > num_messages) {
      write("Not that number of messages.\n");
      return 1;
   }
   rest = messages;
   jun2 = messages;
   messages = "";
   while(rest != 0 && rest != "") {
      i -= 1;
      tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
      if (tmp != 2 && tmp != 3) {
         write("Corrupt.\n");
         return;
         }
      if (i == 0) {
         if(sscanf(hd, "%sboltar", jun) == 1 && this_player()->query_real_name() !="boltar") {
            write("You cannot remove this message.\n");
            messages=jun2;
            return 1;
          }
         say(call_other(this_player(), "query_name") +
            " removed a note titled '" + hd + "'.\n");
         write("Ok.\n");
         messages = messages + rest;
         num_messages -= 1;
         save_object("players/beck/save/rangers/globe");
         return 1;
         }
      messages = messages + hd + ":\n**\n" + body + "\n**\n";
   }
   write("Hm. This should not happen.\n");
}
add_color(str){
   colors += ({ str });
   save_globe();
   return 1;
}
add_animal(str){
   animals += ({ str });
   save_globe();
   return 1;
}
add_weapon(str){
   weapons += ({ str });
   save_globe();
   return 1;
}
remove_color(str){
   colors -= ({ str });
   save_globe();
   return 1;
}
remove_animal(str){
   animals -= ({ str });
   save_globe();
   return 1;
}
remove_weapon(str){
   weapons -= ({ str });
   save_globe();
   return 1;
}

join_power_rangers(){
   int k;
   object communicator;
write("I am sorry.  If you wish to join the Power Rangers at this time\n"+
"you must mail Beck.\n");
return 1;
   if(COMM){
      write("You are already a Power Ranger!!!\n");
      return 1;
   }
   if(this_player()->query_npc() || this_player()->is_kid()){
      return 0;
   }
   if(!restore_object("players/beck/save/rangers/"+NAME)){
      if(member_number == 25){
         write("The Guild has already reached its maximum number of members.\n"+
            "You will have to try to join some other time.\n"+
            "");
         return 1;
      }
      if(this_player()->query_guild_exp() > 0){
         write("You are already in a guild.  \n"+
            "If this is not correct mail Beck.\n");
         return 1;
      }
      if(this_player()->query_level() < 5){
         write("You need to be at least level 5 to join.\n");
         return 1;
      }
      if(this_player()->query_level() > 10){
         write("You can't be above level 10 to initially join.  If you are willing to\n"+
            "drop to level 10 mail Beck.\n");
         return 1;
      }
      communicator = clone_object("/players/beck/rangers/RangerCommunicator.c");
      move_object(communicator, this_player());
      communicator->SRangerColor("Initiate");
      communicator->SRangerDino("Teddy Bear");
      communicator->SRangerAnimal("Hampster");
      communicator->SRangerWeapon("Toothpick");
      communicator->SKarateLevel(0);
      communicator->SOldTitle(this_player()->query_title());
      communicator->SOldPretitle(this_player()->query_pretitle());
      communicator->SSkills("power");
      communicator->ASkills("ranger");
      communicator->ASkills("time");
      communicator->SDefense("block");
      communicator->SOffense("chop");
communicator->SUnlearnedSkills("rt");
communicator->AUnlearnedSkills("rte");
communicator->AUnlearnedSkills("rwho");
communicator->AUnlearnedSkills("practice");
communicator->AUnlearnedSkills("generate");
communicator->AUnlearnedSkills("defense");
communicator->AUnlearnedSkills("offense");
communicator->AUnlearnedSkills("study");
communicator->AUnlearnedSkills("white");
communicator->AUnlearnedSkills("yellow");
communicator->AUnlearnedSkills("orange");
communicator->AUnlearnedSkills("red");
communicator->AUnlearnedSkills("green");
communicator->AUnlearnedSkills("blue");
communicator->AUnlearnedSkills("purple");
communicator->AUnlearnedSkills("brown");
communicator->AUnlearnedSkills("black");
communicator->AUnlearnedSkills("dino");
communicator->AUnlearnedSkills("thunder");
communicator->AUnlearnedSkills("morph");
communicator->AUnlearnedSkills("unmorph");
communicator->AUnlearnedSkills("zord");
communicator->AUnlearnedSkills("megazord");
communicator->AUnlearnedSkills("teleport");
communicator->AUnlearnedSkills("donate");
communicator->AUnlearnedSkills("lead");
communicator->AUnlearnedSkills("jet");
communicator->AUnlearnedSkills("weapon");
communicator->AUnlearnedSkills("blaster");
communicator->AUnlearnedSkills("ninja");
communicator->AUnlearnedSkills("lamp");
communicator->AUnlearnedSkills("armor");
communicator->AUnlearnedSkills("zeo");
communicator->AUnlearnedSkills("turbo");
      write("Congratulations New Power Ranger.\n");
      write("\n");
      write("May the Power Protect You!\n");
      write("\n");
      communicator->save_ranger();
      this_player()->add_guild_exp(100);
      member_number += 1;
      if(present("honor_ranger_communicator", this_player())){
         destruct(present("honor_ranger_communicator", this_player()));
      }
      save_globe();
      init();
      for(k=0; k<sizeof(colors); k++){
         write(colors[k]);
         write(", ");
      }
      write("\n");
      write("To choose your color type ' <name of color from list>'.\n"+
         "Make sure you capitalize the first letter of the color you choose.\n"+
         "");
      input_to("color");
      return 1;
   }
if(NAME == "beck"){
move_object(clone_object("/players/beck/rangers/RangerCommunicator.c"),this_player());
COMM->restore_ranger(); COMM->init(); return 1;
}
   write("Restoring your guild object!!!\n");
   move_object(clone_object("/players/beck/rangers/ranger_communicator.c"), this_player());
   COMM->restore_ranger();
   COMM->init();
   return 1;
}   
color(str){
   int k;
   if(COMM->query_ranger_color() == "New"){
      for(k=0; k<sizeof(colors); k++){
         if(colors[k] == str){
            COMM->set_ranger_color(capitalize(str));
            write("Your new color is set.\n");
            colors -= ({ str });
            save_globe();
            for(k=0; k<sizeof(animals); k++){
               write(animals[k]);
               write(", ");
            }
            write("\n");
            write("To choose your animal name type ' <name of animal>'.\n"+
               "");
            input_to("animal");
            return 1;
          }
      }
      write("That is not a color you can choose.  Write Beck if you want it approved.\n");
      input_to("color");
      return 1;
   }
   write("Your color is already set.\n");
   return 1;
}
animal(str){
   int k;
   if(COMM->query_ranger_animal() == "Teddy Bear"){
      for(k=0; k<sizeof(animals); k++){
         if(animals[k] == str){
            COMM->set_ranger_animal(capitalize(str));
            write("Your new animal is set.\n");
            animals -= ({ str });
            save_globe();
            for(k=0; k<sizeof(animals); k++){
               write(animals[k]);
               write(", ");
            }
            write("\n");
            write("To choose your thunderzord name type '<name of thunderzord>'.\n"+
               "");
            input_to("thunderzord");
            return 1;
          }
      }
      write("That is not a animal you can choose.  Write Beck if you want it approved.\n");
      input_to("animal");
      return 1;
   }
   write("Your animal is already set.\n");
   return 1;
}
thunderzord(str){
   int k;
   if(COMM->query_ranger_thunderzord() == "Hampster"){
      for(k=0; k<sizeof(animals); k++){
         if(animals[k] == str){
            COMM->set_ranger_thunderzord(capitalize(str));
            write("Your new thunderzord is set.\n");
            animals -= ({ str });
            save_globe();
            for(k=0; k<sizeof(weapons); k++){
               write(weapons[k]);
               write(", ");
            }
            write("\n");
            write("To choose your weapon name name type '<name of weapon>'.\n"+
               "");
            input_to("weapon");
            return 1;
          }
      }
      write("That is not a thunderzord you can choose.  Write Beck if you want it approved.\n");
      input_to("thunderzord");
      return 1;
   }
   write("Your thunderzord is already set.\n");
   return 1;
}
weapon(str){
   int k;
   if(COMM->query_ranger_weapon() == "Toothpick"){
      for(k=0; k<sizeof(weapons); k++){
         if(weapons[k] == str){
            COMM->set_ranger_weapon(capitalize(str));
            write("Your new weapon is set.\n");
            weapons -= ({ str });
            save_globe();
            init();
            return 1;
          }
      }
      write("That is not a weapon you can choose.  Write Beck if you want it approved.\n");
      input_to("weapon");
      return 1;
   }
   write("Your weapon is already set.\n");
   return 1;
}


leave_power_rangers(){
   if(!present("ranger_communicator", this_player())){
      write("You are not a Power Ranger\n");
      return 1;
   }
   write("Are you sure you want to leave the Power Rangers?  Yes/No: ");
   input_to("verify_leave_power_rangers");
   return 1;
}
verify_leave_power_rangers(str){
   int i;
   int exp;
   if(!str || (str != "yes" && str != "no")){
      write("You want to leave the Power Rangers?  Yes/No: ");
      input_to("verify_leave_power_rangers");
      return 1;
   }
   if(str == "yes"){
      string cl,wo,an,th;
      int hh,jj;
      write("Very well then.  We will miss you.\n");
      exp = this_player()->query_exp();
      exp = exp/6;
      jj=0-this_player()->query_guild_exp();
      call_other(this_player(),"add_guild_exp",jj);
      hh=0-this_player()->query_guild_rank();
      this_player()->add_exp(-exp);
      this_player()->add_guild_rank(hh);
      this_player()->set_guild_name(0);
      this_player()->set_guild_file(0);
      this_player()->set_home("/room/church");
      cl = COMM->COLOR;
      wo = COMM->WEAPON;
      an = COMM->ANIMAL;
      th = COMM->THUNDER;
      member_number -= 1;
      if(cl != "New"){
         colors += ({ cl });
      }
      if(an != "Teddy Bear"){
         animals += ({ an });
      }
      if(th != "Hampster"){
         animals += ({ th }); 
      }
      if(wo != "Toothpick"){
         weapons += ({ wo });
      }
      ranger_names -= ({"Beck"});
      ranger_levels -= ({"Gold"});
      ranger_colors -= ({"Rainbow"});
      ranger_animals -= ({"Golden Eagle"});
      ranger_thunderzords -= ({"Goldfinch"});
      ranger_weapons -= ({"Holy Avenger"});
      for(i=0; i<sizeof(ranger_names); i++){
         if(ranger_names[i] == CAPNAME){
            ranger_names[i] = "Beck";
            ranger_colors[i] = "Rainbow";
            ranger_levels[i] = "Gold";
            ranger_animals[i] = "Golden Eagle";
            ranger_thunderzords[i] = "Goldfinch";
            ranger_weapons[i] = "Holy Avenger";
          }
      }
      destruct(present("ranger_communicator",this_player())); 
      destruct(present("ranger_armor",this_player()));
      destruct(present("ranger_weapon",this_player()));
      rm("/players/beck/save/rangers/"+this_player()->query_real_name()+".o");
      save_globe();
      return 1;
   }
   if(str == "no"){
      write("Good.  We would have missed you.\n");
      return 1;
   }
   return 1;
}
save_globe(){
   save_object("players/beck/save/rangers/globe");
   return 1;
}
ranger_roster(){
   int i;
   write(justify(" ",35));
   write("POWER RANGERS\n");
   write(justify("Name",12));
   write(justify("Color",10));
   write(justify("Belt",7));
   write(justify("Animal",18));
   write(justify("Thunderzord",18));
   write(justify("Weapon",13));
   write("\n\n");
   for(i=0; i<sizeof(ranger_names); i++){
      write(justify(ranger_names[i],12));
      write(justify(ranger_colors[i],10));
      write(justify(ranger_levels[i],7));
      write(justify(ranger_animals[i],18));
      write(justify(ranger_thunderzords[i],18));
      write(justify(ranger_weapons[i],13));
      write("\n");
   }
   return 1;
}
update_ranger_roster(){
   int i;
   if(member_array(CAPNAME, ranger_names) == -1){
      ranger_names += ({ CAPNAME });
      ranger_colors += ({ COMM->COLOR });
      ranger_levels += ({ "None" });
      ranger_animals += ({ COMM->ANIMAL });
      ranger_thunderzords += ({ COMM->THUNDER });
      ranger_weapons += ({ COMM->WEAPON });
      save_globe();
      return 1;
   }
   for(i=0; i<sizeof(ranger_names); i++){
      if(ranger_names[i] == CAPNAME){
         ranger_colors[i] = COMM->COLOR;
         if(COMM->KARATE == 0) ranger_levels[i] = "None";
         if(COMM->KARATE == 1) ranger_levels[i] = "Basic";
         if(COMM->KARATE == 2) ranger_levels[i] = "White";
         if(COMM->KARATE == 3) ranger_levels[i] = "Yellow";
         if(COMM->KARATE == 4) ranger_levels[i] = "Orange";
         if(COMM->KARATE == 5) ranger_levels[i] = "Red";
         if(COMM->KARATE == 6) ranger_levels[i] = "Green";
         if(COMM->KARATE == 7) ranger_levels[i] = "Blue";
         if(COMM->KARATE == 8) ranger_levels[i] = "Purple";
         if(COMM->KARATE == 9) ranger_levels[i] = "Brown";
         if(COMM->KARATE >= 10) ranger_levels[i] = "Black";
         if(CAPNAME == "Beck") ranger_levels[i] = "Gold";
         ranger_animals[i] = COMM->ANIMAL;
         ranger_thunderzords[i] = COMM->THUNDER;
         ranger_weapons[i] = COMM->WEAPON;
         save_globe();
       }
   }
   return 1;
}
