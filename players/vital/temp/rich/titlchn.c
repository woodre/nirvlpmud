id(str)
{
if ( str=="title" || str =="title change" || str =="change" ) return 1;
return 0;
}

short()
{
return "A title change";
}

long()
{
write("This is a title change to use type `title whatever'.\n");
}

query_value() { return 50; }


get () {
return 1;

}
query_weight() { return 1; }

init() {
    add_action("title" ,"title");
}

title(str) {
     object ob;
        ob=this_player();
          call_other(ob,"set_title",str);
          write("Title changed.\n");
          destruct(this_object());
          return 1;
          }
reset(arg) {}
