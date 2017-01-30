get(){return 1;}
query_value(){return 0;}
short(){return "A Radio Headset";}
long(){write("This cyber-device allows to you eavesdrop on the conversations of all\n"+
"of the other guilds out there.  Use it wisely.\n");
return 1;}
id(str){return str=="headset"||str=="radio";}
init(){
add_action("tune","tune");
}
tune(str){
if (!present("1",environment(this_object()))){
write("You tune in to the other guilds out there.\n");
move_object(clone_object("/players/heroin/closed/listen2.c"), this_player());
return 1;}
write("You turn off your eavesdropping device\n");
command("999",this_player());
return 1;
}
