int
rstrlen(string str) {
  object ob;
  string shrt;
  int length;

  ob = find_living(str);
  if (!str || !ob)
    return 0;
  shrt = (string)ob->short();
  length = strlen(shrt);
  write(":: strlen of "+str+" -> short() :: "+length+"\n");
  return 1;
}
