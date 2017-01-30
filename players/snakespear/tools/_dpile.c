#include "/players/snakespear/closed/ansi.h"
 
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
     emit_channel("junk", BOLD+BLK+"Someone yells: "+NORM+"Dog pile on "+BOLD+capitalize(str)+NORM+"!!!\n");
     emit_channel("junk", dogs[i]->query_name()+HIM+" leaps upon "+NORM+capitalize(str)+".\n");
     dogs-=dogs[i];

     while(sizeof(dogs)>1 && count<5){
           i=random(sizeof(dogs));
           emit_channel("junk", dogs[i]->query_name()+dog_msg()+" "+capitalize(str)+".\n");
           dogs-=dogs[i];
           count++;
     }
     emit_channel("junk", dogs[0]->query_name()+GRN+" completely squashes "+NORM+capitalize(str)+".\n");
     return 1;
}

valid_dog(object ob){
     if(ob->query_level()>19 || ob->query_invis()) return 0;
     if(ob->query_name()=="logon") return 0;
     return 1;
}

string dog_msg(){
     string msg;
     switch(random(8)){
           case 0: msg=RED+" does a backflip onto"+NORM; break;
           case 1: msg=CYN+" jumps high into the air and belly-flops on"+NORM; break;
           case 2: msg=BLU+" does a double flip and lands on"+NORM; break;
           case 3: msg=YEL+" leaps upon"+NORM; break;
           case 4: msg=GRN+" pounces onto"+NORM; break;
           case 5: msg=BOLD+BLK+" does a beautiful swan dive... right onto"+NORM; break;
           case 6: msg=BOLD+" very gracefully, cannonballs on"+NORM; break;
           case 7: msg=MAG+" does a flying clothes-line tackle on"+NORM; break;
     }
     return msg;
}
