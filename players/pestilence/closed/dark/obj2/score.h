score(){
        write(""+HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM+"\n\t\t\t"+HIR+"D A R K  O R D E R"+NORM+"\n\n");
        write(""+HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM+"   Name: \n");
        if(USER->query_pretitle()) write(""+USER->query_pretitle()+" ");
        write(""+capitalize(USER->query_name())+" ");
        if(USER->query_title())write(""+USER->query_title()+" ");
        write("("+USER->query_al_title()+")\n   [Level: "+USER->query_level()+"+ "+USER->query_extra_level()+"]\n");
        write(BLU+"   HP"+NORM+BOLD+" ("+NORM+HIB+USER->query_hp()+NORM+BOLD+"/"+NORM+HIB+USER->query_mhp()+NORM+BOLD+")"+NORM+"\t\t");
        write(RED+"         SP"+NORM+BOLD+" ("+NORM+HIR+USER->query_sp()+NORM+BOLD+"/"+NORM+HIR+USER->query_msp()+NORM+BOLD+")"+NORM+"\t\n");

        write("   Experience ["+USER->query_exp()+"]                Coins ["+USER->query_money()+"]  \n");
        write("   Gxp : "+TP->query_guild_exp()+"\t\t         Glvl: "+TP->query_guild_rank()+"\n");
        write("   Combat Lvl:"+ present("dknight_ob",this_player())->query_combat()+"\n");
        write(
                "\t\tFood["+BOLD+USER->query_stuffed()*100/(USER->query_level()*8)+NORM+"%] "+
                " Soak["+BOLD+USER->query_soaked()*100/(USER->query_level()*8)+NORM+"%] "+
        " Intox["+BOLD+USER->query_intoxination()*100/(USER->query_level()+3)+NORM+"%]\n");
        if(USER->query_quest_point())
        write("   QPS        ["+USER->query_quest_point()+"]\n");
        USER->show_age(   ); 
          USER->check_fight_area();
        if(USER->query_fight_area()){
                write("   "+HIK+"PK Area"+NORM+"\n"+HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+NORM+"\n");
        }
        else{
                write("   "+HIY+"NON-PK Area"+NORM+" \n"+HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+NORM+"\n");
        }
        return 1;
}
