inherit "obj/treasure";

int used;

void reset(int arg){
    if(arg) return;
    ::reset(arg);
    set_short("A Big Glove");
    set_long("This is the Smacking glove.\n"+
      "It looks like you could reach out and smack someone.\n");
    set_value(150);
    set_name("glove");
    set_alias("big glove");
}

status hit(string str){
    if(!find_player(str)){
	write("That player is not logged in.\n");
	return 1;
    }
    if(used > 15){
	write("Your glove has shrunk.\n");
	return 1;
    }
    if(find_player(str)->query_level() > 20){
	write("The glove has no effect on wizards.\n");
	return 1;
    }
    used++;
    tell_room(environment(find_player(str)), "You see "+this_player()->query_name()+
      " cock back "+this_player()->query_possessive()+" arm and smack "+
      find_player(str)->query_name()+" across the face!\n");
    tell_object(find_player(str), "Wow, what a mark that's gonna leave!\n");
    write("You just smacked "+find_player(str)->query_name()+" across the face.\n");
    if(used > 15) write("Your glove just shrunk, it's of no use now.\n");
    return 1;
}

void init(){
    add_action("hit", "smack");
}
