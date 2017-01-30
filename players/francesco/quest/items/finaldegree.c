#include "/players/francesco/univ/ansi.h"
#define tpn this_player()->query_name()
/*inherit "obj/treasure.c";*/
object dude;

reset(arg)
{
    if(arg) return;

dude=this_player();
if(dude) {call_out("healing",50);}

}

get() {return 0;}
drop() { return 1;}

/* short() { return "A Diploma in Mechanical Engineering"; } */

long(str) {
    write("             "+HIC+environment(this_object())->query_name()+NORM+HIW+"\nGraduated in Mechanical Engineering\n"+
          "Proud Alumnus of Nirvana University"+NORM+"\n");
	return;
    }
    

id(str) { return str == "small pin" || str == "pin" || str == "mechengrdpt" ; }

query_weight() { return 0; }

query_auto_load(){return "/players/francesco/quest/items/finaldegree.c:";}

extra_look() {
   if(this_player() == environment()) write("You have a pin on your clothes.\n"); 
else
   write(environment()->query_name()+" has a pin on "+possessive(environment())+" clothes.\n");
}

healing() {
int a;
 a=random(2);
    if(!a) {dude->add_hit_point(1);dude->add_spell_point(1);
  if (environment())  /* Rumplemintz */
   tell_object(environment(),"\n");}
/*
    tell_object(environment(),"Remembering the time of graduation.....\n");}
*/
 call_out("healing",50);
return 1;
}

/*
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
*/
