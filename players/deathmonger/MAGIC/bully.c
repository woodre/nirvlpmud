
id(str){  return str == "inspector"; }
short(){ return "A building inspector"; }
long(){
write("NOTE TO WIZARDS: This has been placed here for a reason.\n");
write("DO NOT DEST THIS in order to open the castle.\n");

}
init(){
     add_action("up","join");
     add_action("up", "enter");
     add_action("up","info");
     add_action("kill","kill");
}

up(){
     write("The building inspector blocks your way.  He says,\n");
     write("Sorry, this castle is under repair. Try again soon.\n");
     return 1;
}

kill(){
     write("The building inspector says, Hey, don't blame me! Blame\n");
     write("Catt!\n");
     return 1;
}
