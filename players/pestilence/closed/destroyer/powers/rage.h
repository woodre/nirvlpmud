rage(str){
    int dam;
    object ob, att;
    string bash_mess1;
    string bash_mess12;
    string bash_mess2;
    dam = 10 + random(35);
    if(environment() != this_player()) return;
if(this_player()->query_guild_rank() < 7){ write("You can't use this skill yet.\n"); return 1; }
/*  
if(this_player()->query_guild_rank() < 4){ write("You can't use this skill yet.\n"); return 1; }
*/
    if (!USER->query_attack()){
        write("You must be fighting to use rage.\n");
        return 1;
    }
    if (!str && !USER->query_attack()){
        write("Unleash rage on who???\n");
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
        write("There is no "+str+" here to unleash rage upon.\n"); 
        return 1; 
    }
/*
    if(USER->query_sp() < 15){
write("You don't have enough sps to maintain use of this skill.\n");
        return 1;
    }
*/
    if(USER->query_hp() < 60){
        write("You are way too weak to use this skill.\n");
        return 1; 
    }
switch(dam){
case 39..100:
bash_mess1 = ""+HIR+"A N N I H I L A T E S"+NORM+"";
bash_mess12 = ""+HIR+"A N N I H I L A T E S"+NORM+"";
bash_mess2 = "with hardened rage.";
break;
case 32..38:
bash_mess1 = ""+HIR+"S M A S H E S"+NORM+"";
bash_mess12 = ""+HIR+"S M A S H E S"+NORM+"";
bash_mess2 = "with a fierce blow to the head.";
break;
case 21..31:
bash_mess1 = ""+HIK+"disrupts"+NORM+"";
bash_mess12 = ""+HIK+"disrupts"+NORM+"";
bash_mess2 = "with an unleashed rage.";
break;
case 14..20:
bash_mess1 = "wounds";
bash_mess12 = "wound";
bash_mess2 = "with a solid shoulder block.";
break;
case 1..13: 
bash_mess1 = "hurts";
bash_mess12 = "hurts";
bash_mess2 = "with a wild rampage.";
break;
default:
bash_mess1 = "misses";
bash_mess12 = "miss";
bash_mess2 = "with a blow to the head.";
break;
}
    write("You scream loudly!\nYou rush "+att->query_name()+" in a bloody rage!\nYour charge "+bash_mess12+" "+att->query_name()+" "+bash_mess2+"\n");
    say(USER->query_name() +" screams loudly!\n"+USER->query_name() +"'s charge "+bash_mess1+" "+att->query_name()+" "+bash_mess2+"\n");
    USER->set_spell_dam(dam);
    USER->add_hit_point(-30);
/*
    USER->add_spell_point(-15);
*/
    return 1;
}
