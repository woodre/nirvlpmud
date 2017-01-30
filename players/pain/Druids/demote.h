demote(str) {
if(!str) {
        write("And what pray-tell would you like to emote to the "+
              "rest of the druids??\n");
        return 1;
}
int x;
object ob,
       staff;
ob = users();
for( x = 0; x < sizeof(ob); x += 1) {
if(present("g_staff",ob[x])) {
staff = present("g_staff",ob[x]);
if(staff->query_muffs() == 0 && staff->query_color() == 0) {
        tell_object(ob[x],RED+"</*\>"+END+me" "+str+"\n");
}
if(staff->query_muffs() == 0 && staff->query_color() == 1) {
        tell_object(ob[x],"</*\> "+me+" "+str+"\n");
}
}
return 1;
}
