reset(arg) {
        if(arg) return;
}

id( str ) {
  if(str=="X chromosome"||str=="x chromosome"||str=="X"||str=="x"||str=="chromosome") return 1;
        return 0;
}

long() {
   write("This is a very special chromosome. It's called the\n"+
      "X-chromosome, which is found in both female and male.\n"+
      "However, it is specific a female chromosome.\n"+
      "For more explenation, read the anatomical guide.\n");
}

short()
   {  return "An X chromosome";}

get() {
        return 1;
}
drop() {
        return 0;
}
