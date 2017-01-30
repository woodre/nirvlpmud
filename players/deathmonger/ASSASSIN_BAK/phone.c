/*  ASSASSIN HOTLINE PHONE   */

int call;
id(str) { return str == "phone"; }
short() {
     return "An Assassin Hotline phone";
}
long(){
     write("########## 'DIAL-AN-ASSASSIN' HOTLINE ##########\n");
     write("Need to get someone assassinated quick?  Need some help with\n");
     write("anything?  Use this assassin hotline and you can announce to \n");
     write("all assassins logged on what you would like to make a contract\n");
     write("for.  Presently, assassins are available to do the following \n");
     write("tasks:\n");
     write("1. ASSASSINATION--At a cost of 1000 gold coins/level of the\n");
     write("   player/monster, you can contract for an assassination.\n");
     write("2. Other tasks may be requested, and the price set by the \n");
     write("   who takes the job.\n");
     write("\n");
     write("Please keep in mind that this is a one-way telephone--all \n");
     write("assassins can hear you, but you can't hear them.  If one  \n");
     write("accepts the job, he/she will contact you.  Also, keep in mind\n");
     write("that assassins are under no obligation to accept your contract\n");
     write("if they don't want to do it.\n");
     write("\n");
     write("All payments must be in advance.  If you worry about assassins\n");
     write("taking your money and running, remember that they are faithful\n");
     write("to the contracts they make under penalty of death.  If you are\n");
     write("cheated by an assassin, write Deathmonger and it will be dealt\n");
     write("with.\n");
     write("There is a small sign with operating instructions.\n");
}
value() {return 0;}
get() { return 0;}
init(){
     add_action("call","call");
     add_action("hangup","hangup");
     add_action("talk","t");
     add_action("read","read");
}

read(str){
     if(str == "sign"){
       write("To get on the hotline, the command is 'call'\n");
     write("To hang up, the command is 'hangup'\n");
     write("(If you have problems calling, you may want to hang up and try again)\n");
     write("To talk on the line, the command is 't <message>'\n");
     return 1;
}
}

call(){
     if(call == 1){
       write("The phone is being used right now.\n");
       return 1;
     }
     if(call == 0){
       write("You pick up the phone and 'Dial-an-Assassin'.\n");
       call = 1;
     return 1;
}
     }
hangup(){
     if(call == 1){
     write("You hang up the phone.\n");
     call = 0;
     return 1;
     }
     if(call == 0){
     write("The phone already has been bung up.\n");
     return 1;
}
}
talk(str){
if(call = 1){
     object ob, guild, caller;
     string me;
     int i;
     caller = this_player();

     ob = users();
     for(i = 0; i < sizeof(ob); i++){
       guild = present("license", ob[i]);
     if(guild){
       tell_object(ob[i], this_player()->query_name()+" (hotline): "+str+"\n");
}
}
     write("You hotlined: "+str+"\n");
     return 1;
}
}
