string messages, new_hd, new_body;
int num_messages;
object who;
int *ranger_time;
string *ranger_purged;
string *ranger_types;
string *ranger_names;
string *ranger_colors;
string *ranger_animals;
string *ranger_dinos;
string *ranger_weapons;
string *ranger_levels;
string *ranger_numbers;
string *colors;
string *animals;
string *dinos;
string *weapons;
string *numbers;
int member_number;

#include "/players/beck/rangers/Defs.h"

id(str) { return str=="globe" || str=="ViewingGlobe"; }
reset(arg) {
   if (arg)
      return;
   restore_object("players/beck/save/rangers/Globe");
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
      "If you wish to become an honorary member only type 'join_honorary'.\n"+
      "Type 'restore' to regain your lost guild object.\n"+
      "Honorary membership allows you to talk on the guild channel.\n"+
      "Have a nice day.\n"+
      "");
}
init() {
   int glevel;
   int gexp;
   add_action("ranger_info","info");
   add_action("join_power_rangers","join");
   add_action("ranger_roster","Rangers");
   add_action("join_honorary","join_honorary");
   add_action("restore_object","restore");
   if(COMM){
      if(member_array(CAPNAME,ranger_purged) != -1){
         destruct(present("RangerCommunicator",TP));
         write("You have not played in over 45 days and have been removed from the Rangers.\n");
         glevel = TP->GLEVEL;
         gexp = TP->query_guild_exp();
         TP->add_guild_exp(-gexp);
         TP->add_exp(gexp);
         TP->add_guild_rank(-glevel);
         TP->set_guild_file(0);
         TP->set_home("/room/church");
         rm("/players/beck/save/rangers/"+TP->query_real_name()+".o");
         remove_ranger_purged(CAPNAME);
         return;
      }
      add_action("leave_power_rangers","leave");
      add_action("new","note");
      add_action("read","read");
      add_action("remove","remove");
      if(TP->query_level() < 20){
         update_ranger_roster();
      }
   }
   if(this_player()->query_real_name() == "beck"){
      add_action("set_time","STIME");
      add_action("add_time","ATIME");
      add_action("remove_time","RTIME");
      add_action("set_ranger_purged","SPURGED");
      add_action("add_ranger_purged","APURGED");
      add_action("remove_ranger_purged","RPURGED");
      add_action("see_time","TIME");
      add_action("see_purged","PURGED");
      add_action("remove_from_roster","REMOVE");
      add_action("set_ranger_type","SRANGERTYPE");
      add_action("add_ranger_type","ARANGERTYPE");
      add_action("set_number","SNUMBER");
      add_action("set_mn","SMEMBERNUM");
      add_action("update_ranger_roster","UPDATE");
      add_action("add_color","ADDCOLOR");
      add_action("add_animal","ADDANIMAL");
      add_action("add_weapon","ADDWEAPON");
      add_action("remove_color","REMCOLOR");
      add_action("remove_animal","REMANIMAL");
      add_action("remove_weapon","REMWEAPON");
      add_action("remove_dino","RDINO");
      add_action("add_dino","ADINO");
      add_action("see_color","COLOR");
      add_action("see_animal","ANIMAL");
      add_action("see_dino","DINO");
      add_action("see_weapon","WEAPON");
      add_action("add_mn","AMEMBERNUM");
      add_action("add_ranger_number","ARANNUMBER");
      add_action("set_ranger_number","SRANNUMBER");
      add_action("see_number","NUMBER");
      add_action("add_number","ANUMBER");
      add_action("remove_number","RNUMBER");
   }
   if(present("ranger_communicator",this_player())){
      join_power_rangers();
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
      " the "+COMM->COLOR+
      " Ranger"+
      ")";
      messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
      num_messages += 1;
      new_body = 0;
      new_hd = 0;
save_globe();
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
save_globe();
         return 1;
         }
      messages = messages + hd + ":\n**\n" + body + "\n**\n";
   }
   write("Hm. This should not happen.\n");
}
set_number(str){
   numbers = ({ str });
   save_globe();
   return 1;
}
add_number(str){
   numbers += ({ str });
   save_globe();
   return 1;
}
remove_number(str){
   numbers -= ({ str });
   save_globe();
   return 1;
}
set_time(str){
   ranger_time = ({ str });
   save_globe();
   return 1;
}
add_time(str){
   ranger_time += ({ str });
   save_globe();
   return 1;
}
remove_time(str){
   ranger_time -= ({ str });
   save_globe();
   return 1;
}
set_ranger_number(str){
   ranger_numbers = ({ str });
   save_globe();
   return 1;
}
add_ranger_number(str){
   ranger_numbers += ({ str });
   save_globe();
   return 1;
}
set_ranger_purged(str){
   ranger_purged = ({ str });
   save_globe();
   return 1;
}
add_ranger_purged(str){
   ranger_purged += ({ str });
   save_globe();
   return 1;
}
remove_ranger_purged(str){
   ranger_purged -= ({ str });
   save_globe();
   return 1;
}
add_dino(str){
   dinos += ({ str });
   save_globe();
   return 1;
}
remove_dino(str){
   dinos -= ({ str });
   save_globe();
   return 1;
}
set_mn(num){
   int i;
   if(sscanf(num, "%df", i) !=1){
      return 1;
   }
   member_number = i;
   save_globe();
   return 1;
}
add_mn(num){
   int i;
   if(sscanf(num, "%df", i) !=1){
      return 1;
   }
   member_number += i;
   save_globe();
   return 1;
}
add_color(str){
   colors += ({ str });
   save_globe();
   return 1;
}
set_ranger_type(str){
   ranger_types = ({ str });
   return 1;
}
add_ranger_type(str){
   ranger_types += ({ str });
   save_globe();
   return 1;
}
add_animal(str){
   animals += ({ str });
   save_globe();
   return 1;
}
add_dinos(str){
   dinos += ({ str });
   save_globe();
   return 1;
}
remove_dinos(str){
   dinos -= ({ str });
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
see_number(){
   int i;
   for(i=0; i<sizeof(numbers); i++){
      write(numbers[i]);
      write(", ");
   }
   write("\n");
   return 1;
}
see_color(){
   int i;
   for(i=0; i<sizeof(colors); i++){
      write(colors[i]);
      write(", ");
   }
   write("\n");
   return 1;
}
see_dino(){
   int i;
   for(i=0; i<sizeof(dinos); i++){
      write(dinos[i]);
      write(", ");
   }
   write("\n");
   return 1;
}
see_animal(){
   int i;
   for(i=0; i<sizeof(animals); i++){
      write(animals[i]);
      write(", ");
   }
   write("\n");
   return 1;
}
see_weapon(){
   int i;
   for(i=0; i<sizeof(weapons); i++){
      write(weapons[i]);
      write(", ");
   }
   write("\n");
   return 1;
}
see_purged(){
   int i;
   for(i=0;i<sizeof(ranger_purged);i++){
      write(ranger_purged[i]);
      write(", ");
   }
   write("\n");
   return 1;
}

see_time(){
   int i;
   for(i=0; i<sizeof(ranger_time); i++){
      write(ranger_time[i]);
      write(", ");
   }
   write("\n");
   return 1;
}

join_honorary(){
   if(COMM){
      write("You are a Power Ranger!");
      return 0;
   }
   if(TP->query_guild_name() == "shardak" || TP->query_guild_name() == "cyberninja"){
      write("Your guild will never be an Ally of the Rangers!\n");
      return 0;
   }
   if(!present("honor_ranger_communicator"), this_player()){
      move_object(clone_object("/players/beck/Rangers/HonorRangerCommunicator.c"), this_player());
      return 1;
   }
   return 0;
}
join_power_rangers(){
   int k,jjj,hhh;
   object communicator;
   if(present("ranger_communicator", this_player())){
      write("Converting to new power ranger...");
      jjj=0-this_player()->query_guild_exp();
      call_other(this_player(),"add_guild_exp",jjj);
      hhh=0-this_player()->query_guild_rank();
      this_player()->add_guild_rank(hhh);
      this_player()->set_guild_name(0);
      this_player()->set_guild_file(0);
      rm("/players/beck/save/rangers/"+this_player()->query_real_name()+".o");
      TP->add_exp(-jjj);
      destruct(present("ranger_communicator",this_player()));
      write("Conversion Complete.\n");
   }
   if(this_player()->query_npc() || this_player()->is_kid()){
      return 0;
   }
   if(this_player()->query_level() > 19){
      write("Wizards are not allowed to join, because of errors that will\n"+
         "occur due to their level.\n");
      write("Please do not clone a guild object.  Clone HonorRangerCommunicator.c");
      return 1;
   }
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
   communicator->SRangerNumber("0");
   communicator->SRangerDino("None");
   communicator->SRangerAnimal("None");
   communicator->SRangerWeapon("None");
   communicator->SKarateLevel(0);
   communicator->SOldTitle(this_player()->query_title());
   communicator->SOldPretitle(this_player()->query_pretitle());
   communicator->SRangerTypes("initiate");
   communicator->SSkills("power");
   communicator->ASkills("skills");
   communicator->ASkills("ranger");
   communicator->ASkills("time");
   communicator->SDefense("block");
   communicator->SOffense("chop");
   communicator->SUnlearnedSkills("rwho");
   communicator->AUnlearnedSkills("practice");
   communicator->AUnlearnedSkills("generate");
   communicator->AUnlearnedSkills("study");
   communicator->AUnlearnedSkills("white");
   communicator->AUnlearnedSkills("dino");
   communicator->AUnlearnedSkills("shiho-nage");
   communicator->AUnlearnedSkills("irimi-nage");
   write("Zordon tells you: Welcome to the Power Rangers!\n"+
      "I am pleased you have decided to become part of our orginization.\n"+
      "For a period of time you will be an initiate\n"+
      "This will be a chance for you to prove that you are worthy\n"+
      "of the ideals that the Power Rangers hold.\n"+
      "The Power Rangers are given their abilities in order to protect good\n"+
      "and destroy evil.  In time you learn many skills that will help\n"+
      "you to use the power you are given to the fullest.\n"+
      "\n"+"Zordon hands you a Communicator.\n"+
      "Zordon tells you:  This is the device that the Rangers use to\n"+
      "communicator with others.  You must learn how to use\n"+
      "it well, for it has many beneficial functions.\n"+
      "Go now and meet the other Power Rangers, learn about your communicator,\n"+
      "and begin your martial arts training.  You must do all this as\n"+
      "well as begin to start fighting the forces of evil in order\n"+
      "to become a true Power Ranger.\n"+
      "Good Luck, and may the Power protect you!\n"+
      "");
   write("\n");
   write("Please log out of Nirvana and back in again for changes to take effect.\n\n");
   communicator->SaveRanger();
   communicator->init();
   this_player()->add_guild_exp(100);
   member_number += 1;
   save_globe();
   init();
   return 1;
}
restore_object(){
   if(COMM){
      write("You do not need to restore anything.\n");
      return 1;
   }
   if(this_player()->query_guild_name() != "rangers"){
      write("This is for Rangers guild members only.\n");
      return 1;
   }
   write("Restoring your guild object!!!\n");
   move_object(clone_object("/players/beck/rangers/RangerCommunicator.c"), this_player());
COMM->init_arg();
   COMM->init();
   return 1;
}   
Color1(){
   int k;
   write("It is time decide on your Ranger Color.\n"+
      "You may choose from the following list.\n"+
      "\n");
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
color(str){
   int k;
   if(COMM->QRangerColor() == "Initiate"){
      for(k=0; k<sizeof(colors); k++){
         if(colors[k] == str){
            COMM->SRangerColor(capitalize(str));
            write("Your new color is set.\n");
            colors -= ({ str });
            save_globe();
            Dino1();
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
Animal1(){
   int k;
   write("\n"+
      "Now you are to choose an animal that best exemplifies you character.\n"+
      "You may choose from the list I will give you.\n"+
      "\n");
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
animal(str){
   int k;
   if(COMM->QRangerAnimal() == "None"){
      for(k=0; k<sizeof(animals); k++){
         if(animals[k] == str){
            COMM->SRangerAnimal(capitalize(str));
            write("Your new animal is set.\n");
            animals -= ({ str });
            save_globe();
            Weapon1();
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
Dino1(){
   int k;
   write("\n"+
      "It is now time to choose your personal Dinozord.\n"+
      "Choose a Dinozord that best exemplifies yourself.\n"+
      "\n");
   for(k=0; k<sizeof(dinos); k++){
      write(dinos[k]);
      write(", ");
   }
   write("\n");
   write("To choose your dinozord name type '<name of thunderzord>'.\n"+
      "");
   input_to("dino");
   return 1;
}
dino(str){
   int k;
   if(COMM->QRangerDino() == "None"){
      for(k=0; k<sizeof(dinos); k++){
         if(dinos[k] == str){
            COMM->SRangerDino(capitalize(str));
            write("Your new dinozord is set.\n");
            dinos -= ({ str });
            save_globe();
            COMM->SaveRanger();
            return 1;
          }
      }
      write("That is not a dinozord you can choose.  Write Beck if you want it approved.\n");
      input_to("dino");
      return 1;
   }
   write("Your dinozord is already set.\n");
   return 1;
}
Weapon1(){
   int k;
   write("\n"+
      "Now choose your weapon that you will bring into battle with you.\n"+
      "\n");
   for(k=0; k<sizeof(weapons); k++){
      write(weapons[k]);
      write(", ");
   }
   write("\n");
   write("To choose your weapon name type '<name of weapon>'.\n"+
      "");
   input_to("weapon");
   return 1;
}
weapon(str){
   int k;
   if(COMM->QRangerWeapon() == "None"){
      for(k=0; k<sizeof(weapons); k++){
         if(weapons[k] == str){
            COMM->SRangerWeapon(capitalize(str));
            write("Your new weapon is set.\n");
            weapons -= ({ str });
            save_globe();
            COMM->SaveRanger();
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
Number1(){
   int k;
   write("\n"+
      "Now choose your number.\n"+
      "\n");
   for(k=0; k<sizeof(numbers); k++){
      write(numbers[k]);
      write(", ");
   }
   write("\n");
   write("To choose your number type '<number>'.\n"+
      "");
   input_to("number");
   return 1;
}
number(str){
   int k;
   if(COMM->QRangerNumber() == "0"){
      for(k=0; k<sizeof(numbers); k++){
         if(numbers[k] == str){
            COMM->SRangerNumber(str);
            write("Your new number is set.\n");
            numbers -= ({ str });
            save_globe();
            COMM->SaveRanger();
            return 1;
          }
      }
      write("That is not a number you can choose.  Write Beck if you want it approved.\n");
      input_to("number");
      return 1;
   }
   write("Your number is already set.\n");
   return 1;
}


leave_power_rangers(){
   if(!present("RangerCommunicator", this_player())){
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
      string nu;
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
      th = COMM->DINO;
      nu = COMM->NUMBER;
      member_number -= 1;
      if(cl != "Initiate"){
         colors += ({ cl });
      }
      if(an != "None"){
         animals += ({ an });
      }
      if(th != "None"){
         dinos += ({ th }); 
      }
      if(wo != "None"){
         weapons += ({ wo });
      }
      if(nu != "0"){
         numbers += ({ nu });
      }
      ranger_names -= ({"Beck"});
      ranger_levels -= ({"Gold"});
      ranger_types -= ({"Supreme"});
      ranger_colors -= ({"Rainbow"});
      ranger_animals -= ({"Goldfinch"});
      ranger_dinos -= ({"Golden Eagle"});
      ranger_time -= ({2000});
      for(i=0; i<sizeof(ranger_names); i++){
         if(ranger_names[i] == CAPNAME){
            ranger_names[i] = "Beck";
            ranger_types[i] = "Supreme";
            ranger_colors[i] = "Rainbow";
            ranger_levels[i] = "Gold";
            ranger_animals[i] = "Goldfinch";
            ranger_dinos[i] = "Golden Eagle";
            ranger_time[i] = 2000;
          }
      }
      destruct(present("RangerCommunicator",this_player())); 
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
   save_object("players/beck/save/rangers/Globe");
save_object("players/beck/Rangers/Save/Globe");
   return 1;
}
remove_from_roster(str){
   int i;
   ranger_names -= ({"Beck"});
   ranger_levels -= ({"Gold"});
   ranger_types -= ({"Supreme"});
   ranger_colors -= ({"Rainbow"});
   ranger_animals -= ({"Goldfinch"});
   ranger_dinos -= ({"Golden Eagle"});
   ranger_time -= ({2000});
   member_number -= 1;
   for(i=0; i<sizeof(ranger_names); i++){
      if(ranger_names[i] == str){
         ranger_names[i] = "Beck";
         ranger_types[i] = "Supreme";
         ranger_colors[i] = "Rainbow";
         ranger_levels[i] = "Gold";
         ranger_animals[i] = "Goldfinch";
         ranger_dinos[i] = "Golden Eagle";
         ranger_time[i] = 2000;
       }
   }
   add_ranger_purged(str);
   return 1;
}
ranger_roster(){
   int i;
   write(justify(" ",35));
   write("POWER RANGERS\n");
   write(justify("Name",12));
   write(justify("Type",9));
   write(justify("Color",10));
   write(justify("Belt",7));
   write(justify("Dino",18));
   write(justify("Animal",15));
   write("\n\n");
   for(i=0; i<sizeof(ranger_names); i++){
      write(justify(ranger_names[i],12));
      write(justify(ranger_types[i],9));
      write(justify(ranger_colors[i],10));
      write(justify(ranger_levels[i],7));
      write(justify(ranger_dinos[i],18));
      write(justify(ranger_animals[i],15));
      write("\n");
   }
   return 1;
}
update_ranger_roster(){
   int i;
   if(member_array(CAPNAME, ranger_names) == -1){
      if(CAPNAME == "some mist"){ return; }
      ranger_names += ({ CAPNAME });
      ranger_types += ({ "Initiate" });
      ranger_colors += ({ COMM->COLOR });
      ranger_levels += ({ "None" });
      ranger_animals += ({ COMM->ANIMAL });
      ranger_dinos += ({ COMM->DINO });
      ranger_time += ({ time() });
      save_globe();
      return 1;
   }
   for(i=0; i<sizeof(ranger_names); i++){
      if(ranger_names[i] == CAPNAME){
         if(TP->GLEVEL < 80) ranger_types[i] = "Space";
         if(TP->GLEVEL < 70) ranger_types[i] = "Rescue";
         if(TP->GLEVEL < 60) ranger_types[i] = "Turbo";
         if(TP->GLEVEL < 50) ranger_types[i] = "Zeo";
         if(TP->GLEVEL < 40) ranger_types[i] = "Ninja";
         if(TP->GLEVEL < 30) ranger_types[i] = "Thunder";
         if(TP->GLEVEL < 20) ranger_types[i] = "Dino";
         if(TP->GLEVEL < 10) ranger_types[i] = "Initiate";
         ranger_colors[i] = COMM->COLOR;
         if(COMM->KARATE == 0) ranger_levels[i] = "None";
         if(COMM->KARATE == 1) ranger_levels[i] = "White";
         if(COMM->KARATE == 2) ranger_levels[i] = "Yellow";
         if(COMM->KARATE == 3) ranger_levels[i] = "Orange";
         if(COMM->KARATE == 4) ranger_levels[i] = "Red";
         if(COMM->KARATE == 5) ranger_levels[i] = "Green";
         if(COMM->KARATE == 6) ranger_levels[i] = "Blue";
         if(COMM->KARATE == 7) ranger_levels[i] = "Purple";
         if(COMM->KARATE == 8) ranger_levels[i] = "Brown";
         if(COMM->KARATE >= 9) ranger_levels[i] = "Black";
         if(CAPNAME == "Beck") ranger_levels[i] = "Gold";
         ranger_animals[i] = COMM->ANIMAL;
         ranger_dinos[i] = COMM->DINO;
         ranger_time[i] = time();
         save_globe();
       }
   }
   return 1;
}
