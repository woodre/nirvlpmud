/*
 *  Fam.h
 *  Mob Misc Abilities
 */

fam_cmd(string str){
     int i;
     string msg;
     object *list;

     if(!str || str == "") return mwho_cmd("fam");
     i=0;
     list=filter_array(users(), "filter_mob", this_object());
     list=filter_array(list, "filter_fam", this_object());
     if(str[0]==58)    /* Emote */
        msg = GUN+RED+TPN+NORM+HIW+" "+str[1..strlen(str)]+NORM+"\n";
     else              /* Chat */
        msg = RED+TPN+" "+NORM+GUN+HIW+str+NORM+"\n";
     while(i<sizeof(list)){
     /* Check for muffled flag */
     if(!present("MOB_OB", list[i])->query_muffle()){
        tell_object(list[i], msg);
     }
     i++;
  }

     return 1;
}
