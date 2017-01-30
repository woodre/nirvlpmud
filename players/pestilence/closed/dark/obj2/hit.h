hit(str){
    int dam;
    object ob, att;
    string bash_mess1;
    string bash_mess2;
    dam = 5 + random(10);
    if(environment() != this_player()) return;  
    if (!str && !USER->query_attack()){
        write("Punch who???\n");
        return 1;
    }
        else if(!str && USER->query_attack()){
                att = USER->query_attack();
        }

    else{ 
                att = present(str, environment(USER)); 
        }
    if(USER->query_spell_dam()) return 1;
    if (!att){ 
        write("There is no "+str+" here to punch"); 
        return 1; 
    }
    if(USER->query_sp() < 10){
        write("You do not have the spell points available for this spell.\n");
        return 1; 
    }
switch(dam){
case 35..100:
bash_mess1 = ""+HIR+"O B L I T E R A T E"+NORM+"";
bash_mess2 = ""+HIR+"O B L I T E R A T E S"+NORM+"";
break;
case 25..34:
bash_mess1 = ""+HIR+"DEVASTATE"+NORM+"";
bash_mess2 = ""+HIR+"DEVASTATES"+NORM+"";
break;
case 12..24:
bash_mess1 = ""+HIK+"destroy"+NORM+"";
bash_mess2 = ""+HIK+"destroyed"+NORM+"";
break;
case 5..11:
bash_mess1 = "wound";
bash_mess2 = "wounds";
break;
case 1..4: 
bash_mess1 = "hurt";
bash_mess2 = "hurts";
break;
default:
bash_mess1 = "miss";
bash_mess2 = "misses";
break;
}
    write("You "+bash_mess1+" "+att->query_name()+" with a flurry of punches.\n");
    say(USER->query_name() +" hits "+att->query_name()+" with a flurry of punches.\n");
    USER->set_spell_dam(dam);
    USER->add_spell_point(-10);
    return 1;
}
