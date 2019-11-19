#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
   char buf[2];
   int bytes_read = 0;
   int total_bytes = 0;
   *lineptr = mx_strnew(0);
   while ((bytes_read = read(fd, buf, 1)) > 0 && buf[0] != delim) {
       total_bytes += bytes_read;
       buf[1] = '\0';
       char *tmp = mx_strjoin(*lineptr, buf);
       mx_strdel(lineptr);
       *lineptr = mx_strdup(tmp);
       mx_strdel(&tmp);
   }
   if (bytes_read == 0 || total_bytes < buf_size) {
       return 0;
   }
   else if (bytes_read == -1) {
       return -1;
   }
   else {
       return total_bytes;
   }
}
