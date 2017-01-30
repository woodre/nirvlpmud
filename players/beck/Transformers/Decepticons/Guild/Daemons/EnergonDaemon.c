#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Defs.h"

object *Decepticons;
ADecepticon(object ob){
   if(!Decepticons)
      Decepticons = ({});
   if(member_array(ob, Decepticons) == -1)
      Decepticons += ({ ob });
/*
   call_out("HB",10);
*/
}

/*
HB(){
   int i;
   int j;
   int exp;
   int energon;
   object base;
   object *structures;
   for(i=0; i<sizeof(Decepticons); i++){
      if(!Decepticons[i])
         Decepticons -= Decepticons[i];
      else{
         energon = Decepticons[i]->QEnegron();
         if(Decepticons[i]->QBase()){
            base = BASEDAEMON->QCurrBase(ENV(Decepticons[i])->RNAME);
            energon += base->QEnergon();
            structures = base->QStructures();
            for (j=0; j<sizeof(structures); j++){
               energon += structures[j]->QEnergon();
            }
         }
      }
      exp = ENV(Decepticons[i])->query_exp();
      exp = energon - exp;
      ENV(Decepticons[i])->add_exp(exp);
      tell_object(ENV(Decepticons[i]), RED+"You have changed your exp by "+exp+OFF+"\n");
   }
   call_out("HB",1000);
}
*/
            
            
   
