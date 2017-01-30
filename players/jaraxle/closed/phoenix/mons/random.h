get_random_mob(){
   switch(random(15)){
      case 0:
      add_object("/players/jaraxle/closed/phoenix/mons/berzerker.c"); 
      break;
      case 1:
      add_object("/players/jaraxle/closed/phoenix/mons/fox.c"); 
      break;
      case 2:
      add_object("/players/jaraxle/closed/phoenix/mons/fox.c",1); 
      break;
      case 3:
      add_object("/players/jaraxle/closed/phoenix/mons/berzerker.c",1); 
      break;
      case 4:
      add_object("/players/jaraxle/closed/phoenix/mons/hunter.c",1); 
      break;
      case 5:
      add_object("/players/jaraxle/closed/phoenix/mons/hunter.c",1); 
      break;

      case 6:
      add_object("/players/jaraxle/closed/phoenix/mons/fox.c",1); 
      add_object("/players/jaraxle/closed/phoenix/mons/hunter.c"); 
      break;
      case 7:
      add_object("/players/jaraxle/closed/phoenix/mons/berzerker.c"); 
      add_object("/players/jaraxle/closed/phoenix/mons/hunter.c", 1); 
      break;
      case 8:
      add_object("/players/jaraxle/closed/phoenix/mons/fox.c"); 
      add_object("/players/jaraxle/closed/phoenix/mons/hunter.c",1); 
      break;
      case 9..11:
      return 0;
      break;
      case 12:
      add_object("/players/jaraxle/closed/phoenix/mons/berzerker.c"); 
      add_object("/players/jaraxle/closed/phoenix/mons/fox.c"); 
      break;
      case 13:
      add_object("/players/jaraxle/closed/phoenix/mons/berzerker.c",1); 
      add_object("/players/jaraxle/closed/phoenix/mons/fox.c"); 
      break;
      case 14:
      add_object("/players/jaraxle/closed/phoenix/mons/berzerker.c",2); 
      break;
   }
   switch(random(15)){
      case 0..9:
      return 0;
      break;
      case 10..12:
      add_object("/players/jaraxle/closed/phoenix/mons/mage.c");
      break;
      case 14:
      add_object("/players/jaraxle/closed/phoenix/mons/knight.c");
      break;
   }
}
