string title;
string text;
id(str) { return str == "sliver" || str == "piece"; }

set_header(str) 
{
  title = str;
}

set_text(str) 
{
    text = str;
}

short() {
  if(title) {
    return "A tiny piece of a Pee ball, titled '"+title+"'";
  }
  return "A tiny piece of a Pee ball with some writing on it";
}

long() {
  display();
}

init() {
  add_action("read","read");
}

read(str) {
  if(!str || !id(str)) return 0;
  display();
  return 1;
}

display() {
  if(title) {
    write("A scribbled text titled '"+title+"':\n\n");
  } else {
    write("This is a piece of a Pee ball with some writing on it:\n\n");
  }
  write(text);
  return 1;
}

get() { return 1; }
query_save_flag() { return 1; }
