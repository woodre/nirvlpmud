UnmorphRanger(){
   if(!COMM){
      write("Only a Power Ranger is allowed to unmorph.\n");
      return 1;
   }
   if(!COMM->QMorphed() && !COMM->QNinja()){
      return 0;
   }
   write("You return to your boring, everyday self.\n");
   this_player()->set_title(COMM->QOldTitle());
   this_player()->set_pretitle(COMM->QOldPretitle());
   present("soul",TP)->setmin("arrives");
   present("soul",TP)->setmout("leaves");
   if(COMM->QZord()){
      command("release",TP);
   }
   if(COMM->QHelmetLamp()){
      COMM->SHelmetLamp();
      COMM->set_arm_light(-2);
   }
   if(COMM->QPowerWeapon()){
      COMM->PowerWeapon();
   }
   if(COMM->QMetallicArmor()){
      COMM->MetallicArmor();
   }
   if(COMM->QMorphed()){
      COMM->SMorphed();
   }
   if(COMM->QNinja()){
      COMM->SNinja();
   }
   return 1;
}
