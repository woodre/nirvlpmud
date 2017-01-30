#include "../defs.h"

cmd(str){
int a;
string wmsg,smsg;
string msg,*word_a;
  if(!str){
    write("What would you like to say?\n");
    return 1;
  }
  word_a = explode(str," ");
  if(word_a[0] == "-old"){
    word_a -= word_a[0];
    msg = implode(word_a," ");
    write("You say: "+msg+"\n");
    say(tpn+" says: "+msg+"\n");
    return 1;
  }
  wmsg = CONVERTMSG_D->convert_say("You",str,BOLD+BLK);
  smsg = CONVERTMSG_D->convert_room_say(tpn,str,BOLD+BLK);
  
write(wmsg+"\n");
say(smsg+"\n");
return 1;
}
