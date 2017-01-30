string OwnerName;
int Energon;
mixed *Enhancements;
mixed *Data;
static object *CurrEnhancements;
static object Config;
mapping DataHolder;

inherit "/players/beck/Transformers/Decepticons/Guild/Object/CombatFort.c";
#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Defs.h"

id(str){
   return str == "base" ||
   str == "decepticon_base";
}

query_invis(){ return 1; }

query_name(){ return "Base"; }

query_npc(){ return 1; }

short(){
   return "The Base of "+OwnerName;
}

long(){
   
   write("The base of "+OwnerName+"\n");
   return 1;
}

reset(){
   is_npc = 1;
   this_object()->RegisterWeapon(this_object(),({"physical",40,0}));
   enable_commands();
   SHitPoint(2000);
}

init(){
   ::init();
   if(environment()){
      if(present("decepticon_base 2", environment()))
         destruct(TO);
   }
   add_action("Enter","enter");
   if(present(TP, TO)){
      add_action("Monitor","monitor");
      add_action("Configure","configure");
      add_action("Exit","exit");
   }
}

SOwnerName(string str){
   OwnerName = str;
   save_object(SAVEDIR+"Base_"+OwnerName);
}

RestoreBase(string name){
   int i;
   int j;
   int k;
   object ob;
   restore_object(SAVEDIR+"Base_"+name);
   DataHolder = ([]);
   
   for(i=0; i<sizeof(Data); i++){
      DataHolder[Data[i]] = ({});
      j = Data[i+1];
      k = 0;
      while(k < j){
         DataHolder[Data[i]] += ({ Data[i+2+k] });
         k++;
       }
      i = i+j+1;
   }
   BASEDAEMON->ACurrBase(OwnerName, TO);
   set_living_name("Base_"+OwnerName);
   for( i=0; i<sizeof(Enhancements); i++){
      j = Enhancements[i+1];
      while(j){
         ob = clone_object(Enhancements[i+2]);
         ob->SBase(TO);
         ob->SName(Enhancements[i]+" "+j);
         move_object(ob, TO);
         ob->RestoreEnhancement();
         ACurrEnhancement(ob);
         j--;
       }
      i = i+2;
   }
   ENV(TO)->set_no_clean(1);
}

/* This is no Teleport for anyone except the owner */
realm(){
   if(TP->NAME != OwnerName)
      return "NT";
}

AEnhancement(string name, string path){
   int temp;
   if(!Enhancements)
      Enhancements = ({});
   temp = member_array(name, Enhancements);
   if(temp != -1)
      Enhancements[temp+1] += 1;
   else
      Enhancements += ({ name, 1, path });
   save_object(SAVEDIR+"Base_"+OwnerName);
}

QEnhancementNum(string name){
   int temp;
   if(!Enhancements)
      Enhancements = ({});
   temp = member_array(name, Enhancements);
   if(temp != -1)
      return Enhancements[temp+1];
   else 
      return 0;
}


ACurrEnhancement(object ob){
   int temp;
   if(!CurrEnhancements)
      CurrEnhancements = ({});
   temp = member_array(ob, CurrEnhancements);
   if(temp != -1)
      return;
   else
      CurrEnhancements += ({ ob });
}

QCurrEnhancement(string name){
   int i;
   for(i=0;i<sizeof(CurrEnhancements); i++){
      if(CurrEnhancements[i]->QName() == name)
         return CurrEnhancements[i];
   }
   return 0;
} 


AData(string name, mixed *data){
   int i;
   string *temp;
   int size;
   if(!Data)
      Data = ({});
   if(!DataHolder)
      DataHolder = ([]);
   DataHolder[name] = data;
   temp = keys(DataHolder);
   Data = ({});
   for(i=0;i<sizeof(temp);i++){
      Data+= ({ temp[i] });
      size = sizeof(DataHolder[temp[i]]);
      Data += ({ size });
      Data += DataHolder[temp[i]];
   }
   save_object(SAVEDIR+"Base_"+OwnerName);
}

QData(string name){
   if(!DataHolder)
      return 0;
   return DataHolder[name];
}

Enter(){
   if(TP->NAME != OwnerName)
      return 0;
   say(TP->NAME+" leaves into the Base.\n");
   move_object(TP,TO);
   tell_room(ENV(TP),TP->NAME+" enters the Base.\n");
   return 1;
}

Exit(){
   say(TP->NAME+" leaves the Base.\n");
   move_object(TP,ENV(TO));
   tell_room(ENV(TP),TP->NAME+" arrives from the Base.\n"); 
   return 1;
}

Monitor(str){
   int i;
   int num;
   if(!str){
write("Base\tEnergon: "+QEnergon("Base")+"\n");
      for (i=0; i<sizeof(CurrEnhancements); i++){
         write((i+1)+"\t");
write(pad(CurrEnhancements[i]->QName(),27));
         write(CurrEnhancements[i]->QOnline() ? BOLD+GREEN+"Online"+OFF : BOLD+RED+"Offline"+OFF);
write("\tEnergon: "+CurrEnhancements[i]->QEnergon()+"");
         write("\n");
      }
write("Total Energon: "+QEnergon()+"\n");
      return 1;
   }
   i = sizeof(CurrEnhancements);
   if(sscanf(str, "%df", num) !=1){
      write("Pick a number of an object to configure.\n");
      return 1;
   }
   if(num <= i){
      CurrEnhancements[num-1]->Monitor();
      return 1;
   }
   else {
      write("That is not a valid choice.\n");
      return 1;
   }
}

Configure(str){
   int i;
   int num;
   if(!str){
      write("Exiting Configuration Mode.\n");
      Config = 0;
      return 1;
   }
   if(!Config){
      i = sizeof(CurrEnhancements);
      if(sscanf(str, "%df", num) !=1){
         write("Pick a number of an object to configure.\n");
         return 1;
      }
      if(num <= i){
         Config = CurrEnhancements[num-1];
         write("Entering Configuration Mode for "+CurrEnhancements[num-1]->QName()+".\n");
         return 1;
      }
      else {
         write("That is not a valid choice.\n");
         return 1;
      }
   }
   else {
      return Config->Configure(str);
   }
}


AEnergon(int amt){
   Energon += amt;
   if(Energon > 10000)
      Energon = 10000;
}

QEnergon(arg){
   int i;
   int energon;
   if(arg)
      return Energon;
   energon = Energon;
   for(i=0;i<sizeof(CurrEnhancements);i++){
      energon += CurrEnhancements[i]->QEnergon();
   }
   return energon;
}
