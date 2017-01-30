id(str){ return str == "something"; }
query_name(){ return "something"; }
short(){ return "Something Zeus coughed up"; }
long(){ write("This is something Zeus coughed up.  It's very sticky and gooey.\n");
}
query_value(){ return 5; }
query_weight(){ return 1; }
get(){ return 1; }
drop(){ return 0; }
void init(){ add_action("eat", "eat"); }
eat(str){ if(str != "something") return 0;
if(!present(this_object(), this_player())) return 0;
write("You eat the something and feel ill.\n");
say(this_player()->query_name()+" eats something Zeus coughed up.\n");
destruct(this_object());
return 1;
}
