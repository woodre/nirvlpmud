#define TPM this_player()->query_money()
#define tp this_player()->query_name()

object ob,ob2,ob3,ob4,ob5;


id(str) {return str == "victoria";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A lady named Victoria";  }
long(){
write("A lady named Victoria (female).\n");
write("A lovely young lady wearing in a short black dress with a white\n"+
     "lace apron, and a white lace hat.  She has a generous smile upon  \n"+
     "her face, and is here for the express purpose of serving you.\n"+
     "Type <list> so see what Victoria can do for you.\n"+
 "Victoria is in good shape.\n"+
 "        Victoria is carrying:\n"+
 "A french maid's outfit (worn).\n"+
 "A silver tea set.\n\n");
        }

list()  {
write("Victoria can:\n"+
     "     <serve> you tea, or <serve> <name> tea\n"+
     "     <polish> the silver\n"+
     "     <wait> upon you, or <wait> upon <name>\n"+
     "\n");
     return 1;
}

init() {
   add_action("serve","serve");
   add_action("list","list");
   add_action("kill","kill");
   add_action("polish","polish");
   add_action("wait","wait");
}

kill(str)  {
if(str == "victoria")  {
write("Victoria cowers before you, making you feel too guilty to kill her.\n");
say(tp+" looks like she is about to attack Victoria.\n"+
     "Victoria cowers, and "+tp+" decides not to attack.\n");
  return 1;
        }
        }

wait(str)  {
object ob;
  if(!str)  {
  write("You lift a finger, and Victoria walks over to await her next command.\n");
  say(tp+" lifts a finger, and Victoria walks over to wait upon "+this_player()->query_objective()+".\n");
  return 1;
        }
  ob = present(str, environment(this_player()));
  if(!present(str, environment(this_player())))  {
    write("Victoria asks \"\Wait upon who?\"\n");
  return 1;
        }
  write("You lift a finger, motioning Victoria towards "+str+".\n"+
  "Victoria walks over to wait upon "+capitalize(str)+".\n");
  say(tp+" lifts a finger, motioning Victoria towards "+capitalize(str)+".\n"+
  "Victoria walks over to wait upon "+capitalize(str)+".\n");
  return 1;
        }

serve(str)  {
object ob;
  if(!str)  {
  write("You lift a finger, and Victoria pours you a cup of tea.\n");
  say(tp+" lifts a finger, and Victoria serves "+this_player()->query_objective()+" a cup of tea.\n");
  return 1;
        }
  ob = present(str, environment(this_player()));
  if(!present(str, environment(this_player())))  {
  write("Victoria asks \"\Serve who tea?\"\n");
  return 1;
        }
  write("You lift a finger, motioning Victoria towards "+capitalize(str)+".\n"+
  "Victoria walks over to "+capitalize(str)+" and serves "+ob->query_objective()+" a cup of tea.\n");
  say(tp+" lifts a finger, motioning Victoria towards "+capitalize(str)+".\n"+
  "Victoria walks over to "+capitalize(str)+" and serves "+ob->query_objective()+" a cup of tea.\n");
  return 1;
        }

polish()  {
  write("You lift a finger, and Victoria begins to polish the silver.\n");
  say(tp+" lifts a finger, and Victoria begins to polish the silver.\n");
  return 1;
        }
