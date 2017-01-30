RangerAnsi(str){
   if(!str){
      PO->SRangerAnsi(OFF);
      return 1;
   }
   if(str == "green")
      PO->SRangerAnsi(GREEN);
   else if(str == "bold green")
      PO->SRangerAnsi(BOLD+GREEN);
   else if(str == "blue")
      PO->SRangerAnsi(BLUE);
   else if(str == "bold blue")
      PO->SRangerAnsi(BOLD+BLUE);
   else if(str == "red")
      PO->SRangerAnsi(RED);
   else if(str == "bold red")
      PO->SRangerAnsi(BOLD+RED);
   else if(str == "white")
      PO->SRangerAnsi(BOLD);
   else{
      write("That is not a valid ANSI Color.\n");
      return 1;
   }
   write("Ansi Color set to "+str+"\n");
   return 1;
}