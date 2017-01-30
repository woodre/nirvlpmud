#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("comb");
   set_short("A silver comb");
   set_long(
   "A beautiful silver comb used to 'brush' your hair.\n");
   set_weight(1);
   set_value(1000);
}

init()  {
   add_action("brush_object", "brush");
        }

brush_object(str)  {
object ob;
string gender;
gender = "its";
if(this_player()->query_gender() == "male"){gender = "his";}
if(this_player()->query_gender() == "female"){gender = "her";}
if(!str){
  write("You brush your hair with the silver comb.\n");
  say(tp+" brushes "+gender+" hair with a beautiful silver comb.\n");
return 1;
}
ob = present(str,environment(this_player()));
if(!ob){ write(str+" is not here right now.\n");
return 1;  }
str = capitalize(str);
write("You brush "+str+"'s hair with the silver comb.\n");
say(tp+" brushes "+str+"'s hair with the silver comb.\n");
tell_object(ob,"It feels wonderful.\n");
    return 1;   }
