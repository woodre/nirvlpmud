#include "/players/wocket/closed/ansi.h"
#define FRAMES 40

cast(){
animate_ball();
write("blah blah ball flies across slamming into blah.\n");
return 1;
}

animate_ball(){
int i,a;
int j,b;

for(i=0,a=FRAMES;i<a;i++){

 for(j=0;j<i;j++){
  write("\n");
 }
 write("    ()");
 write(CLS);
}

}