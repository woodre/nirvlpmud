get_random_mob(){
   switch(random(19)){
      case 0:
      add_object("/players/jaraxle/3rd/alt/mobs/knight.c"); 
      break;
      case 1:
      add_object("/players/jaraxle/3rd/alt/mobs/vamp.c"); 
      break;
      case 2:
      add_object("/players/jaraxle/3rd/alt/mobs/cyber.c"); 
      break;
      case 3:
      add_object("/players/jaraxle/3rd/alt/mobs/fallen.c"); 
      break;
      case 4:
      add_object("/players/jaraxle/3rd/alt/mobs/knight.c"); 
      break;
      case 5:
      add_object("/players/jaraxle/3rd/alt/mobs/necro.c"); 
      break;
      case 6:
      add_object("/players/jaraxle/3rd/alt/mobs/symbiote.c"); 
      break;
      case 7:
      add_object("/players/jaraxle/3rd/alt/mobs/poly.c"); 
      break;
      case 8..18:
      return 0;
      break;
   }
}
