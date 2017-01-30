
RangerWho(string channel){
   object *rangers;
   int i;
   rangers = Rangers[channel];
   write("\n");
   write("============================ THE DARK RANGERS ==============================\n");
   write("\n");
   write(justify("Lvl",4)+justify("M",2)+justify("Name",15)+justify("Color",12)+justify("Btl?",5)+justify("Place",45));
   write("\n");
   write("\n");
   for( i = 0; i<sizeof(rangers); i++) {
      if(rangers[i]){
         if(!rangers[i]->query_invis()){
            write(justify(rangers[i]->is_player() ? rangers[i]->LEVEL : "??",4));
            if(COMMR)
               write(justify(COMMR->QMuffles() ? "*" : " ",2));
            else
               write(justify(" ",2));
            write(justify(rangers[i]->NAME,15));
            if(COMMR)
               write(justify(COMMR->COLOR ,12));
            else
               write(justify("Enemy",12));
            write(justify(rangers[i]->query_attack() ? "Yes" : "No",5));
            write(justify(environment(rangers[i])->short(),45));
            write("\n");
         }
       }
   }
   write("\n");
   write("=============================================================================\n");
   return 1;
}
