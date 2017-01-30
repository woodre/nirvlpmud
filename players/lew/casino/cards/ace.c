inherit "/obj/treasure.c";
object suit;
set_value(){return 1;}
set_value2(){return 13;}
set_pval(){return 1;}
set_pval2(){return 13;}
short(){ return "The ace of "+suit;
}
drop(){return 1;}
id(){return "ace";}
query_weight(){ return 1;}
face(str){
     if(str == 1){suit = "Hearts";}
     if(str == 2){ suit = "Spades";}
     if(str == 3){ suit = "Clubs";}
     if(str == 4){ suit = "Diamonds";}
}
discard(){destruct(this_object());return 1;}
