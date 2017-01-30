#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Defs.h"

DecepticonCommand(str){
   int i;
   mixed *form;
   string title;
   if(!str)
      form = ROBOT;
   if(member_array(str, PO->QForms()) != -1){
      write("You are unable to transform into that.\n");
      return 1;
   }
   if(str == "jet")
      form = JET;
   if(str == "tank")
      form = TANK;
   if(str == "robot")
      form = ROBOT;
   if(PO->QForm() == form[0]){
      write("You are already in that form.\n");
      return 1;
   }
   PO->SForm(form[0]);
   title = BS;
   for(i=0; i<strlen(TPNAME); i++){
      title += BS;
   }
   TP->set_title(title+form[1]);
   tell_room(ENV(TP), TPNAME+" transforms into a "+form[0]+"\n");
   return 1;
}
      