

short()
{
   return "A large grey box (vault) with a small door";
}

query_value()
{
        return 3;
}

  query_weight() {   return 200; }
long()
{
write("It is a grey, sheet steel box about 5 feet high and about 6 feet square.\n"+
"You notice a large yellow sticker on the box which reads:\n"+
"DANGER! HIGH VOLTAGE EQUIPMENT INSIDE. 13,000 VOLTS\n"+
"ARCING CURRENT MAY CAUSE SERIOUS INJURY OR DEATH.\n"+
"DO NOT OPEN CASE UNLESS POWER IS DISCONNECTED.\n"+
"There is a small unlocked door at the bottom, you might be able to enter through\n");
write("it. Through the door you can see the small gold bars attached to the inside of\nthe case\n");
}

init() {
  add_action("enter","enter");
}



get() {
    return 0;
}
id(str) { return str=="vault"||str=="box"; }
 enter(str) {
 if(str!="box" && str!="vault") return 0;
write("You open the door to the electrical vault.\n");
say(this_player()->query_name() + " opens the door to the electrical vault.\n");
write("You begin to enter the vault, there is arcing current all over the place.\n");
say(this_player()->query_name()+" enters the electrical vault.\n");
write("You are suddenly hit by an arc of current!!!!!\n");
say(this_player()->query_name()+" shakes as 13,000 volts flows through ");
this_player()->hit_player(175+random(100)+random(200)+random(150));
log_file("vault",this_player()->query_real_name()+ " got zaped.\n");
if(this_player()->query_gender()=="female") {say("her ");
}else{ say("his ");
}
say("body and then falls to the ground.\n");
/*
 call_other(this_player(), "move_player", "east#players/boltar/things/vault.c");
*/
   return 1;
}
is_castle() {return 1;}
