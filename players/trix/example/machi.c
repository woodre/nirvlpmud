reset(arg) {
        if(arg) return;
        /* Initialization code goes here */

}
long() {
        write( "An acid vending machine , try it !:).\n" );
        return 1;
}

short() {
   return "A vending machine";
}

id(str) {
        if( str == "machine" ) return 1;
        return 0;
}

init() {
        add_action( "buy", "buy" );
        return 1;
}

query_weight()
{   return 50;
}

buy(str)
{  int choice;
   object cosa;
   string nome[10];
   nome[7]=tipper;
   if((!str) || ((sscanf(str,"%d",choice) !=1)))
     { write("Tsk Tsk Tsk!!!\n");
       return 0;
     }
   if (choice==7)
   {
     cosa=clone_object("players/trix/example/ciuspa.c");
     move_object(cosa,this_player());
     tell_object(this_player(),"You buy a "+nome[7]+"!\n");
     call_other(this_player(), "add_money", - 10000);
   }
   return 1;
}

get() {
        return 0;
}

drop() {
        return 1;
}
