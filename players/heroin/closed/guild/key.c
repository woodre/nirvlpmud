id(str){return str=="key";}
short() {return "A Computer Key";}
long() {
write("This appears to be a key of some sort.  It looks more like\n"+
"an access card really.  Hmmm, You think to yourself: Everything here\n"+
"is all old, I wonder what this key goes to?\n");
return 1;}
init() {
add_action("mother","mother");
add_action("location","location");
add_action("turn", "insert");
}
turn(){
object key;
write ("ERRROR......ERRORRR....BEEEP ....PROCESSSIN...PLEASE WAIT\n");
write ("...........LOADING INFORMATION....CREW :: 1 remaining...\n");
write (" LOADING....ELIMINATE TARGET.....PLEASE ENTER OPTION NOW.\n");
write("**********************MENU**************************\n");
write ("*   location                   crew location       *\n");
write ("*                                                  *\n");
write ("*   mother                     courses of action   *\n");
write ("*BEEP   EMERGENCY SHUT DOWN EMINENT **DANGER********\n");
write ("Well, at least you have two options..type <option>\n");
return 1;
}
location(){
write("CREW REMAINING = 1  LOCATION: CARGO BAYS\n");
return 1;
}
mother() {
write("ONE RECOMMENDED COURSE OF ACTION..> PUSH TARGET THROUGH\n");
write("HULL BREACH....PLEASE HOLD SCANNING....................\n");
write("GET LOADER...........\n");
return 1;
}

