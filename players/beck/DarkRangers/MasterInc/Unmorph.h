UnmorphRanger(){
   if(!COMM){
      write("Only a Power Ranger is allowed to unmorph.\n");
      return 1;
   }
   if(!PO->QMorphed() && !PO->QNinja()){
      return 0;
   }
   write("You return to your boring, everyday self.\n");
   this_player()->set_title(PO->QOldTitle());
   this_player()->set_pretitle(PO->QOldPretitle());
   if(PO->QZord()){
      command("release",TP);
   }
   if(PO->QHelmetLamp()){
      PO->SHelmetLamp();
   }
   if(PO->QPowerWeapon()){
      PO->PowerWeapon();
   }
   if(PO->QMetallicArmor()){
      PO->MetallicArmor();
   }
   if(PO->QMorphed()){
      PO->SMorphed();
   }
   if(PO->QNinja()){
      PO->SNinja();
   }
   return 1;
}
