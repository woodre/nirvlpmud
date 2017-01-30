#define tp this_player()
#define tpp this_player()->query_possessive()
#define tpn this_player()->query_name()
#include "/players/francesco/univ/ansi.h"
inherit "obj/treasure.c";
object dude;
int x,play;


reset(arg){ if(arg) return; x=0;
  dude = this_player();}
short() { return "A Temporary University Diploma"; }
long(str) {
    write("This is a plain paper sheet which reports the results of your studies\n"+
          "in Mechanical Engineering, including the marks obtained in the single\n"+
          "subjects.  It allows you to 'graduate' in the final graduation ceremony\n"+
          "performed by the Dean of the Department.\n");
return;}

get() {return 0;}
drop(){return 1;}

init() {
    add_action("graduation","graduate");
}

id(str) { return str == "diploma" ; }

graduation(){
  if(!present("head",environment(tp))){
   notify_fail("The Dean is not present.  You cannot graduate.\n");  return 0; }
  if(play) { notify_fail("Shhhhhh, the ceremony is already in progress...\n"); return 0; }
/*  dude = this_player();*/
   write_file("/players/francesco/log/graduation",ctime(time())+"  "+tpn+"    [Level  "+tp->query_level()+"+"+tp->query_extra_level()+"]\n");  
  play = 1; 
  call_out("narrate",1);
return 1; }	

narrate(){
   narrate_it();
   x += 1;
  if(x<7) call_out("narrate",3);
   else { play = 0; x = 0; 
    call_out("give",5);}
   return 1; }

narrate_it(){
   string text;
   switch(x) {
   case 0: text = "\nThe Dean of the Department of Mechanical Engineering stands up.\n";
   break;
   case 1: text = "\nThe Dean of the Department of Mechanical Engineering clears his throat.\n";
   break;
   case 2: text = "\n'The degree in Mechanical Engineering is an important achievment that everyone\n"+
                  "should be proud of'\n";
   break;
   case 3: text = "\n'We are gathered here to aknowledge the efforts of "+call_other(dude,"query_name")+" during his studies.'\n";
   break;
   case 4: text = "\n'"+call_other(dude,"query_name")+" has worked hard to this goal'\n";
   break;
   case 5: text = "\n'On behalf of the Chancellor of the Nirvana University, I am delighted\n"+
                  "to deliver this degree to "+call_other(dude,"query_name")+" in recognition of his efforts'\n";
   break;
   case 6: text = "\nThe Dean of the Department of Mechanical Engineering hands "+call_other(dude,"query_name")+" a Diploma.\n\n";
   break;
   }
   tell_room(environment(dude),WHT+text+NORM);           
   return 1;}

give(){
   object ob;
/*dude = this_player();*/
/* 
   people();
   say(WHT+"The Dean of the Department of Mechanical Engineering shakes "+call_other(dude,"query_name")+"'s hand vigorously.\n\n"+NORM);
*/ 
   tell_object(dude,WHT+"The Dean of the Department of Mechanical Engineering shakes your hand vigorously.\n\n"+NORM);
/*   tell_room(environment(dude),WHT+"The Dean of the Department of Mechanical Engineering shakes "+dude->query_name()+"'s hand vigorously.\n\n"+NORM);
  */ ob = clone_object("/players/francesco/quest/items/finaldegree.c");
/*     write_file("/players/francesco/log/graduation", ctime(time())+"  "fran]\n");  


    write_file("/players/francesco/log/graduation", ctime(time())+"  "+dude->query_name()+
             "    [Level  "+dude->query_level()+"+"+dude->query_extra_level()+"]\n");  
*/
   dude->people();  
   move_object(ob,dude);
   destruct(this_object());
return 1;}

people(){
/*dude =this_player();*/
/*
      write_file("/players/francesco/log/graduation", ctime(time())+"  "+call_other(dude,"query_name")+
             "    [Level  "+call_other(dude,"query_level")+"+"+call_other(dude,"query_extra_level")+"]\n");  
*/
   say(WHT+"The Dean of the Department of Mechanical Engineering shakes "+call_other(dude,"query_name")+"'s hand vigorously.\n\n"+NORM);
return 1;}


