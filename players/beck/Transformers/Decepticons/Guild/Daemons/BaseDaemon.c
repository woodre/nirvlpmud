string *Bases;
static object *CurrBases;
#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Defs.h"

ACurrBase(string name, object base){
   if(!CurrBases)
      CurrBases = ({});
   if(member_array(name, CurrBases) == -1)
      CurrBases += ({ name, base });
   else
      return;
}
   
QCurrBase(string name){
   int temp;
   name = capitalize(name);
   temp = member_array(name, CurrBases);
   if(temp != -1)
      return CurrBases[temp+1];
   else
      return 0;
}

ABase(string OwnerName, string Room){
   if(!Bases)
      Bases = ({});
   if(member_array(OwnerName, Bases) != -1)
      return;
   Bases += ({ OwnerName, Room });
   save_object(SAVEDIR+"Bases");
}

DistributeBases(){
   int i;
   object base;
   restore_object(SAVEDIR+"Bases");
   for(i=0; i<sizeof(Bases); i++){
          base = clone_object(BASE);
          move_object(base, Bases[i+1]);
          base->RestoreBase(Bases[i]);
ENV(base)->set_no_clean(1);
     
      i = i+1;
   }
}
   
