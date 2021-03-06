/* New command to show a more detailed Score */
Rsc(rtype){
   string karate;
   string type;
   int power;
   write("\n");
   write(TP->short()+"\n");
   if(PO->KARATE == 1){ karate = "White"; }
   else if(PO->KARATE == 2){ karate = "Yellow"; }
   else if(PO->KARATE == 3){ karate = "Orange"; }
   else if(PO->KARATE == 4){ karate = "Red"; }
   else if(PO->KARATE == 5){ karate = "Green"; }
   else if(PO->KARATE == 6){ karate = "Blue"; }
   else if(PO->KARATE == 7){ karate = "Purple"; }
   else if(PO->KARATE == 8){ karate = "Brown"; }
   else if(PO->KARATE == 9){ karate = "Black"; }
   else{ karate = "none"; }
   if(TP->GLEVEL > 69){ type = "Space"; }
   else if(TP->GLEVEL > 59){ type = "Rescue"; }
   else if(TP->GLEVEL > 49){ type = "Turbo"; }
   else if(TP->GLEVEL > 39){ type = "Zeo"; }
   else if(TP->GLEVEL > 29){ type = "Ninja"; }
   else if(TP->GLEVEL > 19){ type = "Thunder"; }
   else if(TP->GLEVEL > 9){ type = "Dino"; }
   else{ type = "Initiate"; }
   if(PO->QKarateDegree())
      karate += " <"+PO->QKarateDegree()+">";
   write("Ranger Type: "+type+"\t\tKarate Belt: "+karate+"\n");
   write("Level: "+TP->LEVEL+"\n");
   if(TP->query_extra_level() > 0)
      write("Extra Level: "+TP->query_extra_level()+"\n");
   write("Hit Points: "+TP->query_hp()+"/"+TP->query_mhp()+"\t\t"+
      "Spell Points: "+TP->query_sp()+"/"+TP->query_msp()+"\n");
   write("Coins: "+TP->query_money()+"\t\t\t"+
      "Experience: "+TP->EXP+"\n");
   write("Intox: "+TP->query_intoxination()*100/(TP->LEVEL+3)+"%\t");
   write("Stuffed: "+(TP->query_stuffed())*100/(TP->LEVEL*8)+"%\t");
   write("Soaked: "+(TP->query_soaked())*100/(TP->LEVEL*8)+"%\t");
   write("Infused: "+(TP->query_infuse())*100/(TP->LEVEL*8)+"%");
   write("\n");
   CheckPower(rtype);
   if(PO->QRangerPoints()){
      power = PO->QRangerPoints();
      if(QPowerPoints(rtype) < power)
         power = QPowerPoints(rtype);
      write("You may use at most "+power+" of the Power Points for Combat.\n");
   }
   if(TP->query_fight_area())
      write(BOLD+RED+"You are in a PK area."+OFF+"\n");
   if(PO->QSpam())
      write("Your Weapon messages are turned OFF.\n");
   if(PO->QAutoGen())
      write("Auto Generate set to "+PO->QAutoGenAmount()+" PP, when over "+PO->QAutoGenLimit()+" Spell Points.\n");
   if(PO->QRangerTactic())
      write("Ranger Tactics: "+capitalize(PO->QRangerTactic())+"\n");
   TP->show_age();
   return 1;
}

