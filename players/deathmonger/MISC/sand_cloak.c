
id(str){ return str == "cloak"; }
short(){ return "Cloak of the High Inquisitioner (worn)"; }
long(){
     write("atmosphere:\n");
     write("whip, beat, slam, stab, sear, scorch\n");
}

get() { return 1; }
init(){
     add_action("whip","whip");
     add_action("beat","beat");
     add_action("slam","slam");
     add_action("stab","stab");
     add_action("sear","sear");
     add_action("scorch","scorch");
}

whip(str){
     object victim;
     victim = present(str, environment(this_player()));
     if(!victim){
       write("Whip who?\n");
     }
     say("Sandman lashes "+capitalize(str)+" with a whip!\n");
     write("You lash "+capitalize(str)+" with a whip!\n");
     tell_object(victim, "Sandman lashes you with a whip!\n");
     return 1;
}
