rush(str){
   int dam, str_bonus;
    object ob, att;
    str_bonus = USER->query_attrib("str");
    dam = (str_bonus);
    if(environment() != this_player()) return;  
    if(dam > 20){
        dam = 20;
    }
    if (!USER->query_attack()){
        write("You must be fighting to rush someone.\n");
        return 1;
    }
    if (!str && !USER->query_attack()){
        write("Rush who???\n");
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
        write("There is no "+str+" here to rush.\n"); 
        return 1; 
    }
    if(USER->query_sp() < 10){
        write("You do not have the energy available for this skill.\n");
        return 1; 
    }
    write("You rush "+att->query_name()+" with a solid shoulder charge.\n");
    say(USER->query_name() +" rushes "+att->query_name()+" with a solid shoulder charge.\n");
    USER->set_spell_dam(dam);
    USER->add_spell_point(-10);
if(USER->query_real_name() == "pestilence") tell_object(USER, "TOTAL IS: "+dam+" and your combat is "+str_bonus+".\n");
    return 1;
}
