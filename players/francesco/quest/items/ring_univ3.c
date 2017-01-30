#include "/players/francesco/univ/ansi.h"
#define tpn this_player()->query_name()
inherit "obj/armor";

string name;

reset(arg) {
 if(arg) return;
 ::reset();
 set_name("ring");
 set_short("An engraved ring");
 set_long(
   "The ring has some engravings on it to 'read'.\n"+
   "It is made by shining steel.\n");
set_value(300);
set_ac(1);
set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
call_out("ringheal", 30);
}

id(str){ return str == "ring" || str == "engraved ring" ; }

init(){
  add_action("read","read");
  add_action("wear","wear");
  ::init();
}

ringheal(){
   if(worn && environment() && random(3)){
   environment()->heal_self(random(6)+1);
   tell_object(environment(),""+HIC+"Some heat rises up from your ring and invigorates your body."+NORM+"\n");
   }
  call_out("ringheal", 30);
}

read(str){
   if(!str) {notify_fail("What do you want to read?\n"); return 1;}
   if(str=="engravings")  {
       write("The engravings read: Alumnus of Nirvana University.\n"+
             "Graduated in Mechanical Engineering."+name+"\n");
       return 1;}
   notify_fail("You cannot read "+str+".\n");
   return 0;
}

wear(str) {
string *all;
int a, sa;
  if(!str) {notify_fail("Wear what?\n"); return 0;} 
  if(!id(str) || environment() != this_player() || worn) return 0;  
  if(str=="ring"){
    all = explode(read_file("/players/francesco/quest/log/solvers"), "\n");
    sa = sizeof(all);
    for(a = 0; a < sa ; a++ ) 
     {write (a+" "+all[a]+"\n");
      if(tpn == all[a]){
      write("ok\n");
      ::wear(str);
      return 1; }
     }
     notify_fail("Where did you steal/get/rob this ring???\n"); 
  return 0;}
  notify_fail("You cannot wear the "+str+".\n");
return 0;}
