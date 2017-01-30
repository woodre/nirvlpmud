object stack;
int sp;
int disable_short;

tos() { return stack[sp-1]; }

empty() { return sp<=0; }

push(obj) {
  if (sp>=sizeof(stack))
    stack += allocate(10);
  stack[sp++]=obj;
  return 1;
}

pop() {
  if (sp<=0)
    return 0;
  return stack[--sp];
}

reset(arg) {
  if (arg) return;
  stack = allocate(10);
}

print() {
  int i;
  for (i=0; i<sp; i++)
    printitem("", 1, stack[i]);
  return 1;
}

static printitem(pre, level, ob) {
  if (intp(ob))
    write(pre+ob+"\n");
  else if (stringp(ob))
    write(pre+"\""+ob+"\"\n");
  else if (objectp(ob)) {
    if (disable_short)
      write(pre+object_name(ob)+"\n");
    else {
      string sh;
      sh = ob->short();
      if (stringp(sh))
        sh = "\t" + sh;
      else
        sh = "";
      write(pre+object_name(ob)+sh+"\n");
    }
  } else {
    int i;
    if (level<=0)
      write(pre+"({ ... })\n");
    else {
      write(pre+"({\n");
      for (i=0; i<sizeof(ob); i++)
        printitem(pre+num(i,"  ")+": ", level-1, ob[i]);
      write(pre+")}\n");
    }
  }
}

num(n, str) {
  string tmp;
  tmp = str + n;
  return extract(str+n, strlen(tmp)-strlen(str), strlen(tmp)-1);
}
