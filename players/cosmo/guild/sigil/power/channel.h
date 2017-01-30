#define HIST "/obj/user/chistory.c"
#define SYM "["+QMI("color")+"*"+NORM+"] "

channel_cmd(string str){
object *list;
int i;
string msg;
  if(!str || str == "") return gwho_cmd("sigil");
  if(str == "history") {
    write(HIST->query_history("Sigil")+"\n");
    return 1;
  }
  i=0;
  list=filter_array(users(), "filter_sigil", this_object());
  if(str[0]==58)    /* Emote */
     msg = SYM+QMI("color")+TPN+NORM+" "+str[1..strlen(str)]+"\n";
  else              /* Chat */
     msg = SYM+QMI("color")+TPN+NORM+": "+str+"\n";
  while(i<sizeof(list)){
     /* Add a check for muffled flag once implemented */
     tell_object(list[i], msg);
     i++;
  }
  HIST->add_history("Sigil", msg);
  return 1;
}
