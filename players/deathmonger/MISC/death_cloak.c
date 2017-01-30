
id(str){ return str == "cloak"; }
short(){ return "Cloak of the Vice Inquisitioner (worn)"; }
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
     say("Deathmonger lashes "+capitalize(str)+" with a whip!\n");
     write("You lash "+capitalize(str)+" with a whip!\n");
     tell_object(victim, "Deathmonger lashes you with a whip!\n");
     return 1;
}

beat(str){
     object victim;
     victim = present(str, environment(this_player()));
     if(!victim){
       write("Beat who?\n");
}

say("Deathmonger beats "+capitalize(str)+" to a pulp with a club!\n");
write("You beat "+capitalize(str)+" to a pulp with a club!\n");
tell_object(victim, 
"Deathmonger beats you to a pulp with a club!\n");
return 1;
}

sear(str){
     object victim;
     victim = present(str, environment(this_player()));
     if(!victim){
     write("Sear who?\n");
      }
write("You sear "+capitalize(str)+"'s tender skin with a white-hot iron!\n");
say("Deathmonger sears "+capitalize(str)+"'s skin with a glowing iron!\n");
tell_object(victim,
"Deathmonger sears you with a glowing, white-hot branding iron!\n");
return 1;
}
