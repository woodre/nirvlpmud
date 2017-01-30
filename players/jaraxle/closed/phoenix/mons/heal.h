get_random_heals(){
   switch(random(14)){
      case 0..2:
      MOCO("/players/jaraxle/closed/phoenix/heals/drink.c"), TO);
      break;
      case 3..5:
      MOCO("/players/jaraxle/closed/phoenix/heals/food.c"), TO);
      break;
      case 6..7:
      MOCO("/players/jaraxle/closed/phoenix/heals/drink.c"), TO);
      MOCO("/players/jaraxle/closed/phoenix/heals/drink.c"), TO);
      break;
      case 8..9:
      MOCO("/players/jaraxle/closed/phoenix/heals/food.c"), TO);
      MOCO("/players/jaraxle/closed/phoenix/heals/food.c"), TO);
      break;
      case 10..12:
      return 0;
      break;
      case 13:
      MOCO("/players/jaraxle/closed/phoenix/heals/food.c"), TO);
      MOCO("/players/jaraxle/closed/phoenix/heals/drink.c"), TO);
      break;
      case 14:
      MOCO("/players/jaraxle/closed/phoenix/heals/drink.c"), TO);
      MOCO("/players/jaraxle/closed/phoenix/heals/drink.c"), TO);
      MOCO("/players/jaraxle/closed/phoenix/heals/food.c"), TO);
      MOCO("/players/jaraxle/closed/phoenix/heals/food.c"), TO);
      break;
   }
   switch(random(15)){
      case 0..13:
      return 0;
      break;
      case 14:
      MOCO("/players/jaraxle/closed/phoenix/heals/regen.c"), TO);
      break;
   }
}
