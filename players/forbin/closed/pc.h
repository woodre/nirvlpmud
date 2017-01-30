#define PC ({ "forbin","ftest","ftestbin","fortest","fone","ftwo","fthree","preston","poggio","z","weyless","delphinus","casper","micah","roubaix","cortez","somantin","ribbit","fee","grenoble","marlowe","ventoux" })

query_pc(string str) {
  if(!PC || !sizeof(PC)) return 0;
  if(index(PC, str) > -1) return 1;
  return 0;
}