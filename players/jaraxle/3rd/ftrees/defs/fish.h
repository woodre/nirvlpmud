view_fish(){
int FISH, AMT;

switch(random(4)){
  case 0: FISH = "bass"; break;
  case 1: FISH = "black bass"; break;
  case 2: FISH = "trout"; break;
  case 3: FISH = "silver fish"; break;
}

switch(random(4)){
  case 0: AMT = "a school of"; break;
  case 1: AMT = "a few"; break;
  case 2: AMT = "a couple of"; break;
  case 3: AMT = "a"; break;
}
write("You see "+AMT+" "+FISH+" swim by under the water.\n");
}
