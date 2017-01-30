inherit "obj/treasure.c";
int coins;
int coinage;
string subject;
string argomento;
string str;
set_coinage2(coinage) { coins=coinage; }

set_subject2(subject) {
argomento= subject;

if(argomento=="calculus"){
    set_short("A Book of Calculus"); 
    set_long("The hardcover of the book is blue.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It reports the study of basic mathematics\n"+
             "for engineers.\n");}

if(argomento=="chemistry"){
    set_short("A Book of Chemistry");
    set_long("The hardcover of the book is brown.  This book is used by students in\n"+
             "their first year of engineering when they have to build up the basis\n"+
             "for their further studies. It basically reports the study of the matter\n"+
             "and its transformations.\n");}

}
reset(arg)
   { if(arg) return;}


id(str) { return str == "book" ; }

init() {
    add_action("return_book","return");
    return 1;
}


return_book(arg) {
    object item;
    if(!arg)
      {
       write("Return what??\n");
       return 1;
      }
    if(arg=="book" || arg==argomento)
    { 
    if(!present("marian",environment(this_player())))
     {
      write("Unfortunately, "+call_other(this_player(),"query_name")+", you cant return this book now.\n"+
            "You might try later.\n");
      return 1;
     }
    
      call_other(this_player(),"add_money",coins); 
      write("Thank you very much, "+call_other(this_player(),"query_name")+", I was exactly looking\n"+
            "for this book of "+argomento+".\n");
      destruct(this_object());
      return 1; 
   }
return 0;
 }


get() { return 1; }

query_weight() { return 1; }

query_value() { return (coins); }

drop() { return 0; }

query_save_flag() { return 1; } 


