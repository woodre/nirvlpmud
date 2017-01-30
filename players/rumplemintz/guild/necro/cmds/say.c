#include "../DEFS"

int cmd(string str){
    int a;
    string wmsg, smsg, msg, *word_a;
    if(!str){
	write("What would you like to say?\n");
	return 1;
    }
    word_a = explode(str," ");
    if(word_a[0] == "-old"){
	int i;
	i = sizeof(word_a);
	word_a = word_a[1..i];
	msg = implode(word_a," ");
	write("You say: "+msg+"\n");
	say(this_player()->query_name()+" says: "+msg+"\n");
	return 1;
    }
    wmsg = ""+CONVERTMSG_D->convert_say("You",str,BOLD+BLK)+"";
    smsg = ""+CONVERTMSG_D->convert_room_say(this_player()->query_name(),str,BOLD+BLK)+"";
    write(wmsg+"\n");
    say(smsg+"\n");
    return 1;
}
