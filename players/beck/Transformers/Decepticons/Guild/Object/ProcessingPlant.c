#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Guild/Object/Enhancement.h"
#include "/players/beck/Lib/Resource.c"
static int Pulse;
static int count;

id(str){
   return str == "processing plant";
}

RestoreEnhancement(){
   mixed *data;
   data = Base->QData(Name);
   if(data){
      Online = data[0];
      Energon = data[1];
      data -=({data[0],data[1]});
      AResource(data);
   }
   Online = 1;
}

Configure(str){
   object temp;
   string item;
   object ob;
mixed *data;
   int i;
   int energy;
   if(str == "online"){
      if(Online){
         write(Name+" is already Online.\n");
         return 1;
      }
      write(Name+" is Online.\n");
      SOnline(1);
   }
   else if(str == "offline"){
      if(!Online){
         write(Name+" is already Offline.\n");
         return 1;
         }
      write(Name+" is Offline.\n");
      SOnline(0);
   }
   if(sscanf(str,"energon %d",i) ==1){
      if(Base->QEnergon("base") > i){
         if(Energon + i > 1000){
            write("That amount would overload the "+Name+"\n");
            return 1;
         }
         Base->AEnergon(-i);
         AEnergon(i);
         write("Allocating "+i+" Energon for use with "+Name+"\n");
      }
      else{
         write("There is not that much Energon to allocate>\n");
         return 1;
      }
   }
   else if(sscanf(str,"process %s",item) == 1){
      if(!present(item,TP)){
         write("You do not have that to process.\n");
         return 1;
         }
      ob = present(item,TP);
      if(ob->QResources()){
         data = ob->QResources();
         for(i=0; i<sizeof(data); i++){
            energy += data[i+1];
            i = i+1;
         }
         if(Energon < energy){
            write("There is not enough Energon to process the item.\n");
            return 1;
         }
         move_object(ob,TO);
         write(capitalize(str)+" has been processed.\n");
         AEnergon(-energy);
         AResource(data);
         destruct(ob);
         }
      else{
         move_object(ob,TO);
         destruct(ob);
         write("The item had no resource material.\n");
         return 1;
      }
   }
   else {
      write("That is not a configuration option for "+Name+"\n");
      return 1;
   }
   data = ({});
   data += ({ Online, Energon });
   if(!QResources())
      Resources = ({});
   data += QResources();
   Base->AData(Name, data);
   return 1;
}

Monitor(){
   int i;
   int j;
   write(Name+"\n\n");
   write(Online ? BOLD+GREEN+"Online"+OFF : BOLD+RED+"Offline"+OFF);
   write("\n");
   MonitorResources();
   return 1;
}
