id(str) { return str == "vial"; }
short() { return "A vial of precious dirt"; }
long() {
  write("This is a clear glass vial filled with.... dirt.\n"+
        "A label on it reads: 'Icelandic volcanic ash. Est. 22 years old.'\n");
}

get() { return 1; }
query_value() { return 10; }
query_weight() { return 1; }

