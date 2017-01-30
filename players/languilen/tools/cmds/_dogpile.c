cmd_dogpile(str){
     int i,count;
     object *dogs;

     if(!find_player(str)){
        write("Can't find "+str+".\n");
        return 1;
     }
     count=0;
     dogs=filter_objects(users(),"valid_dog",this_object());
     dogs-=find_player(str);
     i = sizeof(dogs);
     if(i<3){
        write("You need more people to dog pile someone.\n");
        return 1;
     }
     --i;
     emit_channel("junk", "Someone yells: Dog pile on "+capitalize(str)+"!!!\n");
     emit_channel("junk", dogs[i]->query_name()+" leaps upon "+capitalize(str)+".\n");
     dogs-=dogs[i];

     while(sizeof(dogs)>1 && count<5){
           i=random(sizeof(dogs));
           emit_channel("junk", dogs[i]->query_name()+dog_msg()+" "+capitalize(str)+".\n");
           dogs-=dogs[i];
           count++;
     }
     emit_channel("junk", dogs[0]->query_name()+" completely squashes "+capitalize(str)+".\n");
     return 1;
}

valid_dog(object ob){
     if(ob->query_level()>19 || ob->query_invis()) return 0;
     if(ob->query_name()=="logon" || ob->query_real_name()=="logon") return 0;
     return 1;
}

string dog_msg(){
     string msg;
     switch(random(8)){
           case 0: msg=" does a backflip onto"; break;
           case 1: msg=" jumps high into the air and belly-flops on"; break;
           case 2: msg=" does a double flip and lands on"; break;
           case 3: msg=" leaps upon"; break;
           case 4: msg=" pounces onto"; break;
           case 5: msg=" does a beautiful swan dive... right onto"; break;
           case 6: msg=" very gracefully, cannonballs on"; break;
           case 7: msg=" does a flying clothes-line tackle on"; break;
     }
     return msg;
}

