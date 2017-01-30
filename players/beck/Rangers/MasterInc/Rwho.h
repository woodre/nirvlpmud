
RangerWho(string channel){
   object *rangers;
   int i;
   rangers = Channels[channel];
   write("\n");
   write("============================ The "+channel+"s ==============================\n");
   write("\n");
   write(justify("Level",7)+justify("M",2)+justify("Name",15)+justify("Color",15)+justify("Btl?",5)+justify("Place",45));
   write("\n");
   write("\n");
   for( i = 0; i<sizeof(rangers); i++) {
      if(rangers[i]){
         if(!rangers[i]->query_invis()){
            write(justify(rangers[i]->is_player() ? rangers[i]->LEVEL : "?? ",3));
            if(rangers[i]->query_extra_level() > 0)
               write(justify(rangers[i]->is_player() ? "+"+rangers[i]->query_extra_level() : "  ",4));
            else
               write(justify("  ",4));
            if(COMMR)
               write(justify(COMMR->QMuffles() ? "*" : " ",2));
            else
               write(justify(" ",2));
            write(justify(rangers[i]->NAME,15));
            if(COMMR)
               write(justify(COMMR->COLOR ,15));
            else
               write(justify("Enemy",15));
            write(justify(rangers[i]->query_attack() ? "Yes" : "No",5));
            write(environment(rangers[i])->short());
            write(OFF);
            write("\n");
         }
       }
   }
   write("\n");
   write("=============================================================================\n");
   return 1;
}
