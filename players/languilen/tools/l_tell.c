#include "/players/languilen/closed/ansi.h"
#define TP this_player()
inherit "obj/treasure.c";

void t_update();

reset(arg){
    set_id("l_tell");
    set_long("This is a tell device.\nUsage: tell <target> <msg>\n\
You can also restore your 'old_info'\n");
}

drop(){ return 1; }
get(){ return 1;}
init () {
    if(!environment(this_object())){ destruct(this_object()); }
    write("L_tell loaded.\n"+NORM);
    add_action("renew_ltell","retell");
    if(this_player()->query_real_name() == "languilen"){
       add_action("ltt","tell");
       add_action("oldinfo","old_info");
    }
}

int ltt(string str){
    int x;
    string who,msg;
    object ob;

    x=random(5);

    if (!str){
       write("Usage: Tell <who> <what>\n");
       return 1;
    }
    while(!x) {
          x++;
          t_update();
    }
    sscanf(str,"%s %s",who,msg);
    if (!who && !msg){
       who = str;
    }
    if (!who){
       write("Who do you want to talk to?\n");
       return 1;
    }
    ob = find_player(who);
    if (!ob){ write("Player not found.\n");
       return 1;
    }

    if(!ob->query_interactive()){
       write("- disconnected -");
       return 1;
    }
    if(ob->query_interactive()){
       write("[ idle "+query_idle(ob)+"]\n");
    }
    if( ob->in_edit() ) {
       write("That player is editing...\n");
       return 1;
    }
    if(!msg) return 1;
    if(msg[0] == ':'){
       msg = msg[1..strlen(msg)];
       if(!msg){ return 1; }
       write("You emoteto "+ob->query_name()+" Languilen "+msg+"\n");
       tell_object(ob,HIB+"Languilen "+NORM+msg+"\n");
       return 1;
    }
    write("You tell "+ob->query_name()+": "+msg+"\n");
    tell_object(ob,HIB+"Languilen"+NORM+" tells you: "+msg+"\n");
    return 1;
}

void t_update(){
     int x;
     string mypretitle,mytitle,myaltitle,myguild;

     x=random(3);
     switch(x){
     case 0:  mypretitle="-Traveling beyond time and space-";
               mytitle=" -* "+HIB+"UNIVERSAL"+NORM+" *- ";
               myaltitle="immaterial";
               myguild="Traveler"; break;
     case 1:  mypretitle="The "+BOLD+BLK+"Mob"+NORM+" RULES!";
               mytitle=" Crime Boss       -Luccasi family-";
               myaltitle="brutal";
               myguild="Mobster"; break;
     case 2:  mypretitle="Author of |+ The Unfomercial +|";
               mytitle=" * Infomercial deprogrammer * ";
               myaltitle="intense";
               myguild="IDA"; break;
     default: mypretitle="'The Mob RULES!' says";
               mytitle=" Crime Boss       -Luccasi family-";
               myaltitle="brutal";
               myguild="Mobster"; break;
     }
     TP->set_pretitle(mypretitle);
     TP->set_title(mytitle);
     TP->set_al_title(myaltitle);
     TP->set_guild_name(myguild);
     TP->save_me();
}
int oldinfo(){
     TP->set_pretitle("|");
     TP->set_title("the Oblivious");
     TP->set_al_title("nominal to profile");
     TP->set_guild_name("cynic");
     TP->save_me();
     return 1;
}

int renew_ltell(){
    init();
    return 1;
}
