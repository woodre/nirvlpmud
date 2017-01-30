id(str){
return str == "sign"; }
long() {
write("Ok kids, listen up. My castle is something new!  And here's what to know!\n"+
"\nIN EVERY ROOM YOU CAN DO THE FOLLOWING\nlisten\nsmell\nsearch\n"+
"Not to mention every item in the description can be looked at!!!!\n"+
"ALSO, many of the items you can interact with (touch, enter, whatever)\n"+
"What this means is that not all the exits are obvious, BUT they are all \n"+
"intuitive!!!!!\nMail any Ideas to Unsane\n");
}
short(){ return "A HUGE SIGN"; }
read(str){
if (str == "sign");
{
long();
return 1; }
}
get(){ return 0; }
drop(){ return 0;}
init(){
add_action("read","read");
}
