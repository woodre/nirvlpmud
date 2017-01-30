#define BANNER MAG+"----------------------->>>  "+HIW+"Sigil Help System"+ \
          NORM+MAG+"  <<<-----------------------"+NORM

ghelp_cmd(str) {
string doc, filename;
  if(!str) doc = "index";
  else doc = str;
  filename = GDIR+"help/"+doc;
  if(file_size(filename) > 0) {
    write(BANNER+"\n");
    cat(filename);
    write(BANNER+"\n");
  }
  else write("There is no help available on the topic: "+str+".\n");
  return 1;
}
