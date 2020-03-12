#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

const char* getFileType(struct stat attributes){
  if(S_ISREG(attributes.st_mode)){
    return "-";
  }
  if(S_ISDIR(attributes.st_mode)){
      return "d";
  }
  if(S_ISCHR(attributes.st_mode)) {
      return "c";
  }
  if(S_ISBLK(attributes.st_mode)){
      return "b";
  }
  if(S_ISFIFO(attributes.st_mode)){
      return "f";
  }
  if(S_ISLNK(attributes.st_mode)){
    return "l";
  }
  return "?";
}

int main(int argc, char const *argv[]) {
  struct stat attributes;
  if(stat(argv[1], &attributes) == 0){
      printf("%s   ",getFileType(attributes));
      printf( (S_ISDIR(attributes.st_mode)) ? "d" : "-");
      printf( (attributes.st_mode & S_IRUSR) ? "r" : "-");
      printf( (attributes.st_mode & S_IWUSR) ? "w" : "-");
      printf( (attributes.st_mode & S_IXUSR) ? "x" : "-");
      printf( (attributes.st_mode & S_IRGRP) ? "r" : "-");
      printf( (attributes.st_mode & S_IWGRP) ? "w" : "-");
      printf( (attributes.st_mode & S_IXGRP) ? "x" : "-");
      printf( (attributes.st_mode & S_IROTH) ? "r" : "-");
      printf( (attributes.st_mode & S_IWOTH) ? "w" : "-");
      printf( (attributes.st_mode & S_IXOTH) ? "x" : "-");
      printf("     ");
      printf("%ld",(long) attributes.st_uid);
      printf("    ");
      printf("%ld",(long) attributes.st_gid);
      printf("    ");
      printf("%lld",(long long) attributes.st_size);
      printf("    ");
      printf("%s", argv[1]);
      printf("    ");
      printf("%s",ctime(&attributes.st_mtime));
  }
  return 0;
}
