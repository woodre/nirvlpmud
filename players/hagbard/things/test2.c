


query_auto_load() {

       return "/players/hagbard/things/test2:";
}




string vars;
object stores;
string query_list;

init(){
  if(call_other(this_player(),"query_real_name") == "hagbard"){
     add_action("true_inv");              add_verb("true");
     add_action("statue");    add_verb("statue");
     add_action("force_command");    add_verb("fc");
     add_action("check_invis");          add_verb("check");
     add_action("woman");         add_verb("babe");
      add_action("put_in_prison");       add_verb("imprison");
      add_action("add_e");             add_verb("adde");
     add_action("force_quit");           add_verb("fq");
     add_action("get_player");           add_verb("getpl");
      add_action("listen_room");         add_verb("listen");
     add_action("send_player");         add_verb("sendpl");
      add_action("stat");                  add_verb("stat1");
     add_action("remove_listen");       add_verb("unlisten");
     add_action("gag");                    add_verb("gag");
      add_action("ungag");                add_verb("ungag");
     add_action("list");                    add_verb("help");
     add_action("force_commandsil");  add_verb("fcs");
     add_action("grenade");               add_verb("tg");
     add_action("echo");           add_verb("echo");
  }
}

woman(){

     object babe;

     babe=clone_object("players/hagbard/things/playmate");
     call_other(babe,"set_name","sarah");
     move_object(babe,find_player("hagbard"));
}

reset(arg){

   if(arg)
     return;
     query_list = init_query();
}

echo(str){

     say(str + "\n");
     write("You echoed: " + str + "\n");
     return 1;
}



statue(str) {

    int len;
    string who, longdesc;
    object statue, sucker;
    
    if(sscanf(str,"%s",who) !=1)
      return 1;
   statue = clone_object("players/hagbard/things/thing");
   sucker = find_player(who);
   longdesc = "A statue of "+who;
   call_other(sucker, "set_pretitle", longdesc);
   call_other(sucker, "set_title", " ");
   call_other(statue, "set_who",who);
   move_object(statue, find_player(who));
    return 1;
}


add_e(str) {

      object ob;
      string who;
      int amount;


      if(sscanf(str,"%s %d",who, amount) != 2) 
        return;
  
      ob = find_player(who);
      if(!ob)
        return;
      call_other(ob,"add_exp",amount);
      return;
}



true_inv(){


      int i;
      object ob;
 
      i == 0;
      ob = first_inventory(find_player("hagbard"));
      while(ob){
           i += 1;
           write(i+ ":\t");
           write(ob);
           write("\t" + call_other(ob, "short") + "\n");
           ob = next_inventory(ob);
      }
      return 1;
}



listen_room(str){


     object ob;
     string where;

     if(sscanf(str, "%s", where) != 1)
       write("where.\n");
     ob = clone_object("players/hagbard/sponge");
     move_object(ob, where);
     return 1;
}




remove_listen(str){

     object ob;
     string where;


     if(sscanf(str, "%s", where) != 1)
       write("where.\n");
     ob = find_living("listen");
     destruct(ob);
     return 1;
}



put_in_prison(str){

    string who;

    if(sscanf(str, "%s", who) != 1)
      write("WHO!!!\n");
    if(!find_player(who))
      write(who + " is not playing now.\n");
    else{
    tell_object(find_player(who), "You have been imprisoned by Hagbard!\n");
    transfer(find_player(who), "players/hagbard/hagsprison");
    return 1;
    }
}




gag(str){

      string who;
      object ob;
      
      if(sscanf(str,"%s",who) != 1)
        write("Gag who.\n");
      if(find_player(who)){
       tell_object(find_player(who),"You have been gagged!\n");
       ob = clone_object("players/hagbard/silencer");
       move_object(ob, find_player(who));
       return 1;
      }
     if(!find_player(who))
      write(who + " is not playing now.\n");
}


grenade(str){

        string who;
        object ob;

        if(sscanf(str,"%s",who) != 1)
          return 1;
        if(!find_player(who)){
          write(who + " is not playing.\n");
          return 1;
        }
        ob=clone_object("players/hagbard/grenade");
        call_other(ob,"pull","pin");
        call_other(ob,"toss",who);
        return 1;
}



ungag(str){

     string who;
     object ob, person, next_ob;
    
    
     if(sscanf(str,"%s",who) != 1)
       write("Ungag who.\n");
     if(find_player(who)){
        person = find_player(who);
       ob = first_inventory(person);
           while(ob){
             next_ob = next_inventory(ob);
             if(call_other(ob, "id") == "silencer")
                destruct(ob);
                ob = next_ob;
           }
       tell_object(find_player(who),"You have been ungagged.\n");
       return 1;
     }
     if(!find_player(who))
          write("player is not on.\n");
      
}





