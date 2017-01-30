/*
 *  Mob.h
 *  Mob Misc Abilities
 */

mob_cmd(string str){
object *list;
int i;
string msg;
  if(!str || str == "") return mwho_cmd("mob");
  i=0;
  list=filter_array(users(), "filter_mob", this_object());
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