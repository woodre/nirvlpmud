inherit "obj/living";
id(str){ return str == "van"; }

reset(arg){
   if(!arg){
   enable_commands();
}
}
short(){ return "A Salvation Army van"; }
long(){
    write("This is a Salvation Army van.  It collects donations from\n");
    write("higher level players and gives them to poor newbies.\n");
    write("If you have an item you'd like to donate, 'donate <item>'.\n");
    write("If you are a needy newbie, and you see an item you'd like to\n");
    write("have, 'beg for <item>'.\n");
}
can_put_and_get(str){
    return str != 0; }


init(){
     add_action("donate", "donate");
     add_action("beg", "beg");
     move();
}

donate(str){
     object donation;
     donation = present(str, this_player());
     if(!donation){
       write("You do not have that item in your inventory.\n");
       return 1;
     }
     move_object(donation, this_object());
     write("Thank you for your donation to the needy newbie cause. :)\n");
     write("The Salvation Army wishes you a nice day.\n");
     say(this_player()->query_name() +" donated a "+donation->short()+".\n");
     return 1;
}

beg(str){
     object thing;
     string blah;
     if(!sscanf(str, "for %s", blah)){
       write("Syntax:  beg for <item>\n");
       return 1;
     }
     thing = present(blah, this_object());
     if(!thing){
       write("There is no such thing in the van.\n");
       return 1;
     }
     if(this_player()->query_level() > 8){
       write("Arnold Schwartzeneggar emerges from the van and says:\n");
       write("'Dis is for de newbies.  Get your ass to Mars!'\n");
       write("You'd best do as he says.\n");
       return 1;
     }
     move_object(thing, this_player());
     write("You have successfully begged for a "+thing->short()+".\n");
     write("Your ego must have been hurt, though.\n");
     return 1;
}

move(){
   int i;
   i = random(3);
   if(i == 0){
     command("north");
   }
   if(i == 1){
     command("south");
   }
   if(i == 2){
     command("east");
   }
   if(i == 3){
     command("west");
   }
   call_out("move", 50);
   return 1;
}
