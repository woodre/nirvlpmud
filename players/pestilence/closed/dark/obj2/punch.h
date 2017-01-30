punch(str){
   int dam, str_bonus;
    object ob, att;
    str_bonus = present("dknight_ob",this_player())->query_combat();
   dam = (1+ str_bonus)/2 +random(10);
    if(environment() != this_player()) return;  
    if (!USER->query_attack()){
        write("You must be fighting to punch someone.\n");
        return 1;
    }
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
    write("You hit "+att->query_name()+" with a flurry of punches.\n");
    say(USER->query_name() +" hits "+att->query_name()+" with a flurry of punches.\n");
    dam *= 90; dam /= 100;
    USER->set_spell_dam(dam);
    USER->set_spell_dtype("other|evil");
    USER->add_spell_point(-10);
if(USER->query_real_name() == "pestilence") tell_object(USER, "TOTAL IS: "+dam+" and your combat is "+str_bonus+".\n");
    return 1;
}