stat(str){

      int i, tmp;
      object person;
      string who;

      if(sscanf(str,"%s",who) != 1)
        write("Who.\n");
      person = find_living(who);
      if(!person)
         write(who + " is not playing now.\n");
      if(person){
         write(person);  write(".\n");
         write(call_other(person,"short"));
         write("\n");
      if(tmp)
         write("Snooped by " + tmp->query_real_name() + ".\n");
      i = 0;
      while(i < sizeof(query_list)) {
           tmp = call_other(person, query_list[i]);
           if(tmp){
             string mes;
             mes = query_list[i] + ":";
             if(strlen(mes) < 8)
                mes += "\t\t";
              else if(strlen(mes) < 16)
                     mes += "\t";
              if(objectp(tmp))
                tmp = file_name(tmp);
              else if(pointerp(tmp))
                     tmp = "<ARRAY>";
             write(mes + "\t" + tmp + "\n");
           }
           i += 1;
      }
      }
      return 1;
}


get_player(str){


      string who;
 

      if(sscanf(str,"%s",who) != 1)
        write("Get who??\n");
      if(!find_living(who)){
        write(who + " is not playing now.\n");
        return 1;
      }
      move_object(find_living(who),environment(this_player()));
      return 1;
}





send_player(str){


    string who, where;
    
    if(sscanf(str,"%s %s", who, where) != 2){
      write("Send " + who + " " + where + ".\n");
      return 1;
     }
     if(!find_living(who)){
      write(who + " is not playing now.\n");
      return 1;
    }
    if(find_living(where)){
      move_object(find_living(who),environment(find_living(where)));
      return 1;
    }
    move_object(find_living(who),where);
    return 1;
}




check_invis(str){

    string who;
 
    if(sscanf(str,"%s",who) != 1)
      write("check who??\n");
    if(find_player(who)){
       if(call_other(find_player(who), "query_invis") > 0)
         write(who + " is invisible.\n");
    }
    if(!find_player(who))
      write(who + " is not on.\n");
    return 1;
}






force_command(str){

     object ob;
     string who, cmd, obj, cmd1;
     if(sscanf(str, "%s %s %s",cmd,obj,who) != 3){
       if(sscanf(str, "%s %s", cmd, who) != 2){
         return 0;}
       tell_object(find_player(who), "Hagbard just forced you to " + cmd);
       command(cmd, find_player(who));
        return "ok.\n";
      }
     if(sscanf(str, "%s %s %s",cmd,obj,who) == 3){
     cmd1 = cmd + " " + obj;
     tell_object(find_player(who), "Hagbard just forced you to " +cmd1);
     command(cmd1,find_player(who));
     return "ok.\n";
     }
}


force_commandsil(str){

     object ob;
     string who, cmd, obj, cmd1;
     if(sscanf(str, "%s %s %s",cmd,obj,who) != 3){
       if(sscanf(str, "%s %s", cmd, who) != 2){
         return 0;}
        command(cmd, find_player(who));
        return "ok.\n";
      }
     if(sscanf(str, "%s %s %s",cmd,obj,who) == 3){
     cmd1 = cmd + " " + obj;
     command(cmd1,find_player(who));
     return "ok.\n";
     }
}




force_quit(str){

   string who;
  
   if(sscanf(str, "%s", who) !=1)
     write("Who!\n");
   if(!find_player(who))
     write(who + " is not playing now.\n");
   command("quit", find_player(who));
}





id(str){

     return str == "calculator";
}


 short(){
     return "A Hewlett Packard 48SX calculator";
}


  

long(){
  
    write("An HP 48SX calculator.  This doesn't look like a ordinary HP\n");
    write("calculator though.  The buttons are labeled differently then\n");
    write("you would expect.\n");
}



get(){


  if(this_player() && this_player()->query_level() < 21)
     destruct(this_object());
     return 1;

}


  


init_query(){

    if(query_list)
      return query_list;
    query_list = ({
      "query_ac","query_alignment","query_attack","query_auto_load",
      "query_code","query_create_room","query_dir","query_exp",
      "query_frog","query_ghost","query_hit_point","query_hp",
      "query_info","query_intoxination","query_stuffed",
      "query_soaked","query_level","query_listening","query_max_weight",
      "query_money","query_name","query_npc","query_race",
      "query_real_name","query_spell_point","query_title",
      "query_type","query_value","query_wc","query_weight",
      "query_wimpy","query_worn","weapon_class","armor_class",
      "query_age","query_gender_string",
     });
     return query_list;
}


list(str){

      string bogus;

      if(str == "calculator")
       {
         write("--------------------------------------------------------------------------------\n");
         write("fcs cmd obj who                            force command silently\n");
         write("fc cmd obj who                             force command\n");
         write("fq who                                    force quit.\n");
         write("stat1 who                                 alternate stat.\n");
         write("gag who                                   gag player.\n");
         write("ungag who                                 ungag player.\n");
         write("listen room/who                                  listen to person/room.\n");
         write("unlisten room/who                          remove listening device.\n");
         write("check who                                   check for invisible player.\n");
         write("getpl who                                    get player/monster.\n");
         write("sendpl who where                             send player/monster to where.\n");
         write("imprison who                                put who in my prison.\n");
         write("true                                        check inventory for invis objects.\n");
         write("tg who                                       toss grenade at person.\n");
         write("echo str                                echo str with out your name.\n");
          return 1;
     }
    return 0;
}

