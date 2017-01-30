#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "/obj/monster";
int coins;
int coinage;
string argomento;
string subject;

set_coinage(coins) {coinage= coins;}
set_subject(argomento) {subject=argomento;}


id(str) {return str=="grabber";}

init() {
       ::init();
       add_action("grab_book","grab");
       }

reset(arg){
  if(arg) return;
   set_level(1);
   set_hp(4750);
   set_wc(30);
   set_ac(15);
}

grab_book(str){
  object ob;
  if(!str) { write("Grab what?\n"); return 1;}
  if(str=="book from shelf"  || str==subject+" from shelf") {
   write("You take a book of "+subject+" off of the shelf.\n");
   ob=(clone_object("/players/francesco/quest/items/book.c"));
    if(!call_other(tp,"add_weight",call_other(ob,"query_weight"))) {
     write("Yet, the book looks too heavy for your actual strenght\n"+
           "and it slips from your hands to the ground.  After\n"+
           "it will be firmly in your hands, you can go back\n"+
           "and wander through other shelves.\n");
     move_object(ob,environment());  
     present("book",environment())->set_coinage2(coinage); 
     present("book",environment())->set_subject2(subject);
     move_object(clone_object("/players/francesco/quest/mobs/exit_to.c"),environment());
     destruct(this_object());
    return 1; }
   move_object(ob,tp);
   write("You can now 'go back' and wander through other shelves.\n");
   present("book",tp)->set_coinage2(coinage); 
   present("book",tp)->set_subject2(subject);
   move_object(clone_object("/players/francesco/quest/mobs/exit_to.c"),environment());
   destruct(this_object());
   return 1; }
   write("Grabbing the items that way is not possible.\n"); 
   return 1; 
}

