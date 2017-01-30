

/*  The Power Ranger Talk Channel   */


RangerTalk(string verb, string channel, string msg){
   object *rangers;
   int i;
   string format;
   rangers = Channels[channel];
   if(!msg){ 
      write("It is better to say something.\n");
      return 1;
   }
   format = BOLD+WHITE+"["+OFF+GREEN+channel+OFF+BOLD+WHITE+"] "+
   OFF+TPNAME;
   if(verb == "rt"){ format += " says:"; }
   format += " "+msg+"\n";
   for(i=0; i<sizeof(rangers); i++){
      if(rangers[i]){
         if(COMMR){
            if(!present("ranger_object",rangers[i])->QMuffles()){
               tell_object(rangers[i],format);
            }
         }
       }
   }
   return 1;
}
RangerMessage( string channel, string msg){
   object *rangers;
   int i;
   string format;
   rangers = Channels[channel];
   if(!msg){ 
      write("It is better to say something.\n");
      return 1;
   }
   format = BOLD+WHITE+"["+OFF+GREEN+channel+OFF+BOLD+WHITE+"] "+
   OFF+"";
   format += ""+msg+"\n";
   for(i=0; i<sizeof(rangers); i++){
      if(rangers[i]){
         if(COMMR){
            if(!present("ranger_object",rangers[i])->QMuffles()){
               tell_object(rangers[i],format);
            }
         }
       }
   }
   return 1;
}
