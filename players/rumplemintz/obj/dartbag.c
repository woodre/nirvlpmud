inherit "obj/treasure";
int num_darts;
object eyes;
int num_dart;
reset(arg){
   refresh_desc();
   if(arg) return;
   set_short("A Full Dartbag");
   num_dart=20;
   set_id("dartbag");
   set_long("A bag of darts to throw at Rumplemintz's dartboard.\n");
   set_weight(1);
   set_value(150);
}
get(){return 1;}
long(){write("A bag of darts to throw at Rumplemintz's dartboard.\n");}

refresh_desc(){
   set_short("Dart bag with "+query_dart()+" darts left");
   return;}
set_dart(arg){num_dart=query_dart()+arg;
   if(num_dart>20){num_dart=20;}
   refresh_desc();}
query_dart(){return num_dart; refresh_desc();}
init(){
  add_action("throw","throw");
}
throw(arg){
  object dartboard;
   if(!present("dartboard",environment(this_player()))){
    write("There isn't at dartboard here!.\n"); return 1;}
        eyes=present("dartbag",this_player());
        num_darts=eyes->query_dart();
        if(num_darts==0){write("You are out of darts.\n"); return 1;}
        if(!present("dartboard",this_player()))
        present("dartboard",environment(this_player()))->set_dart(1);
        tell_object(this_player(),"You throw a dart and it hits dead center! Bull's Eye!\n");
        say(capitalize(this_player()->query_name())+" throws a dart at the board and gets a Bull's Eye.\n");
        return 1;}
