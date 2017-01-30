hp_mod(int i){
  int number;
  number = i - ATTHP;
  if(number < 0) number *= -1; /* make sure its positive */
  if(number > 2) return 0;
  return 1;
}
