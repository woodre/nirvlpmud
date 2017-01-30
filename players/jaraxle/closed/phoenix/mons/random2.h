get_random_color(){
string hair_color, gen, gen3, genp;
   switch(random(4)){
      case 0: hair_color = "blue";
      break;
      case 1: hair_color = "white";
      break;
      case 2: hair_color = "silver";
      break;
      case 3: hair_color = "gold";
      break;
   }
   switch(random(3)){
      case 0: gen = "male";
      gen3 = "he";
      genp = "his";
      break;
      case 1: gen = "female";
      gen3 = "she";
      genp = "hers";
      break;
      case 2: gen = "it";
      gen3 = "it";
      genp = "its";
      break;
   }
}
