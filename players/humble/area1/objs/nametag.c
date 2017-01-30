inherit "obj/armor";
#include "../defs.h"
#define USER environment(this_object())

     reset() {
    set_name(HIC+"Nametag"+NORM);
    set_alias("nametag");
    set_short(HIW+"Nametag"+NORM);
       set_long(
    "This is a quality nametag that displays the QFC employee's name so that you may best\n"+
    "be served and to create that warm neighborhood grocer type feel of comfort.\n");
    set_ac(0);
   set_type("extra");
    set_weight(0);
    set_value(100);
       }

     short(){
       string heh;
    heh = ""+HIW+"("+HIY+"";
           if(environment()){
    if(environment() && living(environment())) heh+= environment()->query_name()+NORM+HIW+")"+HIK+"Nametag"+NORM;
    else heh += "Blank"+NORM+HIW+")"+NORM+HIK+" Nametag"+NORM;
         if(worn) heh += " (worn)";
       return heh;
    }
}
