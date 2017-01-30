/* TAR extractor for LPC
 *
 * Basic use is to allow extraction of a single tar file
 * It does not overwrite files.
 */

inherit "/obj/treasure";

#define BLOCK_SIZE 512
#define MAX_BUFFER 500      /* lines */

string root_dir;                  /* current working directory */

string tar_file;                  /* tar file */
int f_ptr;                        /* current position in tar file */

string current_file;              /* current file being extracted */
int current_file_length;          /* length of buffer that is yet to be read */
int current_file_size;            /* file size */

string buffer;                    /* text buffer */

status fatal;                     /* exit if error has occured */
status in_use;                    /* currently extracting */
status buffer_eof;                /* buffer has read EOF */
status is_file;                   /* file already exists */

static void buffer_to_file();

void reset(status arg) {
  if (arg) return;
  set_short("Tarx");
  set_name("tarx");
}

void init() {
  ::init();
  add_action("tarx", "tarx");
}


/* convert octal to integer */

int oct_to_int(int oct) {
  int i, base;

  for (base = 1, i = 0; oct; base *= 8) {
    i += (oct - (oct/10) * 10) * base;
    oct /= 10;
  }
  return 1;
}


/* fill text buffer */

static void fill_buffer() {
  if (!(buffer = read_file(tar_file,f_ptr,MAX_BUFFER))) {
    write("Error reading tar file.\n");
    fatal = 1;
    return;
  }
#ifdef OLD_EXPLODE
  if (sizeof(explode(buffer +"\n","\n")) -1 != MAX_BUFFER) buffer_eof = 1;
#else
  if (sizeof(explode(buffer,"\n")) -1 != MAX_BUFFER) buffer_eof =1 ;
#endif
  f_ptr += MAX_BUFFER;
}


/* retrieve file, file size znd start text from txt header */

status filter_modes(string str) { return str != ""; }

#define FILE_NAME 0
#define FILE_SIZE 4
#define FILE_MODE 7

static void interpret_header() {
  string mode_str, *file_modes, rest;
  string str1, str2, str3;
  int i, field, mode, flag;

  if (fatal || !buffer || buffer == "") return;

/* basic header format */

  if (sscanf(buffer,"%s ustar %s", mode_str, rest) != 2) {
    if (buffer_eof)
      write("Ok\n");
    else
      write("Error: Header incorrect format.\n");
    fatal = 1;
    return;
  }

/* get file mode, file size, file name */

#ifdef OLD_EXPLODE
  file_modes = explode(mode_str +" "," ");
#else
  file_modes = explode(mode_str," ");
#endif
  file_modes = filter_array(file_modes,"filter_modes",this_object());

  if (sizeof(file_modes) != 8) {
    write("Error: Incorrect mode string.\n");
    for (i = 0; i < sizeof(file_modes); i++) {
      write("\tMode"+ i +": "+ file_modes[i] +"\n");
    }
    fatal = 1;
    return;
  }

/* file name */

  current_file = file_modes[FILE_NAME];

/* file size */

  if (!sscanf(file_modes[FILE_SIZE],"%d",current_file_length)) {
    write("Error: Cannot retrieve file size.\n");
    fatal = 1;
  }
  current_file_length = oct_to_int(current_file_length);
  current_file_size = current_file_length;

#if 0

/* file mode */

  if (!sscanf(file_modes[FILE_MODE],"%d",mode)) {
    write("Error: Cannot retrieve file mode.\n");
    fatal = 1;
  }
  if (mode != 0 && mode != 5) {
    write("Error: Illegal file mode.\n");
    fatal = 1;
  }

#endif

/* strip header */

  if (sscanf(buffer,"%s"+ current_file +"%s", str1, buffer) == 2) {
    buffer = current_file + buffer;
  }
  buffer = extract(buffer,BLOCK_SIZE);
}


static void tar_extract() {
  int max_loop;

  while(!fatal && buffer) {
    if(max_loop++ > 15) {
      write("Continuing Tarx....\n");
      call_out("tar_extract",1);
      return;
    }
    interpret_header();
    if (!fatal) {
      is_file = (file_size(root_dir + current_file) >= 0) ? 1 : 0;
      buffer_to_file();
    }
  }
  in_use = 0;
}


void buffer_to_file() {
  string txt, str;
  int i;

  if (!current_file_length || current_file[strlen(current_file)-1] == '/') {
    if (current_file[strlen(current_file)-1] == '/') {
      current_file = extract(current_file,0,strlen(current_file)-2);
    }
    if (file_size(root_dir + current_file) == -2
        || mkdir(root_dir + current_file)) {
      str = current_file;
      str += "                                                     ";
      str = extract(str,0,55) +" Directory\n";
      write(str);
      log_file("TARX", str);
    }
    else {
      fatal = 1;
      write("Error: Cannot create directory "+ root_dir + current_file +"\n");
    }
  }
  else {
    txt = extract(buffer,0,current_file_length-1);

    while (!fatal && strlen(txt) < current_file_length) {
      if (!is_file) write_file(root_dir + current_file,buffer);
      current_file_length -= strlen(buffer);
      fill_buffer();
      txt = extract(buffer,0,current_file_length-1);
    }
    if (!is_file) write_file(root_dir + current_file, txt);

    str = current_file;
    str += "                                                         ";
    str = extract(str,0,55) +" File ";
    if (is_file) {
      str += "exists\n";
    }
    else {
      i = 1 + current_file_size/BLOCK_SIZE;
      str += "\t"+ i;
      if (i <= 999) str += " ";
      if (i <= 99) str += " ";
      if (i <= 9) str += " ";
      str += " Blocks\n";
    }
    write(str);
    log_file("TARX", str);

    buffer = extract(buffer,current_file_length);
  }
}


/* action */

status tarx(string str) {
  string file;

  if (in_use) {
    notify_fail("Currently extracting "+ tar_file +"\n");
    return 0;
  }

  if (!str) {
    notify_fail("tarx <file>, extracts tar file into current directory\n");
    return 0;
  }

  tar_file = (string)this_player()->make_path(str);
  if (file_size(tar_file) <= 0) {
    notify_fail(str +" does not exist.\n");
    return 0;
  }
  write("Extracting Tar file.\n\n");
  root_dir = (string)this_player()->query_path() +"/";
  if (root_dir[0] != '/') root_dir = "/"+ root_dir;
  write("Working Directory: "+ root_dir +"\n");
  f_ptr = 1;
  current_file_length = 0;
  current_file = 0;
  buffer = 0;
  in_use = 1;
  buffer_eof = 0;
  fill_buffer();
  call_out("tar_extract",1);
  return 1;
}
