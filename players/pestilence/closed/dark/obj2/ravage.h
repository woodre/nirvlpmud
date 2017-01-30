ravage(str){
    int dam;
    object ob, att;
    string bash_mess1;
    string bash_mess12;
    string bash_mess2;
    dam = 5 + random(25);
    if(environment() != this_player()) return;  
if(this_player()->query_guild_rank() < 4){ write("You can't use this skill yet.\n"); return 1; }
    if (!USER->query_attack()){
        write("You must be fighting to use ravage.\n");
        return 1;
    }
    if (!str && !USER->query_attack()){
        write("Ravage who???\n");
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
        write("There is no "+str+" here to ravage.\n"); 
        return 1; 
    }
    if(USER->query_hp() < 60){
        write("You are way too weak to use this skill.\n");
        return 1; 
    }
switch(dam){
case 30..100:
bash_mess1 = ""+HIR+"O B L I T E R A T E S"+NORM+"";
bash_mess12 = ""+HIR+"O B L I T E R A T E"+NORM+"";
bash_mess2 = "with an insane attack.";
break;
case 23..29:
bash_mess1 = ""+HIR+"R A V A G E S"+NORM+"";
bash_mess12 = ""+HIR+"R A V A G E"+NORM+"";
bash_mess2 = "with an insanely "+HIR+"DEVASTATING"+NORM+" blow.";
break;
case 12..22:
bash_mess1 = ""+HIK+"destroys"+NORM+"";
bash_mess12 = ""+HIK+"destroy"+NORM+"";
bash_mess2 = "with a devestating blow, causing "+HIR+"blood"+NORM+" to flow freely.";
break;
case 5..11:
bash_mess1 = "wounds";
bash_mess12 = "wound";
bash_mess2 = "with a solid shoulder block.";
break;
case 1..4: 
bash_mess1 = "hurts";
bash_mess12 = "hurt";
bash_mess2 = "with a wild rampage.";
break;
default:
bash_mess1 = "misses";
bash_mess12 = "miss";
bash_mess2 = "with a blow to the head.";
break;
}
    write("You "+bash_mess12+" "+att->query_name()+" "+bash_mess2+"\n");
    say(USER->query_name() +" "+bash_mess1+" "+att->query_name()+" "+bash_mess2+"\n");
    dam *= 90; dam /= 100;
    USER->set_spell_dam(dam);
    USER->set_spell_dtype("other|evil");
    USER->add_hit_point(-20);
    return 1;
}
