#include "/players/jenny/define.h"
main(str) {
string type, file;

if(sscanf(str,"%s#%s",file,type) != 2) {
        write("Usage: weapons file#type\n");
        return 1;
}
else {
write_file("/open/maledicta/jenny_weapons",WHT+file+" - - "+BLU+type+NORM+"\n");
write("noted.\n");
return 1;}}
