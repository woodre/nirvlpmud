#include "/players/jaraxle/define.h"
object obj;
string att, str1, str2;
main() {
   if(sscanf(environment(TP)->long(), "%sgrass%s", str1, str2) == 2 || sscanf(environment(TP)->short(), "%sgrass%s", str1, str2) == 2){
      write("Grasslands\n");
      return 1; }
   if(sscanf(environment(TP)->long(), "%sdesk%s", str1, str2) == 2 || sscanf(environment(TP)->short(), "%sdesk%s", str1, str2) == 2){
      write("Fire elemental\n");
      return 1; }
   else{
      write("[genric]\n");
      return 1; }
}
