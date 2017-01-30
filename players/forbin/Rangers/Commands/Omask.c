#include "/players/vital/closed/headers/bdefs.h"
#include "/players/vital/Rangers/RangerDefs.h"

string *Rangers;

QMax(){ return 1; }

RangerPower(){
   if(!Rangers)
      Rangers = ({});

   if(!(PO->QMorphed())){
      if(member_array(TPRNAME, Rangers) != -1)
         Rangers -= ({ TPRNAME });
      write("You can only use the Osmosis Mask when Morphed.\n");
      return 1;
   }

   if(member_array(TPRNAME, Rangers) < 0){
      write(BOLD+BLUE+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"+OFF+"\n");
      
      write(BOLD+RED+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"+OFF+"\n");
      
      write(BOLD+RED+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"+OFF+"\n");
      
      write(BOLD+BLUE+"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"+OFF+"\n");
     
      PO->AID("o_mask");
      Rangers += ({TPRNAME});
      return 1;
   }

   
   write("You turn Off your Osmosis Mask.\n");
   PO->RID("o_mask");
   Rangers -= ({ TPRNAME });
   return 1;
}

QRangerInfo(){ return 1; }

RangerInfo(){
   write("Similar to a respirator, the osmosis mask was designed\n"+ 
         "to help protect explorers in the distant region of the Flame\n"+
         "Forest. It attaches securly to a Power Ranger Helmet.\n"+
         "A filtering cartridge is attached around\n"+ 
         "the mouth and nose area.  Wide fabric bands are used to\n"+
         "attach the mask into place.\n"+
         "The mask does impare a rangers view somewhat though, so you may not\n"+
         "be able to see enemy attacks as easily.\n"+
         "");
   return 1;
}


DefSkill(int level){

   if(!Rangers)
      Rangers = ({});
   
   if(member_array(ENV(PO)->query_real_name(), Rangers) >= 0){
      return -2;
   }   
   else
      return 0;
}
