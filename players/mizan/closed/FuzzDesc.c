/*
 * FuzzyDesc.c Version 1.0
 * Mizan@Nirvana
 */

string short_desc;
string long_desc;
int long_num;
int short_num;

reset() {
 if(long_desc || short_desc) {
  long_num=random(sizeof(long_desc));
  short_num=random(sizeof(short_desc));
 }
}

long() {
  write(long_desc[long_num]);
}

short() {
 return short_desc[short_num];
}

