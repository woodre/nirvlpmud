#define FILENAME "BF"

status main(string arg) {
  write_file("/players/forbin/closed/"+FILENAME, "* "+arg+" ["+ctime()[4..15]+" "+ctime()[20..23]+"]\n");
    return (write("Note made.\n"), 1);
}
