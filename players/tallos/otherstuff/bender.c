#define tp this_player()->query_name()
#define TP this_player()

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
   set_id("gender bender");
   set_short("Gender bender");
   set_alias("bender");
   set_long("A small coin which will switch your sex.\n"+
     "Type newsex <male/female> to switch.\n"+
     "You may type whatever you like, but only male & female will work\n"+
     "\n");
   set_weight(0);
   set_value(10000);
}

init()  {
   add_action("new_gender","newsex");
   }

new_gender(str)  {
  string gender;

  if(!str) {
     write("To use type: newsex <male or female> :. newsex male or newsex female.\n");
     return 1;
        }
if(sscanf(str, "%s", gender) !=1) {
      write("To use type: newsex <male or female> :. newsex male or newsex female.\n");
     return 1;
        }
if(str == "male" || "female") {
  call_other(TP, "set_gender", gender);
   write("You are now "+gender+"\n"+
     "\n");
  destruct(this_object());
     return 1;
        }
  }
