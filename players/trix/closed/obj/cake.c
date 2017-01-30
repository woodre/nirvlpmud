int karma;
object this;
reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="cake") return 1;
        return 0;
}

long() {
        write( "This is a yummie and creamy cake, cooked by Trix for Karma's Bday.\n"+
               "Just 'eat cake' if you want to join his party.\n");
}

short()
  { return "A B-day cake"; }
init()
{
  add_action( "eat","eat");
}

eat(arg)
{  if(arg!="cake") return;
   this=this_player();
   if(this->query_name()=="Karma") karma=1;
   if(!karma) { write("You wouldn't start the party without Karma, would u? :)\n"); return 1; }
   write("You take a slice of cake and gobble it down all at once... *YUMMMMMIE*\n");
   say(capitalize(this_player()->query_name())+" takes a slice of cake and gobbles it down all at once.\n",
   this_player());
   call_out("trans",1);
   return 1;
}
get() {
        return 0;
}
drop() {
        return 0;
}
 
trans()
{ object room;
  room=environment(this);
  tell_room(room,this->query_name()+" seems stunned, stomps and falls at the ground.\n");
  tell_object(this,"ThErE MuST haVe BEen SoMEtHINg wiERd iN thAT CAkE. YOu SuDdENlY sTOMp\n"+
                   "oN YOuR fEEt...\n");
  tell_object(this,"You feel transported in another place.\n"+
                   "You are given a cardboard cone hat and a party favour.\n");
  tell_room("/players/trix/closed/partyroom",this->query_name()+" arrives and joins the party.\n");
  move_object(this,"/players/trix/closed/partyroom");
  move_object(clone_object("/players/trix/closed/obj/favor"),this);
  move_object(clone_object("/players/trix/closed/obj/conehat"),this);
  tell_room(room,this->query_name()+" slowly fades away.\n");
}
