 
id(str) {return str == "dispenser"|| str == "giver";}
short() {return "A finger giver";}
long() {write("This machine gives you a finger in which you can finger people.\n"+
              "You can push the button and see what happens.\n");return;}
get() {return 0;}
init () {
        add_action("push","push");
}
push(str) {
  if(!str || str!="button"){
        return 0;
}
if(str == "button"){
        move_object(clone_object("/players/mouzar/closed/finger.c"),this_player());
        say("There is a cry in the distance!\n");
	write("There is a cry in the distance!\n");
        write("You receive a finger from the giver.\n");
        say(capitalize(this_player()->query_real_name())+ " is given a finger.\n");
        return 1;
        }
}
 
