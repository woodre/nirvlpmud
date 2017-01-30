enemy(){
        int i;
        int b;
        int namer;
        int gspacer;
        int guilder;
        int spacer;
        object *plist;
        if(USER->query_ghost()) return 0;

        plist = users();
        write(
                "             >--<  "+YEL+"Possible Army Enemies"+NORM+"  >--<"+NORM+"\n\n"+
                ""+HIC+"Player"+NORM+HIW+":         "+HIC+"Guild"+NORM+HIW+":"+
        "        "+HIC+"Location"+HIW+":"+NORM+"\n\n");
        
        for(i=0; i<sizeof(plist); i++){
                if(plist[i]->query_invis() && plist[i]->query_level() >= USER->query_level()) continue;
                if(plist[i]->query_level() < 20){
                        if(plist[i]->query_pl_k() || plist[i]->query_fight_area()){
                                namer = strlen(plist[i]->query_name());
                                spacer = 14 - namer;
                                write(
                                HIK+plist[i]->query_name()+""+NORM);
                                for(b=0;b<spacer;b++) {
                                        write(" ");
                                }
                                if(plist[i]->query_guild_name()){
                                        guilder = strlen(plist[i]->query_guild_name());
                                        gspacer = 16 - guilder;
                                        write(
                                        WHT+plist[i]->query_guild_name()+NORM+"");
                                }
                                else{
                                        gspacer = 12;
                                        write(HIB+"none"+NORM);
                                }
                                for(b=0;b<gspacer;b++) {
                                        write(" ");
                                }
                                if(environment(plist[i])){
                                        write(environment(plist[i])->short()+"\n");
                                }
                                else{
                                        write("Unknown Location\n");
                                }
                        }
                }
        }
        write("\n"+YEL+">---------------------------------------------------------<"+NORM+"\n");
        return 1;
}
