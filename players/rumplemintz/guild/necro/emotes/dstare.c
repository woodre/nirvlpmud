int cmd(string str){
    object tar;
    if(!str){
	write("You furl your eyebrow and look around with cold dead eyes.\n");
	say(this_player()->query_name()+"'s eyebrow furls and "+this_player()->query_pronoun()+" looks around with cold dead eyes.\n");
	return 1;
    }
    tar = present(str, environment(this_player()));
    if(!tar){
	notify_fail(capitalize(str)+" is not here to stare at.\n");
	return 0;
    }
    if(living(tar)){
	write("You stare at "+tar->query_name()+" with cold dead eyes.\n");
	say(this_player()->query_name()+" stares at "+tar->query_name()+" with cold dead eyes.\n");
	return 1;
    }
    write("You stare at "+str+" with cold dead eyes.\n");
    say(this_player()->query_name()+" stares at "+str+" with cold dead eyes.\n");
    return 1;
}
